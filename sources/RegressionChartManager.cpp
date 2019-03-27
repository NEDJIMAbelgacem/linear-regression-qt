#include "RegressionChartManager.h"
#include <iostream>
#include <string>
#include <QFile>
#include <QRandomGenerator>
#include <QTextStream>

RegressionChartManager::RegressionChartManager(QtCharts::QScatterSeries* point_series, QtCharts::QLineSeries* regression_line) 
{
    std::cout << "RegressionChartManager(" << point_series << ", " << regression_line << ")" << std::endl;
    this->regression_line = regression_line;
    this->point_series = point_series;
}

RegressionChartManager::~RegressionChartManager() { }

void RegressionChartManager::add_point(qreal x, qreal y) {
    if (points_map.find(x) == points_map.end()) {
        std::cout << "add_point(" << x << ", " << y << ")" << std::endl;
        points_map[x] = y;
        point_series->append(x, y);
    } else std::cout << "point (" << x << ", " << y << ") already exists" << std::endl;
}

void RegressionChartManager::erase_point(qreal x, qreal y) {
    auto it = points_map.find(x);
    if (it != points_map.end()) {
        std::cout << "erase_point(" << x << ", " << y << ")" << std::endl;
        points_map.erase(it);
        point_series->remove(x, y);
    } else std::cout << "point (" << x << ", " << y << ") doesn't exist" << std::endl;
}

QPair<qreal, qreal> RegressionChartManager::ordinaryLeastSquaresMethod() {
    int n = points_map.size();
    qreal sum_xy = 0.0f;
    qreal sum_xx = 0.0f;
    qreal sum_x = 0.0f;
    qreal sum_y = 0.0f;
    for (auto it = points_map.begin(); it != points_map.end(); ++it) {
        qreal x = it.key();
        qreal y = it.value();
        sum_xy += x * y;
        sum_xx += x * x;
        sum_x += x;
        sum_y += y;
    }
    qreal m = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    qreal c = sum_y / n - m * sum_x / n;
    return qMakePair(m, c);
}

void RegressionChartManager::apply_regression() {
    if (points_map.size() < 2) {
        std::cout << "cannot apply linear regression" << std::endl;
        std::cout << "reason : points_map.size() == " << points_map.size() << std::endl;
        return;
    }
    std::cout << "apply_regression()" << std::endl;
    QPair<qreal, qreal> p = ordinaryLeastSquaresMethod();
    qreal m = p.first;
    qreal c = p.second;
    
    regression_line->clear();
    regression_line->append(0.0f, c);
    regression_line->append(10.0f, 10.0f * m + c);
}

void RegressionChartManager::clear() {
    point_series->clear();
    points_map.clear();
}

void RegressionChartManager::load_csv_file(QUrl fileUrl) {
    std::cout << "load_csv_file(\"" << fileUrl.toString().toStdString() << "\")" << std::endl;
    QFile file(fileUrl.toLocalFile());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "error : couldn't open file \"" << fileUrl.toString().toStdString() << "\"" << std::endl;
        return;
    }
    int line_n = 0;
    this->clear();
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> values = line.split(';');
        if (values.size() != 2) {
            std::cout << "ill-formatted data at line " << line_n << std::endl;
        }
        qreal x = values[0].trimmed().toDouble();
        qreal y = values[1].trimmed().toDouble();
        add_point(x, y);
        line_n++;
    }
    apply_regression();
    file.close();
}

void RegressionChartManager::generate_random_points(int n) {
    std::cout << "generate_random_points(" << n << ")" << std::endl;
    this->clear();
    for (int i = 0; i < n; ++i) {
        qreal x = QRandomGenerator::global()->bounded(10.0f);
        qreal y = QRandomGenerator::global()->bounded(10.0f);
        add_point(x, y);
    }
    apply_regression();
}

void RegressionChartManager::save_csv_file(QUrl fileUrl) {
    std::cout << "save_csv_file(\"" << fileUrl.toString().toStdString() << "\")" << std::endl;
    QFile file(fileUrl.toLocalFile());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cout << "error : couldn't open file \"" << fileUrl.toString().toStdString() << "\"" << std::endl;
        return;
    }
    QTextStream out(&file);
    for (auto it = points_map.cbegin(); it != points_map.cend(); ++it) {
        qreal x = it.key();
        qreal y = it.value();
        out << x << ";" << y << "\n";
    }
    out.flush();
    file.close();
}