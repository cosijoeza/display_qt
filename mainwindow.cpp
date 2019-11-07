#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QPixmap>
#include <QFile>
#include "ui_mainwindow.h"
#include "mainwindow.h"

#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)

using namespace cv;
using namespace std;

Mat image_1,image_2;
Mat imgGray_1,imgGray_2;
Mat resultado,imWB;
String picture1_path="", picture2_path="";
#include "functions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*-----OPERACIONES LÓGICAS-----*/
void MainWindow::on_logicas_activated(int index)
{
    switch(index)
    {
        case 0:
            cout << "Suma"<<endl;
            resultado = funSuma(image_1,image_2);
            break;
        case 1:
            cout << "Resta"<<endl;
            resultado = funResta(image_1,image_2);
            break;
        case 2:
            cout << "Resta Normalizada"<<endl;
            resultado = funRestaNorm(image_1,image_2);
            break;
        case 3:
            cout << "And"<<endl;
            resultado = funAnd(image_1,image_2);
            break;
        case 4:
            cout << "Or"<<endl;
            resultado = funOr(image_1,image_2);
            break;
        case 5:
            resultado = negative(image_1);
            cout << "Negative"<<endl;
            break;
    }
    imwrite("resultado.jpg",resultado);
    QPixmap pix("resultado.jpg");
    int w = ui->resultado->width();
    int h = ui->resultado->height();
    ui->resultado->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    return;
}
/*-----CANALES-----*/
void MainWindow::on_canales_activated(int index)
{
    cout << "canales"<<endl;
    resultado = funGetChannel(image_1,index);
    imwrite("resultado.jpg",resultado);
    QPixmap pix("resultado.jpg");
    int w = ui->resultado->width();
    int h = ui->resultado->height();
    ui->resultado->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    return;
}
/*-----GEOMETRICAS-----*/
void MainWindow::on_geometricas_activated(int index)
{
    switch(index)
    {
        case 0:
            cout << "1:2"<<endl;
            resultado = escala(imgGray_1,2);
            break;
        case 1:
            cout << "1:4"<<endl;
            resultado = escala(imgGray_1,4);
            break;
        case 2:
            cout << "1:8"<<endl;
            resultado = escala(imgGray_1,8);
            break;
        case 3:
            //Rotacion
	        int angulo=0;
            imWB = imgGray_1.clone();
	        namedWindow("Rotacion", 1);
	        imshow("Rotacion", imWB);
	        createTrackbar("Angulo", "Rotacion", &angulo, 360 , rota, &angulo);
            break;
    }
    imwrite("resultado.jpg",resultado);
    QPixmap pix("resultado.jpg");
    int w = resultado.cols;
    int h = resultado.rows;
    ui->resultado->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    return;
}
//Traslacion
void MainWindow::on_ejex_valueChanged(int arg1)
{
    cout << arg1 <<endl;
    resultado = traslation(imgGray_1,0,arg1);
    imwrite("resultado.jpg",resultado);
    QPixmap pix("resultado.jpg");
    int w = ui->resultado->width();
    int h = ui->resultado->height();
    ui->resultado->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_ejey_valueChanged(int arg1)
{
    cout << arg1 <<endl;
    resultado = traslation(imgGray_1,1,arg1);
    imwrite("resultado.jpg",resultado);
    QPixmap pix("resultado.jpg");
    int w = ui->resultado->width();
    int h = ui->resultado->height();
    ui->resultado->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

/*--------ABRIR ARCHIVOS, LIMPIAR Y CERRAR VENTANAS--------*/
void MainWindow::on_open1_clicked()
{
    QFile file;
    QTextStream io;
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this,"Abrir");
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //Ruta de archivo
    picture1_path = file_name.toStdString();
    //Lectura de imagen RGB y Escala de Grises
    image_1 = imread(picture1_path, CV_LOAD_IMAGE_COLOR);
    imgGray_1 = imread(picture1_path, CV_LOAD_IMAGE_GRAYSCALE);
    if(!file.isOpen() || ! image_1.data )
    {
        QMessageBox::critical(this,"Error","No se pudo abrir archivo");
        return;
    }
    io.setDevice(&file);
    file.flush();
    file.close();
    //Renderizar imagen en interfaz
    QPixmap pix(file_name);
    int w = ui->picture_1->width();
    int h = ui->picture_1->height();
    ui->picture_1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_open2_clicked()
{
    QFile file;
    QTextStream io;
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this,"Abrir");
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //Ruta de archivo
    picture2_path = file_name.toStdString();
    //Lectura de imagen RGB y Escala de grises
    image_2 = imread(picture2_path, CV_LOAD_IMAGE_COLOR);
    imgGray_2 = imread(picture2_path, CV_LOAD_IMAGE_GRAYSCALE);
    if(!file.isOpen() || ! image_1.data )
    {
        QMessageBox::critical(this,"Error","No se pudo abrir archivo");
        return;
    }
    io.setDevice(&file);
    file.flush();
    file.close();
    //Renderizar imagen en interaz
    QPixmap pix(file_name);
    int w = ui->picture_2->width();
    int h = ui->picture_2->height();
    ui->picture_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
void MainWindow::on_clean1_clicked()
{
    ui->picture_1->clear();
    ui->picture_1->setText("Imagen 1");
}

void MainWindow::on_clean2_clicked()
{
    ui->picture_2->clear();
    ui->picture_2->setText("Imagen 2");
}
void MainWindow::on_clean3_clicked()
{
    ui->resultado->clear();
    ui->resultado->setText("Resultado");
}
void MainWindow::on_close_clicked()
{
    this -> close();
}

