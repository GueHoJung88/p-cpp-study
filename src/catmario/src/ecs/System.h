#pragma once

class Registry;

class System {
public:
    virtual ~System() = default;
    virtual void update(float deltaTime, Registry& registry) = 0;
};
