#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <QString>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <iostream>
#include <QtCharts/QChartView>
#include <QtQuick/QQuickItem>
#include <QtCharts/QChartView>
#include <QQmlProperty>
#include <QtQuickControls2/QtQuickControls2>
#include <QAbstractSeries>
#include <QMetaObject>
#include <QtGlobal>
#include <QUrl>

#include "RegressionChartManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView viewer;
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);
    viewer.setTitle(QStringLiteral("linear-regression"));
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.show();

    QQuickItem* root = viewer.rootObject();
    QQuickItem* chartview_obj = root->findChild<QQuickItem*>("chartview");
    QtCharts::QAbstractSeries* series0;
    QtCharts::QAbstractSeries* series1;
    QMetaObject::invokeMethod(chartview_obj, "series", Qt::AutoConnection, Q_RETURN_ARG(QtCharts::QAbstractSeries*, series0), Q_ARG(int, 0));
    QMetaObject::invokeMethod(chartview_obj, "series", Qt::AutoConnection, Q_RETURN_ARG(QtCharts::QAbstractSeries*, series1), Q_ARG(int, 1));

    QtCharts::QScatterSeries* point_series = qobject_cast<QtCharts::QScatterSeries*>(series0);
    QtCharts::QLineSeries* regression_line = qobject_cast<QtCharts::QLineSeries*>(series1);
    
    RegressionChartManager man(point_series, regression_line);

    QObject::connect(root, SIGNAL(add_point(qreal, qreal)),
                     &man, SLOT(add_point(qreal, qreal)));
    QObject::connect(root, SIGNAL(erase_point(qreal, qreal)),
                     &man, SLOT(erase_point(qreal, qreal)));
    QObject::connect(root, SIGNAL(apply_regression()),
                     &man, SLOT(apply_regression()));
    QObject::connect(root, SIGNAL(load_csv_file(QUrl)),
                     &man, SLOT(load_csv_file(QUrl)));
    QObject::connect(root, SIGNAL(generate_random_points(int)),
                     &man, SLOT(generate_random_points(int)));
    QObject::connect(root, SIGNAL(save_csv_file(QUrl)),
                     &man, SLOT(save_csv_file(QUrl)));
    
    return app.exec();
}