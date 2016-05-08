#pragma once

#include "AceShader.hpp"

class AceProgram {

public:
    AceShader* vShader;
    AceShader* fShader;

    GLuint programId;

    GLint uProjection;
	GLint uGlyphColor;
	GLint uAlpha;
	GLint uAlphaLeftTopRightBottom;

public:
	AceProgram(const char* vFilename, const char* fFilename);

	~AceProgram();

	void activate();
};