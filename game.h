#ifndef GAME_H
#define GAME_H

#include <QDateTime>
#include <QImage>

class Game
{
public:
    Game();
    ~Game();
    void arrangementTiles();
    void setBords();
    void createTileArray();
    void setImages();

    void setActiveCardToPassive();
    bool isCardUnlock();
    bool isTwoCardUnlock();
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
private:


};

#endif // GAME_H
