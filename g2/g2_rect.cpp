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

void g2::rectRgb(int left, int bottom, int width, int height) {
	ace_rgb_rect->draw(ace_rgb_prog, left, bottom, width, height, &WinOrtho, red, green, blue);
}

void g2::rectRgbHorizontalGradient(int left, int bottom, int width, int height) {
	ace_rgb_rect->drawHorizontalGradient(ace_rgb_prog, left, bottom, width, height, &WinOrtho, red, green, blue, red2, green2, blue2 );
}

void g2::rectRgbVerticalGradient(int left, int bottom, int width, int height) {
	ace_rgb_rect->drawVerticalGradient(ace_rgb_prog, left, bottom, width, height, &WinOrtho, red, green, blue, red2, green2, blue2);
}

void g2::rectTexture(int left, int bottom, int width, int height) {
	ace_texture_rect->draw(ace_texture_prog, current_ace_texture, left, bottom, width, height, &WinOrtho);

	current_ace_texture->deactivate();

	current_ace_texture = 0;
}

