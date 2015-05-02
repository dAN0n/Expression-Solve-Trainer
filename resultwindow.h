#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QDialog
{
    Q_OBJECT
    int Right;
    int Total;
    MainWindow w;

public slots:
    void StartButtonClicked();
    void WHided(int Right, int Total);

public:
    explicit ResultWindow(QWidget *parent = 0);
    ~ResultWindow();

private:
    Ui::ResultWindow *ui;
};

#endif // RESULTWINDOW_H
