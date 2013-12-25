#include "game.h"
#include <iostream>
Game::Game()
{
    numbActivedTiles = 0;
    setActiveCardToPassive();
    createTileArray();
    setBords();
    arrangementTiles();
    setImages();
}



void Game::createTileArray()
{
    tileArray = new int*[numbTilesH+2];
    for (int i = 0; i < numbTilesH+2; ++i) {
        tileArray[i] = new int[numbTilesW+2];
    }
}

void Game::setBords()
{                                               //0000000000000000000000  Граница из нулей
    for (int j = 0; j < numbTilesW + 2; ++j)    //0********************0    сделана для
    {                                           //0********************0     значительного
        tileArray[numbTilesH + 1][j] = 0;       //0********************0      упрощения алгоритма
        tileArray[0][j] = 0;                    //0********************0       для определения
    }                                           //0********************0        блокировки карты
    for (int i = 0; i < numbTilesH + 2; ++i)    //0********************0
    {                                           //0********************0  Bords from zeros for a simplify definition
        tileArray[i][numbTilesW + 1] = 0;       //0********************0   is card blocked or isn't
        tileArray[i][0] = 0;                    //0********************0
    }                                           //0********************0
                                                //0000000000000000000000
}

void Game::arrangementTiles()
{
    qsrand (QDateTime::currentMSecsSinceEpoch());

    for (int i = 1; i <= numbTilesH; i++) {
        int rand = (qrand() % 3 + 1);
        for (int j = 1; j <= numbTilesW/2; j++) {
            int temp = (qrand() % numbTiles + rand) % numbTiles + 1;
            tileArray[i][j] = temp;
            tileArray[i][numbTilesW-j+1] = temp;
        }
    }
}


void Game::setImages()
{
    /*for (int i = 0; i < numbTiles; ++i)
    {
        image[i] = new QImage(":/Images/Tiles/" + QString(i ) +".jpeg");
    }*/  It doesn't work :( I'll finish this piece of code
    image[0] = new QImage(":/Images/Tiles/1.jpeg");
    image[1] = new QImage(":/Images/Tiles/2.jpeg");
    image[2] = new QImage(":/Images/Tiles/3.jpeg");
    image[3] = new QImage(":/Images/Tiles/4.jpeg");
    image[4] = new QImage(":/Images/Tiles/5.jpeg");
    image[5] = new QImage(":/Images/Tiles/6.jpeg");
    image[6] = new QImage(":/Images/Tiles/7.jpeg");
    image[7] = new QImage(":/Images/Tiles/8.jpeg");
    image[8] = new QImage(":/Images/Tiles/9.jpeg");
    image[9] = new QImage(":/Images/Tiles/10.jpeg");
    image[10] = new QImage(":/Images/Tiles/11.jpeg");
    image[11] = new QImage(":/Images/Tiles/12.jpeg");
    image[12] = new QImage(":/Images/Tiles/13.jpeg");
    image[13] = new QImage(":/Images/Tiles/14.jpeg");
    image[14] = new QImage(":/Images/Tiles/15.jpeg");
    image[15] = new QImage(":/Images/Tiles/16.jpeg");
    image[16] = new QImage(":/Images/Tiles/17.jpeg");
    image[17] = new QImage(":/Images/Tiles/18.jpeg");
    image[18] = new QImage(":/Images/Tiles/19.jpeg");
    image[19] = new QImage(":/Images/Tiles/20.jpeg");
    activeCard = new QImage(":/Images/Tiles/activeTile.jpeg");
}

void Game::setActiveCardToPassive()
{
    activeCardOneX = -1;
    activeCardOneY = -1;
    activeCardTwoX = -1;
    activeCardTwoY = -1;
}

bool Game::isCardUnlock()
{
    int sum = 0;
    if (tileArray[posY/54+2][posX/40+1] == 0)
        sum++;
    if (tileArray[posY/54+1][posX/40] == 0)
        sum++;
    if (tileArray[posY/54+1][posX/40+2] == 0)
        sum++;
    if (tileArray[posY/54][posX/40+1]  == 0)
        sum++;
    if (sum > 1)
        return true;
    return false;

}


Game::~Game()
{
}
