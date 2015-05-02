#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genexpr.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    GenExpr *Example;
    int Right;
    int Total;

public slots:
    void NextExprButtonIsClicked();
    void StopButtonIsClicked();

signals:
    void WHide(int Right, int Total);

public:
    QTimer *Timer;
    int getRight();
    int getTotal();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
