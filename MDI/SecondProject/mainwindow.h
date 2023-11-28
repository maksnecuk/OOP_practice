#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QListWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>
#include "Patient.h"
#include "Person.h"
#include "Doctor.h"
#include "createdoc.h"
#include "createpat.h"
#include "showdoc.h"
#include "showpat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlTableModel;
class DBManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DBManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_createPatPb_clicked();

    void on_createDocPb_clicked();

    void on_showDocPb_clicked();

    void on_showPatPb_clicked();

    void on_exitPb_clicked();

    void on_clearDocPb_clicked();

    void on_clearPatPb_clicked();

private:
    Ui::MainWindow *ui;
    ShowDoc *showDoctor;
    ShowPat *showPatient;

    QString id, firstName, surname, lastName, address, phoneNumber, medicalNumber, diagnosis, specialization;
    DBManager *db;
    QSqlTableModel  *model;

};
#endif // MAINWINDOW_H
