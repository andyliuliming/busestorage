#ifndef abs_exception_hh
#define abs_exception_hh
#include <exception>
using namespace std;
class ABSException : public exception
{
    const char *what() const throw()
    {
        return "ABS++ Exception";
    }
};

#endif