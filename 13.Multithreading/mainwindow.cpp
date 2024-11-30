#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}

void MainWindow::updateProgress(int value){
    ui->progressBar->setValue(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

