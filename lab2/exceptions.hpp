#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include "exceptionRoot.hpp"

class MemoryException: public VectorsException
{
    public:
        MemoryException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Memory error"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class DeletedObjectException: public VectorsException
{
    public:
        MemoryException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Object was deleted"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class InvalidIteratorException: public VectorsException
{
    public:
        MemoryException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Iterator outside the borders"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

#endif