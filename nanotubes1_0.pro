#-------------------------------------------------
#
# Project created by QtCreator 2017-01-11T01:08:01
#
#-------------------------------------------------

QT += core gui serialport widgets

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport printsupport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = nanotubes1_0
TEMPLATE = app


SOURCES += main.cpp\
        mywindow.cpp \
    qcustomplot.cpp

HEADERS  += mywindow.h \
    qcustomplot.h

FORMS    += mywindow.ui
