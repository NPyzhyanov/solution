TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        circle.cpp \
        ellipse.cpp \
        helix.cpp \
        main.cpp \
        print_array.cpp

HEADERS += \
    circle.h \
    consts.h \
    curve.h \
    curve_types.h \
    data_types.h \
    ellipse.h \
    helix.h \
    print_array.h
