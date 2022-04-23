#ifndef VECTORREALISEFORDIFF_HPP
#define VECTORREALISEFORDIFF_HPP

#define PI 3.14
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include <initializer_list>

#include "exceptions.hpp"
#include "vector.hpp"
#include "iterator.hpp"
#include "constIterator.hpp"


template <typename Type>
template <typename TypeIn>
void Vector<Type>::checkSizes(const Vector<TypeIn> &vector, int curLine) const
{
    if (this->sizeV != vector.size())
    {
        time_t curTime = time(NULL);
        throw NotSameRangeException(__FILE__, typeid(*this).name(), curLine, ctime(&curTime));
    }
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator=(const Vector<TypeIn> &vector)
{
    this->sizeV = vector.size();
    this->allocMemForVector(sizeV);
    IteratorV<Type> iterto(*this);
    IteratorV<Type> iterfrom(vector);
    for (; iterto; iterto++, iterfrom++)
        *iterto = Type(*iterfrom);
    return *this;
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator=(const std::initializer_list<TypeIn> &listForm)
{
    this->sizeV = listForm.size();
    this->allocMemForVector(sizeV);
    IteratorV<Type> iter = this->begin();
    for (auto &cur : listForm)
    {
        *iter = Type(cur);
        iter++;
    }
    return *this;
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::sumVec(const Vector<TypeIn> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<decltype((*this)[0] + vector[0])> result(*this);
    IteratorV<decltype((*this)[0] + vector[0])> resIter = result.begin();
    ConstIteratorV<TypeIn> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *resIter + *iterFrom;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::sumEq(const Vector<TypeIn> &vector)
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
template <typename TypeIn>
decltype(auto) Vector<Type>::sumEl(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<decltype((*this)[0] + el)> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<decltype((*this)[0] + el)> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *iterFrom + el;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::sumEq(const TypeIn &el)
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    *this = this->sumEl(el);
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator+=(const Vector<TypeIn> &vector)
{
    this->sumEq(vector);
    return *this;
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator+=(const TypeIn &el)
{
    this->sumEq(el);
    return *this;
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::operator+(const Vector<TypeIn> &vector) const
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
template <typename TypeIn>
decltype(auto) Vector<Type>::operator+(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->sumEl(el);
}




template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::difVec(const Vector<TypeIn> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<decltype((*this)[0] + vector[0])> result(*this);
    IteratorV<Type> resIter = result.begin();
    ConstIteratorV<decltype((*this)[0] + vector[0])> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *resIter - *iterFrom;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::difEq(const Vector<TypeIn> &vector)
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
template <typename TypeIn>
decltype(auto) Vector<Type>::difEl(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<decltype((*this)[0] + el)> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<decltype((*this)[0] + el)> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *iterFrom - el;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::difEq(const TypeIn &el)
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    *this = this->difEl(el);
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator-=(const Vector<TypeIn> &vector)
{
    this->difEq(vector);
    return *this;
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator-=(const TypeIn &el)
{
    this->difEq(el);
    return *this;
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::operator-(const Vector<TypeIn> &vector) const
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
template <typename TypeIn>
decltype(auto) Vector<Type>::operator-(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->difEl(el);
}



template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::diVec(const Vector<TypeIn> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<decltype((*this)[0] / vector[0])> result(*this);
    IteratorV<decltype((*this)[0] / vector[0])> resIter = result.begin();
    ConstIteratorV<TypeIn> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *resIter / *iterFrom;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::divEq(const Vector<TypeIn> &vector)
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
template <typename TypeIn>
decltype(auto) Vector<Type>::divEl(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<decltype((*this)[0] / el)> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<decltype((*this)[0] / el)> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = *iterFrom / el;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::divEq(const TypeIn &el)
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    *this = this->divEl(el);
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator/=(const Vector<TypeIn> &vector)
{
    this->divEq(vector);
    return *this;
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator/=(const TypeIn &el)
{
    this->divEq(el);
    return *this;
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::operator/(const Vector<TypeIn> &vector) const
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
template <typename TypeIn>
decltype(auto) Vector<Type>::operator/(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->divEl(el);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::checkSizesForMul(const Vector<TypeIn> &vector, int curLine) const
{
    if (this->sizeV != 3 || vector.size() != 3)
    {
        time_t curTime = time(NULL);
        throw NotSuitableRangeForMulException(__FILE__, typeid(*this).name(), curLine, ctime(&curTime));
    }
}

//Белоусов говорит, что векторное произведение (обладающее всеми свойствами привычного) -- только в размерности 3 и 7(а?)
template <typename Type>
template <typename TypeIn>
void Vector<Type>::vecMulEq(const Vector<TypeIn> &vector)
{
    this->checkSizesForMul(vector, __LINE__);
    Type x = this->projections[1] * Type(vector.projections[2]) - this->projections[2] * Type(vector.projections[1]);
    Type y = this->projections[2] * Type(vector.projections[0]) - this->projections[0] * Type(vector.projections[2]);
    Type z = this->projections[0] * Type(vector.projections[1]) - this->projections[1] * Type(vector.projections[0]);
    Vector<Type> newV = {x, y, z};
    *this = newV;
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator*=(const Vector<TypeIn> &vector)
{
    this->checkSizesForMul(vector, __LINE__);
    *this = this->vecMulEq(vector);
    return *this;
}

template <typename Type>
template <typename TypeIn>
Vector<Type> Vector<Type>::operator*(const Vector<TypeIn> &vector) const
{
    this->checkSizesForMul(vector, __LINE__);
    Vector<Type> result(*this);
    result.vecMulEq(vector);
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
Vector<Type> Vector<Type>::vecMulVec(const Vector<TypeIn> &vector) const
{
    this->checkSizesForMul(vector, __LINE__);
    Vector<Type> result(*this);
    result.vecMulEq(vector);
    return Vector(result);
}



template <typename Type>
template <typename TypeIn>
void Vector<Type>::vecMulEq(const TypeIn &el)
{
    *this = this->vecMulEl(el);
}

template <typename Type>
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator*=(const TypeIn &el)
{
    *this = this->vecMulEl(el);
    return *this;
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::operator*(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return this->vecMulEl(el);
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::vecMulEl(const TypeIn &el) const
{
    if (this->sizeV == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<decltype((*this)[0] * el)> result(*this);
    ConstIteratorV<Type> iterFrom = this->begin();
    IteratorV<decltype((*this)[0] * el)> resIter = result.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = (*iterFrom) * el;
    return Vector(result);
}



template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::skewMulVec(const Vector<TypeIn> &vector) const
{
    if (this->sizeV == 0 || vector.size() == 0)
    {
        time_t curTime = time(NULL);
        throw EmptyVectorExcpretion(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    this->checkSizes(vector, __LINE__);
    Vector<decltype((*this)[0] * vector[0])> result(*this);
    IteratorV<decltype((*this)[0] * vector[0])> resIter = result.begin();
    ConstIteratorV<TypeIn> iterFrom = vector.begin();
    for (; resIter; resIter++, iterFrom++)
        *resIter = (*resIter) * *iterFrom;
    return Vector(result);
}

template <typename Type>
template <typename TypeIn>
void Vector<Type>::skewMulEq(const Vector<TypeIn> &vector)
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
template <typename TypeIn>
Vector<Type> &Vector<Type>::operator^=(const Vector<TypeIn> &vector)
{
    this->skewMulVec(vector);
    return *this;
}

template <typename Type>
template <typename TypeIn>
decltype(auto) Vector<Type>::operator^(const Vector<TypeIn> &vector) const
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
template <typename TypeIn>
Type Vector<Type>::operator&(const Vector<TypeIn> &vector) const
{
    return this->scalMulVec(vector);
}

template <typename Type>
template <typename TypeIn>
Type Vector<Type>::scalMulVec(const Vector<TypeIn> &vector) const
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

#endif