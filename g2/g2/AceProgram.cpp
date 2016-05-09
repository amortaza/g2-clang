#include "stdafx.h"

#include "AceProgram.hpp"
#include "AceShader.hpp"

AceProgram::AceProgram(const char* vFilename, const char* fFilename) {
    vShader = new AceShader(vFilename, GL_VERTEX_SHADER);
    fShader = new AceShader(fFilename, GL_FRAGMENT_SHADER);

    programId = glCreateProgram();

    glAttachShader(programId, vShader->shaderId);
    glAttachShader(programId, fShader->shaderId);

    glLinkProgram(programId);

    glUseProgram(programId);

    uProjection = glGetUniformLocation(programId, "uProjection");
	uGlyphColor = glGetUniformLocation(programId, "uGlyphColor");
	uAlpha = glGetUniformLocation(programId, "uAlpha");
	uAlphaLeftTopRightBottom = glGetUniformLocation(programId, "uAlphaLeftTopRightBottom");

	GLint texture1 = glGetUniformLocation(programId, "uSampler1");
	if (texture1 > -1) {
		glUniform1i(texture1, 1);
	}
}

AceProgram::~AceProgram() {
    glDetachShader(programId, vShader->shaderId);
    glDetachShader(programId, fShader->shaderId);

    delete vShader;
    delete fShader;

	//test new AceShader();
}

void AceProgram::activate() {
    glUseProgram(programId);
}
