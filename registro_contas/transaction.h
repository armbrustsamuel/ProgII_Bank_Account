/*
número da conta movimentada (cadeia de 5 caracteres),
tipo da movimentação (um caractere, podendo ser ‘S’ para saque e ‘D’ pa ra depósito)
valor da movimentação (cadeia de 10 caracteres contendo virgula para centavos ).
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>

enum class movTypes
{
    SAQUE,
    DEPOSITO
};

class transaction
{
private:
    QString account;
    movTypes movimentation;
    QString value;

public:
    transaction();


    QString getAccount();
    QString getValue();
    movTypes getMovimentationType();

    void setMovimentationType(movTypes mov);
    void setValue(QString data);
    void setAccount(QString data);
};

#endif // TRANSACTION_H
