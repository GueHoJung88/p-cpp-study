#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Character.h"

using namespace std;

int main() {
    // ===== 1단계 복습: 클래스와 객체 =====
    vector<Character> all_characters = initializeCharacters();
    
    // ===== 2. 사용자 입력 (User Input) 심화 - 캐릭터 커스터마이징 =====
    cout << "---------- 멍멍 탐험대 파트너 선택 ----------" << endl;
    for (int i = 0; i < all_characters.size(); ++i) {
        cout << i + 1 << ". " << all_characters[i].species << endl;
    }
    
    cout << "\n함께할 파트너의 번호를 선택하세요: ";
    int choice_idx;
    cin >> choice_idx;
    choice_idx--; // 배열 인덱스는 0부터 시작하므로 1을 빼줍니다.

    // 선택한 캐릭터 객체를 player_character 변수에 복사
    Character player_character = all_characters[choice_idx];

    cout << "\n당신은 '" << player_character.species << "'을(를) 선택했습니다!" << endl;
    player_character.display("happy");

    // --- 캐릭터 특성 직접 설정 기회 제공 ---
    cout << player_character.name << "의 프로필을 직접 설정하시겠습니까? (y/n): ";
    char custom_choice;
    cin >> custom_choice;

    // cin으로 char나 int를 받은 후 string을 받을 땐 버퍼를 비워주는 것이 안전해요.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    if (custom_choice == 'y' || custom_choice == 'Y') {
        cout << "\n--- 나만의 파트너 만들기 ---" << endl;
        cout << "새로운 이름을 지어주세요: ";
        getline(cin, player_character.name);
        
        cout << player_character.name << "의 성별은?: ";
        getline(cin, player_character.gender);

        cout << player_character.name << "의 장래희망은?: ";
        getline(cin, player_character.future_hope);

        cout << "좋아요! 멋진 파트너가 탄생했어요!" << endl;
    } else {
        cout << "기본 설정으로 진행합니다!" << endl;
    }

    // --- 최종 프로필 확인 ---
    cout << "\n<<< 최종 파트너 프로필 >>>" << endl;
    player_character.display();
    player_character.showProfile();

    cout << player_character.name << "와(과) 함께 C++ 탐험을 시작합니다!" << endl;

    return 0;
}