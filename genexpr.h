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

    int getAnswer(); //Получение ответа
    void Regenerate(); //Генерация
    QString OutputInLabel(); //Вывод строки с сгенерированным примером
};

#endif // GENEXPR_H
