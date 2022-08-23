BEGIN_CLS(ecl::Scenery)
INHERIT(IEoCClientObject)
P_GETTER_SETTER(Flags, LuaGetFlags, LuaSetFlags)
P_BITMASK_GETTER_SETTER(Flags, LuaHasFlag, LuaSetFlag)
P_RO(LevelName)
P_RO(GUID)
P(CoverAmount)
P_REF(Physics)
P_REF(SoundParams)
P_REF(FadeParams)
P_REF(Template)
P(VisualResourceID)
P(DefaultState)
P(RenderChannel)
P(IsBlocker)
P(RenderFlags)
P_BITMASK(RenderFlags)
END_CLS()


BEGIN_CLS(ecl::Scenery::SoundSettings)
P(SoundAttenuation)
P(SoundInitEvent)
P(LoopSound)
END_CLS()


BEGIN_CLS(ecl::Scenery::FadeSettings)
P(FadeIn)
P(Opacity)
P(FadeGroup)
END_CLS()
