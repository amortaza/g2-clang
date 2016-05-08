#include "stdafx.h"

#include "AceTexture.hpp"
#include "AceFramebuffer.hpp"

AceFramebuffer::AceFramebuffer(int w, int h) {
    texture = new AceTexture(w, h);

    glGenFramebuffers(1, &framebufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture->tid, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

AceFramebuffer::~AceFramebuffer() {
    delete texture;

    glDeleteFramebuffers(1, &framebufferId);
}

void AceFramebuffer::begin() {
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

    glViewport(0, 0, texture->w, texture->h);
}

void AceFramebuffer::end() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
