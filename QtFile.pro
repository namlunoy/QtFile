QT += core
QT -= gui

CONFIG += c++11

TARGET = QtFile
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
        input.txt \
        output.txt
