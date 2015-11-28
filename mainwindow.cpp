#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fila.h"

Fila *fila = new Fila;

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
    No *novoNoa = new No;
    novoNoa->numero = 2;
    novoNoa->proximo = NULL;
    fila->enqueue(novoNoa);
    No *ptr = fila->dequeue();
    int a = ptr->numero;
    ui->painel->display(a);
}
