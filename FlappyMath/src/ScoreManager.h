#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager {
public:
    ScoreManager();
    void increaseScore();
    void resetScore();
    int getScore() const;
    void saveHighScore();
    int getHighScore() const;

private:
    int score;
    int highScore;
    void loadHighScore();
};

#endif // SCOREMANAGER_H