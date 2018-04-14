#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class account
{
private:
    QString accountNumber;
    QString client;
    double balance;
public:
    account();

    QString getAccountNumber();
    QString getClient();
    double getBalance();

    void setAccountNumber(QString account);
    void setClient(QString data);
    void setBalance(double data);

    void print();
};

#endif // ACCOUNT_H
