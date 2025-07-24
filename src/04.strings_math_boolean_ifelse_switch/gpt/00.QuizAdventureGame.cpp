// 00.QuizAdventureGame.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "json.hpp"
#include "Character.h"

using json = nlohmann::json;
using namespace std;

struct Quiz {
    string type;
    string category;
    string question;
    vector<string> choices;
    string answer;
};

vector<Quiz> loadQuizFromJson(const string& filename) {
    vector<Quiz> quizList;
    ifstream file(filename);
    json data;
    file >> data;
    for (auto& item : data) {
        Quiz q;
        q.type = item["type"];
        q.category = item["category"];
        q.question = item["question"];
        q.choices = item["choices"].get<vector<string>>();
        q.answer = item["answer"];
        quizList.push_back(q);
    }
    return quizList;
}

vector<Quiz> selectRandomQuiz(const vector<Quiz>& all, const vector<string>& categories, int count) {
    vector<Quiz> selected;
    vector<Quiz> filtered;
    for (auto& q : all) {
        if (find(categories.begin(), categories.end(), q.category) != categories.end()) {
            filtered.push_back(q);
        }
    }
    random_shuffle(filtered.begin(), filtered.end());
    for (int i = 0; i < min(count, (int)filtered.size()); ++i) {
        selected.push_back(filtered[i]);
    }
    return selected;
}

int main() {
    srand((unsigned)time(0));
    vector<Character> characters = Character::getDefaultCharacters();

    cout << "🧸 퀴즈 어드벤처에 함께할 캐릭터를 고르세요!\n";
    for (int i = 0; i < characters.size(); ++i) {
        cout << i << ". " << characters[i].name << " (" << characters[i].species << ")\n";
    }
    cout << ">> 캐릭터 번호: ";
    int sel; cin >> sel;
    Character player = characters[sel];

    cout << "기본 성격을 사용할까요? (y/n): ";
    char useDefault; cin >> useDefault;
    if (useDefault == 'y') {
        player.applyDefaults();
    } else {
        cout << "나이를 입력하세요: "; cin >> player.age;
        cout << "출신지를 입력하세요: "; cin >> player.hometown;
        cout << "장래희망은 무엇인가요?: "; cin.ignore(); getline(cin, player.future_hope);
    }

    player.react("happy");
    player.showProfile();

    vector<Quiz> allQuiz = loadQuizFromJson("cpp_quiz_pretest_bank.json");

    cout << "\n📚 문제를 풀고 싶은 학습 범위를 선택하세요 (띄어쓰기로 구분된 키워드)\n";
    cout << "예: syntax input datatype\n>> 범위 입력: ";
    vector<string> categories;
    string input;
    while (cin >> input) {
        categories.push_back(input);
        if (cin.peek() == '\n') break;
    }

    cout << ">> 각 범위에서 몇 문제를 풀고 싶나요? (총 문제 수): ";
    int count; cin >> count;
    vector<Quiz> selectedQuiz = selectRandomQuiz(allQuiz, categories, count);

    int score = 0;
    for (int i = 0; i < selectedQuiz.size(); ++i) {
        Quiz& q = selectedQuiz[i];
        cout << "\n🌟 [퀴즈 " << i + 1 << "/" << selectedQuiz.size() << "] 분야: " << q.category << "\n";
        player.react("thinking");
        cout << "💬 " << q.question << "\n";

        if (q.type == "multiple") {
            for (int j = 0; j < q.choices.size(); ++j) {
                cout << j + 1 << ". " << q.choices[j] << "\n";
            }
            int ans;
            cout << "👉 번호 입력: "; cin >> ans;
            if (q.choices[ans - 1] == q.answer) {
                cout << "🎉 정답입니다!\n";
                player.react("happy");
                score++;
            } else {
                cout << "💥 오답! 정답은: " << q.answer << "\n";
                player.react("sad");
            }
        } else {
            cout << "👉 주관식 정답 입력: ";
            cin.ignore(); string answerText; getline(cin, answerText);
            if (answerText == q.answer) {
                cout << "🎉 정답입니다!\n";
                player.react("happy");
                score++;
            } else {
                cout << "💥 오답! 정답은: " << q.answer << "\n";
                player.react("sad");
            }
        }
    }

    cout << "\n🎯 총점: " << score << " / " << selectedQuiz.size() << "\n";
    player.react(score >= selectedQuiz.size() * 0.7 ? "happy" : "sad");

    return 0;
}