#include "stdafx.h"
#include "Main.h"

using namespace std;

void OnTick() {
	try
	{
		Draw();
	}
	catch (char* msg) {
		printf(msg);
		printf("\n");
	}

    Xel::Swap();
}

int main(int argc, char** argv) {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Xel::Init();

    Xel::Window::SetCallbacks(OnResize, Init_OnGL, UnInit);

    Xel::Mouse::SetCallbacks(
        OnMouseMove,
        OnMouseButton,
        OnMouseScroll);

    Xel::Keyboard::SetCallbacks(
        OnKeyDown,
        OnKeyUp);

    Xel::Window::SetTitle("Bellina v0.1.0");
    Xel::Window::SetPosition(200, 100);
    Xel::Window::SetSize(1280, 800);

    Xel::Loop(OnTick);

	printf("Good bye\n");
	return 0;
}

