#pragma once
#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void swapBuffers();
    bool shouldClose() const;
    void pollEvents();

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }

private:
    SDL_Window* window_;
    SDL_GLContext glContext_;
    int width_;
    int height_;
    bool shouldClose_;
};
