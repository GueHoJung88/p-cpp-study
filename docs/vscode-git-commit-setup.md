# VSCode Git Commit 설정 가이드 / VSCode Git Commit Setup Guide

## 한국어 버전 / Korean Version

### 1. VSCode를 Git Commit 메시지 기본 에디터로 설정하기

#### 1.1 전역 설정 (Global Configuration)

```bash
# VSCode를 기본 에디터로 설정
git config --global core.editor "code --wait"

# 설정 확인
git config --global core.editor
```

#### 1.2 프로젝트별 설정 (Project-specific Configuration)

```bash
# 현재 프로젝트에서만 VSCode를 기본 에디터로 설정
git config core.editor "code --wait"

# 설정 확인
git config core.editor
```

#### 1.3 VSCode 설정 파일을 통한 설정

`.vscode/settings.json` 파일을 생성하거나 수정:

```json
{
    "git.editor": "code --wait"
}
```

### 2. 커스텀 커밋 메시지 템플릿 설정하기

#### 2.1 .gitmessage.txt 템플릿 파일 생성

프로젝트 루트 디렉토리에 `.gitmessage.txt` 파일을 생성:

```txt
# <타입>: <제목>
# 
# <본문>
# 
# <푸터>

# 타입 종류:
# feat: 새로운 기능
# fix: 버그 수정
# docs: 문서 수정
# style: 코드 포맷팅, 세미콜론 누락 등
# refactor: 코드 리팩토링
# test: 테스트 코드 추가/수정
# chore: 빌드 업무 수정, 패키지 매니저 수정 등

# 제목 규칙:
# - 50자 이내
# - 첫 글자는 대문자
# - 마지막에 마침표 금지

# 본문 규칙:
# - 72자 이내로 줄바꿈
# - 무엇을 왜 변경했는지 설명

# 푸터 규칙:
# - 이슈 번호 참조 (예: Closes #123)
# - Breaking Changes 설명
```

#### 2.2 Git 설정으로 템플릿 적용

```bash
# 전역 설정
git config --global commit.template .gitmessage.txt

# 프로젝트별 설정
git config commit.template .gitmessage.txt

# 설정 확인
git config commit.template
```

### 3. 사용 방법

#### 3.1 커밋 메시지 작성

```bash
# 커밋 시 VSCode가 자동으로 열림
git commit

# 또는 메시지와 함께 커밋
git commit -m "feat: 새로운 기능 추가"
```

#### 3.2 템플릿 사용 예시

```bash
# 커밋 시 .gitmessage.txt 템플릿이 자동으로 로드됨
git commit
```

VSCode에서 다음과 같은 내용이 미리 작성되어 있음:

```
# <타입>: <제목>
# 
# <본문>
# 
# <푸터>

# 타입 종류:
# feat: 새로운 기능
# fix: 버그 수정
# docs: 문서 수정
# style: 코드 포맷팅, 세미콜론 누락 등
# refactor: 코드 리팩토링
# test: 테스트 코드 추가/수정
# chore: 빌드 업무 수정, 패키지 매니저 수정 등

# 제목 규칙:
# - 50자 이내
# - 첫 글자는 대문자
# - 마지막에 마침표 금지

# 본문 규칙:
# - 72자 이내로 줄바꿈
# - 무엇을 왜 변경했는지 설명

# 푸터 규칙:
# - 이슈 번호 참조 (예: Closes #123)
# - Breaking Changes 설명
```

### 4. 추가 설정 및 팁

#### 4.1 VSCode Git 확장 프로그램

VSCode에서 Git 작업을 더욱 편리하게 하기 위해 다음 확장 프로그램을 설치:

- GitLens
- Git Graph
- Git History

#### 4.2 커밋 메시지 검증

`.git/hooks/commit-msg` 파일을 생성하여 커밋 메시지 형식을 검증:

```bash
#!/bin/sh
# 커밋 메시지 형식 검증 스크립트
# 예: feat:, fix:, docs: 등으로 시작하는지 확인
```

#### 4.3 설정 확인 명령어

```bash
# 모든 Git 설정 확인
git config --list

# 특정 설정 확인
git config --global --get core.editor
git config --global --get commit.template
```

---

## English Version

### 1. Setting VSCode as Default Editor for Git Commit Messages

#### 1.1 Global Configuration

```bash
# Set VSCode as default editor
git config --global core.editor "code --wait"

# Verify configuration
git config --global core.editor
```

#### 1.2 Project-specific Configuration

```bash
# Set VSCode as default editor for current project only
git config core.editor "code --wait"

# Verify configuration
git config core.editor
```

#### 1.3 Configuration via VSCode Settings

Create or modify `.vscode/settings.json`:

```json
{
    "git.editor": "code --wait"
}
```

### 2. Setting Custom Commit Message Template

#### 2.1 Create .gitmessage.txt Template File

Create `.gitmessage.txt` file in the project root directory:

```txt
# <type>: <subject>
# 
# <body>
# 
# <footer>

# Type categories:
# feat: new feature
# fix: bug fix
# docs: documentation changes
# style: code formatting, missing semicolons, etc.
# refactor: code refactoring
# test: adding or modifying test code
# chore: build process changes, package manager changes, etc.

# Subject rules:
# - Maximum 50 characters
# - Start with capital letter
# - No period at the end

# Body rules:
# - Wrap at 72 characters
# - Explain what and why, not how

# Footer rules:
# - Reference issue numbers (e.g., Closes #123)
# - Describe breaking changes
```

#### 2.2 Apply Template via Git Configuration

```bash
# Global configuration
git config --global commit.template .gitmessage.txt

# Project-specific configuration
git config commit.template .gitmessage.txt

# Verify configuration
git config commit.template
```

### 3. Usage Instructions

#### 3.1 Writing Commit Messages

```bash
# VSCode opens automatically when committing
git commit

# Or commit with message
git commit -m "feat: add new feature"
```

#### 3.2 Template Usage Example

```bash
# Template is automatically loaded when committing
git commit
```

The following content is pre-written in VSCode:

```
# <type>: <subject>
# 
# <body>
# 
# <footer>

# Type categories:
# feat: new feature
# fix: bug fix
# docs: documentation changes
# style: code formatting, missing semicolons, etc.
# refactor: code refactoring
# test: adding or modifying test code
# chore: build process changes, package manager changes, etc.

# Subject rules:
# - Maximum 50 characters
# - Start with capital letter
# - No period at the end

# Body rules:
# - Wrap at 72 characters
# - Explain what and why, not how

# Footer rules:
# - Reference issue numbers (e.g., Closes #123)
# - Describe breaking changes
```

### 4. Additional Settings and Tips

#### 4.1 VSCode Git Extensions

Install the following extensions for more convenient Git operations in VSCode:

- GitLens
- Git Graph
- Git History

#### 4.2 Commit Message Validation

Create `.git/hooks/commit-msg` file to validate commit message format:

```bash
#!/bin/sh
# Commit message format validation script
# Example: Check if it starts with feat:, fix:, docs:, etc.
```

#### 4.3 Configuration Verification Commands

```bash
# Check all Git configurations
git config --list

# Check specific configurations
git config --global --get core.editor
git config --global --get commit.template
```

### 5. Troubleshooting

#### 5.1 Common Issues

1. **VSCode doesn't open**: Check if `code` command is in PATH
2. **Template not loading**: Verify file path and Git configuration
3. **Permission issues**: Ensure proper file permissions

#### 5.2 Useful Commands

```bash
# Check if code command is available
which code

# Test VSCode editor
code --version

# Reset Git configuration
git config --global --unset core.editor
git config --global --unset commit.template
```

---

## 파일 구조 / File Structure

```
project-root/
├── .gitmessage.txt          # 커밋 메시지 템플릿
├── .vscode/
│   └── settings.json        # VSCode 설정
└── docs/
    └── vscode-git-commit-setup.md  # 이 문서
```

## 참고 자료 / References

- [Git Configuration Documentation](https://git-scm.com/docs/git-config)
- [VSCode Git Integration](https://code.visualstudio.com/docs/editor/versioncontrol)
- [Conventional Commits Specification](https://www.conventionalcommits.org/) 