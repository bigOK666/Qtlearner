#include <QtWidgets>
#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);//will automatically connect lineEdit's signal textChanged to slot on_lineEdit_textChanged()

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));//making the 匿名对象成为GoToCellDialog的子对象

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()),this, SLOT(regect()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
