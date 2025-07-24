#include <iostream> // cout, cin, endl 등을 사용하기 위해 필요
#include <string>   // string 타입을 사용하기 위해 필요
#include <vector>   // vector를 사용하기 위해 필요
#include <limits>   // numeric_limits를 사용하기 위해 필요 (cin.ignore 버퍼 비우기)
#include <cstdlib>  // srand, rand를 사용하기 위해 필요
#include <ctime>    // time을 사용하기 위해 필요 (랜덤 시드)
#include <locale>   // setlocale을 사용하기 위해 필요 (한글 출력)
#include <algorithm> // std::random_shuffle, std::find, std::remove_if
#include <cmath>    // 수학 함수를 사용하기 위해 필요 (sqrt, round, log 등)
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

// 모든 퀴즈 데이터를 생성하고 반환하는 함수 (최소 30개)
vector<Question> initializeAllMathBooleanQuizzes() {
    return {
        // --- Math 퀴즈 ---
        {
            "두 숫자 중 더 큰 값을 찾고 싶을 때 사용하는 `cmath` 라이브러리의 함수는 무엇일까요?",
            "최대(maximum)를 의미하는 영어 단어를 떠올려보세요.",
            {
                {"min()", "min()은 더 작은 값을 찾을 때 사용해요.", false},
                {"max()", "정답! max(x,y) 함수는 두 값 중 더 큰 값을 반환합니다.", true},
                {"sum()", "sum()은 두 값을 더할 때 사용해요.", false},
                {"abs()", "abs()는 절댓값을 반환해요.", false}
            }
        },
        {
            "`double num = 81.0;`의 제곱근(square root)을 구하려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?",
            "제곱근을 의미하는 영어 단어를 줄여서 생각해보세요.",
            {
                {"power()", "power()는 거듭제곱을 계산할 때 사용해요.", false},
                {"root()", "root()는 C++ 표준 cmath에 존재하지 않습니다.", false},
                {"sqrt()", "정답! sqrt() 함수는 숫자의 제곱근을 반환합니다.", true},
                {"sq()", "sq()는 C++ 표준 cmath에 존재하지 않습니다.", false}
            }
        },
        {
            "`double value = 3.7;`을 가장 가까운 정수로 반올림하려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?",
            "반올림(round)을 의미하는 영어 단어를 떠올려보세요.",
            {
                {"ceil()", "ceil()은 올림을 할 때 사용해요 (4.0).", false},
                {"floor()", "floor()는 내림을 할 때 사용해요 (3.0).", false},
                {"round()", "정답! round() 함수는 숫자를 가장 가까운 정수로 반올림합니다.", true},
                {"trunc()", "trunc()는 소수점 이하를 버릴 때 사용해요 (3.0).", false}
            }
        },
        {
            "자연로그(natural logarithm)를 계산하는 `cmath` 함수는 무엇일까요?",
            "로그(logarithm)를 의미하는 영어 단어를 생각해보세요.",
            {
                {"exp()", "exp()는 지수 함수(e의 거듭제곱)를 계산해요.", false},
                {"log()", "정답! log() 함수는 자연로그를 계산합니다.", true},
                {"pow()", "pow()는 거듭제곱을 계산해요.", false},
                {"ln()", "ln()은 수학에서 자연로그를 의미하지만, C++ 함수 이름은 log()입니다.", false}
            }
        },
        {
            "`double base = 2.0; double exponent = 3.0;` 일 때, 2의 3제곱(8.0)을 계산하는 `cmath` 함수는 무엇일까요?",
            "거듭제곱(power)을 의미하는 영어 단어를 떠올려보세요.",
            {
                {"sqrt()", "sqrt()는 제곱근을 계산해요.", false},
                {"pow()", "정답! pow(base, exponent) 함수는 거듭제곱을 계산합니다.", true},
                {"log()", "log()는 자연로그를 계산해요.", false},
                {"abs()", "abs()는 절댓값을 반환해요.", false}
            }
        },
        {
            "`int num = -10;`의 절댓값을 구하려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?",
            "절댓값(absolute value)을 의미하는 영어 단어를 줄여서 생각해보세요.",
            {
                {"ceil()", "ceil()은 올림을 할 때 사용해요.", false},
                {"abs()", "정답! abs() 함수는 숫자의 절댓값을 반환합니다.", true},
                {"fabs()", "fabs()는 부동소수점 수의 절댓값을 반환하고, abs()는 정수형에 사용됩니다. 둘 다 맞지만, 문제에서는 `int`를 사용했어요.", false},
                {"floor()", "floor()는 내림을 할 때 사용해요.", false}
            }
        },
        {
            "`double angle = 0.0;`의 사인(sine) 값을 계산하는 `cmath` 함수는 무엇일까요?",
            "삼각 함수 사인(sine)을 의미하는 영어 단어를 생각해보세요.",
            {
                {"cos()", "cos()는 코사인 값을 계산해요.", false},
                {"tan()", "tan()는 탄젠트 값을 계산해요.", false},
                {"sin()", "정답! sin() 함수는 주어진 각도(라디안)의 사인 값을 계산합니다.", true},
                {"asin()", "asin()은 아크 사인 값을 계산해요.", false}
            }
        },
        {
            "두 점 `(x1, y1)`과 `(x2, y2)` 사이의 유클리드 거리를 계산할 때, 피타고라스 정리(`sqrt(pow(dx, 2) + pow(dy, 2))`)에 주로 사용되는 `cmath` 함수는 무엇일까요?",
            "이름 자체가 '피타고라스'를 떠올리게 하는 함수예요.",
            {
                {"hypot()", "정답! hypot(dx, dy) 함수는 두 변의 길이를 통해 빗변의 길이를 (sqrt(x^2 + y^2)) 계산합니다. 유클리드 거리 계산에 유용해요.", true},
                {"dist()", "dist()는 C++ 표준 cmath에 존재하지 않습니다.", false},
                {"pythagoras()", "pythagoras()는 C++ 표준 cmath에 존재하지 않습니다.", false},
                {"distance()", "distance()는 C++ 표준 cmath에 존재하지 않습니다.", false}
            }
        },
        {
            "어떤 숫자의 부호(양수/음수/0)를 얻고 싶을 때, `cmath` 라이브러리의 어떤 함수를 사용할 수 있을까요? (힌트: C++20부터 표준에 포함된 함수)",
            "부호를 의미하는 sign에서 따온 이름이에요.",
            {
                {"sign()", "sign()은 C++20 이전에는 표준이 아니었지만, 이제 표준에 포함되었습니다.", true}, // C++20 이후 std::sign
                {"sgn()", "sgn()은 일반적으로 사용되는 용어지만, C++ 표준 함수는 sign()입니다.", false},
                {"is_positive()", "is_positive()는 C++ 표준 cmath에 존재하지 않습니다.", false},
                {"copysign()", "copysign()은 다른 숫자의 부호를 복사해요.", false}
            }
        },
        {
            "`double value = 5.9;`를 내림(floor)하여 정수로 만들려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?",
            "바닥(floor)을 의미하는 영어 단어를 떠올려보세요.",
            {
                {"round()", "round()는 반올림이에요.", false},
                {"ceil()", "ceil()은 올림이에요.", false},
                {"floor()", "정답! floor() 함수는 주어진 숫자보다 작거나 같은 가장 큰 정수를 반환합니다 (내림).", true},
                {"trunc()", "trunc()는 소수점 이하를 버려요 (양수는 floor와 같고, 음수는 ceil과 같아요).", false}
            }
        },
        {
            "컴퓨터 과학에서 특정 값을 2의 거듭제곱으로 나타낼 때 사용하는 로그 함수는 무엇일까요?",
            "밑이 2인 로그를 의미하는 함수 이름이에요.",
            {
                {"log()", "log()는 자연로그(밑이 e)를 나타내요.", false},
                {"log10()", "log10()은 상용로그(밑이 10)를 나타내요.", false},
                {"log2()", "정답! log2() 함수는 밑이 2인 로그를 계산합니다.", true},
                {"logb()", "logb()는 부동소수점 숫자의 지수 부분을 반환해요.", false}
            }
        },
        {
            "`double val = -7.5;`의 절댓값을 `double` 형태로 반환하는 `cmath` 함수는 무엇일까요?",
            "부동소수점 숫자의 절댓값을 위한 함수를 찾으세요.",
            {
                {"abs()", "abs()는 보통 정수형의 절댓값을 위해 사용됩니다.", false},
                {"fabs()", "정답! fabs() 함수는 부동소수점 숫자의 절댓값을 반환합니다.", true},
                {"dabs()", "dabs()는 C++ 표준 cmath에 존재하지 않습니다.", false},
                {"abs_double()", "abs_double()는 C++ 표준 cmath에 존재하지 않습니다.", false}
            }
        },
        {
            "`double x = 1.0;`의 코사인(cosine) 값을 계산하는 `cmath` 함수는 무엇일까요?",
            "삼각 함수 코사인(cosine)을 의미하는 영어 단어를 생각해보세요.",
            {
                {"sin()", "sin()은 사인 값을 계산해요.", false},
                {"tan()", "tan()은 탄젠트 값을 계산해요.", false},
                {"acos()", "acos()는 아크코사인 값을 계산해요.", false},
                {"cos()", "정답! cos() 함수는 주어진 각도(라디안)의 코사인 값을 계산합니다.", true}
            }
        },
        // --- Boolean 퀴즈 ---
        {
            "프로그래밍에서 'YES/NO', 'ON/OFF', 'TRUE/FALSE'와 같이 단 두 가지 값만 가질 수 있는 데이터 타입은 무엇일까요?",
            "논리적인 판단을 위한 타입이에요.",
            {
                {"int", "int는 정수를 저장해요.", false},
                {"char", "char는 단일 문자를 저장해요.", false},
                {"bool", "정답! bool 타입은 true(참) 또는 false(거짓) 두 가지 값만 가질 수 있습니다.", true},
                {"string", "string은 텍스트를 저장해요.", false}
            }
        },
        {
            "C++에서 `bool` 타입의 `true` 값은 정수형으로 변환될 때 어떤 숫자가 될까요?",
            "컴퓨터가 참을 표현하는 기본적인 숫자예요.",
            {
                {"0", "0은 false에 해당해요.", false},
                {"1", "정답! bool 값 true는 정수 1로, false는 0으로 변환됩니다.", true},
                {"-1", "-1은 일반적으로 사용되지 않아요.", false},
                {"true는 숫자가 될 수 없다.", "bool은 정수형으로 암시적 변환이 가능해요.", false}
            }
        },
        {
            "다음 중 `bool` 변수를 선언하고 `false` 값으로 초기화하는 올바른 방법은 무엇일까요?",
            "`bool` 키워드를 사용하고 `false` 리터럴을 할당하세요.",
            {
                {"boolean isDone = false;", "C++에서 `bool`은 소문자 `b`로 시작해요.", false},
                {"bool isDone = 0;", "0은 false와 동일한 의미로 사용될 수 있지만, `false` 리터럴을 직접 사용하는 것이 더 명확해요.", true}, // 이 보기도 정답으로 간주할 수 있지만, '가장 올바른'은 아니므로 True로 두겠습니다.
                {"bool isDone = \"false\";", "문자열 \"false\"는 bool 값으로 직접 할당될 수 없어요.", false},
                {"Bool isDone = False;", "C++에서 `bool`과 `false`는 모두 소문자로 시작해요.", false}
            }
        },
        {
            "불리언 표현식 `(10 > 5)`의 결과는 무엇일까요? (정수 값으로)",
            "10이 5보다 큰지 판단해보세요.",
            {
                {"0", "10은 5보다 크므로 참이에요.", false},
                {"1", "정답! 10이 5보다 크므로 이 불리언 표현식은 true(1)를 반환합니다.", true},
                {"5", "숫자가 반환되지 않아요.", false},
                {"에러", "비교 연산은 에러를 발생시키지 않아요.", false}
            }
        },
        {
            "`int a = 7;`일 때, 불리언 표현식 `(a == 5)`의 결과는 무엇일까요? (정수 값으로)",
            "a가 5와 같은지 판단해보세요.",
            {
                {"0", "정답! a(7)는 5와 같지 않으므로 이 불리언 표현식은 false(0)를 반환합니다.", true},
                {"1", "a는 5와 같지 않아요.", false},
                {"5", "숫자가 반환되지 않아요.", false},
                {"7", "숫자가 반환되지 않아요.", false}
            }
        },
        {
            "만약 `age` 변수가 15이고 `votingAge`가 18일 때, `(age >= votingAge)` 불리언 표현식의 결과는 무엇일까요?",
            "15가 18보다 크거나 같은지 판단해보세요.",
            {
                {"true", "15는 18보다 크지도 같지도 않아요.", false},
                {"false", "정답! 15는 18보다 크거나 같지 않으므로 false를 반환합니다.", true},
                {"1", "1은 true에 해당해요.", false},
                {"0", "0은 false에 해당해요. (이것도 정답이지만, bool 값으로 질문했으므로 false가 더 적합)", false}
            }
        },
        {
            "`bool` 타입이 주로 사용되는 프로그래밍 상황은 무엇일까요?",
            "어떤 조건이 참인지 거짓인지 판단해야 할 때를 생각해보세요.",
            {
                {"이름 저장", "이름은 string으로 저장해요.", false},
                {"나이 계산", "나이는 int로 저장해요.", false},
                {"조건문(if/else)의 판단 기준", "정답! `bool`은 조건문, 반복문 등 논리적인 흐름 제어의 판단 기준으로 가장 많이 사용됩니다.", true},
                {"복잡한 수학 계산", "복잡한 수학 계산에는 주로 숫자형 타입을 사용해요.", false}
            }
        },
        {
            "`bool isRaining = true;`일 때, `!isRaining`의 결과는 무엇일까요?",
            "`!` 연산자는 불리언 값을 반전시켜요.",
            {
                {"true", "true의 반대는 false예요.", false},
                {"false", "정답! `!`(NOT) 연산자는 불리언 값을 반전시키므로, true의 반대인 false가 됩니다.", true},
                {"에러", "유효한 연산이에요.", false},
                {"0", "0은 false에 해당해요.", false}
            }
        },
        {
            "`bool condition1 = true; bool condition2 = false;`일 때, `condition1 && condition2`의 결과는 무엇일까요?",
            "`&&`(AND) 연산자는 두 조건이 모두 참일 때만 참을 반환해요.",
            {
                {"true", "두 조건 중 하나가 거짓이므로 true가 될 수 없어요.", false},
                {"false", "정답! `&&`(AND) 연산자는 두 피연산자가 모두 true일 때만 true를 반환합니다. 하나라도 false이면 false입니다.", true},
                {"에러", "유효한 연산이에요.", false},
                {"1", "1은 true에 해당해요.", false}
            }
        },
        {
            "`bool condition1 = true; bool condition2 = false;`일 때, `condition1 || condition2`의 결과는 무엇일까요?",
            "`||`(OR) 연산자는 둘 중 하나라도 참이면 참을 반환해요.",
            {
                {"true", "정답! `||`(OR) 연산자는 두 피연산자 중 하나라도 true이면 true를 반환합니다. 여기서는 condition1이 true입니다.", true},
                {"false", "하나라도 true이면 false가 될 수 없어요.", false},
                {"에러", "유효한 연산이에요.", false},
                {"0", "0은 false에 해당해요.", false}
            }
        },
        {
            "C++에서 불리언 값을 화면에 `true`나 `false`라는 문자열로 출력하고 싶을 때, `std::cout`과 함께 사용할 수 있는 조작자는 무엇일까요?",
            "불리언 값을 문자열로 표현하라는 의미를 가진 단어를 찾아보세요.",
            {
                {"std::dec", "std::dec는 10진수 출력을 위한 조작자예요.", false},
                {"std::fixed", "std::fixed는 부동소수점 출력 형식을 고정할 때 사용해요.", false},
                {"std::boolalpha", "정답! `std::boolalpha` 조작자를 사용하면 `bool` 값을 `1/0` 대신 `true/false` 문자열로 출력할 수 있습니다.", true},
                {"std::scientific", "std::scientific은 과학적 표기법으로 숫자를 출력할 때 사용해요.", false}
            }
        },
        {
            "`if (some_boolean_variable)`와 같이 조건문을 작성할 때, `some_boolean_variable`의 값이 `true`이면 `if` 블록이 실행됩니다. 이는 `some_boolean_variable == true`와 어떤 관계일까요?",
            "불리언 변수 자체가 이미 조건으로 사용될 수 있어요.",
            {
                {"`if (some_boolean_variable)`는 항상 `false`를 의미한다.", "이는 틀린 설명이에요.", false},
                {"`if (some_boolean_variable)`는 `some_boolean_variable == true`와 동일한 의미이다.", "정답! 불리언 변수는 그 자체로 논리적 값을 가지므로, `some_boolean_variable == true`와 같이 명시적으로 비교하지 않아도 됩니다.", true},
                {"`if (some_boolean_variable)`는 문법 오류이다.", "유효한 C++ 문법이에요.", false},
                {"`if (some_boolean_variable)`는 `some_boolean_variable != false`와 동일한 의미이다.", "맞는 설명이지만, `some_boolean_variable == true`와 더 직접적인 의미를 가져요.", false}
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
    cout << quiz_master.name << ": 자, " << player.name << "! 네가 배운 수학과 논리 지식을 시험해 볼 시간이다! 긴장해라!" << endl;
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
    vector<Question> all_math_boolean_quizzes = initializeAllMathBooleanQuizzes();
    
    // --- 캐릭터 초기화 및 선택 ---
    vector<Character> all_characters = initializeCharacters();
    
    // 플레이어 캐릭터 설정 (보리로 강제 설정)
    // Character.h에 말티즈 종족과 보리 정보가 추가되었다는 전제 하에 아래 코드 사용
    Character player_character("말티즈", "보리", 130, 35); // 보리 캐릭터 생성 (Character.h에 말티즈 display 추가 필요)
    
    cout << "---------- C++ Math & Boolean 스터디 시작! ----------" << endl;
    cout << "당신은 C++ 스터디의 귀여운 주인공, " << player_character.name << " (" << player_character.species << ") 입니다!" << endl;
    player_character.display("default");
    // 메시지와 감정을 직접 전달
    pressEnterToContinue(player_character, "default", "어서 스터디를 시작해볼까?"); // 보리 캐릭터와 함께 시작

    // 메인 가이드 캐릭터 선언 및 초기화
    Character main_guide = all_characters[0]; // 치와와 '치치'를 메인 가이드로 (초기값)

    // --- 단락 1: C++ Math란? ---
    cout << main_guide.name << " (" << main_guide.species << "): 안녕! 나의 사랑스러운 후배, " << player_character.name << "!" << endl;
    main_guide.display("happy");
    cout << "오늘은 C++ 스터디의 새로운 주제, '수학 함수(Math Functions)'에 대해 알아볼 거야!" << endl;
    cout << "C++에는 숫자들을 가지고 다양한 수학 계산을 할 수 있도록 도와주는 멋진 함수들이 많이 있단다." << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "첫 번째 기능을 살펴볼까?");

    // --- 단락 2: Max와 Min 함수 ---
    cout << main_guide.name << " (" << main_guide.species << "): 먼저, 두 숫자 중에 가장 큰 값이나 가장 작은 값을 찾는 방법을 알아볼 거야!" << endl;
    main_guide.display("default");
    cout << "친구들과 간식을 나눠 먹을 때 누가 가장 많이 가졌는지, 누가 가장 적게 가졌는지 알고 싶을 때 유용하겠지?" << endl;
    cout << "`max(x,y)` 함수는 x와 y 중 더 높은(큰) 값을 찾아주고," << endl;
    cout << "`min(x,y)` 함수는 x와 y 중 더 낮은(작은) 값을 찾아준단다." << endl;
    main_guide.display("happy");
    pressEnterToContinue(main_guide, "happy", "실습해볼까? (Enter)");

    cout << "[실습] 5와 10 중에 더 큰 값과 작은 값을 찾아보자." << endl;
    int val1_ex = 5;
    int val2_ex = 10;
    cout << "```cpp" << endl;
    // 이 부분들 수정: " //" 로 끝나는 문자열 리터럴에서 마지막 "를 제거하고 << endl; 전에 올바르게 닫도록 수정
    cout << "cout << max(" << val1_ex << ", " << val2_ex << "); // 결과: " << std::max(val1_ex, val2_ex) << endl;
    cout << "cout << min(" << val1_ex << ", " << val2_ex << "); // 결과: " << std::min(val1_ex, val2_ex) << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 5와 10 중에 최대값은 " << std::max(val1_ex, val2_ex) << " 이고, 최소값은 " << std::min(val1_ex, val2_ex) << " 이군! 고구마를 더 많이 가져야지!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "다음 함수들을 알아보자! (Enter)");

    // --- 단락 3: C++ <cmath> 라이브러리 ---
    Character current_liki = all_characters[8]; // 임정찬 'Liki'
    cout << current_liki.name << " (" << current_liki.species << "): 선생님! 저는 더 복잡한 계산도 하고 싶어요! 예를 들면 제곱근이나 반올림 같은 거요!" << endl;
    current_liki.display("thinking");
    main_guide.display("happy");
    cout << main_guide.name << " (" << main_guide.species << "): 리키, 아주 좋은 질문이야! 그런 복잡한 함수들은 `<cmath>`라는 특별한 헤더 파일 안에 숨어 있단다!" << endl;
    cout << "`#include <cmath>`를 코드 맨 위에 써주면, `sqrt()` (제곱근), `round()` (반올림), `log()` (자연로그) 같은 유용한 함수들을 사용할 수 있어." << endl;
    main_guide.display("default");
    pressEnterToContinue(main_guide, "default", "실습을 통해 확인해보자! (Enter)");

    cout << "[실습] 64의 제곱근, 2.6의 반올림, 2의 자연로그를 계산해보자." << endl;
    double sqrt_val = 64.0;
    double round_val = 2.6;
    double log_val = 2.0;
    cout << "```cpp" << endl;
    cout << "// <cmath> 헤더 파일 포함" << endl;
    cout << "#include <cmath>" << endl;
    // 이 부분들 수정: " //" 로 끝나는 문자열 리터럴에서 마지막 "를 제거하고 << endl; 전에 올바르게 닫도록 수정
    cout << "cout << sqrt(" << sqrt_val << "); // 결과: " << sqrt(sqrt_val) << endl;
    cout << "cout << round(" << round_val << "); // 결과: " << round(round_val) << endl;
    cout << "cout << log(" << log_val << "); // 결과: " << log(log_val) << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 64의 제곱근은 " << sqrt(sqrt_val) << ", 2.6의 반올림은 " << round(round_val) << ", 2의 자연로그는 " << log(log_val) << " 이로군! 와우!" << endl;
    player_character.display("surprised");
    pressEnterToContinue(player_character, "surprised", "더 다양한 수학 함수를 알고 싶어! (Enter)");

    cout << main_guide.name << " (" << main_guide.species << "): 더 많은 수학 함수들을 알고 싶다면, C++ Math Reference를 참고하면 된단다! 세상의 모든 숫자를 다룰 수 있을 거야!" << endl;
    main_guide.display("happy");
    pressEnterToContinue(main_guide, "happy", "이제 논리적인 세상으로 떠나볼까?");


    // --- 단락 4: C++ Booleans ---
    Character current_babo = all_characters[9]; // 정규호 '바보'
    cout << current_babo.name << " (" << current_babo.species << "): 야, " << player_character.name << "! 이젠 좀 쉬운 거 할 차례 아니야? 맞다, 아니다만 하면 되는 거!" << endl;
    current_babo.display("happy");
    player_character.display("default");
    cout << player_character.name << ": 흥, 쉬운 거라니. 네가 좋아하는 고구마가 맛있는지, 맛없는지 판단하는 것처럼 말이야?" << endl;
    // main_guide를 다시 사용하도록 재설정 (치치 캐릭터)
    main_guide = all_characters[0]; // 다시 치치로 설정하여 캐릭터 일관성 유지
    cout << main_guide.name << " (" << main_guide.species << "): 바로 그거야, " << player_character.name << "! 프로그래밍에서는 '참/거짓', '켜짐/꺼짐', '예/아니오'처럼 딱 두 가지 값만 가질 수 있는 데이터 타입이 필요할 때가 아주 많아!" << endl;
    cout << "이럴 때 사용하는 것이 바로 `bool` 데이터 타입이야. `true`(1) 또는 `false`(0) 값을 가질 수 있단다." << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "bool 변수를 선언해보자!");

    // --- 단락 5: Boolean 값 (true/false, 1/0) ---
    cout << "[실습] `bool` 변수를 선언하고 `true`와 `false` 값을 할당해보자." << endl;
    bool isCodingFun = true;
    bool isFishTasty = false;
    cout << "```cpp" << endl;
    cout << "bool isCodingFun = true;" << endl; //
    cout << "bool isFishTasty = false;" << endl; //
    cout << "cout << isCodingFun; // 결과: " << isCodingFun << " (1)" << endl; //
    cout << "cout << isFishTasty; // 결과: " << isFishTasty << " (0)" << endl; //
    cout << "```" << endl;
    cout << player_character.name << ": 코딩이 재밌다는 건 " << isCodingFun << " (1)! 생선은 맛없다는 건 " << isFishTasty << " (0)! 어때? 명확하지?" << endl;
    player_character.display("happy");
    current_babo.display("surprised");
    cout << current_babo.name << ": 와! 1이랑 0으로 딱 나오네! 신기하다!" << endl;
    pressEnterToContinue(current_babo, "surprised", "하지만 더 중요한 건 비교야!");

    // --- 단락 6: C++ Boolean 표현식 ---
    Character quiz_master_husky = all_characters[2]; // 허스키 '허허'
    cout << quiz_master_husky.name << " (" << quiz_master_husky.species << "): 이제부터 '불리언 표현식'에 대해 알아볼 거야. 이게 진짜 논리의 시작이다!" << endl;
    quiz_master_husky.display("thinking");
    cout << "불리언 표현식은 결과로 `true`(1) 또는 `false`(0) 값을 반환해. 이걸로 복잡한 논리를 만들 수 있단다." << endl;
    cout << "비교 연산자(`>`, `<`, `==` 등)를 사용해서 어떤 조건이 참인지 거짓인지 알아낼 수 있어." << endl;
    quiz_master_husky.display("default");
    pressEnterToContinue(quiz_master_husky, "default", "예시를 통해 알아보자!");

    cout << "[실습] 10이 9보다 큰지 확인해보자." << endl;
    int x_comp = 10;
    int y_comp = 9;
    cout << "```cpp" << endl;
    cout << "int x = 10;" << endl;
    cout << "int y = 9;" << endl;
    cout << "cout << (x > y); // 결과: " << (x_comp > y_comp) << " (1)" << endl; //
    cout << "cout << (10 > 9); // 결과: " << (10 > 9) << " (1)" << endl; //
    cout << "```" << endl;
    cout << player_character.name << ": 10이 9보다 크니까 당연히 `true`(1)지! 훗." << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "같은지 비교도 해볼까?");

    cout << "[실습] 값이 같은지 다른지 비교해보자." << endl;
    int check_val = 10;
    cout << "```cpp" << endl;
    cout << "int x = 10;" << endl;
    cout << "cout << (x == 10); // 결과: " << (check_val == 10) << " (1)" << endl; //
    cout << "cout << (10 == 15); // 결과: " << (10 == 15) << " (0)" << endl; //
    cout << "```" << endl;
    cout << player_character.name << ": 10은 10이랑 같으니까 `true`(1)! 10은 15랑 다르니까 `false`(0)! 완벽해!" << endl;
    player_character.display("happy");
    quiz_master_husky.display("happy");
    cout << quiz_master_husky.name << ": 아주 잘 이해하고 있군! 네 논리력이 대단하다!" << endl;
    pressEnterToContinue(quiz_master_husky, "happy", "실생활 예시로 넘어가자!");

    // --- 단락 7: C++ Boolean 실생활 예시 ---
    // main_guide 변수를 재사용 (현재 main_guide는 치치)
    main_guide = all_characters[0]; // 다시 치치로 설정하여 캐릭터 일관성 유지
    cout << main_guide.name << " (" << main_guide.species << "): 이제 불리언이 어떻게 '진짜' 문제에 사용되는지 알아볼 거야!" << endl;
    main_guide.display("happy");
    cout << "사람이 투표할 수 있는 나이인지 아닌지 판단하는 예를 들어볼게. " << player_character.name << "는 아직 투표 못 하겠네!" << endl;
    player_character.display("sad");
    main_guide.display("default");
    cout << main_guide.name << " (" << main_guide.species << "): 나이(25)가 투표 연령(18)보다 크거나 같은지(`>=`) 비교해서 `true` 또는 `false`를 얻을 수 있어." << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "예시 코드를 볼까?");

    int myAge_vote = 25;
    int votingAge_limit = 18;
    cout << "```cpp" << endl;
    cout << "int myAge = 25;" << endl;
    cout << "int votingAge = 18;" << endl;
    cout << "cout << (myAge >= votingAge); // 결과: " << (myAge_vote >= votingAge_limit) << " (1)" << endl; //
    cout << "```" << endl;
    cout << player_character.name << ": 25살은 18살보다 많으니까 `true`(1)이군! 미래의 보리도 투표할 수 있겠어!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "if-else 문으로 응용해볼까?");

    cout << main_guide.name << " (" << main_guide.species << "): 여기서 더 나아가, 이 불리언 결과를 가지고 '만약 ~이라면, 아니면 ~이다'와 같은 동작을 하게 만들 수 있어. 바로 `if...else` 문이야!" << endl;
    main_guide.display("surprised");
    cout << "만약 나이가 18세 이상이면 '투표 가능!'을 출력하고, 그렇지 않으면 '투표 불가능!'을 출력하는 코드를 볼까?" << endl;
    main_guide.display("default");
    pressEnterToContinue(main_guide, "default", "예시 코드를 확인해보자!");

    cout << "```cpp" << endl;
    cout << "int myAge = 25;" << endl;
    cout << "int votingAge = 18;" << endl;
    cout << "if (myAge >= votingAge) {" << endl; //
    cout << "  cout << \"Old enough to vote!\";" << endl; //
    cout << "} else {" << endl; //
    cout << "  cout << \"Not old enough to vote.\";" << endl; //
    cout << "}" << endl;
    cout << "// 결과: ";
    if (myAge_vote >= votingAge_limit) {
        cout << "Old enough to vote!" << endl;
    } else {
        cout << "Not old enough to vote." << endl;
    }
    cout << "```" << endl;
    cout << player_character.name << ": 오! 이렇게 되면 결과에 따라 다른 말을 할 수 있구나! 정말 유용해!" << endl;
    player_character.display("happy");
    main_guide.display("happy");
    cout << main_guide.name << " (" << main_guide.species << "): 맞아! 불리언은 C++의 모든 비교와 조건의 기본이 된단다. 다음 장에서 `if...else`에 대해 더 자세히 배울 거야!" << endl;
    main_guide.display("happy");
    pressEnterToContinue(main_guide, "happy", "이제 수학과 불리언 퀴즈 시간!");

    // --- 퀴즈 섹션 ---
    cout << "\n\n========== Math & Boolean 퀴즈 타임! ==========" << endl;
    cout << player_character.name << ": 좋아! 고구마 에너지가 가득 찼어! 수학과 논리의 정점을 찍어주지!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "퀴즈를 시작해볼까?");

    // 퀴즈 마스터를 랜덤으로 선택
    vector<Character> quiz_masters_pool = all_characters;
    // 플레이어 캐릭터는 퀴즈 마스터 풀에서 제외
    quiz_masters_pool.erase(std::remove_if(quiz_masters_pool.begin(), quiz_masters_pool.end(), 
                                           [&](const Character& c){ return c.name == player_character.name && c.species == player_character.species; }),
                                           quiz_masters_pool.end());
    
    // 퀴즈 마스터 이름을 랜덤으로 설정 (더 재미있게)
    vector<string> quiz_master_nicknames = {"지식의 수호자", "논리 왕", "수학 천재 냥", "똑똑박사 강아지", "퀴즈 대마왕", "계산 마법사"};
    Character random_quiz_master = quiz_masters_pool[rand() % quiz_masters_pool.size()];
    random_quiz_master.name = quiz_master_nicknames[rand() % quiz_master_nicknames.size()] + " " + random_quiz_master.species;


    conductQuiz(player_character, random_quiz_master, all_math_boolean_quizzes);

    // --- 최종 결과 ---
    cout << "\n\n\n========== 스터디 완료! ==========" << endl;
    if (player_character.hp > 0) {
        cout << "✨ 축하합니다! " << player_character.name << "는(은) Math와 Boolean 스터디의 모든 난관을 극복하고 지식의 정점에 도달했습니다!" << endl;
        player_character.display("happy");
        cout << player_character.name << ": 휴... 드디어 끝났군. 고구마 대량 주문이다! 멍멍!" << endl;
    } else {
        player_character.display("sad");
        cout << "💧 아쉽지만, " << player_character.name << "는(은) 체력이 부족하여 더 이상 스터디를 진행할 수 없었습니다. 다음 기회에 다시 도전해요!" << endl;
        cout << player_character.name << ": 고구마... 고구마... (털썩 쓰러짐)" << endl;
    }
    cout << "\nC++ Math와 Boolean 스터디가 모두 끝났습니다. 정말 수고 많으셨습니다! 안녕!" << endl;

    return 0;
}