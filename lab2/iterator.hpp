#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

#include "exceptions.hpp"
//#include "vector.hpp"

template <typename Type>
class Vector;

template <typename Type>
class IteratorV: public std::iterator<std::random_access_iterator_tag, int>
{
    public:
        IteratorV(const IteratorV<Type> &iterator);
        IteratorV(const Vector<Type> &vector);

        ~IteratorV() = default;

        Type &operator*();
        Type *operator->();
        const Type &operator*() const;
        const Type *operator->() const;
        operator bool() const;

        IteratorV<Type> &operator=(const IteratorV<Type> &iterator);

        IteratorV<Type> &operator-=(size_t number);
        IteratorV<Type> operator-(size_t number);
        IteratorV<Type> &operator--();
        IteratorV<Type> operator--(int);

        IteratorV<Type> &operator+=(size_t number);
        IteratorV<Type> operator+(size_t number);
        IteratorV<Type> &operator++();
        IteratorV<Type> operator++(int);

        bool operator==(const IteratorV<Type> &iter) const;
        bool operator!=(const IteratorV<Type> &iter) const;
        bool operator<=(const IteratorV<Type> &iter) const;
        bool operator>=(const IteratorV<Type> &iter) const;
        bool operator<(const IteratorV<Type> &iter) const;
        bool operator>(const IteratorV<Type> &iter) const;
    
    private:
        std::weak_ptr<Type[]> wptr;
    
    protected:
        Type *getPointer() const;
        void exceptionCheck(int currentLine) const;
        void belongingCheck(int currentLine) const;
        size_t curIndex = 0;
        size_t vectorSize = 0;
};

#include "iteratorRealisation.hpp"

#endif
