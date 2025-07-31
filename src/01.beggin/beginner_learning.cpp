#include "../core/Character.h"
#include "../core/QuizSystem.h"
#include "../core/LearningModule.h"
#include "../core/Utils.h"
#include <iostream>
#include <string>
#include <vector>

using namespace learning;

class BeginnerLearningProgram {
private:
    Character teacher;
    Character student;
    QuizSystem quiz;
    VariableModule variableModule;
    InputModule inputModule;
    OperatorModule operatorModule;
    
public:
    BeginnerLearningProgram() {
        // 캐릭터 초기화
        teacher = Character::createChihuahua("치치", "선생님");
        student = Character::createHumanLiki("리키", "학생");
        
        // 기본 퀴즈 설정
        setupBasicQuizzes();
    }
    
    void run() {
        OutputUtils::printHeader("C++ 기초 학습 프로그램", '=');
        OutputUtils::printColored("치치 선생님과 함께 C++ 기초를 배워봅시다!", "green");
        std::cout << std::endl;
        
        // 1단계: Hello World
        lessonHelloWorld();
        
        // 2단계: 네임스페이스
        lessonNamespace();
        
        // 3단계: 함수와 유틸리티
        lessonFunctions();
        
        // 4단계: 퀴즈
        runQuiz();
        
        // 5단계: 마무리
        finishLesson();
    }
    
private:
    void setupBasicQuizzes() {
        // Hello World 퀴즈
        QuizQuestion q1("C++에서 'Hello, World!'를 출력하는 올바른 코드는?", 
                       {"cout << \"Hello, World!\";", 
                        "printf(\"Hello, World!\");", 
                        "System.out.println(\"Hello, World!\");", 
                        "print(\"Hello, World!\")"}, 0, "기초", "출력", 10);
        quiz.addQuestion(q1);
        
        // 네임스페이스 퀴즈
        QuizQuestion q2("std 네임스페이스의 의미는?", 
                       {"Standard Library", "String Data", "System Tools", "Simple Type"}, 0, "기초", "네임스페이스", 10);
        quiz.addQuestion(q2);
        
        // 함수 퀴즈
        QuizQuestion q3("C++에서 함수를 선언할 때 필요한 것은?", 
                       {"함수 이름과 매개변수", "함수 이름만", "매개변수만", "아무것도 필요없음"}, 0, "기초", "함수", 10);
        quiz.addQuestion(q3);
    }
    
    void lessonHelloWorld() {
        OutputUtils::printSubHeader("1단계: Hello, World!", '-');
        
        teacher.display(Emotion::HAPPY);
        teacher.displayWithMessage(Emotion::HAPPY, "안녕하세요! C++ 기초 학습을 시작해볼까요?");
        
        std::cout << "\n" << StringUtils::center("첫 번째 프로그램: Hello, World!", 50) << std::endl;
        std::cout << "┌─────────────────────────────────────────────────┐" << std::endl;
        std::cout << "│ #include <iostream>                           │" << std::endl;
        std::cout << "│                                                │" << std::endl;
        std::cout << "│ int main() {                                  │" << std::endl;
        std::cout << "│     std::cout << \"Hello, World!\" << std::endl; │" << std::endl;
        std::cout << "│     return 0;                                 │" << std::endl;
        std::cout << "│ }                                             │" << std::endl;
        std::cout << "└─────────────────────────────────────────────────┘" << std::endl;
        
        teacher.displayWithMessage(Emotion::EXCITED, "이 코드는 화면에 'Hello, World!'를 출력합니다!");
        
        // 실습
        std::cout << "\n" << StringUtils::center("실습: 코드를 직접 실행해보세요!", 50) << std::endl;
        std::cout << "1. 위의 코드를 복사해서 새 파일에 붙여넣기" << std::endl;
        std::cout << "2. 파일을 'hello.cpp'로 저장" << std::endl;
        std::cout << "3. 터미널에서 'g++ hello.cpp -o hello' 실행" << std::endl;
        std::cout << "4. './hello' 또는 'hello.exe' 실행" << std::endl;
        
        InputUtils::getStringInput("준비가 되면 Enter를 누르세요...");
        
        teacher.displayWithMessage(Emotion::PROUD, "훌륭합니다! 첫 번째 C++ 프로그램을 완성했어요!");
    }
    
    void lessonNamespace() {
        OutputUtils::printSubHeader("2단계: 네임스페이스 (Namespace)", '-');
        
        teacher.display(Emotion::THINKING);
        teacher.displayWithMessage(Emotion::THINKING, "이제 네임스페이스에 대해 배워볼까요?");
        
        std::cout << "\n" << StringUtils::center("네임스페이스란?", 50) << std::endl;
        std::cout << "• 코드의 이름 충돌을 방지하는 방법" << std::endl;
        std::cout << "• std는 'Standard'의 줄임말" << std::endl;
        std::cout << "• C++ 표준 라이브러리의 모든 기능이 std 안에 있음" << std::endl;
        
        std::cout << "\n" << StringUtils::center("네임스페이스 사용법", 50) << std::endl;
        std::cout << "┌─────────────────────────────────────────────────┐" << std::endl;
        std::cout << "│ // 방법 1: std:: 사용                        │" << std::endl;
        std::cout << "│ std::cout << \"Hello\" << std::endl;           │" << std::endl;
        std::cout << "│                                                │" << std::endl;
        std::cout << "│ // 방법 2: using namespace std;               │" << std::endl;
        std::cout << "│ using namespace std;                          │" << std::endl;
        std::cout << "│ cout << \"Hello\" << endl;                    │" << std::endl;
        std::cout << "└─────────────────────────────────────────────────┘" << std::endl;
        
        teacher.displayWithMessage(Emotion::EXCITED, "std 네임스페이스는 C++의 핵심이에요!");
        
        // 실습
        std::cout << "\n" << StringUtils::center("실습: 네임스페이스 사용하기", 50) << std::endl;
        std::cout << "두 가지 방법으로 같은 결과를 출력해보세요:" << std::endl;
        std::cout << "1. std::cout 사용" << std::endl;
        std::cout << "2. using namespace std; 사용" << std::endl;
        
        InputUtils::getStringInput("준비가 되면 Enter를 누르세요...");
    }
    
    void lessonFunctions() {
        OutputUtils::printSubHeader("3단계: 함수와 유틸리티", '-');
        
        teacher.display(Emotion::HAPPY);
        teacher.displayWithMessage(Emotion::HAPPY, "이제 함수를 만들어보겠습니다!");
        
        std::cout << "\n" << StringUtils::center("함수 만들기", 50) << std::endl;
        std::cout << "┌─────────────────────────────────────────────────┐" << std::endl;
        std::cout << "│ #include <iostream>                           │" << std::endl;
        std::cout << "│ #include <string>                             │" << std::endl;
        std::cout << "│                                                │" << std::endl;
        std::cout << "│ void greet(const std::string& name) {         │" << std::endl;
        std::cout << "│     std::cout << \"Hi, \" << name << \"!\" << std::endl; │" << std::endl;
        std::cout << "│ }                                             │" << std::endl;
        std::cout << "│                                                │" << std::endl;
        std::cout << "│ int main() {                                  │" << std::endl;
        std::cout << "│     greet(\"리키\");                          │" << std::endl;
        std::cout << "│     return 0;                                 │" << std::endl;
        std::cout << "│ }                                             │" << std::endl;
        std::cout << "└─────────────────────────────────────────────────┘" << std::endl;
        
        // 실제 함수 실행
        std::cout << "\n" << StringUtils::center("실제 함수 실행 결과", 50) << std::endl;
        greet("리키");
        
        teacher.displayWithMessage(Emotion::PROUD, "함수를 만들고 사용하는 방법을 배웠어요!");
    }
    
    void runQuiz() {
        OutputUtils::printSubHeader("4단계: 퀴즈 시간!", '-');
        
        teacher.display(Emotion::EXCITED);
        teacher.displayWithMessage(Emotion::EXCITED, "이제 배운 내용을 퀴즈로 확인해볼까요?");
        
        std::cout << "\n총 " << quiz.getTotalQuestions() << "개의 문제가 있습니다." << std::endl;
        std::cout << "각 문제당 10점입니다." << std::endl;
        
        quiz.startQuiz();
        
        while (quiz.hasMoreQuestions()) {
            QuizQuestion currentQuestion = quiz.getCurrentQuestion();
            
            std::cout << "\n" << StringUtils::center("문제 " + std::to_string(quiz.getCurrentQuestionIndex() + 1), 50) << std::endl;
            std::cout << currentQuestion.getQuestion() << std::endl;
            
            const std::vector<std::string>& options = currentQuestion.getOptions();
            for (size_t i = 0; i < options.size(); ++i) {
                std::cout << (i + 1) << ". " << options[i] << std::endl;
            }
            
            int answer = InputUtils::getIntInput("답을 선택하세요 (1-" + std::to_string(options.size()) + "): ", 1, options.size());
            
            bool isCorrect = quiz.submitAnswer(answer - 1);
            
            if (isCorrect) {
                teacher.display(Emotion::HAPPY);
                teacher.displayWithMessage(Emotion::HAPPY, "정답입니다! 훌륭해요!");
                OutputUtils::printSuccess("✓ 정답!");
            } else {
                teacher.display(Emotion::SAD);
                teacher.displayWithMessage(Emotion::SAD, "틀렸어요. 다시 한번 생각해보세요.");
                OutputUtils::printError("✗ 오답!");
            }
        }
        
        // 결과 출력
        QuizResult result = quiz.getFinalResult();
        std::cout << "\n" << StringUtils::center("퀴즈 결과", 50) << std::endl;
        std::cout << "점수: " << result.getScore() << "/" << result.getTotalQuestions() << std::endl;
        std::cout << "정답률: " << result.getPercentage() << "%" << std::endl;
        std::cout << "메시지: " << result.getResultMessage() << std::endl;
        
        if (result.getPercentage() >= 80) {
            teacher.display(Emotion::EXCITED);
            teacher.displayWithMessage(Emotion::EXCITED, "완벽합니다! C++ 기초를 잘 이해하고 있어요!");
        } else if (result.getPercentage() >= 60) {
            teacher.display(Emotion::HAPPY);
            teacher.displayWithMessage(Emotion::HAPPY, "좋습니다! 조금 더 연습하면 더 좋아질 거예요!");
        } else {
            teacher.display(Emotion::THINKING);
            teacher.displayWithMessage(Emotion::THINKING, "괜찮아요! 처음이니까 천천히 다시 배워봐요!");
        }
    }
    
    void finishLesson() {
        OutputUtils::printSubHeader("5단계: 수업 마무리", '-');
        
        teacher.display(Emotion::PROUD);
        teacher.displayWithMessage(Emotion::PROUD, "오늘 C++ 기초를 잘 배웠어요!");
        
        std::cout << "\n" << StringUtils::center("오늘 배운 내용", 50) << std::endl;
        std::cout << "✓ Hello, World! 프로그램 만들기" << std::endl;
        std::cout << "✓ 네임스페이스 이해하기" << std::endl;
        std::cout << "✓ 함수 만들고 사용하기" << std::endl;
        std::cout << "✓ 기본 문법 습득하기" << std::endl;
        
        std::cout << "\n" << StringUtils::center("다음 수업 예고", 50) << std::endl;
        std::cout << "다음에는 변수, 데이터 타입, 연산자에 대해 배워볼 거예요!" << std::endl;
        
        teacher.displayWithMessage(Emotion::HAPPY, "수고했어요! 다음에 또 만나요!");
        
        OutputUtils::printHeader("C++ 기초 학습 완료!", '=');
    }
    
    void greet(const std::string& name) {
        std::cout << "Hi, " << name << "! (from function)" << std::endl;
    }
};

int main() {
    BeginnerLearningProgram program;
    program.run();
    return 0;
} 