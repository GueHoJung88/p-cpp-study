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
using learning::Character;
using learning::Species;
using learning::Emotion;

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

// Enter 키 대기 함수
void pressEnterToContinue(const Character& speaker, const string& emotion = "default", const string& message = "계속하려면 Enter 키를 누르세요...") {
    speaker.display(emotion);
    printBlue("[" + speaker.getName() + "]: ");
    cout << message << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
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
            "2. While Loop 실행 과정",
            "1. 조건을 확인합니다\n"
            "2. 조건이 참이면 코드 블록을 실행합니다\n"
            "3. 다시 조건을 확인합니다\n"
            "4. 조건이 거짓이 될 때까지 반복합니다",
            "int i = 0;\nwhile (i < 3) {\n    cout << i << endl;\n    i++;\n}",
            "위 코드의 출력 결과는?",
            "0\n1\n2",
            "i가 0부터 시작해서 3보다 작을 때까지 반복해요.",
            {
                "이제 While Loop가 어떻게 작동하는지 자세히 설명해드릴게요!",
                "먼저 조건을 확인하고, 참이면 코드를 실행해요.",
                "그 다음 다시 조건을 확인하는 과정을 반복하죠."
            },
            {
                "실행 과정을 단계별로 설명해주세요!",
                "조건 확인 → 코드 실행 → 다시 조건 확인...",
                "이해했어요! 반복하는 구조네요!"
            }
        },
        {
            "3. 무한 루프 주의사항",
            "조건이 절대 거짓이 되지 않으면 무한 루프가 발생합니다.\n"
            "반드시 조건을 변경하는 코드가 있어야 합니다!",
            "int i = 0;\nwhile (i < 5) {\n    cout << i << endl;\n    // i++가 없으면 무한 루프!\n}",
            "무한 루프를 방지하려면 무엇을 해야 할까요?",
            "조건을 변경하는 코드를 추가한다",
            "변수 값을 증가시키거나 감소시켜야 해요.",
            {
                "무한 루프는 프로그래머가 가장 조심해야 할 부분이에요!",
                "조건이 절대 거짓이 되지 않으면 프로그램이 멈추지 않아요.",
                "반드시 조건을 변경하는 코드를 넣어야 해요."
            },
            {
                "무한 루프가 뭔가요?",
                "조건을 변경하는 코드... i++ 같은 걸 말하는 건가요?",
                "아하! 이해했어요!"
            }
        },
        {
            "4. Do-While Loop",
            "Do-While Loop는 코드를 먼저 실행한 후 조건을 확인합니다.\n"
            "최소 한 번은 실행됩니다.",
            "do {\n    // 실행할 코드\n} while (조건);",
            "do-while과 while의 차이점은?",
            "do-while은 최소 한 번은 실행된다",
            "do-while은 조건 확인 전에 먼저 실행해요.",
            {
                "이제 Do-While Loop에 대해 알아볼까요?",
                "While Loop와 비슷하지만 실행 순서가 달라요.",
                "최소 한 번은 실행된다는 점이 중요해요!"
            },
            {
                "Do-While Loop는 뭔가요?",
                "While Loop와 다른 점이 있나요?",
                "최소 한 번은 실행된다는 건 좋네요!"
            }
        },
        {
            "5. While Loop 활용 예제",
            "While Loop는 사용자 입력 처리, 파일 읽기, 게임 루프 등에 활용됩니다.",
            "int number;\ndo {\n    cout << \"양수를 입력하세요: \";\n    cin >> number;\n} while (number <= 0);",
            "위 코드는 무엇을 하는가?",
            "양수를 입력받을 때까지 반복한다",
            "0 이하의 수가 입력되면 다시 입력받아요.",
            {
                "이제 실제 활용 예제를 보여드릴게요!",
                "사용자 입력 처리에 자주 사용되는 패턴이에요.",
                "게임이나 프로그램에서 매우 유용해요!"
            },
            {
                "실제로 어떻게 사용하나요?",
                "사용자 입력을 받을 때 사용하는군요!",
                "정말 유용하네요!"
            }
        }
    };
}

// 간단한 퀴즈 구성
vector<SimpleQuiz> buildSimpleQuizzes() {
    return {
        {
            "While Loop의 올바른 기본 구문은?",
            {"while (조건) {", "while 조건 {", "while (조건)", "while 조건"},
            0,
            "while 키워드 다음에 괄호로 조건을 감싸야 해요."
        },
        {
            "무한 루프를 방지하려면?",
            {"조건을 복잡하게 만든다", "조건을 변경하는 코드를 추가한다", "while 키워드를 생략한다", "괄호를 제거한다"},
            1,
            "조건을 변경하는 코드(예: i++)가 필요해요."
        },
        {
            "int i = 0; while (i < 3) { cout << i; i++; } 의 출력은?",
            {"012", "123", "0123", "1234"},
            0,
            "i가 0, 1, 2일 때 출력되고, 3이 되면 반복이 멈춰요."
        },
        {
            "Do-While Loop의 특징은?",
            {"더 빠르다", "최소 한 번은 실행된다", "더 안전하다", "차이점이 없다"},
            1,
            "do-while은 조건 확인 전에 먼저 코드를 실행해요."
        },
        {
            "사용자 입력 처리에 적합한 것은?",
            {"while (true)", "do-while", "for loop", "if-else"},
            1,
            "do-while은 최소 한 번은 입력받을 수 있어서 적합해요."
        }
    };
}

// 학습 단계 진행 함수
void conductLearningStep(Character& teacher, Character& student, const LearningStep& step, UserLearningData& userData) {
    cout << "\n" << string(50, '=') << endl;
    printYellow("📚 " + step.title + "\n");
    cout << string(50, '=') << endl;
    
    // 선생님과 학생의 대화
    for (size_t i = 0; i < step.teacherDialogue.size(); ++i) {
        teacher.display(Emotion::EXPLAIN);
        printBlue("[" + teacher.getName() + "]: ");
        cout << step.teacherDialogue[i] << endl;
        
        if (i < step.studentDialogue.size()) {
            student.display(Emotion::THINKING);
            printCyan("[" + student.getName() + "]: ");
            cout << step.studentDialogue[i] << endl;
        }
        
        pressEnterToContinue(teacher, "happy", "계속하시겠어요?");
    }
    
    // 개념 설명
    printCyan("💡 개념 설명:\n");
    cout << step.explanation << endl;
    
    pressEnterToContinue(teacher, "thinking", "이해했나요?");
    
    // 코드 예제
    printGreen("💻 코드 예제:\n");
    cout << step.codeExample << endl;
    
    pressEnterToContinue(teacher, "thinking", "이 코드를 분석해보세요!");
    
    // 실습 문제
    printRed("🎯 실습 문제:\n");
    cout << step.practiceQuestion << endl;
    printPurple("💡 힌트: " + step.hint + "\n");
    
    string userAnswer;
    cout << "답을 입력하세요: ";
    getline(cin, userAnswer);
    
    // 정답 확인
    if (userAnswer.find(step.practiceAnswer) != string::npos) {
        teacher.display(Emotion::HAPPY);
        printBlue("[" + teacher.getName() + "]: ");
        cout << "정답입니다! 잘했어요! 🎉\n";
        userData.whileLoopScore++;
    } else {
        teacher.display(Emotion::SAD);
        printBlue("[" + teacher.getName() + "]: ");
        cout << "틀렸어요. 정답은 '" << step.practiceAnswer << "' 입니다.\n";
    }
    
    userData.totalQuestions++;
    pressEnterToContinue(teacher, "happy", "다음 단계로 넘어가요!");
}

// 간단한 퀴즈 진행 함수
void conductSimpleQuiz(Character& teacher, Character& student, const vector<SimpleQuiz>& quizzes, UserLearningData& userData) {
    cout << "\n" << string(50, '=') << endl;
    printYellow("📝 이해도 점검 퀴즈\n");
    cout << string(50, '=') << endl;
    
    teacher.display(Emotion::QUIZ);
    printBlue("[" + teacher.getName() + "]: ");
    cout << "이제 배운 내용을 퀴즈로 점검해볼까요? 🎯\n";
    
    for (const auto& quiz : quizzes) {
        cout << "\n📋 문제: " << quiz.question << endl;
        
        for (size_t i = 0; i < quiz.options.size(); ++i) {
            cout << (i + 1) << ". " << quiz.options[i] << endl;
        }
        
        int userChoice;
        cout << "\n답을 선택하세요 (1-" << quiz.options.size() << "): ";
        cin >> userChoice;
        
        if (userChoice == quiz.correctIndex + 1) {
            teacher.display(Emotion::HAPPY);
            printBlue("[" + teacher.getName() + "]: ");
            cout << "정답입니다! 🎉\n";
            userData.whileLoopScore++;
        } else {
            teacher.display(Emotion::SAD);
            printBlue("[" + teacher.getName() + "]: ");
            cout << "틀렸어요. 정답은 " << (quiz.correctIndex + 1) << "번입니다.\n";
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
    vector<Character> all_characters = Character::initializeCharacters();
    
    // 보리를 주인공으로 설정
    Character student;
    for (const auto& chara : all_characters) {
        if (chara.getSpecies() == Species::MALTESE) {
            student = chara;
            break;
        }
    }
    
    // 선생님 캐릭터 선택 (치와와)
    Character teacher;
    for (const auto& chara : all_characters) {
        if (chara.getSpecies() == Species::CHIHUAHUA) {
            teacher = chara;
            break;
        }
    }
    
    cout << "\n🎮 주인공: " << student.getName() << " (" << student.getRole() << ")" << endl;
    cout << "🎓 선생님: " << teacher.getName() << " (" << teacher.getRole() << ")" << endl;
    
    student.display(Emotion::HAPPY);
    printCyan("[" + student.getName() + "]: ");
    cout << "안녕하세요! While Loop를 배우고 싶어요! 🐕\n";
    
    // 사용자 이름 입력
    string username;
    cout << "\n이름을 입력해주세요: ";
    getline(cin, username);
    
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
    
    student.display(Emotion::HAPPY);
    printCyan("[" + student.getName() + "]: ");
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
    
    teacher.display(Emotion::HAPPY);
    printBlue("[" + teacher.getName() + "]: ");
    cout << "다음에 또 만나요! 🐕\n";
    
    return 0;
} 