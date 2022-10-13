
BEGIN_CLS(UIObject)
P_RO(Path)
P_RO(IsDragging)
P_RO(ChildUIHandle)
P_RO(ParentUIHandle)
P(Layer)
P(RenderOrder)
P(MovieLayout)
P(FlashSize)
P(FlashMovieSize)
P(SysPanelPosition)
P(SysPanelSize)
P(Left)
P(Top)
P(Right)
P(MinSize)
P(UIScale)
P(CustomScale)
P(AnchorObjectName)
P(AnchorId)
P(AnchorTarget)
P(AnchorPos)
P(AnchorTPos)
P(UIScaling)
P_RO(IsUIMoving)
P_RO(IsDragging2)
P_RO(IsMoving2)
P_RO(RenderDataPrepared)
P_RO(InputFocused)
P(HasAnchorPos)
P_RO(UIObjectHandle)
P_RO(Type)
P(PlayerId)

P_GETTER_SETTER(Flags, LuaGetFlags, LuaSetFlags)
P_BITMASK_GETTER_SETTER(Flags, LuaHasFlag, LuaSetFlag)

P_FUN(GetPosition, LuaGetPosition)
P_FUN(SetPosition, LuaSetPosition)
P_FUN(Resize, SetMovieClipSize)
P_FUN(Show, LuaShow)
P_FUN(Hide, LuaHide)
P_FUN(Invoke, LuaInvoke)
P_FUN(GotoFrame, LuaGotoFrame)
P_FUN(GetValue, GetValue)
P_FUN(SetValue, SetValue)
P_FUN(GetHandle, LuaGetHandle)
P_FUN(GetPlayerHandle, LuaGetPlayerHandle)
P_FUN(GetTypeId, GetTypeId)
P_FUN(GetRoot, LuaGetRoot)
P_FUN(Destroy, LuaDestroy)
P_FUN(ExternalInterfaceCall, LuaExternalInterfaceCall)
P_FUN(CaptureExternalInterfaceCalls, CaptureExternalInterfaceCalls)
P_FUN(CaptureInvokes, CaptureInvokes)
P_FUN(EnableCustomDraw, EnableCustomDraw)
P_FUN(SetCustomIcon, SetCustomIcon)
P_FUN(ClearCustomIcon, ClearCustomIcon)
P_FUN(GetUIScaleMultiplier, GetUIScaleMultiplier)
END_CLS()


BEGIN_CLS(ecl::EoCUI)
INHERIT(UIObject)
END_CLS()


BEGIN_CLS(DragDropManager::PlayerDragInfo)
P_RO(DragObject)
// P_RO(DragEgg)
P_RO(DragId)
P_RO(MousePos)
P_RO(IsDragging)
P_RO(IsActive)
END_CLS()


BEGIN_CLS(DragDropManager)
P_REF(PlayerDragDrops)

P_FUN(StopDragging, StopDragging)
P_FUN(StartDraggingName, StartDraggingName)
P_FUN(StartDraggingObject, StartDraggingObject)
END_CLS()
