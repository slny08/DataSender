#include "datasender.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataSender w;
    w.show();
    return a.exec();
}
