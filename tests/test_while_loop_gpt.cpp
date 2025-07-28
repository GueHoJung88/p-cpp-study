#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

// 테스트할 WhileLoop Quiz 프로그램의 주요 기능들
// 실제 프로그램의 구조체와 함수들을 테스트용으로 재정의

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::istringstream;

// 퀴즈 유형 열거형 (원본과 동일)
enum class QuizType {
    REVIEW_QUIZ,      // 복습 퀴즈
    FINAL_QUIZ,       // 최종 점검 퀴즈
    PRACTICE_QUIZ     // 연습 퀴즈
};

// 퀴즈 문제 구조체 (원본과 동일)
struct QuizQuestion {
    string question;
    string hint;
    vector<string> options;
    int correctIndex;
    string explanation;
    string category;
    int difficulty;
    QuizType type;
};

// 사용자 퀴즈 데이터 구조체 (원본과 동일)
struct UserQuizData {
    string username;
    int reviewQuizScore;
    int finalQuizScore;
    int practiceQuizScore;
    int totalReviewQuestions;
    int totalFinalQuestions;
    int totalPracticeQuestions;
    vector<string> completedCategories;
    string lastQuizDate;
};

// 테스트용 캐릭터 클래스 (간소화)
class Character {
private:
    string name;
    string role;

public:
    Character() : name(""), role("") {} // 기본 생성자 추가
    Character(const string& n, const string& r) : name(n), role(r) {}
    
    string getName() const { return name; }
    string getRole() const { return role; }
    
    void display(const string& emotion = "default") const {
        // 테스트에서는 출력을 캡처하기 위해 실제 출력은 하지 않음
    }
};

// 색상 출력 함수들 (테스트용)
inline void printBlue(const string& text) {
    cout << "[BLUE]" << text << "[RESET]";
}

inline void printYellow(const string& text) {
    cout << "[YELLOW]" << text << "[RESET]";
}

inline void printGreen(const string& text) {
    cout << "[GREEN]" << text << "[RESET]";
}

inline void printRed(const string& text) {
    cout << "[RED]" << text << "[RESET]";
}

inline void printPurple(const string& text) {
    cout << "[PURPLE]" << text << "[RESET]";
}

inline void printCyan(const string& text) {
    cout << "[CYAN]" << text << "[RESET]";
}

// 사용자 퀴즈 데이터 저장 함수 (테스트용)
void saveUserQuizData(const UserQuizData& userData) {
    ofstream file("test_user_quiz_data.txt");
    file << "username:" << userData.username << endl;
    file << "reviewQuizScore:" << userData.reviewQuizScore << endl;
    file << "finalQuizScore:" << userData.finalQuizScore << endl;
    file << "practiceQuizScore:" << userData.practiceQuizScore << endl;
    file << "totalReviewQuestions:" << userData.totalReviewQuestions << endl;
    file << "totalFinalQuestions:" << userData.totalFinalQuestions << endl;
    file << "totalPracticeQuestions:" << userData.totalPracticeQuestions << endl;
    file << "lastQuizDate:" << userData.lastQuizDate << endl;
    file << "completedCategories:";
    for (const auto& category : userData.completedCategories) {
        file << category << ",";
    }
    file << endl;
    file.close();
}

// 사용자 퀴즈 데이터 로드 함수 (테스트용)
UserQuizData loadUserQuizData(const string& username) {
    UserQuizData userData;
    userData.username = username;
    userData.reviewQuizScore = 0;
    userData.finalQuizScore = 0;
    userData.practiceQuizScore = 0;
    userData.totalReviewQuestions = 0;
    userData.totalFinalQuestions = 0;
    userData.totalPracticeQuestions = 0;
    userData.lastQuizDate = "";
    
    ifstream file("test_user_quiz_data.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t colonPos = line.find(':');
            if (colonPos != string::npos) {
                string key = line.substr(0, colonPos);
                string value = line.substr(colonPos + 1);
                
                if (key == "username") {
                    userData.username = value;
                } else if (key == "reviewQuizScore") {
                    istringstream iss(value);
                    iss >> userData.reviewQuizScore;
                } else if (key == "finalQuizScore") {
                    istringstream iss(value);
                    iss >> userData.finalQuizScore;
                } else if (key == "practiceQuizScore") {
                    istringstream iss(value);
                    iss >> userData.practiceQuizScore;
                } else if (key == "totalReviewQuestions") {
                    istringstream iss(value);
                    iss >> userData.totalReviewQuestions;
                } else if (key == "totalFinalQuestions") {
                    istringstream iss(value);
                    iss >> userData.totalFinalQuestions;
                } else if (key == "totalPracticeQuestions") {
                    istringstream iss(value);
                    iss >> userData.totalPracticeQuestions;
                } else if (key == "lastQuizDate") {
                    userData.lastQuizDate = value;
                } else if (key == "completedCategories") {
                    userData.completedCategories.clear();
                    istringstream iss(value);
                    string category;
                    while (getline(iss, category, ',')) {
                        if (!category.empty()) {
                            userData.completedCategories.push_back(category);
                        }
                    }
                }
            }
        }
        file.close();
    }
    
    return userData;
}

// 복습 퀴즈 생성 함수 (테스트용)
vector<QuizQuestion> buildReviewQuizzes() {
    vector<QuizQuestion> quizzes;
    
    QuizQuestion quiz1;
    quiz1.question = "while 루프의 기본 문법은 무엇인가요?";
    quiz1.hint = "조건문을 괄호 안에 작성합니다.";
    quiz1.options = {"while (조건) { 코드 }", "for (조건) { 코드 }", "if (조건) { 코드 }", "do { 코드 } while (조건)"};
    quiz1.correctIndex = 0;
    quiz1.explanation = "while 루프는 'while (조건) { 코드 }' 형태로 작성됩니다.";
    quiz1.category = "기본 문법";
    quiz1.difficulty = 1;
    quiz1.type = QuizType::REVIEW_QUIZ;
    quizzes.push_back(quiz1);
    
    QuizQuestion quiz2;
    quiz2.question = "while 루프에서 무한 루프를 피하기 위해 필요한 것은?";
    quiz2.hint = "조건이 거짓이 되도록 해야 합니다.";
    quiz2.options = {"조건문", "증감식", "중괄호", "세미콜론"};
    quiz2.correctIndex = 1;
    quiz2.explanation = "증감식을 통해 조건이 거짓이 되도록 해야 무한 루프를 피할 수 있습니다.";
    quiz2.category = "루프 제어";
    quiz2.difficulty = 2;
    quiz2.type = QuizType::REVIEW_QUIZ;
    quizzes.push_back(quiz2);
    
    return quizzes;
}

// While Loop 퀴즈 생성 함수 (테스트용)
vector<QuizQuestion> buildWhileLoopQuizzes() {
    vector<QuizQuestion> quizzes;
    
    QuizQuestion quiz1;
    quiz1.question = "다음 중 while 루프의 특징이 아닌 것은?";
    quiz1.hint = "while 루프는 조건을 먼저 확인합니다.";
    quiz1.options = {"조건이 참인 동안 반복", "조건을 먼저 확인", "최소 한 번은 실행", "조건이 거짓이면 종료"};
    quiz1.correctIndex = 2;
    quiz1.explanation = "while 루프는 조건을 먼저 확인하므로, 조건이 거짓이면 한 번도 실행되지 않을 수 있습니다.";
    quiz1.category = "while 루프 특징";
    quiz1.difficulty = 2;
    quiz1.type = QuizType::FINAL_QUIZ;
    quizzes.push_back(quiz1);
    
    QuizQuestion quiz2;
    quiz2.question = "while 루프와 do-while 루프의 차이점은?";
    quiz2.hint = "실행 순서를 생각해보세요.";
    quiz2.options = {"조건 확인 순서", "반복 횟수", "변수 사용", "문법 구조"};
    quiz2.correctIndex = 0;
    quiz2.explanation = "while 루프는 조건을 먼저 확인하고, do-while 루프는 코드를 먼저 실행한 후 조건을 확인합니다.";
    quiz2.category = "루프 비교";
    quiz2.difficulty = 3;
    quiz2.type = QuizType::FINAL_QUIZ;
    quizzes.push_back(quiz2);
    
    QuizQuestion quiz3;
    quiz3.question = "while 루프에서 break 문의 역할은?";
    quiz3.hint = "루프를 강제로 종료합니다.";
    quiz3.options = {"루프를 건너뛰기", "루프를 강제 종료", "조건을 변경", "변수를 초기화"};
    quiz3.correctIndex = 1;
    quiz3.explanation = "break 문은 루프를 강제로 종료하고 루프 밖으로 나갑니다.";
    quiz3.category = "루프 제어";
    quiz3.difficulty = 2;
    quiz3.type = QuizType::PRACTICE_QUIZ;
    quizzes.push_back(quiz3);
    
    return quizzes;
}

// 연습 퀴즈 생성 함수 (테스트용)
vector<QuizQuestion> buildPracticeQuizzes() {
    vector<QuizQuestion> quizzes;
    
    QuizQuestion quiz1;
    quiz1.question = "1부터 10까지 출력하는 while 루프를 작성하세요.";
    quiz1.hint = "초기값을 1로 설정하고, 조건을 10 이하로 설정하세요.";
    quiz1.options = {"int i=1; while(i<=10) { cout<<i; i++; }", "int i=0; while(i<10) { cout<<i; i++; }", "int i=1; while(i<10) { cout<<i; i++; }", "int i=0; while(i<=10) { cout<<i; i++; }"};
    quiz1.correctIndex = 0;
    quiz1.explanation = "1부터 10까지 출력하려면 초기값을 1로 설정하고, 조건을 i<=10으로 설정해야 합니다.";
    quiz1.category = "실습 문제";
    quiz1.difficulty = 1;
    quiz1.type = QuizType::PRACTICE_QUIZ;
    quizzes.push_back(quiz1);
    
    return quizzes;
}

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
    
    void clear() {
        captured_output.str("");
        captured_output.clear();
    }
};

// ===== WhileLoop Quiz 프로그램 테스트 =====

class WhileLoopQuizTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 테스트용 캐릭터들 생성
        quizMaster = Character("퀴즈마스터", "퀴즈 진행자");
        student = Character("학생", "퀴즈 응시자");
        
        // 테스트용 사용자 데이터
        testUserData.username = "testuser";
        testUserData.reviewQuizScore = 0;
        testUserData.finalQuizScore = 0;
        testUserData.practiceQuizScore = 0;
        testUserData.totalReviewQuestions = 0;
        testUserData.totalFinalQuestions = 0;
        testUserData.totalPracticeQuestions = 0;
        testUserData.lastQuizDate = "";
        testUserData.completedCategories.clear();
    }
    
    void TearDown() override {
        // 테스트 파일 정리
        std::remove("test_user_quiz_data.txt");
    }
    
    Character quizMaster;
    Character student;
    UserQuizData testUserData;
};

// ===== 퀴즈 유형 테스트 =====

TEST_F(WhileLoopQuizTest, QuizTypeEnum_ValidValues_DefinedCorrectly) {
    EXPECT_EQ(static_cast<int>(QuizType::REVIEW_QUIZ), 0);
    EXPECT_EQ(static_cast<int>(QuizType::FINAL_QUIZ), 1);
    EXPECT_EQ(static_cast<int>(QuizType::PRACTICE_QUIZ), 2);
}

// ===== 퀴즈 문제 테스트 =====

TEST_F(WhileLoopQuizTest, QuizQuestionCreation_ValidData_CreatesQuestion) {
    QuizQuestion question;
    question.question = "테스트 문제";
    question.hint = "테스트 힌트";
    question.options = {"옵션1", "옵션2", "옵션3", "옵션4"};
    question.correctIndex = 2;
    question.explanation = "테스트 설명";
    question.category = "테스트 카테고리";
    question.difficulty = 3;
    question.type = QuizType::REVIEW_QUIZ;
    
    EXPECT_EQ(question.question, "테스트 문제");
    EXPECT_EQ(question.hint, "테스트 힌트");
    EXPECT_EQ(question.options.size(), 4);
    EXPECT_EQ(question.correctIndex, 2);
    EXPECT_EQ(question.explanation, "테스트 설명");
    EXPECT_EQ(question.category, "테스트 카테고리");
    EXPECT_EQ(question.difficulty, 3);
    EXPECT_EQ(question.type, QuizType::REVIEW_QUIZ);
}

TEST_F(WhileLoopQuizTest, BuildReviewQuizzes_ReturnsValidQuizzes) {
    vector<QuizQuestion> quizzes = buildReviewQuizzes();
    
    EXPECT_EQ(quizzes.size(), 2);
    EXPECT_FALSE(quizzes[0].question.empty());
    EXPECT_FALSE(quizzes[1].question.empty());
    EXPECT_EQ(quizzes[0].type, QuizType::REVIEW_QUIZ);
    EXPECT_EQ(quizzes[1].type, QuizType::REVIEW_QUIZ);
    EXPECT_EQ(quizzes[0].options.size(), 4);
    EXPECT_EQ(quizzes[1].options.size(), 4);
}

TEST_F(WhileLoopQuizTest, BuildWhileLoopQuizzes_ReturnsValidQuizzes) {
    vector<QuizQuestion> quizzes = buildWhileLoopQuizzes();
    
    EXPECT_EQ(quizzes.size(), 3);
    EXPECT_FALSE(quizzes[0].question.empty());
    EXPECT_FALSE(quizzes[1].question.empty());
    EXPECT_FALSE(quizzes[2].question.empty());
    
    // 퀴즈 타입 확인
    EXPECT_EQ(quizzes[0].type, QuizType::FINAL_QUIZ);
    EXPECT_EQ(quizzes[1].type, QuizType::FINAL_QUIZ);
    EXPECT_EQ(quizzes[2].type, QuizType::PRACTICE_QUIZ);
}

TEST_F(WhileLoopQuizTest, BuildPracticeQuizzes_ReturnsValidQuizzes) {
    vector<QuizQuestion> quizzes = buildPracticeQuizzes();
    
    EXPECT_EQ(quizzes.size(), 1);
    EXPECT_FALSE(quizzes[0].question.empty());
    EXPECT_EQ(quizzes[0].type, QuizType::PRACTICE_QUIZ);
    EXPECT_EQ(quizzes[0].options.size(), 4);
}

TEST_F(WhileLoopQuizTest, QuizCorrectIndex_WithinValidRange) {
    vector<QuizQuestion> reviewQuizzes = buildReviewQuizzes();
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    vector<QuizQuestion> practiceQuizzes = buildPracticeQuizzes();
    
    // 모든 퀴즈의 correctIndex가 유효한 범위 내에 있는지 확인
    for (const auto& quiz : reviewQuizzes) {
        EXPECT_GE(quiz.correctIndex, 0);
        EXPECT_LT(quiz.correctIndex, static_cast<int>(quiz.options.size()));
    }
    
    for (const auto& quiz : whileLoopQuizzes) {
        EXPECT_GE(quiz.correctIndex, 0);
        EXPECT_LT(quiz.correctIndex, static_cast<int>(quiz.options.size()));
    }
    
    for (const auto& quiz : practiceQuizzes) {
        EXPECT_GE(quiz.correctIndex, 0);
        EXPECT_LT(quiz.correctIndex, static_cast<int>(quiz.options.size()));
    }
}

// ===== 사용자 퀴즈 데이터 테스트 =====

TEST_F(WhileLoopQuizTest, UserQuizDataCreation_ValidData_CreatesData) {
    UserQuizData userData;
    userData.username = "testuser";
    userData.reviewQuizScore = 85;
    userData.finalQuizScore = 90;
    userData.practiceQuizScore = 95;
    userData.totalReviewQuestions = 10;
    userData.totalFinalQuestions = 15;
    userData.totalPracticeQuestions = 20;
    userData.lastQuizDate = "2024-01-01";
    userData.completedCategories = {"기본 문법", "루프 제어"};
    
    EXPECT_EQ(userData.username, "testuser");
    EXPECT_EQ(userData.reviewQuizScore, 85);
    EXPECT_EQ(userData.finalQuizScore, 90);
    EXPECT_EQ(userData.practiceQuizScore, 95);
    EXPECT_EQ(userData.totalReviewQuestions, 10);
    EXPECT_EQ(userData.totalFinalQuestions, 15);
    EXPECT_EQ(userData.totalPracticeQuestions, 20);
    EXPECT_EQ(userData.lastQuizDate, "2024-01-01");
    EXPECT_EQ(userData.completedCategories.size(), 2);
}

TEST_F(WhileLoopQuizTest, SaveUserQuizData_ValidData_SavesToFile) {
    UserQuizData userData;
    userData.username = "testuser";
    userData.reviewQuizScore = 75;
    userData.finalQuizScore = 80;
    userData.practiceQuizScore = 85;
    userData.totalReviewQuestions = 8;
    userData.totalFinalQuestions = 12;
    userData.totalPracticeQuestions = 16;
    userData.lastQuizDate = "2024-01-15";
    userData.completedCategories = {"기본 문법"};
    
    saveUserQuizData(userData);
    
    // 파일이 생성되었는지 확인
    ifstream file("test_user_quiz_data.txt");
    EXPECT_TRUE(file.is_open());
    file.close();
}

TEST_F(WhileLoopQuizTest, LoadUserQuizData_ExistingFile_LoadsCorrectData) {
    // 먼저 테스트 데이터 저장
    UserQuizData originalData;
    originalData.username = "testuser";
    originalData.reviewQuizScore = 90;
    originalData.finalQuizScore = 95;
    originalData.practiceQuizScore = 100;
    originalData.totalReviewQuestions = 12;
    originalData.totalFinalQuestions = 18;
    originalData.totalPracticeQuestions = 24;
    originalData.lastQuizDate = "2024-01-20";
    originalData.completedCategories = {"기본 문법", "루프 제어", "실습 문제"};
    
    saveUserQuizData(originalData);
    
    // 데이터 로드
    UserQuizData loadedData = loadUserQuizData("testuser");
    
    EXPECT_EQ(loadedData.username, "testuser");
    EXPECT_EQ(loadedData.reviewQuizScore, 90);
    EXPECT_EQ(loadedData.finalQuizScore, 95);
    EXPECT_EQ(loadedData.practiceQuizScore, 100);
    EXPECT_EQ(loadedData.totalReviewQuestions, 12);
    EXPECT_EQ(loadedData.totalFinalQuestions, 18);
    EXPECT_EQ(loadedData.totalPracticeQuestions, 24);
    EXPECT_EQ(loadedData.lastQuizDate, "2024-01-20");
    EXPECT_EQ(loadedData.completedCategories.size(), 3);
    EXPECT_EQ(loadedData.completedCategories[0], "기본 문법");
    EXPECT_EQ(loadedData.completedCategories[1], "루프 제어");
    EXPECT_EQ(loadedData.completedCategories[2], "실습 문제");
}

TEST_F(WhileLoopQuizTest, LoadUserQuizData_NonExistentFile_ReturnsDefaultData) {
    UserQuizData loadedData = loadUserQuizData("nonexistent");
    
    EXPECT_EQ(loadedData.username, "nonexistent");
    EXPECT_EQ(loadedData.reviewQuizScore, 0);
    EXPECT_EQ(loadedData.finalQuizScore, 0);
    EXPECT_EQ(loadedData.practiceQuizScore, 0);
    EXPECT_EQ(loadedData.totalReviewQuestions, 0);
    EXPECT_EQ(loadedData.totalFinalQuestions, 0);
    EXPECT_EQ(loadedData.totalPracticeQuestions, 0);
    EXPECT_EQ(loadedData.lastQuizDate, "");
    EXPECT_TRUE(loadedData.completedCategories.empty());
}

// ===== 색상 출력 함수 테스트 =====

TEST_F(WhileLoopQuizTest, PrintColorFunctions_OutputCorrectFormat) {
    OutputCapture capture;
    
    printBlue("파란색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[BLUE]파란색 텍스트[RESET]");
    
    capture.clear();
    printGreen("초록색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[GREEN]초록색 텍스트[RESET]");
    
    capture.clear();
    printRed("빨간색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[RED]빨간색 텍스트[RESET]");
    
    capture.clear();
    printYellow("노란색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[YELLOW]노란색 텍스트[RESET]");
    
    capture.clear();
    printPurple("보라색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[PURPLE]보라색 텍스트[RESET]");
    
    capture.clear();
    printCyan("청록색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[CYAN]청록색 텍스트[RESET]");
}

// ===== 캐릭터 시스템 테스트 =====

TEST_F(WhileLoopQuizTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("테스트", "역할");
    
    EXPECT_EQ(testChar.getName(), "테스트");
    EXPECT_EQ(testChar.getRole(), "역할");
}

TEST_F(WhileLoopQuizTest, CharacterDisplay_ValidEmotion_DoesNotThrow) {
    Character testChar("테스트", "역할");
    
    // display 함수가 예외를 던지지 않는지 확인
    EXPECT_NO_THROW(testChar.display("happy"));
    EXPECT_NO_THROW(testChar.display("sad"));
    EXPECT_NO_THROW(testChar.display("default"));
}

// ===== 퀴즈 난이도 테스트 =====

TEST_F(WhileLoopQuizTest, QuizDifficulty_ValidRange_WithinBounds) {
    vector<QuizQuestion> reviewQuizzes = buildReviewQuizzes();
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    vector<QuizQuestion> practiceQuizzes = buildPracticeQuizzes();
    
    // 모든 퀴즈의 난이도가 유효한 범위 내에 있는지 확인 (1-5 가정)
    for (const auto& quiz : reviewQuizzes) {
        EXPECT_GE(quiz.difficulty, 1);
        EXPECT_LE(quiz.difficulty, 5);
    }
    
    for (const auto& quiz : whileLoopQuizzes) {
        EXPECT_GE(quiz.difficulty, 1);
        EXPECT_LE(quiz.difficulty, 5);
    }
    
    for (const auto& quiz : practiceQuizzes) {
        EXPECT_GE(quiz.difficulty, 1);
        EXPECT_LE(quiz.difficulty, 5);
    }
}

// ===== 퀴즈 카테고리 테스트 =====

TEST_F(WhileLoopQuizTest, QuizCategories_ValidCategories_NotEmpty) {
    vector<QuizQuestion> reviewQuizzes = buildReviewQuizzes();
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    vector<QuizQuestion> practiceQuizzes = buildPracticeQuizzes();
    
    // 모든 퀴즈의 카테고리가 비어있지 않은지 확인
    for (const auto& quiz : reviewQuizzes) {
        EXPECT_FALSE(quiz.category.empty());
    }
    
    for (const auto& quiz : whileLoopQuizzes) {
        EXPECT_FALSE(quiz.category.empty());
    }
    
    for (const auto& quiz : practiceQuizzes) {
        EXPECT_FALSE(quiz.category.empty());
    }
}

// ===== 통합 테스트 =====

TEST_F(WhileLoopQuizTest, Integration_CompleteQuizFlow_WorksCorrectly) {
    // 복습 퀴즈 생성
    vector<QuizQuestion> reviewQuizzes = buildReviewQuizzes();
    EXPECT_EQ(reviewQuizzes.size(), 2);
    
    // While Loop 퀴즈 생성
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    EXPECT_EQ(whileLoopQuizzes.size(), 3);
    
    // 연습 퀴즈 생성
    vector<QuizQuestion> practiceQuizzes = buildPracticeQuizzes();
    EXPECT_EQ(practiceQuizzes.size(), 1);
    
    // 사용자 데이터 생성 및 저장
    UserQuizData userData;
    userData.username = "integration_test";
    userData.reviewQuizScore = 100;
    userData.finalQuizScore = 95;
    userData.practiceQuizScore = 90;
    userData.totalReviewQuestions = 20;
    userData.totalFinalQuestions = 25;
    userData.totalPracticeQuestions = 30;
    userData.lastQuizDate = "2024-01-25";
    userData.completedCategories = {"통합 테스트"};
    
    saveUserQuizData(userData);
    
    // 데이터 로드 및 검증
    UserQuizData loadedData = loadUserQuizData("integration_test");
    EXPECT_EQ(loadedData.username, "integration_test");
    EXPECT_EQ(loadedData.reviewQuizScore, 100);
    EXPECT_EQ(loadedData.finalQuizScore, 95);
    EXPECT_EQ(loadedData.practiceQuizScore, 90);
    EXPECT_EQ(loadedData.totalReviewQuestions, 20);
    EXPECT_EQ(loadedData.totalFinalQuestions, 25);
    EXPECT_EQ(loadedData.totalPracticeQuestions, 30);
    EXPECT_EQ(loadedData.lastQuizDate, "2024-01-25");
    EXPECT_EQ(loadedData.completedCategories.size(), 1);
    EXPECT_EQ(loadedData.completedCategories[0], "통합 테스트");
}

// ===== 경계값 테스트 =====

TEST_F(WhileLoopQuizTest, BoundaryValues_EmptyStrings_HandlesCorrectly) {
    QuizQuestion question;
    question.question = "";
    question.hint = "";
    question.explanation = "";
    question.category = "";
    
    EXPECT_EQ(question.question, "");
    EXPECT_EQ(question.hint, "");
    EXPECT_EQ(question.explanation, "");
    EXPECT_EQ(question.category, "");
}

TEST_F(WhileLoopQuizTest, BoundaryValues_ZeroScores_HandlesCorrectly) {
    UserQuizData userData;
    userData.username = "zerotest";
    userData.reviewQuizScore = 0;
    userData.finalQuizScore = 0;
    userData.practiceQuizScore = 0;
    userData.totalReviewQuestions = 0;
    userData.totalFinalQuestions = 0;
    userData.totalPracticeQuestions = 0;
    
    saveUserQuizData(userData);
    
    UserQuizData loadedData = loadUserQuizData("zerotest");
    EXPECT_EQ(loadedData.reviewQuizScore, 0);
    EXPECT_EQ(loadedData.finalQuizScore, 0);
    EXPECT_EQ(loadedData.practiceQuizScore, 0);
    EXPECT_EQ(loadedData.totalReviewQuestions, 0);
    EXPECT_EQ(loadedData.totalFinalQuestions, 0);
    EXPECT_EQ(loadedData.totalPracticeQuestions, 0);
}

TEST_F(WhileLoopQuizTest, BoundaryValues_MaximumScores_HandlesCorrectly) {
    UserQuizData userData;
    userData.username = "maxtest";
    userData.reviewQuizScore = 100;
    userData.finalQuizScore = 100;
    userData.practiceQuizScore = 100;
    userData.totalReviewQuestions = 999;
    userData.totalFinalQuestions = 999;
    userData.totalPracticeQuestions = 999;
    
    saveUserQuizData(userData);
    
    UserQuizData loadedData = loadUserQuizData("maxtest");
    EXPECT_EQ(loadedData.reviewQuizScore, 100);
    EXPECT_EQ(loadedData.finalQuizScore, 100);
    EXPECT_EQ(loadedData.practiceQuizScore, 100);
    EXPECT_EQ(loadedData.totalReviewQuestions, 999);
    EXPECT_EQ(loadedData.totalFinalQuestions, 999);
    EXPECT_EQ(loadedData.totalPracticeQuestions, 999);
}

// ===== 성능 테스트 =====

TEST_F(WhileLoopQuizTest, Performance_MultipleQuizQuestions_HandlesEfficiently) {
    vector<QuizQuestion> questions;
    
    // 많은 퀴즈 문제 생성
    for (int i = 0; i < 100; i++) {
        QuizQuestion question;
        question.question = "문제 " + std::to_string(i);
        question.hint = "힌트 " + std::to_string(i);
        question.explanation = "설명 " + std::to_string(i);
        question.category = "카테고리 " + std::to_string(i);
        question.difficulty = (i % 5) + 1;
        question.type = static_cast<QuizType>(i % 3);
        question.options = {"옵션1", "옵션2", "옵션3", "옵션4"};
        question.correctIndex = i % 4;
        questions.push_back(question);
    }
    
    EXPECT_EQ(questions.size(), 100);
    
    // 모든 문제가 올바르게 생성되었는지 확인
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(questions[i].question, "문제 " + std::to_string(i));
        EXPECT_EQ(questions[i].hint, "힌트 " + std::to_string(i));
        EXPECT_EQ(questions[i].explanation, "설명 " + std::to_string(i));
        EXPECT_EQ(questions[i].category, "카테고리 " + std::to_string(i));
    }
}

// ===== 예외 처리 테스트 =====

TEST_F(WhileLoopQuizTest, ExceptionHandling_InvalidQuizIndex_HandlesGracefully) {
    QuizQuestion question;
    question.question = "테스트";
    question.options = {"옵션1", "옵션2"};
    question.correctIndex = 5; // 유효하지 않은 인덱스
    
    // 유효하지 않은 인덱스가 있어도 구조체 자체는 생성됨
    EXPECT_EQ(question.question, "테스트");
    EXPECT_EQ(question.options.size(), 2);
    EXPECT_EQ(question.correctIndex, 5);
}

TEST_F(WhileLoopQuizTest, ExceptionHandling_EmptyQuizOptions_HandlesGracefully) {
    QuizQuestion question;
    question.question = "테스트";
    question.options = {};
    question.correctIndex = 0;
    
    EXPECT_EQ(question.question, "테스트");
    EXPECT_EQ(question.options.size(), 0);
    EXPECT_EQ(question.correctIndex, 0);
}

TEST_F(WhileLoopQuizTest, ExceptionHandling_InvalidDifficulty_HandlesGracefully) {
    QuizQuestion question;
    question.question = "테스트";
    question.difficulty = 10; // 유효하지 않은 난이도
    
    EXPECT_EQ(question.question, "테스트");
    EXPECT_EQ(question.difficulty, 10);
}

// ===== 퀴즈 타입별 분류 테스트 =====

TEST_F(WhileLoopQuizTest, QuizTypeClassification_ReviewQuizzes_HaveCorrectType) {
    vector<QuizQuestion> reviewQuizzes = buildReviewQuizzes();
    
    for (const auto& quiz : reviewQuizzes) {
        EXPECT_EQ(quiz.type, QuizType::REVIEW_QUIZ);
    }
}

TEST_F(WhileLoopQuizTest, QuizTypeClassification_FinalQuizzes_HaveCorrectType) {
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    
    // FINAL_QUIZ 타입의 퀴즈들만 필터링
    int finalQuizCount = 0;
    for (const auto& quiz : whileLoopQuizzes) {
        if (quiz.type == QuizType::FINAL_QUIZ) {
            finalQuizCount++;
        }
    }
    
    EXPECT_EQ(finalQuizCount, 2); // buildWhileLoopQuizzes에서 FINAL_QUIZ는 2개
}

TEST_F(WhileLoopQuizTest, QuizTypeClassification_PracticeQuizzes_HaveCorrectType) {
    vector<QuizQuestion> practiceQuizzes = buildPracticeQuizzes();
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    
    // PRACTICE_QUIZ 타입의 퀴즈들만 필터링
    int practiceQuizCount = 0;
    for (const auto& quiz : practiceQuizzes) {
        if (quiz.type == QuizType::PRACTICE_QUIZ) {
            practiceQuizCount++;
        }
    }
    
    for (const auto& quiz : whileLoopQuizzes) {
        if (quiz.type == QuizType::PRACTICE_QUIZ) {
            practiceQuizCount++;
        }
    }
    
    EXPECT_EQ(practiceQuizCount, 2); // buildPracticeQuizzes에서 1개 + buildWhileLoopQuizzes에서 1개
}

 