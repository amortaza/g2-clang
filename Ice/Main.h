#pragma once

void Draw();

void Init_OnGL();
void UnInit();

void OnMouseMove(int x, int y);
void OnMouseButton(Xel::Mouse::Button button, Xel::Mouse::Action action, int x, int y);
void OnMouseScroll(int amount);

void OnKeyDown(unsigned long long xcode);
void OnKeyUp(unsigned long long xcode);
void OnResize(int w, int h);
