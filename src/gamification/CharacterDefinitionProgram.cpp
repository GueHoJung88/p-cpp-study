#include "CharacterSelector.h"
#include <iostream>
#include <limits>
#include <cstdlib>

namespace learning {
namespace gamification {

CharacterDefinitionProgram::CharacterDefinitionProgram() : currentCharacter(nullptr) {
    std::cout << "=== 캐릭터 정의 프로그램 ===\n";
    std::cout << "C++ 학습을 위한 게임화된 캐릭터 시스템\n\n";
}

CharacterDefinitionProgram::~CharacterDefinitionProgram() {
    if (currentCharacter) {
        delete currentCharacter;
    }
}

void CharacterDefinitionProgram::run() {
    while (true) {
        showMainMenu();
        int choice;
        std::cout << "선택하세요: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                createNewCharacter();
                break;
            case 2:
                loadExistingCharacter();
                break;
            case 3:
                if (currentCharacter) {
                    showCharacterMenu();
                } else {
                    std::cout << "먼저 캐릭터를 선택하거나 생성해주세요.\n";
                }
                break;
            case 4:
                if (currentCharacter) {
                    testDialogueSystem();
                } else {
                    std::cout << "먼저 캐릭터를 선택하거나 생성해주세요.\n";
                }
                break;
            case 5:
                showSettings();
                break;
            case 0:
                std::cout << "프로그램을 종료합니다.\n";
                return;
            default:
                std::cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
        }
        
        std::cout << "\n계속하려면 Enter를 누르세요...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        system("cls"); // Windows
        // system("clear"); // Linux/Mac
    }
}

void CharacterDefinitionProgram::showMainMenu() {
    std::cout << "\n=== 메인 메뉴 ===\n";
    std::cout << "1. 새 캐릭터 생성\n";
    std::cout << "2. 기존 캐릭터 불러오기\n";
    std::cout << "3. 캐릭터 관리\n";
    std::cout << "4. 대화 시스템 테스트\n";
    std::cout << "5. 설정\n";
    std::cout << "0. 종료\n";
    
    if (currentCharacter) {
        std::cout << "\n현재 선택된 캐릭터: " << currentCharacter->getName() 
                  << " (" << currentCharacter->getSpeciesString() << ")\n";
    }
}

void CharacterDefinitionProgram::showCharacterMenu() {
    while (true) {
        std::cout << "\n=== 캐릭터 관리 메뉴 ===\n";
        std::cout << "1. 캐릭터 정보 보기\n";
        std::cout << "2. 상세 프로필 보기\n";
        std::cout << "3. 캐릭터 커스터마이징\n";
        std::cout << "4. 프로필 편집\n";
        std::cout << "5. 캐릭터 저장\n";
        std::cout << "6. 캐릭터 삭제\n";
        std::cout << "0. 메인 메뉴로 돌아가기\n";
        
        int choice;
        std::cout << "선택하세요: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                selector.displayCharacterInfo(*currentCharacter);
                break;
            case 2:
                selector.displayCharacterProfile(*currentCharacter);
                break;
            case 3:
                *currentCharacter = selector.customizeCharacter(*currentCharacter);
                break;
            case 4:
                selector.editCharacterProfile(*currentCharacter);
                break;
            case 5:
                saveCurrentCharacter();
                break;
            case 6:
                deleteCharacter();
                return;
            case 0:
                return;
            default:
                std::cout << "잘못된 선택입니다.\n";
        }
    }
}

void CharacterDefinitionProgram::showCustomizationMenu() {
    std::cout << "\n=== 커스터마이징 메뉴 ===\n";
    std::cout << "1. 이름 변경\n";
    std::cout << "2. 역할 변경\n";
    std::cout << "3. 프로필 편집\n";
    std::cout << "0. 돌아가기\n";
}

void CharacterDefinitionProgram::showDialogueMenu() {
    std::cout << "\n=== 대화 시스템 메뉴 ===\n";
    std::cout << "1. 상황별 대화 테스트\n";
    std::cout << "2. 감정별 대화 테스트\n";
    std::cout << "3. 복합 대화 테스트\n";
    std::cout << "0. 돌아가기\n";
}

void CharacterDefinitionProgram::createNewCharacter() {
    std::cout << "\n=== 새 캐릭터 생성 ===\n";
    
    // 캐릭터 선택
    Character* selected = selector.selectCharacter();
    if (!selected) {
        std::cout << "캐릭터 선택에 실패했습니다.\n";
        return;
    }
    
    // 커스터마이징
    Character customized = selector.customizeCharacter(*selected);
    
    // 현재 캐릭터로 설정
    if (currentCharacter) {
        delete currentCharacter;
    }
    currentCharacter = new Character(customized);
    
    std::cout << "\n새 캐릭터가 생성되었습니다!\n";
    selector.displayCharacterInfo(*currentCharacter);
}

void CharacterDefinitionProgram::loadExistingCharacter() {
    std::cout << "\n=== 기존 캐릭터 불러오기 ===\n";
    
    std::string filename;
    std::cout << "캐릭터 파일명을 입력하세요: ";
    std::cin.ignore();
    std::getline(std::cin, filename);
    
    Character* loaded = selector.loadCharacter(filename);
    if (loaded) {
        if (currentCharacter) {
            delete currentCharacter;
        }
        currentCharacter = loaded;
        std::cout << "캐릭터를 성공적으로 불러왔습니다!\n";
        selector.displayCharacterInfo(*currentCharacter);
    } else {
        std::cout << "캐릭터 파일을 불러오는데 실패했습니다.\n";
    }
}

void CharacterDefinitionProgram::saveCurrentCharacter() {
    if (!currentCharacter) {
        std::cout << "저장할 캐릭터가 없습니다.\n";
        return;
    }
    
    std::string filename;
    std::cout << "저장할 파일명을 입력하세요: ";
    std::cin.ignore();
    std::getline(std::cin, filename);
    
    if (selector.saveCharacter(*currentCharacter, filename)) {
        std::cout << "캐릭터가 성공적으로 저장되었습니다!\n";
    } else {
        std::cout << "캐릭터 저장에 실패했습니다.\n";
    }
}

void CharacterDefinitionProgram::deleteCharacter() {
    if (!currentCharacter) {
        std::cout << "삭제할 캐릭터가 없습니다.\n";
        return;
    }
    
    std::cout << "정말로 현재 캐릭터를 삭제하시겠습니까? (y/n): ";
    char confirm;
    std::cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        delete currentCharacter;
        currentCharacter = nullptr;
        std::cout << "캐릭터가 삭제되었습니다.\n";
    }
}

void CharacterDefinitionProgram::testDialogueSystem() {
    while (true) {
        showDialogueMenu();
        int choice;
        std::cout << "선택하세요: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                testSituationDialogues();
                break;
            case 2:
                testEmotionDialogues();
                break;
            case 3:
                testCombinedDialogues();
                break;
            case 0:
                return;
            default:
                std::cout << "잘못된 선택입니다.\n";
        }
    }
}

void CharacterDefinitionProgram::testSituationDialogues() {
    std::cout << "\n=== 상황별 대화 테스트 ===\n";
    
    // 상황 타입 목록 표시
    std::cout << "테스트할 상황을 선택하세요:\n";
    std::cout << "1. 학습 중\n";
    std::cout << "2. 퀴즈 시작\n";
    std::cout << "3. 퀴즈 성공\n";
    std::cout << "4. 퀴즈 실패\n";
    std::cout << "5. 레벨업\n";
    std::cout << "6. 격려\n";
    std::cout << "7. 축하\n";
    std::cout << "8. 위로\n";
    std::cout << "9. 설명\n";
    std::cout << "10. 힌트\n";
    
    int choice;
    std::cout << "선택하세요: ";
    std::cin >> choice;
    
    SituationType situation;
    switch (choice) {
        case 1: situation = SituationType::LEARNING; break;
        case 2: situation = SituationType::QUIZ_START; break;
        case 3: situation = SituationType::QUIZ_SUCCESS; break;
        case 4: situation = SituationType::QUIZ_FAILURE; break;
        case 5: situation = SituationType::LEVEL_UP; break;
        case 6: situation = SituationType::ENCOURAGEMENT; break;
        case 7: situation = SituationType::CELEBRATION; break;
        case 8: situation = SituationType::COMFORT; break;
        case 9: situation = SituationType::EXPLANATION; break;
        case 10: situation = SituationType::HINT; break;
        default:
            std::cout << "잘못된 선택입니다.\n";
            return;
    }
    
    // 대화 출력
    std::string dialogue = selector.getDialogueSystem().getRandomSituationDialogue(
        currentCharacter->getSpecies(), situation);
    
    std::cout << "\n[" << currentCharacter->getName() << "의 대화]\n";
    std::cout << dialogue << "\n";
    
    // 캐릭터 표시
    currentCharacter->displayWithMessage(Emotion::EXPLAIN, dialogue);
}

void CharacterDefinitionProgram::testEmotionDialogues() {
    std::cout << "\n=== 감정별 대화 테스트 ===\n";
    
    // 감정 타입 목록 표시
    std::cout << "테스트할 감정을 선택하세요:\n";
    std::cout << "1. 기쁨\n";
    std::cout << "2. 슬픔\n";
    std::cout << "3. 생각\n";
    std::cout << "4. 놀람\n";
    std::cout << "5. 화남\n";
    std::cout << "6. 흥분\n";
    std::cout << "7. 자랑\n";
    std::cout << "8. 혼란\n";
    std::cout << "9. 의지\n";
    std::cout << "10. 호기심\n";
    
    int choice;
    std::cout << "선택하세요: ";
    std::cin >> choice;
    
    EmotionDialogueType emotion;
    switch (choice) {
        case 1: emotion = EmotionDialogueType::HAPPY; break;
        case 2: emotion = EmotionDialogueType::SAD; break;
        case 3: emotion = EmotionDialogueType::THINKING; break;
        case 4: emotion = EmotionDialogueType::SURPRISED; break;
        case 5: emotion = EmotionDialogueType::ANGRY; break;
        case 6: emotion = EmotionDialogueType::EXCITED; break;
        case 7: emotion = EmotionDialogueType::PROUD; break;
        case 8: emotion = EmotionDialogueType::CONFUSED; break;
        case 9: emotion = EmotionDialogueType::DETERMINED; break;
        case 10: emotion = EmotionDialogueType::CURIOUS; break;
        default:
            std::cout << "잘못된 선택입니다.\n";
            return;
    }
    
    // 대화 출력
    std::string dialogue = selector.getDialogueSystem().getRandomEmotionDialogue(
        currentCharacter->getSpecies(), emotion);
    
    std::cout << "\n[" << currentCharacter->getName() << "의 대화]\n";
    std::cout << dialogue << "\n";
    
    // 캐릭터 표시
    currentCharacter->displayWithMessage(Emotion::EXPLAIN, dialogue);
}

void CharacterDefinitionProgram::testCombinedDialogues() {
    std::cout << "\n=== 복합 대화 테스트 ===\n";
    
    // 상황과 감정 조합 테스트
    std::cout << "상황: 퀴즈 성공 + 감정: 기쁨\n";
    std::string dialogue = selector.getDialogueSystem().getCombinedDialogue(
        currentCharacter->getSpecies(), 
        SituationType::QUIZ_SUCCESS, 
        EmotionDialogueType::HAPPY);
    
    std::cout << "\n[" << currentCharacter->getName() << "의 대화]\n";
    std::cout << dialogue << "\n";
    
    // 캐릭터 표시
    currentCharacter->displayWithMessage(Emotion::EXCITED, dialogue);
}

void CharacterDefinitionProgram::showSettings() {
    std::cout << "\n=== 설정 ===\n";
    std::cout << "1. 캐릭터 데이터 내보내기\n";
    std::cout << "2. 캐릭터 데이터 가져오기\n";
    std::cout << "0. 돌아가기\n";
    
    int choice;
    std::cout << "선택하세요: ";
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            exportCharacterData();
            break;
        case 2:
            importCharacterData();
            break;
        case 0:
            return;
        default:
            std::cout << "잘못된 선택입니다.\n";
    }
}

void CharacterDefinitionProgram::exportCharacterData() {
    std::cout << "캐릭터 데이터 내보내기 기능은 향후 구현 예정입니다.\n";
}

void CharacterDefinitionProgram::importCharacterData() {
    std::cout << "캐릭터 데이터 가져오기 기능은 향후 구현 예정입니다.\n";
}

} // namespace gamification
} // namespace learning 