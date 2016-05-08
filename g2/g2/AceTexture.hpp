#pragma once

class AceTexture {

public:
	int w, h;
	GLuint tid;

public:
	AceTexture();
	AceTexture(int w, int h);

	~AceTexture();

	void loadRgb(const char* filename);

	void loadRgba(const char* filename);

	void loadAlpha(unsigned char* buffer, int w, int h);
	
	void activate();
	void activate2();

	void deactivate();
	void deactivate2();

private:
	unsigned char* imageData = 0;
	
};