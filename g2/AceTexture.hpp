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

    void load(const char* filename) {
        imageData = SOIL_load_image(filename, &w, &h, 0, SOIL_LOAD_RGB);

        glBindTexture(GL_TEXTURE_2D, tid);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    }

    void activate() {
        glBindTexture(GL_TEXTURE_2D, tid);
    }

private:
	unsigned char* imageData = 0;
	
};