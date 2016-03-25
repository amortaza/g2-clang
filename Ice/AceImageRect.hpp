#pragma once

#include "AceProgram.hpp"
#include "AceTexture.hpp"

class AceImageRect {

public:

    AceImageRect(const char* filename, int textureWidth, int textureHeight, AceProgram* ace_prog) {
        this->ace_prog = ace_prog;

        ace_tex_rect = new AceTexRect();

		ace_texture = new AceTexture(textureWidth, textureHeight);
		ace_texture->load(filename);
    }

    ~AceImageRect() {
		delete ace_tex_rect;
        delete ace_texture;
    }

    void draw(int left, int bottom, int w, int h, glm::mat4* Projection) {
		ace_tex_rect->draw(ace_prog, ace_texture, left, bottom, w, h, Projection);
    }

private:

	AceProgram* ace_prog;
	AceTexture* ace_texture;
	AceTexRect* ace_tex_rect;
};