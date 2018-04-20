#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class account
{
private:
    QString accountNumber;
    QString client;
    float balance;
public:
    account();

    QString getAccountNumber();
    QString getClient();
    float getBalance();

    void setAccountNumber(QString account);
    void setClient(QString data);
    void setBalance(float data);

    void print();
};

#endif // ACCOUNT_H
