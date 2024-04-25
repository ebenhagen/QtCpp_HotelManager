#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"

ChangePasswordDialog::ChangePasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasswordDialog)
{
    ui->setupUi(this);

    //设置固定尺寸
    this->setFixedSize(400, 300);
    //设置标题
    this->setWindowTitle("酒店管理系统");
    //设置图标
    this->setWindowIcon(QIcon(":/images/hotel_icon.svg"));
}

ChangePasswordDialog::~ChangePasswordDialog()
{
    delete ui;
}

void ChangePasswordDialog::on_btnChange_clicked()
{
    if (ui->letNewP->text() != ui->letOkNewP->text()) {
        QMessageBox::warning(this, "警告", "两次输入的新密码不一致");
        ui->letOkNewP->clear();
    }
    else {
        emit changePassword(ui->letOkNewP->text());
        on_btnCancel_clicked();
    }
}


void ChangePasswordDialog::on_btnCancel_clicked()
{
    ui->letNewP->clear();
    ui->letOkNewP->clear();
    this->hide();
}

