#include <iostream>
#include <string>

// C++ 스터디를 더욱 재미있게 만들어 줄 우리의 친구들을 소개합니다!
// namespace를 사용하면 std::cout 대신 cout처럼 코드를 짧게 쓸 수 있어요.
using namespace std;

int main() {
    // ===== 1. 변수 (Variables) 학습 =====
    // 변수는 데이터를 저장하는 상자(컨테이너)와 같아요.

    // --- Declaring (Creating) Variables ---
    // C++에서는 변수를 만들기 전에 어떤 종류의 데이터를 담을지 '타입'을 정해줘야 해요.
    // 형식: type variableName = value;

    cout << "---------- 멍멍 탐험대 캐릭터 소개! ----------" << endl << endl;

    // ** 치와와 캐릭터 정보 **
    // string: "Hello World" 와 같은 문자열(텍스트)을 저장합니다.
    string chihuahua_name = "치와와";
    // int: 123이나 -123과 같은 정수(소수점 없는 숫자)를 저장합니다.
    int chihuahua_hp = 80;
    // double: 19.99처럼 소수점이 있는 숫자를 저장합니다.
    double chihuahua_cute_rate = 98.5;
    // char: 'a'나 'B'처럼 단 하나의 글자를 저장합니다. 작은따옴표로 감싸요.
    char chihuahua_rank = 'A';
    // bool: 참(true) 또는 거짓(false) 두 가지 상태만 저장합니다.
    bool chihuahua_is_tiny = true;

    cout << "### " << chihuahua_name << " ###" << endl;
    cout << R"(
 (\_/)
 (•ᴥ•)
 / >🍖
    )" << endl;
    // --- Display Variables ---
    // cout과 << 연산자를 사용해 변수에 저장된 값을 화면에 출력할 수 있어요.
    cout << "이름: " << chihuahua_name << endl;
    cout << "체력: " << chihuahua_hp << endl;
    cout << "귀여움 지수: " << chihuahua_cute_rate << "%" << endl;
    cout << "위험 등급: " << chihuahua_rank << endl;
    cout << "소형견인가요? (1=true, 0=false): " << chihuahua_is_tiny << endl << endl;

    // ** 웰시코기 캐릭터 정보 **
    // 한 번에 여러 변수를 선언할 수도 있어요.
    string corgi_name = "웰시코기", corgi_specialty = "식빵 굽기";
    int corgi_hp = 120, corgi_leg_length = 5; // 짧은 다리...

    cout << "### " << corgi_name << " ###" << endl;
    cout << R"(
 (❍ᴥ❍)
 /⌒🍑⌒\
  ￣|￣|
    )" << endl;
    cout << "이름: " << corgi_name << endl;
    cout << "체력: " << corgi_hp << endl;
    // --- Add Variables Together ---
    // + 연산자로 변수와 변수, 변수와 값을 더할 수 있습니다.
    cout << "특기: " << corgi_specialty + " & 엉덩이 흔들기" << endl;
    cout << "다리 길이(cm): " << corgi_leg_length << " (ㅠㅠ)" << endl << endl;


    // ** 시베리안 허스키 캐릭터 정보 **
    string husky_name = "허스키";
    int husky_hp = 200;

    cout << "### " << husky_name << " ###" << endl;
    cout << R"(
  /^ ^\
 ( ᴥᴥ )
  |U U|
    )" << endl;
    cout << "이름: " << husky_name << endl;
    cout << "체력: " << husky_hp << endl;


    // --- Constants ---
    // const 키워드를 사용하면 변수를 '상수'로 만들 수 있어요.
    // 상수는 절대 바꿀 수 없는 값이 됩니다. (read-only)
    const int MAX_HP = 200;
    // husky_hp = 210; // 허스키의 체력은 최대 체력을 넘을 수 없어요.
    // MAX_HP = 210; // 에러 발생! const로 선언된 변수는 값을 바꿀 수 없습니다.
    cout << "이 게임의 최대 체력은 " << MAX_HP << "입니다." << endl << endl;
    
    return 0;
}