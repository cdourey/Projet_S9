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

void MainWindow::vecteur()
{



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

ui1(new Ui::MainWindow)

{
    ui1->setupUi(this);
    graphe1 = new QChart();
    graphe2 = new QChart();
    graphe3 = new QChart();
    donnees = new QLineSeries();
    donnees2 = new QLineSeries();
    donnees3 = new QLineSeries();

   // graphe 1
    donnees->append(0,6);
    donnees->append(1,5);
    donnees->append(2,6);
    donnees->append(5,7);
    donnees->append(1,16);
    donnees->append(0,4);
   // graphe 2
    donnees2->append(0,6);
    donnees2->append(1,5);
    donnees2->append(2,6);
    donnees2->append(3,7);
    donnees2->append(4,-2);
    donnees2->append(5,4);
   // graphe 3
    donnees3->append(-1,6);
    donnees3->append(1,5);
    donnees3->append(2,6);
    donnees3->append(3,7);
    donnees3->append(4,-2);
    donnees3->append(5,4);

    // Ajout points
    graphe1->setTitle("hello");
    graphe1->addSeries(donnees);
    // Ajout points
    graphe2->setTitle("hello2");
    graphe2->addSeries(donnees2);
    // Ajout points
    graphe3->setTitle("hello3");
    graphe3->addSeries(donnees3);


}

MainWindow::~MainWindow()
{
    delete(ui1);
}

void MainWindow::on_actionOuvrir_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Ouvrir un fichier de donnÃ©es", "", "*");
    qInfo()<<"Fichier Ouvert "<<filename;

}

void MainWindow::on_graphique_1_clicked()
{
    graphe1->createDefaultAxes();
    ui1->fenetreView->setChart(graphe1);
}
void MainWindow::on_graphique_2_clicked()
{
    graphe2->createDefaultAxes();
    ui1->fenetreView->setChart(graphe2);
}
void MainWindow::on_graphique_3_clicked()
{
    graphe3->createDefaultAxes();
    ui1->fenetreView->setChart(graphe3);
}


//
