#include "stdafx.h"

#include "AceImageRect.hpp"
#include "AceProgram.hpp"
#include "AceTextureRect.hpp"
#include "AceTexture.hpp"

AceImageRect::AceImageRect(const char* filename, int textureWidth, int textureHeight, AceProgram* ace_prog) {
    this->ace_prog = ace_prog;

	ace_texture_rect = new AceTextureRect();

	ace_texture = new AceTexture(textureWidth, textureHeight);
	ace_texture->loadRgb(filename);
}

AceImageRect::~AceImageRect() {
	delete ace_texture_rect;
    delete ace_texture;

	//test new AceTextureRect();
	//test new AceTexture();
}

void AceImageRect::draw(int left, int top, int w, int h, glm::mat4* Projection) {
	printf("You need to fix AceImageRect.draw dawg\n");
	//ace_texture_rect->draw(ace_prog, ace_texture, left, top, w, h, Projection);
}
