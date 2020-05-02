#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMdiSubWindow>
#include <QImage>
#include <QFile>
#include <QByteArray>
#include <QtGlobal>  //to use quint16


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    //QImage convertToGray(QImage *pInputImage);
    QString strFileName;
    QImage image;
    explicit Dialog(QWidget *parent = 0);
    int width;     //Declare 'width' variable
    int height;     //Declare 'height' variable
    ~Dialog();

signals:
    void sendData(QImage value);

public slots:
    void on_buttonBox_accepted();


private slots:
    void on_lineEdit_editingFinished();
    void on_lineEdit_2_editingFinished();

    void on_ColorButton_clicked();

    void on_buttonBox_rejected();

    void on_GrayScaleButton_clicked();

private:
    QFile *file = new QFile;
    QByteArray byteArray;
    const uchar* data;
    bool GrayColorFlag;
    Ui::Dialog *ui;
};


#endif // DIALOG_H
