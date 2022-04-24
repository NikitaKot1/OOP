#ifndef IteratorVREALISATION_H
#define IteratorVREALISATION_H

#include "iterator.hpp"
#include "vector.hpp"

template <typename Type>
void IteratorV<Type>::exceptionCheck(int currentLine) const
{
    if (wptr.expired())
    {
        time_t curTime = time(NULL);
        throw DeletedObjectException(__FILE__, typeid(*this).name(), currentLine, ctime(&curTime));
    }
}

template <typename Type>
void IteratorV<Type>::belongingCheck(int currentLine) const
{
    if (this->curIndex >= this->vectorSize)
    {
        time_t curTime = time(NULL);
        throw InvalidIteratorException(__FILE__, typeid(*this).name(), currentLine, ctime(&curTime));
    }
}

template <typename Type>
Type *IteratorV<Type>::getPointer() const
{
    std::shared_ptr<Type[]> copyptr = this->wptr.lock();
    return copyptr.get() + curIndex;
}

template <typename Type>
IteratorV<Type>::IteratorV(const IteratorV<Type> &iter)
{
    this->wptr = iter.wptr;
    this->curIndex = iter.curIndex;
    this->vectorSize = iter.vectorSize;
}

template <typename Type>
IteratorV<Type>::IteratorV(const Vector<Type> &vector)
{
    this->wptr = vector.projections;
    this->curIndex = 0;
    this->vectorSize = vector.size();
}

template <typename Type>
Type &IteratorV<Type>::operator*()
{
    exceptionCheck(__LINE__);
    belongingCheck(__LINE__);
    return *getPointer();
}

template <typename Type>
Type *IteratorV<Type>::operator->()
{
    exceptionCheck(__LINE__);
    belongingCheck(__LINE__);
    return getPointer();
}

template <typename Type>
IteratorV<Type>::operator bool() const
{
    this->exceptionCheck(__LINE__);
    return this->curIndex < this->vectorSize && this->vectorSize != 0;
}

template <typename Type>
IteratorV<Type> &IteratorV<Type>::operator=(const IteratorV<Type> &iter)
{
    this->wptr = iter->wptr;
    return *this;
}

template <typename Type>
IteratorV<Type> &IteratorV<Type>::operator+=(size_t number)
{
    exceptionCheck(__LINE__);
    this->curIndex += number;
    return *this;
}

template <typename Type>
IteratorV<Type> IteratorV<Type>::operator+(size_t number)
{
    exceptionCheck(__LINE__);
    (*this) += number;
    return *this;
}

template <typename Type>
IteratorV<Type> &IteratorV<Type>::operator++()
{
    exceptionCheck(__LINE__);
    (this->curIndex)++;
    return *this;
}

template <typename Type>
IteratorV<Type> IteratorV<Type>::operator++(int)
{
    exceptionCheck(__LINE__);
    (this->curIndex)++;
    return *this;
}

template <typename Type>
IteratorV<Type> &IteratorV<Type>::operator-=(size_t number)
{
    exceptionCheck(__LINE__);
    this->curIndex -= number;
    return *this;
}

template <typename Type>
IteratorV<Type> IteratorV<Type>::operator-(size_t number)
{
    exceptionCheck(__LINE__);
    (*this) -= number;
    return *this;
}

template <typename Type>
IteratorV<Type> &IteratorV<Type>::operator--()
{
    exceptionCheck(__LINE__);
    (this->curIndex)--;
    return *this;
}

template <typename Type>
IteratorV<Type> IteratorV<Type>::operator--(int)
{
    exceptionCheck(__LINE__);
    (this->curIndex)--;
    return *this;
}

template <typename Type>
bool IteratorV<Type>::operator==(const IteratorV<Type> &iter) const
{
    exceptionCheck(__LINE__);
    return this->curIndex == iter.curIndex;
}

template <typename Type>
bool IteratorV<Type>::operator!=(const IteratorV<Type> &iter) const
{
    exceptionCheck(__LINE__);
    return this->curIndex != iter.curIndex;
}

template <typename Type>
bool IteratorV<Type>::operator<=(const IteratorV<Type> &iter) const
{
    exceptionCheck(__LINE__);
    return this->curIndex <= iter.curIndex;
}

template <typename Type>
bool IteratorV<Type>::operator>=(const IteratorV<Type> &iter) const
{
    exceptionCheck(__LINE__);
    return this->curIndex >= iter.curIndex;
}

template <typename Type>
bool IteratorV<Type>::operator<(const IteratorV<Type> &iter) const
{
    exceptionCheck(__LINE__);
    return this->curIndex < iter.curIndex;
}

template <typename Type>
bool IteratorV<Type>::operator>(const IteratorV<Type> &iter) const
{
    exceptionCheck(__LINE__);
    return this->curIndex > iter.curIndex;
}

template <typename Type>
Type &IteratorV<Type>::operator[](const size_t index)
{
    exceptionCheck(__LINE__);
    if (index + this->curIndex >= this->vectorSize)
    {
        time_t curTime = time(NULL);
        throw InvalidIteratorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return *(this + index);
}

template <typename Type>
const Type &IteratorV<Type>::operator[](const size_t index) const
{
    exceptionCheck(__LINE__);
    if (index + this->curIndex >= this->vectorSize)
    {
        time_t curTime = time(NULL);
        throw InvalidIteratorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return *(this + index);
}

#endif
