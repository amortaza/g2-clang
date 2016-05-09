#pragma once

extern class AceShader;

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