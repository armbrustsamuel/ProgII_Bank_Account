#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cadastrarBtn_pressed()
{
   QString acc = this->ui->numeroTxt->text();
   QString client = this->ui->clienteTxt->text();
   QString balance = this->ui->saldoInicialTxt->text();

   QFile g();
   f = new QFile(this->ui->arquivoContaTxt->text());

   account * oAccount = new account();
   oAccount->setAccountNumber(acc);
   oAccount->setBalance(balance.toInt());
   oAccount->setClient(client);

   if(f->open(QIODevice::WriteOnly | QIODevice::Append)){
       QDataStream ds (f);
       char BufferBytes[sizeof(account)];
       memcpy(BufferBytes, oAccount, sizeof(account));
       f->write(BufferBytes, sizeof(account));
       index++;

       f->flush();
       f->close();
   }

   this->ui->numeroTxt->clear();
   this->ui->clienteTxt->clear();
   this->ui->saldoInicialTxt->clear();
}

void MainWindow::on_cadastrarBtn_2_pressed()
{
    QFile g(this->ui->arquivoContaTxt->text());
    char BufferBytes[sizeof(account)];
    account * oAccount = new account();
    test=0;

    this->ui->transacoesPesquisadaTxt->clear();
    if(g.open(QIODevice::ReadWrite)){
        while(!g.atEnd()){
            g.seek(test*(sizeof(account)));
            g.read(BufferBytes, sizeof(account));
            memcpy(oAccount, BufferBytes, sizeof(account));
            this->ui->transacoesPesquisadaTxt->append(oAccount->getAccountNumber()+
                  " :: "+oAccount->getClient()+ " :: "+QString::number(oAccount->getBalance()));
            test++;
        }
        g.flush();
        g.close();
    }
    test = 0;

    this->ui->numeroTxt->setText(oAccount->getAccountNumber());
    this->ui->clienteTxt->setText(oAccount->getClient());
    this->ui->saldoInicialTxt->setText(QString::number(oAccount->getBalance()));
}

void MainWindow::on_pesquisarTransacoesBtn_pressed()
{
    this->ui->transacoesPesquisadaTxt->clear();
    QFile transactionFile(this->ui->arquivoTransacoesTxt->text());
    if( transactionFile.exists() ) {
        if( transactionFile.open(QIODevice::ReadWrite | QIODevice::Text) ){
            while(!transactionFile.atEnd()){
                QString line = transactionFile.readLine();
                QString account = line.mid(0,5);
                QString operation = line.mid(5,1);
                float value = line.mid(6).toFloat();
                if(account == this->ui->contaPesquisadaTxt->text()){
                    if(operation == "S"){
                        this->ui->transacoesPesquisadaTxt->append(
                                   "Conta: "+account+" "+
                                   "Operação: Crédito"+" "+
                                   "Valor: "+QString::number(value));
                    } else {
                        if(operation == "D"){
                             this->ui->transacoesPesquisadaTxt->append(
                                        "Conta: "+account+" "+
                                        "Operação: Débito"+" "+
                                        "Valor: "+QString::number(value));
                        }
                    }
                }
            }
        }
    }
    transactionFile.close();
}

///Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/3-FileStream/TGA/movimentacao.txt

void MainWindow::on_contasArquivoBtn_pressed()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/3-FileStream/TGA",
                "All files (*.*);;Binary File (*.bin)"
                );

    // Coloquei o caminho para minha pasta do projeto. Pode ser alterado para C:

    this->ui->arquivoContaTxt->setText(filename);
}

void MainWindow::on_transacoesArquivoBtn_pressed()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/3-FileStream/TGA",
                "All files (*.*);;Text File (*.txt)"
                );

    // Coloquei o caminho para minha pasta do projeto. Pode ser alterado para C:

    this->ui->arquivoTransacoesTxt->setText(filename);
}

void MainWindow::on_atualizarSaldoBtn_pressed()
{
    QFile transactionFile(this->ui->arquivoTransacoesTxt->text());
    QFile g(this->ui->arquivoContaTxt->text());
    QString line;
    QString accountNumber;
    QString operation;

    account * oAccount = new account();
    int accountFound=0;
    test=0;

    if( transactionFile.exists() ) {
        if( transactionFile.open(QIODevice::ReadWrite | QIODevice::Text) ){
            while(!transactionFile.atEnd()){
                line = transactionFile.readLine();
                accountNumber = line.mid(0,5);
                operation = line.mid(5,1);
                float value = line.mid(6).toFloat();
                accountFound = 0;

                while(accountFound == 0){
                    if(g.open(QIODevice::ReadWrite)){
                        char BufferBytes[sizeof(account)];
                        g.seek(test*(sizeof(account)));
                        g.read(BufferBytes, sizeof(account));
                        memcpy(oAccount, BufferBytes, sizeof(account));
                        if(accountNumber == oAccount->getAccountNumber()){
                            if(operation == "S"){
                                oAccount->setBalance(oAccount->getBalance() + value);
                            }
                            if(operation == "D"){
                                oAccount->setBalance(oAccount->getBalance() - value);
                            }
                            memcpy(BufferBytes, oAccount, sizeof(account));
                            g.seek(test*(sizeof(account)));
                            g.write(BufferBytes, sizeof(account));
                            accountFound = 1;
                        }
                        test++;
                        g.flush();
                        g.close();
                    }
                }
                test = 0;
            }
            transactionFile.close();
        }
    }
}
