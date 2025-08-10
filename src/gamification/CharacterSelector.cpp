#include "CharacterSelector.h"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>

namespace learning {
namespace gamification {

// CharacterDialogueSystem 구현
CharacterDialogueSystem::CharacterDialogueSystem() {
    initializeChihuahuaDialogues();
    initializeWelshCorgiDialogues();
    initializeGoldenRetrieverDialogues();
    initializeHuskyDialogues();
    initializeRabbitDialogues();
    initializeCatDialogues();
    initializeMalteseDialogues();
    initializeBichonFriseDialogues();
    initializeBulldogDialogues();
    initializeHumanLikiDialogues();
    initializeHumanBaboDialogues();
    initializeMysticalCatDialogues();
}

void CharacterDialogueSystem::initializeChihuahuaDialogues() {
    // 상황별 대화 초기화
    situationDialogues[Species::CHIHUAHUA][SituationType::LEARNING] = {
        "와우! 새로운 것을 배우는 건 정말 재미있어요! 🐕",
        "열심히 공부하면 언젠가 멋진 프로그래머가 될 수 있을 거예요!",
        "어려운 부분이 있으면 언제든 도와드릴게요!"
    };
    
    situationDialogues[Species::CHIHUAHUA][SituationType::QUIZ_START] = {
        "퀴즈 시간이에요! 준비되셨나요? 💪",
        "자, 이제 실력을 보여줄 시간이에요!",
        "긴장하지 마세요. 천천히 생각해보세요!"
    };
    
    situationDialogues[Species::CHIHUAHUA][SituationType::QUIZ_SUCCESS] = {
        "축하해요! 정말 잘했어요! 🎉",
        "와! 대단해요! 이제 더 어려운 것도 도전해보세요!",
        "정말 똑똑하시네요! 자랑스러워요!"
    };
    
    situationDialogues[Species::CHIHUAHUA][SituationType::QUIZ_FAILURE] = {
        "괜찮아요! 실패는 성공의 어머니예요! 💪",
        "다시 한번 도전해보세요. 이번엔 꼭 성공할 거예요!",
        "틀린 것도 배움이에요. 천천히 다시 해보세요!"
    };
    
    // 감정별 대화 초기화
    emotionDialogues[Species::CHIHUAHUA][EmotionDialogueType::HAPPY] = {
        "와아! 정말 기뻐요! 🐕✨",
        "행복해서 꼬리가 계속 흔들려요!",
        "오늘은 정말 좋은 날이에요!"
    };
    
    emotionDialogues[Species::CHIHUAHUA][EmotionDialogueType::SAD] = {
        "흐으... 기분이 안 좋아요 😢",
        "위로해주시면 기분이 나아질 것 같아요",
        "슬픈 일이 있으셨나요? 함께 있어드릴게요"
    };
    
    emotionDialogues[Species::CHIHUAHUA][EmotionDialogueType::THINKING] = {
        "흠... 이 문제를 어떻게 풀까요? 🤔",
        "깊이 생각해보면 답이 보일 거예요",
        "천천히 차근차근 생각해보세요"
    };
}

void CharacterDialogueSystem::initializeWelshCorgiDialogues() {
    // 웰시코기 전용 대화들
    situationDialogues[Species::WELSH_CORGI][SituationType::LEARNING] = {
        "코기 선생님이 도와드릴게요! 🐕",
        "짧은 다리지만 열심히 가르쳐드릴게요!",
        "귀여운 코기와 함께 배워보세요!"
    };
    
    emotionDialogues[Species::WELSH_CORGI][EmotionDialogueType::HAPPY] = {
        "코기 코기! 기뻐요! 🐕",
        "귀여운 웃음이 나와요!",
        "행복해서 꼬리가 빙글빙글!"
    };
}

void CharacterDialogueSystem::initializeGoldenRetrieverDialogues() {
    // 골든리트리버 전용 대화들
    situationDialogues[Species::GOLDEN_RETRIEVER][SituationType::ENCOURAGEMENT] = {
        "힘내세요! 당신은 할 수 있어요! 🐕",
        "포기하지 마세요! 함께 가요!",
        "믿어요! 정말 잘하고 있어요!"
    };
    
    emotionDialogues[Species::GOLDEN_RETRIEVER][EmotionDialogueType::DETERMINED] = {
        "의지가 불타고 있어요! 🔥",
        "목표를 향해 달려가요!",
        "절대 포기하지 않을 거예요!"
    };
}

void CharacterDialogueSystem::initializeHuskyDialogues() {
    // 허스키 전용 대화들
    situationDialogues[Species::HUSKY][SituationType::LEARNING] = {
        "모험을 떠나볼까요? 🐺",
        "새로운 도전을 해보세요!",
        "허스키와 함께 탐험해요!"
    };
    
    situationDialogues[Species::HUSKY][SituationType::ENCOURAGEMENT] = {
        "아우우! 힘내세요! 🐺",
        "허스키의 용기로 도와드릴게요!",
        "절대 포기하지 마세요!"
    };
    
    emotionDialogues[Species::HUSKY][EmotionDialogueType::EXCITED] = {
        "아우우! 흥분돼요! 🐺",
        "에너지가 넘쳐요!",
        "뛰어다니고 싶어요!"
    };
}

void CharacterDialogueSystem::initializeRabbitDialogues() {
    // 토끼 전용 대화들
    situationDialogues[Species::RABBIT][SituationType::LEARNING] = {
        "토끼와 함께 퀴즈를 풀어요! 🐰",
        "깡충깡충 뛰면서 문제를 풀어요!",
        "귀여운 토끼가 도와드릴게요!"
    };
    
    situationDialogues[Species::RABBIT][SituationType::QUIZ_START] = {
        "깡충깡충! 퀴즈 시작이에요! 🐰",
        "토끼처럼 빠르게 답해보세요!",
        "귀여운 토끼가 응원할게요!"
    };
    
    emotionDialogues[Species::RABBIT][EmotionDialogueType::SHY] = {
        "으으... 수줍어요... 🐰",
        "부끄러워서 얼굴이 빨개져요",
        "조용히 있어야겠어요..."
    };
    
    emotionDialogues[Species::RABBIT][EmotionDialogueType::HAPPY] = {
        "깡충깡충! 기뻐요! 🐰",
        "행복해서 뛰어다니고 싶어요!",
        "오늘은 정말 좋은 날이에요!"
    };
}

void CharacterDialogueSystem::initializeCatDialogues() {
    // 고양이 전용 대화들
    situationDialogues[Species::CAT][SituationType::LEARNING] = {
        "냥냥이와 함께 배워요! 🐱",
        "고양이의 지혜로 가르쳐드릴게요!",
        "집중해서 들어보세요!"
    };
    
    situationDialogues[Species::CAT][SituationType::QUIZ_START] = {
        "냥냥이의 엄격한 채점이에요! 🐱",
        "정확하게 채점해드릴게요!",
        "고양이의 날카로운 눈으로 확인해요!"
    };
    
    emotionDialogues[Species::CAT][EmotionDialogueType::PROUD] = {
        "흥! 잘했네요! 🐱",
        "고양이도 인정할 정도로 뛰어나요!",
        "정말 대단해요!"
    };
    
    emotionDialogues[Species::CAT][EmotionDialogueType::THINKING] = {
        "흠... 깊이 생각해보세요 🐱",
        "고양이처럼 천천히 생각해요",
        "답은 어딘가에 있어요..."
    };
}

void CharacterDialogueSystem::initializeMalteseDialogues() {
    // 말티즈 전용 대화들
    situationDialogues[Species::MALTESE][SituationType::LEARNING] = {
        "보리예요! 환영합니다! 🐕",
        "귀여운 말티즈와 함께해요!",
        "언제든 도와드릴게요!"
    };
    
    situationDialogues[Species::MALTESE][SituationType::WELCOME] = {
        "보리예요! 새로운 친구를 만나봐요! 🐕",
        "말티즈의 따뜻한 환영이에요!",
        "편하게 있어요!"
    };
    
    emotionDialogues[Species::MALTESE][EmotionDialogueType::PLAYFUL] = {
        "놀아요! 놀아요! 🐕",
        "장난기 가득한 말티즈예요!",
        "즐거운 시간을 보내요!"
    };
    
    emotionDialogues[Species::MALTESE][EmotionDialogueType::HAPPY] = {
        "와아! 정말 기뻐요! 🐕",
        "행복해서 꼬리가 빙글빙글!",
        "오늘은 정말 좋은 날이에요!"
    };
}

void CharacterDialogueSystem::initializeBichonFriseDialogues() {
    // 비숑 프리제 전용 대화들
    situationDialogues[Species::BICHON_FRISE][SituationType::LEARNING] = {
        "예쁘게 가르쳐드릴게요! 🐕",
        "아름다운 코드를 만들어요!",
        "비숑처럼 깔끔하게 정리해요!"
    };
    
    situationDialogues[Species::BICHON_FRISE][SituationType::BEAUTY] = {
        "아름다운 코드를 만들어요! 🐕",
        "깔끔하고 예쁘게 정리해요!",
        "비숑의 미적 감각으로 도와드릴게요!"
    };
    
    emotionDialogues[Species::BICHON_FRISE][EmotionDialogueType::CALM] = {
        "차분하게 생각해보세요 🐕",
        "평온한 마음으로 접근해요",
        "천천히, 차근차근..."
    };
    
    emotionDialogues[Species::BICHON_FRISE][EmotionDialogueType::FOCUSED] = {
        "집중해서 생각해보세요 🐕",
        "비숑처럼 차분하게 접근해요",
        "답을 찾을 수 있을 거예요!"
    };
}

void CharacterDialogueSystem::initializeBulldogDialogues() {
    // 불독 전용 대화들
    situationDialogues[Species::BULLDOG][SituationType::PROTECTION] = {
        "불독이 지켜드릴게요! 🐕",
        "어려운 문제도 물어뜯어버려요!",
        "강한 의지로 도와드려요!"
    };
    
    emotionDialogues[Species::BULLDOG][EmotionDialogueType::DETERMINED] = {
        "절대 포기하지 않아요! 🐕",
        "의지가 불타고 있어요!",
        "목표를 향해 달려가요!"
    };
}

void CharacterDialogueSystem::initializeHumanLikiDialogues() {
    // 임정찬 전용 대화들
    situationDialogues[Species::HUMAN_LIKI][SituationType::STUDENT] = {
        "안녕하세요! 학생입니다! 👨‍🎓",
        "함께 공부해요!",
        "어려운 부분이 있으면 도와드릴게요!"
    };
    
    emotionDialogues[Species::HUMAN_LIKI][EmotionDialogueType::CURIOUS] = {
        "이게 어떻게 작동하는지 궁금해요! 🤔",
        "더 자세히 알고 싶어요!",
        "호기심이 가득해요!"
    };
}

void CharacterDialogueSystem::initializeHumanBaboDialogues() {
    // 정규호 전용 대화들
    situationDialogues[Species::HUMAN_BABO][SituationType::ENTERTAINMENT] = {
        "바보가 왔어요! 😄",
        "즐거운 분위기로 만들어요!",
        "웃음이 가득한 학습 시간!"
    };
    
    emotionDialogues[Species::HUMAN_BABO][EmotionDialogueType::PLAYFUL] = {
        "장난기 가득한 바보예요! 😄",
        "즐거운 시간을 보내요!",
        "웃음이 나와요!"
    };
}

void CharacterDialogueSystem::initializeMysticalCatDialogues() {
    // 싀백 전용 대화들
    situationDialogues[Species::MYSTICAL_CAT][SituationType::WISDOM] = {
        "먀엉... 지혜를 나누어드릴게요... 🐱",
        "신비로운 고양이의 가르침이에요...",
        "깊은 생각으로 접근해보세요..."
    };
    
    emotionDialogues[Species::MYSTICAL_CAT][EmotionDialogueType::MYSTERIOUS] = {
        "먀엉... 신비로운 기운이 느껴져요... 🐱",
        "깊은 생각에 잠겨있어요...",
        "현자의 지혜가 깃들어 있어요..."
    };
}

std::string CharacterDialogueSystem::getSituationDialogue(Species species, SituationType situation) {
    auto speciesIt = situationDialogues.find(species);
    if (speciesIt == situationDialogues.end()) {
        return "안녕하세요!";
    }
    
    auto situationIt = speciesIt->second.find(situation);
    if (situationIt == speciesIt->second.end() || situationIt->second.empty()) {
        return "상황에 맞는 대화가 없어요.";
    }
    
    return situationIt->second[0];
}

std::string CharacterDialogueSystem::getRandomSituationDialogue(Species species, SituationType situation) {
    auto speciesIt = situationDialogues.find(species);
    if (speciesIt == situationDialogues.end()) {
        return "안녕하세요!";
    }
    
    auto situationIt = speciesIt->second.find(situation);
    if (situationIt == speciesIt->second.end() || situationIt->second.empty()) {
        return "상황에 맞는 대화가 없어요.";
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, situationIt->second.size() - 1);
    
    return situationIt->second[dis(gen)];
}

std::string CharacterDialogueSystem::getEmotionDialogue(Species species, EmotionDialogueType emotion) {
    auto speciesIt = emotionDialogues.find(species);
    if (speciesIt == emotionDialogues.end()) {
        return "감정을 표현해요.";
    }
    
    auto emotionIt = speciesIt->second.find(emotion);
    if (emotionIt == speciesIt->second.end() || emotionIt->second.empty()) {
        return "이 감정에 맞는 대화가 없어요.";
    }
    
    return emotionIt->second[0];
}

std::string CharacterDialogueSystem::getRandomEmotionDialogue(Species species, EmotionDialogueType emotion) {
    auto speciesIt = emotionDialogues.find(species);
    if (speciesIt == emotionDialogues.end()) {
        return "감정을 표현해요.";
    }
    
    auto emotionIt = speciesIt->second.find(emotion);
    if (emotionIt == speciesIt->second.end() || emotionIt->second.empty()) {
        return "이 감정에 맞는 대화가 없어요.";
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, emotionIt->second.size() - 1);
    
    return emotionIt->second[dis(gen)];
}

std::string CharacterDialogueSystem::getCombinedDialogue(Species species, SituationType situation, EmotionDialogueType emotion) {
    std::string situationDialogue = getRandomSituationDialogue(species, situation);
    std::string emotionDialogue = getRandomEmotionDialogue(species, emotion);
    
    return situationDialogue + " " + emotionDialogue;
}

void CharacterDialogueSystem::addSituationDialogue(Species species, SituationType situation, const std::string& dialogue) {
    situationDialogues[species][situation].push_back(dialogue);
}

void CharacterDialogueSystem::addEmotionDialogue(Species species, EmotionDialogueType emotion, const std::string& dialogue) {
    emotionDialogues[species][emotion].push_back(dialogue);
}

// CharacterSelector 구현
CharacterSelector::CharacterSelector() {
    // 기본 캐릭터들 초기화
    availableCharacters = Character::initializeAllCharacters();
}

void CharacterSelector::displayAvailableCharacters() const {
    std::cout << "\n=== 사용 가능한 캐릭터 목록 ===\n";
    for (size_t i = 0; i < availableCharacters.size(); ++i) {
        const auto& character = availableCharacters[i];
        std::cout << std::setw(2) << (i + 1) << ". ";
        std::cout << std::setw(15) << character.getName() << " (";
        std::cout << character.getSpeciesString() << ") - ";
        std::cout << character.getRole() << "\n";
    }
    std::cout << "\n";
}

Character* CharacterSelector::selectCharacter() {
    displayAvailableCharacters();
    
    std::cout << "캐릭터 번호를 선택하세요 (1-" << availableCharacters.size() << "): ";
    int choice;
    std::cin >> choice;
    
    if (choice >= 1 && choice <= static_cast<int>(availableCharacters.size())) {
        return &availableCharacters[choice - 1];
    }
    
    std::cout << "잘못된 선택입니다. 기본 캐릭터를 선택합니다.\n";
    return &availableCharacters[0];
}

Character* CharacterSelector::selectCharacterByName(const std::string& name) {
    for (auto& character : availableCharacters) {
        if (character.getName() == name) {
            return &character;
        }
    }
    return nullptr;
}

Character* CharacterSelector::selectCharacterBySpecies(Species species) {
    for (auto& character : availableCharacters) {
        if (character.getSpecies() == species) {
            return &character;
        }
    }
    return nullptr;
}

void CharacterSelector::displayCharacterInfo(const Character& character) const {
    std::cout << "\n=== 캐릭터 정보 ===\n";
    std::cout << "이름: " << character.getName() << "\n";
    std::cout << "종류: " << character.getSpeciesString() << "\n";
    std::cout << "역할: " << character.getRole() << "\n";
    std::cout << "레벨: " << character.getLevel() << "\n";
    std::cout << "경험치: " << character.getExperience() << "/" << character.getMaxExperience() << "\n";
    std::cout << "HP: " << character.getHp() << "\n";
    std::cout << "파워: " << character.getPower() << "\n";
}

void CharacterSelector::displayCharacterProfile(const Character& character) const {
    std::cout << "\n=== 상세 프로필 ===\n";
    std::cout << "나이: " << character.getAge() << "세\n";
    std::cout << "자산: " << character.getAssets() << "원\n";
    std::cout << "고향: " << character.getHometown() << "\n";
    std::cout << "성별: " << character.getGender() << "\n";
    std::cout << "사회적 지위: " << character.getSocialStatus() << "\n";
    std::cout << "이상형: " << character.getIdealType() << "\n";
    std::cout << "미래 희망: " << character.getFutureHope() << "\n";
    std::cout << "약점: " << character.getWeakness() << "\n";
}

Character CharacterSelector::customizeCharacter(const Character& baseCharacter) {
    Character customized = baseCharacter;
    
    std::cout << "\n=== 캐릭터 커스터마이징 ===\n";
    
    std::string newName;
    std::cout << "새로운 이름을 입력하세요 (현재: " << customized.getName() << "): ";
    std::cin.ignore();
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        customized.setName(newName);
    }
    
    std::string newRole;
    std::cout << "새로운 역할을 입력하세요 (현재: " << customized.getRole() << "): ";
    std::getline(std::cin, newRole);
    if (!newRole.empty()) {
        customized.setRole(newRole);
    }
    
    return customized;
}

void CharacterSelector::editCharacterName(Character& character, const std::string& newName) {
    character.setName(newName);
}

void CharacterSelector::editCharacterRole(Character& character, const std::string& newRole) {
    character.setRole(newRole);
}

void CharacterSelector::editCharacterProfile(Character& character) {
    std::cout << "\n=== 프로필 편집 ===\n";
    
    int newAge;
    std::cout << "나이를 입력하세요 (현재: " << character.getAge() << "): ";
    std::cin >> newAge;
    character.setAge(newAge);
    
    std::string newHometown;
    std::cout << "고향을 입력하세요 (현재: " << character.getHometown() << "): ";
    std::cin.ignore();
    std::getline(std::cin, newHometown);
    if (!newHometown.empty()) {
        character.setHometown(newHometown);
    }
    
    std::string newGender;
    std::cout << "성별을 입력하세요 (현재: " << character.getGender() << "): ";
    std::getline(std::cin, newGender);
    if (!newGender.empty()) {
        character.setGender(newGender);
    }
}

bool CharacterSelector::saveCharacter(const Character& character, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    file << character.getName() << "\n";
    file << static_cast<int>(character.getSpecies()) << "\n";
    file << character.getRole() << "\n";
    file << character.getLevel() << "\n";
    file << character.getExperience() << "\n";
    file << character.getAge() << "\n";
    file << character.getAssets() << "\n";
    file << character.getHometown() << "\n";
    file << character.getGender() << "\n";
    file << character.getSocialStatus() << "\n";
    file << character.getIdealType() << "\n";
    file << character.getFutureHope() << "\n";
    file << character.getWeakness() << "\n";
    file << character.getHp() << "\n";
    file << character.getPower() << "\n";
    
    file.close();
    return true;
}

Character* CharacterSelector::loadCharacter(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return nullptr;
    }
    
    std::string name, role, hometown, gender, socialStatus, idealType, futureHope, weakness;
    int speciesInt, level, experience, age, hp, power;
    long long assets;
    
    file >> name >> speciesInt >> role >> level >> experience >> age >> assets;
    file.ignore();
    std::getline(file, hometown);
    std::getline(file, gender);
    std::getline(file, socialStatus);
    std::getline(file, idealType);
    std::getline(file, futureHope);
    std::getline(file, weakness);
    file >> hp >> power;
    
    file.close();
    
    Species species = static_cast<Species>(speciesInt);
    Character* character = new Character(name, species, role);
    character->setLevel(level);
    character->setExperience(experience);
    character->setAge(age);
    character->setAssets(assets);
    character->setHometown(hometown);
    character->setGender(gender);
    character->setSocialStatus(socialStatus);
    character->setIdealType(idealType);
    character->setFutureHope(futureHope);
    character->setWeakness(weakness);
    character->setHp(hp);
    character->setPower(power);
    
    return character;
}

} // namespace gamification
} // namespace learning 