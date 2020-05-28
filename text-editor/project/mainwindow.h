#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "apropos.h"
#include <QTextCharFormat>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_groupBoxPolice_clicked();

    void on_checkBoxGras_stateChanged(int arg1);

    void on_checkBoxItalique_stateChanged(int arg1);

    void on_comboBoxCouleur_currentIndexChanged(int index);

    void on_actionOuvrir_triggered();

    void on_actionEnregistrer_Param_tres_triggered();

    void on_actionA_propos_triggered();

private:
    Ui::MainWindow *ui;
    APropos *ap;
    QTextCharFormat charFont;
    QFont font;
    QString couleur;
};

#endif // MAINWINDOW_H
