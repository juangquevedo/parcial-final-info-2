#include "planeta.h"

planeta::planeta(double nxo, double nyo, double long nmas, double nrad, double nvox, double nvoy){
    xo=nxo;
    yo=nyo;
    mas=nmas;
    rad=nrad;
    vox=nvox;
    voy=nvoy;
    nxo=(xo*3)/100;
    nyo=(yo*3)/100;
    nxo=abs(nxo+300);
    nyo=abs(nyo-300);
    ima->setRect(0,0,10,10);
    //ima->setPixmap(QPixmap(":/new/prefix1/planet.png").scaled((rad/10)-5,(rad/10)-5));
    //ima->setPos(nxo-(((rad/10)-5)/2),nyo-(((rad/10)-5)/2));
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
    nxo=(xo*3)/100;
    nyo=(yo*3)/100;
    nxo=abs(nxo+300);
    nyo=abs(nyo-300);
    ima->setPos(nxo-(((rad/10)-5)/2),nyo-(((rad/10)-5)/2));
}
