#ifndef VECTORREALISATION_HPP
#define VECTORREALISATION_HPP

#define PI 3.14
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include <initializer_list>

#include "exceptions.hpp"
#include "vector.hpp"
#include "iteratorRealisation.hpp"
#include "constIteratorRealisation.hpp"


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
void Vector<Type>::checkSizes(const Vector<Type> &vector, int curLine) const
{
    if (this->sizeV != vector.size())
    {
        time_t curTime = time(NULL);
        throw NotSameRangeException(__FILE__, typeid(*this).name(), curLine, ctime(&curTime));
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
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
    this->sizeV = vector.size();
    this->allocMemForVector(sizeV);
    IteratorV<Type> iterto(*this);
    IteratorV<Type> iterfrom(vector);
    for (; iterto; iterto++, iterfrom++)
        *iterto = *iterfrom;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const std::initializer_list<Type> &listForm)
{
    this->sizeV = listForm.size();
    this->allocMemForVector(sizeV);
    IteratorV<Type> iter = this->begin();
    for (auto &cur : listForm)
    {
        *iter = cur;
        iter++;
    }
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::sumVec(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<Type> result(*this);
    IteratorV<Type> resIter = result.begin();
    ConstIteratorV<Type> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *resIter + *iterFrom;
    return Vector(result);
}

template <typename Type>
void Vector<Type>::sumEq(const Vector<Type> &vector)
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    *this = this->sumVec(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::sumEl(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<Type> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<Type> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *iterFrom + el;
    return Vector(result);
}

template <typename Type>
void Vector<Type>::sumEq(const Type &el)
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    *this = this->sumEl(el);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vector)
{
    this->sumEq(vector);
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type &el)
{
    this->sumEq(el);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    return this->sumVec(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->sumEl(el);
}




template <typename Type>
Vector<Type> Vector<Type>::difVec(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<Type> result(*this);
    IteratorV<Type> resIter = result.begin();
    ConstIteratorV<Type> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *resIter - *iterFrom;
    return Vector(result);
}

template <typename Type>
void Vector<Type>::difEq(const Vector<Type> &vector)
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    *this = this->difVec(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::difEl(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<Type> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<Type> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *iterFrom - el;
    return Vector(result);
}

template <typename Type>
void Vector<Type>::difEq(const Type &el)
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    *this = this->difEl(el);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector)
{
    this->difEq(vector);
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Type &el)
{
    this->difEq(el);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    return this->difVec(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->difEl(el);
}



template <typename Type>
Vector<Type> Vector<Type>::diVec(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<Type> result(*this);
    IteratorV<Type> resIter = result.begin();
    ConstIteratorV<Type> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *resIter / *iterFrom;
    return Vector(result);
}

template <typename Type>
void Vector<Type>::divEq(const Vector<Type> &vector)
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    *this = this->diVec(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::divEl(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<Type> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<Type> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *iterFrom / el;
    return Vector(result);
}

template <typename Type>
void Vector<Type>::divEq(const Type &el)
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    *this = this->divEl(el);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Vector<Type> &vector)
{
    this->divEq(vector);
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &el)
{
    this->divEq(el);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator/(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    return this->diVec(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator/(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->divEl(el);
}

template <typename Type>
void Vector<Type>::checkSizesForMul(const Vector<Type> &vector, int curLine) const
{
    if (this->sizeV != 3 || vector.size() != 3)
    {
        time_t curTime = time(NULL);
        throw NotSuitableRangeForMulException(__FILE__, typeid(*this).name(), curLine, ctime(&curTime));
    }
}

//Белоусов говорит, что векторное произведение (обладающее всеми свойствами привычного) -- только в размерности 3 и 7(а?)
template <typename Type>
void Vector<Type>::vecMulEq(const Vector<Type> &vector)
{
    this->checkSizesForMul(vector, __LINE__);
    Type x = this->projections[1] * vector.projections[2] - this->projections[2] * vector.projections[1];
    Type y = this->projections[2] * vector.projections[0] - this->projections[0] * vector.projections[2];
    Type z = this->projections[0] * vector.projections[1] - this->projections[1] * vector.projections[0];
    Vector<Type> newV = {x, y, z};
    *this = newV;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Vector<Type> &vector)
{
    this->checkSizesForMul(vector, __LINE__);
    *this = this->vecMulEq(vector);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(const Vector<Type> &vector) const
{
    this->checkSizesForMul(vector, __LINE__);
    Vector<Type> result(*this);
    result.vecMulEq(vector);
    return Vector(result);
}

template <typename Type>
Vector<Type> Vector<Type>::vecMulVec(const Vector<Type> &vector) const
{
    this->checkSizesForMul(vector, __LINE__);
    Vector<Type> result(*this);
    result.vecMulEq(vector);
    return Vector(result);
}



template <typename Type>
void Vector<Type>::vecMulEq(const Type &el)
{
    *this = this->vecMulEl(el);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &el)
{
    *this = this->vecMulEl(el);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->vecMulEl(el);
}

template <typename Type>
Vector<Type> Vector<Type>::vecMulEl(const Type &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<Type> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<Type> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = (*iterFrom) * el;
    return Vector(result);
}



template <typename Type>
Vector<Type> Vector<Type>::skewMulVec(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<Type> result(*this);
    IteratorV<Type> resIter = result.begin();
    ConstIteratorV<Type> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = (*resIter) * (*iterFrom);
    return Vector(result);
}

template <typename Type>
void Vector<Type>::skewMulEq(const Vector<Type> &vector)
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    *this = this->skewMulVec(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator^=(const Vector<Type> &vector)
{
    this->skewMulVec(vector);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator^(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    return this->skewMulVec(vector);
}


template <typename Type>
Type Vector<Type>::operator&(const Vector<Type> &vector) const
{
    return this->scalMulVec(vector);
}

template <typename Type>
Type Vector<Type>::scalMulVec(const Vector<Type> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Type sum = 0;
    Vector<Type> res(*this);
    res = res.skewMulVec(vector);
    IteratorV<Type> iter = res.begin();
    for (; iter; iter++)
        sum += *iter;
    return sum;
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
