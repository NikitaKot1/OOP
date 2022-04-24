#ifndef ConstIteratorV_HPP
#define ConstIteratorV_HPP

#include <memory>

#include "exceptions.hpp"
//#include "vector.hpp"

template <typename Type>
class Vector;

template <typename Type>
class ConstIteratorV: public std::iterator<std::random_access_iterator_tag, int>
{
    public:
        ConstIteratorV(const ConstIteratorV<Type> &iterator);
        ConstIteratorV(const Vector<Type> &vector);

        ~ConstIteratorV() = default;

        const Type &operator*() const;
        const Type *operator->() const;
        operator bool() const;

        ConstIteratorV<Type> &operator=(const ConstIteratorV<Type> &iterator);

        ConstIteratorV<Type> &operator-=(size_t number);
        ConstIteratorV<Type> operator-(size_t number);
        ConstIteratorV<Type> &operator--();
        ConstIteratorV<Type> operator--(int);

        ConstIteratorV<Type> &operator+=(size_t number);
        ConstIteratorV<Type> operator+(size_t number);
        ConstIteratorV<Type> &operator++();
        ConstIteratorV<Type> operator++(int);

        bool operator==(const ConstIteratorV<Type> &iter) const;
        bool operator!=(const ConstIteratorV<Type> &iter) const;
        bool operator<=(const ConstIteratorV<Type> &iter) const;
        bool operator>=(const ConstIteratorV<Type> &iter) const;
        bool operator<(const ConstIteratorV<Type> &iter) const;
        bool operator>(const ConstIteratorV<Type> &iter) const;
    
        const Type &operator[](const size_t index) const;

    private:
        std::weak_ptr<Type[]> wptr;
    
    protected:
        Type *getPointer() const;
        void exceptionCheck(int currentLine) const;
        void belongingCheck(int currentLine) const;
        size_t curIndex = 0;
        size_t vectorSize = 0;
};

#include "constIteratorRealisation.hpp"

#endif
