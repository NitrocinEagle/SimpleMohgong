
#ifndef WINDOW_H
#define WINDOW_H

#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include "gamewindow.h"

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~Window();

private:
    const static int width = 850;
    const static int height = 590;
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createGameWindow();
    void createWindow();

    GameView *gameWindow;

    QAction *aNewGame;
    QAction *aSaveGame;
    QAction *aLoadGame;
    QAction *aStatictic;
    QAction *aExit;

    QMenu *mGame;

    QToolBar *tNewGame;
    QToolBar *tLoadGame;
    QToolBar *tSaveGame;
    QToolBar *tStatictic;
    QToolBar *tExit;



public slots:
    void newGame();
    void loadGame();
    void saveGame();
    void statictic();
    void exitGame();
};

#endif // WINDOW_H
