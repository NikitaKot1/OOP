#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>

#include "exceptions.hpp"
#include "vector.hpp"

template <typename Type>
class Vector;

template <typename Type>
class Iterator: public std::iterator<std::random_access_iterator_tag, int>
{
    public:
        Iterator(const Iterator<Type> &iterator);
        Iterator(const Vector<Type> &vector);

        ~Iterator() = default;

        Type &operator*();
        Type *operator->();
        operator bool() const;

        Iterator<Type> &operator=(const Iterator<Type> &iterator);

        Iterator<Type> &operator-=(size_t number);
        Iterator<Type> operator-(size_t number);
        Iterator<Type> &operator--();
        Iterator<Type> operator--(int);

        Iterator<Type> &operator+=(size_t number);
        Iterator<Type> operator+(size_t number);
        Iterator<Type> &operator++();
        Iterator<Type> operator++(int);

        bool operator==(const Iterator<Type> &iter) const;
        bool operator!=(const Iterator<Type> &iter) const;
        bool operator<=(const Iterator<Type> &iter) const;
        bool operator>=(const Iterator<Type> &iter) const;
        bool operator<(const Iterator<Type> &iter) const;
        bool operator>(const Iterator<Type> &iter) const;
    
    private:
        std::weak_ptr<Type[]> wptr;
    
    protected:
        Type *getPointer() const;
        void exceptionCheck(int currentLine);
        void belongingCheck(int currentLine);
        size_t curIndex = 0;
        size_t vectorSize = 0;
};

#endif