#pragma once

#include "AceTexture.hpp"

namespace g2 {
	class TextureRef {
	public:
		GLuint id;
		AceTexture* ace_texture;

		~TextureRef() {
			delete ace_texture;
		}
	};

	TextureRef* createTexture();
	void beginTexture(TextureRef*);
	void endTexture();

	void freeTexture(TextureRef*);

	void load(const char* filename);

	void texture(TextureRef*);
}

