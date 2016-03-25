#include "stdafx.h"

#include "g2.h"

using namespace g2::Internal;

void g2::ortho(int width, int height) {
    WinOrtho = glm::ortho(0.f, (float)width, 0.f, (float)height);
}

void g2::viewport(int width, int height) {
    glViewport(0, 0, width, height);
}

void g2::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void g2::rgb(unsigned char _red, unsigned char _green, unsigned char _blue) {
    red = _red / 255.f;
    green = _green / 255.f;
    blue = _blue / 255.f;

    if (beginType == 1) {
        quadRed[quadIndex] = red;
        quadGreen[quadIndex] = green;
        quadBlue[quadIndex] = blue;

        ++quadIndex;
    }
}

void g2::rect(int left, int bottom, int width, int height) {
    if (beginType == 1) {
        quadLeft = left;
        quadBottom = bottom;
        quadWidth = width;
        quadHeight = height;
    }
    else {
		ace_rgb_rect->draw(ace_rgb_prog, left, bottom, width, height, &WinOrtho, red, green, blue);
    }
}

void g2::beginQuad() {
    beginType = 1;
    quadIndex = 0;
}

void g2::end() {
    if (beginType == 1) {
		ace_rgb_rect->draw(ace_rgb_prog, quadLeft, quadBottom, quadWidth, quadHeight, &WinOrtho, quadRed, quadGreen, quadBlue);
    }

    beginType = 0;
}

GLuint g2::createTexture() {
    GLuint tid;

    glGenTextures(1, &tid);

    return tid;
}

void g2::freeTexture(GLuint tid) {
    glDeleteTextures(1, &tid);
}

void g2::beginTexture(GLuint tid) {
    beginType = 2;

    textureId = tid;

    glBindTexture(GL_TEXTURE_2D, tid);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

int textureWidth, textureHeight;

void g2::size(int width, int height) {
    textureWidth = width;
    textureHeight = height;
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

	ace_rgb_prog = new AceProgram("c:/_c/ice/shader/col_rect.vertex.txt", "c:/_c/ice/shader/col_rect.fragment.txt");
	ace_rgb_rect = new AceRgbRect();
}

void g2::uninit() {
	delete ace_rgb_rect;
	delete ace_rgb_prog;
}

namespace g2 {
    namespace Internal {
        float red;
        float green;
        float blue;

        glm::mat4 WinOrtho;

        // 0: none, 1: quad, 2: texture
        int beginType;

        // texture
        GLuint textureId;

        // quad
        int quadIndex;
    
        float quadRed[4];
        float quadGreen[4];
        float quadBlue[4];

        float quadLeft;
        float quadBottom;
        float quadWidth;
        float quadHeight;

		//
		AceRgbRect* ace_rgb_rect;
		AceProgram* ace_rgb_prog;
    }
}

