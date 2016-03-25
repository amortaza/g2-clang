#pragma once

class AceShader {

public:
    GLuint shaderId;

public:
    AceShader(const char* filename, GLuint type) {
        shaderId = glCreateShader(type);

        std::string shaderSrc = readFile(filename);
        const char* shaderSrcPtr = shaderSrc.c_str();

        glShaderSource(shaderId, 1, &shaderSrcPtr, NULL);
        glCompileShader(shaderId);

        checkCompilation();
    }

    ~AceShader() {
        glDeleteShader(shaderId);
    }

private:
    void checkCompilation() {
        GLint status;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            GLint infoLogLength;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

            GLchar *strInfoLog = new GLchar[infoLogLength + 1];
            glGetShaderInfoLog(shaderId, infoLogLength, NULL, strInfoLog);

            std::cout << "Failed to compile shader:" << strInfoLog << std::endl;
            delete[] strInfoLog;

            throw "Failed to compile shader.";
        }
    }

    std::string readFile(const char* filename) {
        std::string str;
        std::ifstream stream(filename, std::ios::in);

        if (stream.is_open()){
            std::string line = "";

            while (getline(stream, line))
                str += "\n" + line;

            stream.close();
        }
        else {
            std::cout << "Could not read file " << filename << std::endl;
            throw "error";
        }

        return str;
    }
};