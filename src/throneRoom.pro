TEMPLATE = app
CONFIG += c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        Subject.cpp \
        globals.cpp \
        King.cpp \
        King.h \
        globals.h

QT += core

QMAKE_CXXFLAGS += -std=c++2a
