#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class account
{
private:
    char accountNumber[6];
    char client[41];
    float balance;
public:
    account();
    account(QString acc, QString client, float balance);

    QString getAccountNumber();
    QString getClient();
    float getBalance();

    void setAccountNumber(QString account);
    void setClient(QString data); //const QString &data
    void setBalance(float data);

    void print();
};

#endif // ACCOUNT_H
