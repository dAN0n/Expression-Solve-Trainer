#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Right=0;
    Total=0;
    Example = new GenExpr;
    Timer = new QTimer;
    Example->Regenerate();
    ui->ExprLabel->setText(Example->OutputInLabel());

    QObject::connect(ui->NextExprButton, SIGNAL (clicked()), this, SLOT(NextExprButtonIsClicked()));
    QObject::connect(Timer, SIGNAL(timeout()), this, SLOT(NextExprButtonIsClicked()));
    QObject::connect(ui->StopTrainButton, SIGNAL (clicked()), this, SLOT(StopButtonIsClicked()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::NextExprButtonIsClicked(){
    QString Check;
    Check = ui->AnswerField->text();
    QString Answer = QString::number(Example->getAnswer());

    if(Check==Answer){
        Right++;
        ui->CheckAnswer->setText("Right!");
    }
    else ui->CheckAnswer->setText("Not right!");
    Total++;

    Example->Regenerate();
    ui->AnswerField->clear();
    ui->ExprLabel->setText(Example->OutputInLabel());
    Timer->start(10000);
}

void MainWindow::StopButtonIsClicked(){
    hide();
    emit WHide(Right, Total);

    Timer->stop();
    Example->Regenerate();
    ui->ExprLabel->setText(Example->OutputInLabel());
    Right=0;
    Total=0;
}
