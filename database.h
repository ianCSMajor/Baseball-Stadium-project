#ifndef DATABASE_H
#define DATABASE_H

#include "header.h"

class database
{
private:
    QSqlDatabase db;
    QString DB_PATH = "D:/Programming/CS1D-master/CS1D-Projejt--jgrady15/database.sqlite";
    QString EX_PATH = "D:/Programming/CS1D-master/College Touring Project-1/College Campus Distances and Souvenirs.xlsx";

public:
    database();
    ~database();

    void createDatabase();
    void addDistancesTable(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance);
    void addSouvenirsTable(QString collegeName, std::vector<QString> souvenirName, std::vector<double> souvenirPricing);

    void readExcel(QString excelPath, int worksheetNumber, int row, int col);
};

#endif // DATABASE_H
