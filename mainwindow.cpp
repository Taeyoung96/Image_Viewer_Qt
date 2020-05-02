#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h" // To use Dialog
#include <QFileDialog> //To use QFileDialog
#include <QGraphicsScene>
#include <QPixmap>
#include <QFile>
#include <QBitArray>

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

// when you click the button, open dialog
void MainWindow::on_OpenRawImageButton_clicked()
{
    dlg = new Dialog(this);
    dlg->setModal(true);       //show dialog
    dlg->exec();

    pix = QPixmap::fromImage(image,Qt::AutoColor); //initialize raw image to qpixmap
    ui->label_image->setPixmap(pix);               //show image on qlabel
}

// when you click the button, open image with format
void MainWindow::on_OpenFormatImageButton_clicked()
{
    QString ImageFilter = "jpg file(*.jpg);;png file(*.png);;bmp file(*.bmp)";
    ImageName = QFileDialog::getOpenFileName(this,"Open a file","C:/Users/TaeYoung/Desktop/영상처리시스템설계_과제1",ImageFilter);
    //Choose the image path

    QPixmap pix(ImageName); //initialize jpg&png image to qpixmap
    ui->label_image->setPixmap(pix);
    RawDataFlag = false;    //change the flag
}

// when you click the button, rotate image 45 degree
void MainWindow::on_Rotate45Button_clicked()
{
    if(!RawDataFlag){       //if you initialize jpg&png image
        QPixmap pix_temp(ImageName);
        transform.rotate(45);      //rotate image 45 degrees
        ui->label_image->setPixmap(pix_temp.transformed(transform));
    }
    else{                   //if you initialize raw image to qpixmap
        transform.rotate(45);
        ui->label_image->setPixmap(pix.transformed(transform));
    }
}

// when you click the button, rotate image 90 degree
void MainWindow::on_Rotate90Button_clicked()
{
    if(!RawDataFlag){
        QPixmap pix_temp(ImageName);
        transform.rotate(90);   //rotate image 90 degrees
        ui->label_image->setPixmap(pix_temp.transformed(transform));
    }
    else{
        transform.rotate(90);
        ui->label_image->setPixmap(pix.transformed(transform));
    }

}

// when you click the button, rotate image 180 degree
void MainWindow::on_Rotate180Button_clicked()
{
    if(!RawDataFlag){
        QPixmap pix_temp(ImageName);
        transform.rotate(180);  //rotate image 180 degrees
        ui->label_image->setPixmap(pix_temp.transformed(transform));
    }
    else{
        transform.rotate(180);
        ui->label_image->setPixmap(pix.transformed(transform));
    }

}
