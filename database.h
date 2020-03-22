#ifndef DATABASE_H
#define DATABASE_H

#include "header.h"

namespace colleges
{
    typedef std::vector<std::pair<QString, double>> distanceVectoredPair; // set of ending college, distance
    typedef std::vector<std::pair<QString, double>> souvenirVectoredPair; // set of souvenir names and prices
    typedef std::vector<std::pair<QString, double>> tempVectoredPair; // temp data set for readExcelFile
}

class database
{
private:
    QSqlDatabase db;
    std::unordered_map<QString, colleges::distanceVectoredPair> distanceMap; // Key is starting college
    std::unordered_map<QString, colleges::souvenirVectoredPair> souvenirMap; // Key is name of college

public:
    database();
    ~database();

    // DATABASE FUNCTIONS
    void openDatabase();
    void createDatabase();
    void printDistancesTable();

    void insertDistanceTable(QString key, QString temp1, double temp2);
    void insertSouvenirTable(QString key, QString temp1, double temp2);

    QSqlDatabase getDatabase();

    // EXCEL FUNCTIONS
    void readExcelFile(int worksheetNumber, int row);

    // MAP VECTORED PAIR FUNCTIONS
    std::unordered_map<QString, colleges::distanceVectoredPair> getDistanceMap() const;
    std::unordered_map<QString, colleges::distanceVectoredPair> getSouvenirMap() const;

    QString displayDistanceKey() const;
    QString displaySouvenirKey() const;

    void editSouvenirName();
    void editSouvenirPrice();

    void printDistanceMap();
    void printSouvenirMap();

    void insertDistanceMap(QString key, colleges::tempVectoredPair temp);
    QString getSouvenirMapKey(QString search);

};

#endif // DATABASE_H
