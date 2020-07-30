#include "objetos.h"

objetos::objetos(int x, double na){
    circulo->setRect(x,10,10,10);
    circulo->setBrush(Qt::gray);
    a=na/10000;
}

void objetos::actualizar(){
    int y=circulo->y();
    y+=(a*1)+(0.5*a*1);
    circulo->setPos(circulo->x(),y);
    if(y>700 || y<0)
        a=-a;
}

bool objetos::contacto(int px, int py){
    bool temp;
    for(int i=circulo->y();i<(circulo->y()+10);i++){
        temp=(i>=py && i<=(py+10));
        for(int j=circulo->x();j<(circulo->x()+10);j++){
            if(temp && j>=px && j<=(px+10))
                return 1;
        }
    }
    return 0;
}
