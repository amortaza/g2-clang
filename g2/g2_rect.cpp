#include "stdafx.h"

#include "g2.h"

using namespace g2;
using namespace g2::Internal;

void g2::rgb(unsigned char _red, unsigned char _green, unsigned char _blue) {
	red = _red / 255.f;
	green = _green / 255.f;
	blue = _blue / 255.f;
}

void g2::rgb2(unsigned char _red, unsigned char _green, unsigned char _blue) {
	red2 = _red / 255.f;
	green2 = _green / 255.f;
	blue2 = _blue / 255.f;
}

void g2::rectRgb(int left, int top, int width, int height) {
	rect(FLAG_RGB_SOLID, left, top, width, height);
}

void g2::rectTexture(int left, int top, int width, int height) {
	rect(FLAG_TEXTURE, left, top, width, height);
}

void g2::rect(int flags, int left, int top, int width, int height) {
	// default to rgb, so if texture is not set, then RGB
	if ( flags & FLAG_TEXTURE) {
		if (flags & FLAG_ALPHA_HORIZ_GRADIENT) {
			float alphas[] = { current_alpha, -1, alpha2, -1};
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}
		else if (flags & FLAG_ALPHA_VERT_GRADIENT) {
			float alphas[] = { -1, alpha2, -1, current_alpha };
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}
		else {
			// left, top, right, bottom
			float alphas[] = { current_alpha, current_alpha, current_alpha, current_alpha };
			ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas);
		}

		current_ace_texture->deactivate();

		current_ace_texture = 0;
	}
	else {
		if (flags & FLAG_RGB_SOLID) {
			if (flags & FLAG_ALPHA_HORIZ_GRADIENT) {
				// left, top, right, bottom
				float alphas[] = {current_alpha, current_alpha, alpha2, alpha2 };
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red, green, blue, alphas);
			}
			else if (flags & FLAG_ALPHA_VERT_GRADIENT) {
				// left, top, right, bottom
				float alphas[] = { alpha2, current_alpha, current_alpha, alpha2 };
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red, green, blue, alphas);
			}
			else {
				// left, top, right, bottom
				float alphas[] = { current_alpha, current_alpha, current_alpha, current_alpha };

				// no transparency
				ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, red, green, blue, alphas);
			}
		}
		else if (flags & FLAG_RGB_HORIZ_GRADIENT) {
			ace_rgb_rect->drawHorizontalGradient(ace_rgb_prog, left, top, width, height, &WinOrtho, red, green, blue, red2, green2, blue2);
		}
		else if (flags & FLAG_RGB_VERT_GRADIENT) {
			ace_rgb_rect->drawVerticalGradient(ace_rgb_prog, left, top, width, height, &WinOrtho, red, green, blue, red2, green2, blue2);
		}
		else {
			throw "rect() flags are invalid none of rgb solid, horiz or vert gradient.";
		}
	}
}

