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
    ~ShowPat();

private slots:

public slots:


private:
    Ui::ShowPat *ui;
    bool checkFields();
    DBManager *db;
    QSqlTableModel  *model;

};

#endif // SHOWPAT_H
