#pragma once

#include "AceTexture.hpp"

extern class AceProgram;

class AceTextureRect {

public:

	AceTextureRect();

	~AceTextureRect();

	void draw(AceProgram* prog, AceTexture* texture, int left, int top, int w, int h, glm::mat4* Projection, float* alphas, float topTextureCoord);

private:
	GLuint vid;

	void setVertexData(int left, int top, int w, int h, float topTextureCoord);
};