#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fila.h"
#include "fila_normal.h"
#include "fila_prioridade.h"
#include <QMessageBox>
#include "dialog.h"
#include <QTime>

Fila_normal *fila_normal = new Fila_normal;
Fila_prioridade *fila_prioridade = new Fila_prioridade;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->barraDeProgresso->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}


void MainWindow::on_btnRetirar_clicked()
{
    //abrir uma nova janela com as opções de retirar ficha preferencial ou normal

    No *novoNo = new No;
    //se foi selecionado ficha normal
    if(true){
        // insere um novo nó na fila
        fila_normal->enqueue(novoNo);
        No *ptr = fila_normal->getTail();
        int n = ptr->getNumero();
        // Simula impressão da ficha e exibe-a
        ui->lblFixaSuaFicha->setText("Imprimindo...");
        ui->barraDeProgresso->setValue(0);
        ui->barraDeProgresso->show();
        delay(500);
        ui->barraDeProgresso->setValue(25);
        delay(500);
        ui->barraDeProgresso->setValue(50);
        delay(500);
        ui->barraDeProgresso->setValue(75);
        delay(500);
        ui->barraDeProgresso->setValue(100);
        ui->painelRetirarFicha->display(n);
        ui->lblFixaSuaFicha->setText("Sua Ficha Normal");
    }
    //se foi selecionado ficha prioridade
    if(false){
        // insere um novo nó na fila
        fila_prioridade->enqueue(novoNo);
        No *ptr = fila_prioridade->getTail();
        int n = ptr->getNumero();
        // Simula impressão da ficha e exibe-a
        ui->lblFixaSuaFicha->setText("Imprimindo...");
        ui->barraDeProgresso->setValue(0);
        ui->barraDeProgresso->show();
        delay(500);
        ui->barraDeProgresso->setValue(25);
        delay(500);
        ui->barraDeProgresso->setValue(50);
        delay(500);
        ui->barraDeProgresso->setValue(75);
        delay(500);
        ui->barraDeProgresso->setValue(100);
        ui->painelRetirarFicha->display(n);
        ui->lblFixaSuaFicha->setText("Sua Ficha Prioritária");
    }
}

void MainWindow::on_btnChamar_clicked()
{
    if(fila_normal->possui_Espera() == true) {

        //verifica o último chamado

        //se o último chamado foi normal e ainda tem preferencial, avisa que  deve chamar preferencial

        //senão, chama o próximo normal

        //ui->painel->display(a);
    }
    else{
        QMessageBox::information(NULL, "Aviso", "Não há ficha normal na espera");
    }
}

void MainWindow::on_btnChamarPrioridade_clicked()
{
    if(fila_prioridade->possui_Espera() == true){
        //verifica o último chamado

        //se o último chamado foi prefernecial e ainda tem normal, avisa que  deve chamar um normal

        //senão, chama o próximo preferencial

        //ui->painel->display(a);
    }
    else{
        QMessageBox::information(NULL, "Aviso", "Não há ficha prioridade na espera");
    }
}
