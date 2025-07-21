#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Character.h" // 우리가 만든 캐릭터 헤더 파일을 포함합니다.

// 사용하려는 기능들을 명시합니다.
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;

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

// 15개의 퀴즈 데이터를 생성하고 반환하는 함수
vector<Question> initializeQuiz() {
    return {
        // --- 1. 변수 & 데이터 타입 퀴즈 ---
        {
            "모험의 첫걸음! 파트너의 '체력'을 저장하려고 해. 소수점이 없는 숫자 100을 저장하기에 가장 기본적인 변수 타입은 무엇일까?",
            "정수(whole number)를 담는 가장 기본적인 컨테이너를 떠올려보세요.",
            {
                {"string", "앗! 'string'은 \"Hello\" 같은 문자열을 담는 타입이야. 숫자를 담기엔 적절하지 않아!", false},
                {"double", "까비! 'double'은 3.14처럼 소수점이 있는 숫자를 위한 타입이야. 지금은 소수점이 필요 없는데...", false},
                {"int", "정답! 'int'는 정수를 저장하기 위한 완벽한 타입이야. 파트너의 체력을 정확하게 기록했어!", true},
                {"char", "땡! 'char'는 'A'처럼 딱 한 글자만 담을 수 있는 작은 상자야. 100을 담기엔 너무 작아!", false}
            }
        },
        {
            "길을 가다 '도도한 고양이'를 만났어. \"내 이름은 '나비'야. 이 이름을 변수에 저장하고 싶다면, 어떤 타입의 변수를 선언해야 할까?\" 라고 묻네.",
            "여러 글자가 모인 '텍스트'를 저장하는 타입을 생각해보세요.",
            {
                {"string", "정답이야! 'string'은 여러 글자로 이루어진 텍스트를 저장하는 데 사용돼. 고양이가 만족한 듯 가르랑거려.", true},
                {"int", "이런! 'int'는 숫자만 저장할 수 있어. '나비'라는 글자는 담을 수 없다구. 고양이가 한심하다는 듯 쳐다봐.", false},
                {"char name = \"나비\";", "아깝다! 'char'는 한 글자만 저장할 수 있고, 큰따옴표(\")가 아니라 작은따옴표(')를 사용해야 해. 문법이 틀렸어!", false},
                {"bool", "아니야! 'bool'은 참(true)이나 거짓(false)만 저장할 수 있어. 이름을 저장할 순 없어.", false}
            }
        },
        // --- 2. 연산자 퀴즈 ---
        {
            "'친절한 리트리버'가 나타나 간식을 나눠주려고 해. \"간식 5개를 3명에게 똑같이 나눠주고 남는 개수를 계산하고 싶어. 어떤 연산자를 써야 할까?\"",
            "나눗셈의 '나머지'를 구하는 특별한 연산자가 있었죠.",
            {
                {"/", "아니야! '/' 연산자는 나눗셈의 '몫'을 구해. 5 / 3 의 결과는 1이 되어서, 남는 개수를 알 수 없어.", false},
                {"%", "정답! '%' (모듈러스) 연산자는 나눗셈의 나머지를 정확히 구해줘. 5 % 3은 2! 남은 간식 2개를 정확히 챙겼어!", true},
                {"*", "땡! '*' 연산자는 곱셈을 할 때 쓰는 거야. 간식 개수가 갑자기 15개로 늘어나 버렸어!", false},
                {"+", "이런! '+' 연산자는 덧셈을 위한 거야. 5 더하기 3은 8... 문제가 해결되지 않았어.", false}
            }
        },
        // --- 3. 사용자 입력 퀴즈 ---
        {
            "사용자에게서 파트너의 나이를 입력받으려고 해. 키보드 입력을 받기 위해 사용하는 C++의 기본 객체는 무엇일까?",
            "화면에 출력하는 건 'cout'이라고 했죠? 그럼 입력을 받는 건...",
            {
                {"cin", "정확해! 'cin'과 추출 연산자 '>>'를 사용해서 키보드로부터 값을 입력받을 수 있어.", true},
                {"cout", "반대야! 'cout'은 화면에 값을 출력(output)할 때 사용해. 입력을 받을 수는 없어!", false},
                {"print", "아쉽다! 'print'는 C++ 표준 라이브러리의 기본 객체는 아니야. Python 같은 다른 언어에서 주로 사용돼.", false},
                {"input", "땡! 'input'이라는 이름의 객체는 C++에 기본적으로 존재하지 않아. 직접 만들어야 해.", false}
            }
        },
        // --- 4. 할당 연산자 퀴즈 ---
        {
            "강을 건너야 해! '튼튼한 불독'이 퀴즈를 내. \"`int x = 10; x += 5;` 코드가 실행된 후, 변수 `x`의 값은 얼마가 될까?\"",
            "`+=`는 기존 값에 오른쪽 값을 더해서 다시 저장하는 축약 연산자예요.",
            {
                {"5", "땡! `x += 5`는 `x`에 5를 새로 할당하는 게 아니라, 기존의 `x` 값에 5를 더하는 거야.", false},
                {"10", "아니야! `x`는 10으로 시작했지만, `x += 5;` 라인 때문에 값이 변했어. 변수는 변할 수 있다구!", false},
                {"15", "정답! `x += 5`는 `x = x + 5`와 같아. 즉, `10 + 5`가 계산되어 `x`는 15가 돼. 튼튼한 다리를 건널 수 있게 됐어!", true},
                {"컴파일 에러가 발생한다.", "아니야! `+=`는 C++의 아주 정상적인 할당 연산자 중 하나야. 문법적으로 아무 문제가 없어!", false}
            }
        },
        // --- 5. 상수 퀴즈 ---
        {
            "모험 중 '최대 체력'처럼 절대로 변하면 안 되는 값을 저장하고 싶어. 변수를 선언할 때 어떤 키워드를 앞에 붙여 '상수'로 만들 수 있을까?",
            "'변하지 않는', '일정한'을 의미하는 영어 단어를 떠올려보세요.",
            {
                {"static", "땡! 'static'은 변수의 생명주기와 관련된 다른 중요한 키워드야.", false},
                {"final", "아깝다! 'final'은 Java 같은 다른 프로그래밍 언어에서 비슷한 역할을 하는 키워드야.", false},
                {"const", "완벽해! 'const' 키워드를 붙이면 변수는 상수가 되어서, 한번 정해진 값을 절대 바꿀 수 없게 돼.", true},
                {"var", "아니야! 'var'는 JavaScript 같은 언어에서 변수를 선언할 때 사용돼.", false}
            }
        },
        // --- 6. 정수 나눗셈 퀴즈 ---
        {
            "'명랑한 비숑'이 나타나 문제를 내. \"`int a = 7, b = 2;` 일 때, `a / b`의 결과값은 무엇일까?\"",
            "정수(int)와 정수(int)의 나눗셈 결과는 어떻게 될까요? 소수점은 어떻게 처리될까요?",
            {
                {"3.5", "아깝다! C++에서 정수끼리의 나눗셈은 결과도 정수가 돼. 소수점 이하는 가차없이 버려진다구!", false},
                {"3", "정답이야! `int`와 `int`를 나누면 결과도 `int`가 되기 때문에, 3.5에서 소수점 이하를 버린 3이 정답이야!", true},
                {"4", "땡! 반올림을 해버렸구나! C++의 정수 나눗셈은 반올림이 아니라 '버림'을 해.", false},
                {"2", "이런! 혹시 나머지 연산(%)이랑 헷갈린 거 아니야? `7 / 2` 는 몫을 구하는 연산이야.", false}
            }
        },
        // --- 7. 논리 연산자 퀴즈 ---
        {
            "어두운 동굴을 지나가려면 두 조건이 모두 참이어야 해. '횃불이 있다(true)' 그리고 '용기가 있다(true)'라는 두 조건을 동시에 만족하는지 확인하려면 어떤 논리 연산자를 써야 할까?",
            "AND, OR, NOT 중에서 '그리고'의 의미를 가진 연산자를 찾아보세요.",
            {
                {"||", "아니야! `||` (OR) 연산자는 둘 중 하나만 참이어도 통과시켜줘. 지금은 둘 다 필요한 상황이야!", false},
                {"!", "땡! `!` (NOT) 연산자는 결과의 참/거짓을 뒤집는 역할을 해. 두 조건을 연결할 수는 없어.", false},
                {"&&", "정답! `&&` (AND) 연산자는 두 조건이 '모두' 참일 때만 참(true)을 반환해. 동굴을 무사히 통과했어!", true},
                {"&", "주의! `&` 하나만 쓰는 건 '비트 AND 연산자'야. 지금처럼 참/거짓을 따지는 논리 연산에는 `&&` 두 개를 써야 해!", false}
            }
        },
        // --- 8. 변수 이름 규칙 퀴즈 ---
        {
            "C++에서 변수 이름을 지을 때, 다음 중 규칙에 어긋나는 이름은 무엇일까?",
            "변수 이름은 공백이나 특수문자를 포함할 수 없어요.",
            {
                {"my_hp", "이건 괜찮아! 변수 이름에는 밑줄(_)을 사용할 수 있어.", false},
                {"_totalScore", "이것도 괜찮아! 변수 이름은 밑줄(_)로 시작할 수 있어.", false},
                {"level2", "이것도 괜찮아! 변수 이름에는 숫자가 포함될 수 있어. 단, 숫자로 시작할 수 없을 뿐이야.", false},
                {"my score", "이게 정답! 변수 이름에는 공백(whitespace)이 들어갈 수 없어. 'myScore'나 'my_score'로 써야 해.", true}
            }
        },
        // --- 9. 증감 연산자 퀴즈 ---
        {
            "파트너의 현재 체력이 50이야. `my_partner.hp++;` 라는 코드를 실행하면 체력은 얼마가 될까?",
            "`++` 연산자는 변수의 값을 1만큼 증가시켜요.",
            {
                {"50", "아니야! `++` 연산자가 실행되었기 때문에 체력에 변화가 생겼어.", false},
                {"51", "맞았어! `++` (증가 연산자)는 변수의 값을 1 증가시켜. 파트너가 힘을 얻어 체력이 51로 회복했어!", true},
                {"52", "너무 많이 회복했는걸! `++`는 1만큼만 증가시켜. `hp += 2` 라고 써야 2만큼 올라가.", false},
                {"49", "반대 방향이야! `--` (감소 연산자)를 썼다면 49가 맞겠지만, `++`는 증가시키는 연산자야.", false}
            }
        },
        // --- 10. auto 키워드 퀴즈 ---
        {
            "`auto myVar = 9.99;` 와 같이 변수를 선언했을 때, `myVar`의 데이터 타입은 컴파일러에 의해 무엇으로 결정될까?",
            "`auto`는 할당되는 값의 형태를 보고 타입을 스스로 결정해요. 9.99는 어떤 종류의 숫자일까요?",
            {
                {"int", "땡! 9.99는 소수점을 가지고 있기 때문에 정수 타입인 'int'가 될 수 없어.", false},
                {"string", "아니야! 큰따옴표(\"\")로 묶여 `\"9.99\"` 였다면 'string'이 맞겠지만, 지금은 순수한 숫자야.", false},
                {"double", "정답! `auto` 키워드는 컴파일러가 값(9.99)을 보고 타입을 추론하게 해. 소수점이 있는 실수는 기본적으로 'double' 타입으로 결정돼.", true},
                {"void", "이런! 'void'는 '타입이 없음'을 의미하는 특별한 키워드야. 변수의 타입으로 사용될 수 없어!", false}
            }
        },
        // --- 11. 비교 연산자 퀴즈 ---
        {
            "다음 중 두 값이 '같지 않다'를 비교하는 연산자는 무엇일까?",
            "같다'는 `==` 로 표현해요. 그럼 '같지 않다'는 느낌표를 사용해서 어떻게 표현할까요?",
            {
                {"><", "땡! 그런 연산자는 C++에 없어!", false},
                {"!=", "정답이야! `!=` 연산자는 두 값이 서로 다른지 비교해서, 다르면 true를, 같으면 false를 반환해. 올바른 길을 찾았어!", true},
                {"==", "반대야! `==` 연산자는 두 값이 '같다'를 비교할 때 사용해!", false},
                {"=:=", "아깝다! `:=` 같은 연산자는 다른 언어에는 있지만, C++의 비교 연산자는 아니야.", false}
            }
        },
        // --- 12. 비교 연산자 퀴즈 2 ---
        {
            "간식을 사려고 해. `int price = 50;` 이고 `int myMoney = 50;` 일 때, `myMoney >= price` 비교 연산의 결과는 무엇일까?",
            "`>=`는 '크거나 같다'는 의미예요. 두 값이 같은 경우도 포함될까요?",
            {
                {"true (1)", "맞았어! `myMoney`는 `price`보다 크진 않지만 '같기' 때문에, '크거나 같다'(`>=`)는 조건은 참(true)이 돼. 무사히 간식을 샀어!", true},
                {"false (0)", "아니야! `>` 였다면 false가 맞겠지만, `>=`는 두 값이 같은 경우도 참(true)으로 인정해줘. 간식을 눈앞에서 놓쳤어!", false},
                {"컴파일 에러", "아니야! `>=`는 완벽하게 올바른 C++ 비교 연산자야.", false},
                {"50", "이런! 비교 연산의 결과는 숫자 값이 아니라, 참(true) 또는 거짓(false)이라는 논리 값이야.", false}
            }
        },
        // --- 13. 다중 할당 퀴즈 ---
        {
            "`int x, y, z; x = y = z = 100;` 처럼 코드를 작성했을 때, 세 변수에 모두 동일한 값이 할당될까?",
            "할당 연산자(=)는 오른쪽에서 왼쪽으로 동작해요.",
            {
                {"x에만 100이 할당된다.", "아니야! 할당 연산은 오른쪽부터 차례대로 실행돼. `z=100`이 먼저 실행되고, 그 결과가 `y`에, 또 그 결과가 `x`에 전달되지.", false},
                {"컴파일 에러가 발생한다.", "아니야! 이건 여러 변수에 같은 값을 할당하는 C++의 올바른 문법이야.", false},
                {"된다. 세 변수 모두 100이 된다.", "정답이야! C++에서는 이렇게 한 줄로 여러 변수에 동일한 값을 할당할 수 있어!", true},
                {"z에만 100이 할당된다.", "땡! 할당 연산자는 오른쪽에서 왼쪽으로 연쇄적으로 일어나. `z=100`에서 멈추지 않아!", false}
            }
        },
        // --- 14. 실수 나눗셈 퀴즈 ---
        {
            "마지막 관문! `double a = 10.0; int b = 4;` 일 때, `a / b`의 결과값은 무엇일까?",
            "실수(`double`)와 정수(`int`)가 만나면 어떻게 될까요? 결과는 더 넓은 범위를 가진 타입을 따라가요.",
            {
                {"2", "아니야! 이번엔 한쪽이 `double`이기 때문에 정수 나눗셈처럼 소수점을 버리지 않아.", false},
                {"2.0", "거의 다 왔어! 계산 결과는 맞지만, 타입이 `double`이므로 소수점 이하까지 정확하게 표현될 거야.", false},
                {"2.5", "완벽해! 연산에 `double`이 하나라도 포함되면, 다른 타입이 `double`로 자동 형변환되어 계산돼. 그래서 결과도 `double`인 2.5가 나와. 드디어 지식의 산 정상이야!", true},
                {"3", "땡! 정수 나눗셈의 규칙과 헷갈렸구나! 실수(`double`)가 포함된 연산은 결과를 버리거나 반올림하지 않아.", false}
            }
        }
    };
}


int main() {
    // 게임 시작 시 필요한 초기 설정
    srand(time(0));
    setlocale(LC_ALL, "");

    // 퀴즈 데이터 준비
    vector<Question> quiz = initializeQuiz();
    
    // --- 캐릭터 초기화 및 선택 ---
    vector<Character> all_characters = initializeCharacters();
    cout << "---------- 최종 관문: 지식의 산 정복! ----------" << endl;
    cout << "도전할 당신의 파트너를 선택하세요!" << endl;
    for (int i = 0; i < all_characters.size(); ++i) {
        cout << i + 1 << ". " << all_characters[i].species << endl;
    }
    
    int player_choice_idx;
    while (true) {
        cout << "\n당신의 선택은? (숫자 입력): ";
        cin >> player_choice_idx;
        if (cin.good() && player_choice_idx > 0 && player_choice_idx <= all_characters.size()) {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "잘못된 입력입니다. 1부터 " << all_characters.size() << " 사이의 숫자를 입력해주세요." << endl;
    }
    player_choice_idx--;

    Character player_character = all_characters[player_choice_idx];
    all_characters.erase(all_characters.begin() + player_choice_idx); // 퀴즈 출제자 목록에서 플레이어 제외

    // --- 사용자 커스터마이징 ---
    cout << "\n파트너의 프로필을 직접 설정하시겠습니까? (y/n): ";
    char custom_choice;
    cin >> custom_choice;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    if (custom_choice == 'y' || custom_choice == 'Y') {
        cout << "파트너의 진짜 이름은?: ";
        getline(cin, player_character.name);
        cout << player_character.name << "의 장래희망은?: ";
        getline(cin, player_character.future_hope);
    }
    
    cout << "\n좋아! " << player_character.name << "와(과) 함께 지식의 산 정복을 시작합니다!" << endl;
    player_character.showProfile();
    cout << "\n" << endl;


    // --- 통합 미니 게임 시작 ---
    for (int i = 0; i < quiz.size(); ++i) {
        cout << "\n\n========== " << i + 1 << "번째 문제 ==========" << endl;
        if (player_character.hp <= 0) {
            cout << "체력이 0이 되어 더 이상 진행할 수 없습니다..." << endl;
            break;
        }

        // 현재 문제와 퀴즈 마스터(NPC) 설정
        Question& current_question = quiz[i];
        Character& quiz_master = all_characters[rand() % all_characters.size()];

        cout << "\n수호자 '" << quiz_master.name << "'이(가) 나타났다!" << endl;
        quiz_master.display("thinking");
        
        cout << "\n[문제] " << current_question.questionText << endl;
        cout << "[힌트] " << current_question.hint << endl;
        
        // 선택지 출력
        for (int j = 0; j < current_question.options.size(); ++j) {
            cout << "  " << j + 1 << ". " << current_question.options[j].text << endl;
        }

        int user_answer_idx;
        while (true) {
            cout << "\n정답은? (숫자 입력): ";
            cin >> user_answer_idx;
            if (cin.good() && user_answer_idx > 0 && user_answer_idx <= current_question.options.size()) {
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "잘못된 입력입니다. 보기 중 하나의 숫자를 입력해주세요." << endl;
        }
        user_answer_idx--;

        // 정답 확인 및 결과 출력
        AnswerOption& chosen_option = current_question.options[user_answer_idx];
        
        cout << "\n--- 결과 ---" << endl;
        if (chosen_option.isCorrect) {
            cout << "정답입니다!" << endl;
            player_character.display("happy");
            quiz_master.display("surprised");
        } else {
            cout << "틀렸습니다! (HP -20)" << endl;
            player_character.hp -= 20;
            player_character.display("sad");
            quiz_master.display("sad");
        }
        
        cout << "\n[설명] " << chosen_option.rationale << endl;
        cout << "\n현재 " << player_character.name << "의 HP: " << player_character.hp << endl;
        cout << "계속하려면 Enter 키를 누르세요...";
        cin.get();
    }

    // --- 최종 결과 ---
    cout << "\n\n\n========== 도전 종료 ==========" << endl;
    if (player_character.hp > 0) {
        cout << "축하합니다! " << player_character.name << "는(은) 지식의 산 정상에 무사히 도착했습니다!" << endl;
        player_character.display("happy");
    } else {
        player_character.display("sad");
        cout << "아쉽지만, " << player_character.name << "는(은) 쓰러지고 말았습니다. 다음 기회에 다시 도전해요!" << endl;
    }
    cout << "\nC++ 스터디 기본 과정이 모두 끝났습니다. 정말 수고 많으셨습니다!" << endl;

    return 0;
}