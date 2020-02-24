#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_PATH);
    db.open();
}

database::~database() {}

void database::createDatabase()
{
    QSqlQuery query;
}

void database::readExcel()
{
    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    auto workbook  = workbooks->querySubObject("Open(const QString&)", EX_PATH);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", 1);    // use first worksheet

    // setup a range of 61 rows and 3 columns
    auto range     = sheet->querySubObject("Range(A1,C61)");

    for(int i = 1; i <= 61; ++i)
    {
        auto cell = sheet->querySubObject("Cells(int, int)", i, 1);
        qDebug() << cell->dynamicCall("Value()").toInt();
    }

    // if successful, show the address (first cell found)
//    if (nullptr != find)
//        qDebug() << find->dynamicCall("Address");

    // don't forget to quit Excel
    excel->dynamicCall("Quit()");
}
