/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnPilihFile;
    QLabel *deskripsi;
    QTextEdit *LiveUpdate;
    QLabel *solusiChoice;
    QPushButton *btnSimpan;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1600, 1031);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnPilihFile = new QPushButton(centralwidget);
        btnPilihFile->setObjectName("btnPilihFile");
        btnPilihFile->setGeometry(QRect(730, 290, 90, 29));
        deskripsi = new QLabel(centralwidget);
        deskripsi->setObjectName("deskripsi");
        deskripsi->setGeometry(QRect(560, 90, 461, 191));
        LiveUpdate = new QTextEdit(centralwidget);
        LiveUpdate->setObjectName("LiveUpdate");
        LiveUpdate->setGeometry(QRect(280, 320, 1001, 401));
        LiveUpdate->setReadOnly(true);
        solusiChoice = new QLabel(centralwidget);
        solusiChoice->setObjectName("solusiChoice");
        solusiChoice->setGeometry(QRect(730, 750, 111, 20));
        btnSimpan = new QPushButton(centralwidget);
        btnSimpan->setObjectName("btnSimpan");
        btnSimpan->setGeometry(QRect(740, 770, 90, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1600, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Queens", nullptr));
        btnPilihFile->setText(QCoreApplication::translate("MainWindow", "Pilih File", nullptr));
        deskripsi->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Selamat datang di Queens Problem Solver! </p><p>Silahkan pilih File .txt terlebih dahulu dengan format abjad kapital</p><p>contoh : </p><p>AAAB</p><p>ACCB</p><p>CCDD</p></body></html>", nullptr));
        LiveUpdate->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        solusiChoice->setText(QCoreApplication::translate("MainWindow", "Simpan Solusi?", nullptr));
        btnSimpan->setText(QCoreApplication::translate("MainWindow", "Simpan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
