#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <initializer_list>

#include "vectorRoot.hpp"
#include "constIterator.hpp"
#include "iterator.hpp"


template<typename Type>
class Vector: public VectorRoot
{
    public:
        friend class IteratorV<Type>;
        friend class ConstIteratorV<Type>;

        Vector();
        explicit Vector(size_t size);
        Vector(size_t size, const Type *arrayPtr);
        Vector(size_t size, const Type el);
        Vector(const std::initializer_list<Type> &listForm);
        explicit Vector(const Vector<Type> &vector);

        virtual ~Vector() = default;

        IteratorV<Type> begin();
        IteratorV<Type> end();
        ConstIteratorV<Type> begin() const;
        ConstIteratorV<Type> end() const;
        ConstIteratorV<Type> cBegin() const;
        ConstIteratorV<Type> cEnd() const;

        template <typename TypeOut> // выходной тип
        TypeOut lenght() const;

        bool isZeroVector() const;
        bool isSingleVector() const;

        double angle(const Vector<Type> &vector) const;
        bool parallel(const Vector<Type> &vector) const;
        bool perpendicular(const Vector<Type> &vector) const;

        Type &at(size_t pos);
        Type &operator[](size_t pos);
        const Type &at(size_t pos) const;
        const Type &operator[](size_t pos) const;

        Vector<Type> &operator=(const Vector<Type> &vector);
        Vector<Type> &operator=(const std::initializer_list<Type> &listForm);

        //сумма векторов и вектора с числом
        Vector<Type> &operator+=(const Vector<Type> &vector);
        Vector<Type> &operator+=(const Type &el);
        void sumEq(const Vector<Type> &vector);
        void sumEq(const Type &el);
        Vector<Type> operator+(const Vector<Type> &vector) const;
        Vector<Type> operator+(const Type &el) const;
        Vector<Type> sumVec(const Vector<Type> &vector) const;
        Vector<Type> sumEl(const Type &el) const;

        //разница векторов и вектора с числом
        Vector<Type> &operator-=(const Vector<Type> &vector);
        Vector<Type> &operator-=(const Type &el);
        void difEq(const Vector<Type> &vector);
        void difEq(const Type &el);
        Vector<Type> operator-(const Vector<Type> &vector) const;
        Vector<Type> operator-(const Type &el) const;
        Vector<Type> difVec(const Vector<Type> &vector) const;
        Vector<Type> difEl(const Type &el) const;

        //векторное произведение
        Vector<Type> &operator*=(const Vector<Type> &vector);
        void vecMulEq(const Vector<Type> &vector);
        Vector<Type> operator*(const Vector<Type> &vector) const;
        Vector<Type> vecMulVec(const Vector<Type> &vector) const;

        //произведение вектора на число
        Vector<Type> &operator*=(const Type &el);
        void vecMulEq(const Type &el);
        Vector<Type> operator*(const Type &el) const;
        Vector<Type> vecMulEl(const Type &el) const;

        //скалярное произведение
        Type operator&(const Vector<Type> &vector) const;
        Type scalMulVec(const Vector<Type> &vector) const;

        //косое произведение
        Vector<Type> &operator^=(const Vector<Type> &vector);
        void skewMulEq(const Vector<Type> &vector);
        Vector<Type> operator^(const Vector<Type> &vector) const;
        Vector<Type> skewMulVec(const Vector<Type> &vector) const;

        //деление вектора на вектор (поэлементно) и на число
        Vector<Type> &operator/=(const Vector<Type> &vector);
        Vector<Type> &operator/=(const Type &el);
        void divEq(const Vector<Type> &vector);
        void divEq(const Type &el);
        Vector<Type> operator/(const Vector<Type> &vector) const;
        Vector<Type> operator/(const Type &el) const;
        Vector<Type> diVec(const Vector<Type> &vector) const;
        Vector<Type> divEl(const Type &el) const;

        //уножение на -1
        Vector<Type> &operator-();
        Vector<Type> negative();

        bool operator==(const Vector<Type> &vector) const;
        bool isEqual(const Vector<Type> &vector) const;
        bool operator!=(const Vector<Type> &vector) const;
        bool isNotEqual(const Vector<Type> &vector) const;

    protected:
        void allocMemForVector(size_t size);
        void checkSizes(const Vector<Type> &vector, int curLine) const;
        void checkSizesForMul(const Vector<Type> &vector, int curLine) const;

    private:
        std::shared_ptr<Type[]> projections;
};

#include "vectorRealisation.hpp"

#endif
