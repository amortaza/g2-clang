#include "stdafx.h"

#include "g2.h"

using namespace g2::Internal;

void g2::rgb(unsigned char _red, unsigned char _green, unsigned char _blue) {
	red = _red / 255.f;
	green = _green / 255.f;
	blue = _blue / 255.f;

	if (stack.isQuad()) {
		quadRed[quadIndex] = red;
		quadGreen[quadIndex] = green;
		quadBlue[quadIndex] = blue;

		quadIndex = (quadIndex + 1) % 3;
	}
}

void g2::rect(int left, int bottom, int width, int height) {

	if (stack.isQuad()) {
		quadLeft = left;
		quadBottom = bottom;
		quadWidth = width;
		quadHeight = height;
	}
	else if (stack.isNone()) {
		ace_rgb_rect->draw(ace_rgb_prog, left, bottom, width, height, &WinOrtho, red, green, blue);
	}
	else {
		throw "g2::rect does not operate with beginType that is not Quad or None";
	}
}

void g2::quad() {
	stack.pushQuad();
	quadIndex = 0;
}
