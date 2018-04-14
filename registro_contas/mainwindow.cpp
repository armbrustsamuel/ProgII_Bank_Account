#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    f = new QFile("/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGA/contas.bin");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
//    f->close();
    delete ui;
}

void MainWindow::on_cadastrarBtn_pressed()
{
   QString acc = this->ui->numeroTxt->text();
   QString client = this->ui->clienteTxt->text();
   QString balance = this->ui->saldoInicialTxt->text();

//   if( !f.exists() ) {
//       ui->contentText->setText("Arquivo não Existe.");
//       return;
//   }

   f = new QFile(this->ui->arquivoContaTxt->text());

   f->open(QIODevice::WriteOnly);

   QDataStream ds (f);

   ds.device()->seek(0);

   account * oAccount = new account();
   oAccount->setAccountNumber(acc);
   oAccount->setBalance(balance.toInt());
   oAccount->setClient(client);

   ds.device()->seek(0);

   char BufferBytes[sizeof(account)]; //Cria um buffer temporário de bytes no tamanho do objeto

   memcpy(BufferBytes, oAccount, sizeof(account)); //Copia os bytes do objeto para o buffer de bytes

   ds.writeRawData(BufferBytes, sizeof(account)); // grava o buffer contendo os bytes do objeto no arquivo através do stream. (também pode ser feito com o método write do Qfile)

   this->ui->numeroTxt->clear();
   this->ui->clienteTxt->clear();
   this->ui->saldoInicialTxt->clear();

   f->close();
}

void MainWindow::on_cadastrarBtn_2_pressed()
{

//    if( !f.exists() ) {
//        ui->contentText->setText("Arquivo não Existe.");
//        return;
//    }
    f = new QFile(this->ui->arquivoContaTxt->text());

    f->open(QIODevice::ReadOnly);

    QDataStream ds (f);

    ds.device()->seek(0);

    account * oAccount = new account();

    char BufferBytes[sizeof(account)]; //Cria um buffer temporário de bytes no tamanho do objeto

    ds.readRawData(BufferBytes, sizeof(account));

    memcpy(oAccount, BufferBytes, sizeof(account)); //Copia os bytes do objeto para o buffer de bytes

    this->ui->numeroTxt->setText(oAccount->getAccountNumber());
    this->ui->clienteTxt->setText(oAccount->getClient());
    this->ui->saldoInicialTxt->setText(QString::number(oAccount->getBalance()));

    f->close();
}

void MainWindow::on_pesquisarTransacoesBtn_pressed()
{

}

void MainWindow::on_contasArquivoBtn_pressed()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGA/",
                "All files (*.*);;Binary File (*.bin)"
                );

    this->ui->arquivoContaTxt->setText(filename);
}

void MainWindow::on_transacoesArquivoBtn_pressed()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGA/",
                "All files (*.*);;Text File (*.txt)"
                );

    this->ui->arquivoTransacoesTxt->setText(filename);
}
