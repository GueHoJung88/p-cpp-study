
# 🧠 C++ Symbol Resolution & Python 비교

## 1. `main.cpp`에서 `util::greet` 찾기 과정

```cpp
// main.cpp
#include "util.h"
int main() {
    util::greet("Gyuhon");
}
```

- main.cpp → `#include "util.h"` → 함수 선언 인식
- 컴파일러는 `util::greet()` 사용됨을 인식하고 main.o 생성
- 링커가 `util.cpp`에서 해당 심볼을 찾고 결합 → 실행파일 생성

---

## 2. `main.cpp`에서 `std::cout` 찾기 과정

```cpp
// main.cpp
#include <iostream>
int main() {
    std::cout << "Hello" << std::endl;
}
```

- `#include <iostream>` → `std::cout` 선언 포함
- `std` 네임스페이스 내부에 `cout` 정의됨
- 링커가 C++ 표준 라이브러리(libstdc++)에서 구현체를 자동 연결

---

## 3. Python의 `print()` vs C++의 `std::cout`

| 항목             | C++ (`std::cout`)                            | Python (`print`)       |
|------------------|-----------------------------------------------|------------------------|
| 문법              | `std::cout << "hi" << std::endl;`            | `print("hi")`          |
| 줄바꿈            | `std::endl` 명시 필요                        | 자동 줄바꿈            |
| 표준 스트림 객체  | `std::ostream` 클래스                        | 내장 함수              |
| 포맷팅 방식       | 연산자 오버로딩 (`<<`)                        | 문자열 내부 포맷팅    |
| 네임스페이스 필요 | `std::` 사용                                 | 불필요                 |
| 실행 대상         | 바이너리 (컴파일 결과)                       | 인터프리터에서 직접 실행|

---

## 4. 시각화

🖼 SVG: [verified_cpp_symbol_resolution.svg](../image/verified_cpp_symbol_resolution.svg)

---

## 5. 구성 요약

- `util::greet`는 사용자 정의 네임스페이스 → 헤더 + 구현 `.cpp` 필요
- `std::cout`은 표준 네임스페이스 → `<iostream>`만 포함해도 컴파일 + 자동 링크됨
- Python은 모든 것이 런타임(import + 함수 정의)에서 즉시 처리됨

---

🕓 생성일: 2025-07-15
