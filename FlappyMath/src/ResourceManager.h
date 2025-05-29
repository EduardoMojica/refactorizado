class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    Texture2D loadTexture(const char* filePath);
    void unloadTexture(Texture2D texture);
    Texture2D getTexture(const char* filePath);

private:
    std::map<std::string, Texture2D> textures;
};