#pragma once

#include "AceTextureRect.hpp"

class AceImageRect {

private:

	AceProgram* ace_prog;
	AceTexture* ace_texture;
	AceTextureRect* ace_texture_rect;

public:

    AceImageRect(const char* filename, int textureWidth, int textureHeight, AceProgram* ace_prog) {
        this->ace_prog = ace_prog;

		ace_texture_rect = new AceTextureRect();

		ace_texture = new AceTexture(textureWidth, textureHeight);
		ace_texture->loadRgb(filename);
    }

    ~AceImageRect() {
		delete ace_texture_rect;
        delete ace_texture;
    }

    void draw(int left, int top, int w, int h, glm::mat4* Projection) {
		ace_texture_rect->draw(ace_prog, ace_texture, left, top, w, h, Projection);
    }

};