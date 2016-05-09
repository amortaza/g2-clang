#pragma once

#include "AceTexture.hpp"

extern class AceProgram;

class AceTextureGlyph {

public:

	AceTextureGlyph();

	~AceTextureGlyph();

	void draw(AceProgram* prog,
		AceTexture* texture,
		int charX, int charW, int charH, int atlasWidth,
		int left, int top,
		glm::mat4* Projection,
		float font_red, float font_green, float font_blue,
		float alpha);

private:
	GLuint vid;

	void setVertexData(int left, int top, int charX, int charW, int charH, int atlasWidth);
};