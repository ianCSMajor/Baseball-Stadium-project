#ifndef HEADER_H
#define HEADER_H

/* (JONATHAN):
 * When adding stuff to the header refer to the
 * collegetouring.pro and look at the: (QT += core sql gui)
 * the #include should be in order with this
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
#include "qaxobject.h"

// STL
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#endif // !HEADER_H
