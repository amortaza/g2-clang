#pragma once

#include "AceShader.hpp"

class AceProgram {

public:
    AceShader* vShader;
    AceShader* fShader;

    GLuint programId;

    GLint uProjection;
    //GLint uSampler;

public:
    AceProgram(const char* vFilename, const char* fFilename) {
        vShader = new AceShader(vFilename, GL_VERTEX_SHADER);
        fShader = new AceShader(fFilename, GL_FRAGMENT_SHADER);

        programId = glCreateProgram();

        glAttachShader(programId, vShader->shaderId);
        glAttachShader(programId, fShader->shaderId);

        glLinkProgram(programId);

        glUseProgram(programId);

        uProjection = glGetUniformLocation(programId, "uProjection");
        //uSampler = glGetUniformLocation(programId, "uSampler");
    }

    ~AceProgram() {
        glDetachShader(programId, vShader->shaderId);
        glDetachShader(programId, fShader->shaderId);

        delete vShader;
        delete fShader;
    }

    void activate() {
        glUseProgram(programId);
    }
};