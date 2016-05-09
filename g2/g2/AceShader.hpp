#pragma once

using namespace std;

class AceShader {

public:
    GLuint shaderId;

public:
	AceShader(const char* filename, GLuint type);
	~AceShader();

private:
	void checkCompilation();

	string readFile(const char* filename);
};