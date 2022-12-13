#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <string>


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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
