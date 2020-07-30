#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include "planeta.h"
#include "objetos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void iniciar();

private slots:
    void on_pushButton_clicked();

    void actcualizar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scena;
    QTimer *timer;
    QVector <planeta> planetas;
    QVector <planeta>::iterator it;
    QList <objetos> obj;
    QList <objetos>::iterator itb;
};
#endif // MAINWINDOW_H
