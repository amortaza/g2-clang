#pragma once

#include "AceProgram.hpp"

class AceRgbRect {

public:

    AceRgbRect() {
        glGenBuffers(1, &vid);
    }

    ~AceRgbRect() {
        glDeleteBuffers(1, &vid);
    }

    void draw(AceProgram* prog, int left, int top, int w, int h, glm::mat4* Projection, float r, float g, float b, float* alphas) {
        prog->activate();

        setVertexData(left, top, w, h, r, g, b, alphas);

        commonDraw(prog, Projection);
    }

	void drawHorizontalGradient(	AceProgram* prog, 
									int left, int top, int w, int h, glm::mat4* Projection,
									float r, float g, float b,
									float r2, float g2, float b2 ) {

		prog->activate();

		setVertexDataHorizontalGradient(left, top, w, h, r, g, b, r2, g2, b2);

		commonDraw(prog, Projection);
	}
	
	void drawVerticalGradient(AceProgram* prog,
		int left, int top, int w, int h, glm::mat4* Projection,
		float r, float g, float b,
		float r2, float g2, float b2) {

		prog->activate();

		setVertexDataVerticalGradient(left, top, w, h, r, g, b, r2, g2, b2);

		commonDraw(prog, Projection);
	}

private:

	GLuint vid;

	void commonDraw(AceProgram* prog, glm::mat4* Projection) {
		glUniformMatrix4fv(prog->uProjection, 1, GL_FALSE, glm::value_ptr((*Projection)));

		glBindBuffer(GL_ARRAY_BUFFER, vid);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)32);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
	
	void setVertexData(int left, int top, int w, int h, float r, float g, float b, float* alphasLeftTopRightBottom) {
        int right = left + w;
        int bottom = top + h;        

        const float vertexData[] = {
            left, bottom,    // 2 ints * 4 bytes per int = 8 bytes
            left, top,      
            right, top,     
            right, bottom,   // 8 bytes per row * 4 rows = 32 bytes

            r, g, b, alphasLeftTopRightBottom[0],
            r, g, b, alphasLeftTopRightBottom[1],
            r, g, b, alphasLeftTopRightBottom[2],
            r, g, b, alphasLeftTopRightBottom[3]
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

	void setVertexDataHorizontalGradient(int left, int top, int w, int h, float r, float g, float b, float r2, float g2, float b2) {
		int right = left + w;
		int bottom = top + h;

		const float vertexData[] = {
			left, bottom,    // 2 ints * 4 bytes per int = 8 bytes
			left, top,
			right, top,
			right, bottom,   // 8 bytes per row * 4 rows = 32 bytes

			r, g, b, 1.f,
			r, g, b, 1.f,
			r2, g2, b2, 1.f,
			r2, g2, b2, 1.f
		};

		glBindBuffer(GL_ARRAY_BUFFER, vid);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void setVertexDataVerticalGradient(int left, int top, int w, int h, float r, float g, float b, float r2, float g2, float b2) {
		int right = left + w;
		int bottom = top + h;

		const float vertexData[] = {
			left, bottom,    // 2 ints * 4 bytes per int = 8 bytes
			left, top,
			right, top,
			right, bottom,   // 8 bytes per row * 4 rows = 32 bytes

			r, g, b, 1.f,
			r2, g2, b2, 1.f,
			r2, g2, b2, 1.f,
			r, g, b, 1.f
		};

		glBindBuffer(GL_ARRAY_BUFFER, vid);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
};