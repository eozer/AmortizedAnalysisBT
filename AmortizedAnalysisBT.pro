QT += core
QT -= gui

CONFIG += c++11

TARGET = AmortizedAnalysisBT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    binarysearchtree.cpp

HEADERS += \
    binarysearchtree.h
