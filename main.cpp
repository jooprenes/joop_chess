#include <QtGui/QApplication>
#include "chess.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    chess foo;
    foo.show();
    return app.exec();
}
