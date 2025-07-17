// =====================================
// 🎯 연습 미션 1: 줄바꿈을 추가해보세요!
// 현재는 두 문장이 한 줄에 출력됩니다.
// 아래 두 줄을 수정해서 출력 결과가 두 줄로 나오게 해보세요:
//
// cout << "Hello World!";
// cout << "Have a good day!";
//
// 🔁 수정 예시:
// cout << "Hello World!" << endl;
// cout << "Have a good day!" << endl;
//
// 또는 '\n' 문자를 사용해서도 줄바꿈을 할 수 있습니다.
// =====================================

#include <iostream>  // 표준 입출력 라이브러리 포함: cout 사용 가능
using namespace std; // std:: 없이 cout, endl 등을 바로 사용할 수 있게 해줌

int main() {  // 프로그램의 진입점: main 함수의 실행이 프로그램 시작을 의미함

    // 첫 번째 출력 문장: 화면에 "Hello World!" 출력
    cout << "Hello World!";

    // 두 번째 출력 문장: 이어서 "Have a good day!" 출력
    cout << "Have a good day!";

    // return 문: 프로그램이 정상적으로 종료되었음을 운영체제에 알림
    return 0;
}
