#pragma once


namespace g2 {

	struct TextureRef {
		GLuint id;
	};

	TextureRef* createTexture();

	void freeTexture(TextureRef*);

	void beginTexture(TextureRef*);
	
	void load(const char* filename);
}
