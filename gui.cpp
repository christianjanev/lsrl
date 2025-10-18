#include "gui.h"
#include "qcustomplot.h"
#include "stats.h"
#include "data.h"

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

    QStringList table_titles;
    table_titles.append(QString::fromStdString(data.second.first));
    table_titles.append(QString::fromStdString(data.second.second));
    table->setHorizontalHeaderLabels(table_titles);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setRowCount(x.size());

    // series = new QScatterSeries;
    // line = new QScatterSeries;
    x_series = new QVector<double>();
    y_series = new QVector<double>();

    for (int i = 0; i < x.size(); i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem;

        item->setText(QString::fromStdString(std::to_string(x[i])));
        table->setItem(i, 0, item);

        item = new QTableWidgetItem;

        item->setText(QString::fromStdString(std::to_string(y[i])));
        table->setItem(i, 1, item);

        // series->append(x[i], y[i]);
        // line->append(x[i], y[i]);
        x_series->append((double)x[i]);
        y_series->append((double)y[i]);
    }

    plot = ui->graph;
    x_axis = plot->xAxis;
    y_axis = plot->yAxis;
    
    // graph 0 = scatter only
    plot->addGraph();
    line = new QCPItemStraightLine(plot);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    plot->graph(0)->setData(*x_series, *y_series);
    plot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);

    QCPScatterStyle dot_style;
    dot_style.setShape(QCPScatterStyle::ssDisc);
    dot_style.setPen(QPen(Qt::blue));
    dot_style.setBrush(Qt::white);
    dot_style.setSize(15);
    plot->graph(0)->setScatterStyle(dot_style);
    plot->graph(0)->setSelectable(QCP::SelectionType::stSingleData);

    std::optional<linear_equation> eq = linreg(x, y);
    if (eq.has_value())
    {
        line->point1->setCoords(0, eq.value().a + eq.value().b * 0);
        line->point2->setCoords(5, eq.value().a + eq.value().b * 5);\
    }

    x_axis->setLabel(table_titles.first());
    y_axis->setLabel(table_titles.last());
    x_axis->setRangeUpper(max(data_tables.first).value() * 1.2);
    y_axis->setRangeUpper(max(data_tables.second).value() * 1.6);
    x_axis->setRangeLower(min(data_tables.first).value() - ( (min(data_tables.first).value() * 0.2) + 1 ));
    y_axis->setRangeLower(min(data_tables.second).value() - ( (min(data_tables.second).value() * 0.2) + 1 ));

    plot->replot();

    stats = ui->stats;

    r_item = new QTableWidgetItem;
    r2_item = new QTableWidgetItem;

    x_mean_item = new QTableWidgetItem;
    sum_x_item = new QTableWidgetItem;
    sum_x2_item = new QTableWidgetItem;
    std_dev_x_item = new QTableWidgetItem;
    min_x_item = new QTableWidgetItem;
    max_x_item = new QTableWidgetItem;

    y_mean_item = new QTableWidgetItem;
    sum_y_item = new QTableWidgetItem;
    sum_y2_item = new QTableWidgetItem;
    std_dev_y_item = new QTableWidgetItem;
    min_y_item = new QTableWidgetItem;
    max_y_item = new QTableWidgetItem;

    sum_multiplied_item = new QTableWidgetItem;

    size_item = new QTableWidgetItem;

    update_stats();

    stats->setItem(0, 0, r_item);
    stats->setItem(1, 0, r2_item);
    stats->setItem(2, 0, x_mean_item);
    stats->setItem(3, 0, sum_x_item);
    stats->setItem(4, 0, sum_x2_item);
    stats->setItem(5, 0, std_dev_x_item);
    stats->setItem(6, 0, min_x_item);
    stats->setItem(7, 0, max_x_item);

    stats->setItem(8, 0, y_mean_item);
    stats->setItem(9, 0, sum_y_item);
    stats->setItem(10, 0, sum_y2_item);
    stats->setItem(11, 0, std_dev_y_item);
    stats->setItem(12, 0, min_y_item);
    stats->setItem(13, 0, max_y_item);

    stats->setItem(14, 0, sum_multiplied_item);

    stats->setItem(15, 0, size_item);

    connect(table, &QTableWidget::cellChanged, this, &Window::table_updated);
    connect(table, &QTableWidget::currentCellChanged, this, &Window::cell_selected);
}

Window::~Window()
{
    delete ui;
}

void Window::table_updated(int row, int col)
{
    x_series->replace(x_series->indexOf(data_tables.first[row]), std::stof(table->item(row, 0)->text().toStdString()));
    y_series->replace(y_series->indexOf(data_tables.second[row]), std::stof(table->item(row, 1)->text().toStdString()));
    
    if (col == 0)
        data_tables.first[row] = std::stof(table->item(row, col)->text().toStdString());
    else
        data_tables.second[row] = std::stof(table->item(row, col)->text().toStdString());

    plot->graph(0)->setData(*x_series, *y_series);

    std::optional<linear_equation> eq = linreg(data_tables.first, data_tables.second);
    if (eq.has_value())
    {
        line->point1->setCoords(0, eq.value().a + eq.value().b * 0);
        line->point2->setCoords(5, eq.value().a + eq.value().b * 5);\
    }

    plot->replot();

    update_stats();
}

void Window::cell_selected(int row, int col, int old_row, int old_col)
{
    // series->setPointSelected(old_row, false);
    // series->setPointSelected(row, true);
}

void Window::button_pressed()
{
    // std::optional<linear_equation> lsrl = linreg(data_tables.first, data_tables.second);
    // std::optional<float> correlation_coefficient = r(data_tables.first, data_tables.second);

    // if (lsrl.has_value())
    //     equation_string = titles.second + " = " + std::to_string(lsrl.value().a) + " + " + std::to_string(lsrl->b) + "(" + titles.first + ")";
    // else { std::cerr << "X and Y must be the same size.\n"; exit(1); }
    
    // if (correlation_coefficient.has_value())
    //     r_string = "r=" + std::to_string(correlation_coefficient.value());
    // else { std::cerr << "X and Y must be the same size.\n"; exit(1); }
    // equation->setText(QString::fromStdString(equation_string));
    // correlation->setText(QString::fromStdString(r_string));
}

void Window::update_stats()
{
    std::optional<float> r_value = r(data_tables.first, data_tables.second);
    std::optional<sums> sum_pair = sum_of_two(data_tables.first, data_tables.second);
    std::optional<sums> sum2_pair = sum_of_two_squared(data_tables.first, data_tables.second);
    std::optional<float> x_min = min(data_tables.first);
    std::optional<float> x_max = max(data_tables.first);
    std::optional<float> y_min = min(data_tables.second);
    std::optional<float> y_max = max(data_tables.second);
    std::optional<float> var_x = variance(data_tables.first);
    std::optional<float> var_y = variance(data_tables.second);
    std::optional<float> sum_multiplied;

    r_string = "Failed to calculate r";
    r2_string = "Failed to calculated r^2";

    x_mean_string = "Failed to calculate mean of x";
    sum_x_string = "Failed to calculate sum of x";
    sum_x2_string = "Failed to calculate sum of x^2";
    std_dev_x_string = "Failed to calculate variance of x";
    min_x_string = "Failed to calculate min of x";
    max_x_string = "Failed to calculate max of x";

    y_mean_string = "Failed to calculate mean of y";
    sum_y_string = "Failed to calculate sum of y";
    sum_y2_string = "Failed to calculate sum of y^2";
    std_dev_y_string = "Failed to calculate variance of y";
    min_y_string = "Failed to calculate min of y";
    max_y_string = "Failed to calculate max of y";

    sum_multiplied_string = "Failed to calculate sum of lists multiplied";

    std::string size_string = std::to_string(data_tables.first.size());

    if (r_value.has_value())
    {
        r_string = std::to_string(r_value.value());
        r2_string = std::to_string(r_value.value() * r_value.value());
    }

    if (sum_pair.has_value())
    {
        sum_x_string = std::to_string(sum_pair.value().first);
        sum_y_string = std::to_string(sum_pair.value().second);

        x_mean_string = std::to_string(sum_pair.value().first / data_tables.first.size());
        y_mean_string = std::to_string(sum_pair.value().second / data_tables.first.size());
    }

    if (sum2_pair.has_value())
    {
        sum_x2_string = std::to_string(sum2_pair.value().first);
        sum_y2_string = std::to_string(sum2_pair.value().second);
    }

    if (x_min.has_value())
    {
        min_x_string = std::to_string(x_min.value());
        max_x_string = std::to_string(x_max.value());
    }

    if (y_min.has_value())
    {
        min_y_string = std::to_string(y_min.value());
        max_y_string = std::to_string(y_max.value());
    }

    if (var_x.has_value())
    {
        std_dev_x_string = std::to_string(std::sqrt(var_x.value()));
    }

    if (var_y.has_value())
    {
        std_dev_y_string = std::to_string(std::sqrt(var_y.value()));
    }

    if (data_tables.first.size() == data_tables.second.size())
    {
        std::vector<float> multiplied;

        for (int i = 0; i < data_tables.first.size(); i++)
        {
            multiplied.push_back(data_tables.first[i] * data_tables.second[i]);
        }

        sum_multiplied = sum(multiplied);

        if (sum_multiplied.has_value()) sum_multiplied_string = std::to_string(sum_multiplied.value());
    }

    r_item->setText(QString::fromStdString(r_string));
    r2_item->setText(QString::fromStdString(r2_string));

    x_mean_item->setText(QString::fromStdString(x_mean_string));
    sum_x_item->setText(QString::fromStdString(sum_x_string));
    sum_x2_item->setText(QString::fromStdString(sum_x2_string));
    std_dev_x_item->setText(QString::fromStdString(std_dev_x_string));
    min_x_item->setText(QString::fromStdString(min_x_string));
    max_x_item->setText(QString::fromStdString(max_x_string));

    y_mean_item->setText(QString::fromStdString(y_mean_string));
    sum_y_item->setText(QString::fromStdString(sum_y_string));
    sum_y2_item->setText(QString::fromStdString(sum_y2_string));
    std_dev_y_item->setText(QString::fromStdString(std_dev_y_string));
    min_y_item->setText(QString::fromStdString(min_y_string));
    max_y_item->setText(QString::fromStdString(max_y_string));

    sum_multiplied_item->setText(QString::fromStdString(sum_multiplied_string));

    size_item->setText(QString::fromStdString(size_string));
}