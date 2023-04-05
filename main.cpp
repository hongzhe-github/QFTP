
#include "ftproject.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FTProject w;
    w.show();
    return a.exec();
}
