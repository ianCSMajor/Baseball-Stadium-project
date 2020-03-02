#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_PATH);
    db.open();
}

database::~database()
{
    db.close();
}

void database::createDatabase()
{
    QSqlQuery query;

    query.exec("CREATE TABLE Distances("
               "StartingCollege VARCHAR(60) PRIMARY KEY,"
               "EndingCollege   VARCHAR(60),"
               "Distance        INTEGER);");

    query.exec("CREATE TABLE SouvenirCollege(CollegeName VARCHAR(60) PRIMARY KEY);");

    query.exec("CREATE TABLE SouvenirNamesPrices("
               "TraditionalSouvenir VARCHAR(30) PRIMARY KEY,"
               "Cost NUMERIC);");
}

// TODO: Linked List Iterator to make this easier
void database::addDistancesTable(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance)
{
    QSqlQuery query;

    query.exec("CREATE UNIQUE INDEX idx_startingCollege"
               "ON Distances (StartingCollege)");

    for(int i = 0; i < static_cast<int>(endingCollege.size()); ++i)
    {
        query.bindValue(":startingCollege",startingCollege);
        query.bindValue(":endingCollege", endingCollege[i]);
        query.bindValue(":distance", distance[i]);

        // WILL INSERT IF NEW VALUES EXIST
        query.prepare("REPLACE INTO Distances(StartingCollege, EndingCollege, Distance)"
                      "VALUES(:startingCollege, :endingCollege, :distance)");
    }

    if(!query.exec())
        qDebug() << "Failed: " << query.lastError();
}

// TODO: Linked List Iterator instead of 3 arguments
void database::addSouvenirsTable(QString collegeName, std::vector<QString> souvenirName, std::vector<double> souvenirPricing)
{
    QSqlQuery query;

    query.exec("CREATE UNIQUE INDEX idx_collegeName"
               "ON SouvenirCollege (CollegeName)");

    // TODO: Add an iterator for Souvenir Colleges Table

    query.exec("CREATE UNIQUE INDEX idx_souvenirName"
               "ON SouvenirNamesPrices (TraditionalSouvenir)");

    // TODO: Add an iterator for Souvenir Names & Prices Table

    if(query.exec())
        qDebug() << "UPDATE WORKED!";
    else
        qDebug() << "UPDATE DID NOT WORK";
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
