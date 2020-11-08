QT       +=core gui sql printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrador.cpp \
    alumno.cpp \
    cambiar_contrasena.cpp \
    foto.cpp \
    inicio.cpp \
    main.cpp \
    materias_aprobadas.cpp \
    materias_por_cursar.cpp \
    mostrar_avance.cpp \
    reestablecer_contrasenia.cpp \
    restablecer_contrasena1.cpp \
    visualizar_materias.cpp

HEADERS += \
    administrador.h \
    alumno.h \
    cambiar_contrasena.h \
    foto.h \
    inicio.h \
    materias_aprobadas.h \
    materias_por_cursar.h \
    mostrar_avance.h \
    reestablecer_contrasenia.h \
    restablecer_contrasena1.h \
    visualizar_materias.h

FORMS += \
    administrador.ui \
    alumno.ui \
    cambiar_contrasena.ui \
    foto.ui \
    inicio.ui \
    materias_aprobadas.ui \
    materias_por_cursar.ui \
    mostrar_avance.ui \
    reestablecer_contrasenia.ui \
    restablecer_contrasena1.ui \
    visualizar_materias.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    SRC.qrc

DISTFILES +=
