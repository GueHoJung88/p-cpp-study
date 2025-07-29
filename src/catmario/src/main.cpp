#include "game/Game.hpp"
#include <iostream>

int main() {
    Game game;

    if (!game.initialize()) {
        std::cerr << "Failed to initialize game" << std::endl;
        return -1;
    }

    std::cout << "Starting Super Mario ECS game..." << std::endl;
    game.run();

    return 0;
}
