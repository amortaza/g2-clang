#pragma once

#include "AceTexture.hpp"

class AceFramebuffer {

public:
    GLuint framebufferId;
    AceTexture* texture;

public:

	AceFramebuffer(int w, int h);
	~AceFramebuffer();

	void begin();
	void end();
};