#pragma once

#include "AceTexture.hpp"

class AceTextureRect {

public:

	AceTextureRect() {
        glGenBuffers(1, &vid);
    }

    ~AceTextureRect() {
        glDeleteBuffers(1, &vid);
    }

    void draw(AceProgram* prog, AceTexture* texture, int left, int top, int w, int h, glm::mat4* Projection, float* alphas, float topTextureCoord) {
        prog->activate();

        texture->activate();

        setVertexData(left, top, w, h, topTextureCoord);

		glUniformMatrix4fv(prog->uProjection, 1, GL_FALSE, glm::value_ptr((*Projection)));

		glUniform4f(prog->uAlphaLeftTopRightBottom, alphas[0], alphas[1], alphas[2], alphas[3]);

		glBindBuffer(GL_ARRAY_BUFFER, vid);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)64);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}

	void drawAtlasChar(	AceProgram* prog, 
					    AceTexture* texture, 
		                int charX, int charW, int charH, int atlasWidth, 
					    int left, int top, 
						glm::mat4* Projection,
						float font_red, float font_green, float font_blue,
						float alpha) {

		prog->activate();

		texture->activate();

		setVertexData2(left, top, charX, charW, charH, atlasWidth);

		glUniform4f(prog->uGlyphColor, font_red, font_green, font_blue, alpha);

		glUniformMatrix4fv(prog->uProjection, 1, GL_FALSE, glm::value_ptr((*Projection)));

		glBindBuffer(GL_ARRAY_BUFFER, vid);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)64);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}

private:
	GLuint vid;

	void setVertexData2(int left, int top, int charX, int charW, int charH, int atlasWidth) {
		int right = left + charW;
		int bottom = top + charH;

		float sLeft = (float)charX / (float)atlasWidth;
		float sRight = (float)(charX+charW) / (float)atlasWidth;

		const float vertexData[] = {
			left, bottom, 0.0f, 1.f, // 4*4 = 16
			left, top, 0.0f,  1.f,
			right, top, 0.0f,  1.f,
			right, bottom, 0.0f,  1.f, // 16*4 = 64

			sLeft, 1.f,
			sLeft, 0.0f,
			sRight, 0.0f,
			sRight, 1.0f
		};

		glBindBuffer(GL_ARRAY_BUFFER, vid);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	void setVertexData(int left, int top, int w, int h, float topTextureCoord) {
        int right = left + w;
        int bottom = top + h;

        const float vertexData[] = {
            left, bottom, 0.0f, 1.0f, // 4*4 = 16
            left, top, 0.0f, 1.0f,
            right, top, 0.0f, 1.0f,
            right, bottom, 0.0f, 1.0f, // 16*4 = 64

            0.0f, topTextureCoord,
            0.0f, 1.f - topTextureCoord,
            1.0f, 1.f - topTextureCoord,
            1.0f, topTextureCoord
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};