#ifndef VECTORREALISATION_HPP
#define VECTORREALISATION_HPP

#define PI 3.14
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include <initializer_list>

#include "exceptions.hpp"
#include "vector.hpp"
#include "iterator.hpp"
#include "constIterator.hpp"


template <typename T>
void Vector<T>::allocMemForVector(size_t size)
{
    time_t curTime = time(NULL);
    try{
        this->projections.reset(new T[size]);
    }
    catch(const std::exception& e) {
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}

template <typename Type>
Vector<Type>::Vector()
{
    this->sizeV = 0;
    this->allocMemForVector(sizeV);
}

template <typename Type>
Vector<Type>::Vector(const std::initializer_list<Type> &listForm)
{
    this->sizeV = listForm.size();
    this->allocMemForVector(sizeV);

    IteratorV<Type> iter = this->begin();
    for (auto &cur : listForm)
    {
        *iter = cur;
        iter++;
    }
}

template <typename Type>
Vector<Type>::Vector(size_t size)
{
    time_t curTime = time(NULL);
    this->allocMemForVector(size);
    if (!this->projections)
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    this->sizeV = size;
    IteratorV<Type> iter = this->begin();
    for (; iter; iter++)
        *iter = 0;
}

template <typename Type>
Vector<Type>::Vector(size_t size, const Type *arrayPtr)
{
    if (size == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (!arrayPtr)
    {
        time_t curTime = time(NULL);
        throw InvalidArrayPointerException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->allocMemForVector(size);
    this->sizeV = size;

    IteratorV<Type> iter = this->begin();
    for (size_t i = 0; i < size; i++, iter++)
        *iter = arrayPtr[i];
}

template <typename Type>
Vector<Type>::Vector(size_t size, const Type el)
{
    if (size == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->allocMemForVector(size);
    this->sizeV = size;

    IteratorV<Type> iter = this->begin();
    for (; iter; iter++)
        *iter = el;
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type> &vector):  VectorRoot(vector.sizeV)
{
    this->sizeV = vector.size();
    this->allocMemForVector(sizeV);
    IteratorV<Type> iter = this->begin();
    ConstIteratorV<Type> iterFrom = vector.begin();
    for (; iter; iter++, iterFrom++)
        *iter = *iterFrom;
}

template <typename Type>
IteratorV<Type> Vector<Type>::begin()
{
    IteratorV<Type> iter(*this);
    return iter;
}

template <typename Type>
ConstIteratorV<Type> Vector<Type>::begin() const
{
    ConstIteratorV<Type> iter(*this);
    return iter;
}

template <typename Type>
IteratorV<Type> Vector<Type>::end()
{
    IteratorV<Type> iter(*this);
    return iter + this->sizeV;
}

template <typename Type>
ConstIteratorV<Type> Vector<Type>::end() const
{
    ConstIteratorV<Type> iter(*this);
    return iter + this->sizeV;
}

template <typename Type>
ConstIteratorV<Type> Vector<Type>::cBegin() const
{
    ConstIteratorV<Type> iter(*this);
    return iter;
}

template <typename Type>
ConstIteratorV<Type> Vector<Type>::cEnd() const
{
    ConstIteratorV<Type> iter(*this);
    return iter + this->sizeV;
}

template <typename Type>
template <typename TypeOut>
TypeOut Vector<Type>::lenght() const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    ConstIteratorV<Type> iter = this->begin();
    Type sum = 0;
    for (; iter; iter++)
        sum += *iter * *iter;
    return sqrt(sum);
}

template <typename Type>
bool Vector<Type>::isZeroVector() const
{
    return this->lenght<Type>() < __FLT_EPSILON__;
}

template <typename Type>
bool Vector<Type>::isSingleVector() const
{
    return fabs(this->lenght<Type>() - 1) < __FLT_EPSILON__;
}

template <typename Type>
double Vector<Type>::angle(const Vector<Type> &vector) const
{
    if (this->isZeroVector() || vector.isZeroVector())
    {
        time_t curTime = time(NULL);
        throw ZeroDivisionException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    double angle = (*this & vector) / (this->lenght<double>() * vector.lenght<double>());
    return acos(angle) * 180 / PI;
}

template <typename Type>
bool Vector<Type>::parallel(const Vector<Type> &vector) const
{
    double angel = this->angle(vector);
    return angel < __DBL_EPSILON__ || fabs(angel - 180) < __DBL_EPSILON__;
}

template <typename Type>
bool Vector<Type>::perpendicular(const Vector<Type> &vector) const
{
    double angel = this->angle(vector);
    return fabs(angel - 90) < __DBL_EPSILON__ || fabs(angel - 270) < __DBL_EPSILON__;
}

template <typename Type>
Type &Vector<Type>::at(size_t pos)
{
    if (pos > sizeV)
    {
        time_t curTime = time(NULL);
        throw IndexOutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    IteratorV<Type> iter = this->begin();
    iter += pos;
    return *iter;
}

template <typename Type>
const Type &Vector<Type>::at(size_t pos) const
{
    if (pos > sizeV)
    {
        time_t curTime = time(NULL);
        throw IndexOutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    ConstIteratorV<Type> iter = this->begin();
    iter += pos;
    return *iter;
}

template <typename Type>
Type &Vector<Type>::operator[](size_t pos)
{
    return at(pos);
}

template <typename Type>
const Type &Vector<Type>::operator[](size_t pos) const
{
    return at(pos);
}

template <typename Type>
Vector<Type> Vector<Type>::negative()
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    IteratorV<Type> iter = this->begin();
    for (; iter; iter++)
        *iter = - *iter;
    return Vector(*this);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-()
{
    return Vector(this->negative());
}

template <typename Type>
bool Vector<Type>::isEqual(const Vector<Type> &vector) const
{
    bool equal = this->sizeV == vector.size();
    if (equal && this->sizeV != 0)
    {
        ConstIteratorV<Type> iter1 = this->begin();
        ConstIteratorV<Type> iter2 = vector.begin();
        for (; equal && iter1; iter1++, iter2++)
            equal = equal && (*iter1 == *iter2);
    }
    return equal;
}

template <typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const
{
    return this->isEqual(vector);
}

template <typename Type>
bool Vector<Type>::isNotEqual(const Vector<Type> &vector) const
{
    return !(this->isEqual(vector));
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &vector) const
{
    return this->isNotEqual(vector);
}

#endif
