#include "objetos.h"

objetos::objetos(int x, double na){
    circulo->setRect(x,10,20,20);
    circulo->setBrush(Qt::gray);
    a=na;
}

void objetos::actualizar(){
}
