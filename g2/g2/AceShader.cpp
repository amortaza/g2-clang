#include "stdafx.h"

#include "AceShader.hpp"

using namespace std;

AceShader::AceShader(const char* filename, GLuint type) {
    shaderId = glCreateShader(type);

    string shaderSrc = readFile(filename);
    const char* shaderSrcPtr = shaderSrc.c_str();

    glShaderSource(shaderId, 1, &shaderSrcPtr, NULL);
    glCompileShader(shaderId);

    checkCompilation();
}

AceShader::~AceShader() {
    glDeleteShader(shaderId);
}


void AceShader::checkCompilation() {
    GLint status;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);

    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shaderId, infoLogLength, NULL, strInfoLog);

        cout << "Failed to compile shader:" << strInfoLog << endl;
        delete[] strInfoLog;

        throw "Failed to compile shader.";
    }
}

string AceShader::readFile(const char* filename) {
    string str;
    ifstream stream(filename, ios::in);

    if (stream.is_open()){
        string line = "";

        while (getline(stream, line))
            str += "\n" + line;

        stream.close();
    }
    else {
        cout << "Could not read file " << filename << endl;
        throw "error";
    }

    return str;
}
