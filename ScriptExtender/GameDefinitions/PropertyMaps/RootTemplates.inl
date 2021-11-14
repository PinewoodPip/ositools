BEGIN_CLS(GameObjectTemplate)
// TODO Tags
P_RO(Flags)
P_RO(Flag)
#if defined(OSI_EOCAPP)
P_RO(Type)
#endif
P_REF(Tags)
P_RO(HasAnyTags)
P_RO(Id)
P_RO(Name)
P_RO(TemplateName)
P_RO(IsGlobal)
P_RO(IsDeleted)
P_RO(LevelName)
P_RO(ModFolder)
P_RO(GroupID)
P_REF(Transform)
P_RO(NonUniformScale)
P(VisualTemplate)
P(PhysicsTemplate)
P(CastShadow)
P(ReceiveDecal)
P(AllowReceiveDecalWhenAnimated)
P(IsReflecting)
P(IsShadowProxy)
P(RenderChannel)
P(CameraOffset)
P_RO(HasParentModRelation)
// TODO - ContainingLevelTemplate
P(HasGameplayValue)
P_RO(FileName)
END_CLS()


BEGIN_CLS(EoCGameObjectTemplate)
INHERIT(GameObjectTemplate)
P(AIBoundsMin)
P(AIBoundsMax)
P(AIBoundsRadius)
P(AIBoundsHeight)
P(AIBoundsAIType)
P(DisplayName)
P(Opacity)
P(Fadeable)
P(FadeIn)
P(SeeThrough)
P(FadeGroup)
P(GameMasterSpawnSection)
P(GameMasterSpawnSubSection)
END_CLS()


BEGIN_CLS(CharacterTemplate)
INHERIT(EoCGameObjectTemplate)
P_REF(CombatComponent)
P(Icon)
P(Stats)
P(SkillSet)
P(Equipment)
P_REF(Treasures)
P_REF(TradeTreasures)
P(LightID)
P(HitFX)
P(DefaultDialog)
P(SpeakerGroup)
P(GeneratePortrait)
P(WalkSpeed)
P(RunSpeed)
P(ClimbAttachSpeed)
P(ClimbLoopSpeed)
P(ClimbDetachSpeed)
P(CanShootThrough)
P(WalkThrough)
P(CanClimbLadders)
P(IsPlayer)
P(Floating)
P(SpotSneakers)
P(CanOpenDoors)
P(AvoidTraps)
P(InfluenceTreasureLevel)
P(HardcoreOnly)
P(NotHardcore)
P(JumpUpLadders)
P(NoRotate)
P(IsHuge)
P(EquipmentClass)
// TODO - OnDeathActions
P(BloodSurfaceType)
P(ExplodedResourceID)
P(ExplosionFX)
// TODO - Scripts, SkillList, ItemList
P(VisualSetResourceID)
P(VisualSetIndices)
P(TrophyID)
P(SoundInitEvent)
P(SoundAttachBone)
P(SoundAttenuation)
P(CoverAmount)
P(LevelOverride)
P(ForceUnsheathSkills)
P(CanBeTeleported)
P(ActivationGroupId)
P_REF(PickingPhysicsTemplates)
P(SoftBodyCollisionTemplate)
P(RagdollTemplate)
// TODO - FootStepInfos
P(DefaultState)
P(GhostTemplate)
P(IsLootable)
P(IsEquipmentLootable)
P(InventoryType)
P(IsArenaChampion)
P(FootstepWeight)
P_RO(EmptyVisualSet)
// TODO - VisualSetObject
END_CLS()


BEGIN_CLS(ItemTemplate)
INHERIT(EoCGameObjectTemplate)
P_REF(CombatComponent)
P(Icon)
P(CanBePickedUp)
P(CanBeMoved)
P(CoverAmount)
P(CanShootThrough)
P(CanClickThrough)
P(Destroyed)
P(WalkThrough)
P(WalkOn)
P(Wadable)
P(IsInteractionDisabled)
P(IsPinnedContainer)
P_REF(PinnedContainerTags)
P(StoryItem)
P(FreezeGravity)
P(IsKey)
P(IsTrap)
P(IsSurfaceBlocker)
P(IsSurfaceCloudBlocker)
P(TreasureOnDestroy)
P(IsHuge)
P(HardcoreOnly)
P(NotHardcore)
P(UsePartyLevelForTreasureLevel)
P(Unimportant)
P(Hostile)
P(UseOnDistance)
P(UseRemotely)
P(IsBlocker)
P(IsPointerBlocker)
P(UnknownDisplayName)
P(Tooltip)
P(Stats)
P_REF(Treasures)
// TODO - OnUsePeaceActions .. ItemList
P(OnUseDescription)
P(DefaultState)
P(Owner)
P(Key)
P(HitFX)
P(LockLevel)
P(Amount)
P(MaxStackAmount)
P(TreasureLevel)
// TODO - Equipment?
P(DropSound)
P(PickupSound)
P(UseSound)
P(EquipSound)
P(UnequipSound)
P(InventoryMoveSound)
P(LoopSound)
P(SoundInitEvent)
P(SoundAttachBone)
P(SoundAttenuation)
P(BloodSurfaceType)
P(Description)
P(UnknownDescription)
P(Speaker)
P(AltSpeaker)
P(SpeakerGroup)
P(ActivationGroupId)
P(Race)
P(IsWall)
P(LevelOverride)
P(Floating)
P(IsSourceContainer)
P(MeshProxy)
P(IsPublicDomain)
P(AllowSummonTeleport)
END_CLS()


BEGIN_CLS(ProjectileTemplate)
INHERIT(EoCGameObjectTemplate)
P(LifeTime)
P(Speed)
P(Acceleration)
P(CastBone)
P(ImpactFX)
P(TrailFX)
P(DestroyTrailFXOnImpact)
P(BeamFX)
P(PreviewPathMaterial)
P(PreviewPathImpactFX)
P(PreviewPathRadius)
P(ImpactFXSize)
P(RotateImpact)
P(IgnoreRoof)
P(DetachBeam)
P(NeedsArrowImpactSFX)
P(ProjectilePath)
P(PathShift)
P(PathRadius)
P(PathMinArcDist)
P(PathMaxArcDist)
P(PathRepeat)
END_CLS()


BEGIN_CLS(CombatComponentTemplate)
P(Alignment)
P(CanFight)
P(CanJoinCombat)
P(CombatGroupID)
P(IsBoss)
P(IsInspector)
P(StartCombatRange)
END_CLS()


BEGIN_CLS(SurfaceTemplate::VisualData)
P(Visual)
P(Height)
P(Rotation)
P(Scale)
P(GridSize)
P(SpawnCell)
P(RandomPlacement)
P(SurfaceNeeded)
P(SurfaceRadiusMax)
END_CLS()


BEGIN_CLS(SurfaceTemplate::StatusData)
P(StatusId)
P(Chance)
P(Duration)
P(RemoveStatus)
P(OnlyWhileMoving)
P(ApplyToCharacters)
P(ApplyToItems)
P(KeepAlive)
P(VanishOnReapply)
P(ForceStatus)
END_CLS()


BEGIN_CLS(SurfaceTemplate)
INHERIT(GameObjectTemplate)
P_RO(SurfaceTypeId)
P_RO(SurfaceType)
P(DisplayName)
P(Description)
P(DecalMaterial)
P(CanEnterCombat)
P(AlwaysUseDefaultLifeTime)
P(DefaultLifeTime)
P(SurfaceGrowTimer)
P(FadeInSpeed)
P(FadeOutSpeed)
P(Seed)
P_REF(InstanceVisual)
P_REF(IntroFX)
P_REF(FX)
P_REF(Statuses)
P(DamageWeapon)
P(Summon)
P(DamageCharacters)
P(DamageItems)
P(DamageTorches)
P(RemoveDestroyedItems)
P(CanSeeThrough)
P(CanShootThrough)
END_CLS()


BEGIN_CLS(TriggerTemplate)
INHERIT(GameObjectTemplate)
P(TriggerType)
P(PhysicsType)
P(Color4)
P(TriggerGizmoOverride)
END_CLS()
