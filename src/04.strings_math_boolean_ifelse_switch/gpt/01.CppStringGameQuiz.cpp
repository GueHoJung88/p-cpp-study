// 🧵 Puppy C++ Adventure: Strings편
// 학습 목표: string 타입 선언, 문자열 연결, 길이 측정, 문자 접근, 사용자 입력, C-style string 비교

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Character.h"

using namespace std;

// 🧩 단락별 설명을 저장할 구조체
struct Paragraph {
    string title;
    string content;
};

// 💡 단락별 학습 데이터 구성
vector<Paragraph> buildParagraphs() {
    return {
        {"1. 문자열(string) 타입 소개",
         "C++에서 문자열은 string 타입으로 표현됩니다.\n문자열은 큰따옴표(\" \" )로 둘러싼 글자들의 모음입니다.\n예: string greeting = \"Hello\";\n<string> 헤더를 반드시 포함해야 해요!"},

        {"2. 문자열 연결 (Concatenation)",
         "+ 연산자를 사용하면 두 문자열을 연결할 수 있어요.\n예: string fullName = firstName + \" \" + lastName;\n또는 append() 함수도 사용할 수 있죠!"},

        {"3. 문자열 길이 측정",
         "string.length() 또는 string.size() 를 사용하면 문자열의 길이를 알 수 있어요.\n예: txt.length(); 또는 txt.size();"},

        {"4. 문자열 문자 접근",
         "[] 연산자 또는 at() 함수로 특정 문자에 접근할 수 있어요.\n예: myString[0], myString.at(1)\n문자도 변경할 수 있습니다!\nmyString[0] = 'J';"},

        {"5. 특수 문자와 이스케이프 시퀀스",
         "문자열 안에 \" 따옴표, 줄바꿈 등을 넣으려면 역슬래시(\\)를 사용해야 해요.\n예: \"He said: \\\"Hello\\\"\"\n- \n: 줄바꿈\n- \t: 탭\n- \\\": 따옴표\n- \\\\ : 역슬래시"},

        {"6. 사용자 입력 cin vs getline",
         "cin은 한 단어만 입력 받을 수 있어요.\n여러 단어(문장)를 받으려면 getline(cin, 변수)를 사용하세요!"},

        {"7. 문자열 vs 숫자",
         "문자열끼리 더하면 연결(concatenation), 숫자는 더하면 계산(addition)됩니다.\nstring x = \"10\" + \"20\" -> \"1020\"\nint x = 10 + 20 -> 30\nstring + int 는 에러!"},

        {"8. C-style 문자열 소개",
         "char greeting[] = \"Hello\"; 와 같은 형태를 C-style 문자열이라 해요.\n문자 배열이며, 끝에는 항상 '\\0' null 문자 포함됨.\n복잡한 조작이 필요한 경우 string 클래스를 추천!"},
    };
}

// 🧠 랜덤 퀴즈 생성기
struct Quiz {
    string question;
    vector<string> choices;
    int correctIndex;
    string explanation;
};

vector<Quiz> buildQuizzes() {
    return {
        {"string 타입을 사용하려면 포함해야 하는 헤더는?",
         {"<iostream>", "<string>", "<cstring>", "<stdio.h>"},
         1, "<string> 헤더를 포함해야 string 객체를 사용할 수 있어요."},

        {"다음 중 문자열 연결 결과가 'John Doe'가 되는 것은?",
         {"firstName + lastName", "firstName + \"Doe\"", "firstName + ' ' + lastName", "firstName + \" \" + lastName"},
         3, "문자열 사이에 공백을 넣기 위해 \" \" 를 추가해야 해요."},

        {"문자열의 길이를 구하는 함수는?",
         {"length()", "size()", "count()", "둘 다 맞음"},
         3, "length()와 size()는 같은 기능을 합니다!"},

        {"myString[0] = 'A'; 는 어떤 연산인가요?",
         {"문자열 변경", "문자 접근", "문자 삭제", "에러 발생"},
         0, "[] 연산자로 특정 문자를 변경할 수 있어요."},

        {"getline(cin, s)를 사용하는 이유는?",
         {"한 글자씩 입력 받기", "엔터 포함 전체 문장을 입력받기", "숫자만 입력 받기", "에러 방지용"},
         1, "getline은 공백 포함 전체 한 줄을 입력받을 수 있어요."},

        {"C++에서 '특수문자'를 문자열에 포함하려면 어떻게 해야 하나요?",
         {"바로 작성한다", "작은 따옴표로 감싼다", "이스케이프 문자(\\)를 사용한다", "가능하지 않다"},
         2, "예: \"He said: \\\"Hi\\\"\" 처럼 \\\" 를 삽입하려면 \\\" 를 사용해야 해요."},

        {"다음 중 C-style 문자열은?",
         {"string s = \"Hi\";", "char s[] = \"Hi\";", "string s(\"Hi\");", "s = \"Hi\";"},
         1, "char 배열로 만든 문자열은 C-style string입니다."},

        {"문자열 'abc'의 마지막 문자는?",
         {"a", "b", "c", "오류 발생"},
         2, "문자열 인덱스는 0부터 시작하므로, [2]가 마지막 문자 'c'에 해당해요."},

        {"다음 중 string s = \"Hello\"; 에서 s.at(0)의 결과는?",
         {"H", "e", "오류", "공백"},
         0, "at(0)은 첫 번째 문자인 'H'를 반환합니다."},

        {"문자열 + 숫자를 더하면 어떻게 되나요?",
         {"연결된다", "에러 발생", "숫자로 변환된다", "0이 된다"},
         1, "string과 int를 직접 더하면 타입 불일치로 에러가 발생합니다."}
    };
}

// 🎮 메인
int main() {
    srand(time(0));

    vector<Character> characters = initializeCharacters();
    Character player = characters[rand() % characters.size()];
    cout << "\n🐶 오늘의 가이드: " << player.name << " (" << player.species << ") 등장!" << endl;
    player.display("happy");

    cout << "\n📘 C++ 문자열 학습 여정에 오신 걸 환영합니다!\nEnter 키를 눌러 한 단락씩 읽어나가요.\n\n";
    cin.ignore();

    vector<Paragraph> paragraphs = buildParagraphs();
    for (const auto& para : paragraphs) {
        cout << "\n=== " << para.title << " ===\n";
        cout << para.content << endl;
        cout << "\n👉 다음으로 넘어가려면 Enter...";
        cin.ignore();
    }

    cout << "\n🎲 지금부터 랜덤 퀴즈 10문제를 풀어보세요!\n" << endl;
    vector<Quiz> all_quiz = buildQuizzes();
    random_shuffle(all_quiz.begin(), all_quiz.end());
    int score = 0;

    for (int i = 0; i < 10; ++i) {
        Quiz& q = all_quiz[i];
        cout << "\nQ" << i + 1 << ") " << q.question << endl;
        for (int j = 0; j < q.choices.size(); ++j) {
            cout << "  " << j + 1 << ". " << q.choices[j] << endl;
        }
        cout << "답 입력: ";
        int ans;
        cin >> ans;

        if (ans - 1 == q.correctIndex) {
            cout << "\n✅ 정답이에요!" << endl;
            player.display("happy");
            score++;
        } else {
            cout << "\n❌ 오답!" << endl;
            player.display("sad");
        }
        cout << "📝 해설: " << q.explanation << endl;
    }

    cout << "\n📊 최종 점수: " << score << " / 10" << endl;
    if (score >= 8) {
        cout << "\n🎉 훌륭해요! 문자열 마스터!" << endl;
        player.display("surprised");
    } else if (score >= 5) {
        cout << "\n👏 괜찮아요! 조금만 더 연습해요!" << endl;
        player.display("thinking");
    } else {
        cout << "\n😿 아쉬워요. 다음엔 더 잘할 수 있어요!" << endl;
        player.display("angry");
    }

    cout << "\n🐶 " << player.name << "와(과) 함께한 문자열 여행 끝! 수고했어요~\n";
    return 0;
}
