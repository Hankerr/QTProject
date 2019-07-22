#ifndef SLD_H
#define SLD_H

#include "sld_global.h"
#include <QString>

class SLDSHARED_EXPORT Sld
{

public:
    Sld();
    QString GetStr();
};

extern "C" SLDSHARED_EXPORT Q_DECL_EXPORT int add(int i,int j); //外部函数定义，必须加上extern声明

#endif // SLD_H
