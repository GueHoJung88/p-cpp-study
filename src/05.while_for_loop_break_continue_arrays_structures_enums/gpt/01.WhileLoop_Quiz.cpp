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
#include "../../../../p_cpp/src/core/Character.h"

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

// 퀴즈 유형 열거형
enum class QuizType {
    REVIEW_QUIZ,      // 복습 퀴즈
    FINAL_QUIZ,       // 최종 점검 퀴즈
    PRACTICE_QUIZ     // 연습 퀴즈
};

// 퀴즈 문제 구조체
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

// 사용자 퀴즈 데이터 구조체
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

// 사용자 퀴즈 데이터 저장 함수
void saveUserQuizData(const UserQuizData& userData) {
    ofstream file("user_quiz_data.txt");
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

// 사용자 퀴즈 데이터 로드 함수
UserQuizData loadUserQuizData(const string& username) {
    UserQuizData userData;
    userData.username = username;
    userData.reviewQuizScore = 0;
    userData.finalQuizScore = 0;
    userData.practiceQuizScore = 0;
    userData.totalReviewQuestions = 0;
    userData.totalFinalQuestions = 0;
    userData.totalPracticeQuestions = 0;
    userData.completedCategories = {};
    userData.lastQuizDate = "";
    
    ifstream file("user_quiz_data.txt");
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
                            
                            if (key == "reviewQuizScore") {
                                userData.reviewQuizScore = stoi(value);
                            } else if (key == "finalQuizScore") {
                                userData.finalQuizScore = stoi(value);
                            } else if (key == "practiceQuizScore") {
                                userData.practiceQuizScore = stoi(value);
                            } else if (key == "totalReviewQuestions") {
                                userData.totalReviewQuestions = stoi(value);
                            } else if (key == "totalFinalQuestions") {
                                userData.totalFinalQuestions = stoi(value);
                            } else if (key == "totalPracticeQuestions") {
                                userData.totalPracticeQuestions = stoi(value);
                            } else if (key == "lastQuizDate") {
                                userData.lastQuizDate = value;
                            } else if (key == "completedCategories") {
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
                    break;
                }
            }
        }
        file.close();
    }
    
    return userData;
}

// 복습 퀴즈 구성 (기존 학습 내용)
vector<QuizQuestion> buildReviewQuizzes() {
    return {
        {
            "C++에서 문자열을 저장하는 기본 데이터 타입은?",
            "글자들의 집합을 담는 타입이에요.",
            {"int", "char", "string", "bool"},
            2,
            "string 타입은 여러 문자로 이루어진 텍스트를 저장합니다.",
            "문자열",
            1,
            QuizType::REVIEW_QUIZ
        },
        {
            "두 문자열을 연결할 때 사용하는 연산자는?",
            "문자열을 합칠 때 사용하는 친숙한 연산자예요.",
            {"-", "*", "+", "/"},
            2,
            "+ 연산자는 문자열을 연결(concatenation)할 때 사용됩니다.",
            "문자열연결",
            1,
            QuizType::REVIEW_QUIZ
        },
        {
            "C++에서 참과 거짓을 나타내는 데이터 타입은?",
            "논리값을 저장하는 타입이에요.",
            {"int", "char", "string", "bool"},
            3,
            "bool은 참(true) 또는 거짓(false)만 저장하는 논리형 타입입니다.",
            "불린",
            1,
            QuizType::REVIEW_QUIZ
        },
        {
            "if (조건) { } else { } 구문에서 else는 언제 실행되나요?",
            "조건이 거짓일 때 실행되는 부분이에요.",
            {"조건이 참일 때", "조건이 거짓일 때", "항상 실행", "절대 실행되지 않음"},
            1,
            "else는 if 조건이 거짓일 때 실행됩니다.",
            "조건문",
            1,
            QuizType::REVIEW_QUIZ
        },
        {
            "switch문에서 break를 사용하지 않으면?",
            "다음 case로 계속 실행되는 현상을 생각해보세요.",
            {"에러가 발생한다", "다음 case로 계속 실행된다", "프로그램이 멈춘다", "아무 일도 일어나지 않는다"},
            1,
            "break가 없으면 다음 case로 계속 실행되는 fall-through 현상이 발생합니다.",
            "스위치문",
            2,
            QuizType::REVIEW_QUIZ
        }
    };
}

// While Loop 퀴즈 구성
vector<QuizQuestion> buildWhileLoopQuizzes() {
    return {
        {
            "While Loop의 올바른 기본 구문은?",
            "while 키워드와 괄호를 사용해요.",
            {"while (조건) {", "while 조건 {", "while (조건)", "while 조건"},
            0,
            "while 키워드 다음에 괄호로 조건을 감싸야 해요.",
            "기본구문",
            1,
            QuizType::FINAL_QUIZ
        },
        {
            "무한 루프를 방지하려면?",
            "변수 값을 증가시키거나 감소시켜야 해요.",
            {"조건을 복잡하게 만든다", "조건을 변경하는 코드를 추가한다", "while 키워드를 생략한다", "괄호를 제거한다"},
            1,
            "조건을 변경하는 코드(예: i++)가 필요해요.",
            "무한루프",
            1,
            QuizType::FINAL_QUIZ
        },
        {
            "int i = 0; while (i < 3) { cout << i; i++; } 의 출력은?",
            "i가 0부터 시작해서 3보다 작을 때까지 반복해요.",
            {"012", "123", "0123", "1234"},
            0,
            "i가 0, 1, 2일 때 출력되고, 3이 되면 반복이 멈춰요.",
            "실행결과",
            1,
            QuizType::FINAL_QUIZ
        },
        {
            "Do-While Loop의 특징은?",
            "실행 순서를 생각해보세요.",
            {"더 빠르다", "최소 한 번은 실행된다", "더 안전하다", "차이점이 없다"},
            1,
            "do-while은 조건 확인 전에 먼저 코드를 실행해요.",
            "do-while",
            2,
            QuizType::FINAL_QUIZ
        },
        {
            "사용자 입력 처리에 적합한 것은?",
            "최소 한 번은 입력받을 수 있는 구조를 생각해보세요.",
            {"while (true)", "do-while", "for loop", "if-else"},
            1,
            "do-while은 최소 한 번은 입력받을 수 있어서 적합해요.",
            "입력처리",
            2,
            QuizType::FINAL_QUIZ
        },
        {
            "while (count > 0) 조건에서 count가 0이 되면?",
            "조건이 거짓이 되면 반복이 멈춰요.",
            {"무한 루프가 된다", "반복이 멈춘다", "에러가 발생한다", "계속 실행된다"},
            1,
            "count가 0이 되면 조건이 거짓이 되어 반복이 멈춰요.",
            "조건분석",
            1,
            QuizType::FINAL_QUIZ
        },
        {
            "while loop에서 break 문의 역할은?",
            "반복문을 즉시 종료하는 키워드를 생각해보세요.",
            {"조건을 변경한다", "반복문을 즉시 종료한다", "다음 반복으로 넘어간다", "에러를 발생시킨다"},
            1,
            "break는 반복문을 즉시 종료하고 다음 코드로 넘어가요.",
            "제어문",
            2,
            QuizType::FINAL_QUIZ
        },
        {
            "continue 문의 역할은?",
            "현재 반복을 건너뛰고 다음 반복으로 넘어가는 키워드예요.",
            {"반복문을 종료한다", "현재 반복을 건너뛴다", "조건을 변경한다", "에러를 발생시킨다"},
            1,
            "continue는 현재 반복을 건너뛰고 다음 반복으로 넘어가요.",
            "제어문",
            2,
            QuizType::FINAL_QUIZ
        }
    };
}

// 연습 퀴즈 구성
vector<QuizQuestion> buildPracticeQuizzes() {
    return {
        {
            "카운트다운 프로그램에서 countdown--;의 역할은?",
            "카운트다운이므로 숫자가 감소해야 해요.",
            {"숫자를 증가시킨다", "숫자를 감소시킨다", "숫자를 0으로 만든다", "숫자를 출력한다"},
            1,
            "countdown--는 숫자를 1씩 감소시켜서 카운트다운을 만듭니다.",
            "카운트다운",
            1,
            QuizType::PRACTICE_QUIZ
        },
        {
            "짝수만 출력하는 프로그램에서 i % 2 == 0의 의미는?",
            "나머지 연산자를 사용해서 짝수인지 확인해요.",
            {"i가 2보다 크다", "i가 짝수이다", "i가 홀수이다", "i가 0이다"},
            1,
            "i % 2 == 0은 i를 2로 나눈 나머지가 0인지 확인하여 짝수인지 판단합니다.",
            "짝수출력",
            2,
            QuizType::PRACTICE_QUIZ
        },
        {
            "사용자가 양수를 입력할 때까지 반복하는 코드는?",
            "do-while을 사용해서 최소 한 번은 입력받아요.",
            {"while (true)", "do-while", "for loop", "if-else"},
            1,
            "do-while은 최소 한 번은 입력받을 수 있어서 사용자 입력 처리에 적합해요.",
            "입력처리",
            2,
            QuizType::PRACTICE_QUIZ
        }
    };
}

// 퀴즈 진행 함수
void conductQuiz(Character& quizMaster, Character& student, const vector<QuizQuestion>& quizzes, UserQuizData& userData, QuizType quizType) {
    string quizTitle;
    int& score = (quizType == QuizType::REVIEW_QUIZ) ? userData.reviewQuizScore : 
                 (quizType == QuizType::FINAL_QUIZ) ? userData.finalQuizScore : userData.practiceQuizScore;
    int& totalQuestions = (quizType == QuizType::REVIEW_QUIZ) ? userData.totalReviewQuestions :
                         (quizType == QuizType::FINAL_QUIZ) ? userData.totalFinalQuestions : userData.totalPracticeQuestions;
    
    switch (quizType) {
        case QuizType::REVIEW_QUIZ:
            quizTitle = "📚 복습 퀴즈";
            break;
        case QuizType::FINAL_QUIZ:
            quizTitle = "🎯 최종 점검 퀴즈";
            break;
        case QuizType::PRACTICE_QUIZ:
            quizTitle = "💻 연습 퀴즈";
            break;
    }
    
    cout << "\n" << string(50, '=') << endl;
    printRed(quizTitle + "\n");
    cout << string(50, '=') << endl;
    
    quizMaster.display(Emotion::QUIZ);
    printBlue("[" + quizMaster.getName() + "]: ");
    cout << "퀴즈를 시작할게요! 준비되셨나요? 🎯\n";
    
    for (const auto& quiz : quizzes) {
        if (quiz.type != quizType) continue;
        
        cout << "\n📋 문제: " << quiz.question << endl;
        printPurple("💡 힌트: " + quiz.hint + "\n");
        
        for (size_t i = 0; i < quiz.options.size(); ++i) {
            cout << (i + 1) << ". " << quiz.options[i] << endl;
        }
        
        int userChoice;
        cout << "\n답을 선택하세요 (1-" << quiz.options.size() << "): ";
        cin >> userChoice;
        
        if (userChoice == quiz.correctIndex + 1) {
            quizMaster.display(Emotion::HAPPY);
            printBlue("[" + quizMaster.getName() + "]: ");
            cout << "정답입니다! 🎉\n";
            score++;
        } else {
            quizMaster.display(Emotion::SAD);
            printBlue("[" + quizMaster.getName() + "]: ");
            cout << "틀렸어요. 정답은 " << (quiz.correctIndex + 1) << "번입니다.\n";
        }
        
        printGreen("📚 설명: " + quiz.explanation + "\n");
        totalQuestions++;
        
        pressEnterToContinue(quizMaster, "happy", "다음 문제로 넘어가요!");
    }
}

// 학습 통계 출력 함수
void showLearningStatistics(const UserQuizData& userData) {
    cout << "\n" << string(50, '=') << endl;
    printYellow("📊 학습 통계\n");
    cout << string(50, '=') << endl;
    
    cout << "👤 사용자: " << userData.username << endl;
    cout << "📅 마지막 퀴즈 날짜: " << userData.lastQuizDate << endl;
    cout << endl;
    
    if (userData.totalReviewQuestions > 0) {
        double reviewPercentage = (static_cast<double>(userData.reviewQuizScore) / userData.totalReviewQuestions) * 100.0;
        cout << "📚 복습 퀴즈: " << userData.reviewQuizScore << "/" << userData.totalReviewQuestions << " (" << reviewPercentage << "%)" << endl;
    }
    
    if (userData.totalFinalQuestions > 0) {
        double finalPercentage = (static_cast<double>(userData.finalQuizScore) / userData.totalFinalQuestions) * 100.0;
        cout << "🎯 최종 점검: " << userData.finalQuizScore << "/" << userData.totalFinalQuestions << " (" << finalPercentage << "%)" << endl;
    }
    
    if (userData.totalPracticeQuestions > 0) {
        double practicePercentage = (static_cast<double>(userData.practiceQuizScore) / userData.totalPracticeQuestions) * 100.0;
        cout << "💻 연습 퀴즈: " << userData.practiceQuizScore << "/" << userData.totalPracticeQuestions << " (" << practicePercentage << "%)" << endl;
    }
    
    cout << endl;
    cout << "✅ 완료한 카테고리: ";
    for (const auto& category : userData.completedCategories) {
        cout << category << " ";
    }
    cout << endl;
}

// 메인 함수
int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    
    cout << "🐾 ==========================================" << endl;
    cout << "🐾   C++ While Loop 퀴즈 프로그램" << endl;
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
    
    // 퀴즈 마스터 캐릭터 선택 (고양이)
    Character quizMaster;
    for (const auto& chara : all_characters) {
        if (chara.getSpecies() == Species::CAT) {
            quizMaster = chara;
            break;
        }
    }
    
    cout << "\n🎮 주인공: " << student.getName() << " (" << student.getRole() << ")" << endl;
    cout << "🎓 퀴즈 마스터: " << quizMaster.getName() << " (" << quizMaster.getRole() << ")" << endl;
    
    student.display(Emotion::HAPPY);
    printCyan("[" + student.getName() + "]: ");
    cout << "안녕하세요! 퀴즈를 풀고 싶어요! 🐕\n";
    
    // 사용자 이름 입력
    string username;
    cout << "\n이름을 입력해주세요: ";
    getline(cin, username);
    
    // 사용자 데이터 로드
    UserQuizData userData = loadUserQuizData(username);
    userData.username = username;
    
    // 퀴즈 데이터 로드
    vector<QuizQuestion> reviewQuizzes = buildReviewQuizzes();
    vector<QuizQuestion> whileLoopQuizzes = buildWhileLoopQuizzes();
    vector<QuizQuestion> practiceQuizzes = buildPracticeQuizzes();
    
    // 퀴즈 선택 메뉴
    while (true) {
        cout << "\n" << string(50, '=') << endl;
        printYellow("📝 퀴즈 선택 메뉴\n");
        cout << string(50, '=') << endl;
        cout << "1. 📚 복습 퀴즈 (기존 학습 내용)" << endl;
        cout << "2. 🎯 최종 점검 퀴즈 (While Loop)" << endl;
        cout << "3. 💻 연습 퀴즈 (While Loop 응용)" << endl;
        cout << "4. 📊 학습 통계 보기" << endl;
        cout << "5. 🚪 종료" << endl;
        
        int choice;
        cout << "\n선택하세요 (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                conductQuiz(quizMaster, student, reviewQuizzes, userData, QuizType::REVIEW_QUIZ);
                break;
            case 2:
                conductQuiz(quizMaster, student, whileLoopQuizzes, userData, QuizType::FINAL_QUIZ);
                break;
            case 3:
                conductQuiz(quizMaster, student, practiceQuizzes, userData, QuizType::PRACTICE_QUIZ);
                break;
            case 4:
                showLearningStatistics(userData);
                break;
            case 5:
                goto exit_program;
            default:
                cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
        }
        
        // 사용자 데이터 저장
        saveUserQuizData(userData);
    }
    
exit_program:
    // 프로그램 종료
    cout << "\n" << string(50, '=') << endl;
    printGreen("🎉 퀴즈 프로그램을 종료합니다! 🎉\n");
    cout << string(50, '=') << endl;
    
    student.display(Emotion::HAPPY);
    printCyan("[" + student.getName() + "]: ");
    cout << "퀴즈 재미있었어요! 다음에 또 만나요! 🐕\n";
    
    quizMaster.display(Emotion::HAPPY);
    printBlue("[" + quizMaster.getName() + "]: ");
    cout << "열심히 공부하세요! 🐱\n";
    
    return 0;
} 