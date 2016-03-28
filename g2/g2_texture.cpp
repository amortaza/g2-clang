#include "stdafx.h"

#include "g2_texture.h"
#include "g2_externals.h"

using namespace g2;
using namespace g2::Internal;

extern TextureRef* current_texture_ref;

void g2::beginTexture(TextureRef* ref) {
	current_texture_ref = ref;
	ref->ace_texture->activate();

	stack.pushTexture();
}

TextureRef* g2::createTexture() {
	TextureRef* ref = new TextureRef();

	ref->ace_texture = new AceTexture();
	ref->ace_texture->activate();

	current_texture_ref = ref;

	return ref;
}

void g2::freeTexture(TextureRef* ref) {
	delete ref->ace_texture;

	delete ref;
}

void g2::load(const char* filename) {

}