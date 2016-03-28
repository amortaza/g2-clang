#include "stdafx.h"

#include "g2.h"

using namespace g2;
using namespace g2::Internal;

TextureRef* current_texture_ref;

void g2::ortho(int width, int height) {
    WinOrtho = glm::ortho(0.f, (float)width, 0.f, (float)height);
}

void g2::viewport(int width, int height) {
    glViewport(0, 0, width, height);
}

void g2::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void g2::end() {

    if (stack.isQuad()) {
		ace_rgb_rect->draw(ace_rgb_prog, quadLeft, quadBottom, quadWidth, quadHeight, &WinOrtho, quadRed, quadGreen, quadBlue);
    }

	stack.pop();
}

void g2::init() {
	glClearColor(0.0f, 0.0f, 1.0f, 0.5f);

	glActiveTexture(GL_TEXTURE0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);

	ace_rgb_prog = new AceProgram("c:/_c/g2/shader/col_rect.vertex.txt", "c:/_c/g2/shader/col_rect.fragment.txt");
	ace_rgb_rect = new AceRgbRect();
}

void g2::uninit() {
	delete ace_rgb_rect;
	delete ace_rgb_prog;

	// no need to free current_texture_ref, it is done by client
}



