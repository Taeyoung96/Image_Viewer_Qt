#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QPushButton>
#include <QMainWindow>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_editingFinished()
{   //enter the width
    width = ui->lineEdit->text().toInt();
}

void Dialog::on_lineEdit_2_editingFinished()
{   //enter the height
    height = ui->lineEdit_2->text().toInt();
}

void Dialog::on_GrayScaleButton_clicked()
{   //when you check grayscale button, change the flag
    GrayColorFlag = false;
}

void Dialog::on_ColorButton_clicked()
{   //when you check color button, change the flag
    GrayColorFlag = true;
}

//if you click 'accept' button,
void Dialog::on_buttonBox_accepted()
{
        QString strFilter = "raw file(*.raw)";
        strFileName = QFileDialog::getOpenFileName(this,"Open a file","C:/Users/TaeYoung/Desktop/영상처리시스템설계_과제1",strFilter);
        //choose the file name

        file->setFileName(strFileName);  //load the file
        file->open(QFile::ReadOnly);  //just read the file

        byteArray = file->readAll(); // transfer file to byteArray
        data = (const uchar*) byteArray.constData(); //transfer byteArray to uchar

        file->close(); //if you get data, close the file

        if(GrayColorFlag){     // if you choose color button
            QImage *temp = new QImage(data,width,height,QImage::Format_RGB888);
            image = *temp;  //initialize image
        }

        else{                  // if you choose gray button
            QImage *temp = new QImage(data,width,height,QImage::Format_Grayscale8);
            image = *temp;  //initialize image

        }
        //pass QImage to mainwindow
        connect(this,SIGNAL(sendData(QImage)),parent(),SLOT(Recv_Value(QImage)));
        emit sendData(image);
}

//if you click 'cancel' button, just closed
void Dialog::on_buttonBox_rejected()
{
    close();
}


