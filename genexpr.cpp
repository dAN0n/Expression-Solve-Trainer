#include "genexpr.h"

GenExpr::GenExpr():x(0), y(0), Operator(0){

}

GenExpr::~GenExpr(){

}

void GenExpr::Regenerate(){
    int *NewX = new int[15];
    int *NewY = new int[15];

    for(int i=0; i<15; i++){
        NewX[i]=i+1;
        NewY[i]=i+1;
    }

    x = NewX[rand()%14];
    y = NewY[rand()%14];

    Operator=rand()%3;
}

int GenExpr::getAnswer(){
    int Answer=0;

    switch(Operator){
    case(PLUS):
        Answer=x+y;
        break;
    case(MINUS):
        Answer=x-y;
        break;
    case(MULTIPLE):
        Answer=x*y;
    }

    return Answer;
}

QString GenExpr::OutputInLabel(){
    QString Output;
    QString xOut;
    QString yOut;
    QString OperatorSymbol;

    switch(Operator){
    case(PLUS):
        OperatorSymbol="+";
        break;
    case(MINUS):
        OperatorSymbol="-";
        break;
    case(MULTIPLE):
        OperatorSymbol="*";
    }

    xOut = QString::number(x);
    yOut = QString::number(y);
    Output=xOut+OperatorSymbol+yOut+"=?";

    return Output;
}
