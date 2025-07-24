#include <iostream> // cout, cin, endl 등을 사용하기 위해 필요
#include <string>   // string 타입을 사용하기 위해 필요
#include <vector>   // vector를 사용하기 위해 필요
#include <limits>   // numeric_limits를 사용하기 위해 필요 (cin.ignore 버퍼 비우기)
#include <cstdlib>  // srand, rand를 사용하기 위해 필요
#include <ctime>    // time을 사용하기 위해 필요 (랜덤 시드)
#include <locale>   // setlocale을 사용하기 위해 필요 (한글 출력)
#include "Character.h" // 우리가 만든 캐릭터 헤더 파일을 포함합니다.

// using 선언으로 std::를 생략하고 바로 사용할 수 있게 합니다.
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;

// 새로운 말티즈 캐릭터 '보리'를 위한 display 함수 오버로드 또는 Character.h에 추가된 것으로 가정
// 이 코드는 Character.h가 업데이트 되었다는 전제 하에 작성됩니다.
// 만약 Character.h가 업데이트되지 않았다면, 이 코드만으로는 말티즈 아스키 아트가 출력되지 않습니다.

int main() {
    // 랜덤 시드 초기화 (퀴즈 마스터 랜덤 선택 등)
    srand(time(0));
    // 한글 출력을 위해 로케일 설정
    setlocale(LC_ALL, "");

    // 캐릭터 초기화 및 선택 (이전 스터디에서 사용한 방식)
    vector<Character> all_characters = initializeCharacters();

    // 임정찬, 정규호, 싀백 캐릭터가 NPC로 등장할 수 있도록 상세 정보가 Character.h에 추가되어야 합니다.
    // 여기서는 기존 캐릭터 목록을 사용하여 예시를 만듭니다.
    // 플레이어 캐릭터는 '보리'로 가정하고, Character.h에 말티즈가 추가되어야 합니다.
    // Character 보리("말티즈", "보리", 130, 35); // 보리의 HP와 Power는 적절히 설정
    // 스터디 진행을 위해 일단 웰시코기를 플레이어로 가정하고 진행하겠습니다.
    Character player_character = all_characters[1]; // 웰시코기 '코코'를 플레이어로
    player_character.name = "코코"; // 임시로 이름 설정
    player_character.species = "웰시코기"; // 임시로 종족 설정 (실제 Character.h 업데이트 필요)

    // 스터디를 이끌어갈 메인 캐릭터들
    Character boree("말티즈", "보리", 130, 35); // 보리 캐릭터
    Character current_guide = all_characters[0]; // 치와와 '치치'를 첫 가이드로

    cout << "---------- C++ 문자열(Strings) 스터디 시작! ----------" << endl;
    cout << current_guide.name << " (" << current_guide.species << "): 안녕! 오늘은 문자열에 대해 알아볼 거야!" << endl;
    current_guide.display("happy");

    // --- 1. 문자열이란? ---
    cout << "\n--- 1. 문자열(String)이란? ---" << endl;
    cout << "글자들이 모여있는 형태를 '문자열'이라고 해. 예를 들어, 'Hello World' 같은 거지." << endl;
    cout << "C++에서는 문자열을 `string`이라는 특별한 타입의 변수에 저장한단다." << endl;
    cout << "그리고 문자열은 항상 큰따옴표(\")로 감싸야 해!" << endl;

    cout << "\n" << boree.name << " (" << boree.species << "): 흥. 식은 죽 먹기군." << endl;
    boree.display("default");

    cout << "\n[실습] 'greeting'이라는 string 변수를 만들고 \"Hello\"를 넣어볼까?" << endl;
    string greeting = "Hello"; // string 변수 선언 및 초기화
    cout << "greeting 변수의 값: " << greeting << endl;

    cout << current_guide.name << ": 잘했어! `string`을 쓰려면 꼭 `<string>` 헤더 파일을 포함해야 하는 거 잊지 마!" << endl;
    cout << "#include <string> 이걸 코드 맨 위에 써야 해!" << endl;
    current_guide.display("happy");

    // --- 2. 문자열 연결 (String Concatenation) ---
    cout << "\n\n--- 2. 문자열 연결 (String Concatenation) ---" << endl;
    cout << boree.name << ": 그런데 글자들을 합치고 싶으면 어떻게 해? 고구마랑 우유를 같이 먹는 것처럼?" << endl;
    boree.display("thinking");

    cout << current_guide.name << ": 좋은 질문이야! '+' 연산자를 사용하면 두 문자열을 하나로 합칠 수 있어. 이걸 '연결(Concatenation)'이라고 해!" << endl;
    current_guide.display("thinking");

    cout << "\n[실습] 네 이름과 성을 합쳐서 '전체 이름'을 만들어보자." << endl;
    string firstName = "Bo";
    string lastName = "ri";
    string fullName = firstName + lastName; // 문자열 연결
    cout << "이름: " << firstName << ", 성: " << lastName << endl;
    cout << "전체 이름 (firstName + lastName): " << fullName << endl;

    cout << current_guide.name << ": 중간에 공백을 넣고 싶으면 어떻게 할까?" << endl;
    cout << current_guide.name << ": 힌트! ' ' 처럼 공백도 문자열로 생각하면 돼!" << endl;
    
    fullName = firstName + " " + lastName; // 공백 추가하여 연결
    cout << "전체 이름 (firstName + \" \" + lastName): " << fullName << endl;
    current_guide.display("surprised");

    cout << "\n또 다른 방법으로는 `append()` 함수를 사용하는 거야." << endl;
    cout << "[실습] `append()` 함수로 다시 합쳐보자." << endl;
    firstName = "Bo"; // 다시 초기화
    lastName = "ri";
    firstName.append(" "); // firstName에 공백 추가
    firstName.append(lastName); // firstName에 lastName 추가
    cout << "append() 함수 사용 후 firstName: " << firstName << endl;

    cout << boree.name << ": 음... '+'가 편하군. 어쨌든 알겠어." << endl;
    boree.display("default");

    // --- 3. 숫자와 문자열의 덧셈 ---
    cout << "\n\n--- 3. 숫자와 문자열의 덧셈 ---" << endl;
    Character quiz_master = all_characters[7]; // 불독 '불리'
    cout << quiz_master.name << " (" << quiz_master.species << "): 이봐! 중요한 경고가 있다!" << endl;
    quiz_master.display("angry");
    cout << "C++에서 '+' 연산자는 숫자에서는 '덧셈'을, 문자열에서는 '연결'을 의미해!" << endl;

    cout << "\n[예시 1] 숫자 + 숫자 = 덧셈" << endl;
    int num1 = 10;
    int num2 = 20;
    int sum = num1 + num2;
    cout << "10 (int) + 20 (int) = " << sum << endl;

    cout << "\n[예시 2] 문자열 + 문자열 = 연결" << endl;
    string str1 = "10";
    string str2 = "20";
    string concat_str = str1 + str2;
    cout << "\"10\" (string) + \"20\" (string) = " << concat_str << endl;

    cout << "\n[경고!] 하지만, 숫자와 문자열을 직접 더할 수는 없어! 에러가 난단다!" << endl;
    cout << quiz_master.name << ": 내가 이걸로 초보들을 많이 혼내줬지!" << endl;
    quiz_master.display("happy");
    // string error_example = str1 + num1; // 이 라인은 컴파일 에러를 발생시킬 것이므로 주석 처리
    // cout << error_example << endl;

    // --- 4. 문자열 길이 (String Length) ---
    cout << "\n\n--- 4. 문자열 길이 (String Length) ---" << endl;
    current_guide = all_characters[5]; // 골든 리트리버 '리버'
    cout << current_guide.name << " (" << current_guide.species << "): 이번엔 문자열의 길이를 재어볼 거야!" << endl;
    current_guide.display("thinking");
    cout << "`length()` 함수나 `size()` 함수를 사용하면 문자열에 몇 글자가 있는지 알 수 있어." << endl;

    cout << "\n[실습] \"멍멍 탐험대\" 문자열의 길이를 재어보자." << endl;
    string team_name = "멍멍 탐험대";
    cout << "문자열: \"" << team_name << "\"" << endl;
    cout << "length() 함수로 잰 길이: " << team_name.length() << endl;
    cout << "size() 함수로 잰 길이: " << team_name.size() << endl;
    current_guide.display("happy");

    // --- 5. 문자열 접근 (Access Strings) ---
    cout << "\n\n--- 5. 문자열 접근 (Access Strings) ---" << endl;
    cout << boree.name << ": 특정 글자만 쏙 뽑아낼 수도 있나? 고구마에서 심지를 빼내듯이?" << endl;
    boree.display("thinking");
    
    cout << current_guide.name << ": 물론이지! 대괄호 `[]` 안에 '인덱스 번호'를 넣으면 돼. 제일 첫 글자는 0번부터 시작한단다!" << endl;

    cout << "\n[실습] \"Boree\" 문자열에서 첫 번째 글자와 두 번째 글자를 뽑아보자." << endl;
    string my_string = "Boree";
    cout << "문자열: \"" << my_string << "\"" << endl;
    cout << "첫 번째 글자 (my_string[0]): " << my_string[0] << endl;
    cout << "두 번째 글자 (my_string[1]): " << my_string[1] << endl;
    
    cout << current_guide.name << ": 마지막 글자는 어떻게 뽑을까? 전체 길이에서 1을 빼면 돼!" << endl;
    cout << "마지막 글자 (my_string[my_string.length() - 1]): " << my_string[my_string.length() - 1] << endl;

    cout << current_guide.name << ": `at()` 함수를 써도 똑같이 접근할 수 있어!" << endl;
    cout << "my_string.at(0): " << my_string.at(0) << endl;

    // --- 6. 문자열 글자 변경 (Change String Characters) ---
    cout << "\n\n--- 6. 문자열 글자 변경 (Change String Characters) ---" << endl;
    cout << boree.name << ": 그럼 글자를 바꿀 수도 있어?" << endl;
    boree.display("default");

    cout << current_guide.name << ": 응! 인덱스 번호를 사용해서 원하는 위치의 글자를 새로운 글자로 바꿔줄 수 있어. 이때는 한 글자니까 작은따옴표(`'`)를 써야 해!" << endl;

    cout << "\n[실습] \"Hello\"를 \"Jello\"로 바꿔보자." << endl;
    string change_string = "Hello";
    cout << "변경 전: " << change_string << endl;
    change_string[0] = 'J'; // 첫 번째 글자 변경
    cout << "변경 후 (change_string[0] = 'J'): " << change_string << endl;
    
    cout << current_guide.name << ": `at()` 함수로도 변경 가능해!" << endl;
    change_string = "Mello";
    cout << "다시 변경 전: " << change_string << endl;
    change_string.at(0) = 'H';
    cout << "변경 후 (change_string.at(0) = 'H'): " << change_string << endl;
    current_guide.display("happy");

    // --- 7. 특수 문자 (Special Characters) ---
    cout << "\n\n--- 7. 특수 문자 (Special Characters) ---" << endl;
    current_guide = all_characters[2]; // 허스키 '허허'
    cout << current_guide.name << " (" << current_guide.species << "): 때로는 특별한 기호들을 문자열 안에 넣어야 할 때가 있어. 예를 들면 큰따옴표(\") 안에 또 큰따옴표를 넣을 때!" << endl;
    current_guide.display("thinking");
    cout << "이럴 때는 '이스케이프 문자(`\\`)'를 사용해줘야 해!" << endl;

    cout << "\n[예시] \"Vikings\"를 큰따옴표 안에 넣어보자." << endl;
    string special_txt = "We are the so-called \"Vikings\" from the north.";
    cout << special_txt << endl;

    cout << "\n[예시] 작은따옴표(')와 역슬래시(`\\`)를 넣어보자." << endl;
    string special_txt2 = "It\'s alright. The character \\ is called backslash.";
    cout << special_txt2 << endl;
    current_guide.display("surprised");

    cout << "\n자주 쓰는 이스케이프 문자에는 `\\n` (줄바꿈)과 `\\t` (탭)도 있어!" << endl;
    cout << "안녕하세요.\n저는 " << boree.name << "입니다.\t반가워요!" << endl;
    current_guide.display("happy");

    // --- 8. 사용자 입력 문자열 (User Input Strings) ---
    cout << "\n\n--- 8. 사용자 입력 문자열 (User Input Strings) ---" << endl;
    cout << boree.name << ": 이제 내가 이름을 받아볼까? 자, 네 이름을 입력해봐." << endl;
    boree.display("happy");

    string user_name;
    cout << "당신의 이름은?: ";
    cin >> user_name; // cin으로 한 단어 입력 받기
    cout << boree.name << ": 오! 네 이름은 '" << user_name << "' 이구나!" << endl;
    cout << boree.name << ": 그런데... 만약 이름에 공백이 있으면 어떻게 될까?" << endl;
    boree.display("thinking");

    cout << "\n[주의!] `cin >>` 은 공백을 만나면 입력을 멈춰!" << endl;
    cout << "그래서 'John Doe'라고 입력하면 'John'만 받아진단다." << endl;
    cout << "\n[실습] 이번엔 '풀네임'을 입력해봐. 띄어쓰기 해서 입력해봐!" << endl;
    string full_user_name_cin;
    cout << "당신의 풀네임은?: ";
    // 이전 cin으로 인해 버퍼에 남은 줄바꿈 문자를 제거 (필수)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> full_user_name_cin; // 다시 cin으로 입력 시도
    cout << boree.name << ": 흐음, 'cin >>'으로 받은 풀네임: '" << full_user_name_cin << "' 이군. 예상대로 첫 단어만 나왔어!" << endl;
    boree.display("sad");

    cout << "\n여러 단어를 포함한 한 줄 전체를 입력받으려면 `getline()` 함수를 사용해야 해!" << endl;
    cout << "`getline(cin, 변수이름)` 이렇게 쓰는 거야." << endl;

    cout << "\n[실습] 다시 풀네임을 입력해봐! 이번엔 `getline()`으로 받아줄게!" << endl;
    string full_user_name_getline;
    cout << "당신의 진짜 풀네임은?: ";
    getline(cin, full_user_name_getline); // getline으로 한 줄 입력 받기
    cout << boree.name << ": 완벽해! `getline()`으로 받은 풀네임: '" << full_user_name_getline << "' 이군! 이걸 보니 고구마가 더 먹고 싶어지는군." << endl;
    boree.display("happy");

    // --- 9. C++ 문자열 이름공간 (String Namespace) ---
    cout << "\n\n--- 9. C++ 문자열 이름공간 (String Namespace) ---" << endl;
    quiz_master = all_characters[8]; // 임정찬 'Liki'
    cout << quiz_master.name << " (" << quiz_master.species << "): 저기요! 궁금한 게 있어요!" << endl;
    quiz_master.display("thinking");
    cout << "어떤 코드에서는 `std::string`이라고 쓰고, 어떤 코드에서는 그냥 `string`이라고 쓰던데, 왜 그래요?" << endl;
    
    current_guide = all_characters[9]; // 정규호 '바보'
    cout << current_guide.name << " (" << current_guide.species << "): 아하! 그건 `using namespace std;` 때문이야!" << endl;
    current_guide.display("happy");
    cout << "`using namespace std;`를 쓰면 `std::`를 생략하고 바로 `string`이나 `cout`을 쓸 수 있어." << endl;
    cout << "만약 저 문장을 안 쓰면 `std::string`, `std::cout`처럼 `std::`를 꼭 붙여야 해." << endl;
    cout << "우리는 스터디에서 편리하게 `using namespace std;`를 사용하고 있지만, 실제 큰 프로젝트에서는 명확하게 `std::`를 붙이는 경우가 많아!" << endl;
    quiz_master.display("surprised");
    cout << quiz_master.name << ": 아하! 그렇구나! 감사합니다!" << endl;

    // --- 10. C-스타일 문자열 (C-Style Strings) ---
    cout << "\n\n--- 10. C-스타일 문자열 (C-Style Strings) ---" << endl;
    Character final_master = all_characters[10]; // 싀백 '먀엉'
    cout << final_master.name << " (" << final_master.species << "): 마지막으로, 고대의 지식을 전해주마." << endl;
    final_master.display("thinking");
    cout << "C++의 뿌리인 C 언어에서는 `string` 타입이 없었어. 대신 `char` 타입으로 글자 배열을 만들어서 문자열처럼 사용했지. 그걸 'C-스타일 문자열'이라고 한다." << endl;

    cout << "\n[예시] 일반 string과 C-스타일 string." << endl;
    string greeting1 = "Hello";    // 일반 string
    char greeting2[] = "Hello";    // C-스타일 string (char 배열)
    cout << "일반 string: " << greeting1 << endl;
    cout << "C-스타일 string: " << greeting2 << endl;
    
    cout << final_master.name << ": 현대 C++에서는 `string` 타입이 훨씬 편리하고 안전하니, 특별한 경우가 아니면 `string`을 쓰는 것이 좋다." << endl;
    final_master.display("happy");

    cout << "\n\n축하합니다! 문자열(String)에 대한 모든 학습을 마쳤습니다!" << endl;
    boree.display("happy");
    cout << boree.name << ": 휴... 드디어 끝났군. 고구마 먹으러 가야지!" << endl;

    return 0;
}