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
    int ExampleCounter;

public slots:
    void NextExprButtonIsClicked(); //Нажатие кнопки Next Expression
    void TimerTimeout();

signals:
    void TrainOver(int Right); //Окончание тренировки

public:
    QTimer *Timer;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
