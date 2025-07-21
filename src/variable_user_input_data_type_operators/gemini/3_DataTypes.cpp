#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Character.h"

using namespace std;

int main() {
    // ===== 1, 2단계 복습 =====
    vector<Character> characters = initializeCharacters();
    Character player_character = characters[1]; // 웰시코기를 플레이어로 가정
    Character quiz_master = characters[5];      // 골든 리트리버를 퀴즈 마스터로

    cout << "플레이어 '" << player_character.name << "'이(가) '" << quiz_master.name << "'를 만났다!" << endl;
    player_character.display();
    quiz_master.display("thinking");
    cout << quiz_master.name << ": 데이터 타입에 대해 얼마나 아는지 퀴즈를 내보겠다!" << endl;
    
    // ===== 3. 데이터형 (Data Types) 학습 퀴즈 =====
    int player_hp = player_character.hp;
    
    // --- 퀴즈 1: int vs double ---
    cout << "\n[퀴즈 1] 내 재산은 " << quiz_master.assets << "뼈다귀야. 이처럼 큰 정수를 저장하려면 'int'보다 더 큰 범위를 가진 데이터 타입이 좋아. 뭘까?" << endl;
    cout << "1. float   2. long long   3. char" << endl;
    int answer1;
    cin >> answer1;

    if (answer1 == 2) {
        cout << "\n정답! 'long long'은 아주 큰 정수도 거뜬히 저장하지!" << endl;
        player_character.display("happy");
        quiz_master.display("surprised");
    } else {
        cout << "\n아쉽네. 정답은 'long long'이야. 자존심에 상처를 입었다! (HP -10)" << endl;
        player_hp -= 10;
        player_character.display("sad");
        cout << "현재 체력: " << player_hp << endl;
    }

    // --- 퀴즈 2: bool ---
    bool is_master_smart = true; // bool 타입 변수
    cout << "\n[퀴즈 2] 내가 똑똑하다는 사실(" << is_master_smart << ")은 참(true)이야. 이렇게 참/거짓을 저장하는 데이터 타입은?" << endl;
    cout << "1. boolean  2. string  3. bool" << endl;
    int answer2;
    cin >> answer2;

    if (answer2 == 3) {
        cout << "\n딩동댕! 'bool'이 정답이야!" << endl;
        player_character.display("happy");
    } else {
        cout << "\n땡! C++에서는 'bool'이라고 해. (HP -10)" << endl;
        player_hp -= 10;
        player_character.display("sad");
        quiz_master.display("angry");
        cout << "현재 체력: " << player_hp << endl;
    }

    cout << "\n데이터 타입 퀴즈를 마쳤습니다! 수고했어!" << endl;
    return 0;
}