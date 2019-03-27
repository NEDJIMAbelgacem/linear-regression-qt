#include <QObject>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QMap>
#include <QtGlobal>
#include <QPair>
#include <QString>
#include <QUrl>

class RegressionChartManager : public QObject {
    Q_OBJECT
private:
    QtCharts::QScatterSeries* point_series = nullptr;
    QtCharts::QLineSeries* regression_line = nullptr;
    QMap<float, float> points_map;
public:
    RegressionChartManager(QtCharts::QScatterSeries* point_series, QtCharts::QLineSeries* regression_line);
    ~RegressionChartManager();
    void clear();
    QPair<qreal, qreal> ordinaryLeastSquaresMethod();
public slots:
    void add_point(qreal x, qreal y);
    void erase_point(qreal x, qreal y);
    void apply_regression();
    void load_csv_file(QUrl fileUrl);
    void generate_random_points(int n);
    void save_csv_file(QUrl fileUrl);
};