#ifndef LISTSCHOOLS_H
#define LISTSCHOOLS_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "planTrip.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ListSchools; }
QT_END_NAMESPACE

class ListSchools : public QMainWindow
{
    Q_OBJECT

public:
    ListSchools(QWidget *parent = nullptr);
    ListSchools(QLinkedList<campus> inpList, QWidget *parent = nullptr);
    ~ListSchools();

private:
    Ui::ListSchools *ui;
    PlanTrip* newTrip;
    QLinkedList<campus> campusList;

private slots:
    void on_campusList_itemClicked(QListWidgetItem *item);
    void on_planButton_clicked();
};
#endif // LISTSCHOOLS_H
