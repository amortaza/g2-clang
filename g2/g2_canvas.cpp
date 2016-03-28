#include "stdafx.h"

#include "AceFramebuffer.hpp"
#include "g2_canvas.h"
#include "g2_core.h"

using namespace g2;

CanvasRef* current_canvas = 0;

std::stack<CanvasRef*> canvasStack;

extern AceTexture* current_ace_texture;

CanvasRef* g2::createCanvas(int w, int h) {
	CanvasRef* canvas = new CanvasRef(w, h);	

	return canvas;
}

void g2::paintCanvas(CanvasRef* canvas) {	
	if (current_canvas != 0) canvasStack.push(current_canvas);

	current_canvas = canvas;

	pushOrtho();
	pushViewport();

	current_canvas->ace_frame_buffer->begin();
}

void g2::endCanvas() {
	current_canvas->ace_frame_buffer->end();

	if (canvasStack.size() > 0) {
		current_canvas = canvasStack.top();
		canvasStack.pop();
	}
	else
		current_canvas = 0;

	popOrtho();
	popViewport();
}