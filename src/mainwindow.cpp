#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphe1 = new QChart();
    datafile = QFileDialog::getExistingDirectory(this);
    getData("/22-03-14 - Fluo CERMEP/","14-03-2022");
    getData("/22-10-20 - Fluo CERMEP/","20-10-2022");
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
                // // cout << line.substr(start, end - start) << " ";//retour à la ligne entre deux tabulations
                segments.push_back(line.substr(start, end - start));
                start = end + 1;//delimiter.size();
                end = line.find(delimiter, start);
                // result = std :: <<line.substr(start, end - start)<<"   ";

            }
            // // cout << line.substr(start, end - start)<<endl;
            segments.push_back(line.substr(start, end - start));
            result.push_back(segments);
            // return result;
        }
        file.close();
    } else {
        // cout << "Unable to open file" << endl;
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
    QString filename = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "","*.txt");
    QVector<QVector<string>> segments = splitString(filename.toStdString(),'\t');
    QVector<double> LonguerOnde;
    QVector<QVector<double>> acquisitions;
    for (int i=14 ; i<15; i++){
        for (int j = 2; j < segments[i].size(); j++) {
            // cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
            LonguerOnde.push_back(stod(segments[i][j]));// stod convertir un string en double
        }
        // cout << endl;
    }// LONGUEUR D'ONDE
    for (size_t i=15 ; i<sizeof(segments); i++){// toutes les acquisitions sont stockées dans le vecteur acquisitions
        QVector<double> acquisition;
        for (int j = 2; j < segments[i].size(); j++) {
            // cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
            acquisition.push_back(stod(segments[i][j]));// stod convertir un string en double
        }
        acquisitions.push_back(acquisition);
        // cout << endl;
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

/******************code Milly*******************************/
void MainWindow::on_actionOuvrir_triggered()// Fonction qui sert à ouvrir le fichier"manip.csv"
{
    QString filename = QFileDialog::getOpenFileName(this, "Ouvrir un cahier de manip", datafile, "*.csv");
    qInfo() << "Fichier Ouvert" << filename;
    add_data(filename);
}
int MainWindow::add_data(QString filename)// permet de lire les données se trouvant dans le fichier ligne par ligne
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return 1;
    }
    QTextStream stream(&file);//fournit une interface pratique pour lire et écrire du texte.
    int counter = 0 ;

    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QDateTime moment;
        // add skip first line
        if(counter==0)
        {
            counter++;
            continue;
        }

        QStringList valeurs = line.split(';',Qt::SkipEmptyParts);// permet de lire les données en enlevant les parties vides
        QString cle = valeurs[0].replace("/","-");
        cle.append(valeurs[1]);
        //moment = QDateTime::fromString(valeurs[0], "dd/MM/yyyy");// pour l'affichage de la date
        //moment = moment.addSecs(valeurs[1].replace("Acq","").toInt());// on considère le numéro de l'acquisition comme les secondes pour les acquisitions faites le meme jour

        QString Nanoparticule = valeurs[3];// le type de nanoparticule qui est à la quatrième colonne
        if(Data.find(Nanoparticule)==Data.end()){
            //qInfo()<<"not found key";
            Data[Nanoparticule]=new QLineSeries();
            Data[Nanoparticule]->append(valeurs[4].toDouble(), Moyennes[cle]);// valeur de la concentration à la 5 ème colonne
        }else{
            Data[Nanoparticule]->append(valeurs[4].toDouble(), Moyennes[cle]);
        }
        //donnees->append(moment.toMSecsSinceEpoch(), valeurs[4].toDouble());
        // qInfo() <<valeurs;
    }
    file.close();

    graphe1->setTitle("Graphique des Intensités en fonction de la concentration");
    graphe1->legend()->show();

    QMap<QString, QLineSeries*>::const_iterator i = Data.constBegin();

    while (i != Data.constEnd()) {
        i.value()->setName(i.key());
        graphe1->addSeries(i.value());
        ++i;
    }
    // graphe1->addSeries(donnees);
    graphe1->createDefaultAxes();
    graphe1->axes(Qt::Horizontal).back()->setTitleText("Concentration (mol/l)");
    graphe1->axes(Qt::Vertical).back()->setTitleText("Intensite de Fluorescence");
    ui->fenetreView->setChart(graphe1);
    //ui1->fenetreView->setRenderHint(QPainter::Antialiasing);
    return 0;
}

void MainWindow::ajout_moyenne(QStringList filenames,QString date)
{
    for(const auto& filename:filenames)
    {
        QVector<QVector<string>> segments = splitString(filename.toStdString(),'\t');
        QVector<double> LonguerOnde;
        QVector<QVector<double>> acquisitions;
        for (int i=14 ; i<15; i++){
            for (int j = 2; j < segments[i].size(); j++) {
                // cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
                LonguerOnde.push_back(stod(segments[i][j]));// stod convertir un string en double
            }
            // cout << endl;
        }// LONGUEUR D'ONDE
        for (size_t i=15 ; i<sizeof(segments); i++){// toutes les acquisitions sont stockées dans le vecteur acquisitions
            QVector<double> acquisition;
            for (int j = 2; j < segments[i].size(); j++) {
                // cout << segments[i][j] << " ";// STOCKER DANS UN VECTEUR
                acquisition.push_back(stod(segments[i][j]));// stod convertir un string en double
            }
            acquisitions.push_back(acquisition);
            // cout << endl;
        }

        QVector<double> vector3(0);
        int startindex= LonguerOnde.indexOf(750);
        int endindex= LonguerOnde.indexOf(950);

        for (int i=0; i<acquisitions.size(); i++)
        {

            double resultat = this->integrale (acquisitions[i], startindex, endindex);
            vector3.push_back(resultat);

        }
        double resultat= this->moyenneVecteur(vector3, vector3.size());
        QString cle= filename.mid(filename.indexOf("Acq"),5);
        cle.prepend(date);
        Moyennes[cle] = resultat;
    }
}

void MainWindow::getData(QString path,QString date)
{
    QStringList filenames ;
    QString dir = datafile;
    dir.append(path);
    QDirIterator it(dir, QStringList() << "*.txt", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext())
            filenames.append(it.next());
    //QList filenames= QFileDialog::getOpenFileNames(this, "Ouvrir un fichier", "","*.txt");
    ajout_moyenne(filenames,date);
}
