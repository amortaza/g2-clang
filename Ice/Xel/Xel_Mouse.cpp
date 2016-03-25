#include "stdafx.h"

#include "Xel/Xel_Mouse.h"
#include "WinOs/WinOs.h"

namespace Xel {

    namespace Mouse {

        namespace Internal {
            void (*g_OnMove)(int x, int y);

            void (*g_OnButton)(Button button, Action action, int x, int y);

            void (*g_OnScroll)(int amount);
        }

        void SetCallbacks(  void (*OnMove)(int x, int y),
                            void (*OnButton)(Button button, Action action, int x, int y),
                            void (*OnScroll)(int amount) ) {

            Internal::g_OnMove      = OnMove;
            Internal::g_OnButton    = OnButton;
            Internal::g_OnScroll    = OnScroll;
        }

        void Capture() {
            SetCapture( WinOs::Window::g_hwnd);
        }

        void Release() {
            ReleaseCapture();
        }
    }
}