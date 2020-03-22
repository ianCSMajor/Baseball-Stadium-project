#ifndef PLANTRIPS_H
#define PLANTRIPS_H

#include "header.h"

namespace Ui {
class planTrips;
}

class planTrips : public QWidget
{
    Q_OBJECT

public:
    explicit planTrips(QWidget *parent = nullptr);
    ~planTrips();

private slots:
    void on_planTripsUI_continueTouringButton_clicked();

    void on_planTripsUI_purchaseButton_clicked();

    void on_planTripsUI_shoppingCartNameListView_activated(const QModelIndex &index);

    void on_planTripsUI_souvenirNameListView_activated(const QModelIndex &index);

private:
    Ui::planTrips *ui;
};

#endif // PLANTRIPS_H
