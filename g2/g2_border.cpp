#include "stdafx.h"

#include "g2/g2_externals.h"
#include "g2/g2_core.h"

using namespace g2;
using namespace g2::flags;
using namespace g2::Internal;

void g2::border(int flags, int x, int y, int width, int height, int thickness, float alpha) {
	float reds[4], greens[4], blues[4];
	_getRgbs(G2_COLOR_SOLID, reds, greens, blues, red1, green1, blue1, red1, green1, blue1);

	float alphas[4];

	_getAlphas(G2_ALPHA_SOLID, alphas, alpha, alpha);

	if (flags & G2_BORDER_LEFT) {
		ace_color_rect->draw(ace_color_prog, x, y, thickness, height, &WinOrtho, alphas, reds, greens, blues);
	}

	if (flags & G2_BORDER_RIGHT) {
		ace_color_rect->draw(ace_color_prog, x + width - thickness, y, thickness, height, &WinOrtho, alphas, reds, greens, blues);
	}

	int bx = x, bw = width;

	if (flags & G2_BORDER_LEFT) {
		bx += thickness;
		bw -= thickness;
	}

	if (flags & G2_BORDER_RIGHT) {
		bw -= thickness;
	}

	if (flags & G2_BORDER_TOP) {
		int by = y;
		int bh = thickness;

		ace_color_rect->draw(ace_color_prog, bx, by, bw, bh, &WinOrtho, alphas, reds, greens, blues);
	}
	
	if (flags & G2_BORDER_BOTTOM) {
		int by = y + height - thickness;
		int bh = thickness;

		ace_color_rect->draw(ace_color_prog, bx, by, bw, bh, &WinOrtho, alphas, reds, greens, blues);
	}
}