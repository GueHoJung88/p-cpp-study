#include "Character.h"
#include <iostream>
#include <algorithm>

namespace learning {

// 기본 생성자 (테스트용)
Character::Character() 
    : name("Test"), species(Species::CHIHUAHUA), role("Test"), 
      level(1), experience(0), maxExperience(100),
      age(5), assets(1000), hometown("Test Town"), gender("Unknown"),
      social_status("Student"), ideal_type("Learning"), future_hope("Success"),
      weakness("None"), hp(100), power(50) {
    initializeChihuahuaArt();
}

// 기존 코드 호환성을 위한 생성자들
Character::Character(const std::string& n, Species s, const std::string& r)
    : name(n), species(s), role(r), 
      level(1), experience(0), maxExperience(100),
      age(5), assets(1000), hometown("Unknown"), gender("Unknown"),
      social_status("Student"), ideal_type("Learning"), future_hope("Success"),
      weakness("None"), hp(100), power(50) {
    
    // 종류별 ASCII 아트 초기화
    switch (s) {
        case Species::CHIHUAHUA:
            initializeChihuahuaArt();
            break;
        case Species::WELSH_CORGI:
            initializeWelshCorgiArt();
            break;
        case Species::GOLDEN_RETRIEVER:
            initializeGoldenRetrieverArt();
            break;
        case Species::HUSKY:
            initializeHuskyArt();
            break;
        case Species::RABBIT:
            initializeRabbitArt();
            break;
        case Species::CAT:
            initializeCatArt();
            break;
        case Species::MALTESE:
            initializeMalteseArt();
            break;
        case Species::BICHON_FRISE:
            initializeBichonFriseArt();
            break;
        case Species::BULLDOG:
            initializeBulldogArt();
            break;
        case Species::HUMAN_LIKI:
            initializeHumanLikiArt();
            break;
        case Species::HUMAN_BABO:
            initializeHumanBaboArt();
            break;
        case Species::MYSTICAL_CAT:
            initializeMysticalCatArt();
            break;
    }
}

// gemini 파일 스타일 생성자
Character::Character(const std::string& sp, const std::string& n, int h, int p)
    : name(n), species(Species::CHIHUAHUA), role("Student"), 
      level(1), experience(0), maxExperience(100),
      age(5), assets(1000), hometown("댕댕월드"), gender("비밀"),
      social_status("모험가 지망생"), ideal_type("맛있는 거 주는 사람"), 
      future_hope("세상 모든 공을 모으는 것"), weakness("진공청소기 소리"),
      hp(h), power(p) {
    
    // 문자열을 Species enum으로 변환
    setSpecies(sp);
    initializeChihuahuaArt();
}

// 문자열 기반 생성자 (기존 코드 호환)
Character::Character(const std::string& n, const std::string& s, const std::string& r)
    : name(n), species(Species::CHIHUAHUA), role(r), 
      level(1), experience(0), maxExperience(100),
      age(5), assets(1000), hometown("Unknown"), gender("Unknown"),
      social_status("Student"), ideal_type("Learning"), future_hope("Success"),
      weakness("None"), hp(100), power(50) {
    
    setSpecies(s);
    initializeChihuahuaArt();
}

// 기존 코드 호환성을 위한 메서드들
std::string Character::getSpeciesString() const {
    switch (species) {
        case Species::CHIHUAHUA: return "치와와";
        case Species::WELSH_CORGI: return "웰시코기";
        case Species::GOLDEN_RETRIEVER: return "골든리트리버";
        case Species::HUSKY: return "허스키";
        case Species::RABBIT: return "토끼";
        case Species::CAT: return "고양이";
        case Species::MALTESE: return "말티즈";
        case Species::BICHON_FRISE: return "비숑 프리제";
        case Species::BULLDOG: return "불독";
        case Species::HUMAN_LIKI: return "임정찬";
        case Species::HUMAN_BABO: return "정규호";
        case Species::MYSTICAL_CAT: return "싀백";
        default: return "Unknown";
    }
}

void Character::setSpecies(const std::string& s) {
    if (s == "치와와" || s == "Chihuahua") species = Species::CHIHUAHUA;
    else if (s == "웰시코기" || s == "Welsh Corgi") species = Species::WELSH_CORGI;
    else if (s == "골든리트리버" || s == "Golden Retriever") species = Species::GOLDEN_RETRIEVER;
    else if (s == "허스키" || s == "Husky") species = Species::HUSKY;
    else if (s == "토끼" || s == "Rabbit") species = Species::RABBIT;
    else if (s == "고양이" || s == "Cat") species = Species::CAT;
    else if (s == "말티즈" || s == "Maltese") species = Species::MALTESE;
    else if (s == "비숑 프리제" || s == "Bichon Frise") species = Species::BICHON_FRISE;
    else if (s == "불독" || s == "Bulldog") species = Species::BULLDOG;
    else if (s == "임정찬" || s == "Liki") species = Species::HUMAN_LIKI;
    else if (s == "정규호" || s == "바보") species = Species::HUMAN_BABO;
    else if (s == "싀백" || s == "먀엉") species = Species::MYSTICAL_CAT;
    else species = Species::CHIHUAHUA; // 기본값
}

// 문자열 기반 display 메서드 (기존 코드 호환)
void Character::display(const std::string& emotion) const {
    Emotion e = Emotion::DEFAULT;
    
    if (emotion == "happy") e = Emotion::HAPPY;
    else if (emotion == "sad") e = Emotion::SAD;
    else if (emotion == "thinking") e = Emotion::THINKING;
    else if (emotion == "surprised") e = Emotion::SURPRISED;
    else if (emotion == "angry") e = Emotion::ANGRY;
    else if (emotion == "explain") e = Emotion::EXPLAIN;
    else if (emotion == "quiz") e = Emotion::QUIZ;
    else if (emotion == "judge") e = Emotion::JUDGE;
    else if (emotion == "correct") e = Emotion::CORRECT;
    else if (emotion == "wrong") e = Emotion::WRONG;
    
    display(e);
}

// 경험치 획득
void Character::gainExperience(int exp) {
    if (exp > 0) {
        experience += exp;
        // levelUp()은 별도로 호출하도록 변경
    }
}

// 레벨업
bool Character::levelUp() {
    if (experience >= maxExperience) {
        level++;
        experience -= maxExperience;
        maxExperience = level * 100; // 레벨에 따라 필요 경험치 증가
        hp += 10; // 레벨업 시 HP 증가
        power += 5; // 레벨업 시 파워 증가
        return true;
    }
    return false;
}

// 상태 정보 반환
std::string Character::getStatus() const {
    return "Level: " + std::to_string(level) + 
           ", Experience: " + std::to_string(experience) + "/" + std::to_string(maxExperience) +
           ", HP: " + std::to_string(hp) + 
           ", Power: " + std::to_string(power);
}

// 캐릭터 표시
void Character::display(Emotion emotion) const {
    std::cout << "=== " << name << " (" << getSpeciesString() << ") ===" << std::endl;
    auto it = emotionArt.find(emotion);
    if (it != emotionArt.end()) {
        for (const auto& line : it->second) {
            std::cout << line << std::endl;
        }
    } else {
        // 기본 감정으로 표시
        auto defaultIt = emotionArt.find(Emotion::DEFAULT);
        if (defaultIt != emotionArt.end()) {
            for (const auto& line : defaultIt->second) {
                std::cout << line << std::endl;
            }
        }
    }
}

// 메시지와 함께 표시
void Character::displayWithMessage(Emotion emotion, const std::string& message) const {
    display(emotion);
    std::cout << name << ": " << message << std::endl;
}

// 감정 문자열 반환
std::string Character::getEmotionString(Emotion emotion) const {
    switch (emotion) {
        case Emotion::DEFAULT: return "기본";
        case Emotion::HAPPY: return "행복";
        case Emotion::SAD: return "슬픔";
        case Emotion::THINKING: return "생각";
        case Emotion::SURPRISED: return "놀람";
        case Emotion::ANGRY: return "화남";
        case Emotion::EXPLAIN: return "설명";
        case Emotion::QUIZ: return "퀴즈";
        case Emotion::JUDGE: return "채점";
        case Emotion::CORRECT: return "정답";
        case Emotion::WRONG: return "오답";
        default: return "기본";
    }
}

// 프로필 표시
void Character::showProfile() const {
    std::cout << "=== " << name << "의 프로필 ===" << std::endl;
    std::cout << "종류: " << getSpeciesString() << std::endl;
    std::cout << "역할: " << role << std::endl;
    std::cout << "나이: " << age << "세" << std::endl;
    std::cout << "재산: " << assets << "원" << std::endl;
    std::cout << "출신지: " << hometown << std::endl;
    std::cout << "성별: " << gender << std::endl;
    std::cout << "사회적 지위: " << social_status << std::endl;
    std::cout << "이상형: " << ideal_type << std::endl;
    std::cout << "미래 희망: " << future_hope << std::endl;
    std::cout << "약점: " << weakness << std::endl;
    std::cout << "체력(HP): " << hp << ", 공격력(Power): " << power << std::endl;
    std::cout << getStatus() << std::endl;
}

// 연산자 오버로딩
bool Character::operator==(const Character& other) const {
    return species == other.species && name == other.name;
}

bool Character::operator!=(const Character& other) const {
    return !(*this == other);
}

// 정적 팩토리 메서드들
Character Character::createChihuahua(const std::string& name, const std::string& role) {
    return Character(name, Species::CHIHUAHUA, role);
}

Character Character::createWelshCorgi(const std::string& name, const std::string& role) {
    return Character(name, Species::WELSH_CORGI, role);
}

Character Character::createGoldenRetriever(const std::string& name, const std::string& role) {
    return Character(name, Species::GOLDEN_RETRIEVER, role);
}

Character Character::createHusky(const std::string& name, const std::string& role) {
    return Character(name, Species::HUSKY, role);
}

Character Character::createRabbit(const std::string& name, const std::string& role) {
    return Character(name, Species::RABBIT, role);
}

Character Character::createCat(const std::string& name, const std::string& role) {
    return Character(name, Species::CAT, role);
}

Character Character::createMaltese(const std::string& name, const std::string& role) {
    return Character(name, Species::MALTESE, role);
}

Character Character::createBichonFrise(const std::string& name, const std::string& role) {
    return Character(name, Species::BICHON_FRISE, role);
}

Character Character::createBulldog(const std::string& name, const std::string& role) {
    return Character(name, Species::BULLDOG, role);
}

Character Character::createHumanLiki(const std::string& name, const std::string& role) {
    return Character(name, Species::HUMAN_LIKI, role);
}

Character Character::createHumanBabo(const std::string& name, const std::string& role) {
    return Character(name, Species::HUMAN_BABO, role);
}

Character Character::createMysticalCat(const std::string& name, const std::string& role) {
    return Character(name, Species::MYSTICAL_CAT, role);
}

// 기존 코드 호환성을 위한 정적 메서드들
std::vector<Character> Character::initializeCharacters() {
    std::vector<Character> characters;
    characters.push_back(Character("치와와", "치치", 80, 20));
    characters.push_back(Character("웰시코기", "코코", 120, 30));
    characters.push_back(Character("허스키", "허허", 200, 50));
    characters.push_back(Character("토끼", "토토", 50, 5));
    characters.push_back(Character("고양이", "냥냥", 70, 25));
    characters.push_back(Character("골든 리트리버", "리버", 150, 40));
    characters.push_back(Character("비숑 프리제", "숑숑", 90, 15));
    characters.push_back(Character("불독", "불리", 180, 60));
    characters.push_back(Character("임정찬", "Liki", 10, 1));
    characters.push_back(Character("정규호", "바보", 10, 2));
    characters.push_back(Character("싀백", "먀엉", 120, 100));
    return characters;
}

std::vector<Character> Character::getDefaultCharacters() {
    return initializeCharacters();
}

// 모든 캐릭터 초기화
std::vector<Character> Character::initializeAllCharacters() {
    std::vector<Character> characters;
    characters.push_back(createChihuahua());
    characters.push_back(createWelshCorgi());
    characters.push_back(createGoldenRetriever());
    characters.push_back(createHusky());
    characters.push_back(createRabbit());
    characters.push_back(createCat());
    characters.push_back(createMaltese());
    characters.push_back(createBichonFrise());
    characters.push_back(createBulldog());
    characters.push_back(createHumanLiki());
    characters.push_back(createHumanBabo());
    characters.push_back(createMysticalCat());
    return characters;
}

// ASCII 아트 초기화 메서드들
void Character::initializeChihuahuaArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "치와와 " + name
    };
    emotionArt[Emotion::HAPPY] = {
        "  /\\_/\\",
        " ( ^.^ )",
        "  > ^ <",
        "행복한 " + name
    };
    emotionArt[Emotion::SAD] = {
        "  /\\_/\\",
        " ( T.T )",
        "  > ^ <",
        "슬픈 " + name
    };
    emotionArt[Emotion::THINKING] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "생각하는 " + name
    };
    emotionArt[Emotion::SURPRISED] = {
        "  /\\_/\\",
        " ( O.O )",
        "  > ^ <",
        "놀란 " + name
    };
    emotionArt[Emotion::ANGRY] = {
        "  /\\_/\\",
        " ( >.< )",
        "  > ^ <",
        "화난 " + name
    };
}

void Character::initializeWelshCorgiArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "웰시코기 " + name
    };
}

void Character::initializeGoldenRetrieverArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "골든리트리버 " + name
    };
}

void Character::initializeHuskyArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "허스키 " + name
    };
}

void Character::initializeRabbitArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "토끼 " + name
    };
}

void Character::initializeCatArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "고양이 " + name
    };
}

void Character::initializeMalteseArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "말티즈 " + name
    };
}

void Character::initializeBichonFriseArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "비숑 프리제 " + name
    };
}

void Character::initializeBulldogArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "불독 " + name
    };
}

void Character::initializeHumanLikiArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  (^_^)",
        "  /|\\",
        "  / \\",
        "인간 " + name
    };
}

void Character::initializeHumanBaboArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  (^_^)",
        "  /|\\",
        "  / \\",
        "인간 " + name
    };
}

void Character::initializeMysticalCatArt() {
    emotionArt[Emotion::DEFAULT] = {
        "  /\\_/\\",
        " ( o.o )",
        "  > ^ <",
        "신비한 고양이 " + name
    };
}

// CharacterManager 구현
void CharacterManager::addCharacter(const Character& character) {
    characters.push_back(character);
}

size_t CharacterManager::getCharacterCount() const {
    return characters.size();
}

Character* CharacterManager::getCharacterByName(const std::string& name) {
    for (auto& character : characters) {
        if (character.getName() == name) {
            return &character;
        }
    }
    return nullptr;
}

Character* CharacterManager::getCharacterBySpecies(Species species) {
    for (auto& character : characters) {
        if (character.getSpecies() == species) {
            return &character;
        }
    }
    return nullptr;
}

std::vector<Character> CharacterManager::getCharactersByRole(const std::string& role) const {
    std::vector<Character> result;
    for (const auto& character : characters) {
        if (character.getRole() == role) {
            result.push_back(character);
        }
    }
    return result;
}

std::vector<Character> CharacterManager::getCharactersByHometown(const std::string& hometown) const {
    std::vector<Character> result;
    for (const auto& character : characters) {
        if (character.getHometown() == hometown) {
            result.push_back(character);
        }
    }
    return result;
}

Character* CharacterManager::getStrongestCharacter() const {
    if (characters.empty()) return nullptr;
    
    Character* strongest = const_cast<Character*>(&characters[0]);
    for (const auto& character : characters) {
        if (character.getPower() > strongest->getPower()) {
            strongest = const_cast<Character*>(&character);
        }
    }
    return strongest;
}

Character* CharacterManager::getWeakestCharacter() const {
    if (characters.empty()) return nullptr;
    
    Character* weakest = const_cast<Character*>(&characters[0]);
    for (const auto& character : characters) {
        if (character.getPower() < weakest->getPower()) {
            weakest = const_cast<Character*>(&character);
        }
    }
    return weakest;
}

double CharacterManager::getAverageLevel() const {
    if (characters.empty()) return 0.0;
    
    int totalLevel = 0;
    for (const auto& character : characters) {
        totalLevel += character.getLevel();
    }
    return static_cast<double>(totalLevel) / characters.size();
}

void CharacterManager::removeCharacter(const std::string& name) {
    characters.erase(
        std::remove_if(characters.begin(), characters.end(),
            [&name](const Character& c) { return c.getName() == name; }),
        characters.end()
    );
}

void CharacterManager::clear() {
    characters.clear();
}

} // namespace learning 