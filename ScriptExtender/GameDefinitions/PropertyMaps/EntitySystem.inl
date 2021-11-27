BEGIN_CLS(BaseComponent)
P_RO(EntityObjectHandle)
END_CLS()


BEGIN_CLS(IGameObject)
P_REF(Base)
P_RO(MyGuid)
P_RO(NetID)

P_FUN(IsTagged, LuaIsTagged)
P_FUN(HasTag, LuaIsTagged)
P_FUN(GetTags, LuaGetTags)
END_CLS()

BEGIN_CLS(IEoCServerObject)
INHERIT(IGameObject)
P_FUN(GetStatus, LuaGetStatus)
P_FUN(GetStatusByType, LuaGetStatusByType)
P_FUN(GetStatuses, LuaGetStatusIds)
P_FUN(GetStatusObjects, LuaGetStatuses)
END_CLS()

BEGIN_CLS(IEoCClientObject)
INHERIT(IGameObject)
P_FUN(GetStatus, LuaGetStatus)
P_FUN(GetStatusByType, LuaGetStatusByType)
P_FUN(GetStatuses, LuaGetStatusIds)
P_FUN(GetStatusObjects, LuaGetStatuses)
END_CLS()
