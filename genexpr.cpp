#include "genexpr.h"

GenExpr::GenExpr():x(0), y(0), Operator(0){

}

GenExpr::~GenExpr(){

}

void GenExpr::Regenerate(){
    Operator=rand()%3;
    switch(Operator){
    case(PLUS):
        x=-1000 + rand()%2001;
        y=-1000 + rand()%2001;
        if(y<0){
            Operator=MINUS;
            y+=2*(-y);
        }
        break;

    case(MINUS):
        x=-1000 + rand()%2001;
        y=-1000 + rand()%2001;
        if(y<0){
            Operator=PLUS;
            y+=2*(-y);
        }
        break;

    case(MULTIPLE):
        x=-20 + rand()%41;
        y=-20 + rand()%41;
        break;
    }
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
