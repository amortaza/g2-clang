#pragma once

extern class AceTextureRect;
extern class AceTexture;
extern class AceProgram;

class AceImageRect {

private:

	AceProgram* ace_prog;
	AceTexture* ace_texture;
	AceTextureRect* ace_texture_rect;

public:

	AceImageRect(const char* filename, int textureWidth, int textureHeight, AceProgram* ace_prog);

	~AceImageRect();

	void draw(int left, int top, int w, int h, glm::mat4* Projection);
};