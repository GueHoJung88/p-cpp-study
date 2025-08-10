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

// 문자열을 Species enum으로 변환
void Character::setSpecies(const std::string& speciesStr) {
    if (speciesStr == "치와와") species = Species::CHIHUAHUA;
    else if (speciesStr == "웰시코기") species = Species::WELSH_CORGI;
    else if (speciesStr == "골든리트리버") species = Species::GOLDEN_RETRIEVER;
    else if (speciesStr == "허스키") species = Species::HUSKY;
    else if (speciesStr == "토끼") species = Species::RABBIT;
    else if (speciesStr == "고양이") species = Species::CAT;
    else if (speciesStr == "말티즈") species = Species::MALTESE;
    else if (speciesStr == "비숑 프리제") species = Species::BICHON_FRISE;
    else if (speciesStr == "불독") species = Species::BULLDOG;
    else if (speciesStr == "임정찬") species = Species::HUMAN_LIKI;
    else if (speciesStr == "정규호") species = Species::HUMAN_BABO;
    else if (speciesStr == "싀백") species = Species::MYSTICAL_CAT;
    else species = Species::CHIHUAHUA; // 기본값
}

// 경험치 획득 및 레벨업
void Character::gainExperience(int exp) {
    experience += exp;
    while (experience >= maxExperience) {
        experience -= maxExperience;
        level++;
        maxExperience = level * 100; // 레벨업 시 필요 경험치 증가
        hp += 10; // 레벨업 시 HP 증가
        power += 5; // 레벨업 시 공격력 증가
    }
}

// 업데이트된 display 함수 - Gemini Character.h의 상세 이미지 통합
void Character::display(Emotion emotion) const {
    std::cout << "--- " << name << " (" << getSpeciesString() << ") | 현재 감정: " << getEmotionString(emotion) << " ---" << std::endl;

    // 종별 상세 ASCII 아트 출력
    switch (species) {
        case Species::CHIHUAHUA:
            displayChihuahua(emotion);
            break;
        case Species::WELSH_CORGI:
            displayWelshCorgi(emotion);
            break;
        case Species::GOLDEN_RETRIEVER:
            displayGoldenRetriever(emotion);
            break;
        case Species::HUSKY:
            displayHusky(emotion);
            break;
        case Species::RABBIT:
            displayRabbit(emotion);
            break;
        case Species::CAT:
            displayCat(emotion);
            break;
        case Species::MALTESE:
            displayMaltese(emotion);
            break;
        case Species::BICHON_FRISE:
            displayBichonFrise(emotion);
            break;
        case Species::BULLDOG:
            displayBulldog(emotion);
            break;
        case Species::HUMAN_LIKI:
            displayHumanLiki(emotion);
            break;
        case Species::HUMAN_BABO:
            displayHumanBabo(emotion);
            break;
        case Species::MYSTICAL_CAT:
            displayMysticalCat(emotion);
            break;
        default:
            displayDefault(emotion);
            break;
    }
    std::cout << "-----------------------------------" << std::endl;
}

// 메시지와 함께 표시
void Character::displayWithMessage(Emotion emotion, const std::string& message) const {
    display(emotion);
    std::cout << "[" << name << "]: " << message << std::endl;
}

// 감정을 문자열로 변환
std::string Character::getEmotionString(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY: return "happy";
        case Emotion::SAD: return "sad";
        case Emotion::THINKING: return "thinking";
        case Emotion::SURPRISED: return "surprised";
        case Emotion::ANGRY: return "angry";
        case Emotion::EXPLAIN: return "explain";
        case Emotion::QUIZ: return "quiz";
        case Emotion::JUDGE: return "judge";
        case Emotion::CORRECT: return "correct";
        case Emotion::WRONG: return "wrong";
        default: return "default";
    }
}

void Character::showProfile() const {
    std::cout << "=== " << name << "의 프로필 ===" << std::endl;
    std::cout << "종족: " << getSpeciesString() << std::endl;
    std::cout << "역할: " << role << std::endl;
    std::cout << "레벨: " << level << std::endl;
    std::cout << "경험치: " << experience << "/" << maxExperience << std::endl;
    std::cout << "나이: " << age << "세" << std::endl;
    std::cout << "자산: " << assets << "원" << std::endl;
    std::cout << "고향: " << hometown << std::endl;
    std::cout << "성별: " << gender << std::endl;
    std::cout << "사회적 지위: " << social_status << std::endl;
    std::cout << "이상형: " << ideal_type << std::endl;
    std::cout << "미래 희망: " << future_hope << std::endl;
    std::cout << "약점: " << weakness << std::endl;
    std::cout << "체력: " << hp << std::endl;
    std::cout << "공격력: " << power << std::endl;
    std::cout << "========================" << std::endl;
}

// 종별 상세 ASCII 아트 출력 함수들
void Character::displayChihuahua(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (o.o)" << std::endl;
            std::cout << " / > o  \"히히! 정말 좋아! 간식 줄래?\"" << std::endl;
            break;
        case Emotion::SAD:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (T_T)" << std::endl;
            std::cout << " / > ;  \"너무 슬퍼... 누가 나 좀 안아줘...\"" << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << " (\\o_o/)" << std::endl;
            std::cout << " ( O_O )" << std::endl;
            std::cout << " / > !  \"깜짝이야! 간식이 어디서 나타났지!?\"" << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (._.?)" << std::endl;
            std::cout << " / > ?  \"음... 뭘까? 간식에 대한 고찰...\"" << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << " (>_<)" << std::endl;
            std::cout << " (o`_`o)" << std::endl;
            std::cout << " / > #  \"내 간식 건드리지 마! 물어버릴 거야!\"" << std::endl;
            break;
        default:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (*.*)" << std::endl;
            std::cout << " / >   " << std::endl;
            break;
    }
}

void Character::displayWelshCorgi(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << " (o.o)" << std::endl;
            std::cout << " /-----\\" << std::endl;
            std::cout << "  |   |   \"기분 최고야! 콩콩! 산책 가자!\"" << std::endl;
            break;
        case Emotion::SAD:
            std::cout << " (T.T)" << std::endl;
            std::cout << " /-----\\" << std::endl;
            std::cout << "  |   |   \"산책... 못 가서 슬퍼...\"" << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << " (O.O)" << std::endl;
            std::cout << " /!---!\\" << std::endl;
            std::cout << "  |   |   \"헉! 내 빵!\"" << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << " (._.?)" << std::endl;
            std::cout << " /-----\\" << std::endl;
            std::cout << "  |   |   \"정답이 뭐더라...\"" << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << " (`_`)" << std::endl;
            std::cout << " /--#--\\" << std::endl;
            std::cout << "  |   |   \"내 방석 누가 가져갔어!\"" << std::endl;
            break;
        default:
            std::cout << " (o.o)" << std::endl;
            std::cout << " /-----\\" << std::endl;
            std::cout << "  |   | " << std::endl;
            break;
    }
}

void Character::displayHusky(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << "  /^ ^\\" << std::endl;
            std::cout << " ( >_< )" << std::endl;
            std::cout << "  |U U|  \"가자! 모험의 시간이다!\"" << std::endl;
            break;
        case Emotion::SAD:
            std::cout << "  /^ ^\\" << std::endl;
            std::cout << " ( ._. )" << std::endl;
            std::cout << "  |...|  \"혼자는 외로워...\"" << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << "  /^o^\\" << std::endl;
            std::cout << " ( O_O )" << std::endl;
            std::cout << "  |! !|  \"저건... 곰인가!?\"" << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << "  /^ ?^\\" << std::endl;
            std::cout << " ( -_- )" << std::endl;
            std::cout << "  |U U|  \"음, 논리적으로 생각해보자.\"" << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << "  /^ ^\\" << std::endl;
            std::cout << " ( >A< )" << std::endl;
            std::cout << "  |# #|  \"누가 내 밥그릇에 손댔어!\"" << std::endl;
            break;
        default:
            std::cout << "  /^ ^\\" << std::endl;
            std::cout << " ( * * )" << std::endl;
            std::cout << "  |U U| " << std::endl;
            break;
    }
}

void Character::displayRabbit(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << " (\\(\\ " << std::endl;
            std::cout << " (^_^) " << std::endl;
            std::cout << " o( )o  \"당근! 맛있어!\"" << std::endl;
            break;
        default:
            std::cout << " (\\(\\ " << std::endl;
            std::cout << " (T_T)" << std::endl;
            std::cout << " o( )o  \"힝... 어려워...\"" << std::endl;
            break;
    }
}

void Character::displayCat(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << " /\\_/\\ " << std::endl;
            std::cout << " (^_^) " << std::endl;
            std::cout << " (   )  \"나름 재미있네옹~\"" << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << " /\\_/\\ " << std::endl;
            std::cout << " (-_-) " << std::endl;
            std::cout << " (   )  \"흥, 시시하다냥.\"" << std::endl;
            break;
        default:
            std::cout << " /\\_/\\ " << std::endl;
            std::cout << " (*_*) " << std::endl;
            std::cout << " (   ) " << std::endl;
            break;
    }
}

void Character::displayMaltese(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << " (\\_/) " << std::endl;
            std::cout << " (^_^)" << std::endl;
            std::cout << "  o o   \"고구마라니! 심장이 뛴다!\"" << std::endl;
            break;
        case Emotion::SAD:
            std::cout << " (\\_/) " << std::endl;
            std::cout << " (T_T)" << std::endl;
            std::cout << "  o o   \"사료는 싫단 말이야...\"" << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << " (\\_O/) " << std::endl;
            std::cout << " (O.O)" << std::endl;
            std::cout << "  o o   \"앗! 간식 소리!\"" << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (._.?)" << std::endl;
            std::cout << "  o o   \"흠... 이 시간에 누가 왔지?\"" << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << " (\\_/) " << std::endl;
            std::cout << " (>_<)" << std::endl;
            std::cout << "  o o   \"내 잠 방해하지 마!\"" << std::endl;
            break;
        default:
            std::cout << " (\\_/) " << std::endl;
            std::cout << " (._.)" << std::endl;
            std::cout << "  o o " << std::endl;
            break;
    }
}

void Character::displayBichonFrise(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (^_^)" << std::endl;
            std::cout << " / >   \"안녕하세요! 귀여운 비숑이에요!\"" << std::endl;
            break;
        case Emotion::SAD:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (T_T)" << std::endl;
            std::cout << " / >   \"미용이 필요해요...\"" << std::endl;
            break;
        default:
            std::cout << " (\\_/)" << std::endl;
            std::cout << " (*.*)" << std::endl;
            std::cout << " / >   " << std::endl;
            break;
    }
}

void Character::displayBulldog(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << "  (o_o)" << std::endl;
            std::cout << " /-----\\" << std::endl;
            std::cout << "  |   |   \"힘세고 강한 불독이에요!\"" << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << "  (>_<)" << std::endl;
            std::cout << " /--#--\\" << std::endl;
            std::cout << "  |   |   \"누가 내 영역을 침범했어!\"" << std::endl;
            break;
        default:
            std::cout << "  (o_o)" << std::endl;
            std::cout << " /-----\\" << std::endl;
            std::cout << "  |   | " << std::endl;
            break;
    }
}

void Character::displayHumanLiki(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << "  (^_^)  \"와! 이해했어요!\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
        case Emotion::SAD:
            std::cout << "  (T_T)  \"이게 아닌데...\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << "  (O_O)  \"헉! 이렇게 되는 거였어요?\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << "  (._.)  \"음... 뭐가 문제지...?\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << "  (>_<)  \"아, 왜 안 되는 거야!\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
        default:
            std::cout << "  (*_*)  \"리키입니다!\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
    }
}

void Character::displayHumanBabo(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << "  (^_^)  \"바보입니다! 하하!\"" << std::endl;
            std::cout << "   / \\   " << std::endl;
            break;
        case Emotion::SAD:
            std::cout << "  (T_T)  \"바보라서 슬퍼요...\"" << std::endl;
            std::cout << "   / \\   " << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << "  (O_O)  \"바보라서 놀랐어요!\"" << std::endl;
            std::cout << "   / \\   " << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << "  (._.?)  \"바보라서 생각해요...\"" << std::endl;
            std::cout << "   / \\   " << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << "  (>_<)  \"이거 아니면 안 돼! 난 천재인데!\"" << std::endl;
            std::cout << "  /| |\\ " << std::endl;
            break;
        default:
            std::cout << "  (^o^)  \"바보입니다! 하하!\"" << std::endl;
            std::cout << "   / \\   " << std::endl;
            break;
    }
}

void Character::displayMysticalCat(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " ( o_o ) \"흐음, 제법이군. 야옹~\"" << std::endl;
            std::cout << " ( ~~~ )  " << std::endl;
            break;
        case Emotion::SAD:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " ( ._. ) \"기대에 미치지 못하는구나... 냐아...\"" << std::endl;
            std::cout << " ( ~~~ )  " << std::endl;
            break;
        case Emotion::SURPRISED:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " ( O_O ) \"놀랍군! 예상을 뛰어넘는 답이다! 갸릉~\"" << std::endl;
            std::cout << " ( ~~~ )  " << std::endl;
            break;
        case Emotion::THINKING:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " ( -_- ) \"깊이 생각해보아라... 진정한 지혜란 무엇인가...\"" << std::endl;
            std::cout << " ( ~~~ )  " << std::endl;
            break;
        case Emotion::ANGRY:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " ( >A< ) \"어리석은 대답이로다! 감히 나의 지혜에 도전하느냐!\"" << std::endl;
            std::cout << " ( ~~~ )  " << std::endl;
            break;
        default:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " ( ^_~ ) " << std::endl;
            std::cout << " ( ~~~ )  " << std::endl;
            break;
    }
}

void Character::displayGoldenRetriever(Emotion emotion) const {
    switch (emotion) {
        case Emotion::HAPPY:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " (^_^)  \"친구가 되어요! 공놀이 할까요?\"" << std::endl;
            std::cout << " (   )  " << std::endl;
            break;
        case Emotion::SAD:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " (T_T)  \"친구가 없어서 슬퍼요...\"" << std::endl;
            std::cout << " (   )  " << std::endl;
            break;
        default:
            std::cout << "  /\\_/\\  " << std::endl;
            std::cout << " (*_*)  " << std::endl;
            std::cout << " (   )  " << std::endl;
            break;
    }
}

void Character::displayDefault(Emotion emotion) const {
    std::cout << name << " (" << getSpeciesString() << ") " << std::endl;
    std::cout << " (\\_/) " << std::endl;
    std::cout << " ('.')" << std::endl;
    std::cout << " o(\")(\") " << std::endl;
}

// ASCII 아트 초기화 함수들 (기존 코드 유지)
void Character::initializeChihuahuaArt() {
    // 기본 초기화 - 상세 아트는 display 함수에서 처리
}

void Character::initializeWelshCorgiArt() {
    // 기본 초기화
}

void Character::initializeGoldenRetrieverArt() {
    // 기본 초기화
}

void Character::initializeHuskyArt() {
    // 기본 초기화
}

void Character::initializeRabbitArt() {
    // 기본 초기화
}

void Character::initializeCatArt() {
    // 기본 초기화
}

void Character::initializeMalteseArt() {
    // 기본 초기화
}

void Character::initializeBichonFriseArt() {
    // 기본 초기화
}

void Character::initializeBulldogArt() {
    // 기본 초기화
}

void Character::initializeHumanLikiArt() {
    // 기본 초기화
}

void Character::initializeHumanBaboArt() {
    // 기본 초기화
}

void Character::initializeMysticalCatArt() {
    // 기본 초기화
}

// CharacterManager 구현
// CharacterManager 생성자는 헤더에서 default로 선언됨

void CharacterManager::addCharacter(const Character& character) {
    characters.push_back(character);
}

Character* CharacterManager::getCharacterByName(const std::string& name) {
    for (auto& chara : characters) {
        if (chara.getName() == name) {
            return &chara;
        }
    }
    return nullptr;
}

Character* CharacterManager::getCharacterBySpecies(Species species) {
    for (auto& chara : characters) {
        if (chara.getSpecies() == species) {
            return &chara;
        }
    }
    return nullptr;
}

std::vector<Character> CharacterManager::getCharactersByRole(const std::string& role) const {
    std::vector<Character> result;
    for (const auto& chara : characters) {
        if (chara.getRole() == role) {
            result.push_back(chara);
        }
    }
    return result;
}

std::vector<Character> CharacterManager::getAllCharacters() const {
    return characters;
}

void CharacterManager::removeCharacter(const std::string& name) {
    characters.erase(
        std::remove_if(characters.begin(), characters.end(),
            [&name](const Character& chara) { return chara.getName() == name; }),
        characters.end()
    );
}

void CharacterManager::clear() {
    characters.clear();
}

size_t CharacterManager::getCharacterCount() const {
    return characters.size();
}

std::vector<Character> CharacterManager::getCharactersByHometown(const std::string& hometown) const {
    std::vector<Character> result;
    for (const auto& chara : characters) {
        if (chara.getHometown() == hometown) {
            result.push_back(chara);
        }
    }
    return result;
}

Character* CharacterManager::getStrongestCharacter() const {
    if (characters.empty()) return nullptr;
    
    const Character* strongest = &characters[0];
    for (const auto& chara : characters) {
        if (chara.getPower() > strongest->getPower()) {
            strongest = &chara;
        }
    }
    return const_cast<Character*>(strongest);
}

Character* CharacterManager::getWeakestCharacter() const {
    if (characters.empty()) return nullptr;
    
    const Character* weakest = &characters[0];
    for (const auto& chara : characters) {
        if (chara.getPower() < weakest->getPower()) {
            weakest = &chara;
        }
    }
    return const_cast<Character*>(weakest);
}

double CharacterManager::getAverageLevel() const {
    if (characters.empty()) return 0.0;
    
    double sum = 0.0;
    for (const auto& chara : characters) {
        sum += chara.getLevel();
    }
    return sum / characters.size();
}

// Character 클래스의 정적 팩토리 메서드들
Character Character::createChihuahua(const std::string& name, const std::string& role) {
    return CharacterFactory::createChihuahua(name, role);
}

Character Character::createWelshCorgi(const std::string& name, const std::string& role) {
    return CharacterFactory::createWelshCorgi(name, role);
}

Character Character::createGoldenRetriever(const std::string& name, const std::string& role) {
    return CharacterFactory::createGoldenRetriever(name, role);
}

Character Character::createHusky(const std::string& name, const std::string& role) {
    return CharacterFactory::createHusky(name, role);
}

Character Character::createRabbit(const std::string& name, const std::string& role) {
    return CharacterFactory::createRabbit(name, role);
}

Character Character::createCat(const std::string& name, const std::string& role) {
    return CharacterFactory::createCat(name, role);
}

Character Character::createMaltese(const std::string& name, const std::string& role) {
    return CharacterFactory::createMaltese(name, role);
}

Character Character::createBichonFrise(const std::string& name, const std::string& role) {
    return CharacterFactory::createBichonFrise(name, role);
}

Character Character::createBulldog(const std::string& name, const std::string& role) {
    return CharacterFactory::createBulldog(name, role);
}

Character Character::createHumanLiki(const std::string& name, const std::string& role) {
    return CharacterFactory::createHumanLiki(name, role);
}

Character Character::createHumanBabo(const std::string& name, const std::string& role) {
    return CharacterFactory::createHumanBabo(name, role);
}

Character Character::createMysticalCat(const std::string& name, const std::string& role) {
    return CharacterFactory::createMysticalCat(name, role);
}

std::vector<Character> Character::initializeCharacters() {
    return CharacterFactory::initializeAllCharacters();
}

std::vector<Character> Character::getDefaultCharacters() {
    return CharacterFactory::initializeAllCharacters();
}

std::vector<Character> Character::initializeAllCharacters() {
    return CharacterFactory::initializeAllCharacters();
}

// CharacterFactory 구현
Character CharacterFactory::createChihuahua(const std::string& name, const std::string& role) {
    Character chara(name, Species::CHIHUAHUA, role);
    chara.setAge(5);
    chara.setAssets(100);
    chara.setHometown("댕댕월드");
    chara.setGender("비밀");
    chara.setSocialStatus("모험가 지망생");
    chara.setIdealType("맛있는 거 주는 사람");
    chara.setFutureHope("세상 모든 공을 모으는 것");
    chara.setWeakness("진공청소기 소리");
    chara.setHp(80);
    chara.setPower(20);
    return chara;
}

Character CharacterFactory::createWelshCorgi(const std::string& name, const std::string& role) {
    Character chara(name, Species::WELSH_CORGI, role);
    chara.setAge(6);
    chara.setAssets(150);
    chara.setHometown("댕댕월드");
    chara.setGender("비밀");
    chara.setSocialStatus("산책 전문가");
    chara.setIdealType("함께 산책하는 사람");
    chara.setFutureHope("세상 모든 공원을 탐험하기");
    chara.setWeakness("높은 곳");
    chara.setHp(120);
    chara.setPower(30);
    return chara;
}

Character CharacterFactory::createGoldenRetriever(const std::string& name, const std::string& role) {
    Character chara(name, Species::GOLDEN_RETRIEVER, role);
    chara.setAge(7);
    chara.setAssets(200);
    chara.setHometown("댕댕월드");
    chara.setGender("비밀");
    chara.setSocialStatus("친구 만들기 전문가");
    chara.setIdealType("공놀이 하는 사람");
    chara.setFutureHope("모든 생물과 친구되기");
    chara.setWeakness("외로움");
    chara.setHp(150);
    chara.setPower(40);
    return chara;
}

Character CharacterFactory::createHusky(const std::string& name, const std::string& role) {
    Character chara(name, Species::HUSKY, role);
    chara.setAge(8);
    chara.setAssets(300);
    chara.setHometown("눈의 나라");
    chara.setGender("비밀");
    chara.setSocialStatus("모험가");
    chara.setIdealType("함께 모험하는 사람");
    chara.setFutureHope("세상 모든 산을 정복하기");
    chara.setWeakness("더위");
    chara.setHp(200);
    chara.setPower(50);
    return chara;
}

Character CharacterFactory::createRabbit(const std::string& name, const std::string& role) {
    Character chara(name, Species::RABBIT, role);
    chara.setAge(3);
    chara.setAssets(50);
    chara.setHometown("토끼굴");
    chara.setGender("비밀");
    chara.setSocialStatus("당근 수집가");
    chara.setIdealType("당근 주는 사람");
    chara.setFutureHope("세상 모든 당근을 모으기");
    chara.setWeakness("늑대");
    chara.setHp(50);
    chara.setPower(5);
    return chara;
}

Character CharacterFactory::createCat(const std::string& name, const std::string& role) {
    Character chara(name, Species::CAT, role);
    chara.setAge(4);
    chara.setAssets(80);
    chara.setHometown("고양이 마을");
    chara.setGender("비밀");
    chara.setSocialStatus("고양이");
    chara.setIdealType("간식 주는 사람");
    chara.setFutureHope("평생 따뜻한 곳에서 잠자기");
    chara.setWeakness("물");
    chara.setHp(70);
    chara.setPower(25);
    return chara;
}

Character CharacterFactory::createMaltese(const std::string& name, const std::string& role) {
    Character chara(name, Species::MALTESE, role);
    chara.setAge(13);
    chara.setAssets(500);
    chara.setHometown("댕댕월드 외곽");
    chara.setGender("암컷");
    chara.setSocialStatus("은퇴한 산책 마스터");
    chara.setIdealType("정시에 고구마를 바치는 자");
    chara.setFutureHope("평생 고구마밭에서 뒹굴기");
    chara.setWeakness("발바닥 만지기");
    chara.setHp(130);
    chara.setPower(35);
    return chara;
}

Character CharacterFactory::createBichonFrise(const std::string& name, const std::string& role) {
    Character chara(name, Species::BICHON_FRISE, role);
    chara.setAge(5);
    chara.setAssets(120);
    chara.setHometown("댕댕월드");
    chara.setGender("비밀");
    chara.setSocialStatus("미용 모델");
    chara.setIdealType("예쁘게 해주는 사람");
    chara.setFutureHope("세상에서 가장 예쁜 강아지 되기");
    chara.setWeakness("더러워지는 것");
    chara.setHp(90);
    chara.setPower(15);
    return chara;
}

Character CharacterFactory::createBulldog(const std::string& name, const std::string& role) {
    Character chara(name, Species::BULLDOG, role);
    chara.setAge(9);
    chara.setAssets(400);
    chara.setHometown("강아지 마을");
    chara.setGender("비밀");
    chara.setSocialStatus("경비원");
    chara.setIdealType("함께 지키는 사람");
    chara.setFutureHope("세상 모든 것을 지키기");
    chara.setWeakness("더위");
    chara.setHp(180);
    chara.setPower(60);
    return chara;
}

Character CharacterFactory::createHumanLiki(const std::string& name, const std::string& role) {
    Character chara(name, Species::HUMAN_LIKI, role);
    chara.setAge(10);
    chara.setAssets(500);
    chara.setHometown("서울 어딘가");
    chara.setGender("남성");
    chara.setSocialStatus("코딩 꿈나무");
    chara.setIdealType("코딩 잘 가르쳐주는 형, 누나");
    chara.setFutureHope("로봇을 만드는 프로그래머");
    chara.setWeakness("어려운 수학 문제");
    chara.setHp(10);
    chara.setPower(1);
    return chara;
}

Character CharacterFactory::createHumanBabo(const std::string& name, const std::string& role) {
    Character chara(name, Species::HUMAN_BABO, role);
    chara.setAge(12);
    chara.setAssets(100);
    chara.setHometown("바보 마을");
    chara.setGender("남성");
    chara.setSocialStatus("바보");
    chara.setIdealType("바보를 이해하는 사람");
    chara.setFutureHope("세상에서 가장 유명한 바보 되기");
    chara.setWeakness("복잡한 생각");
    chara.setHp(10);
    chara.setPower(2);
    return chara;
}

Character CharacterFactory::createMysticalCat(const std::string& name, const std::string& role) {
    Character chara(name, Species::MYSTICAL_CAT, role);
    chara.setAge(1000);
    chara.setAssets(10000);
    chara.setHometown("신비의 숲");
    chara.setGender("비밀");
    chara.setSocialStatus("지식의 수호자");
    chara.setIdealType("지혜를 추구하는 자");
    chara.setFutureHope("세상 모든 지혜를 모으기");
    chara.setWeakness("어리석은 질문");
    chara.setHp(120);
    chara.setPower(100);
    return chara;
}

std::vector<Character> CharacterFactory::initializeAllCharacters() {
    std::vector<Character> characters;
    
    characters.push_back(createChihuahua("치치", "선생님"));
    characters.push_back(createWelshCorgi("코코", "도우미"));
    characters.push_back(createGoldenRetriever("리버", "친구"));
    characters.push_back(createHusky("허허", "모험가"));
    characters.push_back(createRabbit("토토", "학생"));
    characters.push_back(createCat("냥냥", "고양이"));
    characters.push_back(createMaltese("보리", "주인공"));
    characters.push_back(createBichonFrise("숑숑", "미용사"));
    characters.push_back(createBulldog("불리", "경비원"));
    characters.push_back(createHumanLiki("리키", "학생"));
    characters.push_back(createHumanBabo("바보", "바보"));
    characters.push_back(createMysticalCat("먀엉", "지혜의 수호자"));
    
    return characters;
}

// 성격 시스템 메서드 구현
void Character::setPersonalityTrait(const std::string& trait, int value) {
    personalityTraits[trait] = value;
}

void Character::setPersonalityTrait(PersonalityTrait trait, int value) {
    std::string traitName;
    switch (trait) {
        case PersonalityTrait::FRIENDLINESS: traitName = "친근함"; break;
        case PersonalityTrait::KNOWLEDGE: traitName = "지식"; break;
        case PersonalityTrait::PATIENCE: traitName = "인내심"; break;
        case PersonalityTrait::CREATIVITY: traitName = "창의성"; break;
        case PersonalityTrait::LEADERSHIP: traitName = "리더십"; break;
        case PersonalityTrait::HUMOR: traitName = "유머감각"; break;
        case PersonalityTrait::COURAGE: traitName = "용기"; break;
        case PersonalityTrait::WISDOM: traitName = "지혜"; break;
    }
    personalityTraits[traitName] = value;
}

int Character::getPersonalityTrait(const std::string& trait) const {
    auto it = personalityTraits.find(trait);
    return (it != personalityTraits.end()) ? it->second : 5; // 기본값 5
}

int Character::getPersonalityTrait(PersonalityTrait trait) const {
    std::string traitName;
    switch (trait) {
        case PersonalityTrait::FRIENDLINESS: traitName = "친근함"; break;
        case PersonalityTrait::KNOWLEDGE: traitName = "지식"; break;
        case PersonalityTrait::PATIENCE: traitName = "인내심"; break;
        case PersonalityTrait::CREATIVITY: traitName = "창의성"; break;
        case PersonalityTrait::LEADERSHIP: traitName = "리더십"; break;
        case PersonalityTrait::HUMOR: traitName = "유머감각"; break;
        case PersonalityTrait::COURAGE: traitName = "용기"; break;
        case PersonalityTrait::WISDOM: traitName = "지혜"; break;
    }
    return getPersonalityTrait(traitName);
}

std::string Character::getSituationalResponse(const std::string& situation, const std::string& context) const {
    if (situation == "QUIZ") {
        if (context == "CORRECT") {
            return "정답입니다! 정말 잘했어요! 🎉";
        } else if (context == "WRONG") {
            return "틀렸어요. 힌트를 드릴게요! 💡";
        }
    }
    return "흥미로운 상황이네요! 🤔";
}

std::string Character::startConversation(const std::string& target) const {
    return "안녕하세요 " + target + "님! 반갑습니다! 😊";
}

std::string Character::respondToMessage(const std::string& message) const {
    if (message.find("안녕") != std::string::npos) {
        return "안녕하세요! 정말 반갑습니다! 🌟";
    }
    return "흥미로운 말씀이네요! 🤗";
}

std::string Character::getPersonalityBasedAction(const std::string& action) const {
    if (action == "GREETING") {
        int friendliness = getPersonalityTrait("친근함");
        if (friendliness >= 8) {
            return "반갑습니다! 정말 기뻐요! 🎉";
        } else if (friendliness >= 5) {
            return "안녕하세요! 😊";
        } else {
            return "안녕... 😶";
        }
    }
    return "무슨 일이신가요? 🤔";
}

std::string Character::getPersonalityBasedAction(SituationType action) const {
    switch (action) {
        case SituationType::GREETING:
            return getPersonalityBasedAction("GREETING");
        case SituationType::LEARNING:
            return getPersonalityBasedAction("LEARNING");
        case SituationType::ENCOURAGEMENT:
            return getPersonalityBasedAction("ENCOURAGEMENT");
        default:
            return "무슨 일이신가요? 🤔";
    }
}

std::string Character::getSituationalResponse(SituationType situation, const std::string& context) const {
    switch (situation) {
        case SituationType::QUIZ:
            if (context == "CORRECT") {
                return "정답입니다! 정말 잘했어요! 🎉";
            } else if (context == "WRONG") {
                return "틀렸어요. 힌트를 드릴게요! 💡";
            }
            break;
        case SituationType::SUCCESS:
            return "축하합니다! 정말 대단해요! 🎊";
        case SituationType::FAILURE:
            return "괜찮아요. 다음에는 성공할 거예요! 💪";
        case SituationType::ENCOURAGEMENT:
            return "힘내세요! 당신은 할 수 있어요! 🌟";
    }
    return "흥미로운 상황이네요! 🤔";
}

std::string Character::getPersonalitySummary() const {
    if (personalityTraits.empty()) {
        return "아직 성격 특성이 설정되지 않았습니다.";
    }
    
    std::string summary = "성격 특성 요약:\n";
    for (const auto& trait : personalityTraits) {
        summary += "  " + trait.first + ": " + std::to_string(trait.second) + "/10\n";
    }
    return summary;
}

double Character::getPersonalityAverage() const {
    if (personalityTraits.empty()) {
        return 5.0; // 기본값
    }
    
    double sum = 0.0;
    for (const auto& trait : personalityTraits) {
        sum += trait.second;
    }
    return sum / personalityTraits.size();
}

std::string Character::getDominantTrait() const {
    if (personalityTraits.empty()) {
        return "없음";
    }
    
    std::string dominantTrait;
    int maxValue = -1;
    
    for (const auto& trait : personalityTraits) {
        if (trait.second > maxValue) {
            maxValue = trait.second;
            dominantTrait = trait.first;
        }
    }
    
    return dominantTrait;
}

// 미션 클래스 구현
Mission::Mission(const std::string& t, const std::string& desc, int r, 
                 MissionDifficulty diff, const std::string& creator)
    : title(t), description(desc), reward(r), status(MissionStatus::NOT_STARTED), 
      progress(0), difficulty(diff), createdBy(creator) {
}

void Mission::start() {
    status = MissionStatus::IN_PROGRESS;
    progress = 0;
}

void Mission::updateProgress(int newProgress) {
    if (status == MissionStatus::IN_PROGRESS) {
        progress = std::min(100, std::max(0, newProgress));
        if (progress >= 100) {
            complete();
        }
    }
}

void Mission::complete() {
    status = MissionStatus::COMPLETED;
    progress = 100;
}

void Mission::fail() {
    status = MissionStatus::FAILED;
}

void Mission::giveReward(Character& character) {
    if (status == MissionStatus::COMPLETED) {
        character.gainExperience(reward);
    }
}

std::string Mission::getStatusString() const {
    switch (status) {
        case MissionStatus::NOT_STARTED: return "시작 전";
        case MissionStatus::IN_PROGRESS: return "진행 중";
        case MissionStatus::COMPLETED: return "완료";
        case MissionStatus::FAILED: return "실패";
        default: return "알 수 없음";
    }
}

std::string Mission::getDifficultyString() const {
    switch (difficulty) {
        case MissionDifficulty::EASY: return "쉬움";
        case MissionDifficulty::NORMAL: return "보통";
        case MissionDifficulty::HARD: return "어려움";
        case MissionDifficulty::EXPERT: return "전문가";
        default: return "알 수 없음";
    }
}

void Mission::display() const {
    std::cout << "=== " << title << " ===" << std::endl;
    std::cout << "설명: " << description << std::endl;
    std::cout << "보상: " << reward << " 경험치" << std::endl;
    std::cout << "상태: " << getStatusString() << std::endl;
    std::cout << "진행률: " << progress << "%" << std::endl;
    std::cout << "난이도: " << getDifficultyString() << std::endl;
    if (!createdBy.empty()) {
        std::cout << "생성자: " << createdBy << std::endl;
    }
    std::cout << "==================" << std::endl;
}

// Character 클래스의 미션 시스템 메서드 구현
Mission Character::createMission(const std::string& title, const std::string& description, 
                                int reward, MissionDifficulty difficulty) const {
    return Mission(title, description, reward, difficulty, name);
}

void Character::addMission(const Mission& mission) {
    missions.push_back(mission);
}

Mission* Character::getMission(const std::string& title) {
    for (auto& mission : missions) {
        if (mission.getTitle() == title) {
            return &mission;
        }
    }
    return nullptr;
}

int Character::getMissionCount() const {
    return missions.size();
}

std::vector<Mission> Character::getAllMissions() const {
    return missions;
}

void Character::removeMission(const std::string& title) {
    missions.erase(
        std::remove_if(missions.begin(), missions.end(),
            [&title](const Mission& mission) {
                return mission.getTitle() == title;
            }),
        missions.end()
    );
}

void Character::clearMissions() {
    missions.clear();
}

} // namespace learning 