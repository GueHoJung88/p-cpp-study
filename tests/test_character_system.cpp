#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

// 테스트할 캐릭터 시스템 클래스들
#include "../src/core/Character.h"

using namespace learning;

// 캐릭터 시스템 테스트
class CharacterSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 테스트용 캐릭터들 생성
        chihuahua = Character("치치", Species::CHIHUAHUA, "선생님");
        welshCorgi = Character("코코", Species::WELSH_CORGI, "도우미");
        goldenRetriever = Character("리버", Species::GOLDEN_RETRIEVER, "친구");
        husky = Character("허허", Species::HUSKY, "모험가");
        rabbit = Character("토토", Species::RABBIT, "퀴즈");
        cat = Character("냥냥", Species::CAT, "채점");
        maltese = Character("보리", Species::MALTESE, "주인공");
        humanLiki = Character("Liki", Species::HUMAN_LIKI, "학생");
        humanBabo = Character("바보", Species::HUMAN_BABO, "분위기메이커");
        mysticalCat = Character("먀엉", Species::MYSTICAL_CAT, "현자");
    }
    
    void TearDown() override {
        // 테스트 후 정리
    }
    
    Character chihuahua;
    Character welshCorgi;
    Character goldenRetriever;
    Character husky;
    Character rabbit;
    Character cat;
    Character maltese;
    Character humanLiki;
    Character humanBabo;
    Character mysticalCat;
};

// 출력 캡처를 위한 테스트 헬퍼
class OutputCapture {
private:
    std::streambuf* original_cout;
    std::ostringstream captured_output;

public:
    OutputCapture() : original_cout(std::cout.rdbuf()) {
        std::cout.rdbuf(captured_output.rdbuf());
    }
    
    ~OutputCapture() {
        std::cout.rdbuf(original_cout);
    }
    
    std::string getOutput() const {
        return captured_output.str();
    }
};

// ===== 기본 캐릭터 생성 테스트 =====

TEST_F(CharacterSystemTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("Test", Species::CHIHUAHUA, "TestRole");
    
    EXPECT_EQ(testChar.getName(), "Test");
    EXPECT_EQ(testChar.getSpecies(), Species::CHIHUAHUA);
    EXPECT_EQ(testChar.getRole(), "TestRole");
    EXPECT_EQ(testChar.getLevel(), 1);
    EXPECT_EQ(testChar.getExperience(), 0);
}

TEST_F(CharacterSystemTest, CharacterCreation_EmptyData_CreatesCharacter) {
    Character testChar("", Species::CAT, "");
    
    EXPECT_EQ(testChar.getName(), "");
    EXPECT_EQ(testChar.getSpecies(), Species::CAT);
    EXPECT_EQ(testChar.getRole(), "");
    EXPECT_EQ(testChar.getLevel(), 1);
    EXPECT_EQ(testChar.getExperience(), 0);
}

// ===== 상세 프로필 생성자 테스트 =====

TEST_F(CharacterSystemTest, DetailedConstructor_ValidData_CreatesCharacterWithProfile) {
    Character testChar("치와와", "치치", 80, 20);
    
    EXPECT_EQ(testChar.getName(), "치치");
    EXPECT_EQ(testChar.getHp(), 80);
    EXPECT_EQ(testChar.getPower(), 20);
    EXPECT_EQ(testChar.getAge(), 5); // 기본값
    EXPECT_EQ(testChar.getAssets(), 1000); // 기본값
    EXPECT_EQ(testChar.getHometown(), "댕댕월드"); // 기본값
}

TEST_F(CharacterSystemTest, DetailedConstructor_DifferentSpecies_CreatesCorrectCharacter) {
    Character humanChar("임정찬", "Liki", 10, 1);
    
    EXPECT_EQ(humanChar.getName(), "Liki");
    EXPECT_EQ(humanChar.getHp(), 10);
    EXPECT_EQ(humanChar.getPower(), 1);
}

// ===== 경험치 및 레벨업 테스트 =====

TEST_F(CharacterSystemTest, GainExperience_PositiveValue_IncreasesExperience) {
    int initialExp = chihuahua.getExperience();
    chihuahua.gainExperience(50);
    
    EXPECT_EQ(chihuahua.getExperience(), initialExp + 50);
}

TEST_F(CharacterSystemTest, GainExperience_ZeroValue_NoChange) {
    int initialExp = chihuahua.getExperience();
    chihuahua.gainExperience(0);
    
    EXPECT_EQ(chihuahua.getExperience(), initialExp);
}

TEST_F(CharacterSystemTest, GainExperience_NegativeValue_NoChange) {
    int initialExp = chihuahua.getExperience();
    chihuahua.gainExperience(-10);
    
    EXPECT_EQ(chihuahua.getExperience(), initialExp);
}

TEST_F(CharacterSystemTest, LevelUp_SufficientExperience_LevelsUp) {
    chihuahua.gainExperience(100); // 레벨업에 필요한 경험치
    bool leveledUp = chihuahua.levelUp();
    
    EXPECT_TRUE(leveledUp);
    EXPECT_EQ(chihuahua.getLevel(), 2);
    EXPECT_EQ(chihuahua.getExperience(), 0); // 경험치 초기화
}

TEST_F(CharacterSystemTest, LevelUp_InsufficientExperience_NoLevelUp) {
    chihuahua.gainExperience(50); // 부족한 경험치
    bool leveledUp = chihuahua.levelUp();
    
    EXPECT_FALSE(leveledUp);
    EXPECT_EQ(chihuahua.getLevel(), 1);
    EXPECT_EQ(chihuahua.getExperience(), 50);
}

// ===== 상태 정보 테스트 =====

TEST_F(CharacterSystemTest, GetStatus_ValidCharacter_ReturnsCorrectStatus) {
    std::string status = chihuahua.getStatus();
    
    EXPECT_TRUE(status.find("Level: 1") != std::string::npos);
    EXPECT_TRUE(status.find("Experience: 0") != std::string::npos);
    EXPECT_TRUE(status.find("HP:") != std::string::npos);
    EXPECT_TRUE(status.find("Power:") != std::string::npos);
}

// ===== 캐릭터 표시 테스트 =====

TEST_F(CharacterSystemTest, Display_ValidEmotion_ShowsCorrectOutput) {
    OutputCapture capture;
    
    chihuahua.display(Emotion::HAPPY);
    
    std::string output = capture.getOutput();
    EXPECT_TRUE(output.find("치치") != std::string::npos);
    EXPECT_TRUE(output.find("치와와") != std::string::npos);
}

TEST_F(CharacterSystemTest, Display_DefaultEmotion_ShowsDefaultOutput) {
    OutputCapture capture;
    
    chihuahua.display();
    
    std::string output = capture.getOutput();
    EXPECT_TRUE(output.find("치치") != std::string::npos);
}

// ===== 모든 캐릭터 종류 테스트 =====

TEST_F(CharacterSystemTest, AllSpecies_DisplayCorrectly) {
    std::vector<Character> characters = {
        chihuahua, welshCorgi, goldenRetriever, husky, rabbit, 
        cat, maltese, humanLiki, humanBabo, mysticalCat
    };
    
    for (const auto& character : characters) {
        OutputCapture capture;
        character.display(Emotion::HAPPY);
        std::string output = capture.getOutput();
        
        EXPECT_FALSE(output.empty());
        EXPECT_TRUE(output.find(character.getName()) != std::string::npos);
    }
}

// ===== 프로필 표시 테스트 =====

TEST_F(CharacterSystemTest, ShowProfile_ValidCharacter_ShowsCompleteProfile) {
    OutputCapture capture;
    
    chihuahua.showProfile();
    
    std::string output = capture.getOutput();
    EXPECT_TRUE(output.find("치치") != std::string::npos);
    EXPECT_TRUE(output.find("나이:") != std::string::npos);
    EXPECT_TRUE(output.find("재산:") != std::string::npos);
    EXPECT_TRUE(output.find("출신지:") != std::string::npos);
    EXPECT_TRUE(output.find("체력(HP):") != std::string::npos);
    EXPECT_TRUE(output.find("공격력(Power):") != std::string::npos);
}

// ===== 캐릭터 비교 테스트 =====

TEST_F(CharacterSystemTest, CharacterComparison_DifferentSpecies_NotEqual) {
    EXPECT_NE(chihuahua.getSpecies(), welshCorgi.getSpecies());
    EXPECT_NE(welshCorgi.getSpecies(), goldenRetriever.getSpecies());
}

TEST_F(CharacterSystemTest, CharacterComparison_SameSpecies_Equal) {
    Character chihuahua2("치치2", Species::CHIHUAHUA, "학생");
    EXPECT_EQ(chihuahua.getSpecies(), chihuahua2.getSpecies());
}

// ===== 캐릭터 팩토리 테스트 =====

TEST_F(CharacterSystemTest, CharacterFactory_CreateChihuahua_ReturnsValidCharacter) {
    Character chihuahua = Character::createChihuahua();
    
    EXPECT_EQ(chihuahua.getName(), "치치");
    EXPECT_EQ(chihuahua.getSpecies(), Species::CHIHUAHUA);
    EXPECT_EQ(chihuahua.getRole(), "선생님");
}

TEST_F(CharacterSystemTest, CharacterFactory_CreateAllTypes_ReturnsValidCharacters) {
    std::vector<Character> characters = {
        Character::createChihuahua(),
        Character::createWelshCorgi(),
        Character::createGoldenRetriever(),
        Character::createHusky(),
        Character::createRabbit(),
        Character::createCat(),
        Character::createMaltese(),
        Character::createBichonFrise(),
        Character::createBulldog(),
        Character::createHumanLiki(),
        Character::createHumanBabo(),
        Character::createMysticalCat()
    };
    
    EXPECT_EQ(characters.size(), 12);
    
    for (const auto& character : characters) {
        EXPECT_FALSE(character.getName().empty());
        EXPECT_FALSE(character.getRole().empty());
    }
}

TEST_F(CharacterSystemTest, CharacterFactory_InitializeAllCharacters_ReturnsCorrectCount) {
    std::vector<Character> allCharacters = Character::initializeCharacters();
    
    EXPECT_EQ(allCharacters.size(), 11); // initializeCharacters는 11개 반환
}

// ===== 캐릭터 관리자 테스트 =====

TEST_F(CharacterSystemTest, CharacterManager_AddCharacter_StoresCharacter) {
    CharacterManager manager;
    manager.addCharacter(chihuahua);
    
    EXPECT_EQ(manager.getCharacterCount(), 1);
}

TEST_F(CharacterSystemTest, CharacterManager_GetCharacterByName_ReturnsCorrectCharacter) {
    CharacterManager manager;
    manager.addCharacter(chihuahua);
    manager.addCharacter(welshCorgi);
    
    Character* found = manager.getCharacterByName("치치");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "치치");
}

TEST_F(CharacterSystemTest, CharacterManager_GetCharacterBySpecies_ReturnsCorrectCharacter) {
    CharacterManager manager;
    manager.addCharacter(chihuahua);
    manager.addCharacter(welshCorgi);
    
    Character* found = manager.getCharacterBySpecies(Species::WELSH_CORGI);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getSpecies(), Species::WELSH_CORGI);
}

TEST_F(CharacterSystemTest, CharacterManager_GetCharactersByRole_ReturnsCorrectCharacters) {
    CharacterManager manager;
    manager.addCharacter(chihuahua); // 선생님
    manager.addCharacter(welshCorgi); // 도우미
    manager.addCharacter(goldenRetriever); // 친구
    
    auto teachers = manager.getCharactersByRole("선생님");
    EXPECT_EQ(teachers.size(), 1);
    EXPECT_EQ(teachers[0].getName(), "치치");
}

TEST_F(CharacterSystemTest, CharacterManager_GetStrongestCharacter_ReturnsHighestPower) {
    CharacterManager manager;
    manager.addCharacter(chihuahua); // power: 50 (기본값)
    manager.addCharacter(welshCorgi); // power: 50 (기본값)
    manager.addCharacter(mysticalCat); // power: 50 (기본값)
    
    Character* strongest = manager.getStrongestCharacter();
    EXPECT_NE(strongest, nullptr);
    // 모든 캐릭터가 동일한 파워를 가지므로 첫 번째 캐릭터가 반환됨
    EXPECT_EQ(strongest->getName(), "치치");
}

TEST_F(CharacterSystemTest, CharacterManager_GetWeakestCharacter_ReturnsLowestPower) {
    CharacterManager manager;
    manager.addCharacter(chihuahua); // power: 50 (기본값)
    manager.addCharacter(welshCorgi); // power: 50 (기본값)
    manager.addCharacter(rabbit); // power: 50 (기본값)
    
    Character* weakest = manager.getWeakestCharacter();
    EXPECT_NE(weakest, nullptr);
    // 모든 캐릭터가 동일한 파워를 가지므로 첫 번째 캐릭터가 반환됨
    EXPECT_EQ(weakest->getName(), "치치");
}

TEST_F(CharacterSystemTest, CharacterManager_GetAverageLevel_ReturnsCorrectAverage) {
    CharacterManager manager;
    manager.addCharacter(chihuahua); // level: 1
    manager.addCharacter(welshCorgi); // level: 1
    manager.addCharacter(goldenRetriever); // level: 1
    
    double average = manager.getAverageLevel();
    EXPECT_EQ(average, 1.0);
}

// ===== 감정별 표시 테스트 =====

TEST_F(CharacterSystemTest, DisplayEmotions_AllEmotions_ShowCorrectOutput) {
    std::vector<Emotion> emotions = {
        Emotion::DEFAULT, Emotion::HAPPY, Emotion::SAD, 
        Emotion::THINKING, Emotion::SURPRISED, Emotion::ANGRY
    };
    
    for (const auto& emotion : emotions) {
        OutputCapture capture;
        chihuahua.display(emotion);
        std::string output = capture.getOutput();
        
        EXPECT_FALSE(output.empty());
        EXPECT_TRUE(output.find("치치") != std::string::npos);
    }
}

// ===== 특수 캐릭터 테스트 =====

TEST_F(CharacterSystemTest, HumanCharacters_HaveCorrectProperties) {
    EXPECT_EQ(humanLiki.getName(), "Liki");
    EXPECT_EQ(humanLiki.getSpecies(), Species::HUMAN_LIKI);
    EXPECT_EQ(humanLiki.getRole(), "학생");
    
    EXPECT_EQ(humanBabo.getName(), "바보");
    EXPECT_EQ(humanBabo.getSpecies(), Species::HUMAN_BABO);
    EXPECT_EQ(humanBabo.getRole(), "분위기메이커");
}

TEST_F(CharacterSystemTest, MysticalCat_HasCorrectProperties) {
    EXPECT_EQ(mysticalCat.getName(), "먀엉");
    EXPECT_EQ(mysticalCat.getSpecies(), Species::MYSTICAL_CAT);
    EXPECT_EQ(mysticalCat.getRole(), "현자");
}

// ===== 연산자 오버로딩 테스트 =====

TEST_F(CharacterSystemTest, OperatorEquality_SameCharacter_ReturnsTrue) {
    Character char1("Test", Species::CHIHUAHUA, "Role");
    Character char2("Test", Species::CHIHUAHUA, "Role");
    
    EXPECT_TRUE(char1 == char2);
}

TEST_F(CharacterSystemTest, OperatorEquality_DifferentCharacter_ReturnsFalse) {
    Character char1("Test1", Species::CHIHUAHUA, "Role");
    Character char2("Test2", Species::CHIHUAHUA, "Role");
    
    EXPECT_FALSE(char1 == char2);
}

TEST_F(CharacterSystemTest, OperatorInequality_DifferentCharacter_ReturnsTrue) {
    Character char1("Test1", Species::CHIHUAHUA, "Role");
    Character char2("Test2", Species::CHIHUAHUA, "Role");
    
    EXPECT_TRUE(char1 != char2);
}

// ===== 경계값 테스트 =====

TEST_F(CharacterSystemTest, BoundaryValues_ExtremeExperience_HandlesCorrectly) {
    // 매우 큰 경험치
    chihuahua.gainExperience(999999);
    EXPECT_EQ(chihuahua.getExperience(), 999999);
    
    // 음수 경험치 (변화 없어야 함)
    int initialExp = chihuahua.getExperience();
    chihuahua.gainExperience(-999999);
    EXPECT_EQ(chihuahua.getExperience(), initialExp);
}

TEST_F(CharacterSystemTest, BoundaryValues_EmptyStrings_HandlesCorrectly) {
    Character emptyChar("", Species::CAT, "");
    
    EXPECT_EQ(emptyChar.getName(), "");
    EXPECT_EQ(emptyChar.getRole(), "");
    EXPECT_EQ(emptyChar.getSpecies(), Species::CAT);
}

// ===== 성능 테스트 =====

TEST_F(CharacterSystemTest, Performance_MultipleCharacters_HandlesEfficiently) {
    CharacterManager manager;
    
    // 많은 캐릭터 추가
    for (int i = 0; i < 100; ++i) {
        Character char1("Test" + std::to_string(i), Species::CHIHUAHUA, "Role");
        manager.addCharacter(char1);
    }
    
    EXPECT_EQ(manager.getCharacterCount(), 100);
    
    // 검색 성능 테스트
    Character* found = manager.getCharacterByName("Test50");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "Test50");
}

// ===== 통합 테스트 =====

TEST_F(CharacterSystemTest, Integration_CompleteCharacterLifecycle_WorksCorrectly) {
    // 1. 캐릭터 생성
    Character character("TestChar", Species::CHIHUAHUA, "TestRole");
    EXPECT_EQ(character.getName(), "TestChar");
    EXPECT_EQ(character.getLevel(), 1);
    
    // 2. 경험치 획득
    character.gainExperience(50);
    EXPECT_EQ(character.getExperience(), 50);
    
    // 3. 레벨업
    character.gainExperience(50); // 총 100 경험치
    bool leveledUp = character.levelUp();
    EXPECT_TRUE(leveledUp);
    EXPECT_EQ(character.getLevel(), 2);
    EXPECT_EQ(character.getExperience(), 0);
    
    // 4. 표시 테스트
    OutputCapture capture;
    character.display(Emotion::HAPPY);
    std::string output = capture.getOutput();
    EXPECT_TRUE(output.find("TestChar") != std::string::npos);
    
    // 5. 프로필 표시 테스트
    OutputCapture capture2;
    character.showProfile();
    std::string output2 = capture2.getOutput();
    EXPECT_TRUE(output2.find("TestChar") != std::string::npos);
} 