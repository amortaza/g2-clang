#pragma once

extern class AceTexture;

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