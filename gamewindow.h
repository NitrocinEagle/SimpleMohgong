#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QGraphicsView>
#include "game.h"
#include <QEvent>
#include <QMouseEvent>
class GameView : public QWidget
{
    Q_OBJECT

public:
    GameView( QWidget * parent = 0 );
    ~GameView();

    Game *game; 
private:
    QPixmap *fonImage;
public slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *pe);

};
#endif // GAMEWINDOW_H
