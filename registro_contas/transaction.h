/*
número da conta movimentada (cadeia de 5 caracteres),
tipo da movimentação (um caractere, podendo ser ‘S’ para saque e ‘D’ pa ra depósito)
valor da movimentação (cadeia de 10 caracteres contendo virgula para centavos ).
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>

class transaction
{
private:
    QString account;
    movTypes movimentation;
    QString value;

public:
    transaction();
    enum class movTypes
    {
        SAQUE,
        DEPOSITO
    };

    QString getAccount();
    QString getValue();
    movTypes getMovimentationType();

    setMovimentationType(movTypes mov);
    setValue(QString data);
    setAccount(QString data);
};

#endif // TRANSACTION_H
