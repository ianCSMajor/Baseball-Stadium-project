#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(MAIN_MENU);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setComboBoxes()
{
//    ui->adminCommands_selectCollegeComboBox->addItem()
}

// -------------------------ADMIN COMMANDS PAGE-------------------------
// -------------------------START---------------------------------------
void MainWindow::on_adminLoginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::ADMIN_LOGIN);
}

void MainWindow::on_adminLogin_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::MAIN_MENU);
}

void MainWindow::on_adminCommands_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::ADMIN_LOGIN);
}
// -------------------------END-----------------------------------------

// -------------------------VIEW COLLEGES PAGE--------------------------
// -------------------------START---------------------------------------
void MainWindow::on_viewCollegesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::VIEW_COLLEGES);
}

void MainWindow::on_viewColleges_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::MAIN_MENU);
}
// -------------------------END-----------------------------------------

// -------------------------PLAN TRIPS PAGE-----------------------------
// -------------------------START---------------------------------------
void MainWindow::on_planTripsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::PLAN_TRIPS);
}

void MainWindow::on_planTrips_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::MAIN_MENU);
}
// -------------------------END-----------------------------------------
