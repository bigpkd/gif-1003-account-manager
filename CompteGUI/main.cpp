#include "comptegui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CompteGUI w;
    w.show();
    return a.exec();
}
