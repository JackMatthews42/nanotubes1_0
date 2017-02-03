#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QSignalMapper>
#include <QVector>

namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);
    ~MyWindow();

private:
    Ui::MyWindow *ui;
    double alpha;
    double C; // модуль вектора хиральности
    double kc;


private slots:
    void dataPlot();


    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_spinBox_4_valueChanged(int arg1);
    void on_pushButton_4_clicked();
};

#endif // MYWINDOW_H
