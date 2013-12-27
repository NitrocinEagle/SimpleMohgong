#include "game.h"
#include <iostream>

Unknown::Unknown(int _i, int _j, int _data)
{
    i = _i;
    j = _j;
    data = _data;
}

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
       {                                        //0********************0  Bords from zeros for a simplify definition
        tileArray[i][numbTilesW + 1] = 0;       //0********************0   is card blocked or isn't
        tileArray[i][0] = 0;                    //0********************0
    }                                           //0********************0
                                                   //0000000000000000000000
}

void Game::arrangementTiles()
{
    qsrand (QDateTime::currentMSecsSinceEpoch());

    int new_numbTilesH = numbTilesH +2;
    int new_numbTilesW = numbTilesW +2;

    setHelpArray(new_numbTilesH, new_numbTilesW);

    qsrand (QDateTime::currentMSecsSinceEpoch());
    int summ = 0;
    while (summ < (new_numbTilesH-2)*(new_numbTilesW-2))
    {
        for (int i = 1; i < new_numbTilesH - 1; i++)
            for (int j = 1; j < new_numbTilesW - 1; j++)
                if (isPosUnlock(i,j,A) && A[i][j] != 0)
                {
                    summ++;
                    vector.push_back(new Unknown(i,j,100));
                }

        for (int k = 0; k < vector.size(); k++)
        {
            A[vector[k]->i][vector[k]->j] = 0;
        }
        std::cout << "\n\n";
        vector.push_back(new Unknown(0,0,0));
    }


    QVector <Unknown*> mainVector;

    for (int l = 0; l < 14; l++)
    {
        int c = 0;
        int mas[new_numbTilesW];
        do
        {
            mas[c] = vector[c]->data;
            c++;
        }
        while (vector[c]->data != 0);


        for (int i = 0; i < c/2; i++)
        {
            int temp = (qrand() % numbTiles + qrand() % qrand()%10 + 1) % numbTiles + 1;
            mas[i] = temp;
            mas[c-i-1] = temp;
        }

        for (int i = 0; i < rand()%c + 3; i++)
        {
            int randIndex1 = rand()%c;
            int randIndex2 = rand()%c;
            int t;
            t = mas[randIndex1];
            mas[randIndex1] = mas[randIndex2];
            mas[randIndex2] = t;
        }

        for (int i = 0; i < c; i++)
        {
            vector[i]->data = mas[i];
            mainVector.push_back(vector[i]);
        }
        for (int i = 0; i < c+1; i++)
            vector.pop_front();
    }

    for (int i = 0; i < mainVector.size(); i++)
      tileArray[mainVector[i]->i][mainVector[i]->j] = mainVector[i]->data;

    for (int i = 0; i < mainVector.size(); i++)
        delete mainVector[i];
    for (int i = 0; i < vector.size(); i++)
        delete vector[i];
}


void Game::setImages()
{
    /*for (int i = 0; i < numbTiles; ++i)
    {
        image[i] = new QImage(":/Images/Tiles/" + QString(i ) +".jpeg");
    }*/
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

void Game::setHelpArray(int new_H, int new_W)
{
    A = new int*[new_H];
    for (int i = 0; i < new_H; ++i)
        A[i] = new int[new_W];
    for (int j = 0; j < new_W; ++j)
    {
        A[new_H -1][j] = 0;
        A[0][j] = 0;
    }

    for (int i = 0; i < new_H; ++i)
    {
        A[i][new_W -1] = 0;
        A[i][0] = 0;
    }

    for (int i = 1; i < new_H - 1; i++)
        for (int j = 1; j < new_W - 1; j++)
            A[i][j] = 1;
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

void Game::printHelpArray(int new_H, int new_W)
{
    for (int i = 0; i < new_H; i++)
    {
        for (int j = 0; j < new_W; j++)
            std::cout << A[i][j] << " ";
        std::cout << "\n";
    }
}


bool Game::isPosUnlock(int i, int j, int **A)
{
    int sum = 0;
    if (A[i-1][j] == 0)
        sum++;
    if (A[i+1][j] == 0)
        sum++;
    if (A[i][j-1] == 0)
        sum++;
    if (A[i][j+1] == 0)
        sum++;
    if (sum > 1)
        return true;
    return false;
}

Game::~Game()
{
}
