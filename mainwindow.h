#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header.h"
#include "database.h"
#include "plantrips.h"
#include "addsouvenirs.h"

namespace Ui
{
    class MainWindow;
}

enum setIndex
{
    MAIN_MENU      = 0,
    VIEW_COLLEGES  = 1,
    PLAN_TRIPS     = 2,
    ADMIN_LOGIN    = 3,
    ADMIN_COMMANDS = 4
};

namespace viewColleges
{
    extern QString startingCollege;
}

namespace adminCommands
{
    extern QString selectedCollege;
    extern QString selectedSouvenirName;
    extern QString selectedSouvenirPrice;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, database *temp = new database);

    void setStartingComboBoxes();

    QStringList getViewColleges_SouvenirDisplayList(const QString &key);
    QStringList getadminCommands_SouvenirDisplayList(const QString &key);
    ~MainWindow();

private slots:
    void on_planTripsButton_clicked();
    void on_planTrips_backButton_clicked();
    void on_planTrips_displayStartingColleges_activated(const QModelIndex &index);
    void on_planTrips_displayPlannedColleges_activated(const QModelIndex &index);

    void on_signInButton_clicked();
    void on_adminLoginButton_clicked();
    void on_adminLogin_backButton_clicked();

    void on_adminCommands_backButton_clicked();
    void on_adminCommands_loadNewCollegesButton_clicked();
    void on_adminCommands_selectCollegeComboBox_activated(const QString &arg1);
    void on_adminCommands_displaySouvenirList_activated(const QModelIndex &index);

    void on_viewCollegesButton_clicked();
    void on_viewColleges_backButton_clicked();
    void on_viewColleges_startingCollegeComboBox_activated(const QString &arg1);
    void on_viewColleges_startingCollegeComboBox_currentIndexChanged(const QString &arg1);
    void on_viewColleges_displayList_activated(const QModelIndex &index);
    void on_viewColleges_endingCollegeComboBox_activated(const QString &arg1);

    void on_adminCommands_saveEditButton_clicked();

    void on_adminCommands_addButtonButton_clicked();

    void on_adminCommands_deleteButtonButton_clicked();

    void on_planTrips_startButton_clicked();

    void on_planTrips_PSTButton_clicked();

    void on_planTrips_VACButton_clicked();

    void on_planTrips_addAllCollegesButton_clicked();
    
private:
    Ui::MainWindow *ui;
    database *db;
};

#endif // MAINWINDOW_H
