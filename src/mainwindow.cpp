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
QVector<QVector<string>> MainWindow::splitString(string filename, char delimiter) {
    string line;
    QVector<QVector<string>> result;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            int start = 0;
            QVector<string> segments;
            int end = line.find(delimiter);
            while (end != -1) {
               // cout << line.substr(start, end - start) << " ";//retour à la ligne entre deux tabulations
               segments.push_back(line.substr(start, end - start));
                start = end + 1;//delimiter.size();
                end = line.find(delimiter, start);
               // result = std :: <<line.substr(start, end - start)<<"   ";

                }
           // cout << line.substr(start, end - start)<<endl;
            segments.push_back(line.substr(start, end - start));
            result.push_back(segments);
           // return result;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return result;
}

double MainWindow::integrale(QVector <double>  vector, int x,int y)
{
//   // QVector <double> acquisition;

    double resultat = 0;

    for (int i=x; i<y+1;i++)
   {
      resultat= vector[i] +resultat;
   }
    return resultat;
}
double MainWindow::moyenneVecteur (QVector<double> vector, int tailleVector)
{
    int i =0;
    double somme =0 ;
    double resultat;

    for (i=0 ; i<tailleVector; i++)
    {
        somme =vector[i] + somme ; // somme des 10 valeurs


    }
   resultat = somme/tailleVector; // moyenne de ces 10 valeurs

    return resultat;

}

void MainWindow::on_pushButton_clicked()
{
   QVector<QVector<string>> segments = splitString("C:/Users/Laila/OneDrive/Documents/Data/22-03-14 - Fluo CERMEP/Acq01.txt",'\t');
   QVector<double> LonguerOnde;
   QVector<QVector<double>> acquisitions;
     for (int i=14 ; i<15; i++){
         for (int j = 2; j < segments[i].size(); j++) {
             cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
             LonguerOnde.push_back(stod(segments[i][j]));// stod convertir un string en double
          }
              cout << endl;
     }// LONGUEUR D'ONDE
     for (int i=15 ; i<sizeof(segments); i++){// toutes les acquisitions sont stockées dans le vecteur acquisitions
          QVector<double> acquisition;
         for (int j = 2; j < segments[i].size(); j++) {
             cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
             acquisition.push_back(stod(segments[i][j]));// stod convertir un string en double
          }
          acquisitions.push_back(acquisition);
              cout << endl;
     }

// Création du graphique
QChart *chart = new QChart();

// Création des axes
QValueAxis *axisX = new QValueAxis();
axisX->setTitleText("Longueur d'onde (nm)");
axisX->setLabelFormat("%d");
axisX->setTickCount(LonguerOnde.size());
axisX->setRange(200, 1000);
chart->addAxis(axisX, Qt::AlignBottom);

QValueAxis *axisY = new QValueAxis();
axisY->setTitleText("Intensite (unité arbitraire)");
axisY->setLabelFormat("%d");
chart->addAxis(axisY, Qt::AlignLeft);

//une deuxième boucle pour toutes les acquisitions
// Ajout des données au graphique
//QVector<QLineSeries*> vector;

QLineSeries *series = new QLineSeries();

for (int i = 0 ; i < LonguerOnde.size() ; i++)
{
   series->append(LonguerOnde[i], acquisitions[0][i]);
}

// Ajout des séries de données au graphique
chart->addSeries(series);

// Association des séries de données aux axes
series->attachAxis(axisX);
series->attachAxis(axisY);

// Affichage du graphique
QChartView *chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->show();

}


void MainWindow::on_pushButton_5_clicked()
{
    QVector<QVector<string>> segments = splitString("C:/Users/Laila/OneDrive/Documents/Data/22-03-14 - Fluo CERMEP/Acq01.txt",'\t');
    QVector<double> LonguerOnde;
    QVector<QVector<double>> acquisitions;
      for (int i=14 ; i<15; i++){
          for (int j = 2; j < segments[i].size(); j++) {
              cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
              LonguerOnde.push_back(stod(segments[i][j]));// stod convertir un string en double
           }
               cout << endl;
      }// LONGUEUR D'ONDE
      for (int i=15 ; i<sizeof(segments); i++){// toutes les acquisitions sont stockées dans le vecteur acquisitions
           QVector<double> acquisition;

          for (int j = 2; j < segments[i].size(); j++) {
              cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
              acquisition.push_back(stod(segments[i][j]));// stod convertir un string en double
           }
           acquisitions.push_back(acquisition);
               cout << endl;
      }

    //*****definition des indices de départ et fin pour la plage des longueurs d'onde *****//

       int startindex= LonguerOnde.indexOf(750);
       int endindex= LonguerOnde.indexOf(950);

    // ************ Création d'un vecteur pour stocker la somme de chaque répétition d'une acquisition soit 10 valeurs ************//
                QVector<double> vector3(0);
                MainWindow w;

         for (int i=0; i<acquisitions.size(); i++)
                   {

                     double resultat = w.integrale (acquisitions[i], startindex, endindex);
                     cout << "L'integrale vaut " <<resultat<< endl;
                     vector3.push_back(resultat);

    // Concaténer les valeurs de vector3 en une chaîne de caractères

        QString vectorString;

        for (int i = 0; i < vector3.size(); i++) {
            vectorString += QString::number(vector3[i]);
            vectorString += " ";
                     }

    // Mettre à jour l'étiquette (label) pour afficher le résultat

        ui->label->setText(vectorString);

                   }

}


void MainWindow::on_pushButton_6_clicked()
{
    QVector<QVector<string>> segments = splitString("C:/Users/Laila/OneDrive/Documents/Data/22-03-14 - Fluo CERMEP/Acq01.txt",'\t');
    QVector<double> LonguerOnde;
    QVector<QVector<double>> acquisitions;
      for (int i=14 ; i<15; i++){
          for (int j = 2; j < segments[i].size(); j++) {
              cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
              LonguerOnde.push_back(stod(segments[i][j]));// stod convertir un string en double
           }
               cout << endl;
      }// LONGUEUR D'ONDE
      for (int i=15 ; i<sizeof(segments); i++){// toutes les acquisitions sont stockées dans le vecteur acquisitions
           QVector<double> acquisition;
          for (int j = 2; j < segments[i].size(); j++) {
              cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
              acquisition.push_back(stod(segments[i][j]));// stod convertir un string en double
           }
           acquisitions.push_back(acquisition);
               cout << endl;
      }

      QVector<double> vector3(0);
      MainWindow w;
      //*****definition des indices de départ et fin pour la plage des longueurs d'onde *****//

         int startindex= LonguerOnde.indexOf(750);
         int endindex= LonguerOnde.indexOf(950);

      for (int i=0; i<acquisitions.size(); i++)
                {

                  double resultat = w.integrale (acquisitions[i], startindex, endindex);
                  vector3.push_back(resultat);

                  // ************* Appel de la fonction moyenne ************//



                }
      double resultat= w.moyenneVecteur(vector3, vector3.size());

       // Mettre à jour l'étiquette (label) pour afficher le résultat

      QString resultatString = QString::number(resultat);

      ui->label_2->setText(resultatString);

}
