#ifndef VECTORREALISATION_HPP
#define VECTORREALISATION_HPP

#include <cmath>
#include <ctime>

#include "exceptions.hpp"
#include "vector.hpp"

template <typename Type>
void Vector<Type>::allocMemForVector(size_t size)
{
    time_t curTime = time(NULL);
    try
        this->projections.reset(new Type[size])
    catch(const std::exception& e)
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
}

template <typename Type>
Vector<Type>::Vector()
{
    this->size = 0;
    this->allocMemForVector(size);
}



#endif