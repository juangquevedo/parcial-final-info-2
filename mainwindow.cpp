#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scena= new QGraphicsScene;
    timer= new QTimer;

    ui->graphicsView->setScene(scena);
    scena->setSceneRect(0,0,700,700);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actcualizar()));

    iniciar();

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
    srand(time(NULL));
    int x=(10)+rand()%(691-10);
    int a=(1)+rand()%(5+1);
    obj.push_back(objetos(x,a));
    scena->addItem(obj.back().circulo);
}

void MainWindow::actcualizar(){
    for(it=planetas.begin();it!=planetas.end();it++)
        it->calcular(planetas,1,1);
}
