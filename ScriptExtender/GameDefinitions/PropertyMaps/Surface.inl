BEGIN_CLS(esv::Surface)
P_RO(NetID)
P_RO(MyHandle)
P_RO(SurfaceType)
P_RO(Flags)
P_RO(TeamId)
P_RO(OwnerHandle)
P(LifeTime)
P_RO(LifeTimeFromTemplate)
P(StatusChance)
P_RO(Index)
P_RO(NeedsSplitEvaluation)
P_RO(OwnershipTimer)

#if defined(GENERATING_TYPE_INFO)
ADD_TYPE("RootTemplate", SurfaceTemplate)
#endif

#if defined(GENERATING_PROPMAP)
pm.AddProperty("RootTemplate",
	[](lua_State* L, LifetimeHandle const& lifetime, esv::Surface* obj, std::size_t offset, uint64_t flag) {
		MakeObjectRef(L, GetStaticSymbols().GetSurfaceTemplate(obj->SurfaceType));
		return PropertyOperationResult::Success;
	}
);
#endif
END_CLS()

BEGIN_CLS(esv::SurfaceCell)
P(Position)
END_CLS()

BEGIN_CLS(esv::SurfaceAction)
P_RO(MyHandle)
END_CLS()


BEGIN_CLS(esv::CreateSurfaceActionBase)
INHERIT(esv::SurfaceAction)
P(OwnerHandle)
P(Duration)
P(StatusChance)
P(Position)
P(SurfaceType)
P_REF(SurfaceHandlesByType)
END_CLS()


BEGIN_CLS(esv::CreateSurfaceAction)
INHERIT(esv::CreateSurfaceActionBase)
P(Radius)
P(ExcludeRadius)
P(MaxHeight)
P(IgnoreIrreplacableSurfaces)
P(CheckExistingSurfaces)
P(SurfaceCollisionFlags)
P(SurfaceCollisionNotOnFlags)
P(Timer)
P(GrowTimer)
P(GrowStep)
P(CurrentCellCount)
P_REF(SurfaceCells)
P(SurfaceLayer)
END_CLS()


BEGIN_CLS(esv::ChangeSurfaceOnPathAction)
INHERIT(esv::CreateSurfaceActionBase)
P(FollowObject)
P(Radius)
P_RO(IsFinished)
P(IgnoreIrreplacableSurfaces)
P(CheckExistingSurfaces)
P(SurfaceCollisionFlags)
P(SurfaceCollisionNotOnFlags)
P(IgnoreOwnerCells)
END_CLS()


BEGIN_CLS(esv::CreatePuddleAction)
INHERIT(esv::CreateSurfaceActionBase)
P(SurfaceCells)
P(Step)
P(GrowSpeed)
P_RO(IsFinished)
P(IgnoreIrreplacableSurfaces)
P_REF(CellAtGrow)
P_REF(ClosedCells)
P(GrowTimer)
END_CLS()


BEGIN_CLS(esv::ExtinguishFireAction)
INHERIT(esv::CreateSurfaceActionBase)
P(ExtinguishPosition)
P(Radius)
P(Percentage)
P(GrowTimer)
P(Step)
END_CLS()


BEGIN_CLS(esv::RectangleSurfaceAction)
INHERIT(esv::CreateSurfaceActionBase)
P(Target)
P(SurfaceArea)
P(Width)
P(Length)
P(GrowTimer)
P(MaxHeight)
P(GrowStep)
P(AiFlags)
P_REF(DamageList)
P(DeathType)
P(LineCheckBlock)
P_REF(SkillProperties)
P(CurrentGrowTimer)
P_REF(SurfaceCells)
P_REF(Characters)
P_REF(Items)
P(CurrentCellCount)
END_CLS()


BEGIN_CLS(esv::PolygonSurfaceAction)
INHERIT(esv::CreateSurfaceActionBase)
P_REF(PolygonVertices)
P_REF(DamageList)
P(CurrentGrowTimer)
P(GrowTimer)
P(PositionX)
P(PositionZ)
P(GrowStep)
P(LastSurfaceCellCount)
P_REF(SurfaceCells)
P_REF(Characters)
P_REF(Items)
END_CLS()


BEGIN_CLS(esv::SwapSurfaceAction)
INHERIT(esv::CreateSurfaceActionBase)
P(Radius)
P(ExcludeRadius)
P(MaxHeight)
P(Target)
P(IgnoreIrreplacableSurfaces)
P(CheckExistingSurfaces)
P(SurfaceCollisionFlags)
P(SurfaceCollisionNotOnFlags)
P(LineCheckBlock)
P(Timer)
P(GrowTimer)
P(GrowStep)
P(CurrentCellCount)
P_REF(SurfaceCells)
P_REF(TargetCells)
P_REF(SurfaceCellMap)
P_REF(TargetCellMap)
END_CLS()


BEGIN_CLS(esv::ZoneAction)
INHERIT(esv::CreateSurfaceActionBase)
P(SkillId)
P(Target)
P(Shape)
P(Radius)
P(AngleOrBase)
P(BackStart)
P(FrontOffset)
P(MaxHeight)
P(GrowTimer)
P(GrowStep)
P(AiFlags)
P_REF(DamageList)
P(DeathType)
P_REF(SkillProperties)
P(GrowTimerStart)
P_REF(SurfaceCells)
P_REF(Characters)
P_REF(Items)
P(CurrentCellCount)
P(IsFromItem)
END_CLS()


BEGIN_CLS(esv::TransformSurfaceAction)
INHERIT(esv::SurfaceAction)
P(Timer)
P(SurfaceTransformAction)
P(OriginSurface)
P(SurfaceLayer)
P(GrowCellPerSecond)
P_RO(Finished)
P(OwnerHandle)
P(Position)
P(SurfaceLifetime)
P(SurfaceStatusChance)
P_REF(SurfaceMap)
P_REF(SurfaceCellMap)
P_REF(SurfaceRemoveGroundCellMap)
P_REF(SurfaceRemoveCloudCellMap)
END_CLS()
