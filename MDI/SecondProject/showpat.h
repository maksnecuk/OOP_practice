#ifndef SHOWPAT_H
#define SHOWPAT_H

#include <QDialog>
#include <QListWidget>
#include "createpat.h"
#include <QSqlTableModel>
#include "sqlitedbmanager.h"

namespace Ui {
class ShowPat;
}

class ShowPat : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPat(QWidget* parent = nullptr);
    void setList();
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
//    QListWidget* getListWidget();
    ~ShowPat();

private slots:

public slots:
//    void on_patientCreated(Patient *);


private:
    Ui::ShowPat *ui;
    bool checkFields();
//    Patient* patient;
//    QVector<Patient*> patients;

    DBManager *db;
    QSqlTableModel  *model;

};

#endif // SHOWPAT_H
