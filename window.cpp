#include "window.h"


Window::Window(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createGameWindow();
    createWindow();
}

Window::~Window() { }

void Window::createActions()
{
    aExit = new QAction(QIcon(":/Images/Icons/aExit.jpeg"), tr("E&xit"), this);
    aExit->setShortcut(tr("Ctrl+X"));
    aExit->setStatusTip(tr("Exit from game"));

    aNewGame = new QAction(QIcon(":/Images/Icons/aNewGame.jpeg"), tr("Ne&w Game"), this);
    aNewGame->setShortcut(tr("Ctrl+N"));
    aNewGame->setStatusTip(tr("Start new game"));

    aLoadGame = new QAction(QIcon(":/Images/Icons/aLoadGame.jpeg"), tr("Loa&d Game"), this);
    aLoadGame->setShortcut(tr("Ctrl+L"));
    aLoadGame->setStatusTip(tr("Load game"));

    aSaveGame = new QAction(QIcon(":/Images/Icons/aSaveGame.jpeg"), tr("Sa&ve Game"), this);
    aSaveGame->setShortcut(tr("Ctrl+S"));
    aSaveGame->setStatusTip(tr("Save game"));

    aStatictic = new QAction(QIcon(":/Images/Icons/aStatistic.jpeg"), tr("Sta&tistic"), this);
    aStatictic->setShortcut(tr("Ctrl+R"));
    aStatictic->setStatusTip(tr("Game's statistic"));


    connect(aNewGame, SIGNAL( triggered() ), this, SLOT( newGame() ));
    connect(aLoadGame, SIGNAL( triggered() ), this, SLOT( loadGame() ));
    connect(aSaveGame, SIGNAL( triggered() ), this, SLOT( saveGame() ));
    connect(aStatictic, SIGNAL( triggered() ), this, SLOT( statictic() ));
    connect(aExit, SIGNAL( triggered() ), this, SLOT( exitGame() ));
}

void Window::createMenus()
{
    mGame = menuBar()->addMenu(tr("&Game"));
    mGame->addAction(aExit);
}

void Window::createToolBars()
{
    tNewGame = new QToolBar(tr("New Game"));
    tLoadGame = new QToolBar(tr("Load Game"));
    tSaveGame = new QToolBar(tr("Save Game"));
    tStatictic = new QToolBar(tr("Statictic"));
    tExit = new QToolBar(tr("Exit"));

    tNewGame->setMovable(false);
    tLoadGame->setMovable(false);
    tSaveGame->setMovable(false);
    tStatictic->setMovable(false);
    tExit->setMovable(false);

    tNewGame->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tLoadGame->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tSaveGame->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tStatictic->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    addToolBar(Qt::TopToolBarArea, tNewGame);
    tNewGame->addAction(aNewGame);

    addToolBar(Qt::TopToolBarArea, tLoadGame);
    tLoadGame->addAction(aLoadGame);

    addToolBar(Qt::TopToolBarArea, tSaveGame);
    tSaveGame->addAction(aSaveGame);

    addToolBar(Qt::TopToolBarArea, tStatictic);
    tStatictic->addAction(aStatictic);

    addToolBar(Qt::TopToolBarArea, tExit);
    tExit->addAction(aExit);
}

void Window::createStatusBar()
{
    statusBar()->showMessage(tr("Application is launched"), 2000);
}

void Window::createGameWindow()
{
    gameWindow = new GameView(this);
    gameWindow->setFixedSize(width, height);
}

void Window::createWindow()
{
    setCentralWidget(gameWindow);
    setWindowTitle(tr("Mohjong"));
    setWindowIcon(QIcon(":/Images/Icons/blink.png"));

}

void Window::newGame()
{
    gameWindow->game->setBords();
    gameWindow->game->arrangementTiles();
    emit repaint();
}

void Window::loadGame()
{
}

void Window::saveGame()
{
}

void Window::statictic()
{
}
void Window::exitGame()
{
    qApp->exit();
}
