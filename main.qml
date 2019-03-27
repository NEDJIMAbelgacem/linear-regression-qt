import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtCharts 2.2
import QtQuick.Dialogs 1.0

Rectangle {
    id: root
    width: 800; height: 600
    color: "lightgray"
    property int clickCount: 0
    property int menuBarSize: 10
    property real maxX: 10.0
    property real maxY: 10.0
    property real minX: 0.0
    property real minY: 0.0

    signal add_point(real x, real y);
    signal erase_point(real x, real y);
    signal apply_regression();
    signal load_csv_file(url fileUrl);
    signal generate_random_points(int n);
    signal save_csv_file(url fileUrl);
    
    function addPointToScatterSeries(x, y) {
        add_point(x, y);
    }

    function erasePointFromScatterSeries(x, y) {
        erase_point(x, y);
    }

    function getSliderValue(slider) {
        var val = slider.value.toFixed(2);
        return val;
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a csv file : "
        folder: shortcuts.home
        onAccepted: {
            if (fileDialog.selectExisting) load_csv_file(fileDialog.fileUrl);
            else save_csv_file(fileDialog.fileUrl);
        }
        Component.onCompleted: visible = false
        selectMultiple: false
        selectExisting: true
    }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 6

        RowLayout {
            width: parent.width
            spacing: 6
            Layout.margins: 6            

            Button {
                height: parent.height
                text: "Apply regression"
                onClicked: apply_regression()
            }

            Button {
                height: parent.height
                text: "Add"
                onClicked: addPointToScatterSeries(getSliderValue(xSlider), getSliderValue(ySlider))
            }

            Button {
                height: parent.height
                text: "Erase"
                onClicked: erasePointFromScatterSeries(getSliderValue(xSlider), getSliderValue(ySlider))
            }
            
            Text {
                text: "x = " + getSliderValue(xSlider)
            }

            Slider {
                id: xSlider
                from: 0
                value: 5
                to: 9.99
            }

            Text {
                text: "y = " + getSliderValue(ySlider)
            }

            Slider {
                id: ySlider
                from: 0
                value: 5
                to: 9.99
            }
        }

        RowLayout {
            Layout.margins: 6

            Button {
                text: "Load CSV file"
                onClicked: {
                    fileDialog.selectExisting = true;
                    fileDialog.open();
                }
            }

            Button {
                text: "Save as CSV file"
                onClicked: {
                    fileDialog.selectExisting = false;
                    fileDialog.open();
                }
            }

            Button {
                Layout.preferredWidth: 180
                text: "Generate " + randomPointsCount.value + " random points"
                onClicked: generate_random_points(randomPointsCount.value)
            }

            Slider {
                id: randomPointsCount
                from: 10
                to: 1000
                value: 20
                stepSize: 1
            }
        }


        RowLayout {
            width: parent.width

            Rectangle {
                height: parent.height
                width: parent.width
                color: "green"

                ChartView {
                    objectName: "chartview"
                    id: chartview
                    height: parent.height
                    width: parent.width

                    anchors.centerIn: parent
                    
                    theme: ChartView.ChartThemeBrownSand
                    antialiasing: true
                    
                    ValueAxis {
                        id: xAxis
                        min: minX
                        max: maxX
                    }

                    ValueAxis {
                        id: yAxis
                        min: minY
                        max: maxY
                    }

                    ScatterSeries {
                        id: scatterSeries
                        name: "input data"

                        axisX: xAxis
                        axisY: yAxis
                    }

                    LineSeries {
                        id: lineSeries
                        name: "regression line"
                        color: "blue"
                        
                        axisX: xAxis
                        axisY: yAxis
                    }
                }
            }
        }
    }
}