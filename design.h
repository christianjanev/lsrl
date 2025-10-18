/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGN_H
#define UI_DESIGN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_LSRL_Design
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *calculate;
    QVBoxLayout *verticalLayout;
    QTableWidget *table;
    QTableWidget *stats;
    QCustomPlot *graph;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LSRL_Design)
    {
        if (LSRL_Design->objectName().isEmpty())
            LSRL_Design->setObjectName("LSRL_Design");
        LSRL_Design->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LSRL_Design->sizePolicy().hasHeightForWidth());
        LSRL_Design->setSizePolicy(sizePolicy);
        LSRL_Design->setMinimumSize(QSize(1600, 900));
        LSRL_Design->setTabShape(QTabWidget::TabShape::Rounded);
        actionOpen = new QAction(LSRL_Design);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(LSRL_Design);
        actionSave->setObjectName("actionSave");
        centralwidget = new QWidget(LSRL_Design);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 9, 1582, 841));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calculate = new QPushButton(gridLayoutWidget);
        calculate->setObjectName("calculate");

        gridLayout->addWidget(calculate, 1, 0, 1, 4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        table = new QTableWidget(gridLayoutWidget);
        if (table->columnCount() < 2)
            table->setColumnCount(2);
        if (table->rowCount() < 15)
            table->setRowCount(15);
        table->setObjectName("table");
        table->setGridStyle(Qt::PenStyle::DashLine);
        table->setSortingEnabled(true);
        table->setRowCount(15);
        table->setColumnCount(2);
        table->horizontalHeader()->setCascadingSectionResizes(false);
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(table);

        stats = new QTableWidget(gridLayoutWidget);
        if (stats->columnCount() < 1)
            stats->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        stats->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (stats->rowCount() < 16)
            stats->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        stats->setVerticalHeaderItem(15, __qtablewidgetitem16);
        stats->setObjectName("stats");
        stats->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(stats);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        graph = new QCustomPlot(gridLayoutWidget);
        graph->setObjectName("graph");
        graph->setMinimumSize(QSize(1200, 0));

        gridLayout->addWidget(graph, 0, 2, 1, 1);

        LSRL_Design->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LSRL_Design);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1600, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        LSRL_Design->setMenuBar(menubar);
        statusbar = new QStatusBar(LSRL_Design);
        statusbar->setObjectName("statusbar");
        LSRL_Design->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(LSRL_Design);

        QMetaObject::connectSlotsByName(LSRL_Design);
    } // setupUi

    void retranslateUi(QMainWindow *LSRL_Design)
    {
        LSRL_Design->setWindowTitle(QCoreApplication::translate("LSRL_Design", "LSRL", nullptr));
        actionOpen->setText(QCoreApplication::translate("LSRL_Design", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("LSRL_Design", "Save", nullptr));
        calculate->setText(QCoreApplication::translate("LSRL_Design", "Calculate", nullptr));
        QTableWidgetItem *___qtablewidgetitem = stats->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("LSRL_Design", "Two Variable Statistics", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = stats->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("LSRL_Design", "r", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = stats->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("LSRL_Design", "r\302\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = stats->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("LSRL_Design", "x\314\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = stats->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("LSRL_Design", "\316\243x", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = stats->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("LSRL_Design", "\316\243x\302\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = stats->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("LSRL_Design", "S\342\202\223", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = stats->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("LSRL_Design", "minX", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = stats->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("LSRL_Design", "maxX", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = stats->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("LSRL_Design", "y\314\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = stats->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("LSRL_Design", "\316\243y", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = stats->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("LSRL_Design", "\316\243y\302\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = stats->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("LSRL_Design", "S\341\265\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = stats->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("LSRL_Design", "minY", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = stats->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("LSRL_Design", "maxY", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = stats->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("LSRL_Design", "\316\243xy", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = stats->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("LSRL_Design", "n", nullptr));
        menuFile->setTitle(QCoreApplication::translate("LSRL_Design", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LSRL_Design: public Ui_LSRL_Design {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGN_H
