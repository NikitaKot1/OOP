#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

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
        DeletedObjectException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Object was deleted"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class InvalidIteratorException: public VectorsException
{
    public:
        InvalidIteratorException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Iterator outside the borders"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class EmptyVectorExcpretion: public VectorsException
{
    public:
        EmptyVectorExcpretion(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Vector can't be empty"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class InvalidArrayPointerException: public VectorsException
{
    public:
        InvalidArrayPointerException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Array's pointer can't be empty"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class ZeroDivisionException: public VectorsException
{
    public:
        ZeroDivisionException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Division by zero"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class IndexOutOfRangeException: public VectorsException
{
    public:
        IndexOutOfRangeException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Index out of range"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class NotSameRangeException: public VectorsException
{
    public:
        NotSameRangeException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Vectors have not the same range"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

class NotSuitableRangeForMulException: public VectorsException
{
    public:
        NotSuitableRangeForMulException(string fileName, string className, int curLine, 
                        const char *errTime, string information = "Vectors have not the same range (they must be 3)"):
                        VectorsException(fileName, className, curLine, errTime, information){};
        virtual const char *what() const noexcept {return exceptInformation.c_str();}
};

#endif