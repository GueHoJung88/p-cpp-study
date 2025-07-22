#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

// ===== 캐릭터 시스템 =====
class Character {
public:
    string name;
    string species;
    string role;
    
    Character(string n, string s, string r) : name(n), species(s), role(r) {}
    
    void display(const string& emotion = "default") {
        cout << "\n=== " << name << " (" << species << ") - " << role << " ===" << endl;
        
        if (species == "치와와") {
            if (emotion == "happy") {
                cout << " (\\_/)" << endl;
                cout << " (o.o)" << endl;
                cout << " / > o  \"와아! 정말 재미있어!\"" << endl;
            } else if (emotion == "thinking") {
                cout << " (\\_/)" << endl;
                cout << " (._.?)" << endl;
                cout << " / > ?  \"음... 생각해보자!\"" << endl;
            } else if (emotion == "surprised") {
                cout << " (\\o_o/)" << endl;
                cout << " ( o_o )" << endl;
                cout << " / > !  \"깜짝이야! 신기해!\"" << endl;
            } else if (emotion == "explain") {
                cout << " (\\_/)" << endl;
                cout << " (^_^)" << endl;
                cout << " / > *  \"자세히 설명해드릴게요!\"" << endl;
            } else {
                cout << " (\\_/)" << endl;
                cout << " (*.*)" << endl;
                cout << " / >   " << endl;
            }
        } else if (species == "웰시코기") {
            if (emotion == "happy") {
                cout << " (o.o)" << endl;
                cout << " /-----\\" << endl;
                cout << "  |   |   \"기분 최고야! 콩콩!\"" << endl;
            } else if (emotion == "thinking") {
                cout << " (._.?)" << endl;
                cout << " /-----\\" << endl;
                cout << "  |   |   \"정답이 뭐더라...\"" << endl;
            } else if (emotion == "explain") {
                cout << " (^_^)" << endl;
                cout << " /-----\\" << endl;
                cout << "  |   |   \"이해하기 쉽게 설명할게요!\"" << endl;
            } else {
                cout << " (o.o)" << endl;
                cout << " /-----\\" << endl;
                cout << "  |   |   " << endl;
            }
        } else if (species == "골든리트리버") {
            if (emotion == "happy") {
                cout << " U・ᴥ・U" << endl;
                cout << " / >🦴  \"주인님 짱이에요!\"" << endl;
            } else if (emotion == "explain") {
                cout << " U・ᴥ・U" << endl;
                cout << " / >📚  \"제가 도와드릴게요!\"" << endl;
            } else {
                cout << " U・ᴥ・U" << endl;
                cout << " / >   " << endl;
            }
        } else if (species == "토끼") {
            if (emotion == "quiz") {
                cout << " (\\(\\ " << endl;
                cout << " ( •‿•)   \"퀴즈 시간이에요!\"" << endl;
                cout << " o( o )o" << endl;
            } else if (emotion == "happy") {
                cout << " (\\(\\ " << endl;
                cout << " (≧▽≦)   \"정답이에요! 똑똑하네요!\"" << endl;
                cout << " o( o )o" << endl;
            } else {
                cout << " (\\(\\ " << endl;
                cout << " ( •‿•)   " << endl;
                cout << " o( o )o" << endl;
            }
        } else if (species == "고양이") {
            if (emotion == "judge") {
                cout << " /\\_/\\ " << endl;
                cout << " (≧▽≦)  \"채점해드릴게요!\"" << endl;
            } else if (emotion == "correct") {
                cout << " /\\_/\\ " << endl;
                cout << " (≧▽≦)  \"정답이냥~ 똑똑하구나!\"" << endl;
            } else if (emotion == "wrong") {
                cout << " /\\_/\\ " << endl;
                cout << " (ಠ_ಠ)  \"틀렸군... 다음엔 더 잘하자냥.\"" << endl;
            } else {
                cout << " /\\_/\\ " << endl;
                cout << " (•_•)  " << endl;
            }
        }
        cout << endl;
    }
};

// ===== 캐릭터 초기화 =====
vector<Character> initializeCharacters() {
    return {
        Character("초코", "치와와", "변수 전문가"),
        Character("콩이", "웰시코기", "입력 처리 전문가"),
        Character("골디", "골든리트리버", "데이터 타입 전문가"),
        Character("토토", "토끼", "퀴즈 마스터"),
        Character("냥이", "고양이", "채점 전문가")
    };
}

// ===== 유틸리티 함수들 =====
void waitForKey() {
    cout << "\n📝 아무 키나 눌러서 다음으로 진행하세요... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    cout << "\n" << string(50, '=') << "\n" << endl;
}

void printHeader(const string& title) {
    cout << "\n" << string(60, '⭐') << endl;
    cout << "🌟 " << title << " 🌟" << endl;
    cout << string(60, '⭐') << endl;
}

// ===== 1. 변수(Variables) 학습 =====
void learnVariables(Character& teacher) {
    printHeader("1단계: 변수(Variables) 학습");
    
    teacher.display("explain");
    cout << "안녕하세요! 저는 " << teacher.name << "입니다! 변수에 대해 자세히 설명해드릴게요!" << endl;
    
    cout << "\n📚 변수란 무엇일까요?" << endl;
    cout << "변수는 데이터를 저장하는 '상자'입니다. 마치 우리가 물건을 상자에 넣어두는 것처럼," << endl;
    cout << "컴퓨터도 데이터를 변수라는 상자에 넣어두고 필요할 때 꺼내서 사용해요!" << endl;
    
    waitForKey();
    
    cout << "🔍 변수의 특징:" << endl;
    cout << "1. 이름이 있어야 해요 (변수명)" << endl;
    cout << "2. 타입이 있어야 해요 (데이터 타입)" << endl;
    cout << "3. 값을 저장할 수 있어요" << endl;
    cout << "4. 언제든지 값을 바꿀 수 있어요" << endl;
    
    waitForKey();
    
    cout << "💡 변수 선언 예시:" << endl;
    cout << "int age = 5;        // 정수형 변수" << endl;
    cout << "string name = \"초코\";  // 문자열 변수" << endl;
    cout << "double height = 15.5;  // 실수형 변수" << endl;
    cout << "bool isHappy = true;   // 불린형 변수" << endl;
    
    waitForKey();
    
    teacher.display("thinking");
    cout << "실제로 변수를 만들어볼까요?" << endl;
    cout << "당신의 파트너 강아지 정보를 변수에 저장해보세요!" << endl;
    
    string dogName;
    int dogAge;
    double dogWeight;
    
    cout << "\n강아지 이름을 입력하세요: ";
    cin >> dogName;
    
    cout << "강아지 나이를 입력하세요: ";
    cin >> dogAge;
    
    cout << "강아지 몸무게(kg)를 입력하세요: ";
    cin >> dogWeight;
    
    cout << "\n🎉 저장 완료!" << endl;
    cout << "이름: " << dogName << endl;
    cout << "나이: " << dogAge << "살" << endl;
    cout << "몸무게: " << dogWeight << "kg" << endl;
    
    teacher.display("happy");
    cout << "와아! 변수에 데이터를 성공적으로 저장했어요!" << endl;
    
    waitForKey();
}

// ===== 2. 사용자 입력(User Input) 학습 =====
void learnUserInput(Character& teacher) {
    printHeader("2단계: 사용자 입력(User Input) 학습");
    
    teacher.display("explain");
    cout << "안녕하세요! 저는 " << teacher.name << "입니다! 사용자 입력에 대해 설명해드릴게요!" << endl;
    
    cout << "\n📚 사용자 입력이란?" << endl;
    cout << "프로그램이 실행 중에 사용자로부터 데이터를 받는 것을 말해요." << endl;
    cout << "마치 대화하듯이 프로그램과 사용자가 정보를 주고받는 거죠!" << endl;
    
    waitForKey();
    
    cout << "🔍 C++에서 사용자 입력 받기:" << endl;
    cout << "cin >> 변수명;  // 기본 형태" << endl;
    cout << "cin은 'Console Input'의 줄임말이에요!" << endl;
    
    waitForKey();
    
    cout << "💡 다양한 입력 방법:" << endl;
    cout << "1. cin >> 변수;     // 기본 입력" << endl;
    cout << "2. getline(cin, 문자열변수);  // 공백 포함 문자열 입력" << endl;
    cout << "3. cin.get();       // 한 글자 입력" << endl;
    
    waitForKey();
    
    teacher.display("thinking");
    cout << "실제로 다양한 입력을 받아볼까요?" << endl;
    
    string name;
    int age;
    char grade;
    double score;
    
    cout << "\n이름을 입력하세요: ";
    cin >> name;
    
    cout << "나이를 입력하세요: ";
    cin >> age;
    
    cout << "성적 등급을 입력하세요 (A/B/C/D/F): ";
    cin >> grade;
    
    cout << "점수를 입력하세요 (소수점 가능): ";
    cin >> score;
    
    cout << "\n📋 입력된 정보:" << endl;
    cout << "이름: " << name << endl;
    cout << "나이: " << age << "살" << endl;
    cout << "성적 등급: " << grade << endl;
    cout << "점수: " << score << "점" << endl;
    
    teacher.display("happy");
    cout << "훌륭해요! 다양한 타입의 입력을 성공적으로 받았어요!" << endl;
    
    waitForKey();
}

// ===== 3. 데이터 타입(Data Types) 심화 학습 =====
void learnDataTypes(Character& teacher) {
    printHeader("3단계: 데이터 타입(Data Types) 심화 학습");
    
    teacher.display("explain");
    cout << "안녕하세요! 저는 " << teacher.name << "입니다! 데이터 타입에 대해 자세히 설명해드릴게요!" << endl;
    
    cout << "\n📚 데이터 타입이란?" << endl;
    cout << "데이터의 종류와 크기를 정의하는 규칙이에요." << endl;
    cout << "마치 상자의 크기와 용도를 미리 정해두는 것과 같아요!" << endl;
    
    waitForKey();
    
    // ===== 정수형 데이터 타입 =====
    cout << "\n🔢 정수형 데이터 타입" << endl;
    cout << string(50, '-') << endl;
    
    cout << "1. char (문자형)" << endl;
    cout << "   - 크기: " << sizeof(char) << "바이트 (" << sizeof(char) * 8 << "비트)" << endl;
    cout << "   - 범위: " << CHAR_MIN << " ~ " << CHAR_MAX << endl;
    cout << "   - 용도: 단일 문자 저장" << endl;
    cout << "   - 예시: char grade = 'A';" << endl;
    
    waitForKey();
    
    cout << "2. short (짧은 정수형)" << endl;
    cout << "   - 크기: " << sizeof(short) << "바이트 (" << sizeof(short) * 8 << "비트)" << endl;
    cout << "   - 범위: " << SHRT_MIN << " ~ " << SHRT_MAX << endl;
    cout << "   - 용도: 작은 정수 저장" << endl;
    cout << "   - 예시: short age = 25;" << endl;
    
    waitForKey();
    
    cout << "3. int (정수형)" << endl;
    cout << "   - 크기: " << sizeof(int) << "바이트 (" << sizeof(int) * 8 << "비트)" << endl;
    cout << "   - 범위: " << INT_MIN << " ~ " << INT_MAX << endl;
    cout << "   - 용도: 일반적인 정수 저장" << endl;
    cout << "   - 예시: int count = 1000;" << endl;
    
    waitForKey();
    
    cout << "4. long (긴 정수형)" << endl;
    cout << "   - 크기: " << sizeof(long) << "바이트 (" << sizeof(long) * 8 << "비트)" << endl;
    cout << "   - 범위: " << LONG_MIN << " ~ " << LONG_MAX << endl;
    cout << "   - 용도: 큰 정수 저장" << endl;
    cout << "   - 예시: long population = 8000000000L;" << endl;
    
    waitForKey();
    
    cout << "5. long long (매우 긴 정수형)" << endl;
    cout << "   - 크기: " << sizeof(long long) << "바이트 (" << sizeof(long long) * 8 << "비트)" << endl;
    cout << "   - 범위: " << LLONG_MIN << " ~ " << LLONG_MAX << endl;
    cout << "   - 용도: 매우 큰 정수 저장" << endl;
    cout << "   - 예시: long long bigNumber = 9223372036854775807LL;" << endl;
    
    waitForKey();
    
    // ===== 실수형 데이터 타입 =====
    cout << "\n🔢 실수형 데이터 타입" << endl;
    cout << string(50, '-') << endl;
    
    cout << "1. float (단정밀도 실수형)" << endl;
    cout << "   - 크기: " << sizeof(float) << "바이트 (" << sizeof(float) * 8 << "비트)" << endl;
    cout << "   - 정밀도: 약 7자리" << endl;
    cout << "   - 범위: " << FLT_MIN << " ~ " << FLT_MAX << endl;
    cout << "   - 예시: float pi = 3.14159f;" << endl;
    
    waitForKey();
    
    cout << "2. double (배정밀도 실수형)" << endl;
    cout << "   - 크기: " << sizeof(double) << "바이트 (" << sizeof(double) * 8 << "비트)" << endl;
    cout << "   - 정밀도: 약 15자리" << endl;
    cout << "   - 범위: " << DBL_MIN << " ~ " << DBL_MAX << endl;
    cout << "   - 예시: double precisePi = 3.14159265359;" << endl;
    
    waitForKey();
    
    cout << "3. long double (확장 정밀도 실수형)" << endl;
    cout << "   - 크기: " << sizeof(long double) << "바이트 (" << sizeof(long double) * 8 << "비트)" << endl;
    cout << "   - 정밀도: 약 19자리" << endl;
    cout << "   - 예시: long double veryPrecise = 3.14159265359L;" << endl;
    
    waitForKey();
    
    // ===== 기타 데이터 타입 =====
    cout << "\n🔢 기타 데이터 타입" << endl;
    cout << string(50, '-') << endl;
    
    cout << "1. bool (불린형)" << endl;
    cout << "   - 크기: " << sizeof(bool) << "바이트 (" << sizeof(bool) * 8 << "비트)" << endl;
    cout << "   - 값: true 또는 false" << endl;
    cout << "   - 예시: bool isHappy = true;" << endl;
    
    waitForKey();
    
    cout << "2. string (문자열형)" << endl;
    cout << "   - 크기: 가변적 (보통 24바이트 + 문자열 길이)" << endl;
    cout << "   - 용도: 텍스트 저장" << endl;
    cout << "   - 예시: string name = \"초코\";" << endl;
    
    waitForKey();
    
    // ===== 타입 변환과 주의사항 =====
    cout << "\n⚠️ 타입 변환과 주의사항" << endl;
    cout << string(50, '-') << endl;
    
    teacher.display("thinking");
    cout << "타입 변환은 데이터를 다른 타입으로 바꾸는 것을 말해요!" << endl;
    
    cout << "\n1. 암시적 변환 (자동 변환)" << endl;
    cout << "   int a = 5;" << endl;
    cout << "   double b = a;  // int가 double로 자동 변환" << endl;
    cout << "   cout << b;     // 출력: 5.0" << endl;
    
    waitForKey();
    
    cout << "2. 명시적 변환 (캐스팅)" << endl;
    cout << "   double pi = 3.14159;" << endl;
    cout << "   int rounded = (int)pi;  // 명시적 변환" << endl;
    cout << "   cout << rounded;        // 출력: 3" << endl;
    
    waitForKey();
    
    cout << "3. 주의사항 - 데이터 손실" << endl;
    cout << "   double bigNumber = 3.14159;" << endl;
    cout << "   int smallNumber = (int)bigNumber;  // 소수점 손실!" << endl;
    cout << "   cout << smallNumber;               // 출력: 3" << endl;
    
    waitForKey();
    
    cout << "4. 주의사항 - 범위 초과" << endl;
    cout << "   int normal = 2147483647;  // int 최대값" << endl;
    cout << "   int overflow = normal + 1;  // 오버플로우 발생!" << endl;
    cout << "   cout << overflow;           // 출력: -2147483648" << endl;
    
    waitForKey();
    
    // ===== 실제 예제 =====
    cout << "\n🔬 실제 타입 변환 예제" << endl;
    cout << string(50, '-') << endl;
    
    teacher.display("surprised");
    cout << "실제로 타입 변환을 실험해볼까요?" << endl;
    
    double originalValue;
    cout << "소수점이 있는 숫자를 입력하세요 (예: 3.14159): ";
    cin >> originalValue;
    
    int convertedValue = (int)originalValue;
    float floatValue = (float)originalValue;
    
    cout << "\n📊 변환 결과:" << endl;
    cout << "원본 값 (double): " << originalValue << endl;
    cout << "정수 변환 (int): " << convertedValue << endl;
    cout << "실수 변환 (float): " << floatValue << endl;
    
    if (originalValue != convertedValue) {
        cout << "⚠️ 주의: 정수 변환 시 소수점이 손실되었어요!" << endl;
    }
    
    teacher.display("happy");
    cout << "훌륭해요! 데이터 타입과 변환에 대해 잘 이해했어요!" << endl;
    
    waitForKey();
}

// ===== 4. 연산자(Operators) 학습 =====
void learnOperators(Character& teacher) {
    printHeader("4단계: 연산자(Operators) 학습");
    
    teacher.display("explain");
    cout << "안녕하세요! 저는 " << teacher.name << "입니다! 연산자에 대해 설명해드릴게요!" << endl;
    
    cout << "\n📚 연산자란?" << endl;
    cout << "데이터를 조작하고 계산하는 기호들을 말해요." << endl;
    cout << "마치 수학에서 +, -, ×, ÷ 같은 기호와 비슷해요!" << endl;
    
    waitForKey();
    
    cout << "🔍 산술 연산자" << endl;
    cout << string(50, '-') << endl;
    cout << "+ : 덧셈" << endl;
    cout << "- : 뺄셈" << endl;
    cout << "* : 곱셈" << endl;
    cout << "/ : 나눗셈 (몫)" << endl;
    cout << "% : 나머지" << endl;
    
    waitForKey();
    
    cout << "🔍 할당 연산자" << endl;
    cout << string(50, '-') << endl;
    cout << "= : 기본 할당" << endl;
    cout << "+= : 더하고 할당" << endl;
    cout << "-= : 빼고 할당" << endl;
    cout << "*= : 곱하고 할당" << endl;
    cout << "/= : 나누고 할당" << endl;
    cout << "%= : 나머지를 할당" << endl;
    
    waitForKey();
    
    cout << "🔍 비교 연산자" << endl;
    cout << string(50, '-') << endl;
    cout << "== : 같음" << endl;
    cout << "!= : 다름" << endl;
    cout << "> : 큼" << endl;
    cout << "< : 작음" << endl;
    cout << ">= : 크거나 같음" << endl;
    cout << "<= : 작거나 같음" << endl;
    
    waitForKey();
    
    cout << "🔍 논리 연산자" << endl;
    cout << string(50, '-') << endl;
    cout << "&& : AND (그리고)" << endl;
    cout << "|| : OR (또는)" << endl;
    cout << "! : NOT (아님)" << endl;
    
    waitForKey();
    
    teacher.display("thinking");
    cout << "실제로 연산자를 사용해볼까요?" << endl;
    
    int num1, num2;
    cout << "\n첫 번째 숫자를 입력하세요: ";
    cin >> num1;
    cout << "두 번째 숫자를 입력하세요: ";
    cin >> num2;
    
    cout << "\n📊 연산 결과:" << endl;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;
    
    cout << "\n📊 비교 결과:" << endl;
    cout << num1 << " == " << num2 << " : " << (num1 == num2 ? "참" : "거짓") << endl;
    cout << num1 << " != " << num2 << " : " << (num1 != num2 ? "참" : "거짓") << endl;
    cout << num1 << " > " << num2 << " : " << (num1 > num2 ? "참" : "거짓") << endl;
    cout << num1 << " < " << num2 << " : " << (num1 < num2 ? "참" : "거짓") << endl;
    
    teacher.display("happy");
    cout << "훌륭해요! 연산자 사용법을 잘 이해했어요!" << endl;
    
    waitForKey();
}

// ===== 퀴즈 시스템 =====
struct QuizQuestion {
    string question;
    vector<string> options;
    int correctAnswer;
    string explanation;
};

vector<QuizQuestion> createQuiz() {
    return {
        {
            "다음 중 올바른 변수 선언은 무엇일까요?",
            {"int 3dogs = 5;", "int dogs = 'five';", "int dogs = 5;", "string dogs = five;"},
            2,
            "3번이 정답! int형 변수 dogs를 정수 5로 초기화했습니다. 1번은 변수명이 숫자로 시작해서 안되고, 2번은 문자를 int에 넣을 수 없고, 4번은 따옴표가 빠졌어요!"
        },
        {
            "사용자 입력을 받을 때 사용하는 객체는 무엇인가요?",
            {"cout", "cin", "int", "string"},
            1,
            "2번이 정답! cin은 Console Input의 줄임말로, 키보드 입력을 받는 객체예요!"
        },
        {
            "int 타입의 크기는 몇 바이트일까요?",
            {"1바이트", "2바이트", "4바이트", "8바이트"},
            2,
            "3번이 정답! int는 보통 4바이트(32비트)를 차지해요. 시스템에 따라 다를 수 있지만 대부분 4바이트입니다!"
        },
        {
            "5 + 3 * 2의 결과는? (연산자 우선순위 고려)",
            {"11", "16", "13", "10"},
            0,
            "1번이 정답! 곱셈이 덧셈보다 우선순위가 높아서 3 * 2 = 6, 5 + 6 = 11이에요!"
        },
        {
            "다음 중 실수형 데이터 타입이 아닌 것은?",
            {"float", "double", "int", "long double"},
            2,
            "3번이 정답! int는 정수형이고, float, double, long double은 모두 실수형이에요!"
        },
        {
            "변수명 규칙 중 올바른 것은?",
            {"숫자로 시작할 수 있다", "공백을 포함할 수 있다", "언더스코어(_)를 사용할 수 있다", "특수문자를 자유롭게 사용할 수 있다"},
            2,
            "3번이 정답! 언더스코어(_)는 변수명에 사용할 수 있어요. 숫자로 시작하거나 공백, 특수문자는 사용할 수 없어요!"
        },
        {
            "double 타입의 정밀도는 약 몇 자리일까요?",
            {"7자리", "15자리", "19자리", "25자리"},
            1,
            "2번이 정답! double은 약 15자리의 정밀도를 가져요. float는 7자리, long double은 19자리 정도예요!"
        },
        {
            "bool 타입이 가질 수 있는 값은?",
            {"true와 false", "0과 1", "true, false, 0, 1", "true만"},
            0,
            "1번이 정답! bool 타입은 true와 false 두 가지 값만 가질 수 있어요!"
        }
    };
}

void runQuiz(vector<Character>& characters) {
    printHeader("🎯 최종 퀴즈: 학습 내용 확인");
    
    Character& rabbit = characters[3];  // 토끼
    Character& cat = characters[4];     // 고양이
    
    rabbit.display("quiz");
    cout << "안녕하세요! 저는 " << rabbit.name << "입니다!" << endl;
    cout << "지금까지 배운 내용을 퀴즈로 확인해볼까요?" << endl;
    cout << "총 8문제를 풀어보세요!" << endl;
    
    waitForKey();
    
    vector<QuizQuestion> quiz = createQuiz();
    int score = 0;
    int totalQuestions = quiz.size();
    
    for (int i = 0; i < quiz.size(); i++) {
        cout << "\n" << string(50, '=') << endl;
        cout << "문제 " << (i + 1) << "/" << totalQuestions << endl;
        cout << string(50, '=') << endl;
        
        rabbit.display("quiz");
        cout << quiz[i].question << endl;
        cout << endl;
        
        for (int j = 0; j < quiz[i].options.size(); j++) {
            cout << (j + 1) << ". " << quiz[i].options[j] << endl;
        }
        
        cout << "\n번호를 입력하세요 (1~4): ";
        int answer;
        cin >> answer;
        
        cat.display("judge");
        
        bool correct = (answer == quiz[i].correctAnswer + 1);
        if (correct) {
            cat.display("correct");
            score++;
            cout << "🎉 정답입니다!" << endl;
        } else {
            cat.display("wrong");
            cout << "❌ 틀렸습니다!" << endl;
        }
        
        cout << "\n📝 해설:" << endl;
        cout << quiz[i].explanation << endl;
        
        waitForKey();
    }
    
    // 최종 결과
    cout << "\n" << string(60, '🎉') << endl;
    cout << "🎊 최종 결과 발표! 🎊" << endl;
    cout << string(60, '🎉') << endl;
    
    double percentage = (double)score / totalQuestions * 100;
    
    cout << "\n📊 점수: " << score << "/" << totalQuestions << " (" << fixed << setprecision(1) << percentage << "%)" << endl;
    
    if (percentage >= 90) {
        cout << "🏆 우수상! 정말 똑똑하네요!" << endl;
    } else if (percentage >= 70) {
        cout << "🥈 양호! 잘했어요!" << endl;
    } else if (percentage >= 50) {
        cout << "🥉 보통! 더 공부하면 좋겠어요!" << endl;
    } else {
        cout << "📚 노력상! 다시 한번 복습해보세요!" << endl;
    }
    
    cout << "\n💡 학습 완료!" << endl;
    cout << "변수, 사용자 입력, 데이터 타입, 연산자에 대해 모두 배웠어요!" << endl;
    cout << "앞으로도 계속 공부해서 더 똑똑한 프로그래머가 되세요!" << endl;
}

// ===== 메인 함수 =====
int main() {
    cout << "🐾 C++ 기초 학습 프로그램에 오신 것을 환영합니다! 🐾" << endl;
    cout << "귀여운 캐릭터들과 함께 C++의 기초를 배워보세요!" << endl;
    
    vector<Character> characters = initializeCharacters();
    
    // 1단계: 변수 학습
    learnVariables(characters[0]);
    
    // 2단계: 사용자 입력 학습
    learnUserInput(characters[1]);
    
    // 3단계: 데이터 타입 심화 학습
    learnDataTypes(characters[2]);
    
    // 4단계: 연산자 학습
    learnOperators(characters[0]);
    
    // 최종 퀴즈
    runQuiz(characters);
    
    cout << "\n" << string(60, '🌟') << endl;
    cout << "🎉 수고하셨습니다! 🎉" << endl;
    cout << "C++ 기초 학습을 완료하셨네요!" << endl;
    cout << string(60, '🌟') << endl;
    
    return 0;
} 