#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::lecture()
{

   ifstream filename("C:/Users/Laila/OneDrive/Documents/Data/22-03-14 - Fluo CERMEP/Acq01.txt");

   if(filename)
   {
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(filename, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         cout << ligne << endl;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return 0;
}

void MainWindow::ShowChart(){

  ifstream filename("C:/Users/Laila/OneDrive/Documents/Data/22-03-14 - Fluo CERMEP/Acq01.txt");
  filename.open("Acq01.txt",ios::out);
  if(filename.is_open()){

// Séparer par des tabulations dans les ficheirs afin de
// et read line afin de getline()
// fournir un deux tableaux avec X longueur de lamda et Y intensité de fluorescences
// test unitaire afficher le bon spectre avec les deux tabulations x et y et

  filename.close();

  }

}


void MainWindow::on_pushButton_clicked()
{
    cout<<"Afficher le graphique"<< endl;


}

