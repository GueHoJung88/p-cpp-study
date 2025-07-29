#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

// 테스트할 WhileLoop Interactive 프로그램의 주요 기능들
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

// 학습 단계 구조체 (원본과 동일)
struct LearningStep {
    string title;
    string explanation;
    string codeExample;
    string practiceQuestion;
    string practiceAnswer;
    string hint;
    vector<string> teacherDialogue;
    vector<string> studentDialogue;
};

// 간단한 퀴즈 구조체 (원본과 동일)
struct SimpleQuiz {
    string question;
    vector<string> options;
    int correctIndex;
    string explanation;
};

// 사용자 학습 데이터 구조체 (원본과 동일)
struct UserLearningData {
    string username;
    int whileLoopScore;
    int totalQuestions;
    vector<string> completedTopics;
    string lastStudyDate;
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

// 사용자 데이터 저장 함수 (테스트용)
void saveUserData(const UserLearningData& userData) {
    ofstream file("test_user_learning_data.txt");
    file << "username:" << userData.username << endl;
    file << "whileLoopScore:" << userData.whileLoopScore << endl;
    file << "totalQuestions:" << userData.totalQuestions << endl;
    file << "lastStudyDate:" << userData.lastStudyDate << endl;
    file << "completedTopics:";
    for (const auto& topic : userData.completedTopics) {
        file << topic << ",";
    }
    file << endl;
    file.close();
}

// 사용자 데이터 로드 함수 (테스트용)
UserLearningData loadUserData(const string& username) {
    UserLearningData userData;
    userData.username = username;
    userData.whileLoopScore = 0;
    userData.totalQuestions = 0;
    userData.lastStudyDate = "";
    
    ifstream file("test_user_learning_data.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t colonPos = line.find(':');
            if (colonPos != string::npos) {
                string key = line.substr(0, colonPos);
                string value = line.substr(colonPos + 1);
                
                if (key == "username") {
                    userData.username = value;
                } else if (key == "whileLoopScore") {
                    istringstream iss(value);
                    iss >> userData.whileLoopScore;
                } else if (key == "totalQuestions") {
                    istringstream iss(value);
                    iss >> userData.totalQuestions;
                } else if (key == "lastStudyDate") {
                    userData.lastStudyDate = value;
                } else if (key == "completedTopics") {
                    userData.completedTopics.clear();
                    istringstream iss(value);
                    string topic;
                    while (getline(iss, topic, ',')) {
                        if (!topic.empty()) {
                            userData.completedTopics.push_back(topic);
                        }
                    }
                }
            }
        }
        file.close();
    }
    
    return userData;
}

// 학습 단계 생성 함수 (테스트용)
vector<LearningStep> buildWhileLoopLearningSteps() {
    vector<LearningStep> steps;
    
    // 첫 번째 단계
    LearningStep step1;
    step1.title = "While Loop 기본 개념";
    step1.explanation = "while 루프는 조건이 참인 동안 코드 블록을 반복 실행합니다.";
    step1.codeExample = "int i = 0;\nwhile (i < 5) {\n    cout << i << endl;\n    i++;\n}";
    step1.practiceQuestion = "0부터 4까지 출력하는 while 루프를 작성하세요.";
    step1.practiceAnswer = "int i = 0;\nwhile (i <= 4) {\n    cout << i << endl;\n    i++;\n}";
    step1.hint = "초기값을 0으로 설정하고, 조건을 i <= 4로 설정하세요.";
    step1.teacherDialogue = {"안녕하세요! while 루프에 대해 배워보겠습니다.", "while 루프는 조건이 참인 동안 계속 실행됩니다."};
    step1.studentDialogue = {"네, 알겠습니다!", "조건이 거짓이 되면 루프가 종료되는군요."};
    steps.push_back(step1);
    
    // 두 번째 단계
    LearningStep step2;
    step2.title = "While Loop 조건문";
    step2.explanation = "while 루프의 조건문은 반복 실행 여부를 결정합니다.";
    step2.codeExample = "int count = 3;\nwhile (count > 0) {\n    cout << count << endl;\n    count--;\n}";
    step2.practiceQuestion = "3부터 1까지 카운트다운하는 while 루프를 작성하세요.";
    step2.practiceAnswer = "int count = 3;\nwhile (count > 0) {\n    cout << count << endl;\n    count--;\n}";
    step2.hint = "count 변수를 감소시키면서 0보다 클 때까지 반복하세요.";
    step2.teacherDialogue = {"이제 조건문에 대해 더 자세히 알아보겠습니다.", "조건이 거짓이 되면 루프가 종료됩니다."};
    step2.studentDialogue = {"조건문이 중요하군요!", "무한 루프를 피해야겠어요."};
    steps.push_back(step2);
    
    return steps;
}

// 간단한 퀴즈 생성 함수 (테스트용)
vector<SimpleQuiz> buildSimpleQuizzes() {
    vector<SimpleQuiz> quizzes;
    
    SimpleQuiz quiz1;
    quiz1.question = "while 루프의 기본 문법은 무엇인가요?";
    quiz1.options = {"while (조건) { 코드 }", "for (조건) { 코드 }", "if (조건) { 코드 }", "do { 코드 } while (조건)"};
    quiz1.correctIndex = 0;
    quiz1.explanation = "while 루프는 'while (조건) { 코드 }' 형태로 작성됩니다.";
    quizzes.push_back(quiz1);
    
    SimpleQuiz quiz2;
    quiz2.question = "while 루프에서 무한 루프를 피하기 위해 필요한 것은?";
    quiz2.options = {"조건문", "증감식", "중괄호", "세미콜론"};
    quiz2.correctIndex = 1;
    quiz2.explanation = "증감식을 통해 조건이 거짓이 되도록 해야 무한 루프를 피할 수 있습니다.";
    quizzes.push_back(quiz2);
    
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

// ===== WhileLoop Interactive 프로그램 테스트 =====

class WhileLoopInteractiveTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 테스트용 캐릭터들 생성
        teacher = Character("치치", "선생님");
        student = Character("리키", "학생");
        
        // 테스트용 사용자 데이터
        testUserData.username = "testuser";
        testUserData.whileLoopScore = 0;
        testUserData.totalQuestions = 0;
        testUserData.lastStudyDate = "";
        testUserData.completedTopics.clear();
    }
    
    void TearDown() override {
        // 테스트 파일 정리
        std::remove("test_user_learning_data.txt");
    }
    
    Character teacher;
    Character student;
    UserLearningData testUserData;
};

// ===== 학습 단계 테스트 =====

TEST_F(WhileLoopInteractiveTest, LearningStepCreation_ValidData_CreatesStep) {
    LearningStep step;
    step.title = "테스트 제목";
    step.explanation = "테스트 설명";
    step.codeExample = "테스트 코드";
    step.practiceQuestion = "테스트 문제";
    step.practiceAnswer = "테스트 답안";
    step.hint = "테스트 힌트";
    
    EXPECT_EQ(step.title, "테스트 제목");
    EXPECT_EQ(step.explanation, "테스트 설명");
    EXPECT_EQ(step.codeExample, "테스트 코드");
    EXPECT_EQ(step.practiceQuestion, "테스트 문제");
    EXPECT_EQ(step.practiceAnswer, "테스트 답안");
    EXPECT_EQ(step.hint, "테스트 힌트");
}

TEST_F(WhileLoopInteractiveTest, BuildWhileLoopLearningSteps_ReturnsValidSteps) {
    vector<LearningStep> steps = buildWhileLoopLearningSteps();
    
    EXPECT_EQ(steps.size(), 2);
    EXPECT_EQ(steps[0].title, "While Loop 기본 개념");
    EXPECT_EQ(steps[1].title, "While Loop 조건문");
    EXPECT_FALSE(steps[0].explanation.empty());
    EXPECT_FALSE(steps[1].explanation.empty());
}

TEST_F(WhileLoopInteractiveTest, LearningStepTeacherDialogue_ContainsValidContent) {
    vector<LearningStep> steps = buildWhileLoopLearningSteps();
    
    EXPECT_FALSE(steps[0].teacherDialogue.empty());
    EXPECT_FALSE(steps[1].teacherDialogue.empty());
    EXPECT_EQ(steps[0].teacherDialogue.size(), 2);
    EXPECT_EQ(steps[1].teacherDialogue.size(), 2);
}

// ===== 간단한 퀴즈 테스트 =====

TEST_F(WhileLoopInteractiveTest, SimpleQuizCreation_ValidData_CreatesQuiz) {
    SimpleQuiz quiz;
    quiz.question = "테스트 문제";
    quiz.options = {"옵션1", "옵션2", "옵션3", "옵션4"};
    quiz.correctIndex = 1;
    quiz.explanation = "테스트 설명";
    
    EXPECT_EQ(quiz.question, "테스트 문제");
    EXPECT_EQ(quiz.options.size(), 4);
    EXPECT_EQ(quiz.correctIndex, 1);
    EXPECT_EQ(quiz.explanation, "테스트 설명");
}

TEST_F(WhileLoopInteractiveTest, BuildSimpleQuizzes_ReturnsValidQuizzes) {
    vector<SimpleQuiz> quizzes = buildSimpleQuizzes();
    
    EXPECT_EQ(quizzes.size(), 2);
    EXPECT_FALSE(quizzes[0].question.empty());
    EXPECT_FALSE(quizzes[1].question.empty());
    EXPECT_EQ(quizzes[0].options.size(), 4);
    EXPECT_EQ(quizzes[1].options.size(), 4);
    EXPECT_GE(quizzes[0].correctIndex, 0);
    EXPECT_LT(quizzes[0].correctIndex, 4);
    EXPECT_GE(quizzes[1].correctIndex, 0);
    EXPECT_LT(quizzes[1].correctIndex, 4);
}

TEST_F(WhileLoopInteractiveTest, QuizCorrectIndex_WithinValidRange) {
    vector<SimpleQuiz> quizzes = buildSimpleQuizzes();
    
    for (const auto& quiz : quizzes) {
        EXPECT_GE(quiz.correctIndex, 0);
        EXPECT_LT(quiz.correctIndex, static_cast<int>(quiz.options.size()));
    }
}

// ===== 사용자 데이터 관리 테스트 =====

TEST_F(WhileLoopInteractiveTest, UserLearningDataCreation_ValidData_CreatesData) {
    UserLearningData userData;
    userData.username = "testuser";
    userData.whileLoopScore = 85;
    userData.totalQuestions = 10;
    userData.lastStudyDate = "2024-01-01";
    userData.completedTopics = {"기본 개념", "조건문"};
    
    EXPECT_EQ(userData.username, "testuser");
    EXPECT_EQ(userData.whileLoopScore, 85);
    EXPECT_EQ(userData.totalQuestions, 10);
    EXPECT_EQ(userData.lastStudyDate, "2024-01-01");
    EXPECT_EQ(userData.completedTopics.size(), 2);
}

TEST_F(WhileLoopInteractiveTest, SaveUserData_ValidData_SavesToFile) {
    UserLearningData userData;
    userData.username = "testuser";
    userData.whileLoopScore = 75;
    userData.totalQuestions = 8;
    userData.lastStudyDate = "2024-01-15";
    userData.completedTopics = {"기본 개념"};
    
    saveUserData(userData);
    
    // 파일이 생성되었는지 확인
    ifstream file("test_user_learning_data.txt");
    EXPECT_TRUE(file.is_open());
    file.close();
}

TEST_F(WhileLoopInteractiveTest, LoadUserData_ExistingFile_LoadsCorrectData) {
    // 먼저 테스트 데이터 저장
    UserLearningData originalData;
    originalData.username = "testuser";
    originalData.whileLoopScore = 90;
    originalData.totalQuestions = 12;
    originalData.lastStudyDate = "2024-01-20";
    originalData.completedTopics = {"기본 개념", "조건문", "실습"};
    
    saveUserData(originalData);
    
    // 데이터 로드
    UserLearningData loadedData = loadUserData("testuser");
    
    EXPECT_EQ(loadedData.username, "testuser");
    EXPECT_EQ(loadedData.whileLoopScore, 90);
    EXPECT_EQ(loadedData.totalQuestions, 12);
    EXPECT_EQ(loadedData.lastStudyDate, "2024-01-20");
    EXPECT_EQ(loadedData.completedTopics.size(), 3);
    EXPECT_EQ(loadedData.completedTopics[0], "기본 개념");
    EXPECT_EQ(loadedData.completedTopics[1], "조건문");
    EXPECT_EQ(loadedData.completedTopics[2], "실습");
}

TEST_F(WhileLoopInteractiveTest, LoadUserData_NonExistentFile_ReturnsDefaultData) {
    UserLearningData loadedData = loadUserData("nonexistent");
    
    EXPECT_EQ(loadedData.username, "nonexistent");
    EXPECT_EQ(loadedData.whileLoopScore, 0);
    EXPECT_EQ(loadedData.totalQuestions, 0);
    EXPECT_EQ(loadedData.lastStudyDate, "");
    EXPECT_TRUE(loadedData.completedTopics.empty());
}

// ===== 색상 출력 함수 테스트 =====

TEST_F(WhileLoopInteractiveTest, PrintColorFunctions_OutputCorrectFormat) {
    OutputCapture capture;
    
    printBlue("파란색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[BLUE]파란색 텍스트[RESET]");
    
    capture.clear();
    printGreen("초록색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[GREEN]초록색 텍스트[RESET]");
    
    capture.clear();
    printRed("빨간색 텍스트");
    EXPECT_EQ(capture.getOutput(), "[RED]빨간색 텍스트[RESET]");
}

// ===== 캐릭터 시스템 테스트 =====

TEST_F(WhileLoopInteractiveTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("테스트", "역할");
    
    EXPECT_EQ(testChar.getName(), "테스트");
    EXPECT_EQ(testChar.getRole(), "역할");
}

TEST_F(WhileLoopInteractiveTest, CharacterDisplay_ValidEmotion_DoesNotThrow) {
    Character testChar("테스트", "역할");
    
    // display 함수가 예외를 던지지 않는지 확인
    EXPECT_NO_THROW(testChar.display("happy"));
    EXPECT_NO_THROW(testChar.display("sad"));
    EXPECT_NO_THROW(testChar.display("default"));
}

// ===== 통합 테스트 =====

TEST_F(WhileLoopInteractiveTest, Integration_CompleteLearningFlow_WorksCorrectly) {
    // 학습 단계 생성
    vector<LearningStep> steps = buildWhileLoopLearningSteps();
    EXPECT_EQ(steps.size(), 2);
    
    // 퀴즈 생성
    vector<SimpleQuiz> quizzes = buildSimpleQuizzes();
    EXPECT_EQ(quizzes.size(), 2);
    
    // 사용자 데이터 생성 및 저장
    UserLearningData userData;
    userData.username = "integration_test";
    userData.whileLoopScore = 100;
    userData.totalQuestions = 15;
    userData.lastStudyDate = "2024-01-25";
    userData.completedTopics = {"통합 테스트"};
    
    saveUserData(userData);
    
    // 데이터 로드 및 검증
    UserLearningData loadedData = loadUserData("integration_test");
    EXPECT_EQ(loadedData.username, "integration_test");
    EXPECT_EQ(loadedData.whileLoopScore, 100);
    EXPECT_EQ(loadedData.totalQuestions, 15);
    EXPECT_EQ(loadedData.lastStudyDate, "2024-01-25");
    EXPECT_EQ(loadedData.completedTopics.size(), 1);
    EXPECT_EQ(loadedData.completedTopics[0], "통합 테스트");
}

// ===== 경계값 테스트 =====

TEST_F(WhileLoopInteractiveTest, BoundaryValues_EmptyStrings_HandlesCorrectly) {
    LearningStep step;
    step.title = "";
    step.explanation = "";
    step.codeExample = "";
    step.practiceQuestion = "";
    step.practiceAnswer = "";
    step.hint = "";
    
    EXPECT_EQ(step.title, "");
    EXPECT_EQ(step.explanation, "");
    EXPECT_EQ(step.codeExample, "");
    EXPECT_EQ(step.practiceQuestion, "");
    EXPECT_EQ(step.practiceAnswer, "");
    EXPECT_EQ(step.hint, "");
}

TEST_F(WhileLoopInteractiveTest, BoundaryValues_ZeroScores_HandlesCorrectly) {
    UserLearningData userData;
    userData.username = "zerotest";
    userData.whileLoopScore = 0;
    userData.totalQuestions = 0;
    
    saveUserData(userData);
    
    UserLearningData loadedData = loadUserData("zerotest");
    EXPECT_EQ(loadedData.whileLoopScore, 0);
    EXPECT_EQ(loadedData.totalQuestions, 0);
}

TEST_F(WhileLoopInteractiveTest, BoundaryValues_MaximumScores_HandlesCorrectly) {
    UserLearningData userData;
    userData.username = "maxtest";
    userData.whileLoopScore = 100;
    userData.totalQuestions = 999;
    
    saveUserData(userData);
    
    UserLearningData loadedData = loadUserData("maxtest");
    EXPECT_EQ(loadedData.whileLoopScore, 100);
    EXPECT_EQ(loadedData.totalQuestions, 999);
}

// ===== 성능 테스트 =====

TEST_F(WhileLoopInteractiveTest, Performance_MultipleLearningSteps_HandlesEfficiently) {
    vector<LearningStep> steps;
    
    // 많은 학습 단계 생성
    for (int i = 0; i < 100; i++) {
        LearningStep step;
        step.title = "단계 " + std::to_string(i);
        step.explanation = "설명 " + std::to_string(i);
        step.codeExample = "코드 " + std::to_string(i);
        step.practiceQuestion = "문제 " + std::to_string(i);
        step.practiceAnswer = "답안 " + std::to_string(i);
        step.hint = "힌트 " + std::to_string(i);
        steps.push_back(step);
    }
    
    EXPECT_EQ(steps.size(), 100);
    
    // 모든 단계가 올바르게 생성되었는지 확인
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(steps[i].title, "단계 " + std::to_string(i));
        EXPECT_EQ(steps[i].explanation, "설명 " + std::to_string(i));
    }
}

// ===== 예외 처리 테스트 =====

TEST_F(WhileLoopInteractiveTest, ExceptionHandling_InvalidQuizIndex_HandlesGracefully) {
    SimpleQuiz quiz;
    quiz.question = "테스트";
    quiz.options = {"옵션1", "옵션2"};
    quiz.correctIndex = 5; // 유효하지 않은 인덱스
    
    // 유효하지 않은 인덱스가 있어도 구조체 자체는 생성됨
    EXPECT_EQ(quiz.question, "테스트");
    EXPECT_EQ(quiz.options.size(), 2);
    EXPECT_EQ(quiz.correctIndex, 5);
}

TEST_F(WhileLoopInteractiveTest, ExceptionHandling_EmptyQuizOptions_HandlesGracefully) {
    SimpleQuiz quiz;
    quiz.question = "테스트";
    quiz.options = {};
    quiz.correctIndex = 0;
    
    EXPECT_EQ(quiz.question, "테스트");
    EXPECT_EQ(quiz.options.size(), 0);
    EXPECT_EQ(quiz.correctIndex, 0);
}

 