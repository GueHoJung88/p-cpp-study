// Cpp_QuizBattle_Game_Full.cpp (퀴즈 표시 오류 수정 포함)
// 완전판: 100문제 + 학습 리포트 분석 + 귀여운 상호작용 + 체력/패널티 시스템 포함

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "json.hpp"
#include "Character.h"

using namespace std;
using json = nlohmann::json;

struct Quiz
{
    string category;
    string question;
    string type;            // multiple / subjective
    vector<string> options; // 객관식 보기
    string answer;
    string explanation;
};

vector<Quiz> loadQuizzesFromJson(const string &filename)
{
    vector<Quiz> quizzes;
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "퀴즈 파일을 열 수 없습니다." << endl;
        return quizzes;
    }
    json j;
    infile >> j;
    for (auto &item : j)
    {
        Quiz q;
        q.category = item["category"];
        q.question = item["question"];
        q.type = item["type"];
        if (q.type == "multiple")
        {
            q.options = item["options"].get<vector<string>>();
        }

        // ✅ 안전하게 answer 처리
        if (item["answer"].is_string())
        {
            q.answer = item["answer"];
        }
        else if (item["answer"].is_object() && item["answer"].contains("expected"))
        {
            q.answer = item["answer"]["expected"];
        }
        else
        {
            q.answer = "";
        }

        q.explanation = item["explanation"];
        quizzes.push_back(q);
    }

    return quizzes;
}

void analyzeResult(map<string, int> &stats, int totalCorrect)
{
    cout << "\n📊 [학습 영역별 정답 개수]" << endl;
    for (auto &p : stats)
    {
        cout << " - " << p.first << " : " << p.second << " 개" << endl;
    }
    if (totalCorrect == 10)
        cout << "🎓 완벽 학습자! 너무 멋져요!" << endl;
    else if (totalCorrect >= 7)
        cout << "💡 거의 다 왔어요! 부족한 부분 복습!" << endl;
    else
        cout << "📘 기초부터 다시 정리해봐요!" << endl;
}

void startQuizBattle(Character &player, const vector<Quiz> &quizzes)
{
    srand(static_cast<unsigned int>(time(0)));
    vector<Quiz> shuffled = quizzes;
    random_shuffle(shuffled.begin(), shuffled.end());

    map<string, int> correctByCategory;
    int correct = 0, wrong = 0;
    int total = 10;
    time_t startTime = time(0);

    cout << "\n🎮 퀴즈 배틀 시작!" << endl;

    for (int i = 0; i < total; ++i)
    {
        Quiz q = shuffled[i];
        cout << "\n🌟 [퀴즈 " << (i + 1) << "/" << total << "] 분야: " << q.category << endl;
        player.display("thinking");
        cout << "💬 문제: " << q.question << endl; // 🔥 여기에 문제 텍스트 표시

        string userAnswer;
        if (q.type == "multiple")
        {
            for (int j = 0; j < q.options.size(); ++j)
            {
                cout << "  " << j + 1 << ". " << q.options[j] << endl;
            }
            cout << "👉 보기 번호 입력: ";
            int select;
            cin >> select;
            cin.ignore();
            if (select >= 1 && select <= q.options.size())
                userAnswer = q.options[select - 1];
        }
        else
        {
            cout << "👉 주관식 정답 입력: ";
            getline(cin, userAnswer);
        }

        if (userAnswer == q.answer)
        {
            cout << "✨ 정답!" << endl;
            player.display("happy");
            correctByCategory[q.category]++;
            ++correct;
        }
        else
        {
            cout << "💥 오답! 정답은 '" << q.answer << "' 입니다." << endl;
            player.display("angry");
            cout << "💡 해설: " << q.explanation << endl;
            player.hp -= 10;
            ++wrong;
            if (player.hp <= 0)
            {
                cout << "\n💀 기절! 체력이 모두 닳았어요." << endl;
                return;
            }
        }
    }

    time_t endTime = time(0);
    int timeTaken = static_cast<int>(endTime - startTime);
    cout << "\n🏁 퀴즈 완료!" << endl;
    cout << "✔ 정답: " << correct << "/" << total << endl;
    cout << "🕓 시간: " << timeTaken << " 초" << endl;

    analyzeResult(correctByCategory, correct);
}

int main()
{
    vector<Character> characters = initializeCharacters();
    cout << "🧸 퀴즈 모험에 함께할 캐릭터를 선택하세요!\n";
    for (int i = 0; i < characters.size(); ++i)
        cout << i << ". " << characters[i].name << " (" << characters[i].species << ")\n";
    int select;
    cin >> select;
    cin.ignore();
    Character player = characters[select];
    player.display("happy");

    string quizFile = "cpp_quiz_fullset_100.json";
    vector<Quiz> allQuizzes = loadQuizzesFromJson(quizFile);

    while (true)
    {
        startQuizBattle(player, allQuizzes);
        if (player.hp <= 0)
            break;
        cout << "\n💫 다시 도전하시겠어요? (yes/no): ";
        string retry;
        getline(cin, retry);
        if (retry != "yes")
            break;
        player.hp = 50;
    }
    cout << "\n👋 수고했어요!" << endl;
    return 0;
}
