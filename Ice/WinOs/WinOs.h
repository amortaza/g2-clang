#pragma once

namespace WinOs {

    namespace Internal {

        void RegisterWindowClass(WNDPROC wndProc);

        HWND CreateMainWindowEx();
    }

    namespace Window {
        extern HWND g_hwnd;

        void CreateMainWindow(WNDPROC wndProc);

        void SwapBuffers();

        void SetPosition(int left, int top);

        void SetSize(int width, int height);

        void SetTitle(char* title);

        void Close();
    }
}

namespace WinOs {

    namespace GL {

        extern HGLRC g_glrc;
        extern HDC   g_hdc;

        void Create(HWND hwnd);
        void Delete(HWND hwnd);
    }
}
