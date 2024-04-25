#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCryptographicHash>              //包含MD5算法库
#include <QDateTime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QSqlRecord>
#include <changepassworddialog.h>
#include <changeroominfodialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString strToMd5(QString str);         //将口令字符串转换为MD5加密

    //显示房间状态颜色
    void showRoomStatus();

    //一个日期是在一年中的第几天
    quint16 dayOfYear(QString date);

    //获取任意两个日期的天数之差
    quint16 getTheNumOfDays(QString earlierDate, QString laterDate);

    //获取所有预约ID
    QVector<QStringList> getappointID();

    //获取所有历史顾客ID
    QVector<QStringList> getcustomerID();

    //获取所有房间号
    QVector<QStringList> getRoomNumber();

    //判断房间号是否输错
    bool judgeRoomNumber(QString roomNumber);

private slots:
    void on_btnLogin_clicked();

    void on_btnHotalManage_clicked();

    void on_btnBack_clicked();

    void on_btnAppointment_clicked();

    void on_btnRegister_clicked();

    void on_btnCConfirm_clicked();

    void on_btnAClear_clicked();

    void on_btnBClear_clicked();

    void on_btnCClear_clicked();

    void on_btnDCheckOut_clicked();

    void on_btnDClear_clicked();

    void on_btnDVerify_clicked();

    void on_btnESelect_clicked();

    void on_btnEClear_clicked();

    void on_btnLoExit_clicked();

    void on_btnSystemSet_clicked();

    void on_btnChExit_clicked();

    void on_letARoomNumber_textChanged(const QString &arg1);

    void on_letBRoomNumber_textChanged(const QString &arg1);

    void on_btnBSelectAppointment_clicked();

    void on_btnSSBack_clicked();

    void on_btnERefresh_clicked();

    void on_btnGCancel_clicked();

    void on_btnHClean_clicked();

    void on_btnGRefresh_clicked();

    void on_btnHRefresh_clicked();

    void on_btnChangePassword_clicked();

    void on_btnChangeRoomsInfo_clicked();

    //接收修改密码对话框的新密码
    void getNewPassword(QString newPassword);

    //接收修改房间信息的新信息
    void getNewRoomInfo(QStringList newRoomInfo);

    void on_btnRoomRefresh_clicked();

private:
    Ui::Widget *ui;
    QString m_memberId; //所登录的用户账号
    //当前日期
    QDateTime m_dateTime;
    QTimer *m_timer;
    QSqlDatabase m_db;
    QString m_sex = "男";

    //存储所有房间号
    QVector<QString> m_allRoomNumber;

    //控件组，存储显示状态颜色的房间
    QList<QLabel*> m_roomStatusList;
    //访问数据库视图cus_Room
    QSqlTableModel *m_cus_Room_model;


    QStandardItemModel m_modelG; //当前预约记录模型
    QStandardItemModel m_modelH; //历史顾客记录模型
    QStandardItemModel m_modelR; //放假信息模型

    ChangePasswordDialog m_cpDlg;  //修改密码对话框
    ChangeRoomInfoDialog m_criDlg; //修改房间信息对话框
};
#endif // WIDGET_H
