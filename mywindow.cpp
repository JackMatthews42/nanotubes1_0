#include "mywindow.h"
#include "ui_mywindow.h"
#include "qcustomplot.h"
#include <QVector>
#include <math.h>
#include <QDebug>
#include <QFile>

#define A                   sqrt(3)*1.42*pow(10,-10)
#define gamma0              3

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);


    ui->pushButton_2->isEnabled();
    ui->widget->xAxis->setLabel("K, 2pi/A");
    ui->widget->yAxis->setLabel("Energy, Ev");

}

MyWindow::~MyWindow()
{
    delete ui;
}

// нарисовать график
void MyWindow::dataPlot()
{
    double kx,ky,kl,kl0,Q,P,I;
    I = ui->spinBox_4->value();

    QVector<double> E(I),x(I);

        for(int i = 0 ; i < I; i++)
        {
            kl0 = 2*M_PI/(100*A);
            kl = i*(2*M_PI)/(100*A);
            kx = kc*cos(alpha)-kl*sin(alpha);
            ky = kc*sin(alpha)+kl*cos(alpha);

            Q = 4*cos(A*kx/2)*cos(sqrt(3)*A*ky/2);
            P = 4*cos(A*kx/2)*cos(A*kx/2);

            E[i] = gamma0*sqrt(1+Q+P);
            x[i] = kl0+kl;
        }

        ui->widget->addGraph();
        ui->widget->graph(0)->setPen(QPen(Qt::blue));
        ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));


        ui->widget->xAxis->setVisible(true);
        ui->widget->xAxis->setTickLabels(true);
        ui->widget->yAxis->setVisible(true);
        ui->widget->yAxis->setTickLabels(true);

        connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis, SLOT(setRange(QCPRange)));
        connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis, SLOT(setRange(QCPRange)));

        ui->widget->graph(0)->setData(x,E);
        ui->widget->graph(0)->rescaleAxes(true);
        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

        ui->widget->replot();
}

// очистить график
void MyWindow::on_pushButton_clicked()
{
    ui->widget->clearGraphs();
    ui->widget->replot();
}

// опрос формы по клику кнопки
void MyWindow::on_pushButton_2_clicked()
{
    double alpha2,Cx,Cy;
    int n,m,N;
    QString stralpha,strC,strkc;

    n = ui->spinBox->value();
    m = ui->spinBox_2->value();

    alpha2 = 57.325*atan((sqrt(3)*m)/(2*n+m)); // расчёт угла в градусах для представления на форме
    alpha = atan((sqrt(3)*m)/(2*n+m));         // расчёт угла в радианах для последующего использования в программе

    stralpha.setNum(alpha2);
    stralpha = stralpha + " град";
    ui -> lineEdit->setText(stralpha);

    Cx = (n + 0.5*m)*A;
    Cy = 0.5*sqrt(3)*m*A;
    C = sqrt(pow(Cx,2)+pow(Cy,2));

    strC.setNum(C);
    strC = strC + " метров";
    ui->lineEdit_3->setText(strC);

    N = ui->spinBox_3->value();
    kc = 2*M_PI*N/C;
    strkc.setNum(kc);

    ui->lineEdit_2->setText(strkc);

    dataPlot();

}

void MyWindow::on_pushButton_3_clicked()
{

}

void MyWindow::on_pushButton_4_clicked()
{
    QFile some_file("C:/Пользователи/NextO/Рабочий стол/tmp_data2.txt");
    if(!some_file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    else qDebug() << "Файл открыт для записи";
    QByteArray aa("junk just");
    some_file.write(aa);
    some_file.close();
    qDebug() << "Все действия завершены!";
    qDebug() <<" safadfdsfasdfasdfsad ";
}

void MyWindow::on_spinBox_4_valueChanged(int arg1)
{
    qDebug() <<" safadfdsfasdfasdfsad ";
}
