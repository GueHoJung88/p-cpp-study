#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <map>

namespace learning {

// 학습 모듈 기본 클래스
class LearningModule {
protected:
    std::string moduleName;
    std::string description;
    int difficulty;
    bool completed;
    std::map<std::string, std::string> content;
    std::vector<std::string> prerequisites;
    
public:
    LearningModule(const std::string& name, const std::string& desc, int diff);
    virtual ~LearningModule() = default;
    
    // 기본 메서드들
    std::string getName() const { return moduleName; }
    std::string getDescription() const { return description; }
    int getDifficulty() const { return difficulty; }
    bool isCompleted() const { return completed; }
    void setCompleted(bool status) { completed = status; }
    
    // 가상 메서드들
    virtual void startLesson() = 0;
    virtual bool validateAnswer(const std::string& answer) = 0;
    virtual std::string getHint() const = 0;
    virtual std::string getNextStep() const = 0;
    virtual std::vector<std::string> getPrerequisites() const { return prerequisites; }
    
    // 콘텐츠 관리
    void addContent(const std::string& key, const std::string& value);
    std::string getContent(const std::string& key) const;
    bool hasContent(const std::string& key) const;
    
    // 전제 조건 관리
    void addPrerequisite(const std::string& moduleName);
    bool canStart(const std::vector<std::string>& completedModules) const;
};

// 변수 학습 모듈
class VariableModule : public LearningModule {
private:
    std::vector<std::string> validVariableNames;
    std::vector<std::string> invalidVariableNames;
    std::map<std::string, std::string> variableTypes;
    
public:
    VariableModule();
    
    void startLesson() override;
    bool validateAnswer(const std::string& answer) override;
    std::string getHint() const override;
    std::string getNextStep() const override;
    
    // 변수 관련 메서드들
    bool isValidVariableName(const std::string& name) const;
    std::string getVariableType(const std::string& declaration) const;
    std::vector<std::string> getValidVariableNames() const;
    std::vector<std::string> getInvalidVariableNames() const;
};

// 입력 학습 모듈
class InputModule : public LearningModule {
private:
    std::vector<std::string> validInputTypes;
    std::map<std::string, std::string> inputSyntax;
    
public:
    InputModule();
    
    void startLesson() override;
    bool validateAnswer(const std::string& answer) override;
    std::string getHint() const override;
    std::string getNextStep() const override;
    
    // 입력 관련 메서드들
    bool isValidInputMethod(const std::string& method) const;
    std::string getInputSyntax(const std::string& type) const;
    std::vector<std::string> getValidInputTypes() const;
};

// 연산자 학습 모듈
class OperatorModule : public LearningModule {
private:
    std::map<std::string, std::string> operators;
    std::map<std::string, int> operatorPrecedence;
    
public:
    OperatorModule();
    
    void startLesson() override;
    bool validateAnswer(const std::string& answer) override;
    std::string getHint() const override;
    std::string getNextStep() const override;
    
    // 연산자 관련 메서드들
    int calculateResult(const std::string& expression) const;
    bool isOperator(const std::string& op) const;
    std::string getOperatorDescription(const std::string& op) const;
    int getOperatorPrecedence(const std::string& op) const;
};

// 문자열 학습 모듈
class StringModule : public LearningModule {
private:
    std::vector<std::string> stringMethods;
    std::map<std::string, std::string> escapeSequences;
    
public:
    StringModule();
    
    void startLesson() override;
    bool validateAnswer(const std::string& answer) override;
    std::string getHint() const override;
    std::string getNextStep() const override;
    
    // 문자열 관련 메서드들
    std::string concatenateStrings(const std::string& str1, const std::string& str2) const;
    int getStringLength(const std::string& str) const;
    std::string getSubstring(const std::string& str, int start, int length) const;
    std::vector<std::string> getStringMethods() const;
    std::string getEscapeSequence(const std::string& sequence) const;
};

// 조건문 학습 모듈
class ConditionalModule : public LearningModule {
private:
    std::vector<std::string> conditionalOperators;
    std::map<std::string, std::string> conditionalSyntax;
    
public:
    ConditionalModule();
    
    void startLesson() override;
    bool validateAnswer(const std::string& answer) override;
    std::string getHint() const override;
    std::string getNextStep() const override;
    
    // 조건문 관련 메서드들
    bool evaluateCondition(const std::string& condition) const;
    std::string getConditionalSyntax(const std::string& type) const;
    std::vector<std::string> getConditionalOperators() const;
};

// 학습 모듈 팩토리
class LearningModuleFactory {
public:
    static std::unique_ptr<LearningModule> createModule(const std::string& moduleType);
    static std::vector<std::string> getAvailableModules();
    static std::map<std::string, std::string> getModuleDescriptions();
};

// 학습 경로 관리자
class LearningPathManager {
private:
    std::vector<std::unique_ptr<LearningModule>> modules;
    std::map<std::string, std::vector<std::string>> dependencies;
    
public:
    void addModule(std::unique_ptr<LearningModule> module);
    void addDependency(const std::string& moduleName, const std::string& prerequisite);
    
    std::vector<std::string> getAvailableModules(const std::vector<std::string>& completedModules) const;
    std::vector<std::string> getModuleOrder() const;
    std::vector<std::string> getPrerequisites(const std::string& moduleName) const;
    
    LearningModule* getModule(const std::string& moduleName);
    const LearningModule* getModule(const std::string& moduleName) const;
    
    void resetAllModules();
    std::vector<std::string> getCompletedModules() const;
};

} // namespace learning 