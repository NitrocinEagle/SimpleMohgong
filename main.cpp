#include <QApplication>
#include <QCleanlooksStyle>
#include <QTextCodec>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle(new QCleanlooksStyle);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("Unicode"));

    Window w;
    w.show();

    return app.exec();
}
