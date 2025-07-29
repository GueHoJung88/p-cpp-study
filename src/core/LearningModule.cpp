#include "LearningModule.h"
#include <iostream>
#include <algorithm>
#include <cctype>

namespace learning {

// LearningModule (추상 클래스) 구현
LearningModule::LearningModule(const std::string& name, const std::string& desc, int diff) 
    : moduleName(name), description(desc), difficulty(diff), completed(false) {}



void LearningModule::addContent(const std::string& key, const std::string& value) {
    content[key] = value;
}

std::string LearningModule::getContent(const std::string& key) const {
    auto it = content.find(key);
    return (it != content.end()) ? it->second : "";
}

bool LearningModule::hasContent(const std::string& key) const {
    return content.find(key) != content.end();
}

void LearningModule::addPrerequisite(const std::string& moduleName) {
    prerequisites.push_back(moduleName);
}

bool LearningModule::canStart(const std::vector<std::string>& completedModules) const {
    for (const auto& prereq : prerequisites) {
        if (std::find(completedModules.begin(), completedModules.end(), prereq) == completedModules.end()) {
            return false;
        }
    }
    return true;
}

// VariableModule 구현
VariableModule::VariableModule() : LearningModule("Variables", "Learn about variable declaration and usage", 1) {
    validVariableNames = {"name", "age", "score", "userName", "myVariable"};
    invalidVariableNames = {"123name", "my-name", "my name", "class", "int"};
    
    variableTypes = {
        {"int", "정수형"},
        {"double", "실수형"},
        {"string", "문자열"},
        {"bool", "불린형"},
        {"char", "문자형"}
    };
}

std::string VariableModule::getVariableType(const std::string& variableName) const {
    // 간단한 변수 타입 추론 (실제로는 더 복잡할 수 있음)
    if (variableName.find("count") != std::string::npos || 
        variableName.find("num") != std::string::npos ||
        variableName.find("index") != std::string::npos ||
        variableName.find("age") != std::string::npos) {
        return "int";
    } else if (variableName.find("name") != std::string::npos ||
               variableName.find("text") != std::string::npos ||
               variableName.find("str") != std::string::npos) {
        return "string";
    } else if (variableName.find("price") != std::string::npos ||
               variableName.find("rate") != std::string::npos ||
               variableName.find("score") != std::string::npos) {
        return "double";
    } else if (variableName.find("is") != std::string::npos ||
               variableName.find("has") != std::string::npos ||
               variableName.find("can") != std::string::npos) {
        return "bool";
    }
    return "auto";
}

bool VariableModule::isValidVariableName(const std::string& name) const {
    if (name.empty()) return false;
    
    // 첫 번째 문자가 문자나 언더스코어여야 함
    if (!isalpha(name[0]) && name[0] != '_') return false;
    
    // 나머지 문자들은 문자, 숫자, 언더스코어만 허용
    for (char c : name) {
        if (!isalnum(c) && c != '_') return false;
    }
    
    return true;
}

std::vector<std::string> VariableModule::getValidVariableNames() const {
    return validVariableNames;
}

std::vector<std::string> VariableModule::getInvalidVariableNames() const {
    return invalidVariableNames;
}

void VariableModule::startLesson() {
    std::cout << "=== 변수 학습 모듈 시작 ===" << std::endl;
    std::cout << "변수는 데이터를 저장하는 컨테이너입니다." << std::endl;
    std::cout << "문법: 데이터타입 변수명 = 초기값;" << std::endl;
}

bool VariableModule::validateAnswer(const std::string& answer) {
    return isValidVariableName(answer);
}

std::string VariableModule::getHint() const {
    return "변수명은 문자나 언더스코어로 시작해야 하며, 문자, 숫자, 언더스코어만 사용할 수 있습니다.";
}

std::string VariableModule::getNextStep() const {
    return "다음 단계: 변수 타입과 초기화 방법을 학습합니다.";
}

// InputModule 구현
InputModule::InputModule() : LearningModule("User Input", "Learn about getting user input", 2) {
    validInputTypes = {"cin", "getline", "scanf", "getchar"};
    
    inputSyntax = {
        {"cin", "cin >> 변수명;"},
        {"getline", "getline(cin, 변수명);"},
        {"scanf", "scanf(\"%d\", &변수명);"},
        {"getchar", "변수명 = getchar();"}
    };
}

std::string InputModule::getInputSyntax(const std::string& inputType) const {
    if (inputType == "cin") {
        return "cin >> 변수명;";
    } else if (inputType == "getline") {
        return "getline(cin, 변수명);";
    } else if (inputType == "scanf") {
        return "scanf(\"%d\", &변수명);";
    }
    return "cin >> 변수명;";
}

bool InputModule::isValidInputMethod(const std::string& method) const {
    return std::find(validInputTypes.begin(), validInputTypes.end(), method) != validInputTypes.end();
}

std::vector<std::string> InputModule::getValidInputTypes() const {
    return validInputTypes;
}

void InputModule::startLesson() {
    std::cout << "=== 사용자 입력 학습 모듈 시작 ===" << std::endl;
    std::cout << "사용자로부터 데이터를 입력받는 방법을 학습합니다." << std::endl;
    std::cout << "기본 문법: cin >> 변수명;" << std::endl;
}

bool InputModule::validateAnswer(const std::string& answer) {
    return isValidInputMethod(answer);
}

std::string InputModule::getHint() const {
    return "가장 일반적인 입력 방법은 'cin'을 사용하는 것입니다.";
}

std::string InputModule::getNextStep() const {
    return "다음 단계: 다양한 데이터 타입별 입력 방법을 학습합니다.";
}

// OperatorModule 구현
OperatorModule::OperatorModule() : LearningModule("Operators", "Learn about C++ operators", 3) {
    operators = {
        {"+", "Addition"},
        {"-", "Subtraction"},
        {"*", "Multiplication"},
        {"/", "Division"},
        {"%", "Modulus"},
        {"==", "Equal to"},
        {"!=", "Not equal to"},
        {"<", "Less than"},
        {">", "Greater than"},
        {"<=", "Less than or equal to"},
        {">=", "Greater than or equal to"},
        {"&&", "Logical AND"},
        {"||", "Logical OR"},
        {"!", "Logical NOT"}
    };
    
    operatorPrecedence = {
        {"!", 1},
        {"*", 2}, {"/", 2}, {"%", 2},
        {"+", 3}, {"-", 3},
        {"<", 4}, {">", 4}, {"<=", 4}, {">=", 4},
        {"==", 5}, {"!=", 5},
        {"&&", 6},
        {"||", 7}
    };
}

bool OperatorModule::isOperator(const std::string& symbol) const {
    return operators.find(symbol) != operators.end();
}

std::string OperatorModule::getOperatorDescription(const std::string& op) const {
    auto it = operators.find(op);
    return (it != operators.end()) ? it->second : "Unknown operator";
}

int OperatorModule::getOperatorPrecedence(const std::string& op) const {
    auto it = operatorPrecedence.find(op);
    return (it != operatorPrecedence.end()) ? it->second : 0;
}

int OperatorModule::calculateResult(const std::string& expression) const {
    // 간단한 계산 예시 (실제로는 더 복잡한 파서가 필요)
    if (expression.find("+") != std::string::npos) {
        return 1; // 덧셈 연산
    } else if (expression.find("-") != std::string::npos) {
        return 2; // 뺄셈 연산
    } else if (expression.find("*") != std::string::npos) {
        return 3; // 곱셈 연산
    } else if (expression.find("/") != std::string::npos) {
        return 4; // 나눗셈 연산
    }
    return 0; // 알 수 없는 연산
}

void OperatorModule::startLesson() {
    std::cout << "=== 연산자 학습 모듈 시작 ===" << std::endl;
    std::cout << "C++의 다양한 연산자들을 학습합니다." << std::endl;
    std::cout << "산술 연산자: +, -, *, /, %" << std::endl;
    std::cout << "비교 연산자: ==, !=, <, >, <=, >=" << std::endl;
    std::cout << "논리 연산자: &&, ||, !" << std::endl;
}

bool OperatorModule::validateAnswer(const std::string& answer) {
    return isOperator(answer);
}

std::string OperatorModule::getHint() const {
    return "연산자는 수학적 계산이나 논리적 비교에 사용됩니다.";
}

std::string OperatorModule::getNextStep() const {
    return "다음 단계: 연산자 우선순위와 복합 연산을 학습합니다.";
}


// LearningModuleFactory 구현
std::unique_ptr<LearningModule> LearningModuleFactory::createModule(const std::string& moduleType) {
    if (moduleType == "variable") {
        return std::make_unique<VariableModule>();
    } else if (moduleType == "input") {
        return std::make_unique<InputModule>();
    } else if (moduleType == "operator") {
        return std::make_unique<OperatorModule>();
    }
    return nullptr;
}

std::vector<std::string> LearningModuleFactory::getAvailableModules() {
    return {"variable", "input", "operator"};
}

std::map<std::string, std::string> LearningModuleFactory::getModuleDescriptions() {
    return {
        {"variable", "Learn about variable declaration and usage"},
        {"input", "Learn about getting user input"},
        {"operator", "Learn about C++ operators"}
    };
}

// LearningPathManager 구현
void LearningPathManager::addModule(std::unique_ptr<LearningModule> module) {
    modules.push_back(std::move(module));
}

void LearningPathManager::addDependency(const std::string& moduleName, const std::string& prerequisite) {
    dependencies[moduleName].push_back(prerequisite);
}

std::vector<std::string> LearningPathManager::getAvailableModules(const std::vector<std::string>& completedModules) const {
    std::vector<std::string> available;
    for (const auto& module : modules) {
        if (module->canStart(completedModules)) {
            available.push_back(module->getName());
        }
    }
    return available;
}

std::vector<std::string> LearningPathManager::getModuleOrder() const {
    std::vector<std::string> order;
    std::vector<std::string> completed;
    
    // 간단한 위상 정렬 (실제로는 더 복잡한 알고리즘이 필요)
    for (const auto& module : modules) {
        if (module->getPrerequisites().empty()) {
            order.push_back(module->getName());
            completed.push_back(module->getName());
        }
    }
    
    for (const auto& module : modules) {
        if (std::find(order.begin(), order.end(), module->getName()) == order.end()) {
            order.push_back(module->getName());
        }
    }
    
    return order;
}

std::vector<std::string> LearningPathManager::getPrerequisites(const std::string& moduleName) const {
    auto it = dependencies.find(moduleName);
    return (it != dependencies.end()) ? it->second : std::vector<std::string>();
}

LearningModule* LearningPathManager::getModule(const std::string& moduleName) {
    for (auto& module : modules) {
        if (module->getName() == moduleName) {
            return module.get();
        }
    }
    return nullptr;
}

const LearningModule* LearningPathManager::getModule(const std::string& moduleName) const {
    for (const auto& module : modules) {
        if (module->getName() == moduleName) {
            return module.get();
        }
    }
    return nullptr;
}

void LearningPathManager::resetAllModules() {
    for (auto& module : modules) {
        module->setCompleted(false);
    }
}

std::vector<std::string> LearningPathManager::getCompletedModules() const {
    std::vector<std::string> completed;
    for (const auto& module : modules) {
        if (module->isCompleted()) {
            completed.push_back(module->getName());
        }
    }
    return completed;
}

} // namespace learning 