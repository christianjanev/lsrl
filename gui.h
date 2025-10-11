#ifndef GUI
#define GUI

#include "design.h"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QPainter>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QSizePolicy>
#include <QGridLayout>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QChart>
#include <QPen>

#include <string>
#include <iostream>

class Window : public QMainWindow
{
    public:
        Window(QWidget* parent);
        virtual ~Window();
        Ui_LSRL_Design* ui;
    private:
        QLabel* equation;
        QLabel* correlation;
        QTableWidget* table;
        std::string equation_string;
        std::string r_string;
        std::pair<std::vector<float>, std::vector<float>> data_tables;
        std::pair<std::string, std::string> titles;
        QScatterSeries* series;
        QScatterSeries* line;
        QChart* graph;
    private slots:
        void button_pressed();
        void table_updated(int row, int col);
};

#endif