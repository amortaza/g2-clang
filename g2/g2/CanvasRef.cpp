#include "stdafx.h"

#include "AceFramebuffer.hpp"
#include "CanvasRef.h"

using namespace g2;

CanvasRef::CanvasRef(int w, int h) {
	ace_frame_buffer = new AceFramebuffer(w, h);
}

CanvasRef::~CanvasRef() {
	delete ace_frame_buffer;
	//test new AceFramebuffer();
}
