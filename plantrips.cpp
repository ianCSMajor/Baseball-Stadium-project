#include "plantrips.h"
#include "ui_plantrips.h"

planTrips::planTrips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::planTrips)
{
    ui->setupUi(this);
}

planTrips::~planTrips()
{
    delete ui;
}

void planTrips::on_planTripsUI_continueTouringButton_clicked()
{

}

void planTrips::on_planTripsUI_purchaseButton_clicked()
{

}

void planTrips::on_planTripsUI_souvenirNameListView_activated(const QModelIndex &index)
{

}

void planTrips::on_planTripsUI_shoppingCartNameListView_activated(const QModelIndex &index)
{

}
