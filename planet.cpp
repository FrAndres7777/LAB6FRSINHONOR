#include "planet.h"

Planet::Planet(QString name_)
{
    name = name_;

}

void Planet::Tamanio()
{
    //se pintara en en mainwindow.cpp
    setPixmap(QPixmap(name).scaled(radio*2,radio*2));
}

double Planet::getPosx() const
{
    return posx;
}

void Planet::setPosx(double value)
{
    posx = value;
}

double Planet::getPosy() const
{
    return posy;
}

void Planet::setPosy(double value)
{
    posy = value;
}

double Planet::getMasa() const
{
    return masa;
}

void Planet::setMasa(double value)
{
    masa = value;
}

double Planet::getRadio() const
{
    return radio;
}

void Planet::setRadio(double value)
{
    radio = value;
}

double Planet::getVelx() const
{
    return velx;
}

void Planet::setVelx(double value)
{
    velx = value;
}

double Planet::getVely() const
{
    return vely;
}

void Planet::setVely(double value)
{
    vely = value;
}

QString Planet::getName() const
{
    return name;
}

double Planet::getAc_x() const
{
    return ac_x;
}

void Planet::setAc_x(double value)
{
    ac_x = value;
}

double Planet::getAc_y() const
{
    return ac_y;
}

void Planet::setAc_y(double value)
{
    ac_y = value;
}

double Planet::getX_inicial() const
{
    return x_inicial;
}

void Planet::setX_inicial(double value)
{
    x_inicial = value;
}

double Planet::getY_inicial() const
{
    return y_inicial;
}

void Planet::setY_inicial(double value)
{
    y_inicial = value;
}
