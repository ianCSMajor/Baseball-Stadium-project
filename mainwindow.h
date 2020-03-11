#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header.h"
#include "database.h"

namespace Ui {
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void setComboBoxes();

    void on_adminLoginButton_clicked();
    void on_viewCollegesButton_clicked();
    void on_planTripsButton_clicked();
    void on_viewColleges_backButton_clicked();
    void on_planTrips_backButton_clicked();
    void on_adminLogin_backButton_clicked();
    void on_adminCommands_backButton_clicked();

private:
    Ui::MainWindow *ui;
    database db;
};

#endif // MAINWINDOW_H
