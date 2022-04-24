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
        Vector(size_t size, const Type &el);
        Vector(const std::initializer_list<Type> &listForm);
        template <typename TypeIn>
        explicit Vector(const Vector<TypeIn> &vector);
        Vector(Vector<Type> &&vector) noexcept;
        Vector(ConstIteratorV<Type> iter1, ConstIteratorV<Type> iter2);
        Vector(ConstIteratorV<Type> iter1, size_t size);

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

        void setEl(size_t pos, const Type &el);

        // действия с различными типами
        template <typename TypeIn>
        Vector<Type> &operator=(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        Vector<Type> &operator=(const std::initializer_list<TypeIn> &listForm);
        Vector<Type> &operator=(const Vector<Type> &&vector);

        //сумма векторов и вектора с числом
        template <typename TypeIn>
        Vector<Type> &operator+=(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        Vector<Type> &operator+=(const TypeIn &el);
        template <typename TypeIn>
        void sumEq(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        void sumEq(const TypeIn &el);
        template <typename TypeIn>
        decltype(auto) operator+(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) operator+(const TypeIn &el) const;
        template <typename TypeIn>
        decltype(auto) sumVec(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) sumEl(const TypeIn &el) const;

        //разница векторов и вектора с числом
        template <typename TypeIn>
        Vector<Type> &operator-=(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        Vector<Type> &operator-=(const TypeIn &el);
        template <typename TypeIn>
        void difEq(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        void difEq(const TypeIn &el);
        template <typename TypeIn>
        decltype(auto) operator-(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) operator-(const TypeIn &el) const;
        template <typename TypeIn>
        decltype(auto) difVec(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) difEl(const TypeIn &el) const;

        //векторное произведение
        template <typename TypeIn>
        Vector<Type> &operator*=(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        void vecMulEq(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        Vector<Type> operator*(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        Vector<Type> vecMulVec(const Vector<TypeIn> &vector) const;

        //произведение вектора на число
        template <typename TypeIn>
        Vector<Type> &operator*=(const TypeIn &el);
        template <typename TypeIn>
        void vecMulEq(const TypeIn &el);
        template <typename TypeIn>
        decltype(auto) operator*(const TypeIn &el) const;
        template <typename TypeIn>
        decltype(auto) vecMulEl(const TypeIn &el) const;

        //скалярное произведение
        template <typename TypeIn>
        Type operator&(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        Type scalMulVec(const Vector<TypeIn> &vector) const;

        //косое произведение
        template <typename TypeIn>
        Vector<Type> &operator^=(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        void skewMulEq(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        decltype(auto) operator^(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) skewMulVec(const Vector<TypeIn> &vector) const;

        //деление вектора на вектор (поэлементно) и на число
        template <typename TypeIn>
        Vector<Type> &operator/=(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        Vector<Type> &operator/=(const TypeIn &el);
        template <typename TypeIn>
        void divEq(const Vector<TypeIn> &vector);
        template <typename TypeIn>
        void divEq(const TypeIn &el);
        template <typename TypeIn>
        decltype(auto) operator/(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) operator/(const TypeIn &el) const;
        template <typename TypeIn>
        decltype(auto) diVec(const Vector<TypeIn> &vector) const;
        template <typename TypeIn>
        decltype(auto) divEl(const TypeIn &el) const;

        //уножение на -1
        Vector<Type> operator-();
        Vector<Type> negative();

        bool operator==(const Vector<Type> &vector) const;
        bool isEqual(const Vector<Type> &vector) const;
        bool operator!=(const Vector<Type> &vector) const;
        bool isNotEqual(const Vector<Type> &vector) const;

    protected:
        void allocMemForVector(size_t size);
        template <typename TypeIn>
        void checkSizes(const Vector<TypeIn> &vector, int curLine) const;
        template <typename TypeIn>
        void checkSizesForMul(const Vector<TypeIn> &vector, int curLine) const;

    private:
        std::shared_ptr<Type[]> projections;
};

#include "vectorRealisation.hpp"
#include "vectorRealiseForArifm.hpp"

#endif
