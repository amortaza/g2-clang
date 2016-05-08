#pragma once

extern class AceProgram;
extern class AceTexture;

class AceMaskRgbRect {

public:

	AceMaskRgbRect();
	~AceMaskRgbRect();

	void draw(AceProgram* prog, AceTexture* mask, int left, int top, int w, int h, glm::mat4* Projection, float* alphas, float *reds, float *greens, float *blues);

private:

	GLuint vid;


	void setVertexData(int left, int top, int w, int h, float* alphasLeftTopRightBottom, float *reds, float *greens, float *blues);
};