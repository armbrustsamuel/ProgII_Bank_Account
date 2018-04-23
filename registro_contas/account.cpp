#include "account.h"
#include <QByteArray>

account::account()
{
    setAccountNumber("");
    setClient("");
    setBalance(0);
}

account::account(QString acc, QString client, float balance){
    setAccountNumber(acc);
    setClient(client);
    setBalance(balance);
}

QString account::getAccountNumber(){
    return QString (accountNumber);
}

QString account::getClient(){
    return QString (client);
}

float account::getBalance(){
    return balance;
}

void account::setAccountNumber(QString data){
    memcpy( accountNumber, data.toStdString().c_str() ,data.size());
    accountNumber[data.size()] = 0;
}

void account::setClient(QString data){
    memcpy( client, data.toStdString().c_str() ,data.size());
    client[data.size()] = 0;
}

void account::setBalance(float data){
    balance = data;
}
