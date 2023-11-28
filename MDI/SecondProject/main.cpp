#include "mainwindow.h"
#include "Logger.h"
#include <QApplication>
#include "sqlitedbmanager.h"

int main(int argc, char *argv[])
{
    Logger::init();
    QApplication a(argc, argv);

    DBManager* dbManager = SqliteDBManager::getInstance();

    MainWindow w(dbManager);
    w.show();
    bool state = a.exec();
    Logger::clean();
    return state;
}
