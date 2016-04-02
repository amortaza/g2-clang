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

	void clear();

	void rgb(unsigned char red, unsigned char green, unsigned char blue);	
	void rgb2(unsigned char red, unsigned char green, unsigned char blue);

	void rect(int flags, int left, int top, int width, int height);
	void rectRgb(int left, int top, int width, int height);
	void rectTexture(int left, int top, int width, int height);

	void opacity(float alpha);
	void opacity2(float alpha);

	namespace Internal {
		void freeMaps();
	}
}
