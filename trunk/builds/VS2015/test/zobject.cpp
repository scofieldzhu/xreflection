#include "zobject.h"

BASE_ROBJ_IMPL(ZObject)

bool ZObject::IsKindOf(const MetaInfoCls* other_cls_meta_info) const
{
    MetaInfoCls* my_cls_meta_info = GetClsMetaInfo();
    while (my_cls_meta_info != 0)
    {        
        if (my_cls_meta_info == other_cls_meta_info)
            return true;
        my_cls_meta_info = my_cls_meta_info->base_cls_meta_info;
    }
    return false;
}

ZObject::ZObject()
{
}

ZObject::~ZObject()
{
}
