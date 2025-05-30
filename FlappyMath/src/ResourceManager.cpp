#include "ResourceManager.h"
#include "raylib.h"
#include <unordered_map>
#include <string>

class ResourceManager {
public:
    ResourceManager() = default;
    ~ResourceManager() {
        unloadAllResources();
    }

    Texture2D loadTexture(const std::string& filePath) {
        Texture2D texture = LoadTexture(filePath.c_str());
        textures[filePath] = texture;
        return texture;
    }

    void unloadTexture(const std::string& filePath) {
        if (textures.find(filePath) != textures.end()) {
            UnloadTexture(textures[filePath]);
            textures.erase(filePath);
        }
    }

    Texture2D getTexture(const std::string& filePath) {
        if (textures.find(filePath) != textures.end()) {
            return textures[filePath];
        }
        return Texture2D(); // Return an empty texture if not found
    }

    void unloadAllResources() {
        for (auto& pair : textures) {
            UnloadTexture(pair.second);
        }
        textures.clear();
    }

private:
    std::unordered_map<std::string, Texture2D> textures;
};