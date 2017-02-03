#include "mywindow.h"
#include <QApplication>
#include <math.h>
#include <QDebug>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWindow w;
    w.show();

    return a.exec();
}
