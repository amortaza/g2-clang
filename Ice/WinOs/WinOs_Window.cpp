#include "stdafx.h"

#include "WinOs.h"

namespace WinOs {

    namespace Internal {

        void RegisterWindowClass(WNDPROC wndProc) {
            WNDCLASSEX wc;

            wc.cbSize        = sizeof(WNDCLASSEX);
            wc.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
            wc.lpfnWndProc   = wndProc;
            wc.cbClsExtra    = 0;
            wc.cbWndExtra    = 0;
            wc.hInstance     = GetModuleHandle(0);
            wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
            wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
            wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
            wc.lpszMenuName  = NULL;
            wc.lpszClassName = "AceWindowClass";
            wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

            if (!RegisterClassEx(&wc))
                throw "Failed to register window class.";
        }

        HWND CreateMainWindowEx() {
            HWND hwnd = CreateWindowEx(
                    WS_EX_CLIENTEDGE,
                    "AceWindowClass",
                    "The title of my window",
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    800,
                    600,
                    NULL,
                    NULL,
                    GetModuleHandle(0),
                    NULL);

            if (hwnd == NULL)
                throw "Could not create window handle.";

            return hwnd;
        }
    }

    namespace Window {

        HWND g_hwnd;

        void CreateMainWindow(WNDPROC wndProc) {
            Internal::RegisterWindowClass(wndProc);

            g_hwnd = Internal::CreateMainWindowEx();

            ShowWindow(g_hwnd, SW_SHOW);
            UpdateWindow(g_hwnd);
        }

        void SwapBuffers() {
            SwapBuffers(GL::g_hdc);
        }

        void SetPosition(int left, int top) {
            SetWindowPos(g_hwnd, 0, left, top, -1, -1, SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW);
        }

        void SetSize(int width, int height) {
            SetWindowPos(g_hwnd, 0, -1, -1, width, height, SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW);
        }

        void SetTitle(char* title) {
            SetWindowText(g_hwnd, title);
        }

        void Close() {
            PostMessage(Window::g_hwnd, WM_QUIT, 0, 0);
        }
    }
}