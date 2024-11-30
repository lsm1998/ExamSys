#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;//Ui_LoginDialog子类，用于描述登录窗口界面信息
}

class LoginDialog : public QDialog
{
    Q_OBJECT    //支持信号与槽的宏

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_loginBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
