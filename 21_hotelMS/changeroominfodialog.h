#ifndef CHANGEROOMINFODIALOG_H
#define CHANGEROOMINFODIALOG_H

#include <QDialog>

namespace Ui {
class ChangeRoomInfoDialog;
}

class ChangeRoomInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeRoomInfoDialog(QWidget *parent = nullptr);
    ~ChangeRoomInfoDialog();

    void getOldRoomInfo(QStringList oldRoomInfo);

private slots:
    void on_btnChange_clicked();

    void on_btnCancel_clicked();

signals:
    void changeRoomInfo(QStringList newRoomInfo);

private:
    Ui::ChangeRoomInfoDialog *ui;
};

#endif // CHANGEROOMINFODIALOG_H
