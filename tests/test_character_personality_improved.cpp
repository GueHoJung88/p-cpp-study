#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include "../src/core/Character.h"

using namespace learning;

// 개선된 성격 시스템 테스트
void testImprovedPersonalitySystem() {
    std::cout << "=== Improved Personality System Test ===" << std::endl;
    std::cout << "=== 개선된 성격 시스템 테스트 ===" << std::endl;
    
    // 1. 열거형 기반 성격 특성 테스트
    std::cout << "\n1. Enum-based Personality Traits Test:" << std::endl;
    std::cout << "1. 열거형 기반 성격 특성 테스트:" << std::endl;
    
    Character chihuahua = Character::createChihuahua("치치", "선생님");
    
    // 열거형을 사용한 성격 특성 설정
    chihuahua.setPersonalityTrait(PersonalityTrait::FRIENDLINESS, 9);
    chihuahua.setPersonalityTrait(PersonalityTrait::KNOWLEDGE, 8);
    chihuahua.setPersonalityTrait(PersonalityTrait::PATIENCE, 7);
    chihuahua.setPersonalityTrait(PersonalityTrait::CREATIVITY, 6);
    
    // 열거형을 사용한 성격 특성 가져오기
    assert(chihuahua.getPersonalityTrait(PersonalityTrait::FRIENDLINESS) == 9);
    assert(chihuahua.getPersonalityTrait(PersonalityTrait::KNOWLEDGE) == 8);
    assert(chihuahua.getPersonalityTrait(PersonalityTrait::PATIENCE) == 7);
    assert(chihuahua.getPersonalityTrait(PersonalityTrait::CREATIVITY) == 6);
    
    std::cout << "✅ Enum-based personality traits work correctly" << std::endl;
    std::cout << "✅ 열거형 기반 성격 특성이 올바르게 작동함" << std::endl;
    
    // 2. 열거형 기반 상황별 반응 테스트
    std::cout << "\n2. Enum-based Situational Response Test:" << std::endl;
    std::cout << "2. 열거형 기반 상황별 반응 테스트:" << std::endl;
    
    // 열거형을 사용한 상황별 반응
    std::string response = chihuahua.getSituationalResponse(SituationType::QUIZ, "CORRECT");
    assert(!response.empty());
    assert(response.find("정답") != std::string::npos);
    
    response = chihuahua.getSituationalResponse(SituationType::SUCCESS, "");
    assert(!response.empty());
    assert(response.find("축하") != std::string::npos);
    
    response = chihuahua.getSituationalResponse(SituationType::FAILURE, "");
    assert(!response.empty());
    assert(response.find("괜찮아요") != std::string::npos);
    
    std::cout << "✅ Enum-based situational responses work correctly" << std::endl;
    std::cout << "✅ 열거형 기반 상황별 반응이 올바르게 작동함" << std::endl;
    
    // 3. 성격 시스템 유틸리티 테스트
    std::cout << "\n3. Personality System Utility Test:" << std::endl;
    std::cout << "3. 성격 시스템 유틸리티 테스트:" << std::endl;
    
    // 성격 요약
    std::string summary = chihuahua.getPersonalitySummary();
    assert(!summary.empty());
    assert(summary.find("친근함: 9/10") != std::string::npos);
    
    // 성격 평균
    double average = chihuahua.getPersonalityAverage();
    assert(average > 0);
    assert(average <= 10);
    
    // 지배적 특성
    std::string dominant = chihuahua.getDominantTrait();
    assert(dominant == "친근함");
    
    std::cout << "✅ Personality utilities work correctly" << std::endl;
    std::cout << "✅ 성격 시스템 유틸리티가 올바르게 작동함" << std::endl;
    
    // 4. 성격 기반 행동 테스트 (열거형)
    std::cout << "\n4. Personality-Based Behavior Test (Enum):" << std::endl;
    std::cout << "4. 성격 기반 행동 테스트 (열거형):" << std::endl;
    
    std::string behavior = chihuahua.getPersonalityBasedAction(SituationType::GREETING);
    assert(!behavior.empty());
    assert(behavior.find("반갑습니다") != std::string::npos);
    
    std::cout << "✅ Enum-based personality behavior works correctly" << std::endl;
    std::cout << "✅ 열거형 기반 성격 행동이 올바르게 작동함" << std::endl;
    
    // 5. 성격 시스템 상세 정보 출력
    std::cout << "\n5. Personality System Details:" << std::endl;
    std::cout << "5. 성격 시스템 상세 정보:" << std::endl;
    
    std::cout << "성격 특성 요약:" << std::endl;
    std::cout << chihuahua.getPersonalitySummary();
    
    std::cout << "성격 평균: " << std::fixed << std::setprecision(1) 
              << chihuahua.getPersonalityAverage() << "/10" << std::endl;
    
    std::cout << "지배적 특성: " << chihuahua.getDominantTrait() << std::endl;
    
    std::cout << "\n=== All Improved Personality System Tests Passed! ===" << std::endl;
    std::cout << "=== 모든 개선된 성격 시스템 테스트 통과! ===" << std::endl;
}

int main() {
    try {
        testImprovedPersonalitySystem();
        std::cout << "\n🎉 Improved personality system test completed successfully!" << std::endl;
        std::cout << "🎉 개선된 성격 시스템 테스트가 성공적으로 완료되었습니다!" << std::endl;
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