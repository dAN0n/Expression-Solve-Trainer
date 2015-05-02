#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
    Right = 0;
    Total = 0;
    QString _Right = QString::number(Right);
    QString _Total = QString::number(Total);
    ui->setupUi(this);
    ui->RightField->setText(_Right);
    ui->TotalField->setText(_Total);
    QObject::connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(StartButtonClicked()));
    QObject::connect(&w, SIGNAL(WHide(int,int)), this, SLOT(WHided(int,int)));

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

void ResultWindow::WHided(int Right, int Total){
    QString _Right = QString::number(Right);
    QString _Total = QString::number(Total);
    ui->RightField->setText(_Right);
    ui->TotalField->setText(_Total);
    double Right_ = Right;
    double Total_ = Total;
    double Progress = (Right_/Total_)*100;
    ui->progressBar->setValue(Progress);
    show();
}
