#ifndef VECTORROOT_HPP
#define VECTORROOT_HPP

#include <cstddef>

class VectorRoot
{
    protected:
        size_t size = 0;

    public:
        VectorRoot(size_t size = 0): size(size) {}
        virtual size_t size() const {return size;};
        virtual operator bool() const {return bool(size);};
        virtual ~VectorRoot() = 0;
    
};

VectorRoot::~VectorRoot() {}

#endif