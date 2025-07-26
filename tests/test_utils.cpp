#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include "../src/core/Utils.h"

using namespace learning;

// 출력 캡처를 위한 테스트 헬퍼
class OutputCapture {
private:
    std::streambuf* original_cout;
    std::ostringstream captured_output;

public:
    OutputCapture() : original_cout(std::cout.rdbuf()) {
        std::cout.rdbuf(captured_output.rdbuf());
    }
    
    ~OutputCapture() {
        std::cout.rdbuf(original_cout);
    }
    
    std::string getOutput() const {
        return captured_output.str();
    }
};

// 유틸리티 함수 테스트
class UtilsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 테스트 전 초기화
    }
    
    void TearDown() override {
        // 테스트 후 정리
    }
};

// StringUtils 테스트
TEST_F(UtilsTest, StringUtils_Split_ValidString_ReturnsCorrectTokens) {
    auto tokens = StringUtils::split("hello,world,test", ',');
    EXPECT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0], "hello");
    EXPECT_EQ(tokens[1], "world");
    EXPECT_EQ(tokens[2], "test");
}

TEST_F(UtilsTest, StringUtils_Join_ValidTokens_ReturnsCorrectString) {
    std::vector<std::string> tokens = {"hello", "world", "test"};
    std::string result = StringUtils::join(tokens, ",");
    EXPECT_EQ(result, "hello,world,test");
}

TEST_F(UtilsTest, StringUtils_Trim_ValidString_ReturnsTrimmedString) {
    std::string result = StringUtils::trim("  hello world  ");
    EXPECT_EQ(result, "hello world");
}

TEST_F(UtilsTest, StringUtils_StartsWith_ValidString_ReturnsTrue) {
    EXPECT_TRUE(StringUtils::startsWith("hello world", "hello"));
    EXPECT_FALSE(StringUtils::startsWith("hello world", "world"));
}

TEST_F(UtilsTest, StringUtils_EndsWith_ValidString_ReturnsTrue) {
    EXPECT_TRUE(StringUtils::endsWith("hello world", "world"));
    EXPECT_FALSE(StringUtils::endsWith("hello world", "hello"));
}

// MathUtils 테스트
TEST_F(UtilsTest, MathUtils_Gcd_ValidNumbers_ReturnsCorrectGcd) {
    EXPECT_EQ(MathUtils::gcd(48, 18), 6);
    EXPECT_EQ(MathUtils::gcd(54, 24), 6);
}

TEST_F(UtilsTest, MathUtils_Lcm_ValidNumbers_ReturnsCorrectLcm) {
    EXPECT_EQ(MathUtils::lcm(12, 18), 36);
    EXPECT_EQ(MathUtils::lcm(8, 12), 24);
}

TEST_F(UtilsTest, MathUtils_IsPrime_ValidNumbers_ReturnsCorrectResult) {
    EXPECT_TRUE(MathUtils::isPrime(2));
    EXPECT_TRUE(MathUtils::isPrime(3));
    EXPECT_TRUE(MathUtils::isPrime(17));
    EXPECT_FALSE(MathUtils::isPrime(4));
    EXPECT_FALSE(MathUtils::isPrime(1));
}

TEST_F(UtilsTest, MathUtils_Factorial_ValidNumbers_ReturnsCorrectResult) {
    EXPECT_EQ(MathUtils::factorial(0), 1);
    EXPECT_EQ(MathUtils::factorial(1), 1);
    EXPECT_EQ(MathUtils::factorial(5), 120);
}

// ValidationUtils 테스트
TEST_F(UtilsTest, ValidationUtils_IsValidEmail_ValidEmails_ReturnsTrue) {
    EXPECT_TRUE(ValidationUtils::isValidEmail("test@example.com"));
    EXPECT_TRUE(ValidationUtils::isValidEmail("user.name@domain.co.uk"));
    EXPECT_FALSE(ValidationUtils::isValidEmail("invalid-email"));
    EXPECT_FALSE(ValidationUtils::isValidEmail("@domain.com"));
}

TEST_F(UtilsTest, ValidationUtils_IsValidVariableName_ValidNames_ReturnsTrue) {
    EXPECT_TRUE(ValidationUtils::isValidVariableName("variable"));
    EXPECT_TRUE(ValidationUtils::isValidVariableName("_variable"));
    EXPECT_TRUE(ValidationUtils::isValidVariableName("var123"));
    EXPECT_FALSE(ValidationUtils::isValidVariableName("123var"));
    EXPECT_FALSE(ValidationUtils::isValidVariableName("var-name"));
}

TEST_F(UtilsTest, ValidationUtils_HasBalancedParentheses_ValidCode_ReturnsTrue) {
    EXPECT_TRUE(ValidationUtils::hasBalancedParentheses("(hello world)"));
    EXPECT_TRUE(ValidationUtils::hasBalancedParentheses("((nested))"));
    EXPECT_FALSE(ValidationUtils::hasBalancedParentheses("(unclosed"));
    EXPECT_FALSE(ValidationUtils::hasBalancedParentheses(")unopened"));
}

// TimeUtils 테스트
TEST_F(UtilsTest, TimeUtils_GetCurrentTime_ReturnsNonEmptyString) {
    std::string time = TimeUtils::getCurrentTime();
    EXPECT_FALSE(time.empty());
}

TEST_F(UtilsTest, TimeUtils_GetCurrentDate_ReturnsNonEmptyString) {
    std::string date = TimeUtils::getCurrentDate();
    EXPECT_FALSE(date.empty());
}

TEST_F(UtilsTest, TimeUtils_FormatDuration_ValidSeconds_ReturnsFormattedString) {
    std::string result = TimeUtils::formatDuration(3661.0); // 1h 1m 1s
    EXPECT_TRUE(result.find("1h") != std::string::npos);
}

// 기존 util 네임스페이스 테스트
TEST_F(UtilsTest, UtilNamespace_GreetFunction_ValidName_ReturnsExpectedOutput) {
    OutputCapture capture;
    
    util::greet("TestUser");
    
    std::string output = capture.getOutput();
    EXPECT_TRUE(output.find("TestUser") != std::string::npos);
    EXPECT_TRUE(output.find("Hi") != std::string::npos);
}

TEST_F(UtilsTest, UtilNamespace_FormatMessage_ValidInput_ReturnsFormattedMessage) {
    std::string result = util::formatMessage("Hello World");
    EXPECT_EQ(result, "Formatted: Hello World");
}

TEST_F(UtilsTest, UtilNamespace_IsValidName_ValidName_ReturnsTrue) {
    EXPECT_TRUE(util::isValidName("John"));
    EXPECT_TRUE(util::isValidName("Mary"));
    EXPECT_TRUE(util::isValidName("user123"));
}

TEST_F(UtilsTest, UtilNamespace_IsValidName_InvalidName_ReturnsFalse) {
    EXPECT_FALSE(util::isValidName(""));
    EXPECT_FALSE(util::isValidName("123"));
    EXPECT_FALSE(util::isValidName("user@name"));
} 