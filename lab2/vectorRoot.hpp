#ifndef VECTORROOT_HPP
#define VECTORROOT_HPP

#include <cstddef>

class VectorRoot
{
    protected:
        size_t sizeV = 0;

    public:
        VectorRoot(size_t sizeV = 0): sizeV(sizeV) {}
        virtual size_t size() const {return sizeV;};
        virtual operator bool() const {return bool(sizeV);};
        virtual ~VectorRoot() = 0;
    
};

VectorRoot::~VectorRoot() {}

#endif