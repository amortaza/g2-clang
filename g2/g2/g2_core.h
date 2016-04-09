#pragma once

#include "g2_texture.h"

namespace g2 {	

	void init();
	void uninit();

	void ortho(int width, int height);

	void pushOrtho();
	void popOrtho();

	void viewport(int width, int height);
	void pushViewport();
	void popViewport();

	void opacity(float alpha);
	void opacity2(float alpha);

	void padding(int left, int top, int right, int bottom);

	void clear();

	void color(unsigned char red, unsigned char green, unsigned char blue);	
	void color2(unsigned char red, unsigned char green, unsigned char blue);

	void mask(TextureRef*);

	void rect(int flags, int left, int top, int width, int height);
	void rectFlipped(int flags, int left, int top, int width, int height);
}
