#include "stdafx.h"

#include "g2/AceTexture.hpp"

AceTexture::AceTexture() {
	glGenTextures(1, &tid);

	glBindTexture(GL_TEXTURE_2D, tid);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

AceTexture::AceTexture(int w, int h) {
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

AceTexture::~AceTexture() {
	if (imageData) {
		delete imageData;
	}

	glDeleteTextures(1, &tid);
}

void AceTexture::loadRgb(const char* filename) {
	imageData = SOIL_load_image(filename, &w, &h, 0, SOIL_LOAD_RGB);

	glBindTexture(GL_TEXTURE_2D, tid);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
}

void AceTexture::loadRgba(const char* filename) {
	imageData = SOIL_load_image(filename, &w, &h, 0, SOIL_LOAD_AUTO);

	glBindTexture(GL_TEXTURE_2D, tid);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
}

void AceTexture::loadAlpha(unsigned char* buffer, int w, int h) {

	glBindTexture(GL_TEXTURE_2D, tid);

	this->w = w;
	this->h = h;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, w, h, 0, GL_ALPHA, GL_UNSIGNED_BYTE, buffer);
}

void AceTexture::activate() {
	glBindTexture(GL_TEXTURE_2D, tid);
}

void AceTexture::activate2() {
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, tid);
	glActiveTexture(GL_TEXTURE0);
}

void AceTexture::deactivate2() {
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(GL_TEXTURE0);
}

void AceTexture::deactivate() {
	glBindTexture(GL_TEXTURE_2D, 0);
}
