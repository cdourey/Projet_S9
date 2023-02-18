#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; 
    //vector<vector<string>> segments = w.splitString("C:/Users/Laila/OneDrive/Documents/Data/22-03-14 - Fluo CERMEP/Acq01.txt",'\t');
    w.show();
    return a.exec();
}
