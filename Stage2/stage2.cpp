#include "lamp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LampWidget w;
    w.show();
    return a.exec();
}
