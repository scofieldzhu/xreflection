#ifndef __CLS_META_INFO_H__
#define __CLS_META_INFO_H__

#include <cstring>

template <class RObject>
struct ClsMetaInfo
{
    const char* clsname;
    int object_size;
    ClsMetaInfo* base_cls_meta_info;
    RObject* (*create_object_func)();
    ClsMetaInfo* next_cls_meta_info;
    static ClsMetaInfo* st_head_cls_meta_info;
    RObject* CreateObject() 
    {
        if (create_object_func == 0)
            return 0;
        return (*create_object_func)();
    }
    static ClsMetaInfo* Load(const char* cls_name)
    {
        ClsMetaInfo* cur_cls_meta_info = ClsMetaInfo::st_head_cls_meta_info;
        for (; cur_cls_meta_info != 0; cur_cls_meta_info = cur_cls_meta_info->next_cls_meta_info)
        {
            if (strcmp(cur_cls_meta_info->clsname, cls_name) == 0)
                return cur_cls_meta_info;
        }
        return 0;
    }
};
template <class RObject>
ClsMetaInfo<RObject>* ClsMetaInfo<RObject>::st_head_cls_meta_info = 0;

template <class RObject>
struct ClsInitializer
{
    typedef ClsMetaInfo<RObject> MyClsMetaInfo;
    ClsInitializer(MyClsMetaInfo* cls_meta_info)
    {
        cls_meta_info->next_cls_meta_info = MyClsMetaInfo::st_head_cls_meta_info;
        MyClsMetaInfo::st_head_cls_meta_info = cls_meta_info;
    }
};

#endif
