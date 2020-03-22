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
}

void database::openDatabase()
{
    db.open();
}

void database::createDatabase()
{
    QSqlQuery query;
    query.exec("CREATE TABLE Distances ("
               "StartingCollege VARCHAR(60),"
               "EndingCollege VARCHAR(60),"
               "DistanceBetween NUMERIC,"
               "UNIQUE (StartingCollege, EndingCollege));");

    query.exec("CREATE TABLE Souvenirs ("
               "College VARCHAR(60)," // Per column
               "TraditionalSouvenirs VARCHAR(30),"
               "Cost NUMERIC,"
               "UNIQUE (College, TraditionalSouvenirs));");

    query.clear();
}

void database::printDistancesTable()
{
}

void database::insertDistanceTable(QString key, QString temp1, double temp2)
{
    QSqlQuery query(db);
    query.prepare("INSERT OR IGNORE INTO Distances (StartingCollege, EndingCollege, DistanceBetween)"
                  "VALUES (:startingCollege, :endingCollege, :distanceBetween);");

    query.bindValue(":startingCollege", key);
    query.bindValue(":endingCollege", temp1);
    query.bindValue(":distanceBetween", temp2);

    if(!query.exec())
        qDebug() << "ERROR: " << query.lastError();
    query.clear();
}

void database::insertSouvenirTable(QString key, QString temp1, double temp2)
{
    QSqlQuery query(db);
    query.prepare("INSERT OR IGNORE INTO Souvenirs (College, TraditionalSouvenirs, Cost)"
                  "VALUES (:college, :traditionalSouvenirs, :cost);");

    query.bindValue(":college", key);
    query.bindValue(":traditionalSouvenirs", temp1);
    query.bindValue(":cost", temp2);

    if(!query.exec())
        qDebug() << "ERROR: " << query.lastError();
    query.clear();
}

QSqlDatabase database::getDatabase()
{
    return db;
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
    colleges::tempVectoredPair tempDataset;
    QString key, temp1, comparison;
    double temp2;
    for(int x = 2; x != row; ++x)
    {
        key = sheet->querySubObject("Cells(int, int)", x, 1)->dynamicCall("Value()").toString(); // retrieve key from first column
        temp1 = sheet->querySubObject("Cells(int, int)", x, 2)->dynamicCall("Value()").toString(); // get data from second column

        if(worksheetNumber == 1 || worksheetNumber == 3)
        {
            temp2 = sheet->querySubObject("Cells(int, int)", x, 3)->dynamicCall("Value()").toDouble(); // get data from third column
            insertDistanceTable(key, temp1, temp2);
        }

        else if(worksheetNumber == 2)
        {
            temp2 = (sheet->querySubObject("Cells(int, int)", x, 3)->dynamicCall("Value()").toDouble() * 0.0001); // get data from third column
            insertSouvenirTable(key, temp1, temp2);
        }

        tempDataset.push_back({temp1, temp2});

        comparison = sheet->querySubObject("Cells(int, int)", x + 1, 1)->dynamicCall("Value()").toString(); // checks the next row in the first column
        if(key != comparison)
        {
            if(worksheetNumber == 1)
                distanceMap[key] = tempDataset;

            else if(worksheetNumber == 2)
                souvenirMap[key] = tempDataset;

            else if(worksheetNumber == 3)
                insertDistanceMap(key, tempDataset);

            tempDataset.clear();
        }
    }

    excel->dynamicCall("Quit()");
}

std::unordered_map<QString, colleges::distanceVectoredPair> database::getDistanceMap() const
{
    return distanceMap;
}

std::unordered_map<QString, colleges::distanceVectoredPair> database::getSouvenirMap() const
{
    return souvenirMap;
}

void database::insertDistanceMap(QString key, colleges::tempVectoredPair tempDataset)
{
    auto primaryIterator = distanceMap.find(key);
    if(primaryIterator != distanceMap.end())
        for(auto secondaryIterator = tempDataset.begin(); secondaryIterator != tempDataset.end() ; ++secondaryIterator)
            primaryIterator->second.push_back(std::make_pair(secondaryIterator->first, secondaryIterator->second));
    else
        distanceMap[key] = tempDataset;
}

void database::printSouvenirMap()
{
    for(auto it: souvenirMap)
    {
        qDebug() << "College: " << it.first;
        for(auto tempIt : it.second)
        {
            qDebug() << "Traditional Souvenirs: " << tempIt.first;
            qDebug() << "Cost: " << tempIt.second;
        }

        qDebug() << "";
    }
}

void database::printDistanceMap()
{
    for(auto it: distanceMap)
    {
        qDebug() << "Starting College: " << it.first;
        for(auto tempIt : it.second)
        {
            qDebug() << "Ending College: " << tempIt.first;
            qDebug() << "Total Distance: " << tempIt.second;
        }

        qDebug() << "";
    }
}
