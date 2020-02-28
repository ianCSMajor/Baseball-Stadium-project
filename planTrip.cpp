#include "planTrip.h"
#include "ui_plantrip.h"

PlanTrip::PlanTrip(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlanTrip)
{
    ui->setupUi(this);
    QLinkedList<campus> listOfSchools;

}

PlanTrip::PlanTrip(QLinkedList<campus> inpCamList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlanTrip)
{
    ui->setupUi(this);
    QLinkedList<campus> listOfSchools = setNav(inpCamList);
    for(int i = 0; i < listOfSchools.size(); i++)
    {
        ui->tripList->addItem(QString((*(listOfSchools.begin()+1)).getName()));
    }
}

QLinkedList<campus> PlanTrip::setNav(QLinkedList<campus> schools)
{
    QLinkedList<tripCampus> tripOrder;
    QLinkedList<campus> orderedSchools;
    int smallestDist = INT_MAX;
    int smallestDistInx = 0;
    int prevDist = 0;
    bool exit = false;

    for(int i = 0; i < schools.size(); i++)
    {
        tripOrder.push_back(tripCampus(*(schools.begin()+i)));
    }

    for(int i = 0; i < tripOrder.size() && !exit; i++)
    {
        if(strncmp((*(tripOrder.begin()+i)).getName(), "UCI", 3))
        {
            orderedSchools.push_back((*(schools.begin()+i)));
            prevDist = (*(schools.begin()+i)).getDistance();

            for(int i = 0; i < schools.size(); i++)
            {
                smallestDist = INT_MAX;
                for(int j = 0; j < tripOrder.size(); j++)
                {
                    if(abs((*(tripOrder.begin()+j)).getDistance() - prevDist) < smallestDist && !(*(tripOrder.begin()+j)).hasBeenSelected())
                    {
                        smallestDist = (*(tripOrder.begin()+j)).getDistance();
                        smallestDistInx = j;
                    }
                }
                orderedSchools.push_back((*(schools.begin()+smallestDistInx)));
                (tripOrder.begin()+smallestDistInx)->select();
            }
            exit = true;
        }
    }
    if(orderedSchools.size() == 0)
    {
        orderedSchools.push_back(campus(0, "Error"));
    }

    return orderedSchools;
}

PlanTrip::~PlanTrip(){}
