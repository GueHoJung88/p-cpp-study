#include "Utils.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <random>

namespace learning {

// OutputUtils 구현
void OutputUtils::printColored(const std::string& text, const std::string& color) {
    std::cout << color << text << "\033[0m";
}

void OutputUtils::printSuccess(const std::string& text) {
    printColored(text, "\033[32m");
}

void OutputUtils::printError(const std::string& text) {
    printColored(text, "\033[31m");
}

void OutputUtils::printWarning(const std::string& text) {
    printColored(text, "\033[33m");
}

void OutputUtils::printInfo(const std::string& text) {
    printColored(text, "\033[34m");
}

void OutputUtils::printHeader(const std::string& title, char border) {
    std::string borderLine(50, border);
    std::cout << borderLine << std::endl;
    std::cout << title << std::endl;
    std::cout << borderLine << std::endl;
}

void OutputUtils::printSubHeader(const std::string& title, char border) {
    std::string borderLine(30, border);
    std::cout << borderLine << std::endl;
    std::cout << title << std::endl;
    std::cout << borderLine << std::endl;
}

void OutputUtils::printCentered(const std::string& text, int width) {
    int padding = (width - text.length()) / 2;
    std::cout << std::string(padding, ' ') << text << std::endl;
}

void OutputUtils::printBox(const std::string& text, const std::string& title) {
    std::cout << "+" << std::string(48, '-') << "+" << std::endl;
    if (!title.empty()) {
        std::cout << "| " << title << std::string(46 - title.length(), ' ') << " |" << std::endl;
        std::cout << "+" << std::string(48, '-') << "+" << std::endl;
    }
    std::cout << "| " << text << std::string(46 - text.length(), ' ') << " |" << std::endl;
    std::cout << "+" << std::string(48, '-') << "+" << std::endl;
}

void OutputUtils::printProgressBar(int current, int total, int width) {
    float progress = static_cast<float>(current) / total;
    int barWidth = static_cast<int>(progress * width);
    
    std::cout << "[";
    for (int i = 0; i < width; ++i) {
        if (i < barWidth) std::cout << "=";
        else std::cout << " ";
    }
    std::cout << "] " << static_cast<int>(progress * 100) << "%" << std::endl;
}

void OutputUtils::printSpinner() {
    static int spinnerIndex = 0;
    const char* spinner[] = {"|", "/", "-", "\\"};
    std::cout << "\r" << spinner[spinnerIndex % 4] << std::flush;
    spinnerIndex++;
}

void OutputUtils::printWithDelay(const std::string& text, int delayMs) {
    std::cout << text << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
}

void OutputUtils::typewriterEffect(const std::string& text, int delayMs) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

// InputUtils 구현
std::string InputUtils::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return trim(input);
}

int InputUtils::getIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        try {
            value = std::stoi(input);
            if (value >= min && value <= max) {
                return value;
            }
            std::cout << "값은 " << min << "과 " << max << " 사이여야 합니다." << std::endl;
        } catch (const std::exception&) {
            std::cout << "올바른 정수를 입력해주세요." << std::endl;
        }
    }
}

double InputUtils::getDoubleInput(const std::string& prompt, double min, double max) {
    double value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        try {
            value = std::stod(input);
            if (value >= min && value <= max) {
                return value;
            }
            std::cout << "값은 " << min << "과 " << max << " 사이여야 합니다." << std::endl;
        } catch (const std::exception&) {
            std::cout << "올바른 실수를 입력해주세요." << std::endl;
        }
    }
}

char InputUtils::getCharInput(const std::string& prompt) {
    char value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

int InputUtils::getChoice(const std::vector<std::string>& options, const std::string& prompt) {
    std::cout << prompt << std::endl;
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << (i + 1) << ". " << options[i] << std::endl;
    }
    
    return getIntInput("선택: ", 1, static_cast<int>(options.size()));
}

bool InputUtils::getYesNoInput(const std::string& prompt) {
    while (true) {
        std::cout << prompt << " (y/n): ";
        std::string input;
        std::getline(std::cin, input);
        input = toLowerCase(trim(input));
        
        if (input == "y" || input == "yes") return true;
        if (input == "n" || input == "no") return false;
        
        std::cout << "y 또는 n을 입력해주세요." << std::endl;
    }
}

bool InputUtils::isValidInteger(const std::string& input) {
    if (input.empty()) return false;
    
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+') start = 1;
    
    if (start >= input.length()) return false;
    
    for (size_t i = start; i < input.length(); ++i) {
        if (!isdigit(input[i])) return false;
    }
    
    return true;
}

bool InputUtils::isValidDouble(const std::string& input) {
    if (input.empty()) return false;
    
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+') start = 1;
    
    if (start >= input.length()) return false;
    
    bool hasDigit = false;
    bool hasDecimal = false;
    
    for (size_t i = start; i < input.length(); ++i) {
        if (isdigit(input[i])) {
            hasDigit = true;
        } else if (input[i] == '.' && !hasDecimal) {
            hasDecimal = true;
        } else {
            return false;
        }
    }
    
    return hasDigit;
}

bool InputUtils::isValidName(const std::string& name) {
    if (name.empty()) return false;
    
    if (!isalpha(name[0])) return false;
    
    for (char c : name) {
        if (!isalnum(c) && c != ' ') return false;
    }
    
    return true;
}

bool InputUtils::isValidEmail(const std::string& email) {
    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailRegex);
}

std::string InputUtils::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

std::string InputUtils::toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string InputUtils::toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// StringUtils 구현
std::vector<std::string> StringUtils::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

std::vector<std::string> StringUtils::split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    
    tokens.push_back(str.substr(start));
    return tokens;
}

std::string StringUtils::join(const std::vector<std::string>& strings, const std::string& separator) {
    if (strings.empty()) return "";
    
    std::string result = strings[0];
    for (size_t i = 1; i < strings.size(); ++i) {
        result += separator + strings[i];
    }
    
    return result;
}

bool StringUtils::contains(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
}

bool StringUtils::startsWith(const std::string& str, const std::string& prefix) {
    if (str.length() < prefix.length()) return false;
    return str.substr(0, prefix.length()) == prefix;
}

bool StringUtils::endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() < suffix.length()) return false;
    return str.substr(str.length() - suffix.length()) == suffix;
}

std::string StringUtils::replace(const std::string& str, const std::string& oldStr, const std::string& newStr) {
    size_t pos = str.find(oldStr);
    if (pos == std::string::npos) return str;
    
    return str.substr(0, pos) + newStr + str.substr(pos + oldStr.length());
}

std::string StringUtils::replaceAll(const std::string& str, const std::string& oldStr, const std::string& newStr) {
    std::string result = str;
    size_t pos = 0;
    
    while ((pos = result.find(oldStr, pos)) != std::string::npos) {
        result.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
    
    return result;
}

std::string StringUtils::format(const std::string& format, const std::vector<std::string>& args) {
    std::string result = format;
    for (size_t i = 0; i < args.size(); ++i) {
        std::string placeholder = "{" + std::to_string(i) + "}";
        result = replaceAll(result, placeholder, args[i]);
    }
    return result;
}

std::string StringUtils::padLeft(const std::string& str, int width, char padChar) {
    if (str.length() >= width) return str;
    return std::string(width - str.length(), padChar) + str;
}

std::string StringUtils::padRight(const std::string& str, int width, char padChar) {
    if (str.length() >= width) return str;
    return str + std::string(width - str.length(), padChar);
}

std::string StringUtils::center(const std::string& str, int width, char padChar) {
    if (str.length() >= width) return str;
    
    int leftPadding = (width - str.length()) / 2;
    int rightPadding = width - str.length() - leftPadding;
    
    return std::string(leftPadding, padChar) + str + std::string(rightPadding, padChar);
}

std::string StringUtils::escapeHtml(const std::string& str) {
    std::string result = str;
    result = replaceAll(result, "&", "&amp;");
    result = replaceAll(result, "<", "&lt;");
    result = replaceAll(result, ">", "&gt;");
    result = replaceAll(result, "\"", "&quot;");
    result = replaceAll(result, "'", "&#39;");
    return result;
}

std::string StringUtils::unescapeHtml(const std::string& str) {
    std::string result = str;
    result = replaceAll(result, "&amp;", "&");
    result = replaceAll(result, "&lt;", "<");
    result = replaceAll(result, "&gt;", ">");
    result = replaceAll(result, "&quot;", "\"");
    result = replaceAll(result, "&#39;", "'");
    return result;
}

std::string StringUtils::escapeCppString(const std::string& str) {
    std::string result = str;
    result = replaceAll(result, "\\", "\\\\");
    result = replaceAll(result, "\"", "\\\"");
    result = replaceAll(result, "\n", "\\n");
    result = replaceAll(result, "\t", "\\t");
    result = replaceAll(result, "\r", "\\r");
    return result;
}

std::string StringUtils::unescapeCppString(const std::string& str) {
    std::string result = str;
    result = replaceAll(result, "\\n", "\n");
    result = replaceAll(result, "\\t", "\t");
    result = replaceAll(result, "\\r", "\r");
    result = replaceAll(result, "\\\"", "\"");
    result = replaceAll(result, "\\\\", "\\");
    return result;
}

std::string StringUtils::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

// MathUtils 구현
int MathUtils::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MathUtils::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool MathUtils::isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<int> MathUtils::getPrimeFactors(int n) {
    std::vector<int> factors;
    
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    
    if (n > 1) {
        factors.push_back(n);
    }
    
    return factors;
}

int MathUtils::factorial(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int MathUtils::randomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

double MathUtils::randomDouble(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

std::vector<int> MathUtils::randomIntArray(int size, int min, int max) {
    std::vector<int> result;
    result.reserve(size);
    
    for (int i = 0; i < size; ++i) {
        result.push_back(randomInt(min, max));
    }
    
    return result;
}

double MathUtils::mean(const std::vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    
    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

double MathUtils::median(const std::vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    
    std::vector<double> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    
    if (sorted.size() % 2 == 0) {
        return (sorted[sorted.size() / 2 - 1] + sorted[sorted.size() / 2]) / 2.0;
    } else {
        return sorted[sorted.size() / 2];
    }
}

double MathUtils::standardDeviation(const std::vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    
    double avg = mean(numbers);
    double sum = 0.0;
    
    for (double num : numbers) {
        sum += (num - avg) * (num - avg);
    }
    
    return std::sqrt(sum / numbers.size());
}

double MathUtils::variance(const std::vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    
    double avg = mean(numbers);
    double sum = 0.0;
    
    for (double num : numbers) {
        sum += (num - avg) * (num - avg);
    }
    
    return sum / numbers.size();
}

bool MathUtils::isPerfectSquare(int n) {
    if (n < 0) return false;
    int root = static_cast<int>(std::sqrt(n));
    return root * root == n;
}

bool MathUtils::isPalindrome(int n) {
    if (n < 0) return false;
    
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return original == reversed;
}

int MathUtils::reverseNumber(int n) {
    int reversed = 0;
    
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return reversed;
}

int MathUtils::countDigits(int n) {
    if (n == 0) return 1;
    
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    
    return count;
}

// TimeUtils 구현
std::string TimeUtils::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto tm = *std::localtime(&time_t);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");
    return oss.str();
}

std::string TimeUtils::getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto tm = *std::localtime(&time_t);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    return oss.str();
}

std::string TimeUtils::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto tm = *std::localtime(&time_t);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

auto TimeUtils::startTimer() {
    return std::chrono::high_resolution_clock::now();
}

double TimeUtils::getElapsedTime(const std::chrono::high_resolution_clock::time_point& startTime) {
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    return duration.count() / 1000.0;
}

std::string TimeUtils::formatDuration(double seconds) {
    int hours = static_cast<int>(seconds) / 3600;
    int minutes = (static_cast<int>(seconds) % 3600) / 60;
    int secs = static_cast<int>(seconds) % 60;
    
    std::ostringstream oss;
    if (hours > 0) {
        oss << hours << "h " << minutes << "m " << secs << "s";
    } else if (minutes > 0) {
        oss << minutes << "m " << secs << "s";
    } else {
        oss << secs << "s";
    }
    
    return oss.str();
}

void TimeUtils::sleep(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void TimeUtils::sleepSeconds(double seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(seconds * 1000)));
}

// ValidationUtils 구현
bool ValidationUtils::isValidEmail(const std::string& email) {
    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailRegex);
}

bool ValidationUtils::isValidPhoneNumber(const std::string& phone) {
    std::regex phoneRegex(R"(\+?[0-9\s\-\(\)]{10,})");
    return std::regex_match(phone, phoneRegex);
}

bool ValidationUtils::isValidUrl(const std::string& url) {
    std::regex urlRegex(R"(https?://[^\s/$.?#].[^\s]*)");
    return std::regex_match(url, urlRegex);
}

bool ValidationUtils::isValidIpAddress(const std::string& ip) {
    std::regex ipRegex(R"((\d{1,3}\.){3}\d{1,3})");
    if (!std::regex_match(ip, ipRegex)) return false;
    
    auto parts = StringUtils::split(ip, '.');
    for (const auto& part : parts) {
        int num = std::stoi(part);
        if (num < 0 || num > 255) return false;
    }
    return true;
}

bool ValidationUtils::isValidVariableName(const std::string& name) {
    if (name.empty()) return false;
    
    if (!isalpha(name[0]) && name[0] != '_') return false;
    
    for (char c : name) {
        if (!isalnum(c) && c != '_') return false;
    }
    
    return true;
}

bool ValidationUtils::isValidFunctionName(const std::string& name) {
    return isValidVariableName(name);
}

bool ValidationUtils::isValidClassName(const std::string& name) {
    if (name.empty()) return false;
    
    if (!isalpha(name[0]) && name[0] != '_') return false;
    
    for (char c : name) {
        if (!isalnum(c) && c != '_') return false;
    }
    
    return true;
}

bool ValidationUtils::isValidNamespaceName(const std::string& name) {
    return isValidVariableName(name);
}

bool ValidationUtils::isValidName(const std::string& name) {
    if (name.empty()) return false;
    
    if (!isalpha(name[0])) return false;
    
    for (char c : name) {
        if (!isalnum(c) && c != ' ') return false;
    }
    
    return true;
}

bool ValidationUtils::hasBalancedBrackets(const std::string& code) {
    std::stack<char> brackets;
    
    for (char c : code) {
        if (c == '[' || c == '(' || c == '{') {
            brackets.push(c);
        } else if (c == ']') {
            if (brackets.empty() || brackets.top() != '[') return false;
            brackets.pop();
        } else if (c == ')') {
            if (brackets.empty() || brackets.top() != '(') return false;
            brackets.pop();
        } else if (c == '}') {
            if (brackets.empty() || brackets.top() != '{') return false;
            brackets.pop();
        }
    }
    
    return brackets.empty();
}

bool ValidationUtils::hasBalancedParentheses(const std::string& code) {
    int count = 0;
    
    for (char c : code) {
        if (c == '(') count++;
        else if (c == ')') count--;
        
        if (count < 0) return false;
    }
    
    return count == 0;
}

bool ValidationUtils::hasBalancedBraces(const std::string& code) {
    int count = 0;
    
    for (char c : code) {
        if (c == '{') count++;
        else if (c == '}') count--;
        
        if (count < 0) return false;
    }
    
    return count == 0;
}

bool ValidationUtils::hasBalancedQuotes(const std::string& code) {
    bool inSingleQuote = false;
    bool inDoubleQuote = false;
    
    for (char c : code) {
        if (c == '\'' && !inDoubleQuote) {
            inSingleQuote = !inSingleQuote;
        } else if (c == '"' && !inSingleQuote) {
            inDoubleQuote = !inDoubleQuote;
        }
    }
    
    return !inSingleQuote && !inDoubleQuote;
}

// 기존 util 네임스페이스와의 호환성
namespace util {
    void greet(const std::string& name) {
        std::cout << "Hi, " << name << "!" << std::endl;
    }
    
    std::string formatMessage(const std::string& message) {
        return "Formatted: " + message;
    }
    
    bool isValidName(const std::string& name) {
        return learning::ValidationUtils::isValidName(name);
    }
}

} // namespace learning 