#include <iostream>
#include <string>
#include <limits> // cin.ignore()를 위해 필요해요

using namespace std;

// 캐릭터 아트 함수 (재사용)
void displayCorgi(string mood) {
    if (mood == "happy") {
        cout << R"(
 (❍ᴥ❍)
 /⌒🍑⌒\
  ￣|￣|   "헤헤, 잘했어!"
        )" << endl;
    } else {
        cout << R"(
 (；ᴥ；)
 /⌒⌒\
  ￣|￣|   "음... 다시 생각해볼까?"
        )" << endl;
    }
}

void displayRabbit() {
     cout << R"(
 (\(\ 
 (•︵•)
 o( o )o "정답이 뭘까..."
     )" << endl;
}


int main() {
    // ===== 1, 2단계 복습: 변수와 사용자 입력 =====
    string player_name;
    int main_character_choice;

    cout << "플레이어의 이름은 무엇인가요?: ";
    cin >> player_name;

    cout << "\n좋아요, " << player_name << "님! 메인 캐릭터를 선택해주세요 (1.코기, 2.토끼): ";
    cin >> main_character_choice;

    string main_character_name = (main_character_choice == 1) ? "웰시코기" : "토끼";
    int player_hp = 100;

    cout << "\n" << main_character_name << "와(과) 함께 데이터 타입의 숲을 탐험합니다!" << endl;
    cout << "현재 " << player_name << "의 체력: " << player_hp << endl << endl;

    // ===== 3. 데이터형 (Data Types) 학습 퀴즈 =====
    // 데이터 타입은 변수가 저장할 정보의 종류와 크기를 지정해요.
    
    cout << "숲 저편에서 퀴즈의 달인, '똑똑이 리트리버'가 나타났다!" << endl;
    cout << R"(
 (•ᴥ•)
 ( | | )  "안녕! 데이터 타입에 대해 얼마나 아는지 볼까?"
    )" << endl;

    // --- Numeric Types 퀴즈 ---
    cout << "\n[퀴즈 1] 내 나이는 3살이야. 내 나이를 저장하기에 가장 기본적인 데이터 타입은 뭘까?" << endl;
    cout << "1. int   2. double   3. string" << endl;
    cout << "정답 (숫자): ";
    int answer1;
    cin >> answer1;

    if (answer1 == 1) {
        cout << "\n정답! 'int'는 정수를 저장하는데 딱이지!" << endl;
        displayCorgi("happy");
    } else {
        cout << "\n땡! 아쉽네. 정수에는 'int'를 사용해. 체력이 10 깎였다!" << endl;
        player_hp = player_hp - 10;
        displayCorgi("sad");
        cout << "현재 체력: " << player_hp << endl;
    }
    
    // --- Boolean & Character Types 퀴즈 ---
    cout << "\n[퀴즈 2] 지금 내가 행복한지(true) 아닌지(false)를 저장하고 싶어. 어떤 타입을 써야할까?" << endl;
    cout << "1. string   2. char   3. bool" << endl;
    cout << "정답 (숫자): ";
    int answer2;
    cin >> answer2;

    if (answer2 == 3) {
        cout << "\n맞았어! 'bool'은 참/거짓을 표현하는 최고의 방법이야!" << endl;
        displayCorgi("happy");
    } else {
        cout << "\n아까비! 'bool'이 정답이야. 체력이 또 10 깎였다!" << endl;
        player_hp = player_hp - 10;
        displayCorgi("sad");
        cout << "현재 체력: " << player_hp << endl;
    }

    // --- String Type 퀴즈 ---
    // cin 다음에 getline을 쓸 때 발생하는 문제를 방지하기 위한 코드.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "\n[퀴즈 3] 'string' 타입을 사용하려면 소스 코드 맨 위에 뭘 추가해야 할까? (#include <...>) " << endl;
    cout << "정답 (힌트: ____): ";
    string answer3;
    getline(cin, answer3); // 공백 포함 입력을 받기 위해 getline 사용

    if (answer3 == "string") {
        cout << "\n대단해! #include <string> 라이브러리를 포함해야 쓸 수 있지!" << endl;
        displayCorgi("happy");
    } else {
        cout << "\n거의 다 왔는데! 정답은 'string'이야. 체력이 10 깎였다!" << endl;
        player_hp = player_hp - 10;
        displayCorgi("sad");
        cout << "현재 체력: " << player_hp << endl;
    }
    
    cout << "\n퀴즈의 숲 탐험 완료! 수고했어, " << player_name << "!" << endl;
    
    return 0;
}