#ifndef __TEACHER_H__
#define __TEACHER_H__

#include "person.h"

class Teacher : public Person
{
    ZOBJ_DECL(Teacher)
public:
    Teacher();
    ~Teacher();
};

#endif
