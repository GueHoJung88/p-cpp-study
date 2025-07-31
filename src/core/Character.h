#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>

namespace learning {

// 감정 타입 열거형
enum class Emotion {
    DEFAULT,
    HAPPY,
    SAD,
    THINKING,
    SURPRISED,
    ANGRY,
    EXPLAIN,
    QUIZ,
    JUDGE,
    CORRECT,
    WRONG,
    EXCITED,
    PROUD
};

// 캐릭터 종류 열거형 (기존 gemini 파일의 모든 캐릭터 포함)
enum class Species {
    CHIHUAHUA,          // 치와와
    WELSH_CORGI,        // 웰시코기
    GOLDEN_RETRIEVER,   // 골든리트리버
    HUSKY,              // 허스키
    RABBIT,             // 토끼
    CAT,                // 고양이
    MALTESE,            // 말티즈
    BICHON_FRISE,       // 비숑 프리제
    BULLDOG,            // 불독
    HUMAN_LIKI,         // 임정찬 (Liki)
    HUMAN_BABO,         // 정규호 (바보)
    MYSTICAL_CAT        // 싀백 (먀엉)
};

class Character {
private:
    // 기본 정보
    std::string name;
    Species species;
    std::string role;
    
    // 게임 시스템 관련
    int level;
    int experience;
    int maxExperience;
    
    // 상세 프로필 정보 (gemini 파일에서 가져온 정보)
    int age;
    long long assets;
    std::string hometown;
    std::string gender;
    std::string social_status;
    std::string ideal_type;
    std::string future_hope;
    std::string weakness;
    int hp;
    int power;
    
    // 감정별 ASCII 아트 저장
    std::map<Emotion, std::vector<std::string>> emotionArt;
    
    // 캐릭터별 기본 ASCII 아트 초기화
    void initializeChihuahuaArt();
    void initializeWelshCorgiArt();
    void initializeGoldenRetrieverArt();
    void initializeHuskyArt();
    void initializeRabbitArt();
    void initializeCatArt();
    void initializeMalteseArt();
    void initializeBichonFriseArt();
    void initializeBulldogArt();
    void initializeHumanLikiArt();
    void initializeHumanBaboArt();
    void initializeMysticalCatArt();
    
    // 종별 상세 ASCII 아트 출력 함수들
    void displayChihuahua(Emotion emotion) const;
    void displayWelshCorgi(Emotion emotion) const;
    void displayGoldenRetriever(Emotion emotion) const;
    void displayHusky(Emotion emotion) const;
    void displayRabbit(Emotion emotion) const;
    void displayCat(Emotion emotion) const;
    void displayMaltese(Emotion emotion) const;
    void displayBichonFrise(Emotion emotion) const;
    void displayBulldog(Emotion emotion) const;
    void displayHumanLiki(Emotion emotion) const;
    void displayHumanBabo(Emotion emotion) const;
    void displayMysticalCat(Emotion emotion) const;
    void displayDefault(Emotion emotion) const;

public:
    // 기본 생성자 (테스트용)
    Character();
    
    // 기존 코드 호환성을 위한 생성자들
    Character(const std::string& n, Species s, const std::string& r);
    Character(const std::string& sp, const std::string& n, int h, int p);
    
    // 문자열 기반 생성자 (기존 코드 호환)
    Character(const std::string& n, const std::string& s, const std::string& r);
    
    // 기본 접근자
    std::string getName() const { return name; }
    Species getSpecies() const { return species; }
    std::string getRole() const { return role; }
    int getLevel() const { return level; }
    int getExperience() const { return experience; }
    int getMaxExperience() const { return maxExperience; }
    
    // 상세 프로필 접근자
    int getAge() const { return age; }
    long long getAssets() const { return assets; }
    std::string getHometown() const { return hometown; }
    std::string getGender() const { return gender; }
    std::string getSocialStatus() const { return social_status; }
    std::string getIdealType() const { return ideal_type; }
    std::string getFutureHope() const { return future_hope; }
    std::string getWeakness() const { return weakness; }
    int getHp() const { return hp; }
    int getPower() const { return power; }
    
    // 상세 프로필 설정자
    void setAge(int a) { age = a; }
    void setAssets(long long a) { assets = a; }
    void setHometown(const std::string& h) { hometown = h; }
    void setGender(const std::string& g) { gender = g; }
    void setSocialStatus(const std::string& s) { social_status = s; }
    void setIdealType(const std::string& i) { ideal_type = i; }
    void setFutureHope(const std::string& f) { future_hope = f; }
    void setWeakness(const std::string& w) { weakness = w; }
    void setHp(int h) { hp = h; }
    void setPower(int p) { power = p; }
    
    // 기존 코드 호환성을 위한 접근자들
    std::string getSpeciesString() const;
    void setSpecies(const std::string& s);
    
    // 게임 시스템
    void gainExperience(int exp);
    bool levelUp();
    std::string getStatus() const;
    
    // 표시 시스템
    void display(Emotion emotion = Emotion::DEFAULT) const;
    void displayWithMessage(Emotion emotion, const std::string& message) const;
    void display(const std::string& emotion) const; // 문자열 기반 호환
    std::string getEmotionString(Emotion emotion) const;
    void showProfile() const;
    
    // 연산자 오버로딩
    bool operator==(const Character& other) const;
    bool operator!=(const Character& other) const;
    
    // 정적 팩토리 메서드들
    static Character createChihuahua(const std::string& name = "치치", const std::string& role = "선생님");
    static Character createWelshCorgi(const std::string& name = "코코", const std::string& role = "도우미");
    static Character createGoldenRetriever(const std::string& name = "리버", const std::string& role = "친구");
    static Character createHusky(const std::string& name = "허허", const std::string& role = "모험가");
    static Character createRabbit(const std::string& name = "토토", const std::string& role = "퀴즈");
    static Character createCat(const std::string& name = "냥냥", const std::string& role = "채점");
    static Character createMaltese(const std::string& name = "보리", const std::string& role = "주인공");
    static Character createBichonFrise(const std::string& name = "숑숑", const std::string& role = "친구");
    static Character createBulldog(const std::string& name = "불리", const std::string& role = "보호자");
    static Character createHumanLiki(const std::string& name = "Liki", const std::string& role = "학생");
    static Character createHumanBabo(const std::string& name = "바보", const std::string& role = "분위기메이커");
    static Character createMysticalCat(const std::string& name = "먀엉", const std::string& role = "현자");
    
    // 기존 코드 호환성을 위한 정적 메서드들
    static std::vector<Character> initializeCharacters();
    static std::vector<Character> getDefaultCharacters();
    static std::vector<Character> initializeAllCharacters();
};

// 캐릭터 관리자 클래스
class CharacterManager {
private:
    std::vector<Character> characters;
    
public:
    CharacterManager() = default;
    void addCharacter(const Character& character);
    Character* getCharacterByName(const std::string& name);
    Character* getCharacterBySpecies(Species species);
    std::vector<Character> getAllCharacters() const;
    void removeCharacter(const std::string& name);
    void clear();
    size_t getCharacterCount() const;
    
    // 특별한 기능들
    std::vector<Character> getCharactersByRole(const std::string& role) const;
    std::vector<Character> getCharactersByHometown(const std::string& hometown) const;
    Character* getStrongestCharacter() const;
    Character* getWeakestCharacter() const;
    double getAverageLevel() const;
};

// 캐릭터 팩토리 클래스
class CharacterFactory {
public:
    static Character createChihuahua(const std::string& name = "치치", const std::string& role = "선생님");
    static Character createWelshCorgi(const std::string& name = "코코", const std::string& role = "도우미");
    static Character createGoldenRetriever(const std::string& name = "리버", const std::string& role = "친구");
    static Character createHusky(const std::string& name = "허허", const std::string& role = "모험가");
    static Character createRabbit(const std::string& name = "토토", const std::string& role = "학생");
    static Character createCat(const std::string& name = "냥냥", const std::string& role = "고양이");
    static Character createMaltese(const std::string& name = "보리", const std::string& role = "주인공");
    static Character createBichonFrise(const std::string& name = "숑숑", const std::string& role = "미용사");
    static Character createBulldog(const std::string& name = "불리", const std::string& role = "경비원");
    static Character createHumanLiki(const std::string& name = "리키", const std::string& role = "학생");
    static Character createHumanBabo(const std::string& name = "바보", const std::string& role = "바보");
    static Character createMysticalCat(const std::string& name = "먀엉", const std::string& role = "지혜의 수호자");
    
    static std::vector<Character> initializeAllCharacters();
};

} // namespace learning 