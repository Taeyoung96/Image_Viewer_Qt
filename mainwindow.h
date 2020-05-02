#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h" //Add dialog header files
#include <QFileDialog> //To use QFileDialog
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QFile>
#include <QBitArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    QString ImageName = "";     //Declare ImageAddress
    //int weight = 0;     //Declare 'weight' variable
    //int height = 0;     //Declare 'height' variable
    QPixmap pix;
    QImage image;
    bool RawDataFlag = true;
    //QImage ResultImage;
    ~MainWindow();

public slots:
    void Recv_Value(QImage value)
    {
      image = value;
    }

private slots:
    void on_OpenRawImageButton_clicked();

    void on_OpenFormatImageButton_clicked();

    void on_Rotate45Button_clicked();

    void on_Rotate90Button_clicked();

    void on_Rotate180Button_clicked();

private:
    Ui::MainWindow *ui;
   // QGraphicsScene scene;
    QTransform transform;  //Declare Transform
    Dialog *dlg;
};

#endif // MAINWINDOW_H
