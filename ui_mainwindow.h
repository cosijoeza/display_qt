/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *picture_1;
    QLabel *picture_2;
    QLabel *resultado;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *open1;
    QPushButton *open2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *canales;
    QComboBox *geometricas;
    QComboBox *logicas;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QSpinBox *ejex;
    QSpinBox *ejey;
    QPushButton *close;
    QPushButton *clean1;
    QPushButton *clean2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *clean3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1170, 950);
        MainWindow->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	padding: .375rem .75rem;\n"
"  	border-radius: .25rem;\n"
"  	background-color: #007bff;\n"
"  	color: #fff;\n"
"  	transition: background-color .15s ease-in-out;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #0069d9; \n"
"}\n"
"QComboBox\n"
"{\n"
"  	background-color: #fff !important;\n"
"  	color: #000;\n"
"  	transition: background-color .15s ease-in-out;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        picture_1 = new QLabel(centralWidget);
        picture_1->setObjectName(QStringLiteral("picture_1"));
        picture_1->setEnabled(true);
        picture_1->setGeometry(QRect(100, 60, 300, 400));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        picture_1->setFont(font);
        picture_1->setLayoutDirection(Qt::LeftToRight);
        picture_1->setAutoFillBackground(false);
        picture_1->setStyleSheet(QStringLiteral(""));
        picture_1->setAlignment(Qt::AlignCenter);
        picture_2 = new QLabel(centralWidget);
        picture_2->setObjectName(QStringLiteral("picture_2"));
        picture_2->setGeometry(QRect(420, 60, 300, 400));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        picture_2->setFont(font1);
        picture_2->setStyleSheet(QStringLiteral(""));
        picture_2->setAlignment(Qt::AlignCenter);
        resultado = new QLabel(centralWidget);
        resultado->setObjectName(QStringLiteral("resultado"));
        resultado->setGeometry(QRect(740, 60, 300, 400));
        resultado->setFont(font1);
        resultado->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 720, 31, 31));
        QFont font2;
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(460, 750, 31, 51));
        label_3->setFont(font2);
        open1 = new QPushButton(centralWidget);
        open1->setObjectName(QStringLiteral("open1"));
        open1->setGeometry(QRect(140, 480, 185, 35));
        open2 = new QPushButton(centralWidget);
        open2->setObjectName(QStringLiteral("open2"));
        open2->setGeometry(QRect(500, 480, 185, 35));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 630, 871, 35));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        canales = new QComboBox(layoutWidget);
        canales->setObjectName(QStringLiteral("canales"));

        horizontalLayout->addWidget(canales);

        geometricas = new QComboBox(layoutWidget);
        geometricas->setObjectName(QStringLiteral("geometricas"));
        geometricas->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(geometricas);

        logicas = new QComboBox(layoutWidget);
        logicas->setObjectName(QStringLiteral("logicas"));

        horizontalLayout->addWidget(logicas);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 720, 123, 74));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ejex = new QSpinBox(layoutWidget1);
        ejex->setObjectName(QStringLiteral("ejex"));
        ejex->setMinimum(-1000);
        ejex->setMaximum(1000);

        verticalLayout->addWidget(ejex);

        ejey = new QSpinBox(layoutWidget1);
        ejey->setObjectName(QStringLiteral("ejey"));
        ejey->setMinimum(-1000);
        ejey->setMaximum(1000);

        verticalLayout->addWidget(ejey);

        close = new QPushButton(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(870, 810, 88, 33));
        close->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41) !important;"));
        clean1 = new QPushButton(centralWidget);
        clean1->setObjectName(QStringLiteral("clean1"));
        clean1->setGeometry(QRect(190, 520, 88, 33));
        clean1->setStyleSheet(QStringLiteral(""));
        clean2 = new QPushButton(centralWidget);
        clean2->setObjectName(QStringLiteral("clean2"));
        clean2->setGeometry(QRect(550, 520, 88, 33));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 580, 171, 31));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        label->setFont(font3);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(480, 580, 171, 31));
        label_4->setFont(font3);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(790, 570, 111, 41));
        label_5->setFont(font3);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(490, 660, 271, 61));
        label_6->setFont(font3);
        clean3 = new QPushButton(centralWidget);
        clean3->setObjectName(QStringLiteral("clean3"));
        clean3->setGeometry(QRect(850, 520, 88, 33));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1170, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        picture_1->setText(QApplication::translate("MainWindow", "imagen 1", Q_NULLPTR));
        picture_2->setText(QApplication::translate("MainWindow", "Imagen 2", Q_NULLPTR));
        resultado->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "x:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        open1->setText(QApplication::translate("MainWindow", "Abrir", Q_NULLPTR));
        open2->setText(QApplication::translate("MainWindow", "Abrir", Q_NULLPTR));
        canales->clear();
        canales->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "BLUE", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GREEN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RED", Q_NULLPTR)
        );
        geometricas->clear();
        geometricas->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ESCALAMIENTO 1:2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ESCALAMIENTO 1:4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ESCALAMIENTO 1:8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ROTACION", Q_NULLPTR)
        );
        logicas->clear();
        logicas->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SUMA", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RESTA", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RESTA_NORMALIZADA", Q_NULLPTR)
         << QApplication::translate("MainWindow", "AND", Q_NULLPTR)
         << QApplication::translate("MainWindow", "OR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "NEGATIVO", Q_NULLPTR)
        );
        close->setText(QApplication::translate("MainWindow", "Cerrar", Q_NULLPTR));
        clean1->setText(QApplication::translate("MainWindow", "limpiar", Q_NULLPTR));
        clean2->setText(QApplication::translate("MainWindow", "limpiar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Canales BGR", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Aritmeticas", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "L\303\263gicas", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Traslacion", Q_NULLPTR));
        clean3->setText(QApplication::translate("MainWindow", "limpiar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
