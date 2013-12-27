#ifndef GAME_H
#define GAME_H

#include <QDateTime>
#include <QImage>
#include <QVector>

struct Unknown
{
//public:
    int i, j;
    int data;
    Unknown(int _i, int _j, int _data);
};

class Game
{
public:
    Game();
    ~Game();
    void arrangementTiles();
    void setBords();
    void createTileArray();
    void setImages();

    void setHelpArray(int new_H, int new_W);
    void setActiveCardToPassive();
    bool isCardUnlock();

    void printHelpArray(int new_H, int new_W);
    bool isPosUnlock(int i, int j, int **A);
    int **tileArray;
    const static int numbTiles = 20;
    const static int numbTilesW = 20;
    const static int numbTilesH = 10;
    QImage *image[numbTiles];
    QImage *activeCard;
    int posX, posY;
    int activeCardOneX;
    int activeCardOneY;
    int activeCardTwoX;
    int activeCardTwoY;
    int numbActivedTiles;
      int **A;
    QVector <Unknown*> vector;
private:


};

#endif // GAME_H
