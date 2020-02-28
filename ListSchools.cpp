#include "listSchools.h"
#include "ui_listSchools.h"

ListSchools::ListSchools(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListSchools)
{
    ui->setupUi(this);

    for(int i = 0; i < campusList.size(); i++)
    {
        ui->campusList->addItem(QString((*(campusList.begin()+i)).getName()));
    }
}

ListSchools::ListSchools(QLinkedList<campus> inpList, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListSchools)
{
    ui->setupUi(this);

    campusList = inpList;

    for(int i = 0; i < campusList.size(); i++)
    {
        ui->campusList->addItem(QString((*(campusList.begin()+i)).getName()));
    }
}

void ListSchools::on_campusList_itemClicked(QListWidgetItem *item)
{
    int i = 0;
    bool found = false;

    while(i < campusList.size() && !found)
    {
        if(item->text() == QString((*(campusList.begin()+i)).getName()))
            found = true;
        else
            i++;
    }

    ui->campusPropList->clear();

    ui->campusPropList->addItem(QString("Distance from Saddleback"));

    if (found)
        ui->campusPropList->addItem(QString((std::to_string((*(campusList.begin()+i)).getDistance())+ " mi").c_str()));
    else
        ui->campusPropList->addItem(QString("ERROR"));

    if((*(campusList.begin()+i)).numberOfSouvenirs() > 0)
    {
        ui->campusPropList->addItem(QString(""));
        ui->campusPropList->addItem(QString("Souvenirs available:"));
        for(int j = 0; j < (*(campusList.begin()+i)).numberOfSouvenirs(); j++)
        {
            ui->campusPropList->addItem(QString((*(campusList.begin()+i)).getSouvenir(j)));
        }
    }
}

void ListSchools::on_planButton_clicked()
{
    newTrip = new PlanTrip(campusList);
    newTrip->show();
}

ListSchools::~ListSchools()
{
    delete ui;
}

