#include "stdafx.h"

#include "AceMaskRgbRect.hpp"
#include "AceProgram.hpp"
#include "AceTexture.hpp"

AceMaskRgbRect::AceMaskRgbRect() {
	glGenBuffers(1, &vid);
}

AceMaskRgbRect::~AceMaskRgbRect() {
	glDeleteBuffers(1, &vid);
}

void AceMaskRgbRect::draw(AceProgram* prog, AceTexture* mask, int left, int top, int w, int h, glm::mat4* Projection, float* alphas, float *reds, float *greens, float *blues) {
	prog->activate();

	mask->activate();

	setVertexData(left, top, w, h, alphas, reds, greens, blues);

	glUniformMatrix4fv(prog->uProjection, 1, GL_FALSE, glm::value_ptr((*Projection)));

	glBindBuffer(GL_ARRAY_BUFFER, vid);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)32);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)96);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	mask->deactivate();
}



void AceMaskRgbRect::setVertexData(int left, int top, int w, int h, float* alphasLeftTopRightBottom, float *reds, float *greens, float *blues) {
	int right = left + w;
	int bottom = top + h;

	const float vertexData[] = {
		left, bottom,    // 2 ints * 4 bytes per int = 8 bytes
		left, top,
		right, top,
		right, bottom,   // 8 bytes per row * 4 rows = 32 bytes

		reds[0], greens[0], blues[0], alphasLeftTopRightBottom[0], // 4 float * 4 bytes per float = 16
		reds[1], greens[1], blues[1], alphasLeftTopRightBottom[1],
		reds[2], greens[2], blues[2], alphasLeftTopRightBottom[2],
		reds[3], greens[3], blues[3], alphasLeftTopRightBottom[3], // 16 * 4 = 64

		0,1 - 0,
		0,1 - 1,
		1,1 - 1,
		1,1 - 0
	};

	glBindBuffer(GL_ARRAY_BUFFER, vid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
