#include "../qt_drawer.hpp"
#include "qt_drawer_factory.hpp"
#include <memory>

QtDrawerFactory::QtDrawerFactory(std::shared_ptr<QGraphicsScene> &scene) : scene(scene) {}

std::unique_ptr<Drawer> QtDrawerFactory::createDrawer() {
    return std::unique_ptr<QtDrawer>(new QtDrawer(this->scene));
}

