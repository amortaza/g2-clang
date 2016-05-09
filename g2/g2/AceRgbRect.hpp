#pragma once

#include "AceProgram.hpp"

class AceRgbRect {

public:

	AceRgbRect();

	~AceRgbRect();

	void draw(AceProgram* prog, int left, int top, int w, int h, glm::mat4* Projection, float* alphas, float *reds, float *greens, float *blues);

private:

	GLuint vid;

	
	void setVertexData(int left, int top, int w, int h, float* alphasLeftTopRightBottom, float *reds, float *greens, float *blues);
};