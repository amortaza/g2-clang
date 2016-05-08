#include "stdafx.h"

#include "AceTexture.hpp"
#include "TextureRef.h"

using namespace g2;

TextureRef::~TextureRef() {
	delete ace_texture;
}
