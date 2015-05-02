#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
    Right = 0;
    QString _Right = QString::number(Right);
    ui->setupUi(this);
    ui->RightField->setText(_Right);
    QObject::connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(StartButtonClicked()));
    QObject::connect(&w, SIGNAL(TrainOver(int)), this, SLOT(TrainingOver(int)));

}

ResultWindow::~ResultWindow(){
    delete ui;
}

void ResultWindow::StartButtonClicked(){
    w.Timer->start(10000);
    w.setWindowTitle("Expressions Solve Trainer");
    w.show();
    hide();
}

void ResultWindow::TrainingOver(int Right){
    QString _Right = QString::number(Right);
    ui->RightField->setText(_Right);
    ui->progressBar->setValue(Right);
    show();
}
