#include "resultwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ResultWindow r;
    r.setWindowTitle("Expressions Solve Trainer");
    r.show();

    return a.exec();
}
