#include "stdafx.h"

#include "WinOs/WinOs.h"

#include "Xel/Xel_WndProc.h"
#include "Xel/Xel_Mouse.h"
#include "Xel/Xel_Keyboard.h"
#include "Xel/Xel_Window.h"

#ifndef GET_XBUTTON_WPARAM
#   define GET_XBUTTON_WPARAM(w) (HIWORD(w))
#endif

namespace Xel {
    
    namespace Internal {
        void HandleResize(int w, int h){

            if (Window::Internal::g_ResizeCount > 0) {

                Xel::Window::width = w;
                Xel::Window::height = h;

                glViewport(0, 0, w, h);

                if (Window::Internal::g_OnResize)
                    Window::Internal::g_OnResize(w, h);
            }

            ++Window::Internal::g_ResizeCount;
        }

        bool IsMouseMsg(UINT msg) {
            return msg == WM_MOUSEMOVE
                    || msg == WM_LBUTTONDOWN
                    || msg == WM_LBUTTONUP
                    || msg == WM_RBUTTONDOWN
                    || msg == WM_RBUTTONUP
                    || msg == WM_MBUTTONDOWN
                    || msg == WM_MBUTTONUP
                    || msg == WM_XBUTTONDOWN
                    || msg == WM_XBUTTONUP
                    || msg == WM_MOUSEWHEEL;
        }

        void HandleMouseEvent(UINT msg, WPARAM wParam, LPARAM lParam) {
            int x = GET_X_LPARAM(lParam);
            int y = GET_Y_LPARAM(lParam);

            if (msg == WM_MOUSEMOVE)
                Mouse::Internal::g_OnMove(x, y);

            else if (msg == WM_LBUTTONDOWN)
                Mouse::Internal::g_OnButton(Mouse::Left, Mouse::Action::Down, x, y);

            else if (msg == WM_LBUTTONUP)
                Mouse::Internal::g_OnButton(Mouse::Left, Mouse::Action::Up, x, y);

            else if (msg == WM_RBUTTONDOWN)
                Mouse::Internal::g_OnButton(Mouse::Right, Mouse::Action::Down, x, y);

            else if (msg == WM_RBUTTONUP)
                Mouse::Internal::g_OnButton(Mouse::Right, Mouse::Action::Up, x, y);

            else if (msg == WM_MBUTTONDOWN)
                Mouse::Internal::g_OnButton(Mouse::Middle, Mouse::Action::Down, x, y);

            else if (msg == WM_MBUTTONUP)
                Mouse::Internal::g_OnButton(Mouse::Middle, Mouse::Action::Up, x, y);

            else if (msg == WM_XBUTTONDOWN) {
                int xbutton = GET_XBUTTON_WPARAM (wParam);

                if (xbutton == XBUTTON1)
                    Mouse::Internal::g_OnButton(Mouse::X1, Mouse::Action::Down, x, y);

                else if (xbutton == XBUTTON2)
                    Mouse::Internal::g_OnButton(Mouse::X2, Mouse::Action::Down, x, y);
            }

            else if (msg == WM_XBUTTONUP) {
                int xbutton = GET_XBUTTON_WPARAM (wParam);

                if (xbutton == XBUTTON1)
                    Mouse::Internal::g_OnButton(Mouse::X1, Mouse::Action::Up, x, y);

                else if (xbutton == XBUTTON2)
                    Mouse::Internal::g_OnButton(Mouse::X2, Mouse::Action::Up, x, y);
            }

            else if (msg == WM_MOUSEWHEEL)
                Mouse::Internal::g_OnScroll(GET_WHEEL_DELTA_WPARAM(wParam));
        }

        void HandleKeyboardEvent(UINT msg, WPARAM wParam, LPARAM lParam) {
            unsigned long long  previousState = lParam & 0x40000000;

            if (msg == WM_KEYDOWN && previousState == 0 /* up */ )
                Keyboard::Internal::g_OnDown(Xel::Keyboard::Internal::VirtualCodeToXCode(wParam));

            else if (msg == WM_KEYUP )
                Keyboard::Internal::g_OnUp(Xel::Keyboard::Internal::VirtualCodeToXCode(wParam));
        }
    }

    LRESULT CALLBACK _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

        if (Internal::IsMouseMsg(msg))
            Internal::HandleMouseEvent(msg, wParam, lParam);
        
        else if (msg == WM_KEYDOWN || msg == WM_KEYUP)
            Internal::HandleKeyboardEvent(msg, wParam, lParam);

        else if (msg == WM_SIZE)
            Internal::HandleResize(LOWORD(lParam), HIWORD(lParam));

        else if (msg == WM_CREATE) {
            WinOs::GL::Create(hwnd);
            glewInit();

            std::cout << "OpenGL/GLEW context created" << std::endl;
        }

        else if (msg == WM_CLOSE) {
            Xel::Window::Internal::g_OnBeforeGLDeleted();

            WinOs::GL::Delete(hwnd);
        }

        else if (msg == WM_DESTROY)
            PostQuitMessage(0);

        else
            return DefWindowProc(hwnd, msg, wParam, lParam);

        return 0;
    }
}

