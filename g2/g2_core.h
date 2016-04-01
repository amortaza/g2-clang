#pragma once

#include "g2_texture.h"

namespace g2 {	

	void init();
	void uninit();

	void ortho(int left, int bottom, int width, int height);
	void pushOrtho();
	void popOrtho();

	void viewport(int width, int height);
	void pushViewport();
	void popViewport();

	void clear();

	void rgb(unsigned char red, unsigned char green, unsigned char blue);
	void rectRgb(int left, int bottom, int width, int height);

	void rectTexture(int left, int bottom, int width, int height);

	namespace Internal {
		void freeMaps();
	}
}
