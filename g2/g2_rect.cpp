#include "stdafx.h"

#include "g2.h"

using namespace g2;
using namespace g2::Internal;

void g2::rgb(unsigned char red, unsigned char green, unsigned char blue) {
	red1 = red / 255.f;
	green1 = green / 255.f;
	blue1 = blue / 255.f;
}

void g2::rgb2(unsigned char red, unsigned char green, unsigned char blue) {
	red2 = red / 255.f;
	green2 = green / 255.f;
	blue2 = blue / 255.f;
}

void g2::rectRgb(int left, int top, int width, int height) {
	rect(FLAG_RGB_SOLID | FLAG_ALPHA_NONE, left, top, width, height);
}

void g2::rectTexture(int left, int top, int width, int height) {
	rect(FLAG_TEXTURE | FLAG_ALPHA_NONE, left, top, width, height);
}

void g2_internal_getAlphas(int flags, float* alphas) {
	if (flags & FLAG_ALPHA_NONE) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = alpha1_parent;
	}
	else if (flags & FLAG_ALPHA_SOLID) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = alpha1_effective;
	}
	else if (flags & FLAG_ALPHA_HORIZ_GRADIENT) {
		alphas[0] = alpha1_effective;
		alphas[1] = -1;
		alphas[2] = alpha2_effective;
		alphas[3] = -1;
	}
	else if (flags & FLAG_ALPHA_VERT_GRADIENT) {
		alphas[0] = -1;
		alphas[1] = alpha1_effective;
		alphas[2] = -1;
		alphas[3] = alpha2_effective;
	}
	else {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = alpha1_parent;
	}
}

void g2::rect(int flags, int left, int top, int width, int height) {
	float alphas[4];

	g2_internal_getAlphas(flags, alphas);

	float alpha1 = alpha1_effective;
	float alpha2 = alpha2_effective;

	if ( flags & FLAG_TEXTURE) {
		if (flags & FLAG_ALPHA_SOLID) {
			float alphas[] = { alpha1, alpha1, alpha1, alpha1 };
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}
		else if (flags & FLAG_ALPHA_HORIZ_GRADIENT) {
			float alphas[] = { alpha1, -1, alpha2, -1}; // doesnt matter -1 as long as the two -1s are the same
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}
		else if (flags & FLAG_ALPHA_VERT_GRADIENT) {
			float alphas[] = { -1, alpha2, -1, alpha1 }; // doesnt matter -1 as long as the two -1s are the same
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}
		else {
			float alphas[] = { alpha1_parent,alpha1_parent,alpha1_parent,alpha1_parent};
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}

		current_ace_texture->deactivate();

		current_ace_texture = 0;
	}
	else if (flags & FLAG_RGB_ANY) {
		if (flags & FLAG_RGB_SOLID) {
			if (flags & FLAG_ALPHA_SOLID) {
				float alphas[] = { alpha1, alpha1, alpha1, alpha1 };
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red1, green1, blue1, alphas);
			}
			else if (flags & FLAG_ALPHA_HORIZ_GRADIENT) {
				float alphas[] = { alpha1, alpha1, alpha2, alpha2 };
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red1, green1, blue1, alphas);
			}
			else if (flags & FLAG_ALPHA_VERT_GRADIENT) {
				float alphas[] = { alpha2, alpha1, alpha1, alpha2 };
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red1, green1, blue1, alphas);
			}
			else {
				float alphas[] = { alpha1_parent,alpha1_parent,alpha1_parent,alpha1_parent };
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red1, green1, blue1, alphas);
			}
		}
		else if (flags & FLAG_RGB_HORIZ_GRADIENT) {
			ace_rgb_rect->drawHorizontalGradient(ace_rgb_prog, left, top, width, height, &WinOrtho, red1, green1, blue1, red2, green2, blue2);
		}
		else if (flags & FLAG_RGB_VERT_GRADIENT) {
			ace_rgb_rect->drawVerticalGradient(ace_rgb_prog, left, top, width, height, &WinOrtho, red1, green1, blue1, red2, green2, blue2);
		}
		else {
			throw "rect() flags are invalid none of rgb solid, horiz or vert gradient.";
		}
	}
	else {
		throw "rect() flags are none of texture or rgb.";
	}
}

