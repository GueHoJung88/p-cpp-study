#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>
#include <random>
#include <thread>
#include <stack>
#include <climits>
#include <cfloat>

namespace learning {

// 출력 관련 유틸리티
class OutputUtils {
public:
    // 색상 출력 (ANSI 이스케이프 코드)
    static void printColored(const std::string& text, const std::string& color);
    static void printSuccess(const std::string& text);
    static void printError(const std::string& text);
    static void printWarning(const std::string& text);
    static void printInfo(const std::string& text);
    
    // 포맷팅 출력
    static void printHeader(const std::string& title, char border = '=');
    static void printSubHeader(const std::string& title, char border = '-');
    static void printCentered(const std::string& text, int width = 50);
    static void printBox(const std::string& text, const std::string& title = "");
    
    // 진행률 표시
    static void printProgressBar(int current, int total, int width = 50);
    static void printSpinner();
    
    // 지연 출력
    static void printWithDelay(const std::string& text, int delayMs = 100);
    static void typewriterEffect(const std::string& text, int delayMs = 50);
};

// 입력 관련 유틸리티
class InputUtils {
public:
    // 안전한 입력 받기
    static std::string getStringInput(const std::string& prompt = "Enter: ");
    static int getIntInput(const std::string& prompt = "Enter number: ", int min = INT_MIN, int max = INT_MAX);
    static double getDoubleInput(const std::string& prompt = "Enter number: ", double min = -DBL_MAX, double max = DBL_MAX);
    static char getCharInput(const std::string& prompt = "Enter character: ");
    
    // 선택지 입력
    static int getChoice(const std::vector<std::string>& options, const std::string& prompt = "Choose an option: ");
    static bool getYesNoInput(const std::string& prompt = "Yes/No: ");
    
    // 입력 검증
    static bool isValidInteger(const std::string& input);
    static bool isValidDouble(const std::string& input);
    static bool isValidName(const std::string& name);
    static bool isValidEmail(const std::string& email);
    
    // 입력 정리
    static std::string trim(const std::string& str);
    static std::string toLowerCase(const std::string& str);
    static std::string toUpperCase(const std::string& str);
};

// 문자열 관련 유틸리티
class StringUtils {
public:
    // 문자열 조작
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::vector<std::string> split(const std::string& str, const std::string& delimiter);
    static std::string join(const std::vector<std::string>& strings, const std::string& separator);
    static std::string trim(const std::string& str);
    
    // 문자열 검색 및 교체
    static bool contains(const std::string& str, const std::string& substr);
    static bool startsWith(const std::string& str, const std::string& prefix);
    static bool endsWith(const std::string& str, const std::string& suffix);
    static std::string replace(const std::string& str, const std::string& oldStr, const std::string& newStr);
    static std::string replaceAll(const std::string& str, const std::string& oldStr, const std::string& newStr);
    
    // 문자열 포맷팅
    static std::string format(const std::string& format, const std::vector<std::string>& args);
    static std::string padLeft(const std::string& str, int width, char padChar = ' ');
    static std::string padRight(const std::string& str, int width, char padChar = ' ');
    static std::string center(const std::string& str, int width, char padChar = ' ');
    
    // 특수 문자 처리
    static std::string escapeHtml(const std::string& str);
    static std::string unescapeHtml(const std::string& str);
    static std::string escapeCppString(const std::string& str);
    static std::string unescapeCppString(const std::string& str);
};

// 수학 관련 유틸리티
class MathUtils {
public:
    // 기본 수학 함수
    static int gcd(int a, int b);
    static int lcm(int a, int b);
    static bool isPrime(int n);
    static std::vector<int> getPrimeFactors(int n);
    static int factorial(int n);
    
    // 랜덤 수 생성
    static int randomInt(int min, int max);
    static double randomDouble(double min, double max);
    static std::vector<int> randomIntArray(int size, int min, int max);
    
    // 통계 함수
    static double mean(const std::vector<double>& numbers);
    static double median(const std::vector<double>& numbers);
    static double standardDeviation(const std::vector<double>& numbers);
    static double variance(const std::vector<double>& numbers);
    
    // 수학 검증
    static bool isPerfectSquare(int n);
    static bool isPalindrome(int n);
    static int reverseNumber(int n);
    static int countDigits(int n);
};

// 시간 관련 유틸리티
class TimeUtils {
public:
    // 현재 시간 정보
    static std::string getCurrentTime();
    static std::string getCurrentDate();
    static std::string getCurrentDateTime();
    
    // 시간 측정
    static auto startTimer();
    static double getElapsedTime(const std::chrono::high_resolution_clock::time_point& startTime);
    static std::string formatDuration(double seconds);
    
    // 지연 함수
    static void sleep(int milliseconds);
    static void sleepSeconds(double seconds);
};

// 파일 관련 유틸리티
class FileUtils {
public:
    // 파일 존재 여부 확인
    static bool fileExists(const std::string& filename);
    static bool directoryExists(const std::string& path);
    
    // 파일 읽기/쓰기
    static std::string readFile(const std::string& filename);
    static bool writeFile(const std::string& filename, const std::string& content);
    static bool appendToFile(const std::string& filename, const std::string& content);
    
    // 파일 정보
    static size_t getFileSize(const std::string& filename);
    static std::string getFileExtension(const std::string& filename);
    static std::string getFileName(const std::string& path);
    static std::string getDirectory(const std::string& path);
    
    // 디렉토리 조작
    static std::vector<std::string> listFiles(const std::string& directory);
    static std::vector<std::string> listDirectories(const std::string& directory);
    static bool createDirectory(const std::string& path);
    static bool deleteFile(const std::string& filename);
};

// 검증 관련 유틸리티
class ValidationUtils {
public:
    // 일반적인 검증
    static bool isValidEmail(const std::string& email);
    static bool isValidPhoneNumber(const std::string& phone);
    static bool isValidUrl(const std::string& url);
    static bool isValidIpAddress(const std::string& ip);
    
    // C++ 관련 검증
    static bool isValidVariableName(const std::string& name);
    static bool isValidFunctionName(const std::string& name);
    static bool isValidClassName(const std::string& name);
    static bool isValidNamespaceName(const std::string& name);
    static bool isValidName(const std::string& name);
    
    // 코드 검증
    static bool hasBalancedBrackets(const std::string& code);
    static bool hasBalancedParentheses(const std::string& code);
    static bool hasBalancedBraces(const std::string& code);
    static bool hasBalancedQuotes(const std::string& code);
};

// 디버깅 관련 유틸리티
class DebugUtils {
public:
    // 디버그 출력
    static void debugPrint(const std::string& message, const std::string& file = "", int line = 0);
    static void debugPrintVariable(const std::string& name, const std::string& value);
    static void debugPrintVector(const std::string& name, const std::vector<std::string>& values);
    
    // 조건부 디버그
    static void debugIf(bool condition, const std::string& message);
    static void debugAssert(bool condition, const std::string& message);
    
    // 성능 측정
    static void startPerformanceTimer(const std::string& name);
    static void endPerformanceTimer(const std::string& name);
    static void printPerformanceStats();
};

// 기존 util 네임스페이스와의 호환성
namespace util {
    void greet(const std::string& name);
    std::string formatMessage(const std::string& message);
    bool isValidName(const std::string& name);
}

} // namespace learning 