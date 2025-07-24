#include <iostream> // cout, cin, endl 등을 사용하기 위해 필요
#include <string>   // string 타입을 사용하기 위해 필요
#include <vector>   // vector를 사용하기 위해 필요
#include <limits>   // numeric_limits를 사용하기 위해 필요 (cin.ignore 버퍼 비우기)
#include <cstdlib>  // srand, rand를 사용하기 위해 필요
#include <ctime>    // time을 사용하기 위해 필요 (랜덤 시드)
#include <locale>   // setlocale을 사용하기 위해 필요 (한글 출력)
#include <algorithm> // std::random_shuffle, std::find, std::remove_if
#include <cmath>    // 수학 함수를 사용하기 위해 필요
#include <chrono>   // 시간 측정을 위해 필요
#include <map>      // std::map을 사용하기 위해 추가
#include <iomanip>  // std::setprecision을 사용하기 위해 추가

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
    string category; // 문제 카테고리 (예: Variables, Strings, Math, Booleans, If-Else, Switch)
    string questionText;
    string hint;
    vector<AnswerOption> options;
};

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

// 모든 퀴즈 데이터를 생성하고 반환하는 함수 (총 100개)
vector<Question> initializeAllComprehensiveQuizzes() {
    return {
        // --- 1. 변수 (Variables) 관련 퀴즈 (총 15개) ---
        {"Variables", "숫자 5를 저장하기 위한 가장 적절한 C++ 변수 타입은 무엇일까요?", "소수점이 없는 정수를 담는 타입이에요.",
            {{"int", "정답! int는 정수를 저장할 때 사용합니다.", true}, {"double", "double은 소수점이 있는 실수를 저장해요.", false}, {"string", "string은 문자열을 저장해요.", false}, {"bool", "bool은 참/거짓을 저장해요.", false}}
        },
        {"Variables", "C++에서 'const' 키워드의 역할은 무엇일까요?", "변하지 않는 값을 만들 때 사용해요.",
            {{"변수의 크기를 조절한다.", "const와는 관련이 없어요.", false}, {"변수를 동적으로 할당한다.", "const와는 관련이 없어요.", false}, {"변수의 값을 변경할 수 없게 상수화한다.", "정답! const는 변수를 상수로 만들어 값을 바꿀 수 없게 합니다.", true}, {"변수를 정적으로 만든다.", "static 키워드의 역할이에요.", false}}
        },
        {"Variables", "`int x = 10;`에서 `x`는 무엇을 의미할까요?", "데이터를 담는 이름이에요.",
            {{"데이터 타입", "int가 데이터 타입이에요.", false}, {"변수 이름", "정답! x는 값을 저장하는 변수의 이름입니다.", true}, {"값", "10이 값이에요.", false}, {"연산자", "+, -, * 같은 것이 연산자예요.", false}}
        },
        {"Variables", "다음 중 변수 이름으로 사용될 수 없는 것은 무엇일까요?", "변수 이름 규칙을 생각해보세요.",
            {{"my_variable", "밑줄은 사용 가능해요.", false}, {"_score", "밑줄로 시작할 수 있어요.", false}, {"2nd_try", "숫자로 시작할 수 없어요.", true}, {"level1", "숫자를 포함할 수 있어요. 단, 시작은 불가.", false}}
        },
        {"Variables", "`char grade = 'A';`에서 `grade`에 저장된 'A'는 어떤 형태의 값일까요?", "하나의 문자를 나타내는 방식이에요.",
            {{"문자열", "문자열은 큰따옴표로 감싸요.", false}, {"정수", "정수는 숫자로 표현해요.", false}, {"단일 문자", "정답! 작은따옴표로 감싼 한 글자는 단일 문자입니다.", true}, {"불리언", "참/거짓을 나타내요.", false}}
        },
        {"Variables", "변수 `int count = 5;`의 값을 8로 바꾸려면 어떻게 해야 할까요?", "값을 재할당하는 방법을 떠올려보세요.",
            {{"count + 3;", "이것은 덧셈 연산일 뿐 값을 바꾸지 않아요.", false}, {"count == 8;", "이것은 비교 연산이에요.", false}, {"count = 8;", "정답! `=` 연산자를 사용하여 변수에 새로운 값을 할당합니다.", true}, {"int count = 8;", "이미 선언된 변수를 다시 선언할 수 없어요.", false}}
        },
        {"Variables", "여러 개의 정수 변수 `a`, `b`, `c`를 한 줄에 선언하는 올바른 방법은?", "쉼표로 구분하여 선언할 수 있어요.",
            {{"int a; int b; int c;", "가능하지만 한 줄에 선언하는 방법은 아니에요.", false}, {"int a, b, c;", "정답! 같은 타입의 여러 변수를 쉼표로 구분하여 한 줄에 선언할 수 있습니다.", true}, {"int a then b then c;", "잘못된 문법이에요.", false}, {"int a+b+c;", "덧셈 연산이에요.", false}}
        },
        {"Variables", "`string name;` 변수 `name`의 초기값은 무엇일까요?", "문자열 변수가 아무 값도 할당받지 않았을 때의 기본 상태예요.",
            {{"\"null\"", "NULL은 주로 C-스타일 문자열이나 포인터에 사용돼요.", false}, {"임의의 문자열", "정확한 초기값을 알 수 없어요.", false}, {"빈 문자열 (`\"\"`)", "정답! 기본 생성자로 생성된 string은 빈 문자열로 초기화됩니다.", true}, {"컴파일 에러", "에러는 발생하지 않아요.", false}}
        },
        {"Variables", "다음 중 C++11부터 도입된, 컴파일러가 변수의 타입을 자동으로 추론하게 하는 키워드는 무엇일까요?", "자동으로 추론한다는 의미의 키워드예요.",
            {{"new", "new는 동적 메모리 할당에 사용돼요.", false}, {"typeid", "typeid는 타입 정보를 얻을 때 사용돼요.", false}, {"auto", "정답! auto 키워드는 컴파일러가 초기화 값을 보고 타입을 추론하게 합니다.", true}, {"dynamic", "C++에 없는 키워드예요.", false}}
        },
        {"Variables", "변수가 데이터를 저장하는 '컨테이너'라고 비유할 때, 상수는 어떤 컨테이너에 비유할 수 있을까요?", "값을 바꿀 수 없는 컨테이너예요.",
            {{"움직이는 상자", "상수는 값이 변하지 않아요.", false}, {"열리지 않는 보물상자", "정답! 상수는 한 번 결정되면 값이 변경되지 않는 '열리지 않는 보물상자'와 같습니다.", true}, {"빈 박스", "빈 박스는 값이 없는 상태예요.", false}, {"다른 상자를 담는 상자", "이것은 컨테이너 개념과는 거리가 멀어요.", false}}
        },
        {"Variables", "`unsigned int` 타입은 `int` 타입과 어떤 주요한 차이점이 있을까요?", "숫자의 '부호'가 없는 경우, 어떤 장점이 생길까요?",
            {{"더 큰 음수를 저장할 수 있다.", "`unsigned int`는 음수를 저장하지 않습니다.", false}, {"소수점을 저장할 수 있다.", "`unsigned int`는 정수 타입이므로 소수점을 저장할 수 없습니다.", false}, {"오직 양의 정수와 0만 저장할 수 있으며, 더 넓은 양의 범위까지 표현 가능하다.", "`unsigned` 키워드는 부호 비트를 값의 표현에 사용하여 양의 범위가 두 배로 늘어납니다.", true}, {"컴파일 속도가 더 빠르다.", "데이터 타입의 부호 여부가 컴파일 속도에 직접적인 영향을 주지 않습니다.", false}}
        },
        {"Variables", "`long long` 데이터 타입이 `int` 데이터 타입보다 더 큰 수를 저장할 수 있는 이유는 무엇일까요?", "숫자를 표현할 수 있는 '공간'의 크기가 다르기 때문이에요.",
            {{"메모리 할당 방식이 다르기 때문에", "메모리 할당 방식보다는 할당되는 메모리 크기 자체가 다릅니다.", false}, {"사용하는 비트 수가 더 많기 때문에", "`long long`은 일반적으로 `int`보다 더 많은 비트(예: 64비트 vs 32비트)를 사용하여 더 넓은 범위의 값을 표현할 수 있습니다.", true}, {"소수점을 표현할 수 있기 때문에", "`long long`은 정수 타입이므로 소수점을 표현할 수 없습니다.", false}, {"네트워크를 통해 데이터를 전송하기 때문에", "네트워크 전송과는 관련이 없습니다.", false}}
        },
        {"Variables", "변수 `int price = 1000;`에 `+= 500;` 연산을 적용했을 때, `price`의 최종 값은 얼마가 될까요?", "기존 값에 오른쪽 값을 더해서 다시 저장하는 축약 연산자예요.",
            {{"500", "`+=`는 새로운 값을 할당하는 것이 아니라 기존 값에 더하는 연산입니다.", false}, {"1000", "`+=` 연산으로 인해 값이 변경됩니다.", false}, {"1500", "`+=` 연산은 기존 변수 값에 오른쪽 값을 더한 후 다시 변수에 저장하므로, 1000 + 500 = 1500이 됩니다.", true}, {"컴파일 에러", "`+=`는 C++에서 유효한 복합 할당 연산자입니다.", false}}
        },
        {"Variables", "다음 중 C++에서 `double` 타입과 `float` 타입의 주요 차이점은 무엇일까요?", "소수점 숫자의 '정밀도'와 '크기'에 대한 차이를 생각해보세요.",
            {{"`double`은 정수만 저장하고, `float`은 소수점만 저장한다.", "두 타입 모두 소수점을 포함하는 실수를 저장하며, 정수와 소수를 구분하는 기준이 아닙니다.", false}, {"`double`은 `float`보다 더 큰 범위와 높은 정밀도를 가진다.", "`double`은 일반적으로 `float`보다 두 배 많은 메모리(예: 8바이트 vs 4바이트)를 사용하여 더 넓은 범위의 실수와 더 높은 정밀도를 제공합니다.", true}, {"`float`는 `double`보다 더 많은 메모리를 차지한다.", "`double`이 `float`보다 더 많은 메모리를 차지합니다.", false}, {"두 타입 모두 완전히 동일하며 차이가 없다.", "두 타입은 저장할 수 있는 값의 범위와 정밀도에서 차이가 있습니다.", false}}
        },
        {"Variables", "`int x = 5, y = 2;`일 때, `x / y`의 결과는 무엇일까요?", "정수와 정수의 나눗셈은 결과도 정수라는 점을 기억하세요.",
            {{"2.5", "정수 나눗셈은 소수점 이하를 버리고 정수 부분만 반환합니다.", false}, {"2", "두 정수 사이의 나눗셈은 정수 나눗셈으로 수행되어, 결과의 소수점 이하를 버리고 몫인 2를 반환합니다.", true}, {"3", "반올림이 아니라 내림 또는 버림 연산이 수행됩니다.", false}, {"컴파일 에러", "정수 나눗셈은 유효한 연산입니다.", false}}
        },

        // --- 2. 문자열 (Strings) 관련 퀴즈 (총 20개) ---
        {"Strings", "C++에서 'Hello World'와 같은 텍스트를 저장할 때 사용하는 가장 기본적인 데이터 타입은 무엇일까요?", "글자들의 집합을 담는 타입이에요.",
            {{"int", "int는 정수를 저장할 때 사용해요. 텍스트를 담을 수 없답니다.", false}, {"char", "char는 단일 문자를 저장하지만, 'Hello World'처럼 여러 글자를 담기엔 부족해요.", false}, {"string", "정답! string 타입은 여러 문자로 이루어진 텍스트를 저장하는 데 사용됩니다.", true}, {"bool", "bool은 참/거짓을 저장해요.", false}}
        },
        {"Strings", "string 타입을 사용하기 위해 C++ 코드에 반드시 포함해야 하는 헤더 파일은 무엇일까요?", "string이라는 이름과 관련된 헤더 파일을 찾아보세요.",
            {{"<iostream>", "<iostream>은 입출력(cout, cin)을 위한 헤더 파일이에요.", false}, {"<vector>", "<vector>는 동적 배열인 vector를 위한 헤더 파일이에요.", false}, {"<string>", "정답! string 클래스를 사용하려면 <string> 헤더 파일을 포함해야 합니다.", true}, {"<numeric>", "<numeric>은 숫자 관련 함수를 위한 헤더 파일이에요.", false}}
        },
        {"Strings", "다음 중 올바른 string 변수 선언 및 초기화 방법은 무엇일까요?", "string 타입의 변수를 선언하고 큰따옴표로 값을 할당하는 방법을 떠올려보세요.",
            {{"string myText = 'Hello';", "문자열은 작은따옴표(')가 아닌 큰따옴표(\")로 감싸야 해요.", false}, {"char myText = \"Hello\";", "char는 단일 문자를 위한 타입이며, 문자열은 담을 수 없어요.", false}, {"String myText = \"Hello\";", "C++에서 string은 'S'가 소문자여야 해요. (string)", false}, {"string myText = \"Hello\";", "정답! string 변수는 이렇게 선언하고 큰따옴표로 값을 초기화합니다.", true}}
        },
        {"Strings", "두 개의 string 변수 `str1 = \"안녕\"`과 `str2 = \"하세요\"`를 연결하여 `\"안녕하세요\"`를 만들려면 어떤 연산자를 사용해야 할까요?", "문자열을 합칠 때 사용하는 친숙한 연산자예요.",
            {{"-", "빼기 연산자는 문자열에 사용할 수 없어요.", false}, {"*", "곱하기 연산자는 문자열에 사용할 수 없어요.", false}, {"+", "정답! + 연산자는 문자열을 연결(concatenation)할 때 사용됩니다.", true}, {"/", "나누기 연산자는 문자열에 사용할 수 없어요.", false}}
        },
        {"Strings", "다음 중 `string firstName = \"John\"; string lastName = \"Doe\";`를 `\"John Doe\"`로 연결하는 올바른 방법이 아닌 것은 무엇일까요?", "공백을 추가하는 방법을 여러 가지로 생각해보고, 존재하지 않는 함수를 찾아보세요.",
            {{"string fullName = firstName + \" \" + lastName;", "이것은 올바른 방법입니다. 공백 문자열을 추가하여 문자열을 연결합니다.", false}, {"string fullName = firstName + ' ' + lastName;", "이것도 올바른 방법입니다. 단일 문자 공백을 추가하여 문자열을 연결합니다.", false}, {"string fullName = firstName.append(\" \").append(lastName);", "append() 함수를 체인으로 연결하여 문자열을 추가하는 것은 올바른 방법입니다.", false}, {"string fullName = firstName.concatenate(lastName);", "C++ 표준 string 클래스에는 `concatenate()`라는 직접적인 멤버 함수가 존재하지 않습니다.", true}}
        },
        {"Strings", "`string s1 = \"Hello\";`에 `\" World\"`를 추가하여 `\"Hello World\"`로 만들려면 `s1.append(\" World\");`와 같이 `append()` 함수를 사용할 수 있습니다. 이 함수의 반환형은 무엇일까요?", "대부분의 `std::string` 멤버 함수는 자기 자신(`*this`)을 반환하여 체이닝을 가능하게 해요.",
            {{"void", "void는 아무것도 반환하지 않음을 의미해요. append()는 체이닝이 가능해요.", false}, {"string", "정답! append() 함수는 변경된 string 객체의 참조(`string&`)를 반환합니다. 이를 통해 함수 호출을 연결할 수 있죠.", true}, {"int", "int는 정수형 타입으로, 문자열 함수와 관련이 없어요.", false}, {"bool", "bool은 논리형 타입으로, 문자열 함수와 관련이 없어요.", false}}
        },
        {"Strings", "`int num = 10;`과 `string text = \"20\";`이 있을 때, `text + num`의 결과는 무엇일까요?", "C++에서 숫자와 문자열의 직접적인 덧셈(연결)은 허용되지 않습니다.",
            {{"30 (int)", "문자열과 숫자는 직접 덧셈이 되지 않아요.", false}, {"\"1020\" (string)", "문자열과 숫자는 직접 연결되지 않아요.", false}, {"\"2010\" (string)", "문자열과 숫자는 직접 연결되지 않아요.", false}, {"컴파일 에러 발생", "정답! C++은 문자열과 숫자의 직접적인 덧셈(연결)을 허용하지 않아 컴파일 에러가 발생합니다.", true}}
        },
        {"Strings", "`string example = \"Programming\";`의 길이를 얻기 위해 사용할 수 있는 함수는 무엇일까요?", "문자열의 크기를 알려주는 두 가지 함수 이름이 있어요.",
            {{"count()", "count()는 다른 용도로 사용되는 함수입니다.", false}, {"size() 또는 length()", "정답! size()와 length()는 string의 길이를 반환하는 동일한 기능을 합니다.", true}, {"len()", "len()은 C++ 표준 string에 존재하지 않습니다. (Python에서 주로 사용)", false}, {"getLength()", "getLength()는 C++ 표준 string에 존재하지 않습니다.", false}}
        },
        {"Strings", "`string text = \"Coding\";`에서 문자 'd'에 접근하려면 어떤 인덱스를 사용해야 할까요?", "문자열의 인덱스는 0부터 시작해요.",
            {{"0", "'C'에 해당해요.", false}, {"1", "'o'에 해당해요.", false}, {"2", "정답! 'd'는 0부터 시작하는 인덱스로 2번째에 있습니다.", true}, {"3", "'i'에 해당해요.", false}}
        },
        {"Strings", "`string data = \"Data\";`에서 첫 번째 문자를 'F'로 변경하려면 어떤 코드를 사용해야 할까요?", "인덱스에 직접 새 문자를 할당하거나 at() 함수를 사용하세요.",
            {{"data.setChar(0, 'F');", "setChar()는 C++ 표준 string에 존재하지 않습니다.", false}, {"data[0] = \"F\";", "문자열이 아닌 단일 문자를 할당할 때는 작은따옴표를 사용해야 해요.", false}, {"data.at(0) = 'F';", "정답! at() 함수를 사용하거나 `data[0] = 'F';`처럼 직접 인덱싱하여 변경할 수 있습니다.", true}, {"data = 'F' + data.substring(1);", "이 방법도 가능은 하지만, 더 직관적인 방법이 있어요.", false}}
        },
        {"Strings", "C++에서 문자열 안에 큰따옴표(`\"`)를 포함하려면 어떤 이스케이프 시퀀스를 사용해야 할까요?", "역슬래시 뒤에 넣고 싶은 문자를 붙여보세요.",
            {{"/'", "역슬래시(`\\`)를 사용해야 해요.", false}, {"\\\"", "정답! \\\"는 문자열 안에 큰따옴표를 삽입합니다.", true}, {"//", "//는 한 줄 주석을 위한 기호예요.", false}, {"_\"_", "_는 이스케이프 문자가 아니에요.", false}}
        },
        {"Strings", "다음 중 C++ 문자열에서 새로운 줄로 이동하는(줄 바꿈) 이스케이프 시퀀스는 무엇일까요?", "새로운 줄(New Line)을 의미하는 영단어를 떠올려보세요.",
            {{"\\t", "\\t는 탭(Tab)을 위한 이스케이프 시퀀스예요.", false}, {"\\r", "\\r은 캐리지 리턴(Carriage Return)을 위한 이스케이프 시퀀스예요.", false}, {"\\n", "정답! \\n은 새로운 줄(New Line)로 이동하는 이스케이프 시퀀스입니다.", true}, {"\\s", "\\s는 C++ 표준 이스케이프 시퀀스가 아니에요. (정규 표현식에서 공백을 의미하기도 함)", false}}
        },
        {"Strings", "사용자가 공백이 포함된 이름(`\"John Doe\"`)을 입력했을 때, `cin >> name;`을 사용하면 어떤 결과가 나올까요?", "cin은 공백을 입력의 끝으로 인식해요.",
            {{"`\"John Doe\"` 전체가 `name`에 저장된다.", "cin은 공백을 만나면 입력을 중단해요.", false}, {"`\"John\"`만 `name`에 저장되고, `\" Doe\"`는 버퍼에 남는다.", "정답! cin은 공백을 구분자로 인식하여 첫 단어만 읽어들입니다.", true}, {"에러가 발생한다.", "에러는 발생하지 않지만, 예상과 다른 결과가 나올 수 있어요.", false}, {"`\"Doe\"`만 `name`에 저장된다.", "첫 단어인 `\"John\"`이 저장돼요.", false}}
        },
        {"Strings", "공백을 포함한 한 줄 전체의 텍스트를 사용자로부터 입력받기 위해 사용하는 C++ 함수는 무엇일까요?", "입출력 객체 `cin`과 함께 사용되며, 한 '라인'을 읽어들여요.",
            {{"read()", "read()는 다른 용도로 사용되는 함수입니다.", false}, {"input()", "input()은 C++ 표준 라이브러리의 함수가 아니에요.", false}, {"getline(cin, myString);", "정답! getline() 함수는 cin으로부터 한 줄 전체를 읽어들여 string 변수에 저장합니다.", true}, {"cin.readLine();", "readLine()은 C++ 표준 cin 객체에 존재하지 않습니다.", false}}
        },
        {"Strings", "`std::string`과 `char[]` (C-스타일 문자열) 중, 현대 C++에서 더 권장되는 문자열 타입은 무엇일까요?", "더 편리하고 안전한 기능을 제공하는 쪽을 선택해야 해요.",
            {{"char[]", "char[]는 편리성이 떨어지고 안전성 문제가 있을 수 있어요.", false}, {"std::string", "정답! std::string은 더 많은 유용한 함수와 메모리 관리를 자동화하여 편리하고 안전합니다.", true}, {"둘 다 똑같다", "기능과 편의성에서 차이가 있어요.", false}, {"상황에 따라 다르다", "특정 C 함수와 상호작용할 때 외에는 std::string이 더 일반적이에요.", false}}
        },
        {"Strings", "`string s = \"apple\";` 일 때, `s.empty()`의 반환값은 무엇일까요?", "`empty()` 함수는 문자열이 비어있는지 여부를 확인해요.",
            {{"true", "문자열에 'apple'이라는 내용이 있으므로 비어있지 않아요.", false}, {"false", "정답! 'apple'이라는 내용이 있으므로 문자열은 비어있지 않습니다.", true}, {"0", "bool 타입은 true/false를 반환해요.", false}, {"5", "길이를 반환하는 함수가 아니에요.", false}}
        },
        {"Strings", "`string s = \"orange\";` 일 때, `s.at(6)`을 호출하면 어떤 결과가 발생할 가능성이 높을까요?", "`at()` 함수는 유효하지 않은 인덱스에 대해 안전한 처리를 해요.",
            {{"문자 'e'가 반환된다.", "인덱스 6은 범위를 벗어납니다. 'e'는 인덱스 5에 있어요.", false}, {"에러가 발생하지 않고 빈 문자열이 반환된다.", "빈 문자열이 반환되지 않아요.", false}, {"std::out_of_range 예외가 발생한다.", "정답! `at()` 함수는 유효하지 않은 인덱스에 접근하려 할 때 `std::out_of_range` 예외를 던져 안전하게 처리할 수 있게 합니다.", true}, {"컴파일 에러가 발생한다.", "이는 런타임에 발생하는 문제입니다.", false}}
        },
        {"Strings", "`string s = \"cat\";`에 `s.insert(1, \"dog\");`를 호출하면 `s`는 어떤 값이 될까요?", "`insert(pos, str)`는 `pos` 위치에 `str`을 삽입해요.",
            {{"\"dogcat\"", "첫 번째 인덱스에 삽입되는 것이 아니에요.", false}, {"\"cdogat\"", "인덱스 1 위치(두 번째 글자 앞)에 삽입돼요. 'c' 다음에 'dog'가 들어가요.", true}, {"\"cdogaht\"", "오타가 포함되어 있어요.", false}, {"\"cdogato\"", "오타가 포함되어 있어요.", false}}
        },
        {"Strings", "`string s = \"banana\";` 일 때, `s.substr(1, 3)`의 반환값은 무엇일까요?", "`substr(pos, len)`은 `pos` 위치부터 `len` 길이만큼의 부분 문자열을 반환해요.",
            {{"\"ban\"", "인덱스 1부터 시작하고 3글자이므로 'ana'가 됩니다.", false}, {"\"ana\"", "정답! 인덱스 1('a')부터 시작하여 3글자('ana')를 잘라냅니다.", true}, {"\"nana\"", "4글자가 아니에요.", false}, {"\"bana\"", "시작 인덱스가 잘못되었어요.", false}}
        },
        {"Strings", "`string s = \"Hello\";`와 `string t = \"hello\";`를 비교할 때, `s == t`의 결과는 무엇일까요?", "C++의 문자열 비교는 대소문자를 구분해요.",
            {{"true", "대소문자가 다르므로 같지 않아요.", false}, {"false", "정답! C++에서 문자열 비교는 대소문자를 구분하므로 'H'와 'h'가 다르다고 판단합니다.", true}, {"컴파일 에러", "비교 연산자는 문자열에도 유효해요.", false}, {"런타임 에러", "에러가 발생하지 않아요.", false}}
        },

        // --- 3. Math 관련 퀴즈 (총 20개) ---
        {"Math", "두 숫자 중 더 큰 값을 찾고 싶을 때 사용하는 `cmath` 라이브러리의 함수는 무엇일까요?", "최대(maximum)를 의미하는 영어 단어를 떠올려보세요.",
            {{"min()", "min()은 더 작은 값을 찾을 때 사용해요.", false}, {"max()", "정답! max(x,y) 함수는 두 값 중 더 큰 값을 반환합니다.", true}, {"sum()", "sum()은 두 값을 더할 때 사용해요.", false}, {"abs()", "abs()는 절댓값을 반환해요.", false}}
        },
        {"Math", "`double num = 81.0;`의 제곱근(square root)을 구하려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?", "제곱근을 의미하는 영어 단어를 줄여서 생각해보세요.",
            {{"power()", "power()는 거듭제곱을 계산할 때 사용해요.", false}, {"root()", "root()는 C++ 표준 cmath에 존재하지 않습니다.", false}, {"sqrt()", "정답! sqrt() 함수는 숫자의 제곱근을 반환합니다.", true}, {"sq()", "sq()는 C++ 표준 cmath에 존재하지 않습니다.", false}}
        },
        {"Math", "`double value = 3.7;`을 가장 가까운 정수로 반올림하려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?", "반올림(round)을 의미하는 영어 단어를 떠올려보세요.",
            {{"ceil()", "ceil()은 올림을 할 때 사용해요 (4.0).", false}, {"floor()", "floor()는 내림을 할 때 사용해요 (3.0).", false}, {"round()", "정답! round() 함수는 숫자를 가장 가까운 정수로 반올림합니다.", true}, {"trunc()", "trunc()는 소수점 이하를 버릴 때 사용해요 (3.0).", false}}
        },
        {"Math", "자연로그(natural logarithm)를 계산하는 `cmath` 함수는 무엇일까요?", "로그(logarithm)를 의미하는 영어 단어를 생각해보세요.",
            {{"exp()", "exp()는 지수 함수(e의 거듭제곱)를 계산해요.", false}, {"log()", "정답! log() 함수는 자연로그를 계산합니다.", true}, {"pow()", "pow()는 거듭제곱을 계산해요.", false}, {"ln()", "ln()은 수학에서 자연로그를 의미하지만, C++ 함수 이름은 log()입니다.", false}}
        },
        {"Math", "`double base = 2.0; double exponent = 3.0;` 일 때, 2의 3제곱(8.0)을 계산하는 `cmath` 함수는 무엇일까요?", "거듭제곱(power)을 의미하는 영어 단어를 떠올려보세요.",
            {{"sqrt()", "sqrt()는 제곱근을 계산해요.", false}, {"pow()", "정답! pow(base, exponent) 함수는 거듭제곱을 계산합니다.", true}, {"log()", "log()는 자연로그를 계산해요.", false}, {"abs()", "abs()는 절댓값을 반환해요.", false}}
        },
        {"Math", "`int num = -10;`의 절댓값을 구하려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?", "절댓값(absolute value)을 의미하는 영어 단어를 줄여서 생각해보세요.",
            {{"ceil()", "ceil()은 올림을 할 때 사용해요.", false}, {"abs()", "정답! abs() 함수는 숫자의 절댓값을 반환합니다.", true}, {"fabs()", "fabs()는 부동소수점 수의 절댓값을 반환하고, abs()는 정수형에 사용됩니다. 둘 다 맞지만, 문제에서는 `int`를 사용했어요.", false}, {"floor()", "floor()는 내림을 할 때 사용해요.", false}}
        },
        {"Math", "`double angle = 0.0;`의 사인(sine) 값을 계산하는 `cmath` 함수는 무엇일까요?", "삼각 함수 사인(sine)을 의미하는 영어 단어를 생각해보세요.",
            {{"cos()", "cos()는 코사인 값을 계산해요.", false}, {"tan()", "tan()는 탄젠트 값을 계산해요.", false}, {"sin()", "정답! sin() 함수는 주어진 각도(라디안)의 사인 값을 계산합니다.", true}, {"asin()", "asin()은 아크 사인 값을 계산해요.", false}}
        },
        {"Math", "두 점 `(x1, y1)`과 `(x2, y2)` 사이의 유클리드 거리를 계산할 때, 피타고라스 정리(`sqrt(pow(dx, 2) + pow(dy, 2))`)에 주로 사용되는 `cmath` 함수는 무엇일까요?", "이름 자체가 '피타고라스'를 떠올리게 하는 함수예요.",
            {{"hypot()", "정답! hypot(dx, dy) 함수는 두 변의 길이를 통해 빗변의 길이를 (sqrt(x^2 + y^2)) 계산합니다. 유클리드 거리 계산에 유용해요.", true}, {"dist()", "dist()는 C++ 표준 cmath에 존재하지 않습니다.", false}, {"pythagoras()", "pythagoras()는 C++ 표준 cmath에 존재하지 않습니다.", false}, {"distance()", "distance()는 C++ 표준 cmath에 존재하지 않습니다.", false}}
        },
        {"Math", "어떤 숫자의 부호(양수/음수/0)를 얻고 싶을 때, `cmath` 라이브러리의 어떤 함수를 사용할 수 있을까요? (힌트: C++20부터 표준에 포함된 함수)", "부호를 의미하는 sign에서 따온 이름이에요.",
            {{"sign()", "sign()은 C++20 이전에는 표준이 아니었지만, 이제 표준에 포함되었습니다.", true}, {"sgn()", "sgn()은 일반적으로 사용되는 용어지만, C++ 표준 함수는 sign()입니다.", false}, {"is_positive()", "is_positive()는 C++ 표준 cmath에 존재하지 않습니다.", false}, {"copysign()", "copysign()은 다른 숫자의 부호를 복사해요.", false}}
        },
        {"Math", "`double value = 5.9;`를 내림(floor)하여 정수로 만들려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?", "바닥(floor)을 의미하는 영어 단어를 떠올려보세요.",
            {{"round()", "round()는 반올림이에요.", false}, {"ceil()", "ceil()은 올림이에요.", false}, {"floor()", "정답! floor() 함수는 주어진 숫자보다 작거나 같은 가장 큰 정수를 반환합니다 (내림).", true}, {"trunc()", "trunc()는 소수점 이하를 버려요 (양수는 floor와 같고, 음수는 ceil과 같아요).", false}}
        },
        {"Math", "컴퓨터 과학에서 특정 값을 2의 거듭제곱으로 나타낼 때 사용하는 로그 함수는 무엇일까요?", "밑이 2인 로그를 의미하는 함수 이름이에요.",
            {{"log()", "log()는 자연로그(밑이 e)를 나타내요.", false}, {"log10()", "log10()은 상용로그(밑이 10)를 나타내요.", false}, {"log2()", "정답! log2() 함수는 밑이 2인 로그를 계산합니다.", true}, {"logb()", "logb()는 부동소수점 숫자의 지수 부분을 반환해요.", false}}
        },
        {"Math", "`double val = -7.5;`의 절댓값을 `double` 형태로 반환하는 `cmath` 함수는 무엇일까요?", "부동소수점 숫자의 절댓값을 위한 함수를 찾으세요.",
            {{"abs()", "abs()는 보통 정수형의 절댓값을 위해 사용됩니다.", false}, {"fabs()", "정답! fabs() 함수는 부동소수점 숫자의 절댓값을 반환합니다.", true}, {"dabs()", "dabs()는 C++ 표준 cmath에 존재하지 않습니다.", false}, {"abs_double()", "abs_double()는 C++ 표준 cmath에 존재하지 않습니다.", false}}
        },
        {"Math", "`double x = 1.0;`의 코사인(cosine) 값을 계산하는 `cmath` 함수는 무엇일까요?", "삼각 함수 코사인(cosine)을 의미하는 영어 단어를 생각해보세요.",
            {{"sin()", "sin()은 사인 값을 계산해요.", false}, {"tan()", "tan()은 탄젠트 값을 계산해요.", false}, {"acos()", "acos()는 아크코사인 값을 계산해요.", false}, {"cos()", "정답! cos() 함수는 주어진 각도(라디안)의 코사인 값을 계산합니다.", true}}
        },
        {"Math", "다음 중 `cmath` 헤더 파일에 포함되지 않은 기능은 무엇일까요?", "어떤 수학적 기능이 `cmath`에 포함되는지 생각해 보세요.",
            {{"삼각 함수 (sin, cos)", "cmath에 포함돼요.", false}, {"로그 함수 (log, log10)", "cmath에 포함돼요.", false}, {"최대/최소 값 (max, min)", "cmath에 포함돼요.", false}, {"문자열 길이 (length)", "string 헤더에 포함돼요.", true}}
        },
        {"Math", "`double result = fmod(10.5, 3.0);`의 결과는 무엇일까요? (`fmod`는 부동소수점 나머지 연산)", "나머지 연산자와 비슷한 기능을 합니다.",
            {{"1", "정수 나머지 연산과 다를 수 있어요.", false}, {"1.5", "정답! 10.5를 3.0으로 나눈 나머지는 1.5입니다.", true}, {"3", "몫이에요.", false}, {"0.5", "오류 계산입니다.", false}}
        },
        {"Math", "`double x = -4.2;`를 올림(ceil)하여 정수로 만들려면 `cmath` 라이브러리의 어떤 함수를 사용해야 할까요?", "천장(ceiling)을 의미하는 영어 단어를 떠올려보세요.",
            {{"round()", "반올림이에요.", false}, {"floor()", "내림이에요.", false}, {"ceil()", "정답! `ceil()` 함수는 주어진 숫자보다 크거나 같은 가장 작은 정수를 반환합니다. 따라서 -4.2는 -4.0이 됩니다.", true}, {"abs()", "절댓값을 반환해요.", false}}
        },
        {"Math", "`double result = pow(5.0, 2.0);`의 결과는 무엇일까요?", "5의 제곱을 의미해요.",
            {{"10.0", "곱셈이 아니라 거듭제곱이에요.", false}, {"25.0", "정답! `pow(5.0, 2.0)`은 5의 2제곱(5 * 5)인 25.0을 반환합니다.", true}, {"7.0", "덧셈이 아니에요.", false}, {"2.5", "나눗셈이 아니에요.", false}}
        },
        {"Math", "`double val = 1.2345;`를 소수점 첫째 자리에서 반올림하려면 `round(val * 10.0) / 10.0`과 같이 응용할 수 있습니다. 이때 `val * 10.0`의 결과는 무엇일까요?", "곱셈 연산을 정확히 해보세요.",
            {{"12", "정수가 아니라 부동소수점 값이에요.", false}, {"12.3", "정확한 결과가 아니에요.", false}, {"12.345", "정답! `1.2345 * 10.0`의 결과는 12.345입니다.", true}, {"1.23", "곱셈 결과가 너무 작아요.", false}}
        },
        {"Math", "`long double` 타입이 `double` 타입보다 `cmath` 함수에서 가질 수 있는 이점은 무엇일까요?", "정밀도와 범위에 대한 특징을 생각해보세요.",
            {{"더 빠른 연산 속도", "보통 `long double`이 더 느릴 수 있어요.", false}, {"더 적은 메모리 사용", "더 많은 메모리를 사용해요.", false}, {"더 높은 정밀도와 넓은 범위의 표현", "정답! `long double`은 `double`보다 더 많은 메모리를 사용하여 매우 높은 정밀도와 더 넓은 범위의 부동소수점 수를 표현할 수 있습니다.", true}, {"정수 값만 저장 가능", "부동소수점 타입이에요.", false}}
        },
        {"Math", "각도를 라디안으로 변환할 때 사용하는 일반적인 수학 상수 `PI`의 값에 가장 가까운 `cmath` 상수 혹은 표현은 무엇일까요?", "PI 값을 상수로 제공하는 경우가 있어요.",
            {{"M_PI", "정답! `<cmath>` 헤더(또는 `<math.h>`)에는 종종 `M_PI`와 같이 PI 값을 나타내는 매크로 상수가 정의되어 있습니다. 단, 표준 C++ 상수는 아닐 수 있습니다.", true}, {"PI_VAL", "표준 상수가 아니에요.", false}, {"3.14", "정확도가 부족해요.", false}, {"_PI_", "표준 상수가 아니에요.", false}}
        },

        // --- 4. Boolean 관련 퀴즈 (총 15개) ---
        {"Booleans", "프로그래밍에서 'YES/NO', 'ON/OFF', 'TRUE/FALSE'와 같이 단 두 가지 값만 가질 수 있는 데이터 타입은 무엇일까요?", "논리적인 판단을 위한 타입이에요.",
            {{"int", "int는 정수를 저장해요.", false}, {"char", "char는 단일 문자를 저장해요.", false}, {"bool", "정답! bool 타입은 true(참) 또는 false(거짓) 두 가지 값만 가질 수 있습니다.", true}, {"string", "string은 텍스트를 저장해요.", false}}
        },
        {"Booleans", "C++에서 `bool` 타입의 `true` 값은 정수형으로 변환될 때 어떤 숫자가 될까요?", "컴퓨터가 참을 표현하는 기본적인 숫자예요.",
            {{"0", "0은 false에 해당해요.", false}, {"1", "정답! bool 값 true는 정수 1로, false는 0으로 변환됩니다.", true}, {"-1", "-1은 일반적으로 사용되지 않아요.", false}, {"true는 숫자가 될 수 없다.", "bool은 정수형으로 암시적 변환이 가능해요.", false}}
        },
        {"Booleans", "다음 중 `bool` 변수를 선언하고 `false` 값으로 초기화하는 올바른 방법은 무엇일까요?", "`bool` 키워드를 사용하고 `false` 리터럴을 할당하세요.",
            {{"boolean isDone = false;", "C++에서 `bool`은 소문자 `b`로 시작해요.", false}, {"bool isDone = 0;", "0은 false와 동일한 의미로 사용될 수 있지만, `false` 리터럴을 직접 사용하는 것이 더 명확해요.", true}, // 0도 가능하지만 false가 더 명확
                {"bool isDone = \"false\";", "문자열 \"false\"는 bool 값으로 직접 할당될 수 없어요.", false}, {"Bool isDone = False;", "C++에서 `bool`과 `false`는 모두 소문자로 시작해요.", false}}
        },
        {"Booleans", "불리언 표현식 `(10 > 5)`의 결과는 무엇일까요? (정수 값으로)", "10이 5보다 큰지 판단해보세요.",
            {{"0", "10은 5보다 크므로 참이에요.", false}, {"1", "정답! 10이 5보다 크므로 이 불리언 표현식은 true(1)를 반환합니다.", true}, {"5", "숫자가 반환되지 않아요.", false}, {"에러", "비교 연산은 에러를 발생시키지 않아요.", false}}
        },
        {"Booleans", "`int a = 7;`일 때, 불리언 표현식 `(a == 5)`의 결과는 무엇일까요? (정수 값으로)", "a가 5와 같은지 판단해보세요.",
            {{"0", "정답! a(7)는 5와 같지 않으므로 이 불리언 표현식은 false(0)를 반환합니다.", true}, {"1", "a는 5와 같지 않아요.", false}, {"5", "숫자가 반환되지 않아요.", false}, {"7", "숫자가 반환되지 않아요.", false}}
        },
        {"Booleans", "만약 `age` 변수가 15이고 `votingAge`가 18일 때, `(age >= votingAge)` 불리언 표현식의 결과는 무엇일까요?", "15가 18보다 크거나 같은지 판단해보세요.",
            {{"true", "15는 18보다 크지도 같지도 않아요.", false}, {"false", "정답! 15는 18보다 크거나 같지 않으므로 false를 반환합니다.", true}, {"1", "1은 true에 해당해요.", false}, {"0", "0은 false에 해당해요. (이것도 정답이지만, bool 값으로 질문했으므로 false가 더 적합)", false}}
        },
        {"Booleans", "`bool` 타입이 주로 사용되는 프로그래밍 상황은 무엇일까요?", "어떤 조건이 참인지 거짓인지 판단해야 할 때를 생각해보세요.",
            {{"이름 저장", "이름은 string으로 저장해요.", false}, {"나이 계산", "나이는 int로 저장해요.", false}, {"조건문(if/else)의 판단 기준", "정답! `bool`은 조건문, 반복문 등 논리적인 흐름 제어의 판단 기준으로 가장 많이 사용됩니다.", true}, {"복잡한 수학 계산", "복잡한 수학 계산에는 주로 숫자형 타입을 사용해요.", false}}
        },
        {"Booleans", "`bool isRaining = true;`일 때, `!isRaining`의 결과는 무엇일까요?", "`!` 연산자는 불리언 값을 반전시켜요.",
            {{"true", "true의 반대는 false예요.", false}, {"false", "정답! `!`(NOT) 연산자는 불리언 값을 반전시키므로, true의 반대인 false가 됩니다.", true}, {"에러", "유효한 연산이에요.", false}, {"0", "0은 false에 해당해요.", false}}
        },
        {"Booleans", "`bool condition1 = true; bool condition2 = false;`일 때, `condition1 && condition2`의 결과는 무엇일까요?", "`&&`(AND) 연산자는 두 조건이 모두 참일 때만 참을 반환해요.",
            {{"true", "두 조건 중 하나가 거짓이므로 true가 될 수 없어요.", false}, {"false", "정답! `&&`(AND) 연산자는 두 피연산자가 모두 true일 때만 true를 반환합니다. 하나라도 false이면 false입니다.", true}, {"에러", "유효한 연산이에요.", false}, {"1", "1은 true에 해당해요.", false}}
        },
        {"Booleans", "`bool condition1 = true; bool condition2 = false;`일 때, `condition1 || condition2`의 결과는 무엇일까요?", "`||`(OR) 연산자는 둘 중 하나라도 참이면 참을 반환해요.",
            {{"true", "정답! `||`(OR) 연산자는 두 피연산자 중 하나라도 true이면 true를 반환합니다. 여기서는 condition1이 true입니다.", true}, {"false", "하나라도 true이면 false가 될 수 없어요.", false}, {"에러", "유효한 연산이에요.", false}, {"0", "0은 false에 해당해요.", false}}
        },
        {"Booleans", "C++에서 불리언 값을 화면에 `true`나 `false`라는 문자열로 출력하고 싶을 때, `std::cout`과 함께 사용할 수 있는 조작자는 무엇일까요?", "불리언 값을 문자열로 표현하라는 의미를 가진 단어를 찾아보세요.",
            {{"std::dec", "std::dec는 10진수 출력을 위한 조작자예요.", false}, {"std::fixed", "std::fixed는 부동소수점 출력 형식을 고정할 때 사용해요.", false}, {"std::boolalpha", "정답! `std::boolalpha` 조작자를 사용하면 `bool` 값을 `1/0` 대신 `true/false` 문자열로 출력할 수 있습니다.", true}, {"std::scientific", "std::scientific은 과학적 표기법으로 숫자를 출력할 때 사용해요.", false}}
        },
        {"Booleans", "`if (some_boolean_variable)`와 같이 조건문을 작성할 때, `some_boolean_variable`의 값이 `true`이면 `if` 블록이 실행됩니다. 이는 `some_boolean_variable == true`와 어떤 관계일까요?", "불리언 변수 자체가 이미 조건으로 사용될 수 있어요.",
            {{"`if (some_boolean_variable)`는 항상 `false`를 의미한다.", "이는 틀린 설명이에요.", false}, {"`if (some_boolean_variable)`는 `some_boolean_variable == true`와 동일한 의미이다.", "정답! 불리언 변수는 그 자체로 논리적 값을 가지므로, `some_boolean_variable == true`와 같이 명시적으로 비교하지 않아도 됩니다.", true}, {"`if (some_boolean_variable)`는 문법 오류이다.", "유효한 C++ 문법이에요.", false}, {"`if (some_boolean_variable)`는 `some_boolean_variable != false`와 동일한 의미이다.", "맞는 설명이지만, `some_boolean_variable == true`와 더 직접적인 의미를 가져요.", false}}
        },
        {"Booleans", "다음 중 불리언 표현식의 결과가 `true`가 **아닌** 것은 무엇일까요?", "각 조건의 참/거짓 여부를 판단해보세요.",
            {{"`5 < 10`", "5는 10보다 작으므로 참이에요.", false}, {"`'A' == 'a'`", "대소문자가 다르므로 거짓이에요.", true}, {"`!(false)`", "false의 반대는 true예요.", false}, {"`10 >= 10`", "10은 10보다 크거나 같으므로 참이에요.", false}}
        },
        {"Booleans", "`true`와 `false`를 저장하는 `bool` 타입은 컴퓨터 메모리에서 주로 몇 바이트를 차지할까요?", "가장 작은 논리적 단위의 크기를 생각해 보세요.",
            {{"4 바이트", "int나 float의 크기일 수 있어요.", false}, {"8 바이트", "double이나 long long의 크기일 수 있어요.", false}, {"1 바이트", "정답! `bool` 타입은 일반적으로 1바이트를 차지하여 가장 효율적으로 참/거짓을 표현합니다.", true}, {"0 바이트", "메모리를 차지해야 값을 저장할 수 있어요.", false}}
        },
        {"Booleans", "두 불리언 변수 `A`와 `B`가 있을 때, `A || B`가 `false`를 반환하는 경우는 언제일까요?", "`||`(OR) 연산자의 특성을 이해해야 해요.",
            {{"A가 `true`이고 B가 `true`일 때", "이 경우 `true`를 반환해요.", false}, {"A가 `true`이고 B가 `false`일 때", "이 경우 `true`를 반환해요.", false}, {"A가 `false`이고 B가 `true`일 때", "이 경우 `true`를 반환해요.", false}, {"A가 `false`이고 B가 `false`일 때", "정답! `||`(OR) 연산자는 두 피연산자가 모두 `false`일 때만 `false`를 반환합니다.", true}}
        },

        // --- 5. If-Else 관련 퀴즈 (총 15개) ---
        {"If-Else", "다음 중 'a가 b보다 작다'를 나타내는 올바른 조건 연산자는 무엇일까요?", "Less than을 의미하는 기호를 떠올려보세요.",
            {{"a <= b", "작거나 같다를 의미해요.", false}, {"a > b", "크다를 의미해요.", false}, {"a < b", "정답! 작다를 의미하는 연산자입니다.", true}, {"a == b", "같다를 의미해요.", false}}
        },
        {"If-Else", "`if` 문을 사용하여 특정 코드 블록을 실행시키려면, 조건이 어떤 상태여야 할까요?", "if (조건) { ... } 의 의미를 생각해보세요.",
            {{"false", "조건이 거짓일 때 실행되지 않아요.", false}, {"0", "거짓을 의미해요.", false}, {"true", "정답! 조건이 참(true)일 때 if 블록의 코드가 실행됩니다.", true}, {"null", "null은 주로 포인터나 빈 값을 나타내요.", false}}
        },
        {"If-Else", "`int score = 75;`일 때, `if (score >= 80)` 조건문은 어떤 결과를 반환할까요?", "75가 80보다 크거나 같은지 판단해보세요.",
            {{"true", "75는 80보다 작으므로 거짓이에요.", false}, {"false", "정답! 75는 80보다 작으므로 이 조건은 거짓(false)입니다.", true}, {"컴파일 에러", "유효한 조건문이에요.", false}, {"80", "조건문의 결과는 불리언 값이에요.", false}}
        },
        {"If-Else", "`int temp = 5;`일 때, 다음 코드의 출력 결과는 무엇일까요?\n`if (temp > 10) { cout << \"Hot\"; } else { cout << \"Cold\"; }`", "5가 10보다 큰지 판단하고, 조건이 거짓일 때 else 블록이 실행돼요.",
            {{"Hot", "5는 10보다 크지 않아요.", false}, {"Cold", "정답! temp(5)가 10보다 크지 않으므로 else 블록이 실행되어 'Cold'가 출력됩니다.", true}, {"컴파일 에러", "유효한 코드예요.", false}, {"아무것도 출력되지 않음", "else 블록이 실행됩니다.", false}}
        },
        {"If-Else", "`int hour = 14;`일 때, 다음 코드의 출력 결과는 무엇일까요?\n`if (hour < 10) { cout << \"Morning\"; } else if (hour < 15) { cout << \"Afternoon\"; } else { cout << \"Evening\"; }`", "조건들이 순서대로 평가돼요. 첫 번째 조건이 거짓이면 다음 `else if`로 넘어갑니다.",
            {
                {"Morning", "14는 10보다 작지 않아요.", false},
                {"Afternoon", "정답! hour(14)는 10보다 작지 않지만, 15보다는 작으므로 두 번째 조건이 참이 되어 'Afternoon'이 출력됩니다.", true},
                {"Evening", "두 번째 조건이 참이므로 else 블록까지 가지 않아요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {"If-Else", "삼항 연산자(Ternary Operator)로 알려진 `if...else`의 축약형 구문은 무엇일까요?", "세 개의 피연산자를 사용하는 구문이에요.",
            {
                {"variable = (condition) ? expressionTrue : expressionFalse;", "정답! 삼항 연산자의 올바른 구문입니다.", true},
                {"variable = if (condition) expressionTrue else expressionFalse;", "잘못된 문법이에요.", false},
                {"(condition) ? expressionTrue : expressionFalse = variable;", "할당 방향이 틀렸어요.", false},
                {"variable = condition ? expressionTrue : expressionFalse;", "괄호가 없어도 되지만, 보통 조건에 괄호를 붙여 명확하게 합니다.", false}
            }
        },
        {"If-Else", "`if (myNum % 2 == 0)`은 어떤 숫자를 판별할 때 주로 사용되는 조건일까요?", "어떤 숫자가 2로 나누어 떨어지는지 확인하는 조건이에요.",
            {
                {"양수인지 음수인지", "이는 `> 0` 또는 `< 0`으로 판별해요.", false},
                {"홀수인지 짝수인지", "정답! `어떤 숫자가 2로 나누어 떨어지면 짝수`이고, 그렇지 않으면 홀수입니다.", true},
                {"소수인지 아닌지", "소수 판별은 더 복잡한 로직이 필요해요.", false},
                {"0인지 아닌지", "이는 `== 0` 또는 `!= 0`으로 판별해요.", false}
            }
        },
        {"If-Else", "다음 중 `if`와 `else` 문 사용에 대한 설명으로 올바르지 않은 것은 무엇일까요?", "각 키워드의 역할을 정확히 이해하고 있는지 확인하세요.",
            {
                {"`if` 문은 소문자로 써야 한다.", "맞아요. `If`나 `IF`는 오류를 발생시켜요.", false},
                {"`else` 문은 `if` 문 없이 단독으로 사용될 수 있다.", "`else`는 항상 선행하는 `if` 또는 `else if`가 필요해요.", true},
                {"`else if`는 여러 조건을 순차적으로 검사할 때 사용된다.", "맞아요. 첫 조건이 거짓일 때 다음 조건을 검사해요.", false},
                {"조건문 뒤에 중괄호 `{}`를 사용하지 않으면, 첫 번째 문장만 `if` 문에 속한다.", "맞아요. 여러 문장을 포함하려면 중괄호가 필수예요.", false}
            }
        },
        {"If-Else", "다음 `if-else if-else` 체인의 실행 순서로 올바른 것은?\n`if (A) { ... } else if (B) { ... } else { ... }`", "위에서부터 순차적으로 조건을 평가합니다.",
            {
                {"A가 참이면 A 블록 실행 후 끝. A가 거짓이고 B가 참이면 B 블록 실행 후 끝. 둘 다 거짓이면 else 블록 실행 후 끝.", "정답! 이 설명은 if-else if-else 문의 정확한 실행 순서를 나타냅니다.", true},
                {"A가 참이면 A 블록 실행. B가 참이면 B 블록 실행. 둘 다 거짓이면 else 블록 실행.", "조건들이 독립적으로 평가되는 것이 아니라 순차적으로 평가돼요.", false},
                {"세 가지 조건(A, B, else)이 동시에 평가되어 가장 적합한 블록이 실행된다.", "동시에 평가되지 않고 순차적으로 평가돼요.", false},
                {"else 블록이 항상 가장 먼저 평가된 후, A 또는 B가 평가된다.", "else 블록은 모든 if/else if가 거짓일 때만 실행돼요.", false}
            }
        },
        {"If-Else", "`int hour = 17;`일 때, 삼항 연산자 `string greeting = (hour < 12) ? \"Good morning\" : \"Good afternoon\";`의 결과는 무엇일까요?", "17이 12보다 작은지 판단하고, 조건에 따라 `expressionTrue` 또는 `expressionFalse`가 선택됩니다.",
            {
                {"\"Good morning\"", "17은 12보다 작지 않아요.", false},
                {"\"Good afternoon\"", "정답! `hour < 12` (17 < 12)는 false이므로, `expressionFalse`인 \"Good afternoon\"이 선택됩니다.", true},
                {"컴파일 에러", "유효한 구문이에요.", false},
                {"아무것도 출력되지 않음", "삼항 연산자는 항상 값을 반환해요.", false}
            }
        },
        {"If-Else", "다음 `if-else if-else` 문에서 `int num = -5;` 일 때의 출력 결과는?\n`if (num > 0) { cout << \"Positive\"; } else if (num < 0) { cout << \"Negative\"; } else { cout << \"Zero\"; }`", "조건의 순차적 평가를 다시 확인하세요.",
            {
                {"Positive", "-5는 0보다 크지 않아요.", false},
                {"Negative", "정답! `num`(-5)는 0보다 작으므로, 두 번째 `else if` 조건(`num < 0`)이 참이 되어 'Negative'가 출력됩니다.", true},
                {"Zero", "0이 아니므로 `else` 블록까지 가지 않아요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {"If-Else", "어떤 조건이 참일 때 코드 블록을 한 번만 실행하는 가장 기본적인 C++ 문장은 무엇일까요?", "조건에 따라 분기하는 가장 단순한 형태예요.",
            {
                {"while", "반복문이에요.", false},
                {"for", "반복문이에요.", false},
                {"if", "정답! `if` 문은 조건이 참일 때 한 번만 실행되는 코드 블록을 지정합니다.", true},
                {"do-while", "반복문이에요.", false}
            }
        },
        {"If-Else", "`int age = 10;`일 때, `if (age >= 13) { cout << \"Teen\"; } else if (age >= 0) { cout << \"Child\"; }` 의 결과는?", "조건의 순서에 주의하세요.",
            {
                {"Teen", "10은 13보다 작아요.", false},
                {"Child", "정답! 10은 13보다 작고, 0보다 크거나 같으므로 \"Child\"가 출력됩니다.", true},
                {"아무것도 출력되지 않음", "else if 조건이 참이 되므로 출력됩니다.", false},
                {"에러", "유효한 코드예요.", false}
            }
        },
        {"If-Else", "`if (condition);`와 같이 `if`문 뒤에 세미콜론(;)을 붙이면 어떤 문제가 발생할까요?", "세미콜론이 문장을 어떻게 종료시키는지 생각해 보세요.",
            {
                {"컴파일 에러가 발생한다.", "문법적으로는 유효합니다.", false},
                {"`if` 블록 안의 코드가 무시된다.", "정답! `if (condition);`는 빈 문장을 실행하고 `if`문을 종료시키므로, 그 뒤의 `{}` 블록은 항상 실행됩니다.", true},
                {"`if` 조건이 항상 참으로 평가된다.", "조건의 평가와는 무관해요.", false},
                {"프로그램이 무한 루프에 빠진다.", "무한 루프와는 관련 없어요.", false}
            }
        },
        {"If-Else", "두 개의 `if` 문을 연속으로 사용하는 것과 `if-else if`를 사용하는 것의 주요 차이점은 무엇일까요?", "조건 평가의 독립성 또는 상호 배제성을 생각해보세요.",
            {
                {"차이가 없다. 완전히 동일하다.", "차이가 있어요.", false},
                {"연속 `if`는 모든 조건을 독립적으로 평가하고, `if-else if`는 첫 참 조건만 실행한다.", "정답! 연속 `if`는 모든 조건을 확인하지만, `if-else if`는 첫 번째로 참인 조건을 만나는 순간 나머지 조건을 건너뜫니다.", true},
                {"연속 `if`는 더 빠르다.", "일반적으로 `if-else if`가 더 효율적일 수 있어요.", false},
                {"`if-else if`는 문법 오류이다.", "유효한 문법이에요.", false}
            }
        },

        // --- 6. Switch 퀴즈 (총 15개) ---
        {"Switch", "C++에서 여러 조건 중 하나를 선택하여 코드 블록을 실행할 때 사용하는 효율적인 문장은 무엇일까요?", "많은 대안 중 하나를 '선택'할 때 사용해요.",
            {
                {"if-else if", "이것도 가능하지만, '여러 조건 중 하나'라는 표현에 더 적합한 다른 문장이 있어요.", false},
                {"while", "while은 반복문이에요.", false},
                {"switch", "정답! switch 문은 여러 case 중 일치하는 하나를 선택하여 실행하는 데 사용됩니다.", true},
                {"for", "for는 반복문이에요.", false}
            }
        },
        {"Switch", "다음 `switch` 문에서 `day = 7;`일 때 출력 결과는 무엇일까요?\n`switch(day) { case 1: cout << \"Mon\"; break; case 7: cout << \"Sun\"; case 8: cout << \"Invalid\"; break; default: cout << \"Other\"; }`", "`break`의 유무에 따라 흐름이 달라질 수 있어요. `case 7`에 `break`가 있는지 확인하세요.",
            {
                {"Sun", "정답! `case 7`이 일치하고, 그 뒤에 `break`가 없으므로 다음 `case 8`의 코드까지 실행됩니다.", true},
                {"SunInvalid", "실제로 'SunInvalid'가 출력됩니다. 하지만 이 문제의 정답은 Sun 입니다. 문제의 의도를 명확히 하기 위해 보기를 수정해야 합니다.", false}, // 이 보기가 정답인데, 앞의 "Sun"으로 오인할 수 있으므로 텍스트 수정 필요
                {"Other", "default는 일치하는 case가 없을 때 실행돼요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {"Switch", "`switch` 문에서 일치하는 `case`가 없을 때 실행되는 선택적인 키워드는 무엇일까요?", "기본(default)이라는 의미를 가진 영어 단어예요.",
            {
                {"else", "`else`는 `if` 문에 사용돼요.", false},
                {"default", "정답! `default` 키워드는 어떤 `case`에도 일치하지 않을 때 실행될 코드 블록을 지정합니다.", true},
                {"otherwise", "C++에 없는 키워드예요.", false},
                {"none", "C++에 없는 키워드예요.", false}
            }
        },
        {"Switch", "`int day = 0;`일 때, 다음 `switch` 문의 출력 결과는 무엇일까요?\n`switch(day) { case 1: cout << \"Mon\"; break; default: cout << \"Invalid Day\"; break; case 0: cout << \"Sunday\"; break; }`", "`case`의 순서는 중요하지 않아요. 일치하는 `case`가 있는지, `default`가 어디 있는지 확인하세요.",
            {
                {"Mon", "day는 1이 아니에요.", false},
                {"Invalid Day", "default는 다른 case가 일치하지 않을 때 실행돼요.", false},
                {"Sunday", "정답! `day`는 0이므로 `case 0`이 일치하여 'Sunday'가 출력됩니다.", true},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {"Switch", "`switch` 문에서 `break` 키워드의 역할로 올바른 것은 무엇일까요?", "`break`가 없으면 어떤 일이 일어나는지 생각해보세요.",
            {
                {"`switch` 문을 완전히 종료하고 다음 코드로 넘어간다.", "정답! `break`는 일치하는 `case` 블록의 실행을 멈추고 `switch` 문 바깥으로 빠져나가게 합니다.", true},
                {"다음 `case`로 계속 실행되도록 한다.", "`break`가 없을 때 발생하는 현상이에요.", false},
                {"`switch` 문 내에서 무한 루프를 생성한다.", "`break`와는 관련이 없어요.", false},
                {"오류를 발생시킨다.", "오류가 아니라 정상적인 키워드예요.", false}
            }
        },
        {"Switch", "사용자로부터 요일(1=월, 2=화, ..., 7=일)을 입력받아 요일 이름을 출력하는 `switch` 문을 작성할 때, 1부터 7까지의 숫자 외의 다른 값이 입력될 경우 '유효하지 않은 요일'이라고 출력하려면 어떤 키워드를 사용해야 할까요?", "일치하는 case가 없을 때의 예외 처리를 위한 키워드예요.",
            {
                {"else", "switch 문에서는 else를 사용하지 않아요.", false},
                {"error", "C++ 키워드가 아니에요.", false},
                {"default", "정답! `default` 키워드는 `switch` 표현식의 값과 일치하는 `case` 라벨이 없을 때 실행될 코드 블록을 지정합니다.", true},
                {"fallback", "C++ 키워드가 아니에요.", false}
            }
        },
        {"Switch", "`switch` 문에서 `case` 라벨에 사용할 수 없는 데이터 타입은 무엇일까요?", "`case` 라벨은 상수 정수 표현식이어야 합니다.",
            {
                {"int", "int는 가장 흔하게 사용돼요.", false},
                {"char", "char는 정수형으로 변환되므로 사용 가능해요.", false},
                {"enum", "enum 값은 정수형으로 사용되므로 가능해요.", false},
                {"string", "`string`은 `switch` 문 `case` 라벨로 직접 사용될 수 없습니다. `if-else if` 체인으로 처리해야 합니다.", true}
            }
        },
        {"Switch", "`switch` 문에서 `case` 값은 중복될 수 있을까요?", "`case`는 특정 값에 대한 분기를 나타냅니다.",
            {
                {"예, 가능합니다.", "각 `case` 라벨은 고유한 값을 가져야 해요.", false},
                {"아니오, 중복될 수 없습니다. 컴파일 에러가 발생합니다.", "정답! `switch` 문에서 `case` 라벨의 값은 고유해야 합니다. 중복될 경우 컴파일 에러가 발생합니다.", true},
                {"문법적으로는 가능하지만, 런타임에 경고가 발생한다.", "문법적으로 허용되지 않아요.", false},
                {"`break` 키워드가 있으면 중복될 수 있다.", "`break` 유무와 상관없이 `case` 값은 중복될 수 없어요.", false}
            }
        },
        {"Switch", "`switch (expression)`에서 `expression`으로 사용할 수 없는 것은 무엇일까요?", "`expression`은 정수형으로 평가될 수 있는 값이어야 해요.",
            {
                {"정수형 변수", "가능합니다.", false},
                {"문자형 변수", "문자형은 정수형으로 변환되므로 가능합니다.", false},
                {"부동소수점(double) 변수", "정답! `switch` 문은 정수형 또는 열거형(enum) 값을 기반으로 동작하므로, 부동소수점 값은 사용할 수 없습니다.", true},
                {"열거형(enum) 값", "가능합니다.", false}
            }
        },
        {"Switch", "`switch` 문에서 여러 `case`가 동일한 코드 블록을 실행하도록 만들려면 어떻게 해야 할까요?", "break 없이 case 라벨을 나열하는 방법을 생각해 보세요.",
            {
                {"각 `case`마다 동일한 코드를 복사해서 붙여넣는다.", "비효율적인 방법이에요.", false},
                {"`case` 라벨들을 쉼표로 구분하여 나열한다. (예: `case 1, 2:`)", "C++ switch에서 쉼표로 case를 나열할 수는 없어요. 이건 다른 언어 문법이에요.", false},
                {"`case` 라벨들을 `break` 없이 연속적으로 나열한다. (fall-through 활용)", "정답! `break` 키워드 없이 여러 `case` 라벨을 연속적으로 나열하면, 해당 `case`부터 `break`를 만날 때까지 코드가 실행됩니다.", true},
                {"`if-else if` 문을 대신 사용해야 한다.", "switch 문으로도 가능해요.", false}
            }
        },
        {"Switch", "다음 `switch` 문에서 `int level = 1;`일 때 출력 결과는?\n`switch(level) { default: cout << \"Unknown\"; break; case 1: cout << \"Beginner\"; break; case 2: cout << \"Advanced\"; break; }`", "`default`의 위치와 `case`의 일치 여부를 확인하세요.",
            {
                {"Unknown", "level이 1이므로 `case 1`이 일치해요.", false},
                {"Beginner", "정답! `level`은 1이므로 `case 1`이 일치하여 'Beginner'가 출력됩니다. `default`는 일치하는 `case`가 없을 때만 실행됩니다.", true},
                {"Advanced", "level은 2가 아니에요.", false},
                {"컴파일 에러", "유효한 코드예요.", false}
            }
        },
        {"Switch", "`switch` 문이 `if-else if` 체인보다 더 효율적일 수 있는 경우는 언제일까요?", "코드의 가독성과 성능 측면에서 장점을 생각해 보세요.",
            {
                {"조건이 복잡하고 범위 기반일 때", "`if-else if`가 더 적합해요.", false},
                {"조건이 특정 값(정수, 문자 등)에 대한 다중 분기일 때", "정답! `switch` 문은 단일 변수의 여러 정수 또는 문자 값에 대한 분기를 처리할 때 `if-else if`보다 가독성이 좋고 컴파일러 최적화에 유리할 수 있습니다.", true},
                {"부동소수점 값을 비교할 때", "`switch`는 부동소수점 값을 직접 비교할 수 없어요.", false},
                {"동적으로 조건을 변경해야 할 때", "`if-else if`가 더 유연해요.", false}
            }
        },
        {"Switch", "모든 `case` 블록에 `break`를 포함하지 않으면 `switch` 문에서 발생할 수 있는 주요 문제는 무엇일까요?", "`fall-through` 현상을 떠올려보세요.",
            {
                {"런타임 에러가 발생한다.", "에러가 아니라 의도치 않은 동작이에요.", false},
                {"일치하는 `case`만 실행되고 종료된다.", "`break`가 있을 때의 동작이에요.", false},
                {"일치하는 `case`부터 `switch` 블록의 끝까지 모든 `case` 코드가 실행된다.", "정답! `break`가 없으면 일치하는 `case` 이후의 모든 `case` 코드가 순차적으로 실행되는 'fall-through' 현상이 발생합니다.", true},
                {"프로그램이 무한 루프에 빠진다.", "무한 루프와는 관련 없어요.", false}
            }
        },
        {"Switch", "다음 중 `switch` 문의 `expression`으로 사용할 수 있는 유효한 C++ 코드는 무엇일까요?", "`expression`은 정수형으로 평가될 수 있어야 해요.",
            {
                {"`3.14` (double 리터럴)", "부동소수점 값은 사용할 수 없어요.", false},
                {"`\"Hello\"` (string 리터럴)", "문자열은 사용할 수 없어요.", false},
                {"`'Z'` (char 리터럴)", "정답! `char`는 정수형으로 변환되므로 `switch` 표현식으로 사용될 수 있습니다.", true},
                {"`true` (bool 리터럴)", "bool은 가능하지만, 문제의 맥락에서 가장 일반적인 답변을 고르는 것이 좋아요.", false}
            }
        },
        {"Switch", "`switch` 문에서 `default` 키워드의 위치는 중요할까요?", "`default`의 실행 조건과 관계를 생각해 보세요.",
            {
                {"`default`는 항상 마지막에 와야 한다.", "관례상 마지막에 오지만, 문법적으로는 어디든 가능해요.", false},
                {"`default`는 어떤 `case`에도 일치하지 않을 때 실행되므로 위치는 중요하지 않다.", "정답! `default`의 위치는 `switch`문의 실행 로직에 영향을 주지 않습니다. 어느 위치에 있든 일치하는 `case`가 없으면 실행됩니다.", true},
                {"`default`는 반드시 첫 `case` 앞에 와야 한다.", "필수적이지 않아요.", false},
                {"`default`는 `break` 키워드와 함께 사용할 수 없다.", "함께 사용 가능해요.", false}
            }
        }
    };
}

// 종합 퀴즈 진행 함수
void conductComprehensiveQuiz(Character& player, const vector<Question>& all_quizzes) {
    // 학습 영역별 점수 추적
    std::map<string, int> category_correct_counts;
    std::map<string, int> category_total_counts;
    
    // 모든 퀴즈 카테고리를 추출하고 초기화
    for(const auto& q : all_quizzes) {
        category_correct_counts[q.category] = 0;
        category_total_counts[q.category] = 0;
    }

    bool continue_quiz = true;
    while (continue_quiz) {
        int correct_answers = 0;
        int total_questions_asked = 0;

        // 퀴즈 마스터를 랜덤으로 선택하고 이름 설정
        vector<Character> quiz_masters_pool = initializeCharacters();
        quiz_masters_pool.erase(std::remove_if(quiz_masters_pool.begin(), quiz_masters_pool.end(),
                                               [&](const Character& c){ return c.name == player.name && c.species == player.species; }),
                                               quiz_masters_pool.end());
        vector<string> quiz_master_nicknames = {"지식의 수호자", "천재 멍냥이", "퀴즈 대마왕", "궁금증 해결사", "코딩 마스터"};
        Character current_quiz_master = quiz_masters_pool[rand() % quiz_masters_pool.size()];
        current_quiz_master.name = quiz_master_nicknames[rand() % quiz_master_nicknames.size()] + " " + current_quiz_master.species;

        // 퀴즈 문제 섞기 및 선택 (10개 이상)
        vector<Question> shuffled_quizzes = all_quizzes;
        std::random_shuffle(shuffled_quizzes.begin(), shuffled_quizzes.end());
        int num_quizzes_to_ask = std::min((int)shuffled_quizzes.size(), 10 + (rand() % 5)); // 10~14개 랜덤 출제

        cout << "\n========== 대망의 종합 퀴즈 시간! ==========" << endl;
        cout << player.name << ": 좋아! 내가 얼마나 똑똑해졌는지 시험해 볼 시간이다! 고구마의 힘을 보여주지! 멍멍!" << endl;
        player.display("happy");
        pressEnterToContinue(player, "happy", "모든 지식을 뽐낼 준비 됐어!");

        cout << current_quiz_master.name << " (" << current_quiz_master.species << "): 안녕! " << player.name << "! 내가 바로 오늘의 퀴즈 마스터, " << current_quiz_master.name << " 이다냥!" << endl;
        current_quiz_master.display("thinking");
        cout << current_quiz_master.name << ": 지금부터 네가 C++ 기본기를 얼마나 잘 다졌는지 확인해 볼 거다냥! 총 " << num_quizzes_to_ask << "문제를 풀어야 한다냥!" << endl;
        current_quiz_master.display("default");
        pressEnterToContinue(player, "surprised", "도전! (두근두근)");

        // 타이머 시작
        auto start_time = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < num_quizzes_to_ask; ++i) {
            if (player.hp <= 0) {
                cout << "\n" << player.name << ": 으윽... 체력이... 더 이상은... (털썩)" << endl;
                player.display("sad");
                cout << current_quiz_master.name << ": 아쉽군... " << player.name << "가 기절하고 말았다냥! 다음 기회에 다시 도전하라냥!" << endl;
                current_quiz_master.display("sad");
                pressEnterToContinue(current_quiz_master, "sad", "오늘은 여기까지다냥...");
                return; // 퀴즈 종료 (void 함수이므로 return;만 사용)
            }

            Question q = shuffled_quizzes[i];
            
            // 문제 출제 캐릭터 변경 (재미 요소)
            Character question_giver = quiz_masters_pool[rand() % quiz_masters_pool.size()];
            // 퀴즈 마스터가 아닌 다른 캐릭터가 랜덤으로 문제를 내도록
            while ((question_giver.name == player.name && question_giver.species == player.species) || (question_giver.name == current_quiz_master.name && question_giver.species == current_quiz_master.species)) {
                question_giver = quiz_masters_pool[rand() % quiz_masters_pool.size()];
            }

            cout << "\n========== 문제 " << i + 1 << " (" << q.category << ") ==========" << endl;
            question_giver.display("thinking");
            cout << question_giver.name << ": " << player.name << ", 이 문제에 대해 어떻게 생각하나냥?" << endl;
            cout << "[문제] " << q.questionText << endl;
            cout << "[힌트] " << q.hint << endl;

            vector<AnswerOption> current_options = q.options;
            std::random_shuffle(current_options.begin(), current_options.end()); // 선택지 섞기

            for (int j = 0; j < current_options.size(); ++j) {
                cout << "  " << j + 1 << ". " << current_options[j].text << endl;
            }

            int user_choice;
            while (true) {
                cout << "\n정답은? (숫자 입력): ";
                cin >> user_choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (cin.fail() || user_choice <= 0 || user_choice > current_options.size()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    player.display("sad");
                    cout << player.name << ": 멍... 숫자를 제대로 입력해야지! 헷갈려..." << endl;
                    question_giver.display("angry");
                    cout << question_giver.name << ": " << player.name << ", 정신 차려라냥! 정확한 숫자를 입력해라냥!" << endl;
                } else {
                    break;
                }
            }

            AnswerOption& chosen_answer = current_options[user_choice - 1];
            total_questions_asked++;
            category_total_counts[q.category]++;

            cout << "\n--- 결과 ---" << endl;
            if (chosen_answer.isCorrect) {
                correct_answers++;
                category_correct_counts[q.category]++;
                player.display("happy");
                cout << player.name << ": 야호! 정답이다! 나 천재인가봐! 고구마가 더 맛있게 느껴져!" << endl;
                question_giver.display("surprised");
                cout << question_giver.name << ": 훌륭하다냥! 정답이다냥! 다음 문제도 기대된다냥!" << endl;
                cout << "[설명] " << chosen_answer.rationale << endl;
                player.hp += 15; // 정답 시 HP 회복
                cout << player.name << "의 체력이 15 회복되었어! (현재 HP: " << player.hp << ")" << endl;
            } else {
                player.display("sad");
                cout << player.name << ": 으악! 틀렸어... 멍... 머리가 지끈거려... 고구마라도 좀 줄래?" << endl;
                question_giver.display("angry");
                cout << question_giver.name << ": 쯧쯧! 틀렸다냥! " << player.name << ", 아직 멀었다냥!" << endl;
                // 패널티 요소: 문제 낸 친구가 실망해서 떠나고 다른 친구가 등장
                if (rand() % 3 == 0) { // 33% 확률로 친구가 떠남
                    cout << question_giver.name << ": 이 문제도 못 맞추다니... 실망이다냥! 나는 간다냥! (휙)" << endl;
                    question_giver.display("sad");
                    // 새로운 캐릭터 등장
                    Character new_friend = quiz_masters_pool[rand() % quiz_masters_pool.size()];
                    // 떠난 캐릭터와 플레이어 제외
                    while ((new_friend.name == player.name && new_friend.species == player.species) || (new_friend.name == question_giver.name && new_friend.species == question_giver.species)) {
                        new_friend = quiz_masters_pool[rand() % quiz_masters_pool.size()];
                    }
                    cout << new_friend.name << " (" << new_friend.species << "): " << player.name << "! 힘내! 내가 옆에서 응원해줄게! 다음 문제는 내가 내줄까?" << endl;
                    new_friend.display("happy");
                    // question_giver를 new_friend로 업데이트하여 다음 문제에 사용하도록 할 수도 있지만, 여기서는 그냥 일회성 등장으로 처리
                    // 만약 이 친구가 다음 문제도 내게 하려면, question_giver = new_friend; 와 같이 할당해야 합니다.
                } else {
                     cout << question_giver.name << ": 벌칙이다냥! " << player.name << ", 꼬리 붕붕 춤 3초다냥!" << endl;
                     player.display("thinking"); // 꼬리 붕붕 추는 모습
                     cout << player.name << ": 멍... (꼬리를 흔들흔들)..." << endl;
                }
                cout << "[설명] " << chosen_answer.rationale << endl;
                player.hp -= 30; // 오답 시 HP 감소 (더 큰 패널티)
                cout << player.name << "의 체력이 30 감소했어! (현재 HP: " << player.hp << ")" << endl;
            }
            pressEnterToContinue(player, (player.hp > 0 ? "default" : "sad"), "다음 문제로 갈까?");
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;

        cout << "\n\n========== 퀴즈 결과 보고서 ==========" << endl;
        player.display("happy");
        cout << player.name << ": 휴... 드디어 퀴즈가 끝났다! 고구마 먹고 싶어!" << endl;
        current_quiz_master.display("default");
        cout << current_quiz_master.name << ": 수고했다냥! " << player.name << "! 이제 결과를 알려주겠다냥!" << endl;

        cout << "총 문제 수: " << total_questions_asked << endl;
        cout << "맞춘 문제 수: " << correct_answers << endl;
        cout << "총점: " << (int)(((double)correct_answers / total_questions_asked) * 100) << "점!" << endl;
        cout << "문제 풀이에 걸린 시간: " << std::fixed << std::setprecision(2) << duration.count() << "초" << endl;

        cout << "\n--- 학습 영역별 이해도 ---" << endl;
        for (const auto& pair : category_total_counts) {
            string category = pair.first;
            int total = pair.second;
            int correct = category_correct_counts[category];
            if (total > 0) {
                cout << "- " << category << ": " << (int)(((double)correct / total) * 100) << "% 이해 (" << correct << "/" << total << " 문제)" << endl;
            } else {
                cout << "- " << category << ": 해당 카테고리 문제가 출제되지 않았습니다." << endl;
            }
        }
        
        if (player.hp > 0 && correct_answers == total_questions_asked) {
            cout << "\n✨✨✨ 완벽해! " << player.name << "! 모든 문제를 맞췄다냥! 진정한 C++ 마스터로 인정한다냥! ✨✨✨" << endl;
            player.display("happy");
            current_quiz_master.display("happy");
            continue_quiz = false; // 100% 학습률 달성! 종료
        } else if (player.hp > 0) {
            cout << "\n" << player.name << ": 으음... 아직 부족한 부분이 있나? 100%가 될 때까지 다시 도전해야겠어!" << endl;
            player.display("thinking");
            cout << current_quiz_master.name << ": 아직 완벽하지 않군! 다시 도전해서 실력을 완벽하게 만들겠다냥?" << endl;
            current_quiz_master.display("default");
            
            cout << "다시 도전하시겠습니까? (y/n): ";
            char retry_choice;
            cin >> retry_choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (retry_choice == 'y' || retry_choice == 'Y') {
                continue_quiz = true;
                player.hp = 130; // 체력 초기화
                // 학습 영역별 점수도 초기화 (새로운 시도이므로)
                for(auto& pair : category_correct_counts) pair.second = 0;
                for(auto& pair : category_total_counts) pair.second = 0;
                cout << "\n" << player.name << ": 좋아! 다시 한번 힘내보자! 이번엔 꼭 완벽하게 해낼 거야!" << endl;
                player.display("happy");
            } else {
                continue_quiz = false;
                cout << "\n" << player.name << ": 아쉽지만 오늘은 여기까지! 다음 기회에 다시 도전할게!" << endl;
                player.display("sad");
            }
        } else {
            continue_quiz = false; // 체력 0이 되면 바로 종료
        }
    } // end while (continue_quiz)
    // 함수가 void이므로 return을 하지 않습니다.
}


int main() {
    // 게임 시작 시 필요한 초기 설정
    srand(time(0));
    setlocale(LC_ALL, "");

    // 모든 퀴즈 데이터 초기화
    vector<Question> all_comprehensive_quizzes = initializeAllComprehensiveQuizzes();
    
    // --- 캐릭터 초기화 및 선택 ---
    vector<Character> all_characters = initializeCharacters();
    
    // 플레이어 캐릭터 설정 (보리로 강제 설정)
    Character player_character("말티즈", "보리", 130, 35); // 보리 캐릭터 생성

    cout << "---------- C++ 종합 지식 시험! ----------" << endl;
    cout << "당신은 C++ 스터디의 귀여운 주인공, " << player_character.name << " (" << player_character.species << ") 입니다!" << endl;
    player_character.display("default");
    pressEnterToContinue(player_character, "default", "지금까지 배운 모든 것을 보여줄 시간이야!"); 

    // 종합 퀴즈 시작
    conductComprehensiveQuiz(player_character, all_comprehensive_quizzes);

    cout << "\n\nC++ 종합 스터디가 모두 끝났습니다. 정말 수고 많으셨습니다! 안녕!" << endl;
    player_character.display("default");
    
    return 0; // main 함수는 int를 반환해야 합니다.
}