#include <cmath>
#include <iostream>
#include "point.hpp"

//#define M_PI 3.14159

inline double toRad(const double angle) {
    return angle * (M_PI / 180);
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

Point::Point(const Point &&other) noexcept : x(other.x), y(other.y), z(other.z) {
    other.~Point();
}

Point &Point::operator=(Point &&other) noexcept {
    this->setX(other.x);
    this->setY(other.y);
    this->setZ(other.z);
    other.~Point();

    return *this;
}

bool Point::operator==(const Point &other) const noexcept {
    return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
}

bool Point::equ(const Point &other) const noexcept {
    return *this == other;
}

bool Point::operator!=(const Point &other) const noexcept {
    return !(*this == other);
}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

double Point::getZ() const {
    return this->z;
}

void Point::setX(double new_x) {
    this->x = new_x;
}

void Point::setY(double new_y) {
    this->y = new_y;
}

void Point::setZ(double new_z) {
    this->z = new_z;
}

Point Point::operator+(const Point &other) {
    Point res(*this);

    res.setX(res.x + other.x);
    res.setY(res.y + other.y);
    res.setZ(res.z + other.z);

    return res;
}

Point Point::operator-() const {
    return Point(-this->x, -this->y, -this->z);
}

Point Point::operator-(const Point &other) {
    Point res(*this);

    res.setX(res.x - other.x);
    res.setY(res.y - other.y);
    res.setZ(res.z - other.z);

    return res;
}

void Point::move(double dx, double dy, double dz) {
    this->setX(this->x + dx);
    this->setY(this->y + dy);
    this->setZ(this->z + dz);
}

void Point::scale(double kx, double ky, double kz) {
    this->setX(this->x * kx);
    this->setY(this->y * ky);
    this->setZ(this->z * kz);
}

void Point::rotate(double ax, double ay, double az, const Point &center) {
    this->rotateX(ax, center);
    this->rotateY(ay, center);
    this->rotateZ(az, center);
}

void Point::rotateX(double ax, const Point &center) {
    const double _cos = cos(toRad(ax));
    const double _sin = sin(toRad(ax));
    const double _y = center.y;
    const double _z = center.z;

    this->setY(_y + (this->y - _y) * _cos + (this->z - _z) * _sin);
    this->setZ(_z + (this->z - _z) * _cos - (this->y - _y) * _sin);
}

void Point::rotateY(double ay, const Point &center) {
    const double _cos = cos(toRad(ay));
    const double _sin = sin(toRad(ay));
    const double _x = center.x;
    const double _z = center.z;

    this->setX(_x + (this->x - _x) * _cos + (this->z - _z) * _sin);
    this->setZ(_z + (this->z - _z) * _cos - (this->x - _x) * _sin);
}

void Point::rotateZ(double az, const Point &center) {
    const double _cos = cos(toRad(az));
    const double _sin = sin(toRad(az));
    const double _x = center.x;
    const double _y = center.y;

    this->setX(_x + (this->x - _x) * _cos + (this->y - _y) * _sin);
    this->setY(_y + (this->y - _y) * _cos - (this->x - _x) * _sin);
}

Point Point::relativeTo(const Point &point) {
    return *this + point;
}


