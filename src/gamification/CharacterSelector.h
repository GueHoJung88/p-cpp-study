#pragma once

#include "../core/Character.h"
#include <string>
#include <vector>
#include <map>

namespace learning {
namespace gamification {

// 상황별 대화 타입
enum class SituationType {
    LEARNING,           // 학습 중
    QUIZ_START,        // 퀴즈 시작
    QUIZ_SUCCESS,      // 퀴즈 성공
    QUIZ_FAILURE,      // 퀴즈 실패
    LEVEL_UP,          // 레벨업
    ENCOURAGEMENT,     // 격려
    CELEBRATION,       // 축하
    COMFORT,           // 위로
    EXPLANATION,       // 설명
    HINT,              // 힌트
    CORRECTION,        // 정정
    WELCOME,           // 환영
    GOODBYE,           // 작별
    MORNING,           // 아침 인사
    EVENING,           // 저녁 인사
    STUDY_BREAK,       // 학습 휴식
    STUDY_RESUME,      // 학습 재개
    ERROR_HANDLING,    // 오류 처리
    SUCCESS_FEEDBACK,  // 성공 피드백
    FAILURE_FEEDBACK   // 실패 피드백
};

// 감정별 대화 타입
enum class EmotionDialogueType {
    HAPPY,             // 기쁨
    SAD,               // 슬픔
    THINKING,          // 생각
    SURPRISED,         // 놀람
    ANGRY,             // 화남
    EXCITED,           // 흥분
    PROUD,             // 자랑
    CONFUSED,          // 혼란
    DETERMINED,        // 의지
    CURIOUS,           // 호기심
    SHY,               // 수줍음
    PLAYFUL,           // 장난
    CALM,              // 차분
    ENTHUSIASTIC,      // 열정
    RELAXED,           // 편안
    FOCUSED,           // 집중
    TIRED,             // 피곤
    MOTIVATED,         // 동기부여
    SATISFIED,         // 만족
    DISAPPOINTED       // 실망
};

// 캐릭터 대화 시스템
class CharacterDialogueSystem {
private:
    std::map<Species, std::map<SituationType, std::vector<std::string>>> situationDialogues;
    std::map<Species, std::map<EmotionDialogueType, std::vector<std::string>>> emotionDialogues;
    
    void initializeChihuahuaDialogues();
    void initializeWelshCorgiDialogues();
    void initializeGoldenRetrieverDialogues();
    void initializeHuskyDialogues();
    void initializeRabbitDialogues();
    void initializeCatDialogues();
    void initializeMalteseDialogues();
    void initializeBichonFriseDialogues();
    void initializeBulldogDialogues();
    void initializeHumanLikiDialogues();
    void initializeHumanBaboDialogues();
    void initializeMysticalCatDialogues();

public:
    CharacterDialogueSystem();
    
    // 상황별 대화 가져오기
    std::string getSituationDialogue(Species species, SituationType situation);
    std::string getRandomSituationDialogue(Species species, SituationType situation);
    
    // 감정별 대화 가져오기
    std::string getEmotionDialogue(Species species, EmotionDialogueType emotion);
    std::string getRandomEmotionDialogue(Species species, EmotionDialogueType emotion);
    
    // 복합 대화 (상황 + 감정)
    std::string getCombinedDialogue(Species species, SituationType situation, EmotionDialogueType emotion);
    
    // 대화 추가/수정
    void addSituationDialogue(Species species, SituationType situation, const std::string& dialogue);
    void addEmotionDialogue(Species species, EmotionDialogueType emotion, const std::string& dialogue);
};

// 캐릭터 선택기
class CharacterSelector {
private:
    std::vector<Character> availableCharacters;
    CharacterDialogueSystem dialogueSystem;
    
public:
    CharacterSelector();
    
    // 사용 가능한 캐릭터 목록 표시
    void displayAvailableCharacters() const;
    
    // 사용 가능한 모든 캐릭터 가져오기
    const std::vector<Character>& getAllCharacters() const { return availableCharacters; }
    
    // 캐릭터 선택
    Character* selectCharacter();
    Character* selectCharacterByName(const std::string& name);
    Character* selectCharacterBySpecies(Species species);
    
    // 캐릭터 정보 표시
    void displayCharacterInfo(const Character& character) const;
    void displayCharacterProfile(const Character& character) const;
    
    // 캐릭터 커스터마이징
    Character customizeCharacter(const Character& baseCharacter);
    void editCharacterName(Character& character, const std::string& newName);
    void editCharacterRole(Character& character, const std::string& newRole);
    void editCharacterProfile(Character& character);
    
    // 캐릭터 저장/불러오기
    bool saveCharacter(const Character& character, const std::string& filename);
    Character* loadCharacter(const std::string& filename);
    
    // 대화 시스템 접근
    CharacterDialogueSystem& getDialogueSystem() { return dialogueSystem; }
};

// 캐릭터 정의 프로그램 메인 클래스
class CharacterDefinitionProgram {
private:
    CharacterSelector selector;
    Character* currentCharacter;
    
public:
    CharacterDefinitionProgram();
    ~CharacterDefinitionProgram();
    
    // 메인 실행 루프
    void run();
    
    // 메뉴 시스템
    void showMainMenu();
    void showCharacterMenu();
    void showCustomizationMenu();
    void showDialogueMenu();
    
    // 캐릭터 관리
    void createNewCharacter();
    void loadExistingCharacter();
    void saveCurrentCharacter();
    void deleteCharacter();
    
    // 대화 시스템 테스트
    void testDialogueSystem();
    void testSituationDialogues();
    void testEmotionDialogues();
    
    // 설정
    void showSettings();
    void exportCharacterData();
    void importCharacterData();
};

} // namespace gamification
} // namespace learning 