#ifndef SHOWDOC_H
#define SHOWDOC_H

#include <QDialog>
#include <QListWidget>
#include "createdoc.h"

namespace Ui {
class ShowDoc;
}

class ShowDoc : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDoc(QWidget *parent = nullptr);
    void setList(const QVector<Doctor*>& doctors);
    QListWidget* getListWidget();
    ~ShowDoc();

public slots:
    void on_doctorCreated(Doctor*);
private slots:

private:
    Ui::ShowDoc *ui;
    bool checkFields();
    QVector<Doctor*> doctors;
};

#endif // SHOWDOC_H