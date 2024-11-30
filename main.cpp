#include "examdialog.h"
#include "logindialog.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSystemTrayIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale: uiLanguages)
    {
        const QString baseName = "ExamSys_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            QApplication::installTranslator(&translator);
            break;
        }
    }

    // 设置图标
    QIcon icon(":/images/exam.ico");
    QApplication::setWindowIcon(icon);

    LoginDialog logDialog;
    int res = logDialog.exec();
    if (res == QDialog::Accepted)
    {
        new ExamDialog();
    } else
    {
        return 0;
    }
    return QApplication::exec();
}
