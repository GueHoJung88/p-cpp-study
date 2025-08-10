#include <iostream> // cout, cin, endl 등을 사용하기 위해 필요
#include <string>   // string 타입을 사용하기 위해 필요
#include <vector>   // vector를 사용하기 위해 필요
#include <limits>   // numeric_limits를 사용하기 위해 필요 (cin.ignore 버퍼 비우기)
#include <cstdlib>  // srand, rand를 사용하기 위해 필요
#include <ctime>    // time을 사용하기 위해 필요 (랜덤 시드)
#include <locale>   // setlocale을 사용하기 위해 필요 (한글 출력)
#include <algorithm> // std::random_shuffle, std::find, std::remove_if
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
vector<Question> initializeAllStringQuizzes() {
    return {
        // --- 문자열 기본 (string 타입, include <string>) ---
        {
            "C++에서 'Hello World'와 같은 텍스트를 저장할 때 사용하는 가장 기본적인 데이터 타입은 무엇일까요?",
            "글자들의 집합을 담는 타입이에요.",
            {
                {"int", "int는 정수를 저장할 때 사용해요. 텍스트를 담을 수 없답니다.", false},
                {"char", "char는 단일 문자를 저장하지만, 'Hello World'처럼 여러 글자를 담기엔 부족해요.", false},
                {"string", "정답! string 타입은 여러 문자로 이루어진 텍스트를 저장하는 데 사용됩니다.", true},
                {"bool", "bool은 참(true) 또는 거짓(false)만 저장하는 논리형 타입이에요.", false}
            }
        },
        {
            "string 타입을 사용하기 위해 C++ 코드에 반드시 포함해야 하는 헤더 파일은 무엇일까요?",
            "string이라는 이름과 관련된 헤더 파일을 찾아보세요.",
            {
                {"<iostream>", "<iostream>은 입출력(cout, cin)을 위한 헤더 파일이에요.", false},
                {"<vector>", "<vector>는 동적 배열인 vector를 위한 헤더 파일이에요.", false},
                {"<string>", "정답! string 클래스를 사용하려면 <string> 헤더 파일을 포함해야 합니다.", true},
                {"<numeric>", "<numeric>은 숫자 관련 함수를 위한 헤더 파일이에요.", false}
            }
        },
        {
            "다음 중 올바른 string 변수 선언 및 초기화 방법은 무엇일까요?",
            "string 타입의 변수를 선언하고 큰따옴표로 값을 할당하는 방법을 떠올려보세요.",
            {
                {"string myText = 'Hello';", "문자열은 작은따옴표(')가 아닌 큰따옴표(\")로 감싸야 해요.", false},
                {"char myText = \"Hello\";", "char는 단일 문자를 위한 타입이며, 문자열은 담을 수 없어요.", false},
                {"String myText = \"Hello\";", "C++에서 string은 'S'가 소문자여야 해요. (string)", false},
                {"string myText = \"Hello\";", "정답! string 변수는 이렇게 선언하고 큰따옴표로 값을 초기화합니다.", true}
            }
        },
        // --- 문자열 연결 (Concatenation, append) ---
        {
            "두 개의 string 변수 `str1 = \"안녕\"`과 `str2 = \"하세요\"`를 연결하여 `\"안녕하세요\"`를 만들려면 어떤 연산자를 사용해야 할까요?",
            "문자열을 합칠 때 사용하는 친숙한 연산자예요.",
            {
                {"-", "빼기 연산자는 문자열에 사용할 수 없어요.", false},
                {"*", "곱하기 연산자는 문자열에 사용할 수 없어요.", false},
                {"+", "정답! + 연산자는 문자열을 연결(concatenation)할 때 사용됩니다.", true},
                {"/", "나누기 연산자는 문자열에 사용할 수 없어요.", false}
            }
        },
        {
            "다음 중 `string firstName = \"John\"; string lastName = \"Doe\";`를 `\"John Doe\"`로 연결하는 올바른 방법이 아닌 것은 무엇일까요?",
            "공백을 추가하는 방법을 여러 가지로 생각해보고, 잘못된 것을 골라보세요.",
            {
                {"string fullName = firstName + \" \" + lastName;", "이것은 올바른 방법입니다. 공백 문자열을 추가했어요.", false},
                {"string fullName = firstName + ' ' + lastName;", "이것도 올바른 방법입니다. 단일 문자 공백을 추가했어요.", false},
                {"string fullName = firstName.append(\" \").append(lastName);", "append() 함수를 체인으로 연결하여 사용할 수 있어요.", false},
                {"string fullName = firstName.concatenate(lastName);", "concatenate() 함수는 C++ 표준 string에 존재하지 않습니다.", true}
            }
        },
        {
            "`string s1 = \"Hello\";`에 `\" World\"`를 추가하여 `\"Hello World\"`로 만들려면 `s1.append(\" World\");`와 같이 `append()` 함수를 사용할 수 있습니다. 이 함수의 반환형은 무엇일까요?",
            "대부분의 `std::string` 멤버 함수는 자기 자신(`*this`)을 반환하여 체이닝을 가능하게 해요.",
            {
                {"void", "void는 아무것도 반환하지 않음을 의미해요. append()는 체이닝이 가능해요.", false},
                {"string", "정답! append() 함수는 변경된 string 객체의 참조(`string&`)를 반환합니다. 이를 통해 함수 호출을 연결할 수 있죠.", true},
                {"int", "int는 정수형 타입으로, 문자열 함수와 관련이 없어요.", false},
                {"bool", "bool은 논리형 타입으로, 문자열 함수와 관련이 없어요.", false}
            }
        },
        // --- 숫자와 문자열 ---
        {
            "`int num = 10;`과 `string text = \"20\";`이 있을 때, `text + num`의 결과는 무엇일까요?",
            "C++에서 숫자와 문자열의 직접적인 덧셈(연결)은 허용되지 않습니다.",
            {
                {"30 (int)", "문자열과 숫자는 직접 덧셈이 되지 않아요.", false},
                {"\"1020\" (string)", "문자열과 숫자는 직접 연결되지 않아요.", false},
                {"\"2010\" (string)", "문자열과 숫자는 직접 연결되지 않아요.", false},
                {"컴파일 에러 발생", "정답! C++은 문자열과 숫자의 직접적인 덧셈(연결)을 허용하지 않아 컴파일 에러가 발생합니다.", true}
            }
        },
        {
            "`string s_num1 = \"5\";`와 `string s_num2 = \"7\";`이 있을 때, `string result = s_num1 + s_num2;`의 결과는 무엇일까요?",
            "두 문자열의 + 연산은 어떻게 동작할까요?",
            {
                {"12 (int)", "문자열끼리의 + 연산은 덧셈이 아닌 연결이에요.", false},
                {"\"57\" (string)", "정답! 두 string은 연결되어 '57'이라는 새로운 string이 됩니다.", true},
                {"에러 발생", "+ 연산자는 string에도 정의되어 있어 에러가 발생하지 않아요.", false},
                {"\"12\" (string)", "값을 숫자로 변환하여 더하는 것이 아니에요.", false}
            }
        },
        // --- 문자열 길이 (length(), size()) ---
        {
            "`string example = \"Programming\";`의 길이를 얻기 위해 사용할 수 있는 함수는 무엇일까요?",
            "문자열의 크기를 알려주는 두 가지 함수 이름이 있어요.",
            {
                {"count()", "count()는 다른 용도로 사용되는 함수입니다.", false},
                {"size() 또는 length()", "정답! size()와 length()는 string의 길이를 반환하는 동일한 기능을 합니다.", true},
                {"len()", "len()은 C++ 표준 string에 존재하지 않습니다. (Python에서 주로 사용)", false},
                {"getLength()", "getLength()는 C++ 표준 string에 존재하지 않습니다.", false}
            }
        },
        {
            "`string empty_str = \"\";` 일 때, `empty_str.length()`의 결과는 무엇일까요?",
            "빈 문자열에는 몇 글자가 있을까요?",
            {
                {"1", "빈 문자열은 아무 글자도 포함하고 있지 않아요.", false},
                {"0", "정답! 빈 문자열의 길이는 0입니다.", true},
                {"에러", "빈 문자열의 길이를 구하는 것은 에러가 아니에요.", false},
                {"NULL", "NULL은 포인터 관련 용어입니다.", false}
            }
        },
        // --- 문자열 접근 ([], at()) ---
        {
            "string text = \"Coding\";`에서 문자 'd'에 접근하려면 어떤 인덱스를 사용해야 할까요?",
            "문자열의 인덱스는 0부터 시작해요.",
            {
                {"0", "'C'에 해당해요.", false},
                {"1", "'o'에 해당해요.", false},
                {"2", "정답! 'd'는 0부터 시작하는 인덱스로 2번째에 있습니다.", true},
                {"3", "'i'에 해당해요.", false}
            }
        },
        {
            "string word = \"Apple\";`에서 마지막 문자인 'e'에 접근하는 올바른 방법은 무엇일까요?",
            "마지막 인덱스는 길이에서 1을 빼야 해요.",
            {
                {"word[word.length()]", "length()는 문자열의 총 길이를 반환하므로, 이는 유효하지 않은 인덱스(Out of Bounds)가 될 수 있어요.", false},
                {"word[word.length() - 1]", "정답! 문자열 인덱스는 0부터 시작하므로, 마지막 문자는 (길이 - 1) 인덱스에 있습니다.", true},
                {"word[5]", "문자열의 길이가 5이므로 인덱스 5는 유효하지 않아요.", false},
                {"word.last()", "last() 함수는 C++ 표준 string에 존재하지 않습니다.", false}
            }
        },
        {
            "string data = \"Data\";`에서 첫 번째 문자를 'F'로 변경하려면 어떤 코드를 사용해야 할까요?",
            "인덱스에 직접 새 문자를 할당하거나 at() 함수를 사용하세요.",
            {
                {"data.setChar(0, 'F');", "setChar()는 C++ 표준 string에 존재하지 않습니다.", false},
                {"data[0] = \"F\";", "문자열이 아닌 단일 문자를 할당할 때는 작은따옴표를 사용해야 해요.", false},
                {"data.at(0) = 'F';", "정답! at() 함수를 사용하거나 `data[0] = 'F';`처럼 직접 인덱싱하여 변경할 수 있습니다.", true},
                {"data = 'F' + data.substring(1);", "이 방법도 가능은 하지만, 더 직관적인 방법이 있어요.", false}
            }
        },
        // --- 특수 문자 (Escape Characters) ---
        {
            "C++에서 문자열 안에 큰따옴표(`\"`)를 포함하려면 어떤 이스케이프 시퀀스를 사용해야 할까요?",
            "역슬래시 뒤에 넣고 싶은 문자를 붙여보세요.",
            {
                {"/'", "역슬래시(`\\`)를 사용해야 해요.", false},
                {"\\\"", "정답! \\\"는 문자열 안에 큰따옴표를 삽입합니다.", true},
                {"//", "//는 한 줄 주석을 위한 기호예요.", false},
                {"_\"_", "_는 이스케이프 문자가 아니에요.", false}
            }
        },
        {
            "다음 중 C++ 문자열에서 새로운 줄로 이동하는(줄 바꿈) 이스케이프 시퀀스는 무엇일까요?",
            "새로운 줄(New Line)을 의미하는 영단어를 떠올려보세요.",
            {
                {"\\t", "\\t는 탭(Tab)을 위한 이스케이프 시퀀스예요.", false},
                {"\\r", "\\r은 캐리지 리턴(Carriage Return)을 위한 이스케이프 시퀀스예요.", false},
                {"\\n", "정답! \\n은 새로운 줄(New Line)로 이동하는 이스케이프 시퀀스입니다.", true},
                {"\\s", "\\s는 C++ 표준 이스케이프 시퀀스가 아니에요. (정규 표현식에서 공백을 의미하기도 함)", false}
            }
        },
        {
            "`string path = \"C:\\\\Program Files\";`와 같이 두 개의 역슬래시(`\\\\`)를 사용한 이유는 무엇일까요?",
            "역슬래시 자체가 특수 문자이기 때문에 발생하는 상황이에요.",
            {
                {"오타이다.", "오타가 아니에요! 의도된 표현이랍니다.", false},
                {"하나의 역슬래시를 문자열에 포함시키기 위해서", "정답! 역슬래시(`\\`) 자체도 이스케이프 문자이므로, 문자열 안에 역슬래시를 표현하려면 두 개(`\\\\`)를 사용해야 합니다.", true},
                {"두 개의 역슬래시를 실제로 출력하기 위해서", "두 개를 입력해야 하나가 출력돼요.", false},
                {"경로를 나타내는 특별한 문법이다.", "경로 표현에 사용될 수 있지만, 근본적인 이유는 이스케이프 문자 규칙 때문이에요.", false}
            }
        },
        // --- 사용자 입력 문자열 (cin, getline) ---
        {
            "사용자가 공백이 포함된 이름(`\"John Doe\"`)을 입력했을 때, `cin >> name;`을 사용하면 어떤 결과가 나올까요?",
            "cin은 공백을 입력의 끝으로 인식해요.",
            {
                {"`\"John Doe\"` 전체가 `name`에 저장된다.", "cin은 공백을 만나면 입력을 중단해요.", false},
                {"`\"John\"`만 `name`에 저장되고, `\" Doe\"`는 버퍼에 남는다.", "정답! cin은 공백을 구분자로 인식하여 첫 단어만 읽어들입니다.", true},
                {"에러가 발생한다.", "에러는 발생하지 않지만, 예상과 다른 결과가 나올 수 있어요.", false},
                {"`\"Doe\"`만 `name`에 저장된다.", "첫 단어인 `\"John\"`이 저장돼요.", false}
            }
        },
        {
            "공백을 포함한 한 줄 전체의 텍스트를 사용자로부터 입력받기 위해 사용하는 C++ 함수는 무엇일까요?",
            "입출력 객체 `cin`과 함께 사용되며, 한 '라인'을 읽어들여요.",
            {
                {"read()", "read()는 다른 용도로 사용되는 함수입니다.", false},
                {"input()", "input()은 C++ 표준 라이브러리의 함수가 아니에요.", false},
                {"getline(cin, myString);", "정답! getline() 함수는 cin으로부터 한 줄 전체를 읽어들여 string 변수에 저장합니다.", true},
                {"cin.readLine();", "readLine()은 C++ 표준 cin 객체에 존재하지 않습니다.", false}
            }
        },
        {
            "`cin`으로 `int`나 `char`를 입력받은 직후 `getline()`을 사용하면, 원치 않는 빈 줄이 입력되는 경우가 있습니다. 이를 방지하기 위해 `getline()` 호출 전에 어떤 함수를 사용해야 할까요?",
            "입력 버퍼에 남아있는 이전의 줄바꿈 문자를 제거해야 해요.",
            {
                {"cin.clear();", "cin.clear()는 입력 스트림의 에러 플래그를 지울 때 사용해요.", false},
                {"cin.flush();", "flush()는 출력 스트림을 비울 때 주로 사용해요. 입력과는 관련이 적습니다.", false},
                {"cin.ignore(numeric_limits<streamsize>::max(), '\\n');", "정답! 이 코드는 입력 버퍼에 남아있는 모든 문자를 지정된 구분자('\\n')까지 무시하여 버퍼를 비웁니다.", true},
                {"cin.reset();", "reset()는 C++ 표준 cin 객체에 존재하지 않습니다.", false}
            }
        },
        // --- 이름공간 (Namespace) ---
        {
            "다음 코드에서 `string` 앞에 `std::`를 붙이지 않아도 되는 이유는 무엇일까요?\n`#include <iostream>\n#include <string>\nusing namespace std;\nint main() { string name = \"Alice\"; ... }`",
            "using namespace std; 문장의 역할을 생각해보세요.",
            {
                {"string은 기본 데이터 타입이라서", "string은 클래스 타입이지 기본 데이터 타입이 아니에요.", false},
                {"<string> 헤더 파일에 자동으로 포함되어 있어서", "헤더 파일 포함과는 별개로 이름공간 접두사가 필요해요.", false},
                {"`using namespace std;` 문장 때문에", "정답! `using namespace std;`는 `std` 이름공간에 있는 요소들을 `std::` 접두사 없이 사용할 수 있게 합니다.", true},
                {"main 함수 안에 있어서", "main 함수 안이라서가 아니라, 이름공간 선언 때문이에요.", false}
            }
        },
        // --- C-스타일 문자열 ---
        {
            "C++에서 `char message[] = \"Hello\";`와 같이 선언하는 문자열을 무엇이라고 부를까요?",
            "C 언어에서 유래한 방식이에요.",
            {
                {"Java 스타일 문자열", "Java와는 관련이 없어요.", false},
                {"Python 스타일 문자열", "Python과는 관련이 없어요.", false},
                {"C-스타일 문자열", "정답! char 배열을 이용한 문자열은 C 언어에서 유래했기 때문에 C-스타일 문자열이라고 부릅니다.", true},
                {"Modern C++ 문자열", "Modern C++에서는 `std::string`을 더 선호해요.", false}
            }
        },
        {
            "`std::string`과 `char[]` (C-스타일 문자열) 중, 현대 C++에서 더 권장되는 문자열 타입은 무엇일까요?",
            "더 편리하고 안전한 기능을 제공하는 쪽을 선택해야 해요.",
            {
                {"char[]", "char[]는 편리성이 떨어지고 안전성 문제가 있을 수 있어요.", false},
                {"std::string", "정답! std::string은 더 많은 유용한 함수와 메모리 관리를 자동화하여 편리하고 안전합니다.", true},
                {"둘 다 똑같다", "기능과 편의성에서 차이가 있어요.", false},
                {"상황에 따라 다르다", "특정 C 함수와 상호작용할 때 외에는 std::string이 더 일반적이에요.", false}
            }
        },
        // --- 추가 퀴즈 (응용) ---
        {
            "`string s = \"Hello\"; s[s.length()] = '!';` 코드를 실행하면 어떤 문제가 발생할 수 있을까요?",
            "문자열 인덱스의 범위를 벗어나는 경우를 생각해 보세요.",
            {
                {"정상적으로 'Hello!'가 된다.", "s.length()는 유효한 인덱스가 아니에요.", false},
                {"컴파일 에러가 발생한다.", "런타임 에러가 발생할 가능성이 더 높아요.", false},
                {"런타임 에러(Out of Bounds Access)가 발생할 수 있다.", "정답! s.length()는 문자열의 길이를 반환하며, 이는 유효한 마지막 인덱스(length - 1)를 넘어섭니다. 배열의 범위를 벗어난 접근은 예측 불가능한 결과를 초래해요.", true},
                {"문자열이 비어버린다.", "문자열이 비어버리는 것은 아니에요.", false}
            }
        },
        {
            "`string data = \"ABC\";` 일 때, `data.at(1)`과 `data[1]`은 어떤 결과를 반환할까요?",
            "두 가지 접근 방식의 차이점을 생각해보세요.",
            {
                {"`at(1)`은 'A', `[1]`은 'B'", "둘 다 동일한 인덱스를 가리켜요.", false},
                {"둘 다 'B'를 반환한다.", "정답! `at()`과 `[]`는 모두 동일한 인덱스의 문자에 접근하는 기능을 제공합니다.", true},
                {"`at()`은 문자열의 길이, `[1]`은 두 번째 문자", "at()은 문자를 반환해요.", false},
                {"`at()`은 예외를 던질 수 있지만, `[]`는 그렇지 않다.", "이것은 정확한 설명이지만, 반환값에 대한 질문이므로 오답이에요.", false}
            }
        },
        {
            "`string message; getline(cin, message);` 이후, `message` 변수에 `\"Hello, C++!\"`가 저장되었다면, `message.find(\"C++\")`의 반환값은 무엇일까요?",
            "`find` 함수는 부분 문자열이 시작하는 인덱스를 반환해요. (인덱스 0부터 시작)",
            {
                {"0", "\"Hello\"의 시작 인덱스예요.", false},
                {"7", "정답! 'C'는 0부터 시작하는 인덱스에서 7번째 위치에 있습니다. (H-0, e-1, l-2, l-3, o-4, ,-5,  -6, C-7)", true},
                {"-1", "-1은 보통 찾지 못했을 때 반환돼요.", false},
                {"에러", "find 함수는 에러를 발생시키지 않아요.", false}
            }
        },
        {
            "만약 `string text = \"Hello\";`에서 `text.erase(1, 2);`를 호출한다면, `text`는 어떤 값이 될까요?",
            "`erase(pos, len)`은 `pos` 위치부터 `len` 길이만큼 문자를 삭제해요.",
            {
                {"\"Hlo\"", "인덱스 1부터 2개의 문자를 삭제하면 'el'이 사라져요.", true},
                {"\"Helo\"", "하나의 문자만 삭제되는 것이 아니에요.", false},
                {"\"Hllo\"", "다른 문자가 삭제되었어요.", false},
                {"\"Hello\"", "문자열이 변경되지 않았어요.", false}
            }
        },
        {
            "`string s = \"apple\";` 일 때, `s.empty()`의 반환값은 무엇일까요?",
            "`empty()` 함수는 문자열이 비어있는지 여부를 확인해요.",
            {
                {"true", "문자열에 'apple'이라는 내용이 있으므로 비어있지 않아요.", false},
                {"false", "정답! 'apple'이라는 내용이 있으므로 문자열은 비어있지 않습니다.", true},
                {"0", "bool 타입은 true/false를 반환해요.", false},
                {"5", "길이를 반환하는 함수가 아니에요.", false}
            }
        },
        {
            "`string s = \"orange\";` 일 때, `s.at(6)`을 호출하면 어떤 결과가 발생할 가능성이 높을까요?",
            "`at()` 함수는 유효하지 않은 인덱스에 대해 안전한 처리를 해요.",
            {
                {"문자 'e'가 반환된다.", "인덱스 6은 범위를 벗어납니다. 'e'는 인덱스 5에 있어요.", false},
                {"에러가 발생하지 않고 빈 문자열이 반환된다.", "빈 문자열이 반환되지 않아요.", false},
                {"std::out_of_range 예외가 발생한다.", "정답! `at()` 함수는 유효하지 않은 인덱스에 접근하려 할 때 `std::out_of_range` 예외를 던져 안전하게 처리할 수 있게 합니다.", true},
                {"컴파일 에러가 발생한다.", "이는 런타임에 발생하는 문제입니다.", false}
            }
        },
        {
            "`string s = \"cat\";`에 `s.insert(1, \"dog\");`를 호출하면 `s`는 어떤 값이 될까요?",
            "`insert(pos, str)`는 `pos` 위치에 `str`을 삽입해요.",
            {
                {"\"dogcat\"", "첫 번째 인덱스에 삽입되는 것이 아니에요.", false},
                {"\"cdogat\"", "전체 문자열의 시작에 삽입되는 것이 아니에요.", false},
                {"\"cdogaht\"", "오타가 포함되어 있어요.", false},
                {"\"cdogato\"", "오타가 포함되어 있어요.", false},
                {"\"cdogat\"", "인덱스 1 위치(두 번째 글자 앞)에 삽입돼요. 'c' 다음에 'dog'가 들어가요.", true}
            }
        },
        {
            "`string s = \"banana\";` 일 때, `s.substr(1, 3)`의 반환값은 무엇일까요?",
            "`substr(pos, len)`은 `pos` 위치부터 `len` 길이만큼의 부분 문자열을 반환해요.",
            {
                {"\"ban\"", "인덱스 1부터 시작하고 3글자이므로 'ana'가 됩니다.", false},
                {"\"ana\"", "정답! 인덱스 1('a')부터 시작하여 3글자('ana')를 잘라냅니다.", true},
                {"\"nana\"", "4글자가 아니에요.", false},
                {"\"bana\"", "시작 인덱스가 잘못되었어요.", false}
            }
        },
        {
            "`string s = \"Hello\";`와 `string t = \"hello\";`를 비교할 때, `s == t`의 결과는 무엇일까요?",
            "C++의 문자열 비교는 대소문자를 구분해요.",
            {
                {"true", "대소문자가 다르므로 같지 않아요.", false},
                {"false", "정답! C++에서 문자열 비교는 대소문자를 구분하므로 'H'와 'h'가 다르다고 판단합니다.", true},
                {"컴파일 에러", "비교 연산자는 문자열에도 유효해요.", false},
                {"런타임 에러", "에러가 발생하지 않아요.", false}
            }
        },
        {
            "`string text = \"C++ is fun!\";`에서 `text.replace(0, 3, \"Java\");`를 호출하면 `text`는 어떤 값이 될까요?",
            "`replace(pos, len, str)`는 `pos` 위치부터 `len` 길이만큼의 문자를 `str`로 대체해요.",
            {
                {"\"Java is fun!\"", "정답! 인덱스 0부터 3글자(\"C++\")를 \"Java\"로 대체합니다.", true},
                {"\"C++Java is fun!\"", "대체하는 것이 아니라 삽입하는 것이 아니에요.", false},
                {"\"JavaC++ is fun!\"", "다른 위치에 대체되었어요.", false},
                {"\"Javafun!\"", "너무 많은 문자가 대체되었어요.", false}
            }
        },
        {
            "사용자로부터 입력받은 문자열 `std::string inputStr;`의 양 끝에서 공백을 제거하려면 어떤 함수를 사용해야 할까요? (힌트: `std::string`에 직접 지원하는 함수는 아니지만, 흔히 사용되는 방식)",
            "일반적으로 직접 구현하거나, 특정 라이브러리의 도움을 받아야 해요.",
            {
                {"inputStr.trim();", "trim()은 C++ 표준 string에 존재하지 않습니다. (Python, Java 등에 존재)", false},
                {"inputStr.removeWhitespace();", "removeWhitespace()는 C++ 표준 string에 존재하지 않습니다.", false},
                {"직접 구현하거나 외부 라이브러리 사용", "정답! std::string 자체에는 양 끝 공백을 제거하는 trim()과 같은 내장 함수가 없습니다. 보통 직접 구현하거나 Boost 같은 외부 라이브러리의 도움을 받습니다.", true},
                {"inputStr.strip();", "strip()은 C++ 표준 string에 존재하지 않습니다. (Python에 존재)", false}
            }
        },
        {
            "`std::string s1 = \"apple\"; std::string s2 = s1;` 이후, `s1`과 `s2`는 메모리상에서 어떻게 저장될까요?",
            "`std::string`은 값(value)으로 복사될 때 새로운 메모리를 할당해요.",
            {
                {"동일한 메모리 주소를 공유한다.", "std::string은 별도의 메모리를 할당하여 독립적인 객체로 복사돼요.", false},
                {"s1과 s2는 각각 독립적인 메모리를 가진다.", "정답! std::string은 복사 생성자(copy constructor)를 통해 새로운 메모리에 문자열 내용을 복사하므로, 두 객체는 독립적인 메모리를 가집니다.", true},
                {"s2는 s1의 포인터만 가진다.", "포인터만 가지는 것은 다른 개념이에요. (참조 복사나 포인터 직접 할당)", false},
                {"컴파일 에러가 발생한다.", "정상적인 복사 연산이에요.", false}
            }
        },
        {
            "`string s = \"Hello\";`에서 `s.c_str()` 함수가 반환하는 값의 타입은 무엇일까요?",
            "`c_str()`은 C-스타일 문자열을 반환해요.",
            {
                {"string", "std::string 객체가 아닌 C-스타일 문자열을 반환해요.", false},
                {"char*", "정답! `c_str()` 함수는 C-스타일 문자열인 `const char*` 타입의 포인터를 반환합니다. 이는 C 함수와 상호작용할 때 유용해요.", true},
                {"void*", "void*는 모든 타입의 포인터를 가리킬 수 있는 제네릭 포인터예요.", false},
                {"int*", "int*는 정수형 포인터예요.", false}
            }
        },
        {
            "다음 중 `string` 객체를 생성하는 데 사용할 수 없는 방법은 무엇일까요?",
            "생성자를 사용하는 다양한 방법을 떠올려보세요.",
            {
                {"`string s;` (기본 생성자)", "빈 문자열로 초기화하는 기본 생성자예요. 가능해요.", false},
                {"`string s(\"Hello\");` (C-스타일 문자열로부터)", "C-스타일 문자열을 인자로 받는 생성자예요. 가능해요.", false},
                {"`string s = 'C';` (단일 문자로 초기화)", "string은 단일 문자로 직접 초기화될 수 없어요. char는 string과 다른 타입이에요.", true},
                {"`string s(5, 'a');` (문자 반복)", "특정 문자를 여러 번 반복하여 문자열을 생성하는 생성자예요. 가능해요. (예: \"aaaaa\")", false}
            }
        },
        {
            "`string s = \"Data\";` 일 때, `s.capacity()`는 무엇을 의미할까요?",
            "`capacity`는 할당된 메모리 공간을 나타내요.",
            {
                {"문자열의 현재 길이", "길이는 `length()` 또는 `size()`예요.", false},
                {"문자열이 현재 할당된 메모리에서 최대로 저장할 수 있는 문자 수", "정답! `capacity()`는 문자열이 현재 할당된 메모리 공간 내에서 재할당 없이 저장할 수 있는 최대 문자 수를 반환합니다.", true},
                {"문자열의 남은 공간", "남은 공간이 아니라 총 할당 공간이에요.", false},
                {"컴파일 에러", "유효한 함수예요.", false}
            }
        },
        {
            "`string s = \"apple\";`에서 `s.clear();`를 호출하면 `s`는 어떤 상태가 될까요?",
            "`clear()`는 문자열의 내용을 지워요.",
            {
                {"`s`는 메모리에서 해제된다.", "메모리에서 해제되는 것은 아니지만, 내용은 지워져요.", false},
                {"`s`는 빈 문자열이 된다 (`s.length()`는 0).", "정답! `clear()` 함수는 문자열의 모든 내용을 지우고 길이를 0으로 만듭니다.", true},
                {"`s`는 'a'만 남는다.", "모든 내용이 지워져요.", false},
                {"에러가 발생한다.", "정상적인 함수 호출이에요.", false}
            }
        },
        {
            "`string s = \"hello\";`와 `string t = \"hello\";`를 비교할 때, `s.compare(t)`의 결과는 무엇일까요?",
            "`compare` 함수는 두 문자열이 같으면 0을 반환해요.",
            {
                {"양수", "두 문자열이 동일하므로 양수가 반환되지 않아요.", false},
                {"음수", "두 문자열이 동일하므로 음수가 반환되지 않아요.", false},
                {"0", "정답! `compare()` 함수는 두 문자열이 사전적으로 동일할 때 0을 반환합니다.", true},
                {"true", "compare 함수는 int를 반환해요.", false}
            }
        },
        {
            "`string s = \"test\";`에서 `s.push_back('!');`를 호출하면 `s`는 어떤 값이 될까요?",
            "`push_back`은 문자열의 끝에 단일 문자를 추가해요.",
            {
                {"\"test\"", "문자열이 변경되지 않았어요.", false},
                {"\"!test\"", "문자열의 시작에 추가되는 것이 아니에요.", false},
                {"\"test!\"", "정답! `push_back()` 함수는 문자열의 끝에 단일 문자를 추가합니다.", true},
                {"컴파일 에러", "유효한 함수 호출이에요.", false}
            }
        },
        {
            "`string s = \"example\";`에서 `s.pop_back();`을 호출하면 `s`는 어떤 값이 될까요?",
            "`pop_back`은 문자열의 끝에서 단일 문자를 제거해요.",
            {
                {"\"example\"", "문자열이 변경되지 않았어요.", false},
                {"\"exampl\"", "정답! `pop_back()` 함수는 문자열의 마지막 문자를 제거합니다.", true},
                {"\"xample\"", "시작 문자가 제거되는 것이 아니에요.", false},
                {"컴파일 에러", "유효한 함수 호출이에요.", false}
            }
        },
        {
            "`string s = \"apple\";`에서 `s.resize(3);`를 호출하면 `s`는 어떤 값이 될까요?",
            "`resize`는 문자열의 길이를 조절해요. 길이가 짧아지면 잘리고, 길어지면 기본 값으로 채워져요.",
            {
                {"\"apple\"", "문자열의 길이가 변경돼요.", false},
                {"\"app\"", "정답! `resize(3)`은 문자열의 길이를 3으로 줄여 'app'이 됩니다.", true},
                {"\"ple\"", "다른 부분이 잘렸어요.", false},
                {"\"app   \"", "길이가 늘어날 때 공백으로 채워져요. 줄어들 때는 잘려요.", false}
            }
        },
        {
            "`string s = \"hello\";`에서 `s.find('l')`의 반환값은 무엇일까요?",
            "`find()`는 찾고자 하는 문자가 처음 나타나는 인덱스를 반환해요.",
            {
                {"0", "'h'의 인덱스예요.", false},
                {"1", "'e'의 인덱스예요.", false},
                {"2", "정답! 'l'은 0부터 시작하는 인덱스로 2번째에 처음 나타납니다.", true},
                {"3", "두 번째 'l'의 인덱스예요.", false}
            }
        },
        {
            "`string s = \"banana\";`에서 `s.rfind('a')`의 반환값은 무엇일까요?",
            "`rfind()`는 찾고자 하는 문자가 뒤에서부터 처음 나타나는 인덱스를 반환해요.",
            {
                {"1", "첫 번째 'a'의 인덱스예요.", false},
                {"3", "중간 'a'의 인덱스예요.", false},
                {"5", "정답! `rfind()`는 뒤에서부터 찾아 처음 발견되는 'a'의 인덱스(원래 문자열 기준)인 5를 반환합니다.", true},
                {"-1", "찾지 못했을 때 반환돼요. 여기서는 찾을 수 있어요.", false}
            }
        },
        {
            "`string s = \"test\"; s.assign(\"new\");` 이후 `s`의 값은 무엇일까요?",
            "`assign()`은 문자열의 내용을 완전히 새로운 것으로 교체해요.",
            {
                {"\"testnew\"", "assign은 추가가 아니라 교체예요.", false},
                {"\"test\"", "assign은 문자열을 변경해요.", false},
                {"\"new\"", "정답! `assign()` 함수는 문자열의 내용을 인자로 전달된 새로운 문자열로 완전히 바꿉니다.", true},
                {"컴파일 에러", "유효한 함수 호출이에요.", false}
            }
        },
        {
            "다음 중 `std::string`과 관련된 `getline` 함수가 아닌 것은 무엇일까요?",
            "입력 스트림과 string 변수를 인자로 받는 형태를 생각해보세요.",
            {
                {"`std::getline(std::cin, myString);`", "가장 일반적인 형태의 getline이에요. 맞아요.", false},
                {"`std::istream& getline (std::istream& is, std::string& str, char delim);`", "구분자를 지정할 수 있는 오버로드된 getline 함수예요. 맞아요.", false},
                {"`std::string::getline();`", "`getline`은 `std::string`의 멤버 함수가 아니라 전역 함수예요.", true}, // string 클래스에 속한 멤버 함수가 아님
                {"`std::getline(inputStream, targetString);`", "템플릿 인자 없이도 사용될 수 있는 일반적인 형태예요. 맞아요.", false}
            }
        },
        {
            "`string s = \"abcdef\";` 일 때, `s.at(s.length() / 2)`의 결과는 무엇일까요?",
            "문자열의 중간 인덱스를 계산해보세요.",
            {
                {"'c'", "인덱스 2에 해당해요.", false},
                {"'d'", "정답! 길이가 6이고 인덱스는 0부터 5까지이므로, 6 / 2 = 3 인덱스에 있는 'd'가 반환됩니다.", true},
                {"'e'", "다른 인덱스예요.", false},
                {"'f'", "마지막 인덱스예요.", false}
            }
        },
        {
            "`string s = \"Hello\";`에 `s.insert(5, \" World!\");`를 호출하면 `s`는 어떤 값이 될까요?",
            "`insert(pos, str)`는 `pos` 위치에 `str`을 삽입해요. `pos`가 `s.length()`와 같으면 문자열 끝에 추가돼요.",
            {
                {"\"Hello World!\"", "정답! 인덱스 5는 'o' 다음의 위치, 즉 문자열의 끝을 의미하므로, \" World!\"가 끝에 추가됩니다.", true},
                {"\" World!Hello\"", "시작에 삽입되는 것이 아니에요.", false},
                {"\"Hell World!o\"", "다른 위치에 삽입되었어요.", false},
                {"컴파일 에러", "유효한 함수 호출이에요.", false}
            }
        },
        {
            "`string s = \"hello\";`와 `string t = \"hello\";`를 비교할 때, `s.compare(t)`의 결과는 무엇일까요?",
            "`compare` 함수는 두 문자열이 같으면 0을 반환해요.",
            {
                {"양수", "두 문자열이 동일하므로 양수가 반환되지 않아요.", false},
                {"음수", "두 문자열이 동일하므로 음수가 반환되지 않아요.", false},
                {"0", "정답! `compare()` 함수는 두 문자열이 사전적으로 동일할 때 0을 반환합니다.", true},
                {"true", "compare 함수는 int를 반환해요.", false}
            }
        },
        {
            "`string s = \"C++\";` 일 때, `s.empty()`의 반환값은 무엇일까요?",
            "문자열에 내용이 있는지 없는지 확인하는 함수예요.",
            {
                {"true", "문자열에 'C++'이라는 내용이 있으므로 비어있지 않아요.", false},
                {"false", "정답! 문자열에 내용이 있으므로 `false`를 반환합니다.", true},
                {"0", "bool 타입을 반환해요.", false},
                {"3", "길이를 반환하는 함수가 아니에요.", false}
            }
        },
        {
            "`string s = \"apple\";` 일 때, `s.front()`의 반환값은 무엇일까요?",
            "`front()` 함수는 문자열의 첫 번째 문자에 대한 참조를 반환해요.",
            {
                {"'a'", "정답! `front()` 함수는 문자열의 첫 번째 문자를 반환합니다.", true},
                {"'e'", "마지막 문자예요.", false},
                {"에러", "유효한 함수 호출이에요.", false},
                {"빈 문자", "빈 문자열이 아니므로 빈 문자를 반환하지 않아요.", false}
            }
        },
        {
            "`string s = \"banana\";` 일 때, `s.back()`의 반환값은 무엇일까요?",
            "`back()` 함수는 문자열의 마지막 문자에 대한 참조를 반환해요.",
            {
                {"'b'", "첫 번째 문자예요.", false},
                {"'a'", "정답! `back()` 함수는 문자열의 마지막 문자인 'a'를 반환합니다.", true},
                {"에러", "유효한 함수 호출이에요.", false},
                {"빈 문자", "빈 문자열이 아니므로 빈 문자를 반환하지 않아요.", false}
            }
        },
        {
            "C++11부터 `std::string`의 내용에 직접 접근할 수 있는 함수로 `data()`가 있습니다. `string s = \"test\"; char* ptr = s.data();`를 실행하면 `ptr`은 무엇을 가리킬까요?",
            "`data()`는 문자열의 실제 데이터를 담고 있는 메모리 블록의 포인터를 반환해요.",
            {
                {"`s` 객체 자체", "객체 자체가 아니라 객체 내부의 문자열 데이터예요.", false},
                {"`\"test\"`의 시작 주소", "정답! `data()`는 문자열 `\"test\"`가 저장된 메모리 공간의 시작 주소(`char*`)를 가리킵니다. 이는 C 함수와 상호작용할 때 유용해요.", true},
                {"`s`의 길이", "길이가 아니라 데이터 주소예요.", false},
                {"에러", "유효한 함수 호출이에요.", false}
            }
        },
        {
            "`string s = \"\";` 일 때, `s.max_size()`는 무엇을 의미할까요?",
            "`max_size`는 string 객체가 저장할 수 있는 최대 문자 수를 나타내요.",
            {
                {"현재 시스템 메모리의 크기", "시스템 메모리가 아니라 string 객체의 이론적인 최대 크기예요.", false},
                {"string이 저장할 수 있는 이론적인 최대 문자 수", "정답! `max_size()`는 `std::string` 객체가 저장할 수 있는 이론적인 최대 문자 수를 반환합니다. 이는 시스템 및 컴파일러에 따라 달라질 수 있어요.", true},
                {"현재 문자열의 최대 길이", "현재 문자열의 길이는 `length()`예요.", false},
                {"컴파일러가 제공하는 최대 길이", "컴파일러 및 시스템 아키텍처에 따라 달라져요.", false}
            }
        },
        {
            "`string s = \"abc\"; s.insert(3, 2, 'X');`를 호출하면 `s`는 어떤 값이 될까요?",
            "`insert(pos, count, char)`는 `pos` 위치에 `char`를 `count`만큼 반복하여 삽입해요.",
            {
                {"\"abcX\"", "두 번 삽입되어야 해요.", false},
                {"\"abcXX\"", "정답! 인덱스 3(문자열 끝)에 'X'를 2번 삽입하여 \"abcXX\"가 됩니다.", true},
                {"\"abXXc\"", "다른 위치에 삽입되었어요.", false},
                {"컴파일 에러", "유효한 함수 호출이에요.", false}
            }
        },
        {
            "`string s = \"banana\";`에서 `s.find('a', 2)`의 반환값은 무엇일까요?",
            "`find(char, pos)`는 `pos` 위치부터 검색을 시작하여 문자가 처음 나타나는 인덱스를 반환해요.",
            {
                {"1", "검색 시작 위치가 2이므로 인덱스 1은 해당되지 않아요.", false},
                {"3", "정답! 인덱스 2('n')부터 'a'를 검색하므로, 그 다음에 오는 'a'의 인덱스인 3을 반환합니다.", true},
                {"5", "마지막 'a'의 인덱스예요.", false},
                {"-1", "찾지 못했을 때 반환돼요. 여기서는 찾을 수 있어요.", false}
            }
        }
    };
}

// 다음 단락으로 넘어가기 위한 함수 (캐릭터 포함)
// Character.h의 display 함수를 const로 변경해야 합니다.
void pressEnterToContinue(const Character& speaker, const string& emotion = "default", const string& message = "계속하려면 Enter 키를 누르세요...") {
    cout << "\n--- " << speaker.name << " (" << speaker.species << ") ---" << endl;
    speaker.display(emotion); // 이 부분이 const 오류를 발생시키는 원인
    cout << message << endl;
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
    cout << quiz_master.name << ": 자, " << player.name << "! 네가 배운 문자열 지식을 시험해 볼 시간이다! 긴장해라!" << endl;
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
            cout << quiz_master.name << ": 쯧쯧! 아직 멀었군! 정답은 `" << shuffled_options[0].text << "` (올바른 답은 항상 첫 번째 옵션이라고 가정) 야! 다시 한번 잘 들어라!" << endl; 
            cout << "[설명] " << chosen_option.rationale << endl;
            player.hp -= 20; // 오답 시 HP 감소
            cout << player.name << "의 체력이 20 감소했어! (현재 HP: " << player.hp << ")" << endl;
        }
        
        // 퀴즈 결과 확인 후 다음 문제로 넘어갈 때도 캐릭터 등장
        pressEnterToContinue(player, (player.hp > 0 ? "happy" : "sad"), "다음 문제로 넘어갈까? (Enter)");
    }
    
    // 퀴즈 종료 시 퀴즈 마스터 대화
    cout << "\n" << quiz_master.name << ": 휴... 오늘 퀴즈는 여기까지다. " << player.name << ", 수고했다! 네 실력이 많이 늘었군!" << endl;
    quiz_master.display("default");
    pressEnterToContinue(player, (player.hp > 0 ? "happy" : "sad"), "정말 끝난 건가? (Enter)");
}


int main() {
    // 게임 시작 시 필요한 초기 설정
    srand(time(0));
    setlocale(LC_ALL, "");

    // 퀴즈 데이터 준비
    vector<Question> all_string_quizzes = initializeAllStringQuizzes();
    
    // --- 캐릭터 초기화 및 선택 ---
    vector<Character> all_characters = initializeCharacters();
    
    // 플레이어 캐릭터 설정 (보리로 강제 설정)
    // Character.h에 말티즈 종족과 보리 정보가 추가되었다는 전제 하에 아래 코드 사용
    Character player_character("말티즈", "보리", 130, 35); // 보리 캐릭터 생성 (Character.h에 말티즈 display 추가 필요)
    
    cout << "---------- C++ 문자열(Strings) 스터디 시작! ----------" << endl;
    cout << "당신은 C++ 스터디의 귀여운 주인공, " << player_character.name << " (" << player_character.species << ") 입니다!" << endl;
    player_character.display("default");
    pressEnterToContinue(player_character, "default", "어서 스터디를 시작해볼까? (Enter)"); // 보리 캐릭터와 함께 시작

    // 메인 가이드 캐릭터 선언 및 초기화
    Character main_guide = all_characters[0]; // 치와와 '치치'를 메인 가이드로 (초기값)

    // --- 단락 1: 문자열이란? ---
    cout << main_guide.name << " (" << main_guide.species << "): 안녕! 나의 사랑스러운 후배, " << player_character.name << "!" << endl;
    main_guide.display("happy");
    cout << "오늘은 C++ 스터디의 새로운 주제, '문자열(Strings)'에 대해 알아볼 거야!" << endl;
    cout << "문자열은 말 그대로 '텍스트'나 '글자들'을 저장하는 데 사용된단다. 예를 들면, \"Hello World\" 같은 문장 말이야." << endl;
    cout << "C++에서 문자열은 `string`이라는 특별한 타입의 변수에 저장하고, 항상 큰따옴표(\")로 감싸서 사용해야 해." << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "자, 다음으로 넘어가볼까? (Enter)");

    cout << player_character.name << ": 흥. 식은 죽 먹기군. 고구마 먹는 것보다 쉽겠지." << endl;
    player_character.display("default");
    cout << "좋아, 그럼 'greeting'이라는 `string` 변수를 만들고 \"Hello\"를 넣어볼까?" << endl;
    
    cout << "```cpp" << endl;
    cout << "string greeting = \"Hello\";" << endl;
    cout << "```" << endl;
    string greeting_ex = "Hello";
    cout << player_character.name << ": `greeting` 변수에 \"Hello\"가 잘 들어갔나 보자! 결과: " << greeting_ex << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "잘했어! (Enter)");

    cout << main_guide.name << " (" << main_guide.species << "): 아주 잘했어! " << player_character.name << "!" << endl;
    main_guide.display("happy");
    cout << "참, 중요한 거! `string` 타입을 사용하려면 코드 맨 위에 `<string>` 헤더 파일을 꼭 포함해야 해! `#include <string>` 이렇게 말이야!" << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "다음 내용으로 넘어갈까? (Enter)");

    // --- 단락 2: 문자열 연결 (String Concatenation) ---
    cout << main_guide.name << " (" << main_guide.species << "): 다음은 '문자열 연결'이야. " << player_character.name << "처럼 귀여운 이름을 여러 개 합치고 싶을 때 쓰지!" << endl;
    main_guide.display("happy");
    cout << player_character.name << ": 흥! 내 이름을 함부로 쓰지 마! (고구마 째려봄)" << endl;
    player_character.display("angry");
    cout << main_guide.name << " (" << main_guide.species << "): 으음... 화내지 마, " << player_character.name << "! C++에서는 `+` 연산자를 사용하면 두 문자열을 하나로 합칠 수 있어. 이걸 '연결(Concatenation)'이라고 해." << endl;
    main_guide.display("default");
    pressEnterToContinue(main_guide, "default", "연결 예시를 볼까? (Enter)");

    cout << "[실습] 네 이름과 성을 합쳐서 '전체 이름'을 만들어보자." << endl;
    string firstName = "보리";
    string lastName = "강아지";
    string fullName = firstName + lastName; // 문자열 연결
    cout << "```cpp" << endl;
    cout << "string firstName = \"보리\";" << endl;
    cout << "string lastName = \"강아지\";" << endl;
    cout << "string fullName = firstName + lastName;" << endl;
    cout << "// 결과: " << fullName << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 내 이름은 '" << firstName << "'이고, '강아지'는 성이 아니라 종족인데... 어쨌든 합치면: " << fullName << endl;
    player_character.display("default");
    pressEnterToContinue(player_character, "default", "이제 공백을 넣어볼까? (Enter)");

    cout << main_guide.name << " (" << main_guide.species << "): " << player_character.name << ", 그럼 이름 사이에 공백을 넣고 싶으면 어떻게 할까? 힌트! 공백도 하나의 문자열로 생각하면 돼!" << endl;
    main_guide.display("thinking");
    fullName = firstName + " " + lastName; // 공백 추가하여 연결
    cout << "```cpp" << endl;
    cout << "string fullName = firstName + \" \" + lastName;" << endl;
    cout << "// 결과: " << fullName << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 아하! 이렇게 하는 거였군! 결과: " << fullName << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "다음 방법도 궁금해! (Enter)");

    cout << main_guide.name << " (" << main_guide.species << "): 또 다른 방법으로는 `append()` 함수를 사용하는 거야. 문자열 객체가 가지고 있는 기능이지! 마치 네 꼬리에 간식을 붙이는 것처럼!" << endl;
    main_guide.display("surprised");
    cout << "[실습] `append()` 함수로 다시 합쳐보자." << endl;
    string appendFirstName = "보리"; // append를 위해 새 변수 사용
    string appendLastName = "강아지";
    appendFirstName.append(" "); // appendFirstName에 공백 추가
    appendFirstName.append(appendLastName); // appendFirstName에 appendLastName 추가
    cout << "```cpp" << endl;
    cout << "string firstName = \"보리\";" << endl;
    cout << "string lastName = \"강아지\";" << endl;
    cout << "firstName.append(\" \");" << endl;
    cout << "firstName.append(lastName);" << endl;
    cout << "// 결과: " << appendFirstName << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 음... `append()` 함수를 사용한 결과: " << appendFirstName << endl;
    player_character.display("thinking");
    pressEnterToContinue(player_character, "thinking", "`+` 연산자가 더 편한 것 같지만... (Enter)");

    // --- 단락 3: 숫자와 문자열의 덧셈 ---
    Character quiz_master_bull = all_characters[7]; // 불독 '불리'
    cout << quiz_master_bull.name << " (" << quiz_master_bull.species << "): 이봐! " << player_character.name << "! 중요한 경고가 있다! 내 말을 잘 들어야 할 거야!" << endl;
    quiz_master_bull.display("angry");
    cout << "C++에서 `+` 연산자는 숫자에서는 '덧셈'을, 문자열에서는 '연결'을 의미해! 헷갈리면 큰일 나!" << endl;
    pressEnterToContinue(quiz_master_bull, "angry", "예시를 보여주지. (Enter)");

    cout << "[예시 1] 숫자 + 숫자 = 덧셈" << endl;
    int num1_ex = 10;
    int num2_ex = 20;
    int sum_ex = num1_ex + num2_ex;
    cout << "```cpp" << endl;
    cout << "int num1 = 10;" << endl;
    cout << "int num2 = 20;" << endl;
    cout << "int sum = num1 + num2; // 결과: " << sum_ex << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 10 + 20은 당연히 30이지! 냠냠." << endl;
    player_character.display("default");
    pressEnterToContinue(player_character, "default", "다음 예시! (Enter)");

    cout << "[예시 2] 문자열 + 문자열 = 연결" << endl;
    string str1_ex = "10";
    string str2_ex = "20";
    string concat_str_ex = str1_ex + str2_ex;
    cout << "```cpp" << endl;
    cout << "string str1 = \"10\";" << endl;
    cout << "string str2 = \"20\";" << endl;
    cout << "string concat_str = str1 + str2; // 결과: " << concat_str_ex << endl;
    cout << "```" << endl;
    cout << player_character.name << ": \"10\"과 \"20\"을 합치면 \"1020\"이 되는구나! 신기하네." << endl;
    player_character.display("surprised");
    pressEnterToContinue(player_character, "surprised", "가장 중요한 경고! (Enter)");

    cout << quiz_master_bull.name << " (" << quiz_master_bull.species << "): 하지만! 가장 중요한 경고는 이거야!" << endl;
    quiz_master_bull.display("angry");
    cout << "!!! 경고: 숫자와 문자열을 직접 더할 수는 없어! 그렇게 하면 에러가 발생한단다 !!!" << endl;
    cout << "```cpp" << endl;
    cout << "string x = \"10\";" << endl;
    cout << "int y = 20;" << endl;
    cout << "// string z = x + y; // 이 코드는 컴파일 에러를 발생시킵니다!" << endl;
    cout << "```" << endl;
    cout << quiz_master_bull.name << ": 내가 이걸로 초보 모험가들을 많이 혼내줬지! 하하하! 조심하라구!" << endl;
    quiz_master_bull.display("happy");
    pressEnterToContinue(quiz_master_bull, "happy", "다음 주제로! (Enter)");

    // --- 단락 4: 문자열 길이 (String Length) ---
    // main_guide 변수를 재사용
    main_guide = all_characters[5]; // 골든 리트리버 '리버'
    cout << main_guide.name << " (" << main_guide.species << "): 이번엔 문자열의 길이를 재어볼 거야! 예를 들어, 내가 얼마나 많은 간식을 가지고 있는지 세는 것처럼!" << endl;
    main_guide.display("happy");
    cout << "`length()` 함수나 `size()` 함수를 사용하면 문자열에 몇 글자가 있는지 알 수 있어. 둘 다 같은 기능을 한단다!" << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "실습해볼까? (Enter)");

    cout << "[실습] \"멍멍 탐험대\" 문자열의 길이를 재어보자." << endl;
    string team_name_len = "멍멍 탐험대";
    cout << "```cpp" << endl;
    cout << "string team_name = \"멍멍 탐험대\";" << endl;
    cout << "cout << team_name.length(); // 결과: " << team_name_len.length() << endl;
    cout << "cout << team_name.size();   // 결과: " << team_name_len.size() << endl;
    cout << "```" << endl;
    cout << player_character.name << ": \"멍멍 탐험대\"의 길이... " << team_name_len.length() << " 글자!" << endl;
    player_character.display("happy");
    main_guide.display("happy");
    cout << main_guide.name << ": 완벽해! " << player_character.name << "! 이젠 얼마나 긴 문자열도 두렵지 않겠네!" << endl;
    pressEnterToContinue(main_guide, "happy", "다음 주제로 가자! (Enter)");

    // --- 단락 5: 문자열 접근 (Access Strings) ---
    cout << player_character.name << ": 음... 문자열에서 특정 글자만 쏙 뽑아낼 수도 있나? 마치 고구마에서 심지를 빼내듯이?" << endl;
    player_character.display("thinking");
    // main_guide 변수를 재사용
    main_guide = all_characters[6]; // 비숑 프리제 '숑숑'
    cout << main_guide.name << " (" << main_guide.species << "): 물론이지! " << player_character.name << "! 네 귀여운 질문이 나를 기쁘게 하는군!" << endl;
    main_guide.display("happy");
    cout << "대괄호 `[]` 안에 '인덱스 번호'를 넣으면 돼. 기억해! 첫 글자는 0번부터 시작한단다! 마치 줄을 서는 것처럼!" << endl;
    pressEnterToContinue(main_guide, "happy", "예시를 보자! (Enter)");

    cout << "[실습] \"Boree\" 문자열에서 첫 번째 글자와 두 번째 글자를 뽑아보자." << endl;
    string my_string_access = "Boree";
    cout << "```cpp" << endl;
    cout << "string my_string = \"Boree\";" << endl;
    cout << "cout << my_string[0]; // 결과: " << my_string_access[0] << endl;
    cout << "cout << my_string[1]; // 결과: " << my_string_access[1] << endl;
    cout << "```" << endl;
    cout << player_character.name << ": \"Boree\"의 0번째 글자는 '" << my_string_access[0] << "', 1번째 글자는 '" << my_string_access[1] << "' 이군! 쉽다 쉬워!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "마지막 글자는? (Enter)");
    
    cout << main_guide.name << " (" << main_guide.species << "): 그럼 마지막 글자는 어떻게 뽑을까? 전체 길이에서 1을 빼면 돼! 인덱스는 0부터 시작하니까!" << endl;
    main_guide.display("thinking");
    cout << "```cpp" << endl;
    cout << "cout << my_string[my_string.length() - 1]; // 결과: " << my_string_access[my_string_access.length() - 1] << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 오! 마지막 글자는 '" << my_string_access[my_string_access.length() - 1] << "'이구나! 이것도 완벽해!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "at() 함수도 궁금해! (Enter)");

    cout << main_guide.name << " (" << main_guide.species << "): 그리고 `at()` 함수를 써도 똑같이 접근할 수 있어! `my_string.at(0)` 이런 식으로 말이야. 편한 걸로 쓰면 된단다!" << endl;
    main_guide.display("surprised");
    cout << "```cpp" << endl;
    cout << "cout << my_string.at(0); // 결과: " << my_string_access.at(0) << endl;
    cout << "```" << endl;
    player_character.display("default");
    pressEnterToContinue(player_character, "default", "다음 주제로! (Enter)");

    // --- 단락 6: 문자열 글자 변경 (Change String Characters) ---
    cout << player_character.name << ": 그럼 글자를 바꿀 수도 있어? 고구마 심지를 파서 다른 걸로 채워 넣듯이?" << endl;
    player_character.display("thinking");
    main_guide.display("happy");
    cout << main_guide.name << " (" << main_guide.species << "): 응! 인덱스 번호를 사용해서 원하는 위치의 글자를 새로운 글자로 바꿔줄 수 있어. 이때는 한 글자니까 작은따옴표(`'`)를 써야 해!" << endl;
    main_guide.display("default");
    pressEnterToContinue(main_guide, "default", "바로 실습해보자! (Enter)");

    cout << "[실습] \"Hello\"를 \"Jello\"로 바꿔보자." << endl;
    string change_string_ex = "Hello";
    cout << player_character.name << ": 바꾸기 전에는: " << change_string_ex << endl;
    player_character.display("default");
    cout << "```cpp" << endl;
    cout << "string myString = \"Hello\";" << endl;
    cout << "myString[0] = 'J';" << endl;
    cout << "// 결과: " << change_string_ex << " -> Jello" << endl;
    cout << "```" << endl;
    change_string_ex[0] = 'J'; // 첫 번째 글자 변경
    cout << player_character.name << ": 첫 번째 글자를 'J'로 바꾸니: " << change_string_ex << " 가 되었어! 신기해!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "at() 함수로도 해볼까? (Enter)");
    
    main_guide.display("happy");
    cout << main_guide.name << " (" << main_guide.species << "): `at()` 함수로도 변경 가능해! 똑같지? 원하는 대로 바꿔봐!" << endl;
    change_string_ex = "Mello";
    cout << player_character.name << ": 다시 원래대로 'Mello'로 돌려놓고..." << endl;
    player_character.display("default");
    cout << "```cpp" << endl;
    cout << "string myString = \"Mello\";" << endl;
    cout << "myString.at(0) = 'H';" << endl;
    cout << "// 결과: " << change_string_ex << " -> Hello" << endl;
    cout << "```" << endl;
    change_string_ex.at(0) = 'H';
    cout << player_character.name << ": 이제 'H'로 바꿔서: " << change_string_ex << " ! 완벽해!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "다음 중요한 주제로! (Enter)");

    // --- 단락 7: 특수 문자 (Special Characters) ---
    // main_guide 변수를 재사용
    main_guide = all_characters[2]; // 허스키 '허허'
    cout << main_guide.name << " (" << main_guide.species << "): 이번엔 아주 중요한 개념이야! '특수 문자'!" << endl;
    main_guide.display("thinking");
    cout << "때로는 문자열 안에 큰따옴표(\")나 작은따옴표(') 같은 특별한 기호들을 넣고 싶을 때가 있어. 그냥 쓰면 컴퓨터가 헷갈려 할 거야!" << endl;
    cout << "이럴 때는 `백슬래시(\\) 이스케이프 문자`를 사용해서 C++에게 '이건 특별한 의미가 아니라 그냥 문자열의 일부야!'라고 알려줘야 해!" << endl;
    main_guide.display("default");
    pressEnterToContinue(main_guide, "default", "예시를 자세히 볼까? (Enter)");

    cout << "[예시] \"Vikings\"를 큰따옴표 안에 넣어보자." << endl;
    string special_txt_ex = "We are the so-called \"Vikings\" from the north.";
    cout << "```cpp" << endl;
    cout << "string txt = \"We are the so-called \\\"Vikings\\\" from the north.\";" << endl;
    cout << "// 결과: " << special_txt_ex << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 오! `\\\"`를 쓰니 큰따옴표가 잘 나오는군! 결과: " << special_txt_ex << endl;
    player_character.display("surprised");
    pressEnterToContinue(player_character, "surprised", "작은따옴표랑 역슬래시도? (Enter)");

    cout << "[예시] 작은따옴표(')와 역슬래시(`\\`)를 넣어보자." << endl;
    string special_txt2_ex = "It\'s alright. The character \\ is called backslash.";
    cout << "```cpp" << endl;
    cout << "string txt = \"It\\'s alright. The character \\\\ is called backslash.\";" << endl;
    cout << "// 결과: " << special_txt2_ex << endl;
    cout << "```" << endl;
    cout << player_character.name << ": `\\' `는 작은따옴표, `\\\\`는 역슬래시! 정말 신기해!" << endl;
    player_character.display("happy");
    main_guide.display("surprised");
    pressEnterToContinue(main_guide, "surprised", "아주 중요한 이스케이프 문자들! (Enter)");

    cout << main_guide.name << " (" << main_guide.species << "): 자주 쓰는 이스케이프 문자에는 `\\n` (줄바꿈)과 `\\t` (탭)도 있어! 이건 정말 유용하니 꼭 기억해둬!" << endl;
    main_guide.display("happy");
    cout << "```cpp" << endl;
    cout << "cout << \"안녕하세요.\\n저는 " << player_character.name << "입니다.\\t반가워요!\";" << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 짜잔!" << endl;
    cout << "안녕하세요.\n저는 " << player_character.name << "입니다.\t반가워요!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "다음 주제로 넘어가자! (Enter)");

    // --- 단락 8: 사용자 입력 문자열 (User Input Strings) ---
    cout << player_character.name << ": 좋아, 이제 내가 직접 이름을 입력받아볼 차례인가? 자, 모험가! 네 이름을 입력해봐." << endl;
    player_character.display("happy");

    string user_name_cin;
    cout << "당신의 이름은?: ";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 이전 입력이 없으므로 불필요 (맨 처음 실행 시)
    cin >> user_name_cin; // cin으로 한 단어 입력 받기
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 다음 getline을 위해 버퍼 비우기
    cout << player_character.name << ": 오! 네 이름은 '" << user_name_cin << "' 이구나! 멍멍!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "그런데 말이야... (Enter)");

    cout << player_character.name << ": 그런데... 만약 이름에 공백이 있으면 어떻게 될까? 예를 들어 '보리 공주'처럼 말이야..." << endl;
    player_character.display("thinking");
    cout << "```cpp" << endl;
    cout << "string fullName_cin;" << endl; // 변수 이름 변경
    cout << "cout << \"Type your full name: \";" << endl;
    cout << "cin >> fullName_cin; // 공백이 있으면 첫 단어만 저장됩니다." << endl;
    cout << "```" << endl;
    cout << "!!! 중요: `cin >>`은 공백(whitespace)을 만나면 입력을 멈춰! 그래서 'John Doe'라고 입력하면 'John'만 받아진단다." << endl;
    pressEnterToContinue(player_character, "thinking", "실제로 해볼까? (Enter)");

    cout << "[실습] 이번엔 '풀네임'을 입력해봐. 띄어쓰기 해서 입력해봐!" << endl;
    string full_user_name_cin_ex;
    cout << "당신의 풀네임은?: ";
    // 이미 위에서 cin.ignore를 했으므로 바로 cin >> 가능.
    cin >> full_user_name_cin_ex; // 다시 cin으로 입력 시도
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 다음 getline을 위해 버퍼 비우기
    cout << player_character.name << ": 흐음, 'cin >>'으로 받은 풀네임: '" << full_user_name_cin_ex << "' 이군. 예상대로 첫 단어만 나왔어! 힝..." << endl;
    player_character.display("sad");
    pressEnterToContinue(player_character, "sad", "해결책은 없을까? (Enter)");

    // main_guide 변수를 재사용
    main_guide = all_characters[1]; // 웰시코기 '코코'
    cout << main_guide.name << " (" << main_guide.species << "): " << player_character.name << ", 슬퍼하지 마! 나 코코가 해결책을 알려줄게!" << endl;
    main_guide.display("happy");
    cout << "여러 단어를 포함한 한 줄 전체를 입력받으려면 `getline()` 함수를 사용해야 해! `getline(cin, 변수이름)` 이렇게 쓰는 거야." << endl;
    cout << "그리고, `cin >>` 다음에 `getline()`을 바로 사용하면, `cin >>`이 남긴 '엔터(줄바꿈 문자)' 때문에 `getline()`이 바로 실행되어 버리는 문제가 생겨." << endl;
    cout << "이걸 막으려면 `getline()` 호출 전에 `cin.ignore(numeric_limits<streamsize>::max(), '\\n');`을 써서 입력 버퍼를 비워줘야 해! 아주 중요해!" << endl;
    main_guide.display("thinking");
    pressEnterToContinue(main_guide, "thinking", "이제 제대로 입력받아보자! (Enter)");

    cout << "[실습] 다시 풀네임을 입력해봐! 이번엔 `getline()`으로 받아줄게! 띄어쓰기 마음껏 써도 돼!" << endl;
    string full_user_name_getline_ex;
    cout << "당신의 진짜 풀네임은?: ";
    // 이전에 cin.ignore를 했으므로 여기서는 다시 필요 없습니다. (바로 위에서)
    getline(cin, full_user_name_getline_ex); // getline으로 한 줄 입력 받기
    cout << player_character.name << ": 완벽해! `getline()`으로 받은 풀네임: '" << full_user_name_getline_ex << "' 이군! 이걸 보니 고구마가 더 먹고 싶어지는군!" << endl;
    player_character.display("happy");
    main_guide.display("happy");
    cout << main_guide.name << " (" << main_guide.species << "): 이야! " << player_character.name << " 정말 잘하는데? 뿌듯해라!" << endl;
    pressEnterToContinue(main_guide, "happy", "다음 주제로! (Enter)");

    // --- 단락 9: C++ 문자열 이름공간 (String Namespace) ---
    Character current_liki = all_characters[8]; // 임정찬 'Liki'
    cout << current_liki.name << " (" << current_liki.species << "): 저기요! 선생님! 궁금한 게 있어요!" << endl;
    current_liki.display("thinking");
    cout << "어떤 코드에서는 `std::string`이라고 쓰고, 어떤 코드에서는 그냥 `string`이라고 쓰던데, 왜 그래요? 너무 헷갈려요!" << endl;
    pressEnterToContinue(current_liki, "thinking", "정규호에게 물어보자! (Enter)");
    
    Character current_babo = all_characters[9]; // 정규호 '바보'
    cout << current_babo.name << " (" << current_babo.species << "): 아하! " << current_liki.name << "! 그건 `using namespace std;` 때문이야!" << endl;
    current_babo.display("happy");
    cout << "`using namespace std;`를 코드 맨 위에 쓰면 `std::`를 생략하고 바로 `string`이나 `cout` 같은 것들을 쓸 수 있어." << endl;
    cout << "만약 저 문장을 안 쓰면 `std::string`, `std::cout`처럼 `std::`를 꼭 붙여야 한단다. 마치 내 이름 앞에 '바보'를 꼭 붙이는 것처럼!" << endl;
    current_babo.display("default");
    cout << player_character.name << ": 푸흐흐... '바보 정규호'라니... 귀엽군." << endl;
    player_character.display("happy");
    current_liki.display("surprised");
    cout << current_liki.name << ": 아하! 그렇구나! 이제 알겠어요! 감사합니다, " << current_babo.name << " 선생님!" << endl;
    pressEnterToContinue(current_liki, "surprised", "다음 주제로! (Enter)");

    // --- 단락 10: C-스타일 문자열 (C-Style Strings) ---
    Character final_master_swibaek = all_characters[10]; // 싀백 '먀엉'
    cout << final_master_swibaek.name << " (" << final_master_swibaek.species << "): 마지막으로, 고대의 지식을 전해주마. 이 지혜를 받아들여라." << endl;
    final_master_swibaek.display("thinking");
    cout << "C++의 뿌리인 C 언어에서는 `string` 타입이 없었어. 대신 `char` 타입으로 글자 배열을 만들어서 문자열처럼 사용했지. 그걸 'C-스타일 문자열'이라고 한다." << endl;
    final_master_swibaek.display("default");
    pressEnterToContinue(final_master_swibaek, "default", "예시를 통해 자세히 보자. (Enter)");

    cout << "[예시] 일반 string과 C-스타일 string." << endl;
    string greeting1_cstyle = "Hello";    // 일반 string
    char greeting2_cstyle[] = "Hello";    // C-스타일 string (char 배열)
    cout << "```cpp" << endl;
    cout << "string greeting1 = \"Hello\";    // 일반 string" << endl;
    cout << "char greeting2[] = \"Hello\";    // C-스타일 string (char 배열)" << endl;
    cout << "```" << endl;
    cout << player_character.name << ": 일반 string은 `" << greeting1_cstyle << "` 이고, C-스타일 string은 `" << greeting2_cstyle << "` 이로군. 비슷하게 생겼네?" << endl;
    player_character.display("thinking");
    pressEnterToContinue(player_character, "thinking", "하지만 중요한 차이가 있어! (Enter)");
    
    cout << final_master_swibaek.name << " (" << final_master_swibaek.species << "): 그렇다. 현대 C++에서는 `string` 타입이 훨씬 편리하고 안전하니, 특별한 경우가 아니면 `string`을 쓰는 것이 좋다. 나의 지혜로운 말을 기억해라!" << endl;
    final_master_swibaek.display("happy");
    cout << player_character.name << ": 네! 먀엉 선생님! 보리는 `string`이 더 편한 것 같아요!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "드디어 대망의 퀴즈 시간! (Enter)");

    // --- 퀴즈 섹션 ---
    cout << "\n\n========== 문자열 퀴즈 타임! ==========" << endl;
    cout << player_character.name << ": 이제 내가 얼마나 똑똑한지 보여줄 시간인가? 덤벼라, 문제들! 고구마의 힘을 보여주겠어!" << endl;
    player_character.display("happy");
    pressEnterToContinue(player_character, "happy", "퀴즈를 시작해볼까? (Enter)");

    // 퀴즈 마스터를 랜덤으로 선택
    vector<Character> quiz_masters_pool = all_characters;
    // 플레이어 캐릭터는 퀴즈 마스터 풀에서 제외
    // 람다 캡처를 사용할 때, [=] (값으로 캡처) 또는 [&] (참조로 캡처)를 명시적으로 사용해야 합니다.
    // 여기서는 player_character에 접근해야 하므로 참조 캡처 [&]를 사용합니다.
    quiz_masters_pool.erase(std::remove_if(quiz_masters_pool.begin(), quiz_masters_pool.end(), 
                                           [&](const Character& c){ return c.name == player_character.name && c.species == player_character.species; }),
                                           quiz_masters_pool.end());
    
    // 퀴즈 마스터 이름을 랜덤으로 설정 (더 재미있게)
    vector<string> quiz_master_nicknames = {"지식의 수호자", "문제 마스터", "뇌섹냥", "똑똑한 멍멍이", "퀴즈 대장", "현자", "꼬리 흔드는 교수님"};
    Character random_quiz_master = quiz_masters_pool[rand() % quiz_masters_pool.size()];
    random_quiz_master.name = quiz_master_nicknames[rand() % quiz_master_nicknames.size()] + " " + random_quiz_master.species;


    conductQuiz(player_character, random_quiz_master, all_string_quizzes);

    // --- 최종 결과 ---
    cout << "\n\n\n========== 스터디 완료! ==========" << endl;
    if (player_character.hp > 0) {
        cout << "✨ 축하합니다! " << player_character.name << "는(은) 문자열 스터디의 모든 난관을 극복하고 지식의 정점에 도달했습니다!" << endl;
        player_character.display("happy");
        cout << player_character.name << ": 휴... 드디어 끝났군. 이제 고구마 대량 주문이다! 멍멍!" << endl;
    } else {
        player_character.display("sad");
        cout << "💧 아쉽지만, " << player_character.name << "는(은) 체력이 부족하여 더 이상 스터디를 진행할 수 없었습니다. 다음 기회에 다시 도전해요!" << endl;
        cout << player_character.name << ": 고구마... 고구마가 필요해... (털썩 쓰러짐)" << endl;
    }
    cout << "\nC++ 문자열 스터디가 모두 끝났습니다. 정말 수고 많으셨습니다! 안녕!" << endl;

    return 0;
}