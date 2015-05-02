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
    MainWindow w;

public slots:
    void StartButtonClicked(); //Нажатие кнопки Start!
    void TrainingOver(int Right); //Конец тренировки

public:
    explicit ResultWindow(QWidget *parent = 0);
    ~ResultWindow();

private:
    Ui::ResultWindow *ui;
};

#endif // RESULTWINDOW_H
