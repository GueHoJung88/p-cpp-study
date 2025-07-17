#include <iostream>  // (1) 입출력 라이브러리 포함. cout, cin 등을 사용 가능하게 해줌.

using namespace std; // (2) std 네임스페이스를 기본으로 사용하겠다는 선언.
                     // cout, cin 등을 std:: 없이 사용할 수 있게 됨.

int main() {         // (4) C++ 프로그램의 시작점인 메인 함수 정의.
                     // 이 중괄호 내부의 코드가 실행됨.

  cout << "Hello World!"; // (5) 콘솔에 "Hello World!" 문자열을 출력함.
                          // cout: 출력 객체, <<: 삽입 연산자 (insertion operator)

  return 0;         // (6) 프로그램 정상 종료를 의미. 운영체제에 0을 반환함.
}                   // (7) main 함수 종료를 나타내는 중괄호
