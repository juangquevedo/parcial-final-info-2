#ifndef OBJETOS_H
#define OBJETOS_H

#include <QGraphicsEllipseItem>
#include <QBrush>

class objetos
{
public:
    objetos(int x, double na);
    void actualizar();
    bool contacto(int px,int py);
    double a;
    QGraphicsEllipseItem *circulo= new QGraphicsEllipseItem;
};

#endif // OBJETOS_H
