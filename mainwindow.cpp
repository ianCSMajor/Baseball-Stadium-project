#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace viewColleges
{
    QString startingCollege;
}

namespace adminCommands
{
    QString selectedCollege;
    QString selectedSouvenirName;
    QString selectedSouvenirPrice;
}

MainWindow::MainWindow(QWidget *parent, database *temp) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    db = temp;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(MAIN_MENU);
    setStartingComboBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStartingComboBoxes()
{
    QSqlRecord record;
    QStringList tempList;
    QSqlQuery query1;

    query1.prepare("SELECT DISTINCT StartingCollege FROM Distances ORDER BY StartingCollege;");
    if(!query1.exec())
        qDebug() << query1.lastError();

    while(query1.next())
    {
        record = query1.record();
//      qDebug() << record.value(0).toString();
        tempList << record.value(0).toString();
    }

    ui->viewColleges_startingCollegeComboBox->addItems(tempList);
    ui->adminCommands_selectCollegeComboBox->addItems(tempList);
    ui->planTrips_displayStartingColleges->addItems(tempList);

    QRegExpValidator *onlyNums = new QRegExpValidator(QRegExp("\\d*[\\.,]?\\d+"), this);
    ui->adminCommands_souvenirPriceLineEdit->setValidator(onlyNums);
}

// -------------------------ADMIN LOGIN PAGE----------------------------
// ---------------------------------------------------------------------
// -------------------------START---------------------------------------

void MainWindow::on_signInButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if(username == "admin" && password == "password")
        ui->stackedWidget->setCurrentIndex(ADMIN_COMMANDS);
    else
        QMessageBox::warning(this, "Admin Login", "Information incorrect. Try again.");
}

// ---------------------------------------------------------------------
// -------------------------END-----------------------------------------
// ---------------------------------------------------------------------
// -------------------------ADMIN COMMANDS PAGE-------------------------
// ---------------------------------------------------------------------
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

void MainWindow::on_adminCommands_selectCollegeComboBox_activated(const QString &key)
{
    adminCommands::selectedCollege = key;
    ui->adminCommands_displaySouvenirList->clear();
    ui->adminCommands_displaySelectCollegeLineEditDisabled->setText(key);
    ui->adminCommands_displaySouvenirList->addItems(getadminCommands_SouvenirDisplayList(key));
}

void MainWindow::on_adminCommands_displaySouvenirList_activated(const QModelIndex &index)
{
    QSqlQuery query;
    QSqlRecord record;
    double itemPrice;
    QString value;

    value = ui->adminCommands_displaySouvenirList->model()->data(index).toString();

    query.prepare("SELECT Cost FROM Souvenirs WHERE College = :c AND TraditionalSouvenirs = :ts;");
    query.bindValue(":c", adminCommands::selectedCollege);
    query.bindValue(":ts", value);

    if(!query.exec())
        qDebug() << query.lastError();

    while(query.next())
    {
        record = query.record();
        itemPrice = record.value(0).toDouble();
    }

    adminCommands::selectedSouvenirName = value;
    adminCommands::selectedSouvenirPrice = QString::number(itemPrice, 'G', 5);

    ui->adminCommands_souvenirNameLineEdit->setText(value);
    ui->adminCommands_souvenirPriceLineEdit->setText(QString::number(itemPrice, 'G', 5));
}

QStringList MainWindow::getadminCommands_SouvenirDisplayList(const QString &key)
{
    QSqlQuery query;
    QSqlRecord record;
    QStringList souvenirs;

    // SOUVENIR LIST VIEW //
    query.prepare("SELECT TraditionalSouvenirs FROM Souvenirs WHERE College = :selectedCollege;");
    query.bindValue(":selectedCollege", key);

    if(!query.exec())
        qDebug() << query.lastError();

    while(query.next())
    {
        record = query.record();
//      qDebug() << record.value(0).toString();
        souvenirs << record.value(0).toString();
    }

    return souvenirs;
}

void MainWindow::on_adminCommands_loadNewCollegesButton_clicked()
{
    this->close();
    qDebug() << "Reading New Campuses...";
    db->readExcelFile(3, 47);
    ui->viewColleges_startingCollegeComboBox->clear();
    ui->viewColleges_endingCollegeComboBox->clear();
    ui->viewColleges_displayList->clear();

    ui->adminCommands_selectCollegeComboBox->clear();
    ui->adminCommands_displaySouvenirList->clear();

    ui->planTrips_displayStartingColleges->clear();
    ui->planTrips_displayPlannedColleges->clear();

    setStartingComboBoxes();
    qDebug() << "Finished Reading!";

    this->show();
}

void MainWindow::on_adminCommands_saveEditButton_clicked()
{
    QSqlRecord record;
    QStringList traditionalSouvenir;
    QSqlQuery query1, query2, query3;
//
    query1.prepare("DELETE FROM Souvenirs WHERE College = :c AND TraditionalSouvenirs = :ts AND Cost = :cost;");
    query1.bindValue(":c", adminCommands::selectedCollege);
    query1.bindValue(":ts", adminCommands::selectedSouvenirName);
    query1.bindValue(":cost", adminCommands::selectedSouvenirPrice);

    if(!query1.exec())
        qDebug() << query1.lastError();
//
    query2.prepare("INSERT OR IGNORE INTO Souvenirs (College, TraditionalSouvenirs, Cost) VALUES (:college, :traditionalSouvenirs, :cost);");
    query2.bindValue(":college", adminCommands::selectedCollege);
    query2.bindValue(":traditionalSouvenirs", ui->adminCommands_souvenirNameLineEdit->text());
    query2.bindValue(":cost", ui->adminCommands_souvenirPriceLineEdit->text());

    if(!query2.exec())
        qDebug() << query2.lastError();
//
    ui->adminCommands_displaySouvenirList->clear();
    query3.prepare("SELECT TraditionalSouvenirs FROM Souvenirs WHERE College = :c;");
    query3.bindValue(":c", adminCommands::selectedCollege);

    if(!query3.exec())
        qDebug() << query3.lastError();

    while(query3.next())
    {
        record = query3.record();
        traditionalSouvenir << record.value(0).toString();
    }

    ui->adminCommands_displaySouvenirList->addItems(traditionalSouvenir);
}

void MainWindow::on_adminCommands_addButtonButton_clicked()
{
    addSouvenirs *newInstance = new addSouvenirs;
    newInstance->setLabel(adminCommands::selectedCollege);
    newInstance->show();
}

void MainWindow::on_adminCommands_deleteButtonButton_clicked()
{
    QSqlQuery query;
    QString temp1, temp2, temp3;
    temp1 = adminCommands::selectedCollege;
    temp2 = adminCommands::selectedSouvenirName;
    temp3 = adminCommands::selectedSouvenirPrice;

    query.prepare("DELETE FROM Souvenirs WHERE College = :c AND TraditionalSouvenirs = :ts AND Cost = :cost;");
    query.bindValue(":c", temp1);
    query.bindValue(":ts", temp2);
    query.bindValue(":cost", temp3);

    qDebug() << temp1;
    qDebug() << temp2;
    qDebug() << temp3;

    if(!query.exec())
        qDebug() << query.lastError();

    ui->adminCommands_souvenirNameLineEdit->clear();
    ui->adminCommands_souvenirPriceLineEdit->clear();
    ui->adminCommands_displaySouvenirList->clear();
    ui->adminCommands_displaySouvenirList->addItems(getadminCommands_SouvenirDisplayList(temp1));

    ui->viewColleges_displayList->clear();
    ui->viewColleges_productPrice->clear();
}

// ---------------------------------------------------------------------
// -------------------------END-----------------------------------------
// ---------------------------------------------------------------------
// -------------------------VIEW COLLEGES PAGE--------------------------
// ---------------------------------------------------------------------
// -------------------------START---------------------------------------

void MainWindow::on_viewCollegesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::VIEW_COLLEGES);
}

void MainWindow::on_viewColleges_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::MAIN_MENU);
}

void MainWindow::on_viewColleges_startingCollegeComboBox_activated(const QString &key)
{
    QSqlQuery query;
    QSqlRecord record;
    QStringList endingCollege;

    // ENDING COLLEGE COMBO BOX //
    query.prepare("SELECT DISTINCT EndingCollege FROM Distances WHERE StartingCollege = :startingCollege ORDER BY EndingCollege;");
    query.bindValue(":startingCollege", key);

    if(!query.exec())
        qDebug() << query.lastError();

    while(query.next())
    {
        record = query.record();
//      qDebug() << record.value(0).toString();
        endingCollege << record.value(0).toString();
    }

    ui->viewColleges_endingCollegeComboBox->clear();
    ui->viewColleges_displayList->clearSelection();
    ui->viewColleges_displayList->clear();

    ui->viewColleges_collegeSelected->setText(key);
    ui->viewColleges_endingCollegeComboBox->addItems(endingCollege);
    ui->viewColleges_displayList->addItems(getViewColleges_SouvenirDisplayList(key));
    viewColleges::startingCollege = key;
}

QStringList MainWindow::getViewColleges_SouvenirDisplayList(const QString &key)
{
    QSqlQuery query;
    QSqlRecord record;
    QStringList souvenirs;

    // SOUVENIR LIST VIEW //
    query.prepare("SELECT TraditionalSouvenirs FROM Souvenirs WHERE College = :selectedCollege;");
    query.bindValue(":selectedCollege", key);

    if(!query.exec())
        qDebug() << query.lastError();

    while(query.next())
    {
        record = query.record();
//      qDebug() << record.value(0).toString();
        souvenirs << record.value(0).toString();
    }

    return souvenirs;
}

void MainWindow::on_viewColleges_displayList_activated(const QModelIndex &index)
{
    QSqlQuery query;
    QSqlRecord record;
    QString value;
    double temp;
    value = ui->viewColleges_displayList->model()->data(index).toString();

    query.prepare("SELECT Cost FROM Souvenirs WHERE College = :c AND TraditionalSouvenirs = :ts;");
    query.bindValue(":c", viewColleges::startingCollege);
    query.bindValue(":ts", value);

    if(!query.exec())
        qDebug() << query.lastError();

    while(query.next())
    {
        record = query.record();
        temp = record.value(0).toDouble();
    }

    ui->viewColleges_productPrice->setText("$" + QString::number(temp, 'G', 4));
}

void MainWindow::on_viewColleges_endingCollegeComboBox_activated(const QString &endingCollege)
{
    QString temp;
    QSqlQuery query;
    QSqlRecord record;

    // ENDING COLLEGE COMBO BOX //
    query.prepare("SELECT DISTINCT DistanceBetween FROM Distances WHERE StartingCollege = '" + viewColleges::startingCollege + "' AND EndingCollege = '" + endingCollege + "';");
    if(!query.exec())
        qDebug() << query.lastError();

    while(query.next())
    {
        record = query.record();
        temp = record.value(0).toString();
    }

    ui->viewColleges_totalDistance->setText(temp);
}

void MainWindow::on_viewColleges_startingCollegeComboBox_currentIndexChanged(const QString &arg1)
{
}

// ---------------------------------------------------------------------
// -------------------------END-----------------------------------------
// ---------------------------------------------------------------------
// -------------------------PLAN TRIPS PAGE-----------------------------
// ---------------------------------------------------------------------
// -------------------------START---------------------------------------

void MainWindow::on_planTripsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::PLAN_TRIPS);
}

void MainWindow::on_planTrips_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(setIndex::MAIN_MENU);
}

void MainWindow::on_planTrips_displayStartingColleges_activated(const QModelIndex &index)
{
    QString value = ui->planTrips_displayStartingColleges->model()->data(index).toString();

    ui->planTrips_displayStartingColleges->model()->removeRow(ui->planTrips_displayStartingColleges->currentRow());
    ui->planTrips_displayPlannedColleges->addItem(value);
}

void MainWindow::on_planTrips_displayPlannedColleges_activated(const QModelIndex &index)
{
    QString value = ui->planTrips_displayPlannedColleges->model()->data(index).toString();

    ui->planTrips_displayPlannedColleges->model()->removeRow(ui->planTrips_displayPlannedColleges->currentRow());
    ui->planTrips_displayStartingColleges->addItem(value);
}

// PLAN CUSTOM TRIP
void MainWindow::on_planTrips_startButton_clicked()
{
    
}

// PLAN SHORTEST TRIP
void MainWindow::on_planTrips_PSTButton_clicked()
{

}

// VISIT ALL COLLEGES
void MainWindow::on_planTrips_VACButton_clicked()
{

}

void MainWindow::on_planTrips_addAllCollegesButton_clicked()
{
    for(int i = 0; i < ui->planTrips_displayStartingColleges->count(); ++i)
        ui->planTrips_displayPlannedColleges->addItem(ui->planTrips_displayStartingColleges->item(i)->text());
    
	ui->planTrips_displayStartingColleges->clear();
}

// ---------------------------------------------------------------------
// -------------------------END-----------------------------------------
// ---------------------------------------------------------------------
