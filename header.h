#ifndef HEADER_H
#define HEADER_H

/* (JONATHAN):
 * When adding stuff to the header refer to the
 * collegetouring.pro and look at the: (QT += core sql gui)
 * the #include should be in contiguous order like above
 */

// CORE
#include <QCoreApplication>
#include <QApplication>
#include <QVector>
#include <QList>
#include <QDebug>
#include <QFile>

// SQL
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

// GUI
#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QPixmap>

// AXCONTAINER
//#include "qaxobject.h"
#include <QAxObject>

// STL
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

#define DB_PATH "D:/Programming/CS1D-master/CS1D-Projejt--jgrady15/database.sqlite"
#define EX_PATH "D:/Programming/CS1D-master/College Touring Project-1/College Campus Distances and Souvenirs"

typedef std::set<std::pair<QString, double>> PairedSet;

#endif // !HEADER_H
