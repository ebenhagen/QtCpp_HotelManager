#include "changeroominfodialog.h"
#include "ui_changeroominfodialog.h"

ChangeRoomInfoDialog::ChangeRoomInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeRoomInfoDialog)
{
    ui->setupUi(this);

    //设置固定尺寸
    this->setFixedSize(400, 300);
    //设置标题
    this->setWindowTitle("酒店管理系统");
    //设置图标
    this->setWindowIcon(QIcon(":/images/hotel_icon.svg"));
}

ChangeRoomInfoDialog::~ChangeRoomInfoDialog()
{
    delete ui;
}


void ChangeRoomInfoDialog::getOldRoomInfo(QStringList oldRoomInfo) //获取原来的数据
{
    ui->letRoomNumber->setText(oldRoomInfo[0]);
    ui->letRoomType->setText(oldRoomInfo[1]);
    ui->letRoomDepict->setText(oldRoomInfo[2]);
    ui->letPrice->setText(oldRoomInfo[3]);
    ui->letStatus->setText(oldRoomInfo[4]);
}


void ChangeRoomInfoDialog::on_btnChange_clicked()
{
    QStringList newRoomInfo;
    newRoomInfo << ui->letRoomNumber->text();
    newRoomInfo << ui->letRoomType->text();
    newRoomInfo << ui->letRoomDepict->text();
    newRoomInfo << ui->letPrice->text();
    newRoomInfo << ui->letStatus->text();
    emit changeRoomInfo(newRoomInfo);
    on_btnCancel_clicked();
}


void ChangeRoomInfoDialog::on_btnCancel_clicked()
{
    ui->letRoomNumber->clear();
    ui->letRoomType->clear();
    ui->letRoomDepict->clear();
    ui->letPrice->clear();
    ui->letStatus->clear();
    this->hide();
}

