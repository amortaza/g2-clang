#include "stdafx.h"

#include "g2.h"

using namespace g2;
using namespace g2::Internal;

extern TextureRef* current_texture_ref;

void g2::rgb(unsigned char _red, unsigned char _green, unsigned char _blue) {
	red = _red / 255.f;
	green = _green / 255.f;
	blue = _blue / 255.f;
}

void g2::rect(int left, int bottom, int width, int height) {
	if (current_texture_ref == 0)
		ace_rgb_rect->draw(ace_rgb_prog, left, bottom, width, height, &WinOrtho, red, green, blue);
	else
		ace_texture_rect->draw(ace_texture_prog, current_texture_ref->ace_texture, left, bottom, width, height, &WinOrtho);
}

