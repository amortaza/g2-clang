#pragma once

#include "AceTexture.hpp"

namespace g2 {
	struct TextureRef {
		GLuint id;
		AceTexture* ace_texture;
	};

	TextureRef* createTexture();
	void beginTexture(TextureRef*);

	void freeTexture(TextureRef*);

	void load(const char* filename);
}

