#include "header.h"
#include "database.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
    MainWindow w;

    w.show();

    db.createDatabase();
    // db.readExcel();

    return a.exec();
}
