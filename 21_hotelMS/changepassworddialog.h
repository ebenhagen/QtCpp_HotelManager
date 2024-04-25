#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ChangePasswordDialog;
}

class ChangePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordDialog(QWidget *parent = nullptr);
    ~ChangePasswordDialog();

private slots:
    void on_btnChange_clicked();

    void on_btnCancel_clicked();
signals:
    void changePassword(QString newPassword);

private:
    Ui::ChangePasswordDialog *ui;
};

#endif // CHANGEPASSWORDDIALOG_H
