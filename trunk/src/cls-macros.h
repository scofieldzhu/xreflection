#ifndef __CLS_MACROS_H__
#define __CLS_MACROS_H__

#define BASE_ROBJ_DECL(RCls) \
    public:\
        typedef RCls RClsType; \
        typedef ClsMetaInfo<RClsType> MetaInfoCls; \
        typedef ClsInitializer<RClsType> ClsInitializerType; \
    __META_CLS_DECL(RCls)

#define BASE_ROBJ_IMPL(RCls) __META_CLS_IMPL(RCls, 0, 0, 0)

#define CLS_META_INFO(ThisCls) (&ThisCls::meta_##ThisCls)     

#define ROBJ_DECL(ThisCls) \
    __META_CLS_DECL(ThisCls) \
    static RClsType* CreateObject();
#define ROBJ_IMPL(ThisCls, BaseCls) \
    typedef ThisCls::RClsType RClsType; \
    RClsType* ThisCls::CreateObject(){ return new ThisCls; } \
    __META_CLS_IMPL(ThisCls, CLS_META_INFO(BaseCls), ThisCls::CreateObject, 0)

#define __META_CLS_DECL(ThisCls) \
    public:\
        static MetaInfoCls meta_##ThisCls; \
        virtual MetaInfoCls* GetClsMetaInfo()const;         

#define __META_CLS_IMPL(ThisCls, BaseMetaInfo, CreateMethod, NextMetaInfo) \
    typedef ThisCls::MetaInfoCls MetaInfoCls; \
    static char __class_name__[] = #ThisCls; \
    MetaInfoCls ThisCls::meta_##ThisCls = { __class_name__, sizeof(ThisCls), BaseMetaInfo, CreateMethod, NextMetaInfo}; \
    static ThisCls::ClsInitializerType __initilizer_(&ThisCls::meta_##ThisCls); \
    MetaInfoCls* ThisCls::GetClsMetaInfo()const { return &ThisCls::meta_##ThisCls; } 

#endif
