/*
número da conta (QString de 5 caracteres),
nome do cliente (Qstring 40 caracteres)
saldo (valor real);
*/

#include <main.h>
#include "mainwindow.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    account *myAccount = new account(QString("12345"), QString("Samuel"), 1034);

//    cout << myAccount->getAccountNumber().toStdString();
//    cout << myAccount->getClient().toStdString();
//    cout << myAccount->getBalance();

//    return 0;
}
