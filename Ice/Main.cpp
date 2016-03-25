#include "stdafx.h"
#include "Main.h"

void OnTick() {
    Draw();

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

    Xel::Window::SetTitle("Bellina v0.01");
    Xel::Window::SetPosition(200, 100);
    Xel::Window::SetSize(1280, 800);

    Xel::Loop(OnTick);

    std::cout << "good bye." << std::endl;	return 0;
}

