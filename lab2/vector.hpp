#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include "vectorRoot.hpp"

template<typename Type>
class Vector: public VectorRoot
{
    private:
        std::shared_ptr<Type[]> projections;
    
    public:
        Vector();
        Vector(const std::initializer_list<Type> &listForm);
        explicit Vector(size_t size);
        explicit Vector(size_t size, const Type *arrayPtr);
        explicit Vector(size_t size, const Type el);
        explicit Vector(const Vector<Type> &vector);
        //rvalue?

        virtual ~Vector() = default;

        bool isZeroVector() const;
        bool isSingleVector() const;

        template <typename TypeOut> // выходной тип
        TypeOut lenght() const;

        double angle(const Vector<Type> &vector) const;
        bool parallel(const Vector<Type> &vector) const;
        bool perpendicular(const Vector<Type> &vector) const;

        Type &at(size_t pos);
        Type &operator[](size_t pos);

        Vector<Type> &operator=(const Vector<Type> &vector);
        Vector<Type> &operator=(const std::initializer_list<Type> &listForm);

        //сумма векторов и вектора с числом
        Vector<Type> &operator+=(const Vector<Type> &vector);
        Vector<Type> &operator+=(const Type &el);
        void sumEq(const Vector<Type> &vector);
        void sumEq(const Type &el);
        Vector<Type> &operator+(const Vector<Type> &vector);
        Vector<Type> &operator+(const Type &el);
        Vector<Type> &sumVec(const Vector<Type> &vector);
        Vector<Type> &sumEl(const Type &el);

        //разница векторов и вектора с числом
        Vector<Type> &operator-=(const Vector<Type> &vector);
        Vector<Type> &operator-=(const Type &el);
        void difEq(const Vector<Type> &vector);
        void difEq(const Type &el);
        Vector<Type> &operator-(const Vector<Type> &vector);
        Vector<Type> &operator-(const Type &el);
        Vector<Type> &difVec(const Vector<Type> &vector);
        Vector<Type> &difEl(const Type &el);

        //векторное произведение
        Vector<Type> &operator*=(const Vector<Type> &vector);
        void vecMulEq(const Vector<Type> &vector);
        Vector<Type> &operator*(const Vector<Type> &vector);
        Vector<Type> &vecMulVec(const Vector<Type> &vector);

        //произведение вектора на число
        Vector<Type> &operator*=(const Type &el);
        void vecMulEq(const Type &el);
        Vector<Type> &operator*(const Type &el);
        Vector<Type> &vecMulEl(const Type &el);

        //скалярное произведение
        Vector<Type> &operator&=(const Vector<Type> &vector);
        void scalMulEq(const Vector<Type> &vector);
        Vector<Type> &operator&(const Vector<Type> &vector);
        Vector<Type> &scalMulVec(const Vector<Type> &vector);

        //косое произведение
        Vector<Type> &operator:=(const Vector<Type> &vector);
        void skewMulEq(const Vector<Type> &vector);
        Vector<Type> &operator:(const Vector<Type> &vector);
        Vector<Type> &skewMulVec(const Vector<Type> &vector);

        //деление вектора на вектор (поэлементно) и на число
        Vector<Type> &operator/=(const Vector<Type> &vector);
        Vector<Type> &operator/=(const Type &el);
        void divEq(const Vector<Type> &vector);
        void divEq(const Type &el);
        Vector<Type> &operator/(const Vector<Type> &vector);
        Vector<Type> &operator/(const Type &el);
        Vector<Type> &divVec(const Vector<Type> &vector);
        Vector<Type> &divEl(const Type &el);

        //уножение на -1
        Vector<Type> &operator-();
        Vector<Type> negative();

        bool operator==(const Vector<Type> &vector) const;
        bool isEqual(const Vector<Type> &vector) const;
        bool operator!=(const Vector<Type> &vector) const;
        bool isNotEqual(const Vector<Type> &vector) const;

    protected:
        void allocMemForVector(size_t size);
};

#endif