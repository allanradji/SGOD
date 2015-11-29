#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fila.h"
#include "fila_normal.h"
#include "fila_prioridade.h"
#include <QMessageBox>

Fila_normal *fila_normal = new Fila_normal;
Fila_prioridade *fila_prioridade = new Fila_prioridade;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRetirar_clicked()
{
    //abrir uma nova janela com as opções de retirar ficha preferencial ou normal

    No *novoNoa = new No;
    novoNoa->numero = 2;
    novoNoa->proximo = NULL;
    //se foi selecionado ficha normal
    if(true){
        fila_normal->enqueue(novoNoa);
        No *ptr = fila_normal->dequeue();
        int a = ptr->numero;
        ui->painel->display(a);
    }
    //se foi selecionado ficha prioridade
    if(false){
        fila_prioridade->enqueue(novoNoa);
        No *ptr = fila_prioridade->dequeue();
        int a = ptr->numero;
        ui->painel->display(a);
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
