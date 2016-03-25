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


    void draw(AceProgram* prog, int left, int bottom, int w, int h, glm::mat4* Projection, float r, float g, float b) {
        prog->activate();

        setVertexData(left, bottom, w, h, r, g, b);

        commonDraw(prog, Projection);
    }

    void draw(AceProgram* prog, int left, int bottom, int w, int h, glm::mat4* Projection, float* r4, float *g4, float *b4) {
        prog->activate();

        setVertexData(left, bottom, w, h, r4, g4, b4);

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
	
	void setVertexData(int left, int bottom, int w, int h, float r, float g, float b) {
        int right = left + w;
        int top = bottom + h;        

        const float vertexData[] = {
            left, bottom,    // 2 ints * 4 bytes per int = 8 bytes
            left, top,      
            right, top,     
            right, bottom,   // 8 bytes per row * 4 rows = 32 bytes

            r, g, b, 1.f,
            r, g, b, 1.f,
            r, g, b, 1.f,
            r, g, b, 1.f
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void setVertexData(int left, int bottom, int w, int h, float* r4, float* g4, float* b4) {
        int right = left + w;
        int top = bottom + h;

        const float vertexData[] = {
            left, bottom,    // 4*2 = 8
            left, top,      
            right, top,     
            right, bottom,   // 8*4 = 32

            r4[0], g4[0], b4[0], 1.f,
            r4[1], g4[1], b4[1], 1.f,
            r4[2], g4[2], b4[2], 1.f,
            r4[3], g4[3], b4[3], 1.f
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};