#pragma once

#include "AceProgram.hpp"
#include "AceTexture.hpp"

class AceTextureRect {

public:

	AceTextureRect() {
        glGenBuffers(1, &vid);
    }

    ~AceTextureRect() {
        glDeleteBuffers(1, &vid);
    }

    void draw(AceProgram* prog, AceTexture* texture, int left, int bottom, int w, int h, glm::mat4* Projection) {
        prog->activate();

        texture->activate();

        setVertexData(left, bottom, w, h);

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

	void drawAtlasSub(	AceProgram* prog, 
					    AceTexture* texture, 
		                int charX, int charW, int charH, int atlasWidth, 
					    int left, int bottom, 
						glm::mat4* Projection) {

		prog->activate();

		texture->activate();

		setVertexData2(left, bottom, charX, charW, charH, atlasWidth);

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

	void setVertexData2(int left, int bottom, int charX, int charW, int charH, int atlasWidth) {
		int right = left + charW;
		int top = bottom + charH;

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
	
	void setVertexData(int left, int bottom, int w, int h) {
        int right = left + w;
        int top = bottom + h;

        const float vertexData[] = {
            left, bottom, 0.0f, 1.0f, // 4*4 = 16
            left, top, 0.0f, 1.0f,
            right, top, 0.0f, 1.0f,
            right, bottom, 0.0f, 1.0f, // 16*4 = 64

            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};