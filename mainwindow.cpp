#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fila.h"
#include "dialog.h"
#include <QTime>

Fila *fila = new Fila;

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
    // insere um novo nó na fila
    No *novoNo = new No;
    fila->enqueue(novoNo);
    No *ptr = fila->getTail();
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
    ui->lblFixaSuaFicha->setText("Sua Ficha");
}

void MainWindow::on_btnChamar_clicked()
{

}
