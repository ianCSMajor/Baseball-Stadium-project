#include "addsouvenirs.h"
#include "ui_addsouvenirs.h"

addSouvenirs::addSouvenirs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addSouvenirs)
{
    ui->setupUi(this);
    QRegExpValidator *onlyNums = new QRegExpValidator(QRegExp("\\d*[\\.,]?\\d+"), this);
    ui->addSouvenirs_priceSouvenirLineEditEnabled->setValidator(onlyNums);
}

addSouvenirs::~addSouvenirs()
{
    delete ui;
}

void addSouvenirs::setLabel(QString key)
{
    ui->addSouvenirs_selectedCollegeLineEditDisabled->setText(key);
}

void addSouvenirs::on_addSouvenirs_addButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO Souvenirs (College, TraditionalSouvenirs, Cost)"
                  "VALUES (:college, :traditionalSouvenirs, :cost);");

    query.bindValue(":college", ui->addSouvenirs_selectedCollegeLineEditDisabled->text());
    query.bindValue(":traditionalSouvenirs", ui->addSouvenirs_nameSouvenirLineEditEnabled->text());
    query.bindValue(":cost", ui->addSouvenirs_priceSouvenirLineEditEnabled->text());

    if(!query.exec())
        qDebug() << "ERROR: " << query.lastError();
    query.clear();
    this->close();
}
