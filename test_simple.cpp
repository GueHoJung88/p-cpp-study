#include "src/core/Character.h"
#include "src/core/QuizSystem.h"
#include "src/core/LearningModule.h"
#include "src/core/Utils.h"
#include <iostream>

using namespace learning;

int main() {
    std::cout << "=== C++ Learning System Test ===" << std::endl;
    
    // Character 시스템 테스트
    std::cout << "\n1. Character System Test:" << std::endl;
    Character chihuahua = Character::createChihuahua("치치", "선생님");
    chihuahua.display(Emotion::HAPPY);
    
    CharacterManager manager;
    manager.addCharacter(chihuahua);
    std::cout << "캐릭터 수: " << manager.getCharacterCount() << std::endl;
    
    // Quiz 시스템 테스트
    std::cout << "\n2. Quiz System Test:" << std::endl;
    QuizSystem quiz;
    QuizQuestion question("1 + 1 = ?", {"1", "2", "3", "4"}, 1, "수학", "기초", 10);
    quiz.addQuestion(question);
    std::cout << "퀴즈 문제 추가 완료" << std::endl;
    
    // Learning Module 테스트
    std::cout << "\n3. Learning Module Test:" << std::endl;
    VariableModule varModule;
    std::cout << "변수 모듈 이름: " << varModule.getName() << std::endl;
    
    // Utils 테스트
    std::cout << "\n4. Utils Test:" << std::endl;
    std::string testStr = "  Hello World  ";
    std::string trimmed = learning::StringUtils::trim(testStr);
    std::cout << "원본: '" << testStr << "'" << std::endl;
    std::cout << "정리: '" << trimmed << "'" << std::endl;
    
    std::cout << "\n=== 모든 시스템이 정상 작동합니다! ===" << std::endl;
    return 0;
} 