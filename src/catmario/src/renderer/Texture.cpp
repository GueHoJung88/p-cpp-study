#include "renderer/Texture.hpp"
#include <iostream>
#include <vector>

// Simple image loading implementation - for production use stb_image or similar
Texture::Texture() : textureID_(0), width_(0), height_(0), nrChannels_(0) {}

Texture::~Texture() {
    if (textureID_) {
        glDeleteTextures(1, &textureID_);
    }
}

bool Texture::loadFromFile(const std::string& path) {
    // This is a simplified implementation
    // In a real project, you'd use stb_image or similar library

    // Create a simple 32x32 white texture as placeholder
    width_ = 32;
    height_ = 32;
    nrChannels_ = 4;

    std::vector<unsigned char> data(width_ * height_ * 4, 255); // White texture

    glGenTextures(1, &textureID_);
    glBindTexture(GL_TEXTURE_2D, textureID_);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    std::cout << "Loaded placeholder texture (32x32)" << std::endl;
    return true;
}

void Texture::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, textureID_);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
