#include <iostream>
#include "teacher.h"
using namespace std;

class Test : public ZObject
{
    ZOBJ_DECL(Test)    
};

ZOBJ_IMPL(Test, ZObject)

int main()
{       
    ZObject* new_t = ClsMetaInfo<ZObject>::Load("Test")->CreateObject();    
    cout << new_t->GetClsMetaInfo()->clsname << endl;
    new_t = ClsMetaInfo<ZObject>::Load("Person")->CreateObject();
    cout << new_t->GetClsMetaInfo()->clsname << endl;
    new_t = ClsMetaInfo<ZObject>::Load("Teacher")->CreateObject();
    cout << new_t->GetClsMetaInfo()->clsname << endl;
    new_t = ClsMetaInfo<ZObject>::Load("ZObject")->CreateObject();
    cout << new_t->GetClsMetaInfo()->clsname << endl;
    return 0;
}