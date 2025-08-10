#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "Character.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::istringstream;

// 학습 단계 구조체
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

// 간단한 퀴즈 구조체
struct SimpleQuiz {
    string question;
    vector<string> options;
    int correctIndex;
    string explanation;
};

// 사용자 학습 데이터 구조체
struct UserLearningData {
    string username;
    int whileLoopScore;
    int totalQuestions;
    vector<string> completedTopics;
    string lastStudyDate;
};

// 색상 출력 함수들
void printBlue(const string& text) {
    cout << "\033[34m" << text << "\033[0m";
}

void printYellow(const string& text) {
    cout << "\033[33m" << text << "\033[0m";
}

void printGreen(const string& text) {
    cout << "\033[32m" << text << "\033[0m";
}

void printRed(const string& text) {
    cout << "\033[31m" << text << "\033[0m";
}

void printPurple(const string& text) {
    cout << "\033[35m" << text << "\033[0m";
}

void printCyan(const string& text) {
    cout << "\033[36m" << text << "\033[0m";
}

// 수정된 Enter 키 대기 함수 - 자동 진행
void pressEnterToContinue(const Character& speaker, const string& emotion = "default", const string& message = "계속하려면 Enter 키를 누르세요...") {
    speaker.display(emotion);
    printBlue("[" + speaker.name + "]: ");
    cout << message << endl;
    cout << "자동으로 3초 후 진행됩니다..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << endl;
}

// 사용자 데이터 저장 함수
void saveUserData(const UserLearningData& userData) {
    ofstream file("user_learning_data.txt");
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

// 사용자 데이터 로드 함수
UserLearningData loadUserData(const string& username) {
    UserLearningData userData;
    userData.username = username;
    userData.whileLoopScore = 0;
    userData.totalQuestions = 0;
    userData.completedTopics = {};
    userData.lastStudyDate = "";
    
    ifstream file("user_learning_data.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(':');
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1);
                
                if (key == "username" && value == username) {
                    // 같은 사용자 데이터를 찾았으므로 계속 읽기
                    while (getline(file, line)) {
                        pos = line.find(':');
                        if (pos != string::npos) {
                            key = line.substr(0, pos);
                            value = line.substr(pos + 1);
                            
                            if (key == "whileLoopScore") {
                                userData.whileLoopScore = stoi(value);
                            } else if (key == "totalQuestions") {
                                userData.totalQuestions = stoi(value);
                            } else if (key == "lastStudyDate") {
                                userData.lastStudyDate = value;
                            } else if (key == "completedTopics") {
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
                    break;
                }
            }
        }
        file.close();
    }
    
    return userData;
}

// While Loop 학습 단계 구성
vector<LearningStep> buildWhileLoopLearningSteps() {
    return {
        {
            "1. While Loop 기본 개념",
            "While Loop는 조건이 참인 동안 반복적으로 코드 블록을 실행하는 반복문입니다.\n"
            "조건이 거짓이 되면 반복이 멈춥니다.",
            "while (조건) {\n    // 실행할 코드\n}",
            "다음 중 while loop의 올바른 구문은?",
            "while (조건) {",
            "while 키워드 다음에 괄호가 있어야 해요.",
            {
                "안녕하세요! 오늘은 While Loop에 대해 배워볼 거예요! 🐕",
                "While Loop는 프로그래밍에서 가장 중요한 반복문 중 하나랍니다.",
                "조건이 참인 동안 계속 반복하는 구조예요."
            },
            {
                "안녕하세요! While Loop를 배우고 싶어요! 🐕",
                "조건이 참인 동안 반복한다는 건 어떤 뜻인가요?",
                "아하! 이해했어요!"
            }
        },
        {
            "2. While Loop 실행 흐름",
            "While Loop는 다음과 같은 순서로 실행됩니다:\n"
            "1. 조건을 확인\n"
            "2. 조건이 참이면 코드 블록 실행\n"
            "3. 다시 1번으로 돌아가서 반복\n"
            "4. 조건이 거짓이 되면 반복 종료",
            "int i = 0;\nwhile (i < 5) {\n    cout << i << endl;\n    i++;\n}",
            "while loop에서 무한 루프를 방지하려면?",
            "조건을 변경하는 코드가 필요하다",
            "조건이 항상 참이면 무한 루프가 됩니다.",
            {
                "이제 While Loop가 어떻게 동작하는지 알아볼까요?",
                "조건을 확인하고, 참이면 코드를 실행하고, 다시 조건을 확인해요.",
                "무한 루프에 주의해야 해요!"
            },
            {
                "조건을 확인하고 실행하는 거군요!",
                "무한 루프는 뭔가요?",
                "조건을 바꾸는 코드가 필요하군요!"
            }
        }
    };
}

// 간단한 퀴즈 구성
vector<SimpleQuiz> buildSimpleQuizzes() {
    return {
        {
            "While Loop의 기본 구문은?",
            {"while 조건 {", "while (조건) {", "while 조건:", "while (조건):"},
            1,
            "While Loop는 while (조건) { } 형태로 작성합니다."
        },
        {
            "While Loop에서 무한 루프를 방지하려면?",
            {"조건을 변경하는 코드가 필요하다", "조건을 항상 참으로 설정한다", "조건을 사용하지 않는다", "조건을 무시한다"},
            0,
            "조건이 항상 참이면 무한 루프가 되므로, 조건을 변경하는 코드가 필요합니다."
        },
        {
            "다음 중 올바른 While Loop는?",
            {"while (i < 10) { i++; }", "while i < 10 { i++; }", "while (i < 10): i++", "while i < 10: i++"},
            0,
            "while (조건) { } 형태가 올바른 구문입니다."
        }
    };
}

// 학습 단계 진행
void conductLearningStep(Character& teacher, Character& student, const LearningStep& step, UserLearningData& userData) {
    cout << "\n" << string(50, '=') << endl;
    printYellow("📚 " + step.title + "\n");
    cout << string(50, '=') << endl;
    
    // 선생님 대화
    for (const auto& dialogue : step.teacherDialogue) {
        teacher.display("happy");
        printBlue("[" + teacher.name + "]: ");
        cout << dialogue << endl;
        pressEnterToContinue(teacher, "thinking");
    }
    
    // 설명
    printGreen("📖 설명:\n" + step.explanation + "\n");
    pressEnterToContinue(teacher, "happy");
    
    // 코드 예제
    printCyan("💻 코드 예제:\n" + step.codeExample + "\n");
    pressEnterToContinue(teacher, "surprised");
    
    // 학생 대화
    for (const auto& dialogue : step.studentDialogue) {
        student.display("thinking");
        printCyan("[" + student.name + "]: ");
        cout << dialogue << endl;
        pressEnterToContinue(student, "happy");
    }
    
    // 연습 문제
    printYellow("📝 연습 문제: " + step.practiceQuestion + "\n");
    printPurple("💡 힌트: " + step.hint + "\n");
    pressEnterToContinue(teacher, "thinking");
    
    printGreen("✅ 정답: " + step.practiceAnswer + "\n");
    userData.totalQuestions++;
    
    pressEnterToContinue(teacher, "happy", "다음 단계로 넘어가요!");
}

// 간단한 퀴즈 진행
void conductSimpleQuiz(Character& teacher, Character& student, const vector<SimpleQuiz>& quizzes, UserLearningData& userData) {
    cout << "\n" << string(50, '=') << endl;
    printYellow("📝 퀴즈 시작!\n");
    cout << string(50, '=') << endl;
    
    for (size_t i = 0; i < quizzes.size(); ++i) {
        const auto& quiz = quizzes[i];
        
        cout << "\n문제 " << (i + 1) << ": " << quiz.question << endl;
        
        for (size_t j = 0; j < quiz.options.size(); ++j) {
            cout << (j + 1) << ". " << quiz.options[j] << endl;
        }
        
        // 자동으로 정답 선택 (테스트용)
        int selectedAnswer = quiz.correctIndex + 1;
        cout << "\n자동으로 정답을 선택합니다: " << selectedAnswer << endl;
        
        if (selectedAnswer == quiz.correctIndex + 1) {
            printGreen("✅ 정답입니다!\n");
            userData.whileLoopScore++;
        } else {
            printRed("❌ 틀렸습니다.\n");
        }
        
        printGreen("📚 설명: " + quiz.explanation + "\n");
        userData.totalQuestions++;
        
        pressEnterToContinue(teacher, "happy", "다음 문제로 넘어가요!");
    }
}

// 메인 함수
int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    
    cout << "🐾 ==========================================" << endl;
    cout << "🐾   C++ While Loop 대화형 학습 프로그램" << endl;
    cout << "🐾 ==========================================" << endl;
    
    // 캐릭터 초기화
    vector<Character> all_characters = initializeCharacters();
    
    // 보리를 주인공으로 설정
    Character student("말티즈", "보리", 130, 35);
    for (const auto& chara : all_characters) {
        if (chara.species == "말티즈") {
            student = chara;
            break;
        }
    }
    
    // 선생님 캐릭터 선택 (치와와)
    Character teacher("치와와", "치치", 80, 20);
    for (const auto& chara : all_characters) {
        if (chara.species == "치와와") {
            teacher = chara;
            break;
        }
    }
    
    cout << "\n🎮 주인공: " << student.name << " (" << student.species << ")" << endl;
    cout << "🎓 선생님: " << teacher.name << " (" << teacher.species << ")" << endl;
    
    student.display("happy");
    printCyan("[" + student.name + "]: ");
    cout << "안녕하세요! While Loop를 배우고 싶어요! 🐕\n";
    
    // 사용자 이름 입력 (테스트용으로 자동 설정)
    string username = "테스트사용자";
    cout << "\n이름을 입력해주세요: " << username << " (자동 설정)" << endl;
    
    // 사용자 데이터 로드
    UserLearningData userData = loadUserData(username);
    userData.username = username;
    
    // 학습 단계들 로드
    vector<LearningStep> learningSteps = buildWhileLoopLearningSteps();
    vector<SimpleQuiz> simpleQuizzes = buildSimpleQuizzes();
    
    // 기본 개념 학습
    printYellow("\n📚 기본 개념 학습을 시작합니다!\n");
    
    for (const auto& step : learningSteps) {
        conductLearningStep(teacher, student, step, userData);
    }
    
    // 간단한 퀴즈
    printYellow("\n📝 이해도 점검 퀴즈를 시작합니다!\n");
    
    conductSimpleQuiz(teacher, student, simpleQuizzes, userData);
    
    // 학습 완료
    cout << "\n" << string(50, '=') << endl;
    printGreen("🎉 While Loop 학습 완료! 🎉\n");
    cout << string(50, '=') << endl;
    
    // 최종 결과
    double scorePercentage = (static_cast<double>(userData.whileLoopScore) / userData.totalQuestions) * 100.0;
    
    student.display("happy");
    printCyan("[" + student.name + "]: ");
    cout << "축하합니다! 학습이 완료되었어요! 🎊\n";
    cout << "최종 점수: " << userData.whileLoopScore << "/" << userData.totalQuestions << " (" << scorePercentage << "%)\n";
    
    if (scorePercentage >= 80.0) {
        cout << "훌륭한 성과입니다! While Loop를 완벽하게 이해하셨네요! 🌟\n";
    } else if (scorePercentage >= 60.0) {
        cout << "좋은 성과입니다! 조금 더 연습하면 완벽해질 거예요! 💪\n";
    } else {
        cout << "기본 개념을 다시 한번 복습해보세요! 📚\n";
    }
    
    // 사용자 데이터 저장
    saveUserData(userData);
    
    teacher.display("happy");
    printBlue("[" + teacher.name + "]: ");
    cout << "다음에 또 만나요! 🐕\n";
    
    return 0;
} 