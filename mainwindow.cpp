#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDatabase()
{
    QSqlDatabase mainDB = QSqlDatabase::addDatabase("QSQLITE");

    // TODO: Find out how to save relative paths on qt, easier for other
    // members to push/pull code and build
    // mainDB.setDatabaseName("../database test/db.sqlite");

    if(mainDB.open())
    {
        // ui->pushButton_login->setText("Database worked");

        //! This is code that gets read into the SQLite database
        //! <Generates a table and 3 columns>
        QString query = "CREATE TABLE testTable ("
                        "College VARCHAR(50),"
                        "Traditional Souvenirs VARCHAR(25),"
                        "Cost double);";

        QSqlQuery qry;
        qry.exec(query);
    }

}

void MainWindow::on_pushButton_login_clicked()
{

}
