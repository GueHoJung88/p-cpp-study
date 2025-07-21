#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using namespace std;

int main() {
    // ===== 이전 단계 복습 =====
    vector<Character> characters = initializeCharacters();
    Character player = characters[2]; // 허스키를 플레이어로
    Character quiz_master = characters[7]; // 불독을 퀴즈 마스터로

    cout << player.name << "가 연산자 동굴에서 " << quiz_master.name << "을 만났다." << endl;
    player.display();
    quiz_master.display("angry");
    
    // ===== 4. 연산자 (Operators) 학습 퀴즈 =====
    
    // --- 퀴즈 1: 산술 연산자 (Arithmetic) ---
    int items1 = 10, items2 = 3;
    cout << "\n[퀴즈 1] 내가 가진 뼈다귀 " << items1 << "개를 " << items2 << "마리의 강아지에게 똑같이 나눠주면, 몇 개가 남을까? (힌트: 나머지 연산자 %)" << endl;
    int answer1;
    cin >> answer1;
    
    if (answer1 == items1 % items2) {
        cout << "\n정답! 나머지(%) 연산자를 잘 아는군! 똑똑해서 체력 +10 회복!" << endl;
        player.hp += 10; // += 할당 연산자
        player.display("happy");
    } else {
        cout << "\n땡! 정답은 " << items1 % items2 << "개다! (HP -20)" << endl;
        player.hp -= 20;
        player.display("sad");
    }
    cout << player.name << "의 현재 HP: " << player.hp << endl;

    // --- 퀴즈 2: 비교, 논리 연산자 (Comparison, Logical) ---
    cout << "\n[퀴즈 2] 내 공격력(" << quiz_master.power << ")이 네 체력(" << player.hp << ")보다 높고(AND), 내가 너보다 나이(" << quiz_master.age << ")가 많다(" << player.age << "살)는 말은 참(1)일까 거짓(0)일까?" << endl;
    bool answer2;
    cin >> answer2;

    bool real_answer = (quiz_master.power > player.hp) && (quiz_master.age > player.age);
    if (answer2 == real_answer) {
        cout << "\n정답! 논리적 사고력이 뛰어나군!" << endl;
        player.display("happy");
        quiz_master.display("surprised");
    } else {
        cout << "\n아쉽군. &&(AND) 연산자는 둘 다 참일 때만 참이야. (HP -20)" << endl;
        player.hp -= 20;
        player.display("sad");
    }
    cout << player.name << "의 현재 HP: " << player.hp << endl;

    cout << "\n연산자 동굴을 무사히 통과했다!" << endl;
    return 0;
}