QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui/qt/drawer/factory/qt_drawer_factory.cpp \
    gui/qt/drawer/qt_drawer.cpp \
    implementation/commands/camera/add/add_camera.cpp \
    implementation/commands/camera/count/count_cameras.cpp \
    implementation/commands/camera/load/load_camera.cpp \
    implementation/commands/camera/move/move_camera.cpp \
    implementation/commands/camera/remove/remove_camera.cpp \
    implementation/commands/camera/set/set_camera.cpp \
    implementation/commands/model/add/add_model.cpp \
    implementation/commands/model/count/count_models.cpp \
    implementation/commands/model/load/load_model.cpp \
    implementation/commands/model/move/move_model.cpp \
    implementation/commands/model/remove/remove_model.cpp \
    implementation/commands/model/rotate/rotate_model.cpp \
    implementation/commands/model/scale/scale_model.cpp \
    implementation/commands/model/transform/transform_model.cpp \
    implementation/commands/scene/get_main_camera/get_main_camera.cpp \
    implementation/commands/scene/get_object/get_object.cpp \
    implementation/commands/scene/get_scene/get_scene.cpp \
    implementation/commands/scene/render/render_scene.cpp \
    implementation/drawer/solution/solution_drawer_factory.cpp \
    implementation/facade/facade.cpp \
    implementation/load/builders/camera/file_camera_builder/file_camera_builder.cpp \
    implementation/load/builders/model/file_model_builder/file_wireframe_model_builder/file_wireframe_model_builder.cpp \
    implementation/load/directors/camera/camera_director.cpp \
    implementation/load/directors/model/wireframe_model/wireframe_model_director.cpp \
    implementation/load/directors/solution/director_solution.cpp \
    implementation/load/loaders/camera/file_camera_loader.cpp \
    implementation/load/loaders/model/file_wireframe_model_loader.cpp \
    implementation/managers/draw/draw_manager.cpp \
    implementation/managers/load/load_manager.cpp \
    implementation/managers/scene/scene_manager.cpp \
    implementation/managers/transform/transform_manager.cpp \
    implementation/objects/camera/camera.cpp \
    implementation/objects/composite/composite.cpp \
    implementation/objects/model/wireframe_model/model_details/edge/edge.cpp \
    implementation/objects/model/wireframe_model/model_details/point/point.cpp \
    implementation/objects/model/wireframe_model/model_details/wireframe_model_details.cpp \
    implementation/objects/model/wireframe_model/wireframe_model.cpp \
    implementation/scene/scene.cpp \
    implementation/visitor/draw_visitor/draw_visitor.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    design.h \
    display.h \
    gui/qt/design.h \
    gui/qt/display.h \
    gui/qt/drawer/factory/qt_drawer_factory.hpp \
    gui/qt/drawer/qt_drawer.hpp \
    implementation/commands/camera/add/add_camera.hpp \
    implementation/commands/camera/camera_command.hpp \
    implementation/commands/camera/count/count_cameras.hpp \
    implementation/commands/camera/load/load_camera.hpp \
    implementation/commands/camera/move/move_camera.hpp \
    implementation/commands/camera/remove/remove_camera.hpp \
    implementation/commands/camera/set/set_camera.hpp \
    implementation/commands/command.hpp \
    implementation/commands/model/add/add_model.hpp \
    implementation/commands/model/count/count_models.hpp \
    implementation/commands/model/load/load_model.hpp \
    implementation/commands/model/model_command.hpp \
    implementation/commands/model/move/move_model.hpp \
    implementation/commands/model/remove/remove_model.hpp \
    implementation/commands/model/rotate/rotate_model.hpp \
    implementation/commands/model/scale/scale_model.hpp \
    implementation/commands/model/transform/transform_model.hpp \
    implementation/commands/scene/get_main_camera/get_main_camera.hpp \
    implementation/commands/scene/get_object/get_object.hpp \
    implementation/commands/scene/get_scene/get_scene.hpp \
    implementation/commands/scene/render/render_scene.hpp \
    implementation/commands/scene/scene_command.hpp \
    implementation/drawer/drawer.hpp \
    implementation/drawer/solution/solution_drawer_factory.hpp \
    implementation/exceptions/base_exception.hpp \
    implementation/exceptions/camera_exceptions.hpp \
    implementation/exceptions/load_exceptions.hpp \
    implementation/exceptions/model_exceptions.hpp \
    implementation/exceptions/ui_exceptions.hpp \
    implementation/facade/facade.hpp \
    implementation/load/builders/camera/camera_builder.hpp \
    implementation/load/builders/camera/file_camera_builder/file_camera_builder.hpp \
    implementation/load/builders/model/file_model_builder/file_model_builder.hpp \
    implementation/load/builders/model/file_model_builder/file_wireframe_model_builder/file_wireframe_model_builder.hpp \
    implementation/load/builders/model/model_builder.hpp \
    implementation/load/builders/object_builder.hpp \
    implementation/load/directors/camera/camera_director.hpp \
    implementation/load/directors/load_director.hpp \
    implementation/load/directors/model/model_director.hpp \
    implementation/load/directors/model/wireframe_model/wireframe_model_director.hpp \
    implementation/load/directors/solution/director_solution.hpp \
    implementation/load/loaders/camera/file_camera_loader.hpp \
    implementation/load/loaders/file_base_loader.hpp \
    implementation/load/loaders/model/file_wireframe_model_loader.hpp \
    implementation/managers/draw/draw_manager.hpp \
    implementation/managers/load/load_manager.hpp \
    implementation/managers/manager.hpp \
    implementation/managers/manager_creator.hpp \
    implementation/managers/scene/scene_manager.hpp \
    implementation/managers/transform/transform_manager.hpp \
    implementation/objects/camera/camera.hpp \
    implementation/objects/composite/composite.hpp \
    implementation/objects/model/model.hpp \
    implementation/objects/model/wireframe_model/model_details/edge/edge.hpp \
    implementation/objects/model/wireframe_model/model_details/point/point.hpp \
    implementation/objects/model/wireframe_model/model_details/wireframe_model_details.hpp \
    implementation/objects/model/wireframe_model/wireframe_model.hpp \
    implementation/objects/object.hpp \
    implementation/scene/scene.hpp \
    implementation/visitor/draw_visitor/draw_visitor.hpp \
    implementation/visitor/visitor.hpp \
    mainwindow.h

FORMS += \
    gui/qt/ui/design.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/cameras/camera1.dat \
    data/configuration/CameraDirector.cfg \
    data/configuration/WireframeModelDirector.cfg \
    data/configuration/drawer.cfg \
    data/models/model_1.dat \
    data/models/model_2.dat \
    docs/lab_03.drawio \
    docs/lab_03.svg \
    docs/lab_03_new.svg
