#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <math.h>

class Planet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Planet(QString name);
    void Tamanio();
    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

    double getMasa() const;
    void setMasa(double value);

    double getRadio() const;
    void setRadio(double value);

    double getVelx() const;
    void setVelx(double value);

    double getVely() const;
    void setVely(double value);

    QString getName() const;

    double getAc_x() const;
    void setAc_x(double value);

    double getAc_y() const;
    void setAc_y(double value);

    double getX_inicial() const;
    void setX_inicial(double value);

    double getY_inicial() const;
    void setY_inicial(double value);

private:
    double x_inicial,y_inicial,posx,posy,masa,radio,velx,vely,ac_x=0,ac_y=0;
    QString name;
};

#endif // PLANET_H
