#!/bin/bash

# Ubuntu 24.04 Super Mario ECS 프로젝트 빌드 스크립트

echo "=== Super Mario ECS 프로젝트 빌드 스크립트 ==="
echo "Ubuntu 24.04 환경용"
echo ""

# 의존성 설치
echo "1. 시스템 의존성 설치 중..."
sudo apt update
sudo apt install -y build-essential cmake pkg-config
sudo apt install -y libsdl2-dev libsdl2-2.0-0
sudo apt install -y libglm-dev
sudo apt install -y freeglut3-dev libgl1-mesa-dev

echo ""
echo "2. GLAD 라이브러리 설정 중..."

# GLAD 다운로드 (웹 서비스에서 생성한 파일 사용)
if [ ! -d "glad" ]; then
    echo "GLAD 파일을 수동으로 다운로드해야 합니다:"
    echo "1. https://glad.dav1d.de/ 접속"
    echo "2. OpenGL Version: 3.3, Profile: Core 선택"
    echo "3. Generate 버튼 클릭"
    echo "4. 다운로드한 파일을 프로젝트 루트에 'glad' 폴더로 압축 해제"
    echo ""
    echo "또는 다음 명령어로 기본 GLAD 구조 생성:"
    mkdir -p glad/include/glad
    mkdir -p glad/include/KHR
    mkdir -p glad/src

    # 간단한 GLAD 헤더 파일 생성 (실제로는 웹에서 생성해야 함)
    cat > glad/include/glad/glad.h << 'EOF'
#ifndef __glad_h_
#define __glad_h_

#ifdef __gl_h_
#error OpenGL header already included, remove this include, glad already provides it
#endif

#define __gl_h_

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifndef GLAPI
#define GLAPI extern
#endif

struct gladGLversionStruct {
    int major;
    int minor;
};

typedef void* (* GLADloadproc)(const char *name);

GLAPI struct gladGLversionStruct GLVersion;

GLAPI int gladLoadGL(void);
GLAPI int gladLoadGLLoader(GLADloadproc);

#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
#define GLEXT_64_TYPES_DEFINED
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
#endif

// OpenGL 함수들 (실제 GLAD에서는 더 많은 함수가 포함됨)
typedef void (APIENTRYP PFNGLCLEARPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);

GLAPI PFNGLCLEARPROC glad_glClear;
GLAPI PFNGLCLEARCOLORPROC glad_glClearColor;
GLAPI PFNGLVIEWPORTPROC glad_glViewport;

#define glClear glad_glClear
#define glClearColor glad_glClearColor  
#define glViewport glad_glViewport

// 다른 필요한 OpenGL 함수들을 여기에 추가...

#endif
EOF

    cat > glad/src/glad.c << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/glad.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

struct gladGLversionStruct GLVersion = { 0, 0 };

// 함수 포인터들
PFNGLCLEARPROC glad_glClear = NULL;
PFNGLCLEARCOLORPROC glad_glClearColor = NULL;
PFNGLVIEWPORTPROC glad_glViewport = NULL;

static void load_GL_VERSION_1_0(GLADloadproc load) {
    if(!GLAD_GL_VERSION_1_0) return;
    glad_glClear = (PFNGLCLEARPROC)load("glClear");
    glad_glClearColor = (PFNGLCLEARCOLORPROC)load("glClearColor");
    glad_glViewport = (PFNGLVIEWPORTPROC)load("glViewport");
}

int gladLoadGLLoader(GLADloadproc load) {
    GLVersion.major = 3; GLVersion.minor = 3;
    load_GL_VERSION_1_0(load);
    return GLVersion.major != 0 || GLVersion.minor != 0;
}

int gladLoadGL(void) {
    return gladLoadGLLoader(NULL);
}
EOF

    echo "기본 GLAD 파일이 생성되었습니다. 완전한 기능을 위해서는 https://glad.dav1d.de/에서 생성한 파일로 교체하세요."
fi

echo ""
echo "3. 빌드 디렉터리 생성 및 빌드..."

# 빌드 디렉터리 생성
mkdir -p build
cd build

# CMake 실행
cmake ..
if [ $? -ne 0 ]; then
    echo "CMake 구성 실패!"
    exit 1
fi

# 빌드 실행
make -j$(nproc)
if [ $? -ne 0 ]; then
    echo "빌드 실패!"
    exit 1
fi

echo ""
echo "=== 빌드 완료! ==="
echo "실행 파일: ./SuperMario"
echo ""
echo "실행하려면: cd build && ./SuperMario"
