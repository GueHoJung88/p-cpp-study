#include "game/Game.hpp"
#include "core/Window.hpp"
#include "renderer/Renderer.hpp"
#include "ecs/Registry.hpp"
#include "ecs/systems/RenderSystem.hpp"
#include "ecs/components/Components.hpp"
#include <SDL2/SDL.h>
#include <iostream>

const int Game::WINDOW_WIDTH = 1024;  // 적절한 값으로 초기화
const int Game::WINDOW_HEIGHT = 768;

Game::Game() : running_(false), deltaTime_(0.0f) {}

Game::~Game() {
    shutdown();
}

bool Game::initialize() {
    // Create window
    window_ = std::make_unique<Window>(WINDOW_WIDTH, WINDOW_HEIGHT, "Super Mario ECS");

    // Create renderer
    renderer_ = std::make_unique<Renderer>();
    if (!renderer_->initialize(WINDOW_WIDTH, WINDOW_HEIGHT)) {
        std::cerr << "Failed to initialize renderer" << std::endl;
        return false;
    }

    // Create ECS registry
    registry_ = std::make_unique<Registry>();

    // Create systems
    systems_.push_back(std::make_unique<RenderSystem>(*renderer_));

    // Create a test entity
    Entity testEntity = registry_->createEntity();
    registry_->addComponent<Transform>(testEntity, {glm::vec2(400, 300), glm::vec2(1.0f), 0.0f});
    registry_->addComponent<Sprite>(testEntity, {renderer_->loadTexture(""), glm::vec2(64, 64), glm::vec4(1.0f)});

    running_ = true;
    std::cout << "Game initialized successfully!" << std::endl;
    return true;
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();

    while (running_ && !window_->shouldClose()) {
        Uint32 currentTime = SDL_GetTicks();
        deltaTime_ = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        handleInput();
        update(deltaTime_);
        render();

        window_->swapBuffers();

        // Cap to 60 FPS
        SDL_Delay(1);
    }
}

void Game::shutdown() {
    systems_.clear();
    registry_.reset();
    renderer_.reset();
    window_.reset();
}

void Game::update(float deltaTime) {
    // Update all systems
    for (auto& system : systems_) {
        system->update(deltaTime, *registry_);
    }
}

void Game::render() {
    renderer_->clear(0.2f, 0.3f, 0.8f, 1.0f);

    // Systems handle their own rendering
    // RenderSystem is called in update()
}

void Game::handleInput() {
    window_->pollEvents();
}
