#ifndef __ZOBJECT_H__
#define __ZOBJECT_H__

#include "cls-meta-info.hpp"
#include "cls-macros.h"

class ZObject
{
    BASE_ROBJ_DECL(ZObject)
public:    
    bool IsKindOf(const MetaInfoCls* cls_meta_info)const;
    ZObject();
    virtual ~ZObject();
};

#define ZOBJ_DECL ROBJ_DECL
#define ZOBJ_IMPL ROBJ_IMPL

#endif