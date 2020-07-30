#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <math.h>

class planeta
{
public:
    planeta(double nxo,double nyo,double long nmas,double nrad,double nvox, double nvoy);
    QGraphicsEllipseItem *ima= new QGraphicsEllipseItem;
    double xo,yo,rad,vox,voy;
    double long mas,ax=0,ay=0;
    void calcular(QVector <planeta> planetas, double long G,double long T);
    void cambiar_color(int op);
};

#endif // PLANETA_H

