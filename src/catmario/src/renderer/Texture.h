#pragma once
#include <glad/glad.h>
#include <string>

class Texture {
public:
    Texture();
    ~Texture();

    bool loadFromFile(const std::string& path);
    void bind(unsigned int slot = 0) const;
    void unbind() const;

    unsigned int getID() const { return textureID_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }

private:
    unsigned int textureID_;
    int width_;
    int height_;
    int nrChannels_;
};
