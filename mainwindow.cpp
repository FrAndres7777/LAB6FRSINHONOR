#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //escena
    this->setGeometry(400,50,1200,1030);
    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QPixmap(":/imagenes/fondo.png").scaled(1000,1000));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1000,1000);
    ui->graphicsView->setSceneRect(0,0,1000,1000);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVisible(true);
    Invisible();
    //escena entrada de datos

    //Sol
    Sun();
    //timer
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));

    timer2=new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(Crear_archivo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreatePlanet()
{
    if(!planetName(":/imagenes/FR17.png")){
        planets.push_back(new Planet(":/imagenes/FR17.png"));
    }
    else if(!planetName(":/imagenes/FR18.png")){
        planets.push_back(new Planet(":/imagenes/FR18.png"));
    }
    else if(!planetName(":/imagenes/FR19.png")){
        planets.push_back(new Planet(":/imagenes/FR19.png"));
    }
    else if(!planetName(":/imagenes/FR20.png")){
        planets.push_back(new Planet(":/imagenes/FR20.png"));
    }

}

bool MainWindow::planetName(QString name)
{
    for(Planet *i: planets){
        if(i->getName() == name) return true;
    }
    return false;
}

void MainWindow::Sun()
{
    planets.push_back(new Planet(":/imagenes/FRSol.png"));
    planets[0]->setMasa(70000/16);
    planets[0]->setRadio(300/10);
    planets[0]->setVelx(0);
    planets[0]->setVely(0);
    planets[0]->Tamanio();
    planets[0]->setX_inicial(500-planets[0]->getRadio());
    planets[0]->setY_inicial(500-planets[0]->getRadio());
    planets[0]->setPosx(planets[0]->getX_inicial());
    planets[0]->setPosy(planets[0]->getY_inicial());
    scene->addItem(planets[0]);
    planets[0]->setPos(planets[0]->getPosx(),planets[0]->getPosy());
}

void MainWindow::mover()
{
    Aceleracion();

    for(short pos=1;pos<planets.size();pos++){

        planets[pos]->setVelx(planets[pos]->getVelx()+(planets[pos]->getAc_x()*time));
        planets[pos]->setVely(planets[pos]->getVely()+(planets[pos]->getAc_y()*time));
        planets[pos]->setPosx(planets[pos]->getPosx()+(planets[pos]->getVelx()*time));
        planets[pos]->setPosy(planets[pos]->getPosy()+(planets[pos]->getVely()*time));

        planets[pos]->setPos(planets[pos]->getPosx(),planets[pos]->getPosy());
    }
}



void MainWindow::Aceleracion()
{
    double acx=0,acy=0,dist=0;
    for(short pos=1;pos<planets.size();pos++){
        for(short pos2=0;pos2<planets.size();pos2++){
            if(pos!=pos2){
                dist = pow(planets[pos2]->getPosx()-planets[pos]->getPosx(),2);
                dist += pow(planets[pos2]->getPosy()-planets[pos]->getPosy(),2);
                dist = sqrt(dist);
                acx+=(planets[pos2]->getMasa()/pow(dist,3))*(planets[pos2]->getPosx()-planets[pos]->getPosx());
                acy+=(planets[pos2]->getMasa()/pow(dist,3))*(planets[pos2]->getPosy()-planets[pos]->getPosy());
            }
            qDebug() << "Distancia " << dist;
            dist = 0;
        }
        planets[pos]->setAc_x(acx);
        planets[pos]->setAc_y(acy);
        qDebug() << "ac x " << acx;
        qDebug() << "ac y " << acy;
        acx=0,acy=0;
   }


}

void MainWindow::on_add_clicked()
{


    ui->label_8->setText("Agregar planeta.");

    saveButton=true;

    ui->posx->setReadOnly(false);
    ui->posy->setReadOnly(false);
    ui->velx->setReadOnly(false);
    ui->vely->setReadOnly(false);

    ui->masa->setValue(0);
    ui->radio->setValue(0);
    ui->velx->setValue(0);
    ui->vely->setValue(0);
    ui->posx->setValue(0);
    ui->posy->setValue(0);

    timer->stop();
    timer2->stop();
    ui->graphicsView_2->setVisible(true);
    Visible();



}
void MainWindow::on_save_clicked()
{

    if(saveButton){
        //entro en donde no debia

        //agregar planeta
        short pos;
        CreatePlanet();
        pos = planets.size()-1;
        planets[pos]->setMasa(ui->masa->value()/16);
        planets[pos]->setRadio(ui->radio->value()/10);
        planets[pos]->setVelx(ui->velx->value());
        planets[pos]->setVely(ui->vely->value()*-1);
        planets[pos]->Tamanio();
        planets[pos]->setX_inicial(500+(ui->posx->value()/16)-planets[pos]->getRadio());
        planets[pos]->setY_inicial(500-(ui->posy->value()/16)-planets[pos]->getRadio());
        planets[pos]->setPosx(planets[pos]->getX_inicial());
        planets[pos]->setPosy(planets[pos]->getY_inicial());
        scene->addItem(planets[pos]);
        planets[pos]->setPos(planets[pos]->getPosx(),planets[pos]->getPosy());

        Invisible();
    }

    else{
        //donde debia
        planets[number]->setMasa(ui->masa->value()/16);
        planets[number]->setRadio(ui->radio->value()/10);
        planets[number]->setVelx(ui->velx->value());
        planets[number]->setVely(ui->vely->value()*-1);
        planets[number]->Tamanio();
        planets[number]->setX_inicial(500+(ui->posx->value()/16)-planets[number]->getRadio());
        planets[number]->setY_inicial(500-(ui->posy->value()/16)-planets[number]->getRadio());
        planets[number]->setPosx(planets[number]->getX_inicial());
        planets[number]->setPosy(planets[number]->getY_inicial());
        planets[number]->setPos(planets[number]->getPosx(),planets[number]->getPosy());
        //cerrar scena
        on_pushButton_3_clicked();

    }
    Aceleracion();
}

void MainWindow::on_pushButton_3_clicked()
{

    ui->graphicsView_2->setVisible(false);
    Invisible();

}

void MainWindow::Visible()
{
    //label
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_8->setVisible(true);
    //spin box
    ui->posx->setVisible(true);
    ui->posy->setVisible(true);
    ui->masa->setVisible(true);
    ui->radio->setVisible(true);
    ui->velx->setVisible(true);
    ui->vely->setVisible(true);
    //button
    ui->splitter_2->setVisible(true);
}

void MainWindow::Invisible()
{
    //label
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_8->setVisible(false);
    //spin box
    ui->posx->setVisible(false);
    ui->posy->setVisible(false);
    ui->masa->setVisible(false);
    ui->radio->setVisible(false);
    ui->velx->setVisible(false);
    ui->vely->setVisible(false);
    //button
    ui->splitter_2->setVisible(false);
}
void MainWindow::on_play_clicked()
{


    timer->start(10);
    timer2->start(100);
}


