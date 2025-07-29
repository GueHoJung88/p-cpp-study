#include "ecs/Registry.hpp"
#include <queue>
#include <stdexcept>


Registry::Registry() {
    // Initialize available entities queue
    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
        availableEntities_.push(entity);
    }
}

Registry::~Registry() {
    // Cleanup handled by smart pointers
}

Entity Registry::createEntity() {
    if (availableEntities_.empty()) {
        throw std::runtime_error("Too many entities in existence.");
    }

    Entity id = availableEntities_.front();
    availableEntities_.pop();
    ++livingEntityCount_;

    return id;
}

void Registry::destroyEntity(Entity entity) {
    if (entity >= MAX_ENTITIES) {
        throw std::runtime_error("Entity out of range.");
    }

    // Clear the entity's mask
    entityMasks_[entity].reset();

    // Notify each component array that an entity has been destroyed
    for (auto const& pair : componentArrays_) {
        auto const& component = pair.second;
        component->entityDestroyed(entity);
    }

    // Put the destroyed ID at the back of the queue
    availableEntities_.push(entity);
    --livingEntityCount_;
}
