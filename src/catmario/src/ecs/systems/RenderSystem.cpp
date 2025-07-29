#include "ecs/systems/RenderSystem.hpp"
#include "ecs/Registry.hpp"
#include "ecs/components/Components.hpp"
#include "renderer/Renderer.hpp"

RenderSystem::RenderSystem(Renderer& renderer) : renderer_(renderer) {}

void RenderSystem::update(float deltaTime, Registry& registry) {
    // Get all entities that have both Transform and Sprite components
    auto entities = registry.getEntitiesWith<Transform, Sprite>();

    for (Entity entity : entities) {
        auto& transform = registry.getComponent<Transform>(entity);
        auto& sprite = registry.getComponent<Sprite>(entity);

        // Draw the sprite
        renderer_.drawSprite(
            sprite.textureID,
            transform.position,
            sprite.size,
            transform.rotation
        );
    }
}
