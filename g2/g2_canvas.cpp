#include "stdafx.h"

#include "AceFramebuffer.hpp"
#include "g2_canvas.h"

using namespace g2;

extern CanvasRef* current_canvas;
extern AceTexture* current_ace_texture;

CanvasRef* g2::createCanvas(int w, int h) {
	CanvasRef* canvas = new CanvasRef(w, h);	

	return canvas;
}

void g2::beginCanvas(CanvasRef* canvas) {	
	current_canvas = canvas;
	current_ace_texture = canvas->ace_frame_buffer->texture;

	current_canvas->ace_frame_buffer->begin();
}

void g2::endCanvas() {
	current_canvas->ace_frame_buffer->end();
	current_canvas = 0;
	current_ace_texture = 0;
}