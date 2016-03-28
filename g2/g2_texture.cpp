#include "stdafx.h"

#include "g2_texture.h"
#include "g2_externals.h"

using namespace g2;
using namespace g2::Internal;

AceTexture* current_ace_texture = 0;

TextureRef* g2::loadTexture(const char* filename) {
	TextureRef* ref = new TextureRef();

	ref->ace_texture = new AceTexture();
	
	ref->ace_texture->load(filename);

	texture(ref);

	return ref;
}

void g2::texture(CanvasRef* canvas) {
	current_ace_texture = canvas->ace_frame_buffer->texture;
}

void g2::texture(TextureRef* ref) {
	current_ace_texture = ref->ace_texture;
}

