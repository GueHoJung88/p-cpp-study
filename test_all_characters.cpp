#include <iostream>
#include <vector>
#include <string>
#include "src/core/Character.h"

using namespace learning;

void testAllCharacters() {
    std::cout << "=== 모든 캐릭터 테스트 ===\n";
    std::cout << "=== All Characters Test ===\n\n";
    
    // CharacterFactory를 사용하여 모든 캐릭터 생성
    std::vector<Character> allCharacters = CharacterFactory::initializeAllCharacters();
    
    std::cout << "생성된 캐릭터 수: " << allCharacters.size() << "\n";
    std::cout << "Total characters created: " << allCharacters.size() << "\n\n";
    
    // 각 캐릭터의 정보 출력
    for (size_t i = 0; i < allCharacters.size(); ++i) {
        const Character& chara = allCharacters[i];
        std::cout << "--- 캐릭터 " << (i + 1) << " ---\n";
        std::cout << "--- Character " << (i + 1) << " ---\n";
        
        std::cout << "이름: " << chara.getName() << "\n";
        std::cout << "Name: " << chara.getName() << "\n";
        
        std::cout << "종족: ";
        switch (chara.getSpecies()) {
            case Species::CHIHUAHUA: std::cout << "치와와"; break;
            case Species::WELSH_CORGI: std::cout << "웰시코기"; break;
            case Species::GOLDEN_RETRIEVER: std::cout << "골든리트리버"; break;
            case Species::HUSKY: std::cout << "허스키"; break;
            case Species::RABBIT: std::cout << "토끼"; break;
            case Species::CAT: std::cout << "고양이"; break;
            case Species::MALTESE: std::cout << "말티즈"; break;
            case Species::BICHON_FRISE: std::cout << "비숑 프리제"; break;
            case Species::BULLDOG: std::cout << "불독"; break;
            case Species::HUMAN_LIKI: std::cout << "인간 리키"; break;
            case Species::HUMAN_BABO: std::cout << "인간 바보"; break;
            case Species::MYSTICAL_CAT: std::cout << "신비한 고양이"; break;
        }
        std::cout << "\n";
        
        std::cout << "역할: " << chara.getRole() << "\n";
        std::cout << "Role: " << chara.getRole() << "\n";
        
        std::cout << "나이: " << chara.getAge() << "세\n";
        std::cout << "Age: " << chara.getAge() << " years\n";
        
        std::cout << "자산: " << chara.getAssets() << "원\n";
        std::cout << "Assets: " << chara.getAssets() << " won\n";
        
        std::cout << "고향: " << chara.getHometown() << "\n";
        std::cout << "Hometown: " << chara.getHometown() << "\n";
        
        std::cout << "성별: " << chara.getGender() << "\n";
        std::cout << "Gender: " << chara.getGender() << "\n";
        
        std::cout << "사회적 지위: " << chara.getSocialStatus() << "\n";
        std::cout << "Social Status: " << chara.getSocialStatus() << "\n";
        
        std::cout << "이상형: " << chara.getIdealType() << "\n";
        std::cout << "Ideal Type: " << chara.getIdealType() << "\n";
        
        std::cout << "미래 희망: " << chara.getFutureHope() << "\n";
        std::cout << "Future Hope: " << chara.getFutureHope() << "\n";
        
        std::cout << "약점: " << chara.getWeakness() << "\n";
        std::cout << "Weakness: " << chara.getWeakness() << "\n";
        
        std::cout << "HP: " << chara.getHp() << "\n";
        std::cout << "Power: " << chara.getPower() << "\n";
        
        std::cout << "레벨: " << chara.getLevel() << "\n";
        std::cout << "Level: " << chara.getLevel() << "\n";
        
        std::cout << "\n";
        
        // 캐릭터의 감정 표현 테스트
        std::cout << "감정 표현 테스트 (Emotion Display Test):\n";
        chara.display(Emotion::HAPPY);
        std::cout << "\n";
    }
}

void testCharacterManager() {
    std::cout << "=== CharacterManager 테스트 ===\n";
    std::cout << "=== CharacterManager Test ===\n\n";
    
    CharacterManager manager;
    
    // 모든 캐릭터를 매니저에 추가
    std::vector<Character> allCharacters = CharacterFactory::initializeAllCharacters();
    for (const auto& chara : allCharacters) {
        manager.addCharacter(chara);
    }
    
    std::cout << "매니저에 추가된 캐릭터 수: " << manager.getCharacterCount() << "\n";
    std::cout << "Characters in manager: " << manager.getCharacterCount() << "\n\n";
    
    // 종족별로 캐릭터 찾기
    std::cout << "종족별 캐릭터 찾기 (Find by Species):\n";
    Character* chihuahua = manager.getCharacterBySpecies(Species::CHIHUAHUA);
    if (chihuahua) {
        std::cout << "치와와 찾음: " << chihuahua->getName() << "\n";
        std::cout << "Chihuahua found: " << chihuahua->getName() << "\n";
    }
    
    Character* maltese = manager.getCharacterBySpecies(Species::MALTESE);
    if (maltese) {
        std::cout << "말티즈 찾음: " << maltese->getName() << "\n";
        std::cout << "Maltese found: " << maltese->getName() << "\n";
    }
    
    // 역할별로 캐릭터 찾기
    std::cout << "\n역할별 캐릭터 찾기 (Find by Role):\n";
    std::vector<Character> students = manager.getCharactersByRole("학생");
    std::cout << "학생 역할 캐릭터 수: " << students.size() << "\n";
    std::cout << "Student role characters: " << students.size() << "\n";
    
    for (const auto& student : students) {
        std::cout << "- " << student.getName() << " (" << student.getRole() << ")\n";
    }
    
    // 고향별로 캐릭터 찾기
    std::cout << "\n고향별 캐릭터 찾기 (Find by Hometown):\n";
    std::vector<Character> dddWorld = manager.getCharactersByHometown("댕댕월드");
    std::cout << "댕댕월드 출신 캐릭터 수: " << dddWorld.size() << "\n";
    std::cout << "Characters from 댕댕월드: " << dddWorld.size() << "\n";
    
    for (const auto& chara : dddWorld) {
        std::cout << "- " << chara.getName() << " (" << chara.getHometown() << ")\n";
    }
    
    // 가장 강한/약한 캐릭터 찾기
    std::cout << "\n가장 강한/약한 캐릭터 (Strongest/Weakest):\n";
    Character* strongest = manager.getStrongestCharacter();
    Character* weakest = manager.getWeakestCharacter();
    
    if (strongest) {
        std::cout << "가장 강한 캐릭터: " << strongest->getName() << " (Power: " << strongest->getPower() << ")\n";
        std::cout << "Strongest: " << strongest->getName() << " (Power: " << strongest->getPower() << ")\n";
    }
    
    if (weakest) {
        std::cout << "가장 약한 캐릭터: " << weakest->getName() << " (Power: " << weakest->getPower() << ")\n";
        std::cout << "Weakest: " << weakest->getName() << " (Power: " << weakest->getPower() << ")\n";
    }
    
    // 평균 레벨
    std::cout << "\n평균 레벨 (Average Level): " << manager.getAverageLevel() << "\n";
    std::cout << "Average Level: " << manager.getAverageLevel() << "\n";
}

void testPersonalitySystem() {
    std::cout << "\n=== 성격 시스템 테스트 ===\n";
    std::cout << "=== Personality System Test ===\n\n";
    
    Character maltese = CharacterFactory::createMaltese("보리", "주인공");
    
    // 성격 특성 설정
    maltese.setPersonalityTrait(PersonalityTrait::FRIENDLINESS, 8);
    maltese.setPersonalityTrait(PersonalityTrait::KNOWLEDGE, 6);
    maltese.setPersonalityTrait(PersonalityTrait::PATIENCE, 9);
    maltese.setPersonalityTrait(PersonalityTrait::CREATIVITY, 7);
    maltese.setPersonalityTrait(PersonalityTrait::LEADERSHIP, 5);
    maltese.setPersonalityTrait(PersonalityTrait::HUMOR, 8);
    maltese.setPersonalityTrait(PersonalityTrait::COURAGE, 6);
    maltese.setPersonalityTrait(PersonalityTrait::WISDOM, 7);
    
    std::cout << "보리의 성격 특성 (Bori's Personality Traits):\n";
    std::cout << "친근함: " << maltese.getPersonalityTrait(PersonalityTrait::FRIENDLINESS) << "\n";
    std::cout << "지식: " << maltese.getPersonalityTrait(PersonalityTrait::KNOWLEDGE) << "\n";
    std::cout << "인내심: " << maltese.getPersonalityTrait(PersonalityTrait::PATIENCE) << "\n";
    std::cout << "창의성: " << maltese.getPersonalityTrait(PersonalityTrait::CREATIVITY) << "\n";
    std::cout << "리더십: " << maltese.getPersonalityTrait(PersonalityTrait::LEADERSHIP) << "\n";
    std::cout << "유머감각: " << maltese.getPersonalityTrait(PersonalityTrait::HUMOR) << "\n";
    std::cout << "용기: " << maltese.getPersonalityTrait(PersonalityTrait::COURAGE) << "\n";
    std::cout << "지혜: " << maltese.getPersonalityTrait(PersonalityTrait::WISDOM) << "\n";
    
    std::cout << "\n성격 기반 행동 (Personality-based Actions):\n";
    std::cout << "인사: " << maltese.getPersonalityBasedAction(SituationType::GREETING) << "\n";
    std::cout << "학습: " << maltese.getPersonalityBasedAction(SituationType::LEARNING) << "\n";
    std::cout << "도전: " << maltese.getPersonalityBasedAction(SituationType::CHALLENGE) << "\n";
    
    std::cout << "\n상황별 반응 (Situational Responses):\n";
    std::cout << "퀴즈 정답: " << maltese.getSituationalResponse(SituationType::QUIZ, "CORRECT") << "\n";
    std::cout << "퀴즈 오답: " << maltese.getSituationalResponse(SituationType::QUIZ, "WRONG") << "\n";
    
    std::cout << "\n대화 시작: " << maltese.startConversation("학생") << "\n";
    std::cout << "메시지 응답: " << maltese.respondToMessage("안녕하세요") << "\n";
}

int main() {
    std::cout << "=== C++ Character System Comprehensive Test ===\n";
    std::cout << "=== C++ 캐릭터 시스템 종합 테스트 ===\n\n";
    
    try {
        testAllCharacters();
        testCharacterManager();
        testPersonalitySystem();
        
        std::cout << "\n=== 모든 테스트 완료 ===\n";
        std::cout << "=== All Tests Complete ===\n";
        
    } catch (const std::exception& e) {
        std::cerr << "오류 발생 (Error occurred): " << e.what() << "\n";
        return 1;
    }
    
    return 0;
} 