#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Character.h" // 모든 정보가 담긴 헤더

using namespace std;

int main() {
    srand(time(0)); // 랜덤 시드 초기화

    // --- 캐릭터 초기화 및 커스터마이징 ---
    vector<Character> all_characters = initializeCharacters();
    
    // NPC들에게 랜덤 별명 부여 (재미 요소)
    vector<string> nicknames = {"솜뭉치", "댕댕이", "먹보", "잠꾸러기", "똑똑이"};
    for (int i = 0; i < all_characters.size(); ++i) {
        all_characters[i].name = nicknames[rand() % nicknames.size()] + " " + all_characters[i].species;
    }

    cout << "---------- 최종 관문: 지식의 탑 ----------" << endl;
    cout << "도전할 당신의 파트너를 선택하세요!" << endl;
    for (int i = 0; i < all_characters.size(); ++i) {
        cout << i + 1 << ". " << all_characters[i].species << endl;
    }
    int player_choice_idx;
    cin >> player_choice_idx;
    player_choice_idx--;

    Character player_character = all_characters[player_choice_idx];
    all_characters.erase(all_characters.begin() + player_choice_idx);

    // --- 사용자 커스터마이징 ---
    cout << "\n파트너의 프로필을 직접 설정하시겠습니까? (y/n): ";
    char custom_choice;
    cin >> custom_choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (custom_choice == 'y' || custom_choice == 'Y') {
        cout << "파트너의 진짜 이름은?: ";
        getline(cin, player_character.name);
        cout << player_character.name << "의 장래희망은?: ";
        getline(cin, player_character.future_hope);
    }
    
    cout << "\n좋아! " << player_character.name << "와(과) 함께 지식의 탑으로!" << endl;
    player_character.showProfile();


    // --- 통합 미니 게임 시작 (3 라운드) ---
    for (int round = 1; round <= 3; ++round) {
        cout << "\n========== " << round << "층 도전! ==========" << endl;
        if (player_character.hp <= 0) {
            cout << "체력이 0이 되어 도전이 종료됩니다..." << endl;
            break;
        }

        Character& quiz_master = all_characters[rand() % all_characters.size()];
        cout << "\n" << round << "층의 수호자 '" << quiz_master.name << "'이(가) 나타났다!" << endl;
        quiz_master.display("thinking");
        
        cout << "[퀴즈] C++에서 '한 줄 주석'을 작성할 때 사용하는 기호는 무엇일까?" << endl;
        cout << "1. /* 2. //   3. #" << endl;
        int answer;
        cin >> answer;

        if (answer == 2) {
            cout << "\n정답! 기본기가 탄탄하군!" << endl;
            player_character.display("happy");
            quiz_master.display("surprised");
            player_character.assets += 50; // 재산 증가
            cout << "보상으로 50 뼈다귀를 얻었다! (현재 재산: " << player_character.assets << ")" << endl;
        } else {
            cout << "\n오답! 정답은 '//' 야! (HP -30)" << endl;
            player_character.display("sad");
            quiz_master.display("angry");
            player_character.hp -= 30;
        }
        cout << "현재 " << player_character.name << "의 HP: " << player_character.hp << endl;
    }

    // --- 최종 결과 ---
    cout << "\n========== 도전 종료 ==========" << endl;
    if (player_character.hp > 0) {
        cout << "축하합니다! " << player_character.name << "는(은) 지식의 탑 꼭대기에 도달했습니다!" << endl;
        player_character.display("happy");
    } else {
        player_character.display("sad");
        cout << "아쉽지만, " << player_character.name << "는(은) 쓰러지고 말았습니다. 다음 기회에 다시 도전해요!" << endl;
    }
    cout << "\nC++ 스터디 기본 과정이 모두 끝났습니다. 정말 수고 많으셨습니다!" << endl;

    return 0;
}