#include "stdafx.h"

#include "g2.h"

using namespace g2;
using namespace g2::flags;
using namespace g2::Internal;

void g2::color(unsigned char red, unsigned char green, unsigned char blue) {
	red1 = red / 255.f;
	green1 = green / 255.f;
	blue1 = blue / 255.f;
}

void g2::color2(unsigned char red, unsigned char green, unsigned char blue) {
	red2 = red / 255.f;
	green2 = green / 255.f;
	blue2 = blue / 255.f;
}

void g2::rect(int flags, int left, int top, int width, int height) {
	g2::Internal::_rect(flags, left, top, width, height, 1.f);
}

void g2::rectFlipped(int flags, int left, int top, int width, int height) {
	g2::Internal::_rect(flags, left, top, width, height, 0.f);
}

void g2::Internal::_rect(int flags, int left, int top, int width, int height, float topTextureCoord) {
	float alphas[4];

	_getAlphas(flags, alphas, alpha1, alpha2);

	if ( flags & G2_TEXTURE) {
		if (!current_ace_texture) throw "no texture active for rectangle - did you forget to call g2::texture(), or try to use g2::rect() multiple times without calling g2::texture()?";

		if (flags & G2_PAD) {
			float tLeft = left, tWidth = width, tTop = top, tHeight = height;

			tLeft += padding_left; tWidth -= padding_left;
			tTop += padding_top; tHeight -= padding_top;
			tWidth -= padding_right;
			tHeight -= padding_bottom;

			// when not drawing to a canvas, this would have left a black box
			/*float reds[4], greens[4], blues[4];
			_getRgbs(G2_COLOR_SOLID, reds, greens, blues, 0, 0, 0, 0, 0, 0);
			ace_color_rect->draw(ace_color_prog, left, top, width, height, &WinOrtho, alphas, reds, greens, blues);*/

			if (flags & G2_MASK) {
				current_mask_ref->ace_texture->activate2();
				ace_texture_rect->draw(ace_mask_texture_prog, current_ace_texture, tLeft, tTop, tWidth, tHeight, &WinOrtho, alphas, topTextureCoord);
			}
			else {
				ace_texture_rect->draw(ace_texture_prog, current_ace_texture, tLeft, tTop, tWidth, tHeight, &WinOrtho, alphas, topTextureCoord);
			}

			padding_left = padding_top = padding_right = padding_bottom = 0;
		}
		else {
			if (flags & G2_MASK) {
				current_mask_ref->ace_texture->activate2();
				ace_texture_rect->draw(ace_mask_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas, topTextureCoord);
			}
			else {
				ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas, topTextureCoord);
			}
		}

		current_ace_texture->deactivate();
		current_ace_texture = 0;

		if (flags & G2_MASK) {
			current_mask_ref->ace_texture->deactivate2();
			current_mask_ref = 0;
		}
	}
	else if (flags & G2_COLOR_ANY) {
		float reds[4], greens[4], blues[4];

		_getRgbs(flags, reds, greens, blues, red1, green1, blue1, red2, green2, blue2);

		if (flags & G2_MASK) {
			ace_mask_color_rect->draw(ace_mask_color_prog, current_mask_ref->ace_texture, left, top, width, height, &WinOrtho, alphas, reds, greens, blues);
			current_mask_ref = 0;
		}
		else
			ace_color_rect->draw(ace_color_prog, left, top, width, height, &WinOrtho, alphas, reds, greens, blues);
	}
	else {
		throw "rect() flags are none of texture or rgb.";
	}
}

