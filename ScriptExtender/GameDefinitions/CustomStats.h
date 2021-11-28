#pragma once

#include <GameDefinitions/Base/Base.h>
#include <GameDefinitions/Enumerations.h>
#include <GameDefinitions/Net.h>

namespace dse
{

	namespace eocnet
	{
		struct DummyMessage : public net::Message
		{
			inline ~DummyMessage() override {}
			inline void Serialize(net::BitstreamSerializer & serializer) override {}
			inline void Unknown() override {}
			inline Message * CreateNew() override { return this; }
			inline void Reset() override {}
		};

		struct CustomStatDefinitionSyncInfo
		{
			NetId NetId{ NetIdUnassigned };
			uint64_t Unknown1{ 0 };
			FixedString Id;
			STDWString Name;
			STDWString Description;
		};

		struct CustomStatsDefinitionSyncMessage : public DummyMessage
		{
			ObjectSet<CustomStatDefinitionSyncInfo> StatDefns;
		};

		struct CustomStatsDefinitionRemoveMessage : public DummyMessage
		{
			void * PrimSetVMT;
			ObjectSet<uint32_t> StatDefns; // NetID list
			uint64_t Unkn{ 0 };
		};

		struct CustomStatsSyncInfo
		{
			NetId NetId{ NetIdUnassigned };
			Map<FixedString, int> Stats;
		};

		struct CustomStatsSyncMessage : public DummyMessage
		{
			ObjectSet<CustomStatsSyncInfo> Stats;
		};
	}

	namespace eoc
	{
		struct CustomStatsComponent : public BaseComponent
		{
			Map<FixedString, int> StatValues;
		};

		struct CustomStatDefinitionComponent : public ProtectedGameObject<CustomStatDefinitionComponent>
		{
			void * VMT;
			FixedString Id;
			STDWString Name;
			STDWString Description;
		};
	}

	namespace esv
	{
		struct NetComponent : public ProtectedGameObject<NetComponent>
		{
			BaseComponent Base;
			FixedString FixedStr1;
			NetId NetID;
		};

		struct CustomStatDefinitionComponent : public eoc::CustomStatDefinitionComponent
		{
			BaseComponent Base;
			FixedString someStr;
			NetId NetID;
			uint64_t Unkn1;
		};

		struct CustomStatSystem : public ProtectedGameObject<CustomStatSystem>
		{
			void * GameEventListenerVMT;
			void * Unkn1;
			void * NetEventListenerVMT;
			void * BaseComponentVMT;
			EntityWorld * EntityWorld;
			ObjectSet<ComponentHandleWithType> CreatedDefinitions;
			ObjectSet<ComponentHandleWithType> InSyncDefinitions;
			ObjectSet<ComponentHandleWithType> RemovedDefinitions;
			ObjectSet<ComponentHandleWithType> UpdatedDefinitions;
			ObjectSet<ComponentHandleWithType> CustomStatComponents;
			PrimitiveSet<short> PeerIDClassnames;
		};

		typedef int(*CustomStatsProtocol__ProcessMsg)(void * self, void * unkn, void * unkn2, net::Message * msg);

		
		class CustomStatHelpers
		{
		public:
			static std::optional<FixedString> CreateStat(char const* name, char const* description);
			static CustomStatDefinitionComponent* FindStatDefinitionByName(char const* name);
			static CustomStatDefinitionComponent* FindStatDefinitionById(char const* id);

			static void SyncCharacterStats(ComponentHandle entityHandle, eoc::CustomStatsComponent* stats,
				FixedString statKey, int statValue);
			static std::optional<int> GetCharacterStat(ComponentHandle entityHandle, char const* statId);
			static bool SetCharacterStat(ComponentHandle entityHandle, char const* statId, int value);

		private:
			static void ProcessMessage(net::Message* msg);
			static void CreateStatInternal(char const* name, char const* description);
		};
	}

	namespace ecl
	{
		class CustomStatHelpers
		{
		public:
			static std::optional<int> GetCharacterStat(ComponentHandle entityHandle, FixedString const& statId);
		};
	}
}
