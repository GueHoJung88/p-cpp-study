#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "src/core/Character.h"

using namespace learning;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void waitForEnter() {
    std::cout << "\n엔터를 누르면 계속...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void displayMainMenu() {
    clearScreen();
    std::cout << "=== 🎮 캐릭터 시스템 인터랙티브 테스트 ===\n";
    std::cout << "=== Interactive Character System Test ===\n\n";
    std::cout << "1. 🐕 모든 캐릭터 보기 (View All Characters)\n";
    std::cout << "2. 🎭 개별 캐릭터 생성 및 설정 (Create & Configure Character)\n";
    std::cout << "3. 😊 감정 표현 테스트 (Emotion Display Test)\n";
    std::cout << "4. 🧠 성격 시스템 테스트 (Personality System Test)\n";
    std::cout << "5. 🔍 캐릭터 검색 및 관리 (Character Search & Management)\n";
    std::cout << "6. 🎯 미션 시스템 테스트 (Mission System Test)\n";
    std::cout << "7. 💬 대화 시스템 테스트 (Conversation System Test)\n";
    std::cout << "8. 📊 통계 및 분석 (Statistics & Analysis)\n";
    std::cout << "0. 🚪 종료 (Exit)\n\n";
    std::cout << "선택하세요 (Select): ";
}

void viewAllCharacters() {
    clearScreen();
    std::cout << "=== 🐕 모든 캐릭터 목록 ===\n";
    std::cout << "=== All Characters List ===\n\n";
    
    std::vector<Character> allCharacters = CharacterFactory::initializeAllCharacters();
    
    for (size_t i = 0; i < allCharacters.size(); ++i) {
        const Character& chara = allCharacters[i];
        std::cout << (i + 1) << ". " << chara.getName() << " (" << chara.getSpeciesString() << ")\n";
        std::cout << "   역할: " << chara.getRole() << " | 나이: " << chara.getAge() << "세\n";
        std::cout << "   HP: " << chara.getHP() << " | Power: " << chara.getPower() << "\n";
        std::cout << "   고향: " << chara.getHometown() << "\n";
        std::cout << "   약점: " << chara.getWeakness() << "\n";
        std::cout << "   ---\n";
    }
    
    waitForEnter();
}

void createAndConfigureCharacter() {
    clearScreen();
    std::cout << "=== 🎭 개별 캐릭터 생성 및 설정 ===\n";
    std::cout << "=== Create & Configure Character ===\n\n";
    
    std::cout << "생성할 캐릭터 종류를 선택하세요:\n";
    std::cout << "1. 치와와 (Chihuahua)\n";
    std::cout << "2. 웰시코기 (Welsh Corgi)\n";
    std::cout << "3. 골든리트리버 (Golden Retriever)\n";
    std::cout << "4. 허스키 (Husky)\n";
    std::cout << "5. 토끼 (Rabbit)\n";
    std::cout << "6. 고양이 (Cat)\n";
    std::cout << "7. 말티즈 (Maltese)\n";
    std::cout << "8. 비숑 프리제 (Bichon Frise)\n";
    std::cout << "9. 불독 (Bulldog)\n";
    std::cout << "10. 인간 리키 (Human Liki)\n";
    std::cout << "11. 인간 바보 (Human Babo)\n";
    std::cout << "12. 신비한 고양이 (Mystical Cat)\n\n";
    
    int choice;
    std::cout << "선택 (1-12): ";
    std::cin >> choice;
    
    if (choice < 1 || choice > 12) {
        std::cout << "잘못된 선택입니다.\n";
        waitForEnter();
        return;
    }
    
    std::string name, role;
    std::cout << "캐릭터 이름을 입력하세요: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "캐릭터 역할을 입력하세요: ";
    std::getline(std::cin, role);
    
    Character chara;
    switch (choice) {
        case 1: chara = Character::createChihuahua(name, role); break;
        case 2: chara = Character::createWelshCorgi(name, role); break;
        case 3: chara = Character::createGoldenRetriever(name, role); break;
        case 4: chara = Character::createHusky(name, role); break;
        case 5: chara = Character::createRabbit(name, role); break;
        case 6: chara = Character::createCat(name, role); break;
        case 7: chara = Character::createMaltese(name, role); break;
        case 8: chara = Character::createBichonFrise(name, role); break;
        case 9: chara = Character::createBulldog(name, role); break;
        case 10: chara = Character::createHumanLiki(name, role); break;
        case 11: chara = Character::createHumanBabo(name, role); break;
        case 12: chara = Character::createMysticalCat(name, role); break;
    }
    
    std::cout << "\n✅ 캐릭터가 생성되었습니다!\n";
    std::cout << "이름: " << chara.getName() << "\n";
    std::cout << "종족: " << chara.getSpeciesString() << "\n";
    std::cout << "역할: " << chara.getRole() << "\n";
    
    // 성격 특성 설정
    std::cout << "\n🎭 성격 특성을 설정하시겠습니까? (y/n): ";
    char setPersonality;
    std::cin >> setPersonality;
    
    if (setPersonality == 'y' || setPersonality == 'Y') {
        std::cout << "\n성격 특성 설정 (1-10, 기본값: 5):\n";
        
        int friendliness, knowledge, patience, creativity, leadership, humor, courage, wisdom;
        
        std::cout << "친근함 (1-10): ";
        std::cin >> friendliness;
        chara.setPersonalityTrait(PersonalityTrait::FRIENDLINESS, friendliness);
        
        std::cout << "지식 (1-10): ";
        std::cin >> knowledge;
        chara.setPersonalityTrait(PersonalityTrait::KNOWLEDGE, knowledge);
        
        std::cout << "인내심 (1-10): ";
        std::cin >> patience;
        chara.setPersonalityTrait(PersonalityTrait::PATIENCE, patience);
        
        std::cout << "창의성 (1-10): ";
        std::cin >> creativity;
        chara.setPersonalityTrait(PersonalityTrait::CREATIVITY, creativity);
        
        std::cout << "리더십 (1-10): ";
        std::cin >> leadership;
        chara.setPersonalityTrait(PersonalityTrait::LEADERSHIP, leadership);
        
        std::cout << "유머감각 (1-10): ";
        std::cin >> humor;
        chara.setPersonalityTrait(PersonalityTrait::HUMOR, humor);
        
        std::cout << "용기 (1-10): ";
        std::cin >> courage;
        chara.setPersonalityTrait(PersonalityTrait::COURAGE, courage);
        
        std::cout << "지혜 (1-10): ";
        std::cin >> wisdom;
        chara.setPersonalityTrait(PersonalityTrait::WISDOM, wisdom);
        
        std::cout << "\n✅ 성격 특성이 설정되었습니다!\n";
    }
    
    // 프로필 표시
    std::cout << "\n📋 캐릭터 프로필:\n";
    chara.showProfile();
    
    waitForEnter();
}

void emotionDisplayTest() {
    clearScreen();
    std::cout << "=== 😊 감정 표현 테스트 ===\n";
    std::cout << "=== Emotion Display Test ===\n\n";
    
    std::cout << "테스트할 캐릭터를 생성하세요:\n";
    std::string name, role;
    std::cout << "이름: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "역할: ";
    std::getline(std::cin, role);
    
    Character chara = Character::createChihuahua(name, role);
    
    std::cout << "\n🎭 감정 표현 테스트를 시작합니다!\n\n";
    
    // 13가지 감정 모두 테스트
    Emotion emotions[] = {
        Emotion::DEFAULT, Emotion::HAPPY, Emotion::SAD, Emotion::THINKING,
        Emotion::SURPRISED, Emotion::ANGRY, Emotion::EXPLAIN, Emotion::QUIZ,
        Emotion::JUDGE, Emotion::CORRECT, Emotion::WRONG, Emotion::EXCITED, Emotion::PROUD
    };
    
    std::string emotionNames[] = {
        "기본", "행복", "슬픔", "생각", "놀람", "화남", "설명", "퀴즈",
        "판정", "정답", "오답", "흥분", "자랑"
    };
    
    for (int i = 0; i < 13; ++i) {
        std::cout << "--- " << emotionNames[i] << " 감정 ---\n";
        chara.display(emotions[i]);
        std::cout << "\n";
        
        if (i < 12) {
            std::cout << "다음 감정을 보려면 엔터를 누르세요...";
            std::cin.get();
        }
    }
    
    // 메시지와 함께 감정 표현
    std::cout << "\n💬 메시지와 함께 감정 표현:\n";
    chara.displayWithMessage(Emotion::HAPPY, "안녕하세요! 반갑습니다!");
    std::cout << "\n";
    chara.displayWithMessage(Emotion::EXCITED, "와! 정말 재미있어요!");
    std::cout << "\n";
    chara.displayWithMessage(Emotion::THINKING, "흠... 생각해보겠습니다.");
    
    waitForEnter();
}

void personalitySystemTest() {
    clearScreen();
    std::cout << "=== 🧠 성격 시스템 테스트 ===\n";
    std::cout << "=== Personality System Test ===\n\n";
    
    std::cout << "테스트할 캐릭터를 생성하세요:\n";
    std::string name, role;
    std::cout << "이름: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "역할: ";
    std::getline(std::cin, role);
    
    Character chara = Character::createMaltese(name, role);
    
    // 성격 특성 설정
    std::cout << "\n🎭 성격 특성을 극단적으로 설정해보겠습니다:\n";
    chara.setPersonalityTrait(PersonalityTrait::FRIENDLINESS, 10);
    chara.setPersonalityTrait(PersonalityTrait::KNOWLEDGE, 1);
    chara.setPersonalityTrait(PersonalityTrait::PATIENCE, 10);
    chara.setPersonalityTrait(PersonalityTrait::CREATIVITY, 1);
    chara.setPersonalityTrait(PersonalityTrait::LEADERSHIP, 10);
    chara.setPersonalityTrait(PersonalityTrait::HUMOR, 1);
    chara.setPersonalityTrait(PersonalityTrait::COURAGE, 10);
    chara.setPersonalityTrait(PersonalityTrait::WISDOM, 1);
    
    std::cout << "✅ 성격 특성이 설정되었습니다!\n\n";
    
    // 성격 특성 표시
    std::cout << "📊 현재 성격 특성:\n";
    std::cout << "친근함: " << chara.getPersonalityTrait(PersonalityTrait::FRIENDLINESS) << "\n";
    std::cout << "지식: " << chara.getPersonalityTrait(PersonalityTrait::KNOWLEDGE) << "\n";
    std::cout << "인내심: " << chara.getPersonalityTrait(PersonalityTrait::PATIENCE) << "\n";
    std::cout << "창의성: " << chara.getPersonalityTrait(PersonalityTrait::CREATIVITY) << "\n";
    std::cout << "리더십: " << chara.getPersonalityTrait(PersonalityTrait::LEADERSHIP) << "\n";
    std::cout << "유머감각: " << chara.getPersonalityTrait(PersonalityTrait::HUMOR) << "\n";
    std::cout << "용기: " << chara.getPersonalityTrait(PersonalityTrait::COURAGE) << "\n";
    std::cout << "지혜: " << chara.getPersonalityTrait(PersonalityTrait::WISDOM) << "\n\n";
    
    // 상황별 행동 테스트
    std::cout << "🎯 상황별 행동 테스트:\n";
    std::cout << "인사: " << chara.getPersonalityBasedAction(SituationType::GREETING) << "\n";
    std::cout << "학습: " << chara.getPersonalityBasedAction(SituationType::LEARNING) << "\n";
    std::cout << "도전: " << chara.getPersonalityBasedAction(SituationType::CHALLENGE) << "\n\n";
    
    // 상황별 반응 테스트
    std::cout << "💬 상황별 반응 테스트:\n";
    std::cout << "퀴즈 정답: " << chara.getSituationalResponse(SituationType::QUIZ, "정답입니다!") << "\n";
    std::cout << "퀴즈 오답: " << chara.getSituationalResponse(SituationType::QUIZ, "틀렸습니다.") << "\n";
    std::cout << "성공: " << chara.getSituationalResponse(SituationType::SUCCESS, "축하합니다!") << "\n";
    std::cout << "실패: " << chara.getSituationalResponse(SituationType::FAILURE, "다시 시도해보세요.") << "\n";
    
    waitForEnter();
}

void characterSearchAndManagement() {
    clearScreen();
    std::cout << "=== 🔍 캐릭터 검색 및 관리 ===\n";
    std::cout << "=== Character Search & Management ===\n\n";
    
    CharacterManager manager;
    std::vector<Character> allCharacters = CharacterFactory::initializeAllCharacters();
    
    // 모든 캐릭터를 매니저에 추가
    for (const auto& chara : allCharacters) {
        manager.addCharacter(chara);
    }
    
    std::cout << "✅ " << allCharacters.size() << "개의 캐릭터가 매니저에 추가되었습니다.\n\n";
    
    while (true) {
        std::cout << "검색 옵션을 선택하세요:\n";
        std::cout << "1. 종족별 검색 (Species Search)\n";
        std::cout << "2. 역할별 검색 (Role Search)\n";
        std::cout << "3. 고향별 검색 (Hometown Search)\n";
        std::cout << "4. 가장 강한/약한 캐릭터 (Strongest/Weakest)\n";
        std::cout << "5. 평균 레벨 (Average Level)\n";
        std::cout << "0. 메인 메뉴로 돌아가기 (Back to Main Menu)\n\n";
        
        int choice;
        std::cout << "선택: ";
        std::cin >> choice;
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1: {
                std::cout << "\n종족을 선택하세요:\n";
                std::cout << "1. 치와와 2. 웰시코기 3. 골든리트리버 4. 허스키\n";
                std::cout << "5. 토끼 6. 고양이 7. 말티즈 8. 비숑프리제\n";
                std::cout << "9. 불독 10. 인간리키 11. 인간바보 12. 신비한고양이\n";
                int speciesChoice;
                std::cout << "선택: ";
                std::cin >> speciesChoice;
                
                Species species = static_cast<Species>(speciesChoice - 1);
                Character* found = manager.getCharacterBySpecies(species);
                if (found) {
                    std::cout << "찾음: " << found->getName() << "\n";
                    found->showProfile();
                } else {
                    std::cout << "해당 종족의 캐릭터를 찾을 수 없습니다.\n";
                }
                break;
            }
            case 2: {
                std::cout << "\n역할을 입력하세요: ";
                std::string role;
                std::cin.ignore();
                std::getline(std::cin, role);
                
                std::vector<Character*> found = manager.getCharactersByRole(role);
                if (!found.empty()) {
                    std::cout << role << " 역할의 캐릭터 " << found.size() << "개를 찾았습니다:\n";
                    for (const auto& chara : found) {
                        std::cout << "- " << chara->getName() << " (" << chara->getSpeciesString() << ")\n";
                    }
                } else {
                    std::cout << role << " 역할의 캐릭터를 찾을 수 없습니다.\n";
                }
                break;
            }
            case 3: {
                std::cout << "\n고향을 입력하세요: ";
                std::string hometown;
                std::cin.ignore();
                std::getline(std::cin, hometown);
                
                std::vector<Character*> found = manager.getCharactersByHometown(hometown);
                if (!found.empty()) {
                    std::cout << hometown << " 출신 캐릭터 " << found.size() << "개를 찾았습니다:\n";
                    for (const auto& chara : found) {
                        std::cout << "- " << chara->getName() << " (" << chara->getSpeciesString() << ")\n";
                    }
                } else {
                    std::cout << hometown << " 출신 캐릭터를 찾을 수 없습니다.\n";
                }
                break;
            }
            case 4: {
                Character* strongest = manager.getStrongestCharacter();
                Character* weakest = manager.getWeakestCharacter();
                
                if (strongest && weakest) {
                    std::cout << "\n가장 강한 캐릭터: " << strongest->getName() << " (Power: " << strongest->getPower() << ")\n";
                    std::cout << "가장 약한 캐릭터: " << weakest->getName() << " (Power: " << weakest->getPower() << ")\n";
                }
                break;
            }
            case 5: {
                double avgLevel = manager.getAverageLevel();
                std::cout << "\n평균 레벨: " << avgLevel << "\n";
                break;
            }
        }
        
        if (choice != 0) {
            waitForEnter();
        }
    }
}

void missionSystemTest() {
    clearScreen();
    std::cout << "=== 🎯 미션 시스템 테스트 ===\n";
    std::cout << "=== Mission System Test ===\n\n";
    
    std::cout << "미션 시스템은 아직 구현되지 않았습니다.\n";
    std::cout << "향후 업데이트에서 추가될 예정입니다.\n\n";
    
    std::cout << "계획된 기능:\n";
    std::cout << "- 다양한 미션 타입 (퀴즈, 탐험, 수집 등)\n";
    std::cout << "- 미션 진행도 추적\n";
    std::cout << "- 보상 시스템\n";
    std::cout << "- 난이도 조절\n\n";
    
    waitForEnter();
}

void conversationSystemTest() {
    clearScreen();
    std::cout << "=== 💬 대화 시스템 테스트 ===\n";
    std::cout << "=== Conversation System Test ===\n\n";
    
    std::cout << "대화 시스템 테스트를 시작합니다!\n\n";
    
    // 여러 캐릭터 생성
    Character teacher = Character::createChihuahua("치치", "선생님");
    Character student = Character::createMaltese("보리", "학생");
    
    // 성격 특성 설정
    teacher.setPersonalityTrait(PersonalityTrait::KNOWLEDGE, 9);
    teacher.setPersonalityTrait(PersonalityTrait::PATIENCE, 8);
    student.setPersonalityTrait(PersonalityTrait::FRIENDLINESS, 10);
    student.setPersonalityTrait(PersonalityTrait::CREATIVITY, 7);
    
    std::cout << "=== 🎭 대화 시나리오 ===\n\n";
    
    // 시나리오 1: 인사
    std::cout << "치치 (선생님): ";
    teacher.displayWithMessage(Emotion::HAPPY, teacher.getPersonalityBasedAction(SituationType::GREETING));
    std::cout << "\n";
    
    std::cout << "보리 (학생): ";
    student.displayWithMessage(Emotion::EXCITED, student.getPersonalityBasedAction(SituationType::GREETING));
    std::cout << "\n";
    
    // 시나리오 2: 학습
    std::cout << "치치 (선생님): ";
    teacher.displayWithMessage(Emotion::EXPLAIN, teacher.getPersonalityBasedAction(SituationType::LEARNING));
    std::cout << "\n";
    
    std::cout << "보리 (학생): ";
    student.displayWithMessage(Emotion::THINKING, "아하! 이해했어요!");
    std::cout << "\n";
    
    // 시나리오 3: 퀴즈
    std::cout << "치치 (선생님): ";
    teacher.displayWithMessage(Emotion::QUIZ, "자, 이제 퀴즈를 내볼게요!");
    std::cout << "\n";
    
    std::cout << "보리 (학생): ";
    student.displayWithMessage(Emotion::EXCITED, "좋아요! 준비됐어요!");
    std::cout << "\n";
    
    // 시나리오 4: 결과
    std::cout << "치치 (선생님): ";
    teacher.displayWithMessage(Emotion::CORRECT, teacher.getSituationalResponse(SituationType::SUCCESS, "정답입니다!"));
    std::cout << "\n";
    
    std::cout << "보리 (학생): ";
    student.displayWithMessage(Emotion::PROUD, "와! 정말 기뻐요!");
    std::cout << "\n";
    
    waitForEnter();
}

void statisticsAndAnalysis() {
    clearScreen();
    std::cout << "=== 📊 통계 및 분석 ===\n";
    std::cout << "=== Statistics & Analysis ===\n\n";
    
    std::vector<Character> allCharacters = CharacterFactory::initializeAllCharacters();
    
    std::cout << "📈 전체 캐릭터 통계:\n";
    std::cout << "총 캐릭터 수: " << allCharacters.size() << "개\n\n";
    
    // 종족별 통계
    std::map<std::string, int> speciesCount;
    std::map<std::string, int> roleCount;
    std::map<std::string, int> hometownCount;
    
    int totalHP = 0, totalPower = 0, totalLevel = 0;
    
    for (const auto& chara : allCharacters) {
        speciesCount[chara.getSpeciesString()]++;
        roleCount[chara.getRole()]++;
        hometownCount[chara.getHometown()]++;
        totalHP += chara.getHP();
        totalPower += chara.getPower();
        totalLevel += chara.getLevel();
    }
    
    // 종족별 분포
    std::cout << "🐾 종족별 분포:\n";
    for (const auto& pair : speciesCount) {
        std::cout << "  " << pair.first << ": " << pair.second << "개\n";
    }
    std::cout << "\n";
    
    // 역할별 분포
    std::cout << "🎭 역할별 분포:\n";
    for (const auto& pair : roleCount) {
        std::cout << "  " << pair.first << ": " << pair.second << "개\n";
    }
    std::cout << "\n";
    
    // 고향별 분포
    std::cout << "🏠 고향별 분포:\n";
    for (const auto& pair : hometownCount) {
        std::cout << "  " << pair.first << ": " << pair.second << "개\n";
    }
    std::cout << "\n";
    
    // 수치 통계
    std::cout << "📊 수치 통계:\n";
    std::cout << "평균 HP: " << (double)totalHP / allCharacters.size() << "\n";
    std::cout << "평균 Power: " << (double)totalPower / allCharacters.size() << "\n";
    std::cout << "평균 Level: " << (double)totalLevel / allCharacters.size() << "\n\n";
    
    // 가장 강한/약한 캐릭터
    Character* strongest = nullptr;
    Character* weakest = nullptr;
    int maxPower = -1, minPower = 9999;
    
    for (const auto& chara : allCharacters) {
        if (chara.getPower() > maxPower) {
            maxPower = chara.getPower();
            strongest = const_cast<Character*>(&chara);
        }
        if (chara.getPower() < minPower) {
            minPower = chara.getPower();
            weakest = const_cast<Character*>(&chara);
        }
    }
    
    if (strongest && weakest) {
        std::cout << "🏆 최고/최저 Power:\n";
        std::cout << "최고: " << strongest->getName() << " (" << strongest->getSpeciesString() << ") - " << strongest->getPower() << "\n";
        std::cout << "최저: " << weakest->getName() << " (" << weakest->getSpeciesString() << ") - " << weakest->getPower() << "\n";
    }
    
    waitForEnter();
}

int main() {
    while (true) {
        displayMainMenu();
        
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                viewAllCharacters();
                break;
            case 2:
                createAndConfigureCharacter();
                break;
            case 3:
                emotionDisplayTest();
                break;
            case 4:
                personalitySystemTest();
                break;
            case 5:
                characterSearchAndManagement();
                break;
            case 6:
                missionSystemTest();
                break;
            case 7:
                conversationSystemTest();
                break;
            case 8:
                statisticsAndAnalysis();
                break;
            case 0:
                std::cout << "\n프로그램을 종료합니다. 감사합니다!\n";
                std::cout << "Thank you for using the Character System!\n";
                return 0;
            default:
                std::cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
                waitForEnter();
                break;
        }
    }
    
    return 0;
} 