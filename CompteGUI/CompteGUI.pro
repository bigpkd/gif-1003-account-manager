TEMPLATE = app
TARGET = CompteGUI
QT += core \
    gui
HEADERS += suppressioncompteinterface.h \
    ajoutepargneinterface.h \
    ajoutchequeinterface.h \
    comptegui.h
SOURCES += suppressioncompteinterface.cpp \
    ajoutepargneinterface.cpp \
    ajoutchequeinterface.cpp \
    main.cpp \
    comptegui.cpp
FORMS += suppressioncompteinterface.ui \
    ajoutepargneinterface.ui \
    ajoutchequeinterface.ui \
    comptegui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
