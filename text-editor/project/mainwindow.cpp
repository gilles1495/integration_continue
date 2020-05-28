#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QFileDialog>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ap = new APropos(this);

    connect(ui->radioBtnCourier,SIGNAL(clicked()),this,SLOT(on_groupBoxPolice_clicked()));
    connect(ui->radioBtnArial,SIGNAL(clicked()),this,SLOT(on_groupBoxPolice_clicked()));
    connect(ui->radioBtnTNR,SIGNAL(clicked()),this,SLOT(on_groupBoxPolice_clicked()));

    for(auto elem : QColor::colorNames()){
        ui->comboBoxCouleur->addItem(elem);
    }
    couleur = ui->comboBoxCouleur->itemText(0);
    ui->plainTextEditContenu->setStyleSheet("color : "+couleur+" ;");
}

MainWindow::~MainWindow()
{
    delete ap;
    delete ui;
}

void MainWindow::on_groupBoxPolice_clicked()
{
    if(ui->radioBtnCourier->isChecked()){
        font.setFamily("Courier");
        ui->plainTextEditContenu->setFont(font);
    }else if (ui->radioBtnArial->isChecked()) {
        font.setFamily("Arial");
        ui->plainTextEditContenu->setFont(font);
    }else if (ui->radioBtnTNR->isChecked()) {
        font.setFamily("Times New Roman");
        ui->plainTextEditContenu->setFont(font);
    }
}

void MainWindow::on_checkBoxGras_stateChanged(int arg1)
{
    if(arg1 == 2){
        charFont.setFontWeight(QFont::Bold);
    }else if (arg1 == 0) {
        charFont.setFontWeight(QFont::Normal);
    }
    ui->plainTextEditContenu->mergeCurrentCharFormat(charFont);
}
void MainWindow::on_checkBoxItalique_stateChanged(int arg1)
{
    if(arg1 == 2){
        charFont.setFontItalic(true);
    }else if (arg1 == 0) {
        charFont.setFontItalic(false);
    }
    ui->plainTextEditContenu->mergeCurrentCharFormat(charFont);
}

void MainWindow::on_comboBoxCouleur_currentIndexChanged(int index)
{
    couleur  = QColor::colorNames().at(index);
    ui->plainTextEditContenu->setStyleSheet("color : "+couleur+" ;");
}

void MainWindow::on_actionOuvrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir un Fichier","/Users/gilles/Documents/AJC FORMATION/QT5");

    if(fileName != ""){
        QSettings params(fileName, QSettings::IniFormat);
        couleur = params.value("font/couleur").toString();
        font.setFamily(params.value("font/family").toString());
        charFont.setFontWeight(params.value("font/char-font-weight").toInt());

        if(params.value("font/family").toString() == "Courier"){
            ui->radioBtnCourier->setChecked(true);
        }else if (params.value("font/family").toString() == "Arial") {
            ui->radioBtnArial->setChecked(true);
        }else if (params.value("font/family").toString() == "Times New Roman") {
            ui->radioBtnTNR->setChecked(true);
        }

        if(params.value("font/char-font-weight").toInt() == 75){
            ui->checkBoxGras->setChecked(true);
        }else{
            ui->checkBoxGras->setChecked(false);
        }

        if(params.value("font/char-font-italic").toString() == "true"){
            charFont.setFontItalic(true);
            ui->checkBoxItalique->setChecked(true);
        }else{
            charFont.setFontItalic(false);
            ui->checkBoxItalique->setChecked(false);
        }

        ui->comboBoxCouleur->setCurrentIndex(QColor::colorNames().indexOf(couleur));
        ui->plainTextEditContenu->setStyleSheet("color : "+couleur+" ;");
    }else {
        qDebug() << " ERREUR : Probleme lors de l'ouverture du fichier de sauvegarde" << endl;
    }
}

void MainWindow::on_actionEnregistrer_Param_tres_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder les paramètres","/Users/gilles/Documents/AJC FORMATION/QT5");

    if(fileName != ""){
        QSettings params(fileName, QSettings::IniFormat);
        params.setValue("font/couleur", couleur);
        params.setValue("font/char-font-weight", charFont.fontWeight());
        params.setValue("font/char-font-italic", charFont.fontItalic());
        params.setValue("font/family", font.family());
    }else {
        qDebug() << " ERREUR : Probleme lors de la creation du fichier de sauvegarde" << endl;
    }
}

void MainWindow::on_actionA_propos_triggered()
{
    ap->show();
}
