#include "planeta.h"

planeta::planeta(double nxo, double nyo, double long nmas, double nrad, double nvox, double nvoy){
    xo=nxo;
    yo=nyo;
    mas=nmas;
    rad=nrad;
    vox=nvox;
    voy=nvoy;
    nxo=(xo*35)/800;
    nyo=(yo*35)/800;
    nxo=abs(nxo+350);
    nyo=abs(nyo-350);
    ima->setRect(nxo-5,nyo-5,10,10);
}

void planeta::calcular(QVector<planeta> planetas,double long G,double long T){
    double long r,temp,nxo,nyo;
    QVector<planeta>::iterator it;
    ax=0;
    ay=0;
    for(it=planetas.begin();it!=planetas.end();it++){
        r=sqrt(pow(it->xo-xo,2)+pow(it->yo-yo,2));
        if(r!=0){
            temp=(G*it->mas)/pow(abs(r),3);
            ax+=temp*(it->xo-xo);
            ay+=temp*(it->yo-yo);}
    }
    vox+=ax*T;
    voy+=ay*T;
    xo+=vox*T;
    yo+=voy*T;
    nxo=(xo*35)/800;
    nyo=(yo*35)/800;
    nxo=abs(nxo);
    nyo=abs(nyo);
    ima->setPos(nxo,nyo);
}

void planeta::cambiar_color(int op){
switch (op) {
    case 1:
        ima->setBrush(Qt::blue);
        break;
    case 2:
        ima->setBrush(Qt::red);
        break;
    case 3:
        ima->setBrush(Qt::green);
        break;
    case 4:
        ima->setBrush(Qt::yellow);
        break;
    case 5:
        ima->setBrush(Qt::magenta);
        break;
    default:
        ima->setBrush(Qt::cyan);
        break;
}
}
