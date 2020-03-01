#include "database.h"

database::database()
{
}

database::~database() {}

void database::createDatabase()
{
    QSqlQuery query;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_PATH);
    db.open();

    query.exec("CREATE TABLE Distances("
               "StartingCollege VARCHAR(60) PRIMARY KEY,"
               "EndingCollege   VARCHAR(60),"
               "Distance        INTEGER));");

    query.exec("CREATE TABLE Souvenirs("
               "College VARCHAR(60) PRIMARY KEY,"
               "TraditionalSouvenir VARCHAR(60),"
               "Cost NUMERIC));");
}

void database::readExcel(QString excelPath, int worksheetNumber, int row, int col)
{
    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    auto workbook  = workbooks->querySubObject("Open(const QString&)", excelPath);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", worksheetNumber);    // use first worksheet

    // setup a range of 61 rows and 3 columns
//    auto range     = sheet->querySubObject("Range(A1,C61)");

    for(int x = 1; x <= row; ++x)
    {
        auto cell = sheet->querySubObject("Cells(int, int)", x, col);
        qDebug() << cell->dynamicCall("Value()").toInt();
    }

    // if successful, show the address (first cell found)
//    if (nullptr != find)
//        qDebug() << find->dynamicCall("Address");

    // don't forget to quit Excel
    excel->dynamicCall("Quit()");
}
