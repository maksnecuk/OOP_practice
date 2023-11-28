#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"
#include "Logger.h"
#include <QtSql/QSqlTableModel>
#include <QDateTime>


MainWindow::MainWindow(DBManager* dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try{
    dbManager->connectToDataBase();
    }catch(const std::exception &ex){
    qCritical()<<"Here is exception: "<<ex.what();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_createPatPb_clicked()
{
    CreatePat createPatient;
    createPatient.setModal(true);
    createPatient.exec();
}


void MainWindow::on_createDocPb_clicked()
{
    CreateDoc createDoctor;
    createDoctor.setModal(true);
    createDoctor.exec();
}


void MainWindow::on_showPatPb_clicked()
{
    showPatient = new ShowPat(this);
    showPatient->show();
    showPatient->setList();
}

void MainWindow::on_showDocPb_clicked()
{
    showDoctor = new ShowDoc(this);
    showDoctor->show();
    showDoctor->setList();
}



void MainWindow::on_exitPb_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exiting the program", "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QCoreApplication::exit(0);
    }
}




void MainWindow::on_clearPatPb_clicked()
{
    SqliteDBManager *dbManager = SqliteDBManager::getInstance();
    try{
    if (dbManager->clearPatientsTable()) {
        QMessageBox::information(this, "Delete Patients", "Now table about Patients is clear!");
    }
    }catch(const std::exception &ex){
    QMessageBox::critical(this, "Clear Patients", "Error in clearing");
    qWarning()<<"Exception: "<<ex.what();
    }
}


void MainWindow::on_clearDocPb_clicked()
{
    SqliteDBManager *dbManager = SqliteDBManager::getInstance();
    try{
    if (dbManager->clearDoctorsTable()) {
        QMessageBox::information(this, "Delete Doctors", "Now table about Doctors is clear!");
    }
    }catch(const std::exception &ex){
    QMessageBox::critical(this, "Clear Doctors", "Error in clearing");
    qWarning()<<"Exception: "<<ex.what();
    }
}

