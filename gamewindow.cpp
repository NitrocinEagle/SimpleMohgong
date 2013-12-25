#include <gamewindow.h>
#include "game.h"
#include <iostream>
GameView::GameView( QWidget *parent )
    : QWidget( parent)
{
    game = new Game;
    fonImage = new QPixmap(":/Images/Fon.jpeg");
}

GameView::~GameView()
{
}

void GameView::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->drawPixmap(0,0,width(), height(), *fonImage);


    if (game->numbActivedTiles == 2) {
        game->numbActivedTiles = 0;

        if (game->tileArray[game->activeCardOneY+1][game->activeCardOneX+1] == game->tileArray[game->activeCardTwoY+1][game->activeCardTwoX+1])
        {
            game->tileArray[game->activeCardOneY+1][game->activeCardOneX+1] = 0;
            game->tileArray[game->activeCardTwoY+1][game->activeCardTwoX+1] = 0;
        }

        game->setActiveCardToPassive();
    }

    for (int i = 1; i <= game->numbTilesH; i++) {
        for (int j = 1; j <= game->numbTilesW; j++)
            if (game->tileArray[i][j] > 0)
                painter->drawImage(25+(j-1)*40, (i-1)*54+38, *game->image[game->tileArray[i][j]-1]);
    }
    painter->setOpacity(0.5);
    if (game->activeCardOneX != -1)
    {
        painter->drawImage(game->activeCardOneX*40+25, game->activeCardOneY*54+38, *game->activeCard);
    }
    /*else
    if (game->activeCardTwoX != -1)
    {
        painter->drawImage(game->activeCardTwoX*40+25, game->activeCardTwoY*54+38, *game->activeCard);
    }*/
}

void GameView::mousePressEvent(QMouseEvent *pe)
{
    game->posX = pe->x() - 25;
    game->posY = pe->y() - 38;

    if ( (game->posX >= 0) && (game->posX <= 800) && (game->posY >= 0) && (game->posY <= 540))
    {
        if ( (game->tileArray[game->posY/54+1][game->posX/40+1] > 0) && (game->isCardUnlock()))
        {
            game->numbActivedTiles++;
        }
        else
        {
            game->setActiveCardToPassive();
            game->numbActivedTiles = 0;
        }

        if (game->numbActivedTiles == 1)
        {
            game->activeCardOneX = game->posX/40;
            game->activeCardOneY = game->posY/54;
        }
        else
        if (game->numbActivedTiles == 2)
        {
            game->activeCardTwoX = game->posX/40;
            game->activeCardTwoY = game->posY/54;
        }

        if ((game->activeCardOneX == game->activeCardTwoX) && (game->activeCardOneY == game->activeCardTwoY))
        {
            game->numbActivedTiles--;
            if (game->numbActivedTiles < 0)
                game->numbActivedTiles = 0;
            game->activeCardTwoX = 0;
            game->activeCardTwoY = 0;
        }
    }


    emit repaint();
}
