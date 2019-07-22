#ifndef MYDLL_H
#define MYDLL_H

#include "mydll_global.h"

#if defined(MYDLL_LIBRARY)
#  define MYDLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MYDLLSHARED_EXPORT Q_DECL_IMPORT
#endif

class MYDLLSHARED_EXPORT MyDll
{

public:
    MyDll();
    int add(int a,int b);
};

#endif // MYDLL_H
