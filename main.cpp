#include "listSchools.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLinkedList<const char*> allSouvenirs;
    QLinkedList<campus> newList;
    allSouvenirs.push_back("a");
    allSouvenirs.push_back("b");
    newList.push_back(campus(10, "ABC", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("c");
    allSouvenirs.push_back("d");
    newList.push_back(campus(15, "FLK", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("e");
    newList.push_back(campus(43, "UCI", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("f");
    allSouvenirs.push_back("g");
    newList.push_back(campus(102, "IBM", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("h");
    allSouvenirs.push_back("i");
    allSouvenirs.push_back("j");
    newList.push_back(campus(76, "LOZ", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("k");
    newList.push_back(campus(90, "SOK", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("l");
    allSouvenirs.push_back("m");
    newList.push_back(campus(31, "MLB", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("n");
    allSouvenirs.push_back("o");
    newList.push_back(campus(57, "TLE", allSouvenirs));
    allSouvenirs.clear();
    allSouvenirs.push_back("p");
    ListSchools w(newList);
    w.show();
    return a.exec();
}
