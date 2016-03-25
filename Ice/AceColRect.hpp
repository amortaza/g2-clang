#pragma once

#include "AceProgram.hpp"

class AceColRect {

public:
    GLuint vid;

public:

    AceColRect() {
        glGenBuffers(1, &vid);
    }

    ~AceColRect() {
        glDeleteBuffers(1, &vid);
    }

    void common(AceProgram* prog, glm::mat4* Projection) {
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

    void draw(AceProgram* prog, int left, int bottom, int w, int h, glm::mat4* Projection, float r, float g, float b) {
        prog->activate();

        setVertexData(left, bottom, w, h, r, g, b);

        common(prog, Projection);
    }

    void draw(AceProgram* prog, int left, int bottom, int w, int h, glm::mat4* Projection, float* r, float *g, float *b) {
        prog->activate();

        setVertexData(left, bottom, w, h, r, g, b);

        common(prog, Projection);
    }

private:
    void setVertexData(int left, int bottom, int w, int h, float r, float g, float b) {
        int right = left + w;
        int top = bottom + h;        

        const float vertexData[] = {
            left, bottom,    // 4*2 = 8
            left, top,      
            right, top,     
            right, bottom,   // 8*4 = 32

            r, g, b, 1.f,
            r, g, b, 1.f,
            r, g, b, 1.f,
            r, g, b, 1.f
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void setVertexData(int left, int bottom, int w, int h, float* r, float* g, float* b) {
        int right = left + w;
        int top = bottom + h;

        const float vertexData[] = {
            left, bottom,    // 4*2 = 8
            left, top,      
            right, top,     
            right, bottom,   // 8*4 = 32

            r[0], g[0], b[0], 1.f,
            r[1], g[1], b[1], 1.f,
            r[2], g[2], b[2], 1.f,
            r[3], g[3], b[3], 1.f
        };

        glBindBuffer(GL_ARRAY_BUFFER, vid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};