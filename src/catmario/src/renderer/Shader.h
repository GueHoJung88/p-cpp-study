#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

class Shader {
public:
    Shader();
    ~Shader();

    bool loadFromFiles(const std::string& vertexPath, const std::string& fragmentPath);
    bool loadFromStrings(const std::string& vertexSource, const std::string& fragmentSource);

    void use() const;

    // Uniform setters
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setMat4(const std::string& name, const glm::mat4& value) const;

    unsigned int getID() const { return programID_; }

private:
    unsigned int programID_;

    std::string readFile(const std::string& filePath);
    unsigned int compileShader(unsigned int type, const std::string& source);
    bool linkProgram(unsigned int vertex, unsigned int fragment);
    void checkCompileErrors(unsigned int shader, const std::string& type);
};
