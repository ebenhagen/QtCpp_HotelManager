#include "widget.h"
#include "ui_widget.h"
#include<QSqlRecord>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置固定尺寸
    this->setFixedSize(800, 600);
    //设置标题
    this->setWindowTitle("酒店管理系统");
    //设置图标
    this->setWindowIcon(QIcon(":/images/hotel_icon.svg"));

    //登录界面
    ui->stackedWidget->setCurrentIndex(0);

    //时间
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");

    m_timer = new QTimer(this);
    m_timer->start(1000);
    connect(Widget::m_timer, &QTimer::timeout, [=](){
        m_dateTime = QDateTime::currentDateTime();
        ui->dateTimeEdit->setDateTime(m_dateTime);
    });

    //连接数据库
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QCoreApplication::applicationDirPath() + "/hotalMS.db";
    qDebug() << dbPath;
    m_db.setDatabaseName(dbPath);
    //打开
    if (!m_db.open()) {
        QMessageBox::warning(this,"警告","数据库连接失败");
        return;
    }

    //登记界面
    //男女按钮
    connect(Widget::ui->rbtnMale, &QRadioButton::clicked, [=](){
        m_sex = "男";
        qDebug() << m_sex;
    });
    connect(Widget::ui->rbtnFemale, &QRadioButton::clicked, [=](){
        m_sex = "女";
        qDebug() << m_sex;
    });
    m_allRoomNumber << "101" << "102"<< "103"<< "104"<< "105"<< "106"<< "107"<< "108"<< "109"<< "110"
                    << "201" << "202"<< "203"<< "204"<< "205"<< "206"<< "207"<< "208"<< "209"<< "210"
                    << "301" << "302"<< "303"<< "304"<< "305"<< "306"<< "307"<< "308"<< "309"<< "310"
                    << "401" << "402"<< "403"<< "404"<< "405"<< "406"<< "407"<< "408"<< "409"<< "410"
                    << "501" << "502"<< "503"<< "504"<< "505"<< "506"<< "507"<< "508"<< "509"<< "510"
                    << "601" << "602"<< "603"<< "604"<< "605"<< "606"<< "607"<< "608"<< "609"<< "610"
                    << "701" << "702"<< "703"<< "704"<< "705"<< "706"<< "707"<< "708"<< "709"<< "710"
                    << "801" << "802"<< "803"<< "804"<< "805"<< "806"<< "807"<< "808"<< "809"<< "810"
                    << "901" << "902"<< "903"<< "904"<< "905"<< "906"<< "907"<< "908"<< "909"<< "910";

    m_roomStatusList << ui->lbl101 << ui->lbl102 << ui->lbl103 << ui->lbl104 << ui->lbl105 << ui->lbl106 << ui->lbl107<< ui->lbl108 << ui->lbl109 << ui->lbl110
        << ui->lbl201 << ui->lbl202 << ui->lbl203 << ui->lbl204 << ui->lbl205 << ui->lbl206 << ui->lbl207<< ui->lbl208 << ui->lbl209 << ui->lbl210
        << ui->lbl301 << ui->lbl302 << ui->lbl303 << ui->lbl304 << ui->lbl305 << ui->lbl306 << ui->lbl307<< ui->lbl308 << ui->lbl309 << ui->lbl310
        << ui->lbl401 << ui->lbl402 << ui->lbl403 << ui->lbl404 << ui->lbl405 << ui->lbl406 << ui->lbl407<< ui->lbl408 << ui->lbl409 << ui->lbl410
        << ui->lbl501 << ui->lbl502 << ui->lbl503 << ui->lbl504 << ui->lbl505 << ui->lbl506 << ui->lbl507<< ui->lbl508 << ui->lbl509 << ui->lbl510
        << ui->lbl601 << ui->lbl602 << ui->lbl603 << ui->lbl604 << ui->lbl605 << ui->lbl606 << ui->lbl607<< ui->lbl608 << ui->lbl609 << ui->lbl610
        << ui->lbl701 << ui->lbl702 << ui->lbl703 << ui->lbl704 << ui->lbl705 << ui->lbl706 << ui->lbl707<< ui->lbl708 << ui->lbl709 << ui->lbl710
        << ui->lbl801 << ui->lbl802 << ui->lbl803 << ui->lbl804 << ui->lbl805 << ui->lbl806 << ui->lbl807<< ui->lbl808 << ui->lbl809 << ui->lbl810
        << ui->lbl901 << ui->lbl902 << ui->lbl903 << ui->lbl904 << ui->lbl905 << ui->lbl906 << ui->lbl907<< ui->lbl908 << ui->lbl909 << ui->lbl910;
    //数据库cus_Room视图
    m_cus_Room_model = new QSqlTableModel(this);
    m_cus_Room_model->setTable("cus_Room");
    m_cus_Room_model->select();                 //在筛选和排序的条件下，将数据库中符合要求的在model表格中显示出来
    ui->tableViewE->setModel(m_cus_Room_model);

    //不可编辑
    ui->tableViewE->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //选中单行
    ui->tableViewE->setSelectionBehavior(QAbstractItemView::SelectRows);

    //显示预约记录

    ui->tableViewG->setModel(&m_modelG);
    //不可编辑
    ui->tableViewG->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //选中单行
    ui->tableViewG->setSelectionBehavior(QAbstractItemView::SelectRows);

    //显示历史顾客记录

    ui->tableViewH->setModel(&m_modelH);
    //不可编辑
    ui->tableViewH->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //选中单行
    ui->tableViewH->setSelectionBehavior(QAbstractItemView::SelectRows);


    //显示房间信息

    ui->tableViewRoom->setModel(&m_modelR);
    //不可编辑
    ui->tableViewRoom->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //选中单行
    ui->tableViewRoom->setSelectionBehavior(QAbstractItemView::SelectRows);

    //刷新当前预约记录界面
    on_btnGRefresh_clicked();
    //刷新历史顾客记录界面
    on_btnHRefresh_clicked();
    //刷新房间信息
    on_btnRoomRefresh_clicked();

    connect(&m_cpDlg, &ChangePasswordDialog::changePassword, this, &Widget::getNewPassword);
    connect(&m_criDlg, &ChangeRoomInfoDialog::changeRoomInfo, this, &Widget::getNewRoomInfo);
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::strToMd5(QString str)//将口令字符串转换为MD5加密
{
    QString strMd5;
    QByteArray qba;                                                         //①
    qba = QCryptographicHash::hash(str.toLatin1(), QCryptographicHash::Md5);//②生成二进制或文本数据的加密散列值
    strMd5.append(qba.toHex());                                             //③
    return strMd5;
}

quint16 Widget::dayOfYear(QString date) {
    QVector<quint16> days = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    quint16 year = date.section("/",0,0).toInt();
    quint16 month = date.section("/",1,1).toInt();
    quint16 day = date.section("/",2,2).toInt();
    quint16 res = 0;
    for(quint16 i = 1; i < month; i++){
        res += days[i];
    }
    if(((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) && month > 2){
        res += 1;
    }
    res += day;
    return res;
}

quint16 Widget::getTheNumOfDays(QString earlierDate, QString laterDate)
{
    quint16 eYear = earlierDate.section("/",0,0).toInt();//根据/分成几段，从0段开始0段结束
    quint16 lYear = laterDate.section("/",0,0).toInt();

    if (lYear - eYear == 0) {   //年数差为0
        return dayOfYear(laterDate) - dayOfYear(earlierDate);
    }
    else {                      //年数差大于0
        //更早的日期到年底的天数
        quint16 days1 = 0;
        if ((eYear % 400 == 0) || (eYear % 4 == 0 && eYear % 100 != 0)) {
            days1 = 366 - dayOfYear(earlierDate);
        }
        else {
            days1 = 365 - dayOfYear(earlierDate);
        }
        //更晚的日期到年头的天数
        quint16 days2 = dayOfYear(laterDate);
        //之间所有年的天数和
        quint16 days3 = 0;
        quint16 thisYear = eYear + 1;
        while (thisYear < lYear) {
            if ((thisYear % 400 == 0) || (thisYear % 4 == 0 && thisYear % 100 != 0)) {
                days3 += 366;
            }
            else {
                days3 += 365;
            }
            thisYear++;
        }
        return days1 + days2 + days3;
    }
    return 0;
}

bool Widget::judgeRoomNumber(QString roomNumber)
{
    //判断房间号是否输错
    for (int i = 0; i < m_allRoomNumber.size(); i++) {
        if (roomNumber == m_allRoomNumber[i]) {
            return true;
        }
    }
    return false;
}
//****************************************************登录界面****************************************************//
//登录按钮
void Widget::on_btnLogin_clicked()
{
    //数据库查询判断输入是否正确
    if(!ui->letPassword->text().isEmpty()){
        QSqlQuery query;
        QString sqlstr = QString("select password from member where memberId = '%1';").arg(ui->letAccount->text());
        bool ret = query.exec(sqlstr);
        if(!ret){//执行失败
            qDebug()<<query.lastError().text();
        }
        else{//执行成功
            query.next();
            QString pwdMd5 = strToMd5(ui->letPassword->text());//输入口令转成MD5
            if(query.value(0).toString() == pwdMd5){
                //验证通过，进入选择界面
                m_memberId = ui->letAccount->text();
                ui->stackedWidget->setCurrentIndex(1);
            }
            else{
                QMessageBox::warning(this, "密码错误！", "请重新输入", QMessageBox::Ok);
                ui->letPassword->clear();
                ui->letPassword->setFocus();
            }
        }
    }
    else{
        ui->letPassword->setFocus();
    }
}


void Widget::on_btnLoExit_clicked() //登录界面-退出
{
    qApp->exit();
}

//****************************************************选择界面****************************************************//
void Widget::on_btnHotalManage_clicked()   //酒店管理按钮
{
    //到酒店管理界面
    ui->stackedWidget->setCurrentIndex(2);
    ui->tabWidget->setCurrentIndex(0);

    on_btnAClear_clicked(); //调用预约界面 重置槽函数
    on_btnBClear_clicked(); //调用登记界面 重置槽函数

    showRoomStatus(); //调用今日房态界面 显示房间状态颜色函数
}

void Widget::on_btnSystemSet_clicked()     //系统设置
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Widget::on_btnChExit_clicked()        //退出登录
{
    //返回登录界面
    ui->letAccount->clear();
    ui->letPassword->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
//***************************************************系统设置界面*****************************************************//

void Widget::on_btnSSBack_clicked()   //返回按钮
{
    //返回选择界面
    ui->stackedWidget->setCurrentIndex(1);
}


//****************************************************酒店管理界面****************************************************//
//返回按钮
void Widget::on_btnBack_clicked()    //返回按钮
{
    //返回选择界面
    ui->stackedWidget->setCurrentIndex(1);
}

//****************************************************预约界面****************************************************//
void Widget::on_btnAppointment_clicked()
{
    //预约界面-预约按钮
    QString name = ui->letAName->text();
    QString idNumber = ui->letAIDNumber->text();
    QString phoneNumber = ui->letAPhoneNumber->text();
    QString appointmentDate = ui->detADate->text();
    QString roomNumber = ui->letARoomNumber->text();
    if (!judgeRoomNumber(roomNumber)) {
        QMessageBox::warning(this, "警告", "房间号输入有误，请重新输入");
        ui->letARoomNumber->clear();
        ui->letARoomNumber->setFocus();
    }
    else {
        //日期转成yyyy/MM/dd格式
        QDateTime a = QDateTime::fromString(appointmentDate, "yyyy/M/d");
        appointmentDate = a.toString("yyyy/MM/dd");
        QSqlQuery q;
        //判断预约房间是否已经有人预约或有人入住
        QString str = QString("select status from room where roomNumber = '%1'").arg(roomNumber);
        bool isOk = q.exec(str);
        if (!isOk) {
//            QMessageBox::warning(this,"警告","查询房间状态失败！");
        }
        else {
//            QMessageBox::warning(this,"信息","查询房间状态成功！");
            q.next();
            if(q.value(0).toString() == "有人预约"){
                QMessageBox::warning(this,"警告","预约失败！该房间已经有人预约");
            }
            else if(q.value(0).toString() == "有人入住"){
                QMessageBox::warning(this,"警告","预约失败！该房间已经有人入住");
            }
            else if(appointmentDate < m_dateTime.toString("yyyy/MM/dd")){
                QMessageBox::warning(this,"警告","预约失败！预约时间输入有误");
            }
            else {
                QMessageBox::warning(this,"信息","预约成功！");
                //预约表插入本次预约数据
                QString str = QString("insert into appointment(name, IDNumber, phoneNumber, appointmentDate, roomNumber)"
                                      "values('%1','%2','%3','%4','%5')")
                                  .arg(name)
                                  .arg(idNumber)
                                  .arg(phoneNumber)
                                  .arg(appointmentDate)
                                  .arg(roomNumber);
                q.exec(str);
                //更新房间状态
                str = QString("update room set status = '%1' where roomNumber = '%2'").arg("有人预约").arg(roomNumber);
                q.exec(str);
                //今日房态更新
                showRoomStatus();
            }
        }
    }
}


void Widget::on_btnAClear_clicked()
{
    //预约界面-重置按钮
    ui->letAName->clear();
    ui->letAIDNumber->clear();
    ui->letAPhoneNumber->clear();
    ui->detADate->setDateTime(m_dateTime);
    ui->letARoomNumber->clear();
}

void Widget::on_letARoomNumber_textChanged(const QString &arg1)
{
    //（输入不同房间号，comboBox显示该房间的房间类型）
    if(ui->letARoomNumber->text().left(1).toInt() % 3 == 1){
        ui->cbbARoomType->setCurrentText("单人房");
    }
    if(ui->letARoomNumber->text().left(1).toInt() % 3 == 2){
        ui->cbbARoomType->setCurrentText("双人房");
    }
    if(ui->letARoomNumber->text().left(1).toInt() % 3 == 0){
        ui->cbbARoomType->setCurrentText("套房");
    }
}

//****************************************************登记界面****************************************************//

void Widget::on_btnBSelectAppointment_clicked()
{
    //登记界面-查询预约情况按钮（根据输入的姓名，查是否有先前预约，有则直接填入预约时的信息）
    QString name = ui->letBName->text();
    QSqlQuery q;

    QString str = QString("select * from appointment where name = '%1'").arg(name);
    q.exec(str);
    q.next();
    if(q.value(1).toString().isEmpty()){
        QMessageBox::information(this, "没有预约！", "该顾客没有之前的预约");
    }
    else{
        QMessageBox::information(this, "有预约！", "查询到该顾客的预约");
        ui->letBName->setText(q.value(1).toString());
        ui->letBIDNumber->setText(q.value(2).toString());
        ui->letBPhoneNumber->setText(q.value(3).toString());
        ui->detBArrivalDate->setDate(q.value(4).toDate());
        ui->detBDepartureDate->setDate(m_dateTime.date());
        ui->letBRoomNumber->setText(q.value(5).toString());
    }
}
void Widget::on_btnRegister_clicked()
{
    //登记界面-登记按钮
    QString name = ui->letBName->text();

    QString idNumber = ui->letBIDNumber->text();
    QString phoneNumber = ui->letBPhoneNumber->text();
    QString arrivalDate = ui->detBArrivalDate->text();
    QString departureDate = ui->detBDepartureDate->text();
    QString roomNumber = ui->letBRoomNumber->text();

    if (!judgeRoomNumber(roomNumber)) {
        QMessageBox::warning(this, "警告", "房间号输入有误，请重新输入");
        ui->letBRoomNumber->clear();
        ui->letBRoomNumber->setFocus();
    }
    else {
        QSqlQuery q;
        //判断预约房间是否已经有人预约或有人入住
        QString str = QString("select status from room where roomNumber = '%1'").arg(roomNumber);
        //查预约表身份证，判断预约人是否为登记人
        QSqlQuery q2;
        QString str2 = QString("select IDNumber from appointment where roomNumber = '%1'").arg(roomNumber);
        q2.exec(str2);
        bool isOk = q.exec(str);
        if (!isOk) {
//            QMessageBox::warning(this,"警告","查询房间状态失败！");
        }
        else {
//            QMessageBox::warning(this,"信息","查询房间状态成功！");
            //日期转成yyyy/MM/dd格式
            QDateTime a = QDateTime::fromString(arrivalDate, "yyyy/M/d");
            arrivalDate = a.toString("yyyy/MM/dd");
            QDateTime b = QDateTime::fromString(departureDate, "yyyy/M/d");
            departureDate = b.toString("yyyy/MM/dd");

            q.next();
            q2.next();
            if(!q2.value(0).toString().isEmpty() && q.value(0).toString() == "有人预约" && q2.value(0).toString() != idNumber){
                QMessageBox::warning(this,"警告","登记失败！该房间已经有人预约");
            }
            else if(q.value(0).toString() == "有人入住"){
                QMessageBox::warning(this,"警告","登记失败！该房间已经有人入住");
            }
            else if(arrivalDate < m_dateTime.toString("yyyy/MM/dd") || arrivalDate >= departureDate){
                QMessageBox::warning(this,"警告","登记失败！入住时间或离店时间输入有误");
            }
            else{
                QMessageBox::warning(this,"信息","登记成功！");
                //顾客表插入本次登记数据
                str = QString("insert into customer(name, sex, IDNumber, phoneNumber, roomNumber, dateOfArrival, dateOfDeparture)"
                                  "values('%1','%2','%3','%4','%5','%6','%7')")
                              .arg(name)
                              .arg(m_sex)
                              .arg(idNumber)
                              .arg(phoneNumber)
                              .arg(roomNumber)
                              .arg(arrivalDate)
                              .arg(departureDate);
                q.exec(str);
                //更新房间状态
                str = QString("update room set status = '%1' where roomNumber = '%2'").arg("有人入住").arg(roomNumber);
                q.exec(str);
                //今日房态更新
                showRoomStatus();
                //如过有预约，删除该预约
                str = QString("delete from appointment where roomNumber = '%2'").arg(roomNumber);
                if(q.exec(str)){
//                    QMessageBox::warning(this,"信息","预约删除成功！");
                }
            }
        }
    }
}

void Widget::on_btnBClear_clicked()
{
     //登记界面-重置按钮
    ui->letBName->clear();
    ui->letBIDNumber->clear();
    ui->letBPhoneNumber->clear();
    ui->detBArrivalDate->setDateTime(m_dateTime);
    ui->detBDepartureDate->setDateTime(m_dateTime);
    ui->letBRoomNumber->clear();
}

void Widget::on_letBRoomNumber_textChanged(const QString &arg1)
{
    //（输入不同房间号，comboBox显示该房间的房间类型）
    if(ui->letBRoomNumber->text() == "101"
        || ui->letBRoomNumber->text() == "102"
        || ui->letBRoomNumber->text() == "103"
        || ui->letBRoomNumber->text() == "104"
        || ui->letBRoomNumber->text() == "105" ){
        ui->cbbBRoomType->setCurrentText("单人房");
    }
    if(ui->letBRoomNumber->text() == "201"
        || ui->letBRoomNumber->text() == "202"
        || ui->letBRoomNumber->text() == "203"
        || ui->letBRoomNumber->text() == "204"
        || ui->letBRoomNumber->text() == "205"){
        ui->cbbBRoomType->setCurrentText("双人房");
    }
    if(ui->letBRoomNumber->text() == "301"
        || ui->letBRoomNumber->text() == "302"
        || ui->letBRoomNumber->text() == "303"
        || ui->letBRoomNumber->text() == "304"
        || ui->letBRoomNumber->text() == "305"){
        ui->cbbBRoomType->setCurrentText("套房");
    }
}

//****************************************************消费界面****************************************************//
void Widget::on_btnCConfirm_clicked()
{
    //消费界面-确认按钮
    QString roomNumber = ui->letCRoomNumber->text();
    quint16 consume = ui->letCConsume->text().toInt();
    quint16 damage = ui->letCDamage->text().toInt();

    consume = consume + damage;

    QSqlQuery q;
    QString str = QString("select * from room where roomNumber = '%1'").arg(roomNumber);
    q.exec(str);
    q.next();
    if(q.value(4).toString() != "有人入住"){
        QMessageBox::warning(this,"警告","该房间无人入住，消费追加失败！");
    }
    else{
        QMessageBox::warning(this,"信息","消费追加成功！");
        str = QString("select consume from customer where roomNumber = '%1'").arg(roomNumber);
        q.exec(str);
        q.next();
        consume += q.value(0).toInt();
        QSqlQuery q2;
        str = QString("update customer set consume = %1 where roomNumber = '%2'").arg(consume).arg(roomNumber);
        q2.exec(str);
    }
}

void Widget::on_btnCClear_clicked()
{
    //消费界面-重置按钮
    ui->letCRoomNumber->clear();
    ui->letCConsume->setText(0);
    ui->letCDamage->setText(0);
}

//****************************************************退房界面****************************************************//
void Widget::on_btnDVerify_clicked()
{
    //退房界面-核实信息按钮
    QString roomNumber = ui->letDRoomNumber->text();
    QSqlQuery q;
    //多表联查
    QString str = QString("select * from customer join room using(roomNumber) where roomNumber = '%1'").arg(roomNumber);

    bool isOk = q.exec(str);
    if(!isOk){
        QMessageBox::warning(this,"警告","核实信息失败！");
        return;
    }
    else{
        if(q.next()){
            QMessageBox::warning(this,"信息","核实信息成功！");
            QString name = q.value(1).toString();
            QString IDNumber = q.value(3).toString();
            QString arrivalDate = q.value(6).toString();
            QString departureDate = q.value(7).toString();
            quint16 otherconsume = q.value(8).toInt();
            //房间类型 room表
            QString roomType = q.value(9).toString();
            //房间单价
            quint16 price = q.value(11).toInt();
            //天数 计算
            quint16 day = getTheNumOfDays(arrivalDate, departureDate);

            //总价 计算
            quint16 consume = day * price + otherconsume;

            ui->letDName->setText(name);
            ui->letDIDNumber->setText(IDNumber);
            ui->letDRoomType->setText(roomType);
            ui->letDArrival->setText(arrivalDate);
            ui->letDDeparture->setText(departureDate);
            ui->letDOtherConsume->setText(QString::number(otherconsume));
            ui->letDConsume->setText(QString::number(consume));
        }
        else{
            QMessageBox::warning(this,"信息","该房间无人入住，无法退房");
        }
    }
}

void Widget::on_btnDCheckOut_clicked()
{
    //退房界面-退房按钮
    QString roomNumber = ui->letDRoomNumber->text();
    QString consume = ui->letDConsume->text();
    QSqlQuery q;
    //更新consume
    QString str = QString("update customer set consume = %1 where roomNumber = '%2'").arg(consume).arg(roomNumber);
    q.exec(str);
    //查询最终信息，插入recordCustomer
    str = QString("select * from customer where roomNumber = '%1'").arg(roomNumber);
    q.exec(str);
    q.next();
    QSqlQuery q2;
    QString str2 = QString("insert into recordCustomer(name, sex, IDNumber, phoneNumber, roomNumber, dateOfArrival, dateOfDeparture, consume)"
                  "values('%1','%2','%3','%4','%5','%6','%7','%8')")
              .arg(q.value(1).toString())
              .arg(q.value(2).toString())
              .arg(q.value(3).toString())
              .arg(q.value(4).toString())
              .arg(q.value(5).toString())
              .arg(q.value(6).toString())
              .arg(q.value(7).toString())
              .arg(q.value(8).toInt());
    q2.exec(str2);
    //删除customer记录
    str2 = QString("delete from customer where roomNumber = '%1'").arg(roomNumber);
    q2.exec(str2);
    //更新房间状态
    str = QString("update room set status = '%1' where roomNumber = '%2'").arg("无人入住").arg(roomNumber);
    q.exec(str);
    //今日房态更新
    showRoomStatus();
    QMessageBox::warning(this,"信息","退房成功！");

}


void Widget::on_btnDClear_clicked()
{
    //退房界面-重置按钮
    ui->letDRoomNumber->clear();
    ui->letDName->clear();
    ui->letDIDNumber->clear();
    ui->letDRoomType->clear();
    ui->letDArrival->clear();
    ui->letDDeparture->clear();
    ui->letDOtherConsume->clear();
    ui->letDConsume->clear();
}

//****************************************************综合查询界面****************************************************//
void Widget::on_btnESelect_clicked()
{
    //综合查询界面-查询按钮
    QString name = ui->letEName->text();
    QString roomNumber = ui->letERoomNumber->text();
    QSqlQuery q;
    //多表联查
    QString str1 = QString("select * from cus_Room where name = '%1'").arg(name);
    QString str2 = QString("select * from cus_Room where roomNumber = '%1'").arg(roomNumber);
    bool isOk = false;
    if(!name.isEmpty()){
        isOk = q.exec(str1);
    }
    else{
        isOk = q.exec(str2);
    }
    if(!isOk){
        QMessageBox::warning(this,"警告","核实信息失败！");
        return;
    }
    else{
        if(q.next()){
            QMessageBox::warning(this,"信息","核实信息成功！");
            QStandardItemModel * mod = new QStandardItemModel (this);
            mod->setHorizontalHeaderItem(0, new QStandardItem("顾客号"));
            mod->setHorizontalHeaderItem(1, new QStandardItem("姓名"));
            mod->setHorizontalHeaderItem(2, new QStandardItem("性别"));
            mod->setHorizontalHeaderItem(3, new QStandardItem("身份证号"));
            mod->setHorizontalHeaderItem(4, new QStandardItem("手机号"));
            mod->setHorizontalHeaderItem(5, new QStandardItem("房间号"));
            mod->setHorizontalHeaderItem(6, new QStandardItem("入住时间"));
            mod->setHorizontalHeaderItem(7, new QStandardItem("离店时间"));
            mod->setHorizontalHeaderItem(8, new QStandardItem("消费"));
            mod->setHorizontalHeaderItem(9, new QStandardItem("房间类型"));
            mod->setHorizontalHeaderItem(10, new QStandardItem("房间描述"));
            mod->setHorizontalHeaderItem(11, new QStandardItem("单价"));
            mod->setHorizontalHeaderItem(12, new QStandardItem("房间状态"));
            for (int i = 0; i <= 12; i++) {
                mod->setItem(0, i, new QStandardItem(q.value(i).toString()));
            }
            ui->tableViewE->setModel(mod);
        }
        else{
            QMessageBox::warning(this,"信息","没有查询到顾客信息，房间无人入住、房间号错误、或输入姓名有误");
        }
    }
}


void Widget::on_btnEClear_clicked()
{
    //综合查询界面-重置按钮
    ui->letEName->clear();
    ui->letERoomNumber->clear();
}

void Widget::on_btnERefresh_clicked()
{
    //综合查询界面-刷新按钮
    m_cus_Room_model->setTable("cus_Room");
    m_cus_Room_model->select();
    ui->tableViewE->setModel(m_cus_Room_model);
}
//****************************************************今日房态界面****************************************************//
//显示房间状态颜色
void Widget::showRoomStatus()
{
    QSqlQuery q;
    QString str = QString("select * from room");
    q.exec(str);
    for(int i = 0; i < 90; i++){
        q.next();
        if(q.value(4) == "有人预约"){
            m_roomStatusList[i]->setStyleSheet("background-color: rgb(255, 0, 255);");
        }
        if(q.value(4) == "有人入住"){
            m_roomStatusList[i]->setStyleSheet("background-color: rgb(0, 255, 255);");
        }
        if(q.value(4) == "无人入住"){
            m_roomStatusList[i]->setStyleSheet("background-color: rgb(255, 255, 0);");
        }
    }
}
//****************************************************当前预约记录界面****************************************************//
QVector<QStringList> Widget::getappointID()  //获取所有当前预约ID
{
    QSqlQuery q;
    QString str = QString("select * from appointment");
    QVector<QStringList> vec;      //返回值
    bool isOk = q.exec(str);
    if (!isOk) {
        QMessageBox::warning(0 ,"警告","获取所有当前预约ID失败！");
        qDebug()<<q.lastError().text();
    }
    else {
        int iCols = q.record().count(); //获取sql执行得到的数据数量
        QStringList l; //每一行记录
        while(q.next()){
            l.clear();
            for(int i = 0;i < iCols; i++){
                l<<q.value(i).toString(); //一行的每个数据存入l
            }
            vec.push_back(l); //每个l存入返回结果
        }
    }
    return vec;
}


void Widget::on_btnGRefresh_clicked() //刷新按钮
{
    //调用getappointID()获取所有预约ID
    QVector<QStringList> l = getappointID();
    m_modelG.clear();//清除模型
    m_modelG.setHorizontalHeaderLabels(QStringList{"预约id","姓名","身份证号","手机号","预约时间","房间号"});//设置模型表头

    for (int i = 0; i < l.size();i++) {
        QList<QStandardItem*> items;//item存储一行数据，一个单元格显示 QStandardItemModel 数据模型中的一个项。
        for (int j = 0;j <l[i].size();j++) {
            items.append(new QStandardItem(l[i][j]));//该行的item添加每个数据到该行的单元格（达成显示）
        }
        m_modelG.appendRow(items);//模型增加一行
    }
}

void Widget::on_btnGCancel_clicked()
{
    //当前预约记录界面-取消预约按钮
    //选中的预约删除
    int r = ui->tableViewG->currentIndex().row();//获取鼠标点击的行
    if (r < 0) { //没点需要取消预约的所在行
        QMessageBox::information(this,"提示","没点需要取消预约的所在行");
    }
    else{
        //父窗口 标题 中心文本 按键类型 关联回车的按键
        if (QMessageBox::Ok == QMessageBox::question(this,"question","确定要取消该顾客的预约吗？",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok)) {
            qDebug()<<"选择的是ok";
            auto id = m_modelG.item(r,0)->text();           //获取该行item的appointmentId
            QString roomNumber = m_modelG.item(r,5)->text();//获取该行房间号
            QSqlQuery q;
            QString str = QString("delete from appointment where appointmentId = %1;").arg(id);
            bool ret = q.exec(str);
            if(!ret){
                QMessageBox::information(this, "警告", "取消该顾客的预约失败！");
                qDebug()<<q.lastError().text();
            }
            //更新房间状态
            str = QString("update room set status = '%1' where roomNumber = '%2'").arg("无人入住").arg(roomNumber);
            q.exec(str);
            //今日房态更新
            showRoomStatus();
            //刷新本界面
            QMessageBox::information(this, "信息", "取消该顾客的预约成功！");
            on_btnGRefresh_clicked();
        }
        else {
            qDebug()<<"选择的是取消";
        }
    }

}

//****************************************************历史顾客记录界面****************************************************//
QVector<QStringList> Widget::getcustomerID()  //获取所有历史顾客ID
{
    QSqlQuery q;
    QString str = QString("select * from recordCustomer");
    QVector<QStringList> vec;      //返回值
    bool isOk = q.exec(str);
    if (!isOk) {
        QMessageBox::warning(0 ,"警告","获取所有历史顾客ID失败！");
        qDebug()<<q.lastError().text();
    }
    else {
        int iCols = q.record().count(); //获取sql执行得到的数据数量
        QStringList l; //每一行记录
        while(q.next()){
            l.clear();
            for(int i = 0;i < iCols; i++){
                l<<q.value(i).toString(); //一行的每个数据存入l
            }
            vec.push_back(l); //每个l存入返回结果
        }
    }
    return vec;
}

void Widget::on_btnHRefresh_clicked()
{
    //调用getcustomerID()获取所有历史顾客记录ID
    QVector<QStringList> l = getcustomerID();
    m_modelH.clear();                //清除模型
    m_modelH.setHorizontalHeaderLabels(QStringList{"顾客id","姓名","性别","身份证号","手机号","房间号","到达时间","离店时间","总消费"});//设置模型表头

    for (int i = 0; i < l.size();i++) {
        QList<QStandardItem*> items; //item存储一行数据，一个单元格显示 QStandardItemModel 数据模型中的一个项。
        for (int j = 0; j <l[i].size(); j++) {
            items.append(new QStandardItem(l[i][j]));//该行的item添加每个数据到该行的单元格（达成显示）
        }
        m_modelH.appendRow(items);   //模型增加一行
    }
}

void Widget::on_btnHClean_clicked()
{
    //综合查询界面-清空历史顾客记录按钮

    //清空数据库
    //父窗口 标题 中心文本 按键类型 关联回车的按键
    if (QMessageBox::Ok == QMessageBox::question(this,"question","确定要清空历史顾客记录吗？",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok)) {
        qDebug()<<"选择的是ok";
        QSqlQuery q;
        QString str = QString("delete from recordCustomer");
        bool isOk = q.exec(str);
        if (!isOk) {
            QMessageBox::warning(this, "警告", "清空历史顾客记录失败！");
            qDebug()<<q.lastError().text();
        }
        else {
            //刷新界面
            QMessageBox::information(this, "信息", "清空历史顾客记录成功！");
            on_btnHRefresh_clicked();
        }
    } else {
        qDebug()<<"选择的是取消";
    }
}

//****************************************************系统设置界面****************************************************//
void Widget::on_btnChangePassword_clicked()
{
    m_cpDlg.exec();
}

void Widget::getNewPassword(QString newPassword)
{
    QString newMD5 = strToMd5(newPassword);
    QSqlQuery q;
    QString str = QString("update member set password = '%1' where memberId = '%2';").arg(newMD5).arg(m_memberId);
    bool ret = q.exec(str);
    if(!ret){//执行失败
        qDebug()<< q.lastError().text();
    }
    else{//执行成功
        QMessageBox::information(this, "信息", "修改密码成功！");
        qDebug() << "用户ID" << m_memberId;
        qDebug() << "新密码" << newPassword;
        //登录界面重新登录
        ui->stackedWidget->setCurrentIndex(0);
        ui->letAccount->clear();
        ui->letPassword->clear();
    }
}


QVector<QStringList> Widget::getRoomNumber() //获取所有房间号
{
    QSqlQuery q;
    QString str = QString("select * from room");
    QVector<QStringList> vec;      //返回值
    bool isOk = q.exec(str);
    if (!isOk) {
        QMessageBox::warning(0 ,"警告","获取所有房间号失败！");
        qDebug()<<q.lastError().text();
    }
    else {
        int iCols = q.record().count(); //获取sql执行得到的数据数量
        QStringList l; //每一行记录
        while(q.next()){
            l.clear();
            for(int i = 0;i < iCols; i++){
                l<<q.value(i).toString(); //一行的每个数据存入l
            }
            vec.push_back(l); //每个l存入返回结果
        }
    }
    return vec;
}


void Widget::on_btnRoomRefresh_clicked()
{
    //调用getRoomNumber()获取所有房间号
    QVector<QStringList> l = getRoomNumber();
    m_modelR.clear();                //清除模型
    m_modelR.setHorizontalHeaderLabels(QStringList{"房间号","房间类型","房间描述","单价","房间状态"}); //设置模型表头

    for (int i = 0; i < l.size();i++) {
        QList<QStandardItem*> items; //item存储一行数据，一个单元格显示 QStandardItemModel 数据模型中的一个项。
        for (int j = 0; j <l[i].size(); j++) {
            items.append(new QStandardItem(l[i][j]));//该行的item添加每个数据到该行的单元格（达成显示）
        }
        m_modelR.appendRow(items);   //模型增加一行
    }
}

void Widget::on_btnChangeRoomsInfo_clicked()
{
    int r = ui->tableViewRoom->currentIndex().row();//获取鼠标点击的行
    if (r < 0) {
        QMessageBox::information(this,"提示","没点需要修改房间信息的所在行");
    }
    else {
        QStringList oldRoomInfo;
        for (quint16 i = 0; i < 5; i++) {
            oldRoomInfo << m_modelR.item(r, i)->text();
        }
        m_criDlg.getOldRoomInfo(oldRoomInfo);
        m_criDlg.exec();
    }
}

void Widget::getNewRoomInfo(QStringList newRoomInfo)
{
    int r = ui->tableViewRoom->currentIndex().row();//获取鼠标点击的行
    QString roomNumber = m_modelR.item(r,0)->text();//获取该行房间号

    for (auto  c : newRoomInfo) {
        qDebug() << c;
    }

    QSqlQuery q;
    QString str = QString("update room set roomType = '%2', roomDepict = '%3', price = %4 where roomNumber = '%6'")
                      .arg(newRoomInfo[1])
                      .arg(newRoomInfo[2])
                      .arg(newRoomInfo[3].toInt())
                      .arg(roomNumber);
    bool ret = q.exec(str);
    if(!ret){
        QMessageBox::warning(this, "警告", "修改房间信息失败a！");
        qDebug()<<q.lastError().text();
    }
    else {
        //刷新本界面
        QMessageBox::information(this, "信息", "修改房间信息成功！");
        on_btnRoomRefresh_clicked();
    }
}

