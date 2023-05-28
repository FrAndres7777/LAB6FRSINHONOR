#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "planet.h"
#include <QList>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CreatePlanet();
    bool planetName(QString name);
    void Sun();
    void Visible();
    void Invisible();
    void Aceleracion();

    void Imprimir();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QList<Planet *> planets;
    double time = 1;
    QTimer *timer;
    QTimer *timer2;
    int number;
    bool saveButton;

    QString file_name;
public slots:
    void mover();
    void Crear_archivo();

private slots:
    void on_add_clicked();
    void on_save_clicked();
    void on_pushButton_3_clicked();
    void on_play_clicked();
    void on_stop_clicked();
    void on_view_clicked();
    void on_next_clicked();
    void on_back_clicked();
    void on_delete__clicked();
    void on_ok_clicked();
};
#endif // MAINWINDOW_H
