#include "stdafx.h"

#include <map>

#include "free_font.h"
#include "g2.h"

using namespace g2;
using namespace g2::Internal;

void g2::opacity(float alpha) {
	current_alpha = alpha;
}

void g2::opacity2(float alpha) {
	alpha2 = alpha;
}

void g2::ortho(int width, int height) {
    WinOrtho = glm::ortho(0.f, (float)width, (float)height, 0.f);
}

void g2::pushOrtho() {
	orthoStack.push(WinOrtho);
}

void g2::popOrtho() {
	WinOrtho = orthoStack.top();
	orthoStack.pop();
}

void g2::viewport(int width, int height) {
	viewportWidth = width;
	viewportHeight = height;

    glViewport(0, 0, width, height);
}

void g2::pushViewport() {
	viewportStack2.push(viewportWidth);
	viewportStack2.push(viewportHeight);
}

void g2::popViewport() {
	int h = viewportStack2.top();
	viewportStack2.pop();

	int w = viewportStack2.top();
	viewportStack2.pop();

	viewport(w, h);
}

void g2::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void g2::init() {
	glClearColor(0.0f, 0.0f, 1.0f, 0.5f);

	glActiveTexture(GL_TEXTURE0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);

	// blending is required to be able to render text
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	ace_rgb_prog = new AceProgram("c:/_c/g2/shader/rgb_rect.vertex.txt", "c:/_c/g2/shader/rgb_rect.fragment.txt");
	ace_texture_prog = new AceProgram("c:/_c/g2/shader/texture_rect.vertex.txt", "c:/_c/g2/shader/texture_rect.fragment.txt");
	ace_atlas_prog = new AceProgram("c:/_c/g2/shader/atlas_rect.vertex.txt", "c:/_c/g2/shader/atlas_rect.fragment.txt");

	ace_rgb_rect = new AceRgbRect();
	ace_texture_rect = new AceTextureRect();

	font("arial", 24);
}

void g2::Internal::freeMaps() {
	typedef std::map<std::string, Atlas*>::iterator it1;
	typedef std::map<std::string, TextureRef*>::iterator it2;

	for (it1 it = atlasMap.begin(); it != atlasMap.end(); it++) {
		Atlas* atlas = it->second;

		delete atlas;
	}

	atlasMap.clear();

	for (it2 it = atlasRefMap.begin(); it != atlasRefMap.end(); it++) {
		TextureRef* ref = it->second;

		delete ref;
	}

	atlasRefMap.clear();
}

void g2::uninit() {
	freeMaps();

	delete ace_atlas_prog;
	delete ace_texture_prog;
	delete ace_rgb_prog;

	delete ace_rgb_rect;
	delete ace_texture_rect;

	// no need to free current_atlas;
	// no need to free current_atlas_ref;

	// no need to free current_ace_texture
}



