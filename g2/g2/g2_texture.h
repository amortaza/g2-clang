#pragma once

#include "AceTexture.hpp"
#include "g2_canvas.h"

namespace g2 {

	extern class TextureRef;

	TextureRef* loadTextureRgb(char* filename);
	TextureRef* loadTextureRgba(char* filename);
	TextureRef* loadTextureAlpha(unsigned char* buffer, int width, int height);

	void texture(TextureRef*);
	void texture(CanvasRef*);
}

