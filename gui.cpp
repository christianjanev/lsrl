#include "gui.h"
#include "qcolor.h"
#include "stats.h"
#include "data.h"
#include <iostream>

Window::Window(QWidget* parent) : QMainWindow(parent)
{
    ui = new Ui_LSRL_Design;
    ui->setupUi(this);

    table = ui->table;

    std::vector<float> x;
    std::vector<float> y;

    auto data = read_data("data.csv");
    data_tables = data.first;
    titles = data.second;
    x = data_tables.first;
    y = data_tables.second;

    QStringList titles;
    titles.append(QString::fromStdString(data.second.first));
    titles.append(QString::fromStdString(data.second.second));
    table->setHorizontalHeaderLabels(titles);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setRowCount(x.size());


    series = new QScatterSeries;
    line = new QScatterSeries;


    for (int i = 0; i < x.size(); i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem;

        item->setText(QString::fromStdString(std::to_string(x[i])));
        table->setItem(i, 0, item);

        item = new QTableWidgetItem;

        item->setText(QString::fromStdString(std::to_string(y[i])));
        table->setItem(i, 1, item);

        series->append(x[i], y[i]);
        line->append(x[i], y[i]);
    }

    series->setMarkerSize(10);
    series->setBestFitLineVisible(false);
    series->setSelectedColor(QColorConstants::Red);

    QPen pen = line->bestFitLinePen();
    pen.setWidth(pen.width() * 3);
    line->setBestFitLinePen(pen);
    line->setPointsVisible(false);
    line->setBestFitLineVisible(true);
    line->setBestFitLineColor(QColorConstants::Black);

    graph = ui->graph->chart();
    graph->addSeries(series);
    graph->addSeries(line);
    graph->createDefaultAxes();
    graph->legend()->hide();
    graph->setDropShadowEnabled(false);

    connect(table, &QTableWidget::cellChanged, this, &Window::table_updated);
}

Window::~Window()
{
    delete ui;
}

void Window::table_updated(int row, int col)
{
    series->replace(data_tables.first[row], data_tables.second[row], std::stof(table->item(row, 0)->text().toStdString()), std::stof(table->item(row, 1)->text().toStdString()));
    line->replace(data_tables.first[row], data_tables.second[row], std::stof(table->item(row, 0)->text().toStdString()), std::stof(table->item(row, 1)->text().toStdString()));
    
    if (col == 0)
        data_tables.first[row] = std::stof(table->item(row, col)->text().toStdString());
    else
        data_tables.second[row] = std::stof(table->item(row, col)->text().toStdString());
}

void Window::button_pressed()
{
    std::optional<linear_equation> lsrl = linreg(data_tables.first, data_tables.second);
    std::optional<float> correlation_coefficient = r(data_tables.first, data_tables.second);

    if (lsrl.has_value())
        equation_string = titles.second + " = " + std::to_string(lsrl.value().a) + " + " + std::to_string(lsrl->b) + "(" + titles.first + ")";
    else { std::cerr << "X and Y must be the same size.\n"; exit(1); }
    
    if (correlation_coefficient.has_value())
        r_string = "r=" + std::to_string(correlation_coefficient.value());
    else { std::cerr << "X and Y must be the same size.\n"; exit(1); }
    equation->setText(QString::fromStdString(equation_string));
    correlation->setText(QString::fromStdString(r_string));
}