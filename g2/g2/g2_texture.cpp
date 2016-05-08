#include "stdafx.h"

#include "TextureRef.h"

#include "g2/g2_core.h"
#include "g2/g2_externals.h"

using namespace g2;
using namespace g2::Internal;

void g2::padding(int left, int top, int right, int bottom) {
	padding_left = left;
	padding_top = top;
	padding_right = right;
	padding_bottom = bottom;
}

TextureRef* g2::loadTextureRgb(char* filename) {
	TextureRef* ref = new TextureRef();

	ref->ace_texture = new AceTexture();
	
	ref->ace_texture->loadRgb(filename);

	texture(ref);

	return ref;
}

TextureRef* g2::loadTextureRgba(char* filename) {
	TextureRef* ref = new TextureRef();

	ref->ace_texture = new AceTexture();

	ref->ace_texture->loadRgba(filename);

	texture(ref);

	return ref;
}

TextureRef* g2::loadTextureAlpha(unsigned char* buffer, int width, int height) {
	TextureRef* ref = new TextureRef();

	ref->ace_texture = new AceTexture();

	ref->ace_texture->loadAlpha(buffer, width, height);

	texture(ref);

	return ref;
}

void g2::texture(CanvasRef* canvas) {
	// no need to activate texture since it will be activated when drawing occurs
	current_ace_texture = canvas->ace_frame_buffer->texture;
}

void g2::texture(TextureRef* ref) {
	// no need to activate texture since it will be activated when drawing occurs
	current_ace_texture = ref->ace_texture;
}

