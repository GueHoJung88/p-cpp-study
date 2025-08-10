#include <iostream>
#include <cassert>
#include <string>
#include "../src/core/Character.h"

using namespace learning;

// 성격 시스템 테스트
void testPersonalitySystem() {
    std::cout << "=== Personality System Test ===" << std::endl;
    std::cout << "=== 성격 시스템 테스트 ===" << std::endl;
    
    // 1. 성격 특성 테스트
    std::cout << "\n1. Personality Traits Test:" << std::endl;
    std::cout << "1. 성격 특성 테스트:" << std::endl;
    
    Character chihuahua = Character::createChihuahua("치치", "선생님");
    
    // 성격 특성 설정 테스트
    chihuahua.setPersonalityTrait("친근함", 8);
    chihuahua.setPersonalityTrait("지식", 9);
    chihuahua.setPersonalityTrait("인내심", 7);
    
    // 성격 특성 가져오기 테스트
    assert(chihuahua.getPersonalityTrait("친근함") == 8);
    assert(chihuahua.getPersonalityTrait("지식") == 9);
    assert(chihuahua.getPersonalityTrait("인내심") == 7);
    
    std::cout << "✅ Personality traits set and get successfully" << std::endl;
    std::cout << "✅ 성격 특성 설정 및 가져오기 성공" << std::endl;
    
    // 2. 상황별 반응 테스트
    std::cout << "\n2. Situational Response Test:" << std::endl;
    std::cout << "2. 상황별 반응 테스트:" << std::endl;
    
    // 퀴즈 상황에서의 반응
    std::string response = chihuahua.getSituationalResponse("QUIZ", "CORRECT");
    assert(!response.empty());
    assert(response.find("정답") != std::string::npos || response.find("맞았") != std::string::npos);
    
    // 오답 상황에서의 반응
    response = chihuahua.getSituationalResponse("QUIZ", "WRONG");
    assert(!response.empty());
    assert(response.find("틀렸") != std::string::npos || response.find("힌트") != std::string::npos);
    
    std::cout << "✅ Situational responses work correctly" << std::endl;
    std::cout << "✅ 상황별 반응이 올바르게 작동함" << std::endl;
    
    // 3. 대화 시스템 테스트
    std::cout << "\n3. Conversation System Test:" << std::endl;
    std::cout << "3. 대화 시스템 테스트:" << std::endl;
    
    // 대화 시작
    std::string greeting = chihuahua.startConversation("학생");
    assert(!greeting.empty());
    assert(greeting.find("안녕") != std::string::npos || greeting.find("반갑") != std::string::npos);
    
    // 대화 응답
    std::string reply = chihuahua.respondToMessage("안녕하세요 선생님!");
    assert(!reply.empty());
    assert(reply.find("안녕") != std::string::npos || reply.find("반갑") != std::string::npos);
    
    std::cout << "✅ Conversation system works correctly" << std::endl;
    std::cout << "✅ 대화 시스템이 올바르게 작동함" << std::endl;
    
    // 4. 성격 기반 행동 테스트
    std::cout << "\n4. Personality-Based Behavior Test:" << std::endl;
    std::cout << "4. 성격 기반 행동 테스트:" << std::endl;
    
    // 친근함이 높은 캐릭터의 행동
    Character friendlyCat = Character::createCat("냥냥", "친구");
    friendlyCat.setPersonalityTrait("친근함", 10);
    
    std::string behavior = friendlyCat.getPersonalityBasedAction("GREETING");
    assert(!behavior.empty());
    assert(behavior.find("반갑") != std::string::npos || behavior.find("안녕") != std::string::npos);
    
    std::cout << "✅ Personality-based behavior works correctly" << std::endl;
    std::cout << "✅ 성격 기반 행동이 올바르게 작동함" << std::endl;
    
    std::cout << "\n=== All Personality System Tests Passed! ===" << std::endl;
    std::cout << "=== 모든 성격 시스템 테스트 통과! ===" << std::endl;
}

int main() {
    try {
        testPersonalitySystem();
        std::cout << "\n🎉 Personality system test completed successfully!" << std::endl;
        std::cout << "🎉 성격 시스템 테스트가 성공적으로 완료되었습니다!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "❌ Test failed with exception: " << e.what() << std::endl;
        std::cerr << "❌ 테스트가 예외와 함께 실패했습니다: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "❌ Test failed with unknown exception" << std::endl;
        std::cerr << "❌ 테스트가 알 수 없는 예외와 함께 실패했습니다" << std::endl;
        return 1;
    }
} 