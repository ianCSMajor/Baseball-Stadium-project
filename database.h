#ifndef DATABASE_H
#define DATABASE_H

#include "header.h"

namespace colleges
{
    typedef std::set<std::pair<QString, double>> distance; // set of ending college, distance
    typedef std::set<std::pair<QString, double>> souvenir; // set of souvenir names and prices
}

class database
{
private:
    QSqlDatabase db;
    std::map<QString, colleges::distance> distanceMap; // Key is starting college
    std::map<QString, colleges::souvenir> souvenirMap; // Key is name of college

public:
    database();
    ~database();

    void createDatabase();
    void readExcelFile(int worksheetNumber, int row);

    auto getDistanceMap() const;
    auto getSouvenirMap() const;

    void insertDistanceMapset(QString key, QString endingCollege, double distance);
    void insertSouvenirMapset(QString key, QString souvenirName, double price);

    auto getDistanceSetPair(QString searchKey);
    auto getSouvenirSetPair(QString searchKey);

    auto iterateDistanceValue(QString searchKey);
    auto iterateSouvenirValue(QString searchKey);

    QString getDistanceMapKey(QString search);
    QString getSouvenirMapKey(QString search);

};

#endif // DATABASE_H
