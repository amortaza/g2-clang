#include "stdafx.h"

#include "g2/g2.h"

using namespace g2;
using namespace g2::flags;
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
	rect(G2_RGB_SOLID | G2_ALPHA_NONE, left, top, width, height);
}

void g2::rectTexture(int left, int top, int width, int height) {
	rect(G2_TEXTURE | G2_ALPHA_NONE, left, top, width, height);
}

void g2_internal_getAlphas(int flags, float* alphas) {
	if (flags & G2_ALPHA_NONE) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = 1.f;
	}
	else if (flags & G2_ALPHA_SOLID) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = alpha1_effective;
	}
	else if (flags & G2_ALPHA_HORIZ_GRADIENT) {
		alphas[0] = alpha1_effective;
		alphas[1] = -1;
		alphas[2] = alpha2_effective;
		alphas[3] = -1;
	}
	else if (flags & G2_ALPHA_VERT_GRADIENT) {
		alphas[0] = -1;
		alphas[1] = alpha1_effective;
		alphas[2] = -1;
		alphas[3] = alpha2_effective;
	}
	else {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = 1.f;
	}
}

// [0] is color of left-bottom
// [1] is color of left-top
// [2] is color of right-top
// [3] is color of right-bottom
void g2_internal_getRgbs(int flags, float* reds, float *greens, float *blues) {
	if (flags & G2_RGB_SOLID) {
		reds[0] = reds[1] = reds[2] = reds[3] = red1;
		greens[0] = greens[1] = greens[2] = greens[3] = green1;
		blues[0] = blues[1] = blues[2] = blues[3] = blue1;
	}
	else if (flags & G2_RGB_HORIZ_GRADIENT) {
		reds[0] = reds[1] = red1;
		greens[0] = greens[1] = green1;
		blues[0] = blues[1] = blue1;

		reds[2] = reds[3] = red2;
		greens[2] = greens[3] = green2;
		blues[2] = blues[3] = blue2;
	}
	else if (flags & G2_RGB_VERT_GRADIENT) {
		reds[2] = reds[1] = red1;
		greens[2] = greens[1] = green1;
		blues[2] = blues[1] = blue1;

		reds[0] = reds[3] = red2;
		greens[0] = greens[3] = green2;
		blues[0] = blues[3] = blue2;
	}
	else {
		reds[0] = reds[1] = reds[2] = reds[3] = red1;
		greens[0] = greens[1] = greens[2] = greens[3] = green1;
		blues[0] = blues[1] = blues[2] = blues[3] = blue1;
	}
}

void g2::rect(int flags, int left, int top, int width, int height) {
	g2::Internal::_rect(flags, left, top, width, height, 1.f);
}

void g2::rectFlipped(int flags, int left, int top, int width, int height) {
	g2::Internal::_rect(flags, left, top, width, height, 0.f);
}

void g2::Internal::_rect(int flags, int left, int top, int width, int height, float topTextureCoord) {
	float alphas[4];

	g2_internal_getAlphas(flags, alphas);

	if ( flags & G2_TEXTURE) {
		if (!current_ace_texture) throw "no texture active for rectangle - did you forget to call g2::texture(), or try to use g2::rect() multiple times without calling g2::texture()?";

		ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, top, width, height, &WinOrtho, alphas, topTextureCoord);

		current_ace_texture->deactivate();

		current_ace_texture = 0;
	}
	else if (flags & G2_RGB_ANY) {
		float reds[4], greens[4], blues[4];

		g2_internal_getRgbs(flags, reds, greens, blues);

		ace_rgb_rect->draw(ace_rgb_prog, left, top, width, height, &WinOrtho, alphas, reds, greens, blues);
	}
	else {
		throw "rect() flags are none of texture or rgb.";
	}

	alpha1_effective = alpha2_effective = 1.f;
}

