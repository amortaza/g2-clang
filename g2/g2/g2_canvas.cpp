#include "stdafx.h"

using namespace std;

#include "CanvasRef.h"

#include "g2/AceFramebuffer.hpp"
#include "g2/g2_canvas.h"
#include "g2/g2_core.h"

using namespace g2;

CanvasRef* current_canvas = 0;

stack<CanvasRef*> canvasStack;

extern AceTexture* current_ace_texture;

CanvasRef* g2::createCanvas(int w, int h) {
	CanvasRef* canvas = new CanvasRef(w, h);	

	return canvas;
}

void g2::paintCanvas(CanvasRef* canvas) {	
	if (current_canvas != 0) 
		canvasStack.push(current_canvas);

	current_canvas = canvas;

	pushOrtho();
	pushViewport();

	current_canvas->ace_frame_buffer->begin();

	AceTexture* texture = canvas->ace_frame_buffer->texture;
	viewport(texture->w, texture->h);
	ortho(texture->w, texture->h);
}

void g2::endCanvas() {
	current_canvas->ace_frame_buffer->end();

	if (canvasStack.size() > 0) {
		current_canvas = canvasStack.top();
		canvasStack.pop();

		current_canvas->ace_frame_buffer->begin();
	}
	else
		current_canvas = 0;

	popOrtho();
	popViewport();
}