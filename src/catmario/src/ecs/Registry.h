#pragma once
#include <queue>    // for std::queue
#include <array>    // for std::array
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <bitset>

using Entity = std::size_t;
constexpr Entity MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentMask = std::bitset<MAX_COMPONENTS>;

// Base component class
class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void entityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
public:
    void insertData(Entity entity, T component) {
        entityToIndexMap_[entity] = size_;
        indexToEntityMap_[size_] = entity;
        componentArray_[size_] = component;
        ++size_;
    }

    void removeData(Entity entity) {
        // Move last element to deleted element's place
        std::size_t indexOfRemovedEntity = entityToIndexMap_[entity];
        std::size_t indexOfLastElement = size_ - 1;
        componentArray_[indexOfRemovedEntity] = componentArray_[indexOfLastElement];

        // Update map to point to moved spot
        Entity entityOfLastElement = indexToEntityMap_[indexOfLastElement];
        entityToIndexMap_[entityOfLastElement] = indexOfRemovedEntity;
        indexToEntityMap_[indexOfRemovedEntity] = entityOfLastElement;

        entityToIndexMap_.erase(entity);
        indexToEntityMap_.erase(indexOfLastElement);

        --size_;
    }

    T& getData(Entity entity) {
        return componentArray_[entityToIndexMap_[entity]];
    }

    void entityDestroyed(Entity entity) override {
        if (entityToIndexMap_.find(entity) != entityToIndexMap_.end()) {
            removeData(entity);
        }
    }

private:
    std::array<T, MAX_ENTITIES> componentArray_;
    std::unordered_map<Entity, std::size_t> entityToIndexMap_;
    std::unordered_map<std::size_t, Entity> indexToEntityMap_;
    std::size_t size_ = 0;
};

class Registry {
public:
    Registry();
    ~Registry();

    Entity createEntity();
    void destroyEntity(Entity entity);

    template<typename T>
    void addComponent(Entity entity, T component);

    template<typename T>
    void removeComponent(Entity entity);

    template<typename T>
    T& getComponent(Entity entity);

    template<typename T>
    bool hasComponent(Entity entity);

    template<typename... ComponentTypes>
    std::vector<Entity> getEntitiesWith();

private:
    std::queue<Entity> availableEntities_;
    std::array<ComponentMask, MAX_ENTITIES> entityMasks_;
    std::unordered_map<std::type_index, std::shared_ptr<IComponentArray>> componentArrays_;
    std::unordered_map<std::type_index, std::size_t> componentTypes_;
    std::size_t livingEntityCount_ = 0;
    std::size_t nextComponentType_ = 0;

    template<typename T>
    std::shared_ptr<ComponentArray<T>> getComponentArray();

    template<typename T>
    std::size_t getComponentType();
};

// Template implementations
template<typename T>
void Registry::addComponent(Entity entity, T component) {
    getComponentArray<T>()->insertData(entity, component);
    entityMasks_[entity].set(getComponentType<T>(), true);
}

template<typename T>
void Registry::removeComponent(Entity entity) {
    getComponentArray<T>()->removeData(entity);
    entityMasks_[entity].set(getComponentType<T>(), false);
}

template<typename T>
T& Registry::getComponent(Entity entity) {
    return getComponentArray<T>()->getData(entity);
}

template<typename T>
bool Registry::hasComponent(Entity entity) {
    return entityMasks_[entity].test(getComponentType<T>());
}

template<typename T>
std::shared_ptr<ComponentArray<T>> Registry::getComponentArray() {
    std::type_index typeName = std::type_index(typeid(T));

    if (componentArrays_.find(typeName) == componentArrays_.end()) {
        componentArrays_[typeName] = std::make_shared<ComponentArray<T>>();
    }

    return std::static_pointer_cast<ComponentArray<T>>(componentArrays_[typeName]);
}

template<typename T>
std::size_t Registry::getComponentType() {
    std::type_index typeName = std::type_index(typeid(T));

    if (componentTypes_.find(typeName) == componentTypes_.end()) {
        componentTypes_[typeName] = nextComponentType_++;
    }

    return componentTypes_[typeName];
}

template<typename... ComponentTypes>
std::vector<Entity> Registry::getEntitiesWith() {
    std::vector<Entity> entities;
    ComponentMask mask;

    // Set bits for each component type
    (mask.set(getComponentType<ComponentTypes>()), ...);

    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
        if ((entityMasks_[entity] & mask) == mask) {
            entities.push_back(entity);
        }
    }

    return entities;
}
