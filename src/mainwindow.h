#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QChart>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <cmath>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
    int lecture ();
    QVector<QVector<string>> splitString(string filename, char delimiter);
    double moyenneVecteur (QVector<double> vector, int tailleVector);// fonction qui calcule la moyenne
    double integrale(QVector<double> vector, int x, int y); // fonction qui calcule la somme



private slots:

    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

   // void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:

    Ui::MainWindow *ui;
    Ui::MainWindow *ui1;

};
#endif // MAINWINDOW_H
