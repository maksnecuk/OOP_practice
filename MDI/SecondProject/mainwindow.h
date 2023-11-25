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
signals:
//    void itemSelected(const QString& itemText);
private slots:
    void on_createPatPb_clicked();

    void on_createDocPb_clicked();

    void on_showDocPb_clicked();

    void on_showPatPb_clicked();

    void on_exitPb_clicked();

//    void on_itemPatDoubleClicked(QListWidgetItem *item);

//    void on_itemDocDoubleClicked(QListWidgetItem *item);

//    void on_patientCreated(Patient *);
//    void on_doctorCreated(Doctor *);

    void on_clearDocPb_clicked();

    void on_clearPatPb_clicked();

private:
    Ui::MainWindow *ui;
    ShowDoc *showDoctor;
    ShowPat *showPatient;
//    QVector<Doctor*> doctors;
//    QVector<Patient*> patients;
    QString id, firstName, surname, lastName, address, phoneNumber, medicalNumber, diagnosis, specialization;
    DBManager *db;
    QSqlTableModel  *model;
//    void setupModel(const QString &tableName, const QStringList &headers);

};
#endif // MAINWINDOW_H
