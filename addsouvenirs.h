#ifndef ADDSOUVENIRS_H
#define ADDSOUVENIRS_H

#include "header.h"

namespace Ui {
class addSouvenirs;
}

class addSouvenirs : public QWidget
{
    Q_OBJECT

public:
    explicit addSouvenirs(QWidget *parent = nullptr);
    void setLabel(QString key);
    ~addSouvenirs();

private slots:
    void on_addSouvenirs_addButton_clicked();

private:
    Ui::addSouvenirs *ui;
};

#endif // ADDSOUVENIRS_H
