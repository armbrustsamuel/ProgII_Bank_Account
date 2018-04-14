/*
número da conta (QString de 5 caracteres),
nome do cliente (Qstring 40 caracteres)
saldo (valor real);
*/

#include <main.h>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
