#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T11:37:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DisplayCpuInfo
TEMPLATE = app


SOURCES += main.cpp\
        cpuinfodialogview.cpp \
    datasource.cpp \
    customtablemodel.cpp \
    standardlistmodel.cpp

HEADERS  += cpuinfodialogview.h \
    datasource.h \
    customtablemodel.h \
    standardlistmodel.h

FORMS    += cpuinfodialogview.ui
