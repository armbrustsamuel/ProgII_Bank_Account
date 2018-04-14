#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "account.h"
#include "transaction.h"
#include <QByteArray>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QFile * f;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pesquisarTransacoesBtn_pressed();

    void on_contasArquivoBtn_pressed();

    void on_cadastrarBtn_pressed();

    void on_transacoesArquivoBtn_pressed();

    void on_cadastrarBtn_2_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
