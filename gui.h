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
#include <QPen>
#include <qcustomplot.h>
#include <QVector>

#include <string>
#include <iostream>
#include <cmath>
#include <limits>

class Window : public QMainWindow
{
    public:
        Window(QWidget* parent);
        virtual ~Window();
        Ui_LSRL_Design* ui;
    private:
        QTableWidget* table;
        QTableWidget* stats;

        QTableWidgetItem* r_item;
        QTableWidgetItem* r2_item;
        QTableWidgetItem* x_mean_item;
        QTableWidgetItem* y_mean_item;
        QTableWidgetItem* sum_x_item;
        QTableWidgetItem* sum_y_item;
        QTableWidgetItem* sum_x2_item;
        QTableWidgetItem* sum_y2_item;
        QTableWidgetItem* min_x_item;
        QTableWidgetItem* max_x_item;
        QTableWidgetItem* min_y_item;
        QTableWidgetItem* max_y_item;
        QTableWidgetItem* std_dev_x_item;
        QTableWidgetItem* std_dev_y_item;
        QTableWidgetItem* sum_multiplied_item;
        QTableWidgetItem* size_item;

        std::string equation_string;
        std::string r_string;
        std::string r2_string;
        std::string x_mean_string;
        std::string y_mean_string;
        std::string sum_x_string;
        std::string sum_y_string;
        std::string sum_x2_string;
        std::string sum_y2_string;
        std::string min_x_string;
        std::string max_x_string;
        std::string min_y_string;
        std::string max_y_string;
        std::string std_dev_x_string;
        std::string std_dev_y_string;
        std::string sum_multiplied_string;

        std::pair<std::vector<float>, std::vector<float>> data_tables;
        std::pair<std::string, std::string> titles;

        // QScatterSeries* series;
        // QScatterSeries* line;
        // QChart* graph;
        // QValueAxis* x_axis;
        // QValueAxis* y_axis;

        QCustomPlot* plot;
        QCPItemStraightLine* line;
        QCPAxis* x_axis;
        QCPAxis* y_axis;
        QVector<double>* x_series;
        QVector<double>* y_series;
    private slots:
        void button_pressed();
        void table_updated(int row, int col);
        void cell_selected(int row, int col, int old_row, int old_col);
        void update_stats();
};

#endif