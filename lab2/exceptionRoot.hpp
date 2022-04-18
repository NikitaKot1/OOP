#ifndef EXCEPTIONROOT_HPP
#define EXCEPTIONROOT_HPP

#include <exception>
#include <string>
using namespace std;


class VectorsException: public exception
{
    public:
        VectorsException(string fileName, string className, int curLine, 
                         const char *errTime, string information);
        virtual const char *what() const noexcept override;

        virtual ~VectorsException() {}
    
    protected:
        string exceptInformation;
};

#include "exceptionRealisation.hpp"

#endif