#pragma once

#include "AceTexture.hpp"

class AceFramebuffer {

public:
    GLuint framebufferId;
    AceTexture* texture;

public:

    AceFramebuffer(int w, int h) {
        texture = new AceTexture(w, h);

        glGenFramebuffers(1, &framebufferId);
        glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
        glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture->tid, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    ~AceFramebuffer() {
        delete texture;

        glDeleteFramebuffers(1, &framebufferId);
    }

    void begin() {
        glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

        glViewport(0, 0, texture->w, texture->h);
    }

    void end() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

};