#include "stdafx.h"

#include "WinOs/WinOs.h"

#include "Xel/Xel_WndProc.h"
#include "Xel/Xel_Window.h"

namespace Xel {

    void Init() {
        WinOs::Window::CreateMainWindow(_WndProc);
    }

	void Swap() {
		WinOs::Window::SwapBuffers();
	}

    void Close() {
        WinOs::Window::Close();
    }

    void Loop(void (*TickCallback)() ) {
        MSG msg;

        while (true) {
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) == TRUE) {
                if (msg.message == WM_QUIT) 
					return;

                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            // Resize must have been called once
            if (Window::Internal::g_ResizeCount > 0) 
				TickCallback();
        }
    }
}
