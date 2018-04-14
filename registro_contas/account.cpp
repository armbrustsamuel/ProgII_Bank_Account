#include "account.h"

account::account()
{
    setAccountNumber("");
    setClient("");
    setBalance(0);
}

QString account::getAccountNumber(){
    return accountNumber;
}

QString account::getClient(){
    return client;
}

double account::getBalance(){
    return balance;
}

void account::setAccountNumber(QString data){
    accountNumber = data;
}

void account::setClient(QString data){
    client = data;
}

void account::setBalance(double data){
    balance = data;
}
