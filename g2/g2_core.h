#pragma once

#include "g2_texture.h"

namespace g2 {	

	void init();
	void uninit();

	void ortho(int width, int height);

	void viewport(int width, int height);

	void clear();

	void rgb(unsigned char red, unsigned char green, unsigned char blue);

	void rect(int left, int bottom, int width, int height);

	void quad();	

	void end();
}
