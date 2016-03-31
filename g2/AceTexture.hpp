#pragma once

class AceTexture {

public:
	int w, h;
	GLuint tid;

public:
    AceTexture() {
        glGenTextures(1, &tid);

        glBindTexture(GL_TEXTURE_2D, tid);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    AceTexture(int w, int h) {
        this->w = w;
        this->h = h;

        glGenTextures(1, &tid);

        glBindTexture(GL_TEXTURE_2D, tid);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    ~AceTexture() {
        if (imageData) {
            delete imageData;
        }

        glDeleteTextures(1, &tid);
    }

    void loadRgb(const char* filename) {
        imageData = SOIL_load_image(filename, &w, &h, 0, SOIL_LOAD_RGB);

        glBindTexture(GL_TEXTURE_2D, tid);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    }

	void loadAlpha(unsigned char* buffer, int w, int h) {		

		glBindTexture(GL_TEXTURE_2D, tid);

		this->w = w;
		this->h = h;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, w, h, 0, GL_ALPHA, GL_UNSIGNED_BYTE, buffer);
	}
	
	void activate() {
        glBindTexture(GL_TEXTURE_2D, tid);
    }

	void deactivate() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

private:
	unsigned char* imageData = 0;
	
};