#pragma once
#include <memory>
#include <vector>

class Window;
class Renderer;
class Registry;
class System;

class Game {
public:
    Game();
    ~Game();

    bool initialize();
    void run();
    void shutdown();

private:
    void update(float deltaTime);
    void render();
    void handleInput();

    std::unique_ptr<Window> window_;
    std::unique_ptr<Renderer> renderer_;
    std::unique_ptr<Registry> registry_;
    std::vector<std::unique_ptr<System>> systems_;

    bool running_;
    float deltaTime_;

    static const int WINDOW_WIDTH;
    static const int WINDOW_HEIGHT;
};
