# 📘 C++ 학습 정리 자료 (Python과의 비교 및 핵심 문법)

📅 날짜: 2025-07-29


---

## 🧠 C++ vs Python 철학

- **Python**: 간결함, 생산성, 가독성을 중시하는 고수준 인터프리터 언어  
- **C++**: 성능과 메모리 제어, 컴파일 기반 저수준 제어 중심의 언어  
→ 두 언어는 철학이 다르므로 학습 방식도 달라야 합니다.

---

## 1. 🔁 반복문 (for, while, do/while)

### ✅ 기본 구조 요약

```cpp
// for 루프
for (int i = 0; i < 5; i++) {
    std::cout << i << "\n";
}

// while 루프
int i = 0;
while (i < 5) {
    std::cout << i << "\n";
    i++;
}

// do/while 루프
int i = 10;
do {
    std::cout << i << "\n";
    i++;
} while (i < 5);
```

### ✅ while 루프 실전 예제

```cpp
int countdown = 3;
while (countdown > 0) {
  std::cout << countdown << "\n";
  countdown--;
}
std::cout << "Happy New Year!!\n";
```

### ✅ do/while 루프 사용자 입력 예시

```cpp
int number;
do {
  std::cout << "Enter a positive number: ";
  std::cin >> number;
} while (number > 0);
```

---

## 2. 📦 배열 Arrays (1D, 2D)

### ✅ 기본 선언 및 접근

```cpp
std::string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
std::cout << cars[0];  // Volvo
cars[0] = "Opel";      // 값 변경
```

### ✅ 배열 순회

```cpp
for (int i = 0; i < 4; i++) {
    std::cout << cars[i] << "\n";
}
for (std::string car : cars) {
    std::cout << car << "\n";
}
```

### ✅ 배열 크기 구하기

```cpp
int myNumbers[5] = {10, 20, 30, 40, 50};
int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
```

### ✅ 다차원 배열

```cpp
std::string letters[2][4] = {
  {"A", "B", "C", "D"},
  {"E", "F", "G", "H"}
};
std::cout << letters[0][2];  // C
```

### ✅ 실전 평균 계산 예제

```cpp
int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
float avg = 0, sum = 0;
for (int age : ages) { sum += age; }
avg = sum / 8;
```

---

## 3. 🛑 break & continue

### ✅ for 루프에서 사용

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 4) break;
    std::cout << i << "\n";
}
for (int i = 0; i < 10; i++) {
    if (i == 4) continue;
    std::cout << i << "\n";
}
```

### ✅ while 루프 주의

```cpp
int i = 0;
while (i < 10) {
    if (i == 4) {
        i++;
        continue;
    }
    std::cout << i << "\n";
    i++;
}
```

---

## 4. 🧾 열거형 enum

### ✅ 기본 사용법

```cpp
enum Level { LOW, MEDIUM, HIGH };
Level myVar = MEDIUM;
std::cout << myVar; // 1
```

### ✅ 값 지정 및 switch 예시

```cpp
enum Level { LOW = 1, MEDIUM, HIGH };
Level myVar = MEDIUM;

switch (myVar) {
  case LOW: std::cout << "Low"; break;
  case MEDIUM: std::cout << "Medium"; break;
  case HIGH: std::cout << "High"; break;
}
```

---

## 5. 🧱 구조체 struct

### ✅ 구조체 선언 및 사용

```cpp
struct Car {
  std::string brand;
  std::string model;
  int year;
};

Car myCar1 = {"BMW", "X5", 1999};
std::cout << myCar1.brand;
```

### ✅ 다수의 구조체 변수

```cpp
Car myCar2 = {"Ford", "Mustang", 1969};
```

### ✅ 사용자 정의 예제

```cpp
struct Student {
  std::string name;
  int age;
  char grade;
};

Student s1 = {"John", 35, 'A'};
```

---

## 💡 추가로 알면 좋은 개념들

- `vector<T>`: 동적 배열 컨테이너, 배열의 크기를 런타임에 변경 가능
- `sizeof()`는 바이트 단위 반환 → 요소 개수 계산 시 `/ sizeof(arr[0])` 필요
- 반복문에서의 무한 루프 주의 (조건 변수 증감 필수)
- `for-each` 루프는 C++11 이후 사용 가능 (`for (auto val : arr)`)
- `do/while`은 최소 1회 실행이 필요한 사용자 입력 등에 적합
- C++는 `main()` 함수부터 실행되며, 중괄호 `{}`와 세미콜론 `;` 필수

---

✅ 이 문서는 C++ 스터디용 정리 자료로, Python과 비교하며 문법과 사용 예제를 통합적으로 설명합니다.
