#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_PATH);
    db.setConnectOptions(DB_PATH);

    if(QFile::exists(DB_PATH))
    {
        if(db.open())
        {
            qDebug() << "path exists, connection success";
            createDatabase();
        }
        else
            qDebug() << "path does not exist, connection failed";
    }
}

database::~database()
{
    db.close();
}

void database::createDatabase()
{
    QSqlQuery query;
    query.exec("CREATE TABLE Distances("
               "StartingCollege VARCHAR(60) UNIQUE KEY,"
               "EndingCollege   VARCHAR(60),"
               "DistanceBetween NUMERIC);");

    query.exec("CREATE TABLE Souvenirs("
               "College VARCHAR(60) PRIMARY KEY,"
               "TraditionalSouvenirs VARCHAR(30) UNIQUE KEY,"
               "Cost NUMERIC);");
}

void database::readExcelFile(int worksheetNumber, int row)
{
    // Setting up excel stuff
    auto excel     = new QAxObject("Excel.Application");
    auto workbooks = excel->querySubObject("Workbooks");
    auto workbook  = workbooks->querySubObject("Open(const QString&)", EX_PATH);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", worksheetNumber);    // 1 is Distances, 2 is Souvenirs

    // Variables to be used in for loop
    QString key, temp1;
    double temp2;
    PairedSet tempPair;
    for(int x = 2; x != row; ++x)
    {
        key = sheet->querySubObject("Cells(int, int)", x, 1)->dynamicCall("Value()").toString();
        temp1 = sheet->querySubObject("Cells(int, int)", x, 2)->dynamicCall("Value()").toString();
        temp2 = sheet->querySubObject("Cells(int, int)", x, 3)->dynamicCall("Value()").toDouble();
        std::make_pair(temp1, temp2);

        if(key != sheet->querySubObject("Cells(int, int)", x + 1, 1)->dynamicCall("Value()").toString())
        {
            if(worksheetNumber == 1 || worksheetNumber == 3)
                distanceMap.insert({key, tempPair});
            else if(worksheetNumber == 2)
                souvenirMap.insert({key, tempPair});
        }

    }

    if(worksheetNumber == 1)
    {
        for(int x = 2; x <= 111; ++x)
        {
            auto cell = sheet->querySubObject("Cells(int, int)", x, 1);
            key = cell->dynamicCall("Value()").toString();

            cell = sheet->querySubObject("Cells(int, int)", x, 2);
            tempDistance.endingCollege.push_back(cell->dynamicCall("Value()").toString());

            cell = sheet->querySubObject("Cells(int, int)", x, 3);
            tempDistance.totalDistance.push_back(cell->dynamicCall("Value()").toInt());

            // populateDistancesTable(tempDistance.startingCollege, tempDistance.endingCollege[i], tempDistance.totalDistance[i]);
            // ++i;
            if(tempDistance.startingCollege != sheet->querySubObject("Cells(int, int)", x + 1, 1)->dynamicCall("Value()").toString())
            {
                distance.push_back(tempDistance);

                tempDistance.endingCollege.clear();
                tempDistance.totalDistance.clear();
                // i = 0;
            }
        }
    }

    // Calls the souvenirs worksheet
    else if (worksheetNumber == 2)
    {
        for(int x = 2; x <= 61; ++x)
        {
            auto cell = sheet->querySubObject("Cells(int, int)", x, 1);
            tempSouvenir.collegeName = cell->dynamicCall("Value()").toString();

            cell = sheet->querySubObject("Cells(int, int)", x, 2);
            tempSouvenir.souvenirName.push_back(cell->dynamicCall("Value()").toString());

            cell = sheet->querySubObject("Cells(int, int)", x, 3);
            tempSouvenir.souvenirPricing.push_back(cell->dynamicCall("Value()").toDouble());

            // populateSouvenirsTable(tempSouvenir.collegeName, tempSouvenir.souvenirName[i], tempSouvenir.souvenirPricing[i]);
            // ++i;
            if(tempSouvenir.collegeName != sheet->querySubObject("Cells(int, int)", x + 1, 1)->dynamicCall("Value()").toString())
            {
                souvenir.push_back(tempSouvenir);

                tempSouvenir.souvenirName.clear();
                tempSouvenir.souvenirPricing.clear();
                // i = 0;
            }
        }
    }

    else if (worksheetNumber == 3)
    {
        for(int x = 2; x <= 47; ++x)
        {
            auto cell = sheet->querySubObject("Cells(int, int)", x, 1);
            tempSouvenir.collegeName = cell->dynamicCall("Value()").toString();

            cell = sheet->querySubObject("Cells(int, int)", x, 2);
            tempSouvenir.souvenirName.push_back(cell->dynamicCall("Value()").toString());

            cell = sheet->querySubObject("Cells(int, int)", x, 3);
            tempSouvenir.souvenirPricing.push_back(cell->dynamicCall("Value()").toDouble());

            // populateSouvenirsTable(tempSouvenir.collegeName, tempSouvenir.souvenirName[i], tempSouvenir.souvenirPricing[i]);
            // ++i;
            if(tempSouvenir.collegeName != sheet->querySubObject("Cells(int, int)", x + 1, 1)->dynamicCall("Value()").toString())
            {
                souvenir.push_back(tempSouvenir);

                tempSouvenir.souvenirName.clear();
                tempSouvenir.souvenirPricing.clear();
                // i = 0;
            }
        }
    }

    excel->dynamicCall("Quit()");
}

auto database::getDistanceMap() const
{
    return distanceMap;
}

auto database::getSouvenirMap() const
{
    return souvenirMap;
}

void database::insertDistanceMap(QString key, QString endingCollege, double distance)
{

}

void database::insertSouvenirMap(QString key, QString souvenirName, double price)
{

}

auto database::getDistanceVectoredPair(QString searchKey)
{

}

auto database::getSouvenirVectoredPair(QString searchKey)
{

}

auto database::iterateDistanceValue(QString searchKey)
{

}

auto database::iterateSouvenirValue(QString searchKey)
{

}

QString database::getDistanceMapKey(QString search)
{

}

QString database::getSouvenirMapKey(QString search)
{

}
