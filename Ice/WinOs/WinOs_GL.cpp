#include "stdafx.h"

namespace WinOs {

    namespace GL {

        HGLRC g_glrc;
        HDC   g_hdc;

        void Create(HWND hwnd) {

            PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),                              // nSize
                1,                                                          // nVersion
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, // dwFlags
                PFD_TYPE_RGBA,                                              // iPixelType
                32,                                                         // cColorBits
                0, 0, 0, 0, 0, 0,
                0, 0,
                0,                  // AccumBits
                0, 0, 0, 0,
                32,                 // Depth
                8,                  // Stencil
                0,                  // Aux
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
            };

            g_hdc = GetDC(hwnd); 

            int pixelFormat = ChoosePixelFormat(g_hdc, &pfd);

            SetPixelFormat(g_hdc, pixelFormat, &pfd);

            g_glrc = wglCreateContext(g_hdc);

            wglMakeCurrent (g_hdc, g_glrc);
        }

        void Delete(HWND hwnd) {
            std::cout << "Deleting GL RC Context" << std::endl;

            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(g_glrc);

            std::cout << "Releacing DC" << std::endl;
            ReleaseDC(hwnd, g_hdc);

            std::cout << "Destroying Window" << std::endl;
            DestroyWindow(hwnd);

            std::cout << "Unregistring class" << std::endl;
            UnregisterClass("AceWindowClass", GetModuleHandle(0));
        }
    }
}