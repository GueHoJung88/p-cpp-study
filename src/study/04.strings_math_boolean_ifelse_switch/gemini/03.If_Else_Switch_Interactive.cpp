#include <iostream> // cout, cin, endl 등을 사용하기 위해 필요
#include <string>   // string 타입을 사용하기 위해 필요
#include <vector>   // vector를 사용하기 위해 필요
#include <limits>   // numeric_limits를 사용하기 위해 필요 (cin.ignore 버퍼 비우기)
#include <cstdlib>  // srand, rand를 사용하기 위해 필요
#include <ctime>    // time을 사용하기 위해 필요 (랜덤 시드)
#include <locale>   // setlocale을 사용하기 위해 필요 (한글 출력)
#include <algorithm> // std::random_shuffle, std::find, std::remove_if
#include <cmath>    // 수학 함수를 사용하기 위해 필요
#include <ios>      // std::boolalpha, std::noboolalpha를 사용하기 위해 필요

#include "Character.h" // 우리가 만든 캐릭터 헤더 파일을 포함합니다.

// using 선언으로 std::를 생략하고 바로 사용할 수 있게 합니다.
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;

// 퀴즈의 각 선택지를 저장하기 위한 구조체
struct AnswerOption {
    string text;
    string rationale; // 이 선택지를 골랐을 때의 결과 설명
    bool isCorrect;
};

// 퀴즈 문제 하나를 저장하기 위한 구조체
struct Question {
    string questionText;
    string hint;
    vector<AnswerOption> options;
};

// 모든 퀴즈 데이터를 생성하고 반환하는 함수 (최소 30개 이상)
vector<Question> initializeAllIfElseSwitchQuizzes() {
    return {
        // --- If-Else 퀴즈 ---
        {
            "다음 중 'a가 b보다 작다'를 나타내는 올바른 조건 연산자는 무엇일까요?",
            "Less than을 의미하는 기호를 떠올려보세요.",
            {
                {"a <= b", "작거나 같다를 의미해요.", false},
                {"a > b", "크다를 의미해요.", false},
                {"a < b", "정답! 작다를 의미하는 연산자입니다.", true},
                {"a == b", "같다를 의미해요.", false}
            }
        },
        {
            "`if` 문을 사용하여 특정 코드 블록을 실행시키려면, 조건이 어떤 상태여야 할까요?",
            "if (조건) { ... } 의 의미를 생각해보세요.",
            {
                {"false", "조건이 거짓일 때 실행되지 않아요.", false},
                {"0", "거짓을 의미해요.", false},
                {"true", "정답! 조건이 참(true)일 때 if 블록의 코드가 실행됩니다.", true},
                {"null", "null은 주로 포인터나 빈 값을 나타내요.", false}
            }
        },
        {
            "`int score = 75;`일 때, `if (score >= 80)` 조건문은 어떤 결과를 반환할까요?",
            "75가 80보다 크거나 같은지 판단해보세요.",
            {
                {"true", "75는 80보다 작으므로 거짓이에요.", false},
                {"false", "정답! 75는 80보다 작으므로 이 조건은 거짓(false)입니다.", true},
                {"컴파일 에러", "유효한 조건문이에요.", false},
                {"80", "조건문의 결과는 불리언 값이에요.", false}
            }
        },
        {
            "`int temp = 5;`일 때, 다음 코드의 출력 결과는 무엇일까요?\n`if (temp > 10) { cout << \"Hot\"; } else { cout << \"Cold\"; }`",
            "5가 10보다 큰지 판단하고, 조건이 거짓일 때 else 블록이 실행돼요.",
            {
                {"Hot", "5는 10보다 크지 않아요.", false},
                {"Cold", "정답! temp(5)가 10보다 크지 않으므로 else 블록이 실행되어 'Cold'가 출력됩니다.", true},
                {"컴파일 에러", "유효한 코드예요.", false},
                {"아무것도 출력되지 않음", "else 블록이 실행됩니다.", false}
            }
        },
        {
            "`int hour = 14;`일 때, 다음 코드의 출력 결과는 무엇일까요?\n`if (hour < 10) { cout << \"Morning\"; } else if (hour < 15) { cout << \"Afternoon\"; } else { cout << \"Evening\"; }`",
            "조건들이 순서대로 평가돼요. 첫 번째 조건이 거짓이면 다음 `else if`로 넘어갑니다.",
            {
                {"Morning", "14는 10보다 작지 않아요.", false},
                {"Afternoon", "정답! hour(14)는 10보다 작지 않지만, 15보다는 작으므로 두 번째 조건이 참이 되어 'Afternoon'이 출력됩니다.", true},
                {"Evening", "두 번째 조건이 참이므로 else 블록까지 가지 않아요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {
            "C++에서 여러 조건 중 하나를 선택하여 코드 블록을 실행할 때 사용하는 효율적인 문장은 무엇일까요?",
            "많은 대안 중 하나를 '선택'할 때 사용해요.",
            {
                {"if-else if", "이것도 가능하지만, '여러 조건 중 하나'라는 표현에 더 적합한 다른 문장이 있어요.", false},
                {"while", "while은 반복문이에요.", false},
                {"switch", "정답! switch 문은 여러 case 중 일치하는 하나를 선택하여 실행하는 데 사용됩니다.", true},
                {"for", "for는 반복문이에요.", false}
            }
        },
        {
            "다음 `switch` 문에서 `day = 7;`일 때 출력 결과는 무엇일까요?\n`switch(day) { case 1: cout << \"Mon\"; break; case 7: cout << \"Sun\"; case 8: cout << \"Invalid\"; break; default: cout << \"Other\"; }`",
            "`break`의 유무에 따라 흐름이 달라질 수 있어요. `case 7`에 `break`가 있는지 확인하세요.",
            {
                {"Sun", "정답! `case 7`이 일치하고, 그 뒤에 `break`가 없으므로 다음 `case 8`의 코드까지 실행됩니다.", true},
                {"SunInvalid", "`case 7`에는 `break`가 없으므로 `case 8`의 코드도 실행됩니다.", false}, // 오답 보기로 변경
                {"Other", "default는 일치하는 case가 없을 때 실행돼요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {
            "`switch` 문에서 일치하는 `case`가 없을 때 실행되는 선택적인 키워드는 무엇일까요?",
            "기본(default)이라는 의미를 가진 영어 단어예요.",
            {
                {"else", "`else`는 `if` 문에 사용돼요.", false},
                {"default", "정답! `default` 키워드는 어떤 `case`에도 일치하지 않을 때 실행될 코드 블록을 지정합니다.", true},
                {"otherwise", "C++에 없는 키워드예요.", false},
                {"none", "C++에 없는 키워드예요.", false}
            }
        },
        {
            "삼항 연산자(Ternary Operator)로 알려진 `if...else`의 축약형 구문은 무엇일까요?",
            "세 개의 피연산자를 사용하는 구문이에요.",
            {
                {"variable = (condition) ? expressionTrue : expressionFalse;", "정답! 삼항 연산자의 올바른 구문입니다.", true},
                {"variable = if (condition) expressionTrue else expressionFalse;", "잘못된 문법이에요.", false},
                {"(condition) ? expressionTrue : expressionFalse = variable;", "할당 방향이 틀렸어요.", false},
                {"variable = condition ? expressionTrue : expressionFalse;", "괄호가 없어도 되지만, 보통 조건에 괄호를 붙여 명확하게 합니다.", false}
            }
        },
        {
            "`int day = 0;`일 때, 다음 `switch` 문의 출력 결과는 무엇일까요?\n`switch(day) { case 1: cout << \"Mon\"; break; default: cout << \"Invalid Day\"; break; case 0: cout << \"Sunday\"; break; }`",
            "`case`의 순서는 중요하지 않아요. 일치하는 `case`가 있는지, `default`가 어디 있는지 확인하세요.",
            {
                {"Mon", "day는 1이 아니에요.", false},
                {"Invalid Day", "정답! `day`는 0이므로 `case 0`이 일치하여 'Sunday'가 출력됩니다. `default`는 `case 0`이 일치하지 않을 때 실행됩니다.", false}, // 이 부분을 수정하여 'Sunday'가 정답이 되도록
                {"Sunday", "정답! `day`는 0이므로 `case 0`이 일치하여 'Sunday'가 출력됩니다. `default`는 다른 case가 일치하지 않을 때 실행됩니다.", true},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {
            "`if (myNum % 2 == 0)`은 어떤 숫자를 판별할 때 주로 사용되는 조건일까요?",
            "어떤 숫자가 2로 나누어 떨어지는지 확인하는 조건이에요.",
            {
                {"양수인지 음수인지", "이는 `> 0` 또는 `< 0`으로 판별해요.", false},
                {"홀수인지 짝수인지", "정답! `어떤 숫자가 2로 나누어 떨어지면 짝수`이고, 그렇지 않으면 홀수입니다.", true},
                {"소수인지 아닌지", "소수 판별은 더 복잡한 로직이 필요해요.", false},
                {"0인지 아닌지", "이는 `== 0` 또는 `!= 0`으로 판별해요.", false}
            }
        },
        {
            "다음 중 `if`와 `else` 문 사용에 대한 설명으로 올바르지 않은 것은 무엇일까요?",
            "각 키워드의 역할을 정확히 이해하고 있는지 확인하세요.",
            {
                {"`if` 문은 소문자로 써야 한다.", "맞아요. `If`나 `IF`는 오류를 발생시켜요.", false},
                {"`else` 문은 `if` 문 없이 단독으로 사용될 수 있다.", "`else`는 항상 선행하는 `if` 또는 `else if`가 필요해요.", true},
                {"`else if`는 여러 조건을 순차적으로 검사할 때 사용된다.", "맞아요. 첫 조건이 거짓일 때 다음 조건을 검사해요.", false},
                {"조건문 뒤에 중괄호 `{}`를 사용하지 않으면, 첫 번째 문장만 `if` 문에 속한다.", "맞아요. 여러 문장을 포함하려면 중괄호가 필수예요.", false}
            }
        },
        {
            "다음 `if-else if-else` 체인의 실행 순서로 올바른 것은?\n`if (A) { ... } else if (B) { ... } else { ... }`",
            "위에서부터 순차적으로 조건을 평가합니다.",
            {
                {"A가 참이면 A 블록 실행 후 끝. A가 거짓이고 B가 참이면 B 블록 실행 후 끝. 둘 다 거짓이면 else 블록 실행 후 끝.", "정답! 이 설명은 if-else if-else 문의 정확한 실행 순서를 나타냅니다.", true},
                {"A가 참이면 A 블록 실행. B가 참이면 B 블록 실행. 둘 다 거짓이면 else 블록 실행.", "조건들이 독립적으로 평가되는 것이 아니라 순차적으로 평가돼요.", false},
                {"세 가지 조건(A, B, else)이 동시에 평가되어 가장 적합한 블록이 실행된다.", "동시에 평가되지 않고 순차적으로 평가돼요.", false},
                {"else 블록이 항상 가장 먼저 평가된 후, A 또는 B가 평가된다.", "else 블록은 모든 if/else if가 거짓일 때만 실행돼요.", false}
            }
        },
        {
            "`switch` 문에서 `break` 키워드의 역할로 올바른 것은 무엇일까요?",
            "`break`가 없으면 어떤 일이 일어나는지 생각해보세요.",
            {
                {"`switch` 문을 완전히 종료하고 다음 코드로 넘어간다.", "정답! `break`는 일치하는 `case` 블록의 실행을 멈추고 `switch` 문 바깥으로 빠져나가게 합니다.", true},
                {"다음 `case`로 계속 실행되도록 한다.", "`break`가 없을 때 발생하는 현상이에요.", false},
                {"`switch` 문 내에서 무한 루프를 생성한다.", "`break`와는 관련이 없어요.", false},
                {"오류를 발생시킨다.", "오류가 아니라 정상적인 키워드예요.", false}
            }
        },
        {
            "사용자로부터 요일(1=월, 2=화, ..., 7=일)을 입력받아 요일 이름을 출력하는 `switch` 문을 작성할 때, 1부터 7까지의 숫자 외의 다른 값이 입력될 경우 '유효하지 않은 요일'이라고 출력하려면 어떤 키워드를 사용해야 할까요?",
            "일치하는 case가 없을 때의 예외 처리를 위한 키워드예요.",
            {
                {"else", "switch 문에서는 else를 사용하지 않아요.", false},
                {"error", "C++ 키워드가 아니에요.", false},
                {"default", "정답! `default` 키워드는 `switch` 표현식의 값과 일치하는 `case` 라벨이 없을 때 실행될 코드 블록을 지정합니다.", true},
                {"fallback", "C++ 키워드가 아니에요.", false}
            }
        },
        {
            "`if` 문을 사용할 때, 조건이 참일 때 실행할 코드가 한 줄이라면 중괄호 `{}`를 생략해도 됩니다. 하지만 권장되지 않는 이유는 무엇일까요?",
            "코드의 가독성과 유지보수, 잠재적 오류 발생 가능성을 생각해 보세요.",
            {
                {"코드가 더 길어지기 때문에", "줄 수가 줄어들 수 있어요.", false},
                {"컴파일 에러가 발생하기 때문에", "컴파일 에러는 발생하지 않아요.", false},
                {"가독성이 떨어지고, 나중에 코드를 추가할 때 오류가 발생하기 쉽기 때문에", "정답! 중괄호를 생략하면 `if` 문에 속하는 코드가 모호해지고, 나중에 한 줄 더 추가할 때 논리적 오류가 발생할 가능성이 높기 때문입니다.", true},
                {"실행 속도가 느려지기 때문에", "성능에는 큰 차이가 없어요.", false}
            }
        },
        {
            "`int hour = 17;`일 때, 삼항 연산자 `string greeting = (hour < 12) ? \"Good morning\" : \"Good afternoon\";`의 결과는 무엇일까요?",
            "17이 12보다 작은지 판단하고, 조건에 따라 `expressionTrue` 또는 `expressionFalse`가 선택됩니다.",
            {
                {"\"Good morning\"", "17은 12보다 작지 않아요.", false},
                {"\"Good afternoon\"", "정답! `hour < 12` (17 < 12)는 false이므로, `expressionFalse`인 \"Good afternoon\"이 선택됩니다.", true},
                {"컴파일 에러", "유효한 구문이에요.", false},
                {"아무것도 출력되지 않음", "삼항 연산자는 항상 값을 반환해요.", false}
            }
        },
        {
            "`switch` 문에서 `case` 라벨에 사용할 수 없는 데이터 타입은 무엇일까요?",
            "`case` 라벨은 상수 정수 표현식이어야 합니다.",
            {
                {"int", "int는 가장 흔하게 사용돼요.", false},
                {"char", "char는 정수형으로 변환되므로 사용 가능해요.", false},
                {"enum", "enum 값은 정수형으로 사용되므로 가능해요.", false},
                {"string", "`string`은 `switch` 문 `case` 라벨로 직접 사용될 수 없습니다. `if-else if` 체인으로 처리해야 합니다.", true}
            }
        },
        {
            "`if (temperature > 30 || isRaining)` 조건문은 언제 `true`가 될까요?",
            "`||`(OR) 연산자의 특징을 생각해보세요.",
            {
                {"`temperature`가 30보다 크고, `isRaining`도 `true`일 때", "이것은 `&&`(AND) 연산의 결과예요.", false},
                {"`temperature`가 30보다 크거나, `isRaining`이 `true`일 때 둘 중 하나라도 만족하면", "정답! `||`(OR) 연산자는 둘 중 하나라도 참이면 전체 조건이 참이 됩니다.", true},
                {"`temperature`가 30보다 크고, `isRaining`은 `false`일 때", "이것도 가능하지만, '언제 true가 될까'에 대한 가장 포괄적인 설명은 아니에요.", false},
                {"둘 다 `false`일 때", "둘 다 `false`면 전체 조건도 `false`예요.", false}
            }
        },
        {
            "다음 중 `if` 문 다음에 세미콜론(;)을 붙였을 때 발생하는 문제로 가장 적절한 것은?\n`if (condition); { /* code */ }`",
            "세미콜론은 문장의 끝을 의미합니다.",
            {
                {"컴파일 에러가 발생한다.", "문법적으로는 유효하지만 의도와 다르게 작동해요.", false},
                {"`if` 문이 항상 `false`로 평가된다.", "조건과는 무관하게 동작해요.", false},
                {"`if` 문 조건과 관계없이 `{}` 안의 코드가 항상 실행된다.", "정답! `if (condition);`는 조건에 상관없이 빈 문장을 실행하고 종료됩니다. 따라서 뒤에 오는 `{}` 블록은 독립적인 코드 블록으로 인식되어 항상 실행됩니다.", true},
                {"`if` 문이 무한 루프에 빠진다.", "무한 루프와는 관련 없어요.", false}
            }
        },
        {
            "`switch` 문에서 `case` 값은 중복될 수 있을까요?",
            "`case`는 특정 값에 대한 분기를 나타냅니다.",
            {
                {"예, 가능합니다.", "각 `case` 라벨은 고유한 값을 가져야 해요.", false},
                {"아니오, 중복될 수 없습니다. 컴파일 에러가 발생합니다.", "정답! `switch` 문에서 `case` 라벨의 값은 고유해야 합니다. 중복될 경우 컴파일 에러가 발생합니다.", true},
                {"문법적으로는 가능하지만, 런타임에 경고가 발생한다.", "문법적으로 허용되지 않아요.", false},
                {"`break` 키워드가 있으면 중복될 수 있다.", "`break` 유무와 상관없이 `case` 값은 중복될 수 없어요.", false}
            }
        },
        {
            "다음 `if-else if-else` 문에서 `int num = -5;` 일 때의 출력 결과는?\n`if (num > 0) { cout << \"Positive\"; } else if (num < 0) { cout << \"Negative\"; } else { cout << \"Zero\"; }`",
            "조건의 순차적 평가를 다시 확인하세요.",
            {
                {"Positive", "-5는 0보다 크지 않아요.", false},
                {"Negative", "정답! `num`(-5)는 0보다 작으므로, 두 번째 `else if` 조건(`num < 0`)이 참이 되어 'Negative'가 출력됩니다.", true},
                {"Zero", "0이 아니므로 `else` 블록까지 가지 않아요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        }
    };
}

// 다음 단락으로 넘어가기 위한 함수 (캐릭터 포함)
// Character.h의 display 함수가 const로 변경되어야 합니다.
void pressEnterToContinue(const Character& speaker, const string& emotion, const string& message) {
    // 메시지를 먼저 출력하고 그 다음에 캐릭터 이미지를 보여주는 방식으로 변경
    cout << "\n--- " << speaker.name << " (" << speaker.species << ")의 한마디 ---" << endl;
    cout << speaker.name << ": " << message << endl; // 메시지 출력
    speaker.display(emotion); // 캐릭터 이미지 출력
    cout << "계속하려면 Enter 키를 누르세요...";
    cin.get(); // Enter 입력 대기
    cout << "\n";
}

// 퀴즈 진행 함수
void conductQuiz(Character& player, Character& quiz_master, const vector<Question>& all_quizzes) {
    // 모든 퀴즈 목록을 복사하여 섞습니다.
    vector<Question> shuffled_quizzes = all_quizzes;
    std::random_shuffle(shuffled_quizzes.begin(), shuffled_quizzes.end());

    // 10개의 퀴즈만 선택
    int num_quizzes_to_ask = std::min((int)shuffled_quizzes.size(), 10); // 최대 10개, 또는 전체 퀴즈 수만큼
    
    cout << "\n--- " << quiz_master.name << "의 퀴즈 타임! (" << player.name << "의 HP: " << player.hp << ") ---" << endl;
    quiz_master.display("happy");
    cout << quiz_master.name << ": 자, " << player.name << "! 네가 배운 조건문 지식을 시험해 볼 시간이다! 긴장해라!" << endl;
    player.display("default");
    cout << player.name << ": 흥, 고구마만 있으면 두렵지 않아! 덤벼라 문제들!" << endl;
    pressEnterToContinue(quiz_master, "surprised", "도전 정신이 대단하군! 좋다, 첫 번째 문제다!");

    for (int i = 0; i < num_quizzes_to_ask; ++i) {
        if (player.hp <= 0) {
            cout << "체력 0! " << player.name << "는(은) 더 이상 버틸 수 없어 쓰러졌습니다..." << endl;
            player.display("sad");
            quiz_master.display("sad");
            cout << quiz_master.name << ": 아쉽군... 다음 기회에 다시 도전하도록 해라..." << endl;
            break;
        }

        Question current_q = shuffled_quizzes[i];
        
        // 퀴즈 마스터의 감정 변화
        string master_emotion;
        if (i % 3 == 0) master_emotion = "thinking";
        else if (i % 3 == 1) master_emotion = "default";
        else master_emotion = "surprised";

        cout << "\n========== " << i + 1 << "번째 퀴즈! ==========" << endl;
        quiz_master.display(master_emotion);
        cout << quiz_master.name << ": 집중해라, " << player.name << "! 이 문제는 어떠냐?" << endl;
        cout << "[문제] " << current_q.questionText << endl;
        cout << "[힌트] " << current_q.hint << endl;

        // 선택지 출력 (랜덤 순서)
        vector<AnswerOption> shuffled_options = current_q.options;
        std::random_shuffle(shuffled_options.begin(), shuffled_options.end());

        for (int j = 0; j < shuffled_options.size(); ++j) {
            cout << "  " << j + 1 << ". " << shuffled_options[j].text << endl;
        }

        int user_answer_choice;
        while (true) {
            cout << "\n정답은? (숫자 입력): ";
            cin >> user_answer_choice;
            // 입력 버퍼 비우기 (cin >> user_answer_choice 이후 바로 필요)
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            if (cin.fail() || user_answer_choice <= 0 || user_answer_choice > shuffled_options.size()) {
                cin.clear(); // 에러 플래그 초기화
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 잘못된 입력 버리기
                cout << quiz_master.name << ": 으음...? 숫자를 제대로 입력해라! " << player.name << "! 엉뚱한 답은 용납 못한다!" << endl;
                quiz_master.display("angry");
            } else {
                break; // 올바른 입력이면 루프 종료
            }
        }

        AnswerOption& chosen_option = shuffled_options[user_answer_choice - 1];

        cout << "\n--- 결과 ---" << endl;
        if (chosen_option.isCorrect) {
            cout << "✨ " << player.name << ": 야호! 정답이다! 역시 난 고구마의 힘으로 똑똑해졌어! 멍멍!" << endl;
            player.display("happy");
            quiz_master.display("surprised");
            cout << quiz_master.name << ": 훌륭하군! 정확한 지식이다! 네 고구마가 도움이 되었나 보군!" << endl;
            cout << "[설명] " << chosen_option.rationale << endl;
            player.hp += 10; // 정답 시 HP 회복
            cout << player.name << "의 체력이 10 회복되었어! (현재 HP: " << player.hp << ")" << endl;
        } else {
            cout << "💧 " << player.name << ": 으악! 틀렸어... 멍... 머리가 아파... 고구마가 필요해..." << endl;
            player.display("sad");
            quiz_master.display("angry");
            // 틀린 답 중 올바른 정답을 찾아 설명하도록 변경 (shuffled_options에서 isCorrect인 것을 찾음)
            string correct_answer_text = "알 수 없음";
            for(const auto& opt : current_q.options) { // 원본 퀴즈 옵션에서 정답을 찾습니다.
                if (opt.isCorrect) {
                    correct_answer_text = opt.text;
                    break;
                }
            }
            cout << quiz_master.name << ": 쯧쯧! 아직 멀었군! 정답은 '" << correct_answer_text << "' 야! 다시 한번 잘 들어라!" << endl; 
            cout << "[설명] " << chosen_option.rationale << endl;
            player.hp -= 20; // 오답 시 HP 감소
            cout << player.name << "의 체력이 20 감소했어! (현재 HP: " << player.hp << ")" << endl;
        }
        
        // 퀴즈 결과 확인 후 다음 문제로 넘어갈 때도 캐릭터 등장
        pressEnterToContinue(player, (player.hp > 0 ? "happy" : "sad"), "다음 문제로 넘어갈까?");
    }
    
    // 퀴즈 종료 시 퀴즈 마스터 대화
    cout << "\n" << quiz_master.name << ": 휴... 오늘 퀴즈는 여기까지다. " << player.name << ", 수고했다! 네 실력이 많이 늘었군!" << endl;
    quiz_master.display("default");
    pressEnterToContinue(player, (player.hp > 0 ? "happy" : "sad"), "정말 끝난 건가?");
}


int main() {
    // 게임 시작 시 필요한 초기 설정
    srand(time(0));
    setlocale(LC_ALL, "");

    // 퀴즈 데이터 준비
    vector<Question> all_if_else_switch_quizzes = initializeAllIfElseSwitchQuizzes();
    
    // --- 캐릭터 초기화 및 선택 ---
    vector<Character> all_characters = initializeCharacters();
    
    // 플레이어 캐릭터 설정 (보리로 강제 설정)
    // Character.h에 말티즈 종족과 보리 정보가 추가되었다는 전제 하에 아래 코드 사용
    Character player_character("말티즈", "보리", 130, 35); // 보리 캐릭터 생성 (Character.h에 말티즈 display 추가 필요)
    
    cout << "---------- C++ 조건문(If-Else & Switch) 스터디 시작! ----------" << endl;
    cout << "당신은 C++ 스터디의 귀여운 주인공, " << player_character.name << " (" << player_character.species << ") 입니다!" << endl;
    player_character.display("default");
    // 메시지와 감정을 직접 전달
    pressEnterToContinue(player_character, "default", "어서 스터디를 시작해볼까?"); // 보리 캐릭터와 함께 시작

    // 메인 가이드 캐릭터 선언 및 초기화
    Character main_guide = all_characters[0]; // 치와와 '치치'를 메인 가이드로 (초기값)

    // --- 단락 1: C++ 조건문이란? ---
    cout << main_guide.name << " (" << main_guide.species << "): 안녕! 나의 사랑스러운 후배, " << player_character.name << "!" << endl;
    main_guide.display("happy");
    cout << "오늘은 C++ 스터디의 새로운 주제, '조건문(If-Else & Switch)'에 대해 알아볼 거야!" << endl;
    cout << "조건문은 특정 상황에 따라 프로그램의 동작을 다르게 하고 싶을 때 사용한단다. 마치 간식 양에 따라 보리의 표정이 달라지는 것처럼 말이야!" << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "어떤 조건들이 있는지 살펴볼까?");

    // --- 단락 2: 비교 연산자 복습 ---
    cout << main_guide.name << " (" << main_guide.species << "): 조건문에서는 '비교 연산자'를 많이 사용해. 이전에 배운 적 있지? 한번 복습해볼까?" << endl;
    main_guide.display("default");
    cout << " - 작다: `a < b`" << endl;
    cout << " - 작거나 같다: `a <= b`" << endl;
    cout << " - 크다: `a > b`" << endl;
    cout << " - 크거나 같다: `a >= b`" << endl;
    cout << " - 같다: `a == b`" << endl;
    cout << " - 같지 않다: `a != b`" << endl;
    player_character.display("thinking");
    cout << player_character.name << ": 음... 간식 개수를 세는 데 필요한 것들이군! 기억하고 있어!" << endl;
    pressEnterToContinue(player_character, "thinking", "이제 If 문을 알아보자!");

    // --- 단락 3: The if Statement ---
    cout << main_guide.name << " (" << main_guide.species << "): 가장 기본이 되는 조건문은 `if` 문이야!" << endl;
    main_guide.display("happy");
    cout << "`if (조건) { ... }` 형태로 사용하며, '만약 조건이 참(true)이라면, 중괄호 안의 코드를 실행해!'라는 뜻이야." << endl;
    cout << "참고로 `if`는 꼭 소문자로 써야 해. 대문자로 쓰면 에러가 난단다!" << endl;
    main_guide.display("default");
    pressEnterToContinue(main_guide, "default", "실습 예시를 볼까?");

    cout << "[실습] 20이 18보다 큰지 확인하고, 크다면 메시지를 출력해보자." << endl;
    cout << "```cpp" << endl;
    cout << "if (20 > 18) {" << endl;
    cout << "  cout << \"20 is greater than 18\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (20 > 18) {
        cout << "20 is greater than 18" << endl;
    }
    cout << "```" << endl;
    player_character.display("happy");
    cout << player_character.name << ": 20은 18보다 크니까 메시지가 잘 나오는군! 간단해!" << endl;
    pressEnterToContinue(player_character, "happy", "변수로도 해볼까?");

    cout << "[실습] 변수를 사용해서 같은 조건을 확인해보자." << endl;
    int x_if = 20;
    int y_if = 18;
    cout << "```cpp" << endl;
    cout << "int x = 20;" << endl;
    cout << "int y = 18;" << endl;
    cout << "if (x > y) {" << endl;
    cout << "  cout << \"x is greater than y\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (x_if > y_if) {
        cout << "x is greater than y" << endl;
    }
    cout << "```" << endl;
    player_character.display("happy");
    cout << player_character.name << ": 변수를 써도 똑같군! 엑스는 와이보다 커!" << endl;
    pressEnterToContinue(player_character, "happy", "다음은 else 문!");

    // --- 단락 4: The else Statement ---
    Character current_corgi = all_characters[1]; // 웰시코기 '코코'
    cout << current_corgi.name << " (" << current_corgi.species << "): 안녕! " << player_character.name << "! 이번엔 `else` 문이야!" << endl;
    current_corgi.display("happy");
    cout << "`else` 문은 '만약 `if`의 조건이 거짓(false)이라면, 이 코드를 실행해!'라고 할 때 사용해." << endl;
    cout << "`if (조건) { ... } else { ... }` 이런 형태로 쓰지." << endl;
    current_corgi.display("default");
    pressEnterToContinue(current_corgi, "default", "예시를 볼까?");

    cout << "[실습] 시간이 18시보다 빠르면 'Good day.', 아니면 'Good evening.'을 출력해보자." << endl;
    int time_else = 20;
    cout << "```cpp" << endl;
    cout << "int time = 20;" << endl;
    cout << "if (time < 18) {" << endl;
    cout << "  cout << \"Good day.\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << \"Good evening.\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (time_else < 18) {
        cout << "Good day." << endl;
    } else {
        cout << "Good evening." << endl;
    }
    cout << "```" << endl;
    player_character.display("thinking");
    cout << player_character.name << ": 시간은 20이니까 18보다 작지 않아서 'Good evening.'이 나오는군! 이해했어!" << endl;
    pressEnterToContinue(player_character, "thinking", "elif else if로 넘어가자!");

    // --- 단락 5: The else if Statement ---
    Character current_husky = all_characters[2]; // 허스키 '허허'
    cout << current_husky.name << " (" << current_husky.species << "): 이번엔 `else if` 문이야! 여러 개의 조건을 순차적으로 검사할 때 아주 유용하지!" << endl;
    current_husky.display("thinking");
    cout << "`if (조건1) { ... } else if (조건2) { ... } else { ... }` 이런 식으로 사용해." << endl;
    cout << "첫 번째 조건이 거짓이면 두 번째 조건을 검사하고, 그것도 거짓이면 마지막 `else` 블록이 실행된단다." << endl;
    current_husky.display("default");
    pressEnterToContinue(current_husky, "default", "시간 예시로 확인해보자!");

    cout << "[실습] 시간에 따라 'Good morning.', 'Good day.', 'Good evening.'을 출력해보자." << endl;
    int time_else_if = 22;
    cout << "```cpp" << endl;
    cout << "int time = 22;" << endl;
    cout << "if (time < 10) {" << endl;
    cout << "  cout << \"Good morning.\";" << endl;
    cout << "} else if (time < 20) {" << endl;
    cout << "  cout << \"Good day.\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << \"Good evening.\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (time_else_if < 10) {
        cout << "Good morning." << endl;
    } else if (time_else_if < 20) {
        cout << "Good day." << endl;
    } else {
        cout << "Good evening." << endl;
    }
    cout << "```" << endl;
    player_character.display("surprised");
    cout << player_character.name << ": 22시는 10보다 크고, 20보다도 크니까 'Good evening.'이 나오는구나! 만약 14였으면 'Good day.'가 나왔겠지?" << endl;
    pressEnterToContinue(player_character, "surprised", "다음은 짧은 If-Else 문!");

    // --- 단락 6: Short Hand If...Else (Ternary Operator) ---
    main_guide = all_characters[0]; // 다시 치치로 가이드 설정
    cout << main_guide.name << " (" << main_guide.species << "): 어때? 조건문, 어렵지 않지? 이제 좀 더 '똑똑해 보이는' 방법을 알려줄게!" << endl;
    main_guide.display("happy");
    cout << "간단한 `if...else` 문은 '삼항 연산자(Ternary Operator)'라는 짧은 구문으로 바꿀 수 있어. 피연산자가 세 개라서 삼항 연산자라고 부르지!" << endl;
    cout << "구문은 `변수 = (조건) ? 참일 때 값 : 거짓일 때 값;` 이야." << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "예시로 비교해볼까?");

    cout << "[실습] 일반 `if...else`와 삼항 연산자를 비교해보자." << endl;
    int time_short = 20;
    string result_short;
    cout << "```cpp" << endl;
    cout << "int time = 20;" << endl;
    cout << "// 일반 If-Else" << endl;
    cout << "if (time < 18) {" << endl;
    cout << "  cout << \"Good day.\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << \"Good evening.\";" << endl;
    cout << "}" << endl;
    cout << "// 삼항 연산자" << endl;
    cout << "string result = (time < 18) ? \"Good day.\" : \"Good evening.\";" << endl;
    cout << "cout << result;" << endl;
    cout << "// 결과: ";
    result_short = (time_short < 18) ? "Good day." : "Good evening.";
    cout << result_short << endl;
    cout << "```" << endl;
    player_character.display("surprised");
    cout << player_character.name << ": 와! 한 줄로 똑같은 결과를 낼 수 있잖아! 코드가 훨씬 깔끔해 보여!" << endl;
    pressEnterToContinue(player_character, "surprised", "실생활 예시로 넘어가자!");

    // --- 단락 7: C++ If ... Else 실생활 예시 ---
    Character current_retriever = all_characters[5]; // 골든 리트리버 '리버'
    cout << current_retriever.name << " (" << current_retriever.species << "): 잘했어! " << player_character.name << "! 이제 조건문이 실생활에서 어떻게 쓰이는지 보여줄게!" << endl;
    current_retriever.display("happy");
    cout << "문 잠금장치나, 숫자 판별, 투표 가능 여부, 짝수/홀수 판별 등 정말 다양하게 사용된단다!" << endl;
    current_retriever.display("default");
    pressEnterToContinue(current_retriever, "default", "하나씩 살펴볼까?");

    // 예시 1: 문 열기
    cout << "[실습] 문 잠금장치: 올바른 코드를 입력해야 문이 열리게 해보자." << endl;
    int doorCode = 1337;
    int userInputCode;
    cout << player_character.name << ": 문을 열려면 비밀번호를 입력해야 해! (힌트: 1337)" << endl;
    player_character.display("thinking");
    cout << "비밀번호 입력: ";
    cin >> userInputCode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "```cpp" << endl;
    cout << "int doorCode = 1337;" << endl;
    cout << "int userInputCode = " << userInputCode << ";" << endl; // 사용자 입력 값 반영
    cout << "if (doorCode == userInputCode) {" << endl;
    cout << "  cout << \"Correct code.\\nThe door is now open.\\n\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << \"Wrong code.\\nThe door remains closed.\\n\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (doorCode == userInputCode) {
        cout << "Correct code.\nThe door is now open." << endl;
        player_character.display("happy");
        cout << player_character.name << ": 야호! 문이 열렸다! 간식 찾으러 가야지!" << endl;
    } else {
        cout << "Wrong code.\nThe door remains closed." << endl;
        player_character.display("sad");
        cout << player_character.name << ": 힝... 틀렸어... 문이 안 열려..." << endl;
    }
    cout << "```" << endl;
    pressEnterToContinue(current_retriever, "default", "다음 예시로!");

    // 예시 2: 양수/음수/0 판별
    cout << "[실습] 숫자가 양수인지, 음수인지, 0인지 판별해보자." << endl;
    int myNum_pnz = 10;
    cout << player_character.name << ": 이번 숫자는 " << myNum_pnz << " 이야! 이게 양수일까, 음수일까, 아니면 0일까?" << endl;
    player_character.display("thinking");
    cout << "```cpp" << endl;
    cout << "int myNum = " << myNum_pnz << ";" << endl;
    cout << "if (myNum > 0) {" << endl;
    cout << "  cout << \"The value is a positive number.\";" << endl;
    cout << "} else if (myNum < 0) {" << endl;
    cout << "  cout << \"The value is a negative number.\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << \"The value is 0.\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (myNum_pnz > 0) {
        cout << "The value is a positive number." << endl;
        player_character.display("happy");
        cout << player_character.name << ": 양수였어! 역시 긍정적인 숫자가 좋아!" << endl;
    } else if (myNum_pnz < 0) {
        cout << "The value is a negative number." << endl;
        player_character.display("sad");
        cout << player_character.name << ": 음수라니... 어쩐지 힘이 없더라니..." << endl;
    } else {
        cout << "The value is 0." << endl;
        player_character.display("default");
        cout << player_character.name << ": 0이군! 아무것도 아니야!" << endl;
    }
    cout << "```" << endl;
    pressEnterToContinue(current_retriever, "default", "다음 예시로!");

    // 예시 3: 투표 가능 여부 (이전 Boolean 스터디에서 한 번 나왔으므로, 간단히만)
    cout << "[실습] 투표 가능 연령인지 확인해보자." << endl;
    int myAge_vote_ex = 25;
    int votingAge_ex = 18;
    cout << player_character.name << ": 내 나이는 25살, 투표 연령은 18살! 투표할 수 있을까?" << endl;
    player_character.display("thinking");
    cout << "```cpp" << endl;
    cout << "int myAge = " << myAge_vote_ex << ";" << endl;
    cout << "int votingAge = " << votingAge_ex << ";" << endl;
    cout << "if (myAge >= votingAge) {" << endl;
    cout << "  cout << \"Old enough to vote!\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << \"Not old enough to vote.\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (myAge_vote_ex >= votingAge_ex) {
        cout << "Old enough to vote!" << endl;
        player_character.display("happy");
        cout << player_character.name << ": 와! 투표할 수 있어! 책임감 있는 보리가 되겠어!" << endl;
    } else {
        cout << "Not old enough to vote." << endl;
        player_character.display("sad");
        cout << player_character.name << ": 아직 투표를 못 하는구나... 어른이 되고 싶어!" << endl;
    }
    cout << "```" << endl;
    pressEnterToContinue(current_retriever, "default", "다음 예시로!");

    // 예시 4: 짝수/홀수 판별
    cout << "[실습] 숫자가 짝수인지 홀수인지 판별해보자." << endl;
    int myNum_eo = 5;
    cout << player_character.name << ": 이번 숫자는 " << myNum_eo << " 이야! 짝수일까, 홀수일까? 고구마 개수가 딱 맞아야 하는데..." << endl;
    player_character.display("thinking");
    cout << "```cpp" << endl;
    cout << "int myNum = " << myNum_eo << ";" << endl;
    cout << "if (myNum % 2 == 0) {" << endl;
    cout << "  cout << myNum << \" is even.\";" << endl;
    cout << "} else {" << endl;
    cout << "  cout << myNum << \" is odd.\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    if (myNum_eo % 2 == 0) {
        cout << myNum_eo << " is even." << endl;
        player_character.display("happy");
        cout << player_character.name << ": 짝수야! 깔끔하게 두 개씩 나눠 먹을 수 있겠군!" << endl;
    } else {
        cout << myNum_eo << " is odd." << endl;
        player_character.display("sad");
        cout << player_character.name << ": 홀수라니... 하나가 남잖아! 이걸 어떻게 해야 해?!" << endl;
    }
    cout << "```" << endl;
    pressEnterToContinue(current_retriever, "default", "이제 Switch 문으로 넘어가자!");

    // --- 단락 8: C++ Switch Statements ---
    Character current_cat = all_characters[4]; // 고양이 '냥냥'
    cout << current_cat.name << " (" << current_cat.species << "): 야옹~ " << player_character.name << "! 이젠 `switch` 문 차례다옹!" << endl;
    current_cat.display("happy");
    cout << "`switch` 문은 `if...else if`를 여러 번 쓰는 대신, 하나의 '표현식' 값에 따라 여러 코드 블록 중 하나를 '선택'해서 실행할 때 사용한다옹." << endl;
    cout << "마치 내가 좋아하는 간식 종류에 따라 다른 그릇에 담아주는 것과 같다옹!" << endl;
    current_cat.display("default");
    pressEnterToContinue(current_cat, "default", "구문을 볼까옹?");

    cout << "```cpp" << endl;
    cout << "switch(expression) {" << endl;
    cout << "  case x:" << endl;
    cout << "    // x와 일치할 때 코드" << endl;
    cout << "    break;" << endl;
    cout << "  case y:" << endl;
    cout << "    // y와 일치할 때 코드" << endl;
    cout << "    break;" << endl;
    cout << "  default:" << endl;
    cout << "    // 일치하는 case가 없을 때 코드" << endl;
    cout << "}" << endl;
    cout << "```" << endl;
    player_character.display("thinking");
    cout << player_character.name << ": 음... 여러 갈래 길이 있는 것 같군. 어떻게 사용하는 거지?" << endl;
    pressEnterToContinue(player_character, "thinking", "요일 예시를 보자!");

    cout << "[실습] 요일 숫자를 요일 이름으로 바꿔 출력해보자. (1=월요일, 4=목요일)" << endl;
    int day_switch = 4;
    cout << "```cpp" << endl;
    cout << "int day = " << day_switch << ";" << endl;
    cout << "switch (day) {" << endl;
    cout << "  case 1: cout << \"Monday\"; break;" << endl;
    cout << "  case 2: cout << \"Tuesday\"; break;" << endl;
    cout << "  case 3: cout << \"Wednesday\"; break;" << endl;
    cout << "  case 4: cout << \"Thursday\"; break;" << endl;
    cout << "  case 5: cout << \"Friday\"; break;" << endl;
    cout << "  case 6: cout << \"Saturday\"; break;" << endl;
    cout << "  case 7: cout << \"Sunday\"; break;" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    switch (day_switch) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
    }
    cout << endl << "```" << endl;
    player_character.display("happy");
    cout << player_character.name << ": 4는 목요일이군! 딱딱 맞는 게 아주 시원하군!" << endl;
    pressEnterToContinue(player_character, "happy", "break 키워드의 중요성!");

    // --- 단락 9: The break Keyword ---
    cout << current_cat.name << " (" << current_cat.species << "): `switch` 문에서 `break`는 정말 중요한다옹! `break`를 만나면 `switch` 블록을 바로 빠져나간다옹." << endl;
    current_cat.display("thinking");
    cout << "만약 `break`가 없으면, 일치하는 `case` 다음의 `case` 코드까지 쭉 실행된단다! 이걸 'fall-through'라고 부른다옹. 조심해야 한다옹!" << endl;
    current_cat.display("angry");
    pressEnterToContinue(current_cat, "angry", "break가 없는 예시를 볼까옹?");

    cout << "[실습] `break`가 없는 경우: `day = 3`일 때 `break`가 없으면 어떻게 될까?" << endl;
    int day_fall_through = 3;
    cout << "```cpp" << endl;
    cout << "int day = " << day_fall_through << ";" << endl;
    cout << "switch (day) {" << endl;
    cout << "  case 1: cout << \"Mon\"; break;" << endl;
    cout << "  case 2: cout << \"Tue\"; break;" << endl;
    cout << "  case 3: cout << \"Wed\"; // break가 없음!" << endl;
    cout << "  case 4: cout << \"Thu\"; break;" << endl;
    cout << "  default: cout << \"Other\"; break;" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    switch (day_fall_through) {
        case 1: cout << "Mon"; break;
        case 2: cout << "Tue"; break;
        case 3: cout << "Wed"; // no break here
        case 4: cout << "Thu"; break;
        default: cout << "Other"; break;
    }
    cout << endl << "```" << endl;
    player_character.display("surprised");
    cout << player_character.name << ": 헐! 수요일인데 'WedThu'가 나왔어! `break`가 없으면 계속 실행되는구나! 무서워!" << endl;
    pressEnterToContinue(player_character, "surprised", "다음은 default 키워드!");

    // --- 단락 10: The default Keyword ---
    Character final_master_swibaek = all_characters[10]; // 싀백 '먀엉'
    cout << final_master_swibaek.name << " (" << final_master_swibaek.species << "): 야옹~ 마지막으로 `default` 키워드다옹. 이건 일치하는 `case`가 아무것도 없을 때 실행된다옹." << endl;
    final_master_swibaek.display("thinking");
    cout << "마치 내가 아무 간식도 먹고 싶지 않을 때, 그냥 낮잠을 자는 것과 같다옹!" << endl;
    final_master_swibaek.display("default");
    pressEnterToContinue(final_master_swibaek, "default", "예시를 볼까옹?");

    cout << "[실습] `day = 99`일 때 `default`가 어떻게 작동하는지 보자." << endl;
    int day_default = 99;
    cout << "```cpp" << endl;
    cout << "int day = " << day_default << ";" << endl;
    cout << "switch (day) {" << endl;
    cout << "  case 6: cout << \"Today is Saturday\"; break;" << endl;
    cout << "  case 7: cout << \"Today is Sunday\"; break;" << endl;
    cout << "  default: cout << \"Looking forward to the Weekend\";" << endl;
    cout << "}" << endl;
    cout << "// 결과: ";
    switch (day_default) {
        case 6: cout << "Today is Saturday"; break;
        case 7: cout << "Today is Sunday"; break;
        default: cout << "Looking forward to the Weekend";
    }
    cout << endl << "```" << endl;
    player_character.display("happy");
    cout << player_character.name << ": 99는 어떤 요일도 아니니까 `default`가 실행되어서 'Looking forward to the Weekend'가 나오는군! 멍멍!" << endl;
    pressEnterToContinue(player_character, "happy", "드디어 퀴즈 시간!");

    // --- 퀴즈 섹션 ---
    cout << "\n\n========== 조건문 퀴즈 타임! ==========" << endl;
    cout << player_character.name << ": 좋아! 고구마 에너지가 가득 찼어! 조건문의 달인이 되어주지!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "퀴즈를 시작해볼까?");

    // 퀴즈 마스터를 랜덤으로 선택
    vector<Character> quiz_masters_pool = all_characters;
    // 플레이어 캐릭터는 퀴즈 마스터 풀에서 제외
    quiz_masters_pool.erase(std::remove_if(quiz_masters_pool.begin(), quiz_masters_pool.end(), 
                                           [&](const Character& c){ return c.name == player_character.name && c.species == player_character.species; }),
                                           quiz_masters_pool.end());
    
    // 퀴즈 마스터 이름을 랜덤으로 설정 (더 재미있게)
    vector<string> quiz_master_nicknames = {"논리의 대가", "분기점 마스터", "선택의 여왕", "결정왕", "조건문 지배자"};
    Character random_quiz_master = quiz_masters_pool[rand() % quiz_masters_pool.size()];
    random_quiz_master.name = quiz_master_nicknames[rand() % quiz_master_nicknames.size()] + " " + random_quiz_master.species;


    conductQuiz(player_character, random_quiz_master, all_if_else_switch_quizzes);

    // --- 최종 결과 ---
    cout << "\n\n\n========== 스터디 완료! ==========" << endl;
    if (player_character.hp > 0) {
        cout << "✨ 축하합니다! " << player_character.name << "는(은) 조건문 스터디의 모든 난관을 극복하고 지식의 정점에 도달했습니다!" << endl;
        player_character.display("happy");
        cout << player_character.name << ": 휴... 드디어 끝났군. 고구마 대량 주문이다! 멍멍!" << endl;
    } else {
        player_character.display("sad");
        cout << "💧 아쉽지만, " << player_character.name << "는(은) 체력이 부족하여 더 이상 스터디를 진행할 수 없었습니다. 다음 기회에 다시 도전해요!" << endl;
        cout << player_character.name << ": 고구마... 고구마... (털썩 쓰러짐)" << endl;
    }
    cout << "\nC++ 조건문 스터디가 모두 끝났습니다. 정말 수고 많으셨습니다! 안녕!" << endl;

    return 0;
}