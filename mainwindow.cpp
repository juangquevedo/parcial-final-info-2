#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scena= new QGraphicsScene;
    timer= new QTimer;

    ui->graphicsView->setScene(scena);
    scena->setSceneRect(0,0,980,520);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actcualizar()));
    timer->start(5);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::iniciar(){
    planetas.push_back(planeta(0,0,50000,200,0,0));
    planetas.push_back(planeta(-5000,0,70,70,0,-2));
    planetas.push_back(planeta(5000,0,70,70,0,2));
    planetas.push_back(planeta(0,-5000,70,70,2,0));
    planetas.push_back(planeta(0,5000,70,70,-2,0));
    for(it=planetas.begin();it!=planetas.end();it++)
        scena->addItem(it->ima);
}

void MainWindow::on_pushButton_clicked(){
}

void MainWindow::actcualizar(){
}
