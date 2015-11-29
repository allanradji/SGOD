#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fila.h"
#include "fila_normal.h"
#include "fila_prioridade.h"
#include <QMessageBox>
#include "dialog.h"
#include <QTime>
#include <QPalette>

Fila_normal *fila_normal = new Fila_normal;
Fila_prioridade *fila_prioridade = new Fila_prioridade;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->barraDeProgresso->hide();
    QPalette palette = ui->alerta->palette();
    palette.setColor(ui->alerta->foregroundRole(), Qt::red);
    ui->alerta->setPalette(palette);
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
    ui->label_3->setText("N");
    ui->lblFixaSuaFicha->setText("Sua Ficha Normal:");
    delay(2000);
    ui->barraDeProgresso->hide();
}

void MainWindow::on_btnRetirarPrioridade_clicked() {

    // insere um novo nó na fila
    No *novoNo = new No;
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
    ui->label_3->setText("P");
    ui->lblFixaSuaFicha->setText("Sua Ficha Prioritária:");
    delay(2000);
    ui->barraDeProgresso->hide();
}


void MainWindow::on_btnChamar_clicked() // botão chamar próxima ficha
{
    if (fila_normal->isEmpty() == true){ // Verifica se a fila está vazia
        ui->alerta->setText("  A Fila normal está vazia!");
        delay(2000);
        ui->alerta->setText("");
    }else{
        ui->painel->display(fila_normal->getCabeca()->getNumero());
        ui->label_2->setText("N");
        delete fila_normal->dequeue();
    }
}

void MainWindow::on_btnChamarPrioridade_clicked()
{
    if (fila_prioridade->isEmpty() == true){ // Verifica se a fila está vazia
        ui->alerta->setText("  A Fila prioritária está vazia!");
        delay(2000);
        ui->alerta->setText("");
    }else{
        ui->painel->display(fila_prioridade->getCabeca()->getNumero());
        ui->label_2->setText("P");
        delete fila_prioridade->dequeue();
    }
}
