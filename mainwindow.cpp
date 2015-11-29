#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fila.h"
#include "dialog.h"
#include <QTime>

Fila *fila = new Fila;
No *atual = NULL;

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
    ui->lblFixaSuaFicha->setText("Sua Ficha:");
    delay(2000);
    ui->barraDeProgresso->hide();
}

void MainWindow::on_btnChamar_clicked() // botão chamar próxima ficha
{
    if (fila->isEmpty() == true){ // Verifica se a fila está vazia
        ui->alerta->setText("  A Fila está vazia!");
        delay(2000);
        ui->alerta->setText("");
    }else{
        if (fila->getCabeca()->getProximo() == NULL){ // verifica se na fila existe somente 1 elemento
            atual = fila->getCabeca();
            ui->painel->display(atual->getNumero());
        }else{
            if (atual == NULL){ // inicia o percorrimento em uma fila com vários elementos
                atual = fila->getCabeca();
                ui->painel->display(atual->getNumero());
            }else{
                if (atual->getProximo() == NULL){ // verifica se é o último da fila
                    ui->alerta->setText("  A Fila está vazia!");
                    delay(2000);
                    ui->alerta->setText("");
                }else{
                    atual = atual->getProximo(); // percorre a lista
                    ui->painel->display(atual->getNumero());
                }
            }
        }
    }
}
