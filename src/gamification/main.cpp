#include "CharacterSelector.h"
#include <iostream>

int main() {
    try {
        learning::gamification::CharacterDefinitionProgram program;
        program.run();
    } catch (const std::exception& e) {
        std::cerr << "오류가 발생했습니다: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "알 수 없는 오류가 발생했습니다." << std::endl;
        return 1;
    }
    
    return 0;
} 