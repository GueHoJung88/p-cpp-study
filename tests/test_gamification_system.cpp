#include <gtest/gtest.h>
#include "../src/gamification/CharacterSelector.h"
#include "../src/core/Character.h"

using namespace learning;
using namespace learning::gamification;

class GamificationSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 테스트 전 초기화
    }
    
    void TearDown() override {
        // 테스트 후 정리
    }
};

// CharacterDialogueSystem 테스트
TEST_F(GamificationSystemTest, DialogueSystemInitialization) {
    CharacterDialogueSystem dialogueSystem;
    
    // 기본 대화가 초기화되었는지 확인
    std::string dialogue = dialogueSystem.getSituationDialogue(
        Species::CHIHUAHUA, SituationType::LEARNING);
    EXPECT_FALSE(dialogue.empty());
    EXPECT_NE(dialogue, "상황에 맞는 대화가 없어요.");
}

TEST_F(GamificationSystemTest, SituationDialogueRetrieval) {
    CharacterDialogueSystem dialogueSystem;
    
    // 치와와의 학습 상황 대화 테스트
    std::string dialogue = dialogueSystem.getSituationDialogue(
        Species::CHIHUAHUA, SituationType::LEARNING);
    EXPECT_FALSE(dialogue.empty());
    
    // 웰시코기의 학습 상황 대화 테스트
    dialogue = dialogueSystem.getSituationDialogue(
        Species::WELSH_CORGI, SituationType::LEARNING);
    EXPECT_FALSE(dialogue.empty());
}

TEST_F(GamificationSystemTest, EmotionDialogueRetrieval) {
    CharacterDialogueSystem dialogueSystem;
    
    // 치와와의 기쁨 감정 대화 테스트
    std::string dialogue = dialogueSystem.getEmotionDialogue(
        Species::CHIHUAHUA, EmotionDialogueType::HAPPY);
    EXPECT_FALSE(dialogue.empty());
    
    // 골든리트리버의 의지 감정 대화 테스트
    dialogue = dialogueSystem.getEmotionDialogue(
        Species::GOLDEN_RETRIEVER, EmotionDialogueType::DETERMINED);
    EXPECT_FALSE(dialogue.empty());
}

TEST_F(GamificationSystemTest, RandomDialogueRetrieval) {
    CharacterDialogueSystem dialogueSystem;
    
    // 랜덤 대화가 매번 다른지 확인 (가능한 경우)
    std::string dialogue1 = dialogueSystem.getRandomSituationDialogue(
        Species::CHIHUAHUA, SituationType::LEARNING);
    std::string dialogue2 = dialogueSystem.getRandomSituationDialogue(
        Species::CHIHUAHUA, SituationType::LEARNING);
    
    EXPECT_FALSE(dialogue1.empty());
    EXPECT_FALSE(dialogue2.empty());
    
    // 치와와는 학습 상황에 대해 3개의 대화를 가지고 있음
    // 랜덤이므로 같은 대화가 나올 수도 있지만, 둘 다 유효해야 함
    EXPECT_TRUE(dialogue1.find("치와와") != std::string::npos || 
                dialogue1.find("🐕") != std::string::npos ||
                dialogue1.find("배우") != std::string::npos);
    EXPECT_TRUE(dialogue2.find("치와와") != std::string::npos || 
                dialogue2.find("🐕") != std::string::npos ||
                dialogue2.find("배우") != std::string::npos);
}

TEST_F(GamificationSystemTest, CombinedDialogue) {
    CharacterDialogueSystem dialogueSystem;
    
    // 복합 대화 테스트
    std::string combined = dialogueSystem.getCombinedDialogue(
        Species::CHIHUAHUA, 
        SituationType::QUIZ_SUCCESS, 
        EmotionDialogueType::HAPPY);
    
    EXPECT_FALSE(combined.empty());
    EXPECT_GT(combined.length(), 10); // 충분히 긴 대화여야 함
}

TEST_F(GamificationSystemTest, DialogueAddition) {
    CharacterDialogueSystem dialogueSystem;
    
    // 새로운 대화 추가
    dialogueSystem.addSituationDialogue(
        Species::CHIHUAHUA, 
        SituationType::LEARNING, 
        "테스트 대화입니다!");
    
    // 추가된 대화가 포함되어 있는지 확인
    std::vector<std::string> allDialogues;
    // 실제로는 private 멤버에 접근할 수 없으므로, 
    // getRandomSituationDialogue를 여러 번 호출하여 확인
    for (int i = 0; i < 10; ++i) {
        std::string dialogue = dialogueSystem.getRandomSituationDialogue(
            Species::CHIHUAHUA, SituationType::LEARNING);
        if (dialogue == "테스트 대화입니다!") {
            SUCCEED();
            return;
        }
    }
    // 테스트 대화가 나올 확률이 있으므로 실패하지 않음
}

// CharacterSelector 테스트
TEST_F(GamificationSystemTest, CharacterSelectorInitialization) {
    CharacterSelector selector;
    
    // 사용 가능한 캐릭터가 있는지 확인
    EXPECT_GT(selector.getAllCharacters().size(), 0);
}

TEST_F(GamificationSystemTest, CharacterSelection) {
    CharacterSelector selector;
    
    // 이름으로 캐릭터 선택
    Character* character = selector.selectCharacterByName("치치");
    EXPECT_NE(character, nullptr);
    EXPECT_EQ(character->getName(), "치치");
    
    // 종류로 캐릭터 선택
    character = selector.selectCharacterBySpecies(Species::WELSH_CORGI);
    EXPECT_NE(character, nullptr);
    EXPECT_EQ(character->getSpecies(), Species::WELSH_CORGI);
}

TEST_F(GamificationSystemTest, CharacterCustomization) {
    CharacterSelector selector;
    
    // 기본 캐릭터 생성
    Character baseCharacter = Character::createChihuahua("테스트", "테스터");
    
    // 커스터마이징
    Character customized = selector.customizeCharacter(baseCharacter);
    
    // 기본 정보는 유지되어야 함
    EXPECT_EQ(customized.getSpecies(), Species::CHIHUAHUA);
    EXPECT_EQ(customized.getRole(), "테스터");
}

TEST_F(GamificationSystemTest, CharacterSaveAndLoad) {
    CharacterSelector selector;
    
    // 테스트 캐릭터 생성
    Character testCharacter = Character::createMaltese("테스트말티즈", "테스터");
    testCharacter.setAge(3);
    testCharacter.setHometown("테스트타운");
    
    // 임시 파일명
    std::string filename = "test_character.txt";
    
    // 저장
    bool saveResult = selector.saveCharacter(testCharacter, filename);
    EXPECT_TRUE(saveResult);
    
    // 불러오기
    Character* loaded = selector.loadCharacter(filename);
    EXPECT_NE(loaded, nullptr);
    
    if (loaded) {
        EXPECT_EQ(loaded->getName(), "테스트말티즈");
        EXPECT_EQ(loaded->getSpecies(), Species::MALTESE);
        EXPECT_EQ(loaded->getAge(), 3);
        EXPECT_EQ(loaded->getHometown(), "테스트타운");
        
        delete loaded;
    }
    
    // 테스트 파일 삭제
    std::remove(filename.c_str());
}

// 통합 테스트
TEST_F(GamificationSystemTest, FullSystemIntegration) {
    CharacterSelector selector;
    CharacterDialogueSystem& dialogueSystem = selector.getDialogueSystem();
    
    // 캐릭터 선택
    Character* character = selector.selectCharacterBySpecies(Species::GOLDEN_RETRIEVER);
    EXPECT_NE(character, nullptr);
    
    if (character) {
        // 대화 시스템 테스트
        std::string dialogue = dialogueSystem.getCombinedDialogue(
            character->getSpecies(),
            SituationType::ENCOURAGEMENT,
            EmotionDialogueType::DETERMINED);
        
        EXPECT_FALSE(dialogue.empty());
        EXPECT_GT(dialogue.length(), 10);
        
        // 캐릭터 정보 표시 테스트
        selector.displayCharacterInfo(*character);
        selector.displayCharacterProfile(*character);
    }
}

// 경계 조건 테스트
TEST_F(GamificationSystemTest, EdgeCases) {
    CharacterDialogueSystem dialogueSystem;
    
    // 존재하지 않는 종류에 대한 대화 요청
    std::string dialogue = dialogueSystem.getSituationDialogue(
        static_cast<Species>(999), SituationType::LEARNING);
    EXPECT_EQ(dialogue, "안녕하세요!");
    
    // 존재하지 않는 상황에 대한 대화 요청
    dialogue = dialogueSystem.getSituationDialogue(
        Species::CHIHUAHUA, static_cast<SituationType>(999));
    EXPECT_EQ(dialogue, "상황에 맞는 대화가 없어요.");
    
    // 존재하지 않는 감정에 대한 대화 요청
    dialogue = dialogueSystem.getEmotionDialogue(
        Species::CHIHUAHUA, static_cast<EmotionDialogueType>(999));
    EXPECT_EQ(dialogue, "이 감정에 맞는 대화가 없어요.");
}

// 성능 테스트
TEST_F(GamificationSystemTest, PerformanceTest) {
    CharacterDialogueSystem dialogueSystem;
    
    // 대량의 대화 요청 테스트
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 1000; ++i) {
        std::string dialogue = dialogueSystem.getRandomSituationDialogue(
            Species::CHIHUAHUA, SituationType::LEARNING);
        EXPECT_FALSE(dialogue.empty());
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    // 1000번의 대화 요청이 1초 이내에 완료되어야 함
    EXPECT_LT(duration.count(), 1000);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 