#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "../src/core/Character.h"

using namespace learning;

// 미션 시스템 테스트
void testMissionSystem() {
    std::cout << "=== Mission System Test ===" << std::endl;
    std::cout << "=== 미션 시스템 테스트 ====" << std::endl;
    
    // 1. 미션 생성 테스트
    std::cout << "\n1. Mission Creation Test:" << std::endl;
    std::cout << "1. 미션 생성 테스트:" << std::endl;
    
    Character chihuahua = Character::createChihuahua("치치", "선생님");
    
    // 미션 생성
    Mission mission = chihuahua.createMission("C++ 기초 학습", "변수와 데이터 타입에 대해 학습하세요", 100);
    assert(mission.getTitle() == "C++ 기초 학습");
    assert(mission.getDescription() == "변수와 데이터 타입에 대해 학습하세요");
    assert(mission.getReward() == 100);
    
    std::cout << "✅ Mission creation works correctly" << std::endl;
    std::cout << "✅ 미션 생성이 올바르게 작동함" << std::endl;
    
    // 2. 미션 진행 상태 테스트
    std::cout << "\n2. Mission Progress Test:" << std::endl;
    std::cout << "2. 미션 진행 상태 테스트:" << std::endl;
    
    // 미션 시작
    mission.start();
    assert(mission.getStatus() == MissionStatus::IN_PROGRESS);
    
    // 미션 진행률 업데이트
    mission.updateProgress(50);
    assert(mission.getProgress() == 50);
    
    // 미션 완료
    mission.complete();
    assert(mission.getStatus() == MissionStatus::COMPLETED);
    
    std::cout << "✅ Mission progress tracking works correctly" << std::endl;
    std::cout << "✅ 미션 진행 추적이 올바르게 작동함" << std::endl;
    
    // 3. 미션 보상 테스트
    std::cout << "\n3. Mission Reward Test:" << std::endl;
    std::cout << "3. 미션 보상 테스트:" << std::endl;
    
    // 보상 지급
    int initialExp = chihuahua.getExperience();
    mission.giveReward(chihuahua);
    assert(chihuahua.getExperience() == initialExp + 100);
    
    std::cout << "✅ Mission reward system works correctly" << std::endl;
    std::cout << "✅ 미션 보상 시스템이 올바르게 작동함" << std::endl;
    
    // 4. 미션 목록 관리 테스트
    std::cout << "\n4. Mission List Management Test:" << std::endl;
    std::cout << "4. 미션 목록 관리 테스트:" << std::endl;
    
    // 미션 목록에 추가
    chihuahua.addMission(mission);
    assert(chihuahua.getMissionCount() == 1);
    
    // 미션 목록에서 가져오기
    Mission* retrievedMission = chihuahua.getMission("C++ 기초 학습");
    assert(retrievedMission != nullptr);
    assert(retrievedMission->getTitle() == "C++ 기초 학습");
    
    std::cout << "✅ Mission list management works correctly" << std::endl;
    std::cout << "✅ 미션 목록 관리가 올바르게 작동함" << std::endl;
    
    // 5. 미션 난이도 테스트
    std::cout << "\n5. Mission Difficulty Test:" << std::endl;
    std::cout << "5. 미션 난이도 테스트:" << std::endl;
    
    // 난이도별 미션 생성
    Mission easyMission = chihuahua.createMission("간단한 계산", "1+1을 계산하세요", 50, MissionDifficulty::EASY);
    Mission hardMission = chihuahua.createMission("복잡한 알고리즘", "정렬 알고리즘을 구현하세요", 200, MissionDifficulty::HARD);
    
    assert(easyMission.getDifficulty() == MissionDifficulty::EASY);
    assert(hardMission.getDifficulty() == MissionDifficulty::HARD);
    
    std::cout << "✅ Mission difficulty system works correctly" << std::endl;
    std::cout << "✅ 미션 난이도 시스템이 올바르게 작동함" << std::endl;
    
    std::cout << "\n=== All Mission System Tests Passed! ===" << std::endl;
    std::cout << "=== 모든 미션 시스템 테스트 통과! ===" << std::endl;
}

int main() {
    try {
        testMissionSystem();
        std::cout << "\n🎉 Mission system test completed successfully!" << std::endl;
        std::cout << "🎉 미션 시스템 테스트가 성공적으로 완료되었습니다!" << std::endl;
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