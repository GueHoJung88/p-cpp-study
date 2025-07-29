#pragma once
#include "ecs/System.hpp"

class Renderer;

class RenderSystem : public System {
public:
    RenderSystem(Renderer& renderer);
    ~RenderSystem() override = default;

    void update(float deltaTime, Registry& registry) override;

private:
    Renderer& renderer_;
};
