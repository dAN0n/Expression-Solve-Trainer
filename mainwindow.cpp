#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Right=0;
    ExampleCounter=1;
    QString Count = QString::number(ExampleCounter);
    Example = new GenExpr;
    Timer = new QTimer;
    Example->Regenerate();
    ui->CountLabel->setText(Count);
    ui->ExprLabel->setText(Example->OutputInLabel());

    //Нажатие кнопки Next Expression
    QObject::connect(ui->NextExprButton, SIGNAL (clicked()), this, SLOT(NextExprButtonIsClicked()));
    //Истечение таймера
    QObject::connect(Timer, SIGNAL(timeout()), this, SLOT(TimerTimeout()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::NextExprButtonIsClicked(){
    QString Check;
    Check = ui->AnswerField->text();
    QString Answer = QString::number(Example->getAnswer());

    //Сверка с ответом
    if(Check==Answer){
        Right++;
        ui->CheckAnswer->setText("Right!");
        ui->RightAnswerLabel->clear();
    }

    else{
        ui->CheckAnswer->setText("Not right! Right answer is:");
        ui->RightAnswerLabel->setText(Answer);
    }

    ExampleCounter++;

    //После показа 10 примеров
    if(ExampleCounter>10){
        ui->AnswerField->clear();
        hide();
        emit TrainOver(Right);
        Timer->stop();
        Example->Regenerate();
        ui->ExprLabel->setText(Example->OutputInLabel());
        ui->CheckAnswer->clear();
        ui->RightAnswerLabel->clear();
        Right=0;
        ExampleCounter=1;
        QString Count = QString::number(ExampleCounter);
        ui->CountLabel->setText(Count);
    }

    //Генерация нового примера и установка таймера
    else{
        Example->Regenerate();
        ui->AnswerField->clear();
        QString Count = QString::number(ExampleCounter);
        ui->CountLabel->setText(Count);
        ui->ExprLabel->setText(Example->OutputInLabel());
        Timer->start(10000);
    }
}

void MainWindow::TimerTimeout(){
    QString Answer = QString::number(Example->getAnswer());

    ui->CheckAnswer->setText("Time over! Right answer is:");
    ui->RightAnswerLabel->setText(Answer);
    ExampleCounter++;

    //После показа 10 примеров
    if(ExampleCounter>10){
        ui->AnswerField->clear();
        hide();
        emit TrainOver(Right);
        Timer->stop();
        Example->Regenerate();
        ui->ExprLabel->setText(Example->OutputInLabel());
        ui->CheckAnswer->clear();
        ui->RightAnswerLabel->clear();
        Right=0;
        ExampleCounter=1;
        QString Count = QString::number(ExampleCounter);
        ui->CountLabel->setText(Count);
    }

    //Генерация нового примера и установка таймера
    else{
        Example->Regenerate();
        ui->AnswerField->clear();
        QString Count = QString::number(ExampleCounter);
        ui->CountLabel->setText(Count);
        ui->ExprLabel->setText(Example->OutputInLabel());
        Timer->start(10000);
    }
}
