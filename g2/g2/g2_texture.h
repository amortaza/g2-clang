#pragma once

#include "AceTexture.hpp"
#include "g2_canvas.h"

namespace g2 {
	class TextureRef {
	public:
		AceTexture* ace_texture;

		~TextureRef() {
			delete ace_texture;
		}
	};

	TextureRef* loadTextureRgb(char* filename);
	TextureRef* loadTextureRgba(char* filename);
	TextureRef* loadTextureAlpha(unsigned char* buffer, int width, int height);

	void texture(TextureRef*);
	void texture(CanvasRef*);
}

