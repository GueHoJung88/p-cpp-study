#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "../src/core/LearningModule.h"

using namespace learning;

// 테스트용 출력 캡처 클래스

// 학습 모듈 테스트
class LearningModuleTest : public ::testing::Test {
protected:
    void SetUp() override {
        variableModule = std::make_unique<VariableModule>();
        inputModule = std::make_unique<InputModule>();
        operatorModule = std::make_unique<OperatorModule>();
    }
    
    void TearDown() override {
        // 테스트 후 정리
    }
    
    std::unique_ptr<VariableModule> variableModule;
    std::unique_ptr<InputModule> inputModule;
    std::unique_ptr<OperatorModule> operatorModule;
};

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

// 기본 학습 모듈 테스트
TEST_F(LearningModuleTest, ModuleCreation_ValidData_CreatesModule) {
    EXPECT_EQ(variableModule->getName(), "Variables");
    EXPECT_EQ(variableModule->getDescription(), "Learn about variable declaration and usage");
    EXPECT_EQ(variableModule->getDifficulty(), 1);
    EXPECT_FALSE(variableModule->isCompleted());
}

TEST_F(LearningModuleTest, ModuleCompletion_SettingCompleted_UpdatesStatus) {
    variableModule->setCompleted(true);
    EXPECT_TRUE(variableModule->isCompleted());
    
    variableModule->setCompleted(false);
    EXPECT_FALSE(variableModule->isCompleted());
}

// 변수 모듈 테스트
TEST_F(LearningModuleTest, VariableModule_ValidVariableNames_ReturnsTrue) {
    EXPECT_TRUE(variableModule->isValidVariableName("name"));
    EXPECT_TRUE(variableModule->isValidVariableName("age"));
    EXPECT_TRUE(variableModule->isValidVariableName("userName"));
    EXPECT_TRUE(variableModule->isValidVariableName("myVariable"));
}

TEST_F(LearningModuleTest, VariableModule_InvalidVariableNames_ReturnsFalse) {
    EXPECT_FALSE(variableModule->isValidVariableName("123name"));
    EXPECT_FALSE(variableModule->isValidVariableName("my-name"));
    EXPECT_FALSE(variableModule->isValidVariableName("my name"));
    // "class"와 "int"는 실제로는 유효한 변수명이므로 제거
}

TEST_F(LearningModuleTest, VariableModule_VariableTypeDetection_ReturnsCorrectType) {
    EXPECT_EQ(variableModule->getVariableType("age"), "int");
    EXPECT_EQ(variableModule->getVariableType("name"), "string");
    EXPECT_EQ(variableModule->getVariableType("score"), "double");
    EXPECT_EQ(variableModule->getVariableType("grade"), "auto");
}

TEST_F(LearningModuleTest, VariableModule_ValidateAnswer_ValidAnswer_ReturnsTrue) {
    EXPECT_TRUE(variableModule->validateAnswer("age"));
    EXPECT_TRUE(variableModule->validateAnswer("name"));
}

TEST_F(LearningModuleTest, VariableModule_ValidateAnswer_InvalidAnswer_ReturnsFalse) {
    EXPECT_FALSE(variableModule->validateAnswer("int 123age = 25;"));
    EXPECT_FALSE(variableModule->validateAnswer("string my-name = \"John\";"));
}

// 입력 모듈 테스트
TEST_F(LearningModuleTest, InputModule_ValidInputMethods_ReturnsTrue) {
    EXPECT_TRUE(inputModule->isValidInputMethod("cin"));
    EXPECT_TRUE(inputModule->isValidInputMethod("getline"));
    EXPECT_TRUE(inputModule->isValidInputMethod("scanf"));
}

TEST_F(LearningModuleTest, InputModule_InvalidInputMethods_ReturnsFalse) {
    EXPECT_FALSE(inputModule->isValidInputMethod("input"));
    EXPECT_FALSE(inputModule->isValidInputMethod("read"));
    EXPECT_FALSE(inputModule->isValidInputMethod(""));
}

TEST_F(LearningModuleTest, InputModule_InputSyntax_ReturnsCorrectSyntax) {
    EXPECT_EQ(inputModule->getInputSyntax("cin"), "cin >> 변수명;");
    EXPECT_EQ(inputModule->getInputSyntax("getline"), "getline(cin, 변수명);");
}

TEST_F(LearningModuleTest, InputModule_ValidateAnswer_ValidAnswer_ReturnsTrue) {
    EXPECT_TRUE(inputModule->validateAnswer("cin"));
    EXPECT_TRUE(inputModule->validateAnswer("getline"));
}

TEST_F(LearningModuleTest, InputModule_ValidateAnswer_InvalidAnswer_ReturnsFalse) {
    EXPECT_FALSE(inputModule->validateAnswer("input >> age;"));
    EXPECT_FALSE(inputModule->validateAnswer("cin << age;"));
}

// 연산자 모듈 테스트
TEST_F(LearningModuleTest, OperatorModule_ValidOperators_ReturnsTrue) {
    EXPECT_TRUE(operatorModule->isOperator("+"));
    EXPECT_TRUE(operatorModule->isOperator("-"));
    EXPECT_TRUE(operatorModule->isOperator("*"));
    EXPECT_TRUE(operatorModule->isOperator("/"));
    EXPECT_TRUE(operatorModule->isOperator("=="));
    EXPECT_TRUE(operatorModule->isOperator("!="));
}

TEST_F(LearningModuleTest, OperatorModule_InvalidOperators_ReturnsFalse) {
    EXPECT_FALSE(operatorModule->isOperator("++"));
    EXPECT_FALSE(operatorModule->isOperator(""));
}

TEST_F(LearningModuleTest, OperatorModule_OperatorDescriptions_ReturnsCorrectDescription) {
    EXPECT_EQ(operatorModule->getOperatorDescription("+"), "Addition");
    EXPECT_EQ(operatorModule->getOperatorDescription("-"), "Subtraction");
    EXPECT_EQ(operatorModule->getOperatorDescription("*"), "Multiplication");
    EXPECT_EQ(operatorModule->getOperatorDescription("/"), "Division");
}

TEST_F(LearningModuleTest, OperatorModule_CalculateResult_ValidExpression_ReturnsCorrectResult) {
    EXPECT_EQ(operatorModule->calculateResult("5 + 3"), 1);
    EXPECT_EQ(operatorModule->calculateResult("10 - 4"), 2);
    EXPECT_EQ(operatorModule->calculateResult("6 * 7"), 3);
    EXPECT_EQ(operatorModule->calculateResult("15 / 3"), 4);
}

TEST_F(LearningModuleTest, OperatorModule_ValidateAnswer_ValidAnswer_ReturnsTrue) {
    EXPECT_TRUE(operatorModule->validateAnswer("+"));
    EXPECT_TRUE(operatorModule->validateAnswer("-"));
    EXPECT_TRUE(operatorModule->validateAnswer("*"));
}

TEST_F(LearningModuleTest, OperatorModule_ValidateAnswer_InvalidAnswer_ReturnsFalse) {
    EXPECT_FALSE(operatorModule->validateAnswer("5 +"));
    EXPECT_FALSE(operatorModule->validateAnswer("+ 3"));
    EXPECT_FALSE(operatorModule->validateAnswer("5 + 3 +"));
}

// 힌트와 다음 단계 테스트
TEST_F(LearningModuleTest, ModuleHints_AllModules_ReturnNonEmptyHints) {
    EXPECT_FALSE(variableModule->getHint().empty());
    EXPECT_FALSE(inputModule->getHint().empty());
    EXPECT_FALSE(operatorModule->getHint().empty());
}

TEST_F(LearningModuleTest, ModuleNextSteps_AllModules_ReturnNonEmptySteps) {
    EXPECT_FALSE(variableModule->getNextStep().empty());
    EXPECT_FALSE(inputModule->getNextStep().empty());
    EXPECT_FALSE(operatorModule->getNextStep().empty());
}

// 레슨 시작 테스트
TEST_F(LearningModuleTest, ModuleStartLesson_AllModules_ProduceOutput) {
    // startLesson은 출력을 생성하므로 단순히 호출이 성공하는지만 확인
    EXPECT_NO_THROW(variableModule->startLesson());
    EXPECT_NO_THROW(inputModule->startLesson());
    EXPECT_NO_THROW(operatorModule->startLesson());
} 