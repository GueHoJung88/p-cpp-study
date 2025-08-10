#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "src/core/Character.h"

using namespace learning;

int main() {
    // Windows 환경에서 한글 출력을 위한 로케일 설정
    #ifdef _WIN32
    // Windows 콘솔에서 한글 출력을 위한 설정
    system("chcp 65001 > nul");
    #endif
    
    // 로케일 설정
    try {
        std::locale::global(std::locale(""));
    } catch (const std::exception& e) {
        // 로케일 설정 실패 시 기본값 사용
        std::cout << "Warning: Locale setting failed, using default" << std::endl;
    }
    
    std::cout << "=== Character System Test ===" << std::endl;
    std::cout << "=== 캐릭터 시스템 테스트 ===" << std::endl << std::endl;

    // 정적 팩토리 메서드로 캐릭터 생성
    std::cout << "1. Static Factory Method Test:" << std::endl;
    std::cout << "1. 정적 팩토리 메서드 테스트:" << std::endl;
    Character chihuahua = Character::createChihuahua();
    Character rabbit = Character::createRabbit();
    Character cat = Character::createCat();

    std::cout << "Chihuahua: " << chihuahua.getName() << " (" << chihuahua.getRole() << ")" << std::endl;
    std::cout << "치와와: " << chihuahua.getName() << " (" << chihuahua.getRole() << ")" << std::endl;
    std::cout << "Rabbit: " << rabbit.getName() << " (" << rabbit.getRole() << ")" << std::endl;
    std::cout << "토끼: " << rabbit.getName() << " (" << rabbit.getRole() << ")" << std::endl;
    std::cout << "Cat: " << cat.getName() << " (" << cat.getRole() << ")" << std::endl;
    std::cout << "고양이: " << cat.getName() << " (" << cat.getRole() << ")" << std::endl << std::endl;

    // CharacterFactory로 캐릭터 생성
    std::cout << "2. CharacterFactory Test:" << std::endl;
    std::cout << "2. CharacterFactory 테스트:" << std::endl;
    Character maltese = CharacterFactory::createMaltese();
    Character humanLiki = CharacterFactory::createHumanLiki();

    std::cout << "Maltese: " << maltese.getName() << " (" << maltese.getRole() << ")" << std::endl;
    std::cout << "말티즈: " << maltese.getName() << " (" << maltese.getRole() << ")" << std::endl;
    std::cout << "Human Liki: " << humanLiki.getName() << " (" << humanLiki.getRole() << ")" << std::endl;
    std::cout << "인간 리키: " << humanLiki.getName() << " (" << humanLiki.getRole() << ")" << std::endl << std::endl;

    // 캐릭터 프로필 표시
    std::cout << "3. Character Profile Test:" << std::endl;
    std::cout << "3. 캐릭터 프로필 테스트:" << std::endl;
    chihuahua.showProfile();
    std::cout << std::endl;

    // 감정 표현 테스트
    std::cout << "4. Emotion Display Test:" << std::endl;
    std::cout << "4. 감정 표현 테스트:" << std::endl;
    chihuahua.display(Emotion::HAPPY);
    rabbit.display(Emotion::SAD);
    cat.display(Emotion::ANGRY);

    // 경험치 획득 테스트
    std::cout << "\n5. Experience System Test:" << std::endl;
    std::cout << "5. 경험치 시스템 테스트:" << std::endl;
    std::cout << "Initial Level: " << chihuahua.getLevel() << ", Experience: " << chihuahua.getExperience() << std::endl;
    std::cout << "초기 레벨: " << chihuahua.getLevel() << ", 경험치: " << chihuahua.getExperience() << std::endl;
    chihuahua.gainExperience(50);
    std::cout << "After gaining 50 exp: Level " << chihuahua.getLevel() << ", Experience: " << chihuahua.getExperience() << std::endl;
    std::cout << "경험치 50 획득 후: 레벨 " << chihuahua.getLevel() << ", 경험치: " << chihuahua.getExperience() << std::endl;

    // CharacterManager 테스트
    std::cout << "\n6. CharacterManager Test:" << std::endl;
    std::cout << "6. CharacterManager 테스트:" << std::endl;
    CharacterManager manager;
    manager.addCharacter(chihuahua);
    manager.addCharacter(rabbit);
    manager.addCharacter(cat);

    std::cout << "Total Characters: " << manager.getCharacterCount() << std::endl;
    std::cout << "총 캐릭터 수: " << manager.getCharacterCount() << std::endl;

    Character* found = manager.getCharacterByName("치치");
    if (found) {
        std::cout << "Character found by name: " << found->getName() << std::endl;
        std::cout << "이름으로 찾은 캐릭터: " << found->getName() << std::endl;
    }

    std::cout << "\n=== Test Complete ===" << std::endl;
    std::cout << "=== 테스트 완료 ===" << std::endl;
    return 0;
} 