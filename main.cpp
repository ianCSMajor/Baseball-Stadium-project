#include "database.h"
#include "plantrips.h"
#include "addsouvenirs.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
    MainWindow *w = new MainWindow(nullptr, &db);

    db.readExcelFile(1, 111);
    db.readExcelFile(2, 47);
    db.printDistanceMap();
    db.printSouvenirMap();
//    db.printDistancesTable();
    w->show();
    return a.exec();
}
