#ifndef __PERSON_H__
#define __PERSON_H__

#include "zobject.h"

class Person : public ZObject
{
    ZOBJ_DECL(Person)
public:
    Person();
    virtual ~Person();
};

#endif

