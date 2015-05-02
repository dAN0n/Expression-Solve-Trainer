#ifndef GENEXPR_H
#define GENEXPR_H
#include <QString>
#include <QTime>

enum OperatorType{
    PLUS,
    MINUS,
    MULTIPLE
//    DIVISION
};

class GenExpr{
    int x;
    int y;
    int Operator;
public:
    GenExpr();
    ~GenExpr();

    int getAnswer();
    void Regenerate();
    QString OutputInLabel();
};

#endif // GENEXPR_H
