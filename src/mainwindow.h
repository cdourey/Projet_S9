#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <string>
#include <vector>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <stdio.h>
#include <stdlib.h>



#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     ~MainWindow();
    int lecture();
    void ShowChart();
    void vecteur();
    QChartView *fenetre1; // un widget pour afficher un graphe
    QChart *graphe1; // la reprÃ©sentation d'un graphe
    QChart *graphe2;// la reprÃ©sentation d'un graphe
    QChart *graphe3;
    QLineSeries *donnees;// les donnÃ©es
    QLineSeries *donnees2;
    QLineSeries *donnees3;
    QValueAxis *axisX;
    QValueAxis *axisY;
    Cinformations() ; // constructeur par défaut
    virtual ~Cinformations(); // destructeur par défaut
    double moyenneTableau (QVector<int> vector, int tailleVector); // fonction qui calcule la moyenne

    

private slots:
    void on_pushButton_clicked();
    void on_actionOuvrir_triggered();
    void on_graphique_1_clicked();
    void on_graphique_2_clicked();
    void on_graphique_3_clicked();
    QVector<int> vector;
    int tailleVector;
    

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
