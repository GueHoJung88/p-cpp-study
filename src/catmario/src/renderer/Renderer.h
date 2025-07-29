#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <functional>
#include <unordered_map>
#include <memory>

class Shader;
class Texture;

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool initialize(int windowWidth, int windowHeight);
    void shutdown();

    void clear(float r = 0.2f, float g = 0.3f, float b = 0.8f, float a = 1.0f);
    void setViewport(int x, int y, int width, int height);

    void drawSprite(unsigned int textureID, const glm::vec2& position, 
                    const glm::vec2& size, float rotation = 0.0f);

    void beginBatch();
    void endBatch();

    // Shader management
    void loadShader(const std::string& name, const std::string& vertexPath, 
                    const std::string& fragmentPath);
    std::shared_ptr<Shader> getShader(const std::string& name);

    // Texture management
    unsigned int loadTexture(const std::string& path);

private:
    struct SpriteVertex {
        glm::vec2 position;
        glm::vec2 texCoords;
    };

    void setupQuadBuffers();
    void setupShaders();

    // OpenGL objects
    unsigned int VAO_, VBO_, EBO_;

    // Shader storage
    std::unordered_map<std::string, std::shared_ptr<Shader>> shaders_;

    // Default quad vertices
    static const float quadVertices_[16];
    static const unsigned int quadIndices_[6];

    // Projection matrix
    glm::mat4 projection_;
};
