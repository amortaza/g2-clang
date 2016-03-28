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

	TextureRef* loadTexture(const char* filename);

	void texture(TextureRef*);
	void texture(CanvasRef*);
}

