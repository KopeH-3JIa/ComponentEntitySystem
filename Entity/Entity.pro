TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++14
SOURCES += main.cpp \
    component.cpp \
    entity.cpp
include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    component.h \
    entity.h

