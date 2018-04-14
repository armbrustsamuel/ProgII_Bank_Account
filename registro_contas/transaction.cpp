#include "transaction.h"

transaction::transaction()
{
    setAccount("");
    setValue("");
}

QString transaction::getAccount(){
    return account;
}

QString transaction::getValue(){
    return value;
}

movTypes transaction::getMovimentationType(){
    return movimentation;
}

void transaction::setAccount(QString data){
    account = data;
}

void transaction::setMovimentationType(movTypes mov){
    movimentation = mov;
}

void transaction::setValue(QString data){
    value = data;
}
