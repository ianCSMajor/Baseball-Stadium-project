#ifndef PLANTRIP_H
#define PLANTRIP_H

#include <QDialog>
#include <QListWidgetItem>
#include "Header.h"

namespace Ui {class PlanTrip;}

class PlanTrip : public QDialog
{
    Q_OBJECT

public:
    PlanTrip(QWidget *parent = nullptr);
    PlanTrip(QLinkedList<campus> inpCamList, QWidget *parent = nullptr);
    ~PlanTrip();

private:
    Ui::PlanTrip *ui;
    QLinkedList<campus> setNav(QLinkedList<campus> schools);

private slots:


};

class tripCampus
{
    const char* name;
    int distance;
    bool selected;

public:
    tripCampus() : name{"\\unknown\\"}, distance{-1}, selected{false} {}
    tripCampus(campus inpCampus) : name{inpCampus.getName()}, distance{inpCampus.getDistance()}, selected{false} {}
    const char* getName() {return name;};
    int getDistance() {return distance;};
    bool hasBeenSelected() {return selected;};
    void select() {selected = true;};
};

#endif // PLANTRIP_H
