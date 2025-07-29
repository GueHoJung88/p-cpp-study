#include "renderer/Renderer.hpp"
#include "renderer/Shader.hpp"
#include "renderer/Texture.hpp"
#include <iostream>

const float Renderer::quadVertices_[16] = {
    // positions    // texture coords
    -0.5f, -0.5f,   0.0f, 0.0f,  // bottom left
     0.5f, -0.5f,   1.0f, 0.0f,  // bottom right
     0.5f,  0.5f,   1.0f, 1.0f,  // top right
    -0.5f,  0.5f,   0.0f, 1.0f   // top left
};

const unsigned int Renderer::quadIndices_[6] = {
    0, 1, 2,  // first triangle
    2, 3, 0   // second triangle
};

Renderer::Renderer() : VAO_(0), VBO_(0), EBO_(0) {}

Renderer::~Renderer() {
    shutdown();
}

bool Renderer::initialize(int windowWidth, int windowHeight) {
    // Enable blending for sprite transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set up projection matrix
    projection_ = glm::ortho(0.0f, static_cast<float>(windowWidth), 
                           static_cast<float>(windowHeight), 0.0f, 
                           -1.0f, 1.0f);

    setupQuadBuffers();
    setupShaders();

    return true;
}

void Renderer::shutdown() {
    if (VAO_) {
        glDeleteVertexArrays(1, &VAO_);
        VAO_ = 0;
    }
    if (VBO_) {
        glDeleteBuffers(1, &VBO_);
        VBO_ = 0;
    }
    if (EBO_) {
        glDeleteBuffers(1, &EBO_);
        EBO_ = 0;
    }
}

void Renderer::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::setViewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

void Renderer::drawSprite(unsigned int textureID, const glm::vec2& position, 
                         const glm::vec2& size, float rotation) {
    auto shader = getShader("sprite");
    if (!shader) return;

    shader->use();

    // Create transformation matrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));

    // Rotate around center
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    shader->setMat4("model", model);
    shader->setMat4("projection", projection_);

    // Bind texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    shader->setInt("image", 0);

    // Draw quad
    glBindVertexArray(VAO_);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Renderer::beginBatch() {
    // For future batch rendering implementation
}

void Renderer::endBatch() {
    // For future batch rendering implementation
}

void Renderer::loadShader(const std::string& name, const std::string& vertexPath, 
                         const std::string& fragmentPath) {
    auto shader = std::make_shared<Shader>();
    if (shader->loadFromFiles(vertexPath, fragmentPath)) {
        shaders_[name] = shader;
    }
}

std::shared_ptr<Shader> Renderer::getShader(const std::string& name) {
    auto it = shaders_.find(name);
    if (it != shaders_.end()) {
        return it->second;
    }
    return nullptr;
}

unsigned int Renderer::loadTexture(const std::string& path) {
    auto texture = std::make_unique<Texture>();
    if (texture->loadFromFile(path)) {
        return texture->getID();
    }
    return 0;
}

void Renderer::setupQuadBuffers() {
    glGenVertexArrays(1, &VAO_);
    glGenBuffers(1, &VBO_);
    glGenBuffers(1, &EBO_);

    glBindVertexArray(VAO_);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices_), quadVertices_, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices_), quadIndices_, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinate attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Renderer::setupShaders() {
    // Default sprite shader
    std::string vertexShader = R"(
        #version 330 core
        layout (location = 0) in vec2 vertex;
        layout (location = 1) in vec2 tex;

        out vec2 TexCoords;

        uniform mat4 model;
        uniform mat4 projection;

        void main() {
            TexCoords = tex;
            gl_Position = projection * model * vec4(vertex, 0.0, 1.0);
        }
    )";

    std::string fragmentShader = R"(
        #version 330 core
        in vec2 TexCoords;
        out vec4 color;

        uniform sampler2D image;
        uniform vec3 spriteColor = vec3(1.0);

        void main() {
            color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
        }
    )";

    auto shader = std::make_shared<Shader>();
    if (shader->loadFromStrings(vertexShader, fragmentShader)) {
        shaders_["sprite"] = shader;
    }
}
