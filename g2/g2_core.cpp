#include "stdafx.h"

#include "g2.h"

using namespace g2;
using namespace g2::Internal;

int viewportWidth, viewportHeight;

std::stack<glm::mat4> orthoStack;
std::stack<int> viewportStack2;

void g2::ortho(int left, int bottom, int width, int height) {
    WinOrtho = glm::ortho((float)left, (float)width, (float)bottom, (float)height);
}

void g2::pushOrtho() {
	orthoStack.push(WinOrtho);
}

void g2::popOrtho() {
	WinOrtho = orthoStack.top();
	orthoStack.pop();
}

void g2::viewport(int width, int height) {
	viewportWidth = width;
	viewportHeight = height;

    glViewport(0, 0, width, height);
}

void g2::pushViewport() {
	viewportStack2.push(viewportWidth);
	viewportStack2.push(viewportHeight);
}

void g2::popViewport() {
	int h = viewportStack2.top();
	viewportStack2.pop();

	int w = viewportStack2.top();
	viewportStack2.pop();

	viewport(w, h);
}

void g2::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
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
	ace_texture_prog = new AceProgram("c:/_c/g2/shader/texture_rect.vertex.txt", "c:/_c/g2/shader/texture_rect.fragment.txt");
	ace_atlas_prog = new AceProgram("c:/_c/g2/shader/atlas_rect.vertex.txt", "c:/_c/g2/shader/atlas_rect.fragment.txt");

	ace_rgb_rect = new AceRgbRect();
	ace_texture_rect = new AceTextureRect();
}

void g2::uninit() {

	delete ace_atlas_prog;
	delete ace_texture_prog;
	delete ace_rgb_prog;

	delete ace_rgb_rect;
	delete ace_texture_rect;

	// no need to free current_ace_texture
}



