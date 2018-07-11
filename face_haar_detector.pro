#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T17:27:16
#
#-------------------------------------------------

QT       -= core gui

QT += core

TARGET = face_haar_detector
TEMPLATE = lib

DEFINES += FACE_HAAR_DETECTOR_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += face_haar_detector.cpp

HEADERS += face_haar_detector.h\
        face_haar_detector_global.h \
    detector.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += /usr/local/include \
/usr/local/include/opencv \
/usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_legacy.so.2.4.13 \
/usr/local/lib/libopencv_features2d.so.2.4.13 \
/usr/local/lib/libopencv_imgproc.so.2.4.13 \
/usr/local/lib/libopencv_contrib.so.2.4.13 \
/usr/local/lib/libopencv_ocl.so.2.4.13 \
/usr/local/lib/libopencv_ml.so.2.4.13 \
/usr/local/lib/libopencv_highgui.so.2.4.13 \
/usr/local/lib/libopencv_core.so.2.4.13 \
/usr/local/lib/libopencv_superres.so.2.4.13 \
/usr/local/lib/libopencv_calib3d.so.2.4.13 \
/usr/local/lib/libopencv_photo.so.2.4.13 \
/usr/local/lib/libopencv_stitching.so.2.4.13 \
/usr/local/lib/libopencv_videostab.so.2.4.13 \
/usr/local/lib/libopencv_video.so.2.4.13 \
/usr/local/lib/libopencv_objdetect.so.2.4.13 \
/usr/local/lib/libopencv_nonfree.so.2.4.13 \
/usr/local/lib/libopencv_gpu.so.2.4.13 \
/usr/local/lib/libopencv_flann.so.2.4.13
