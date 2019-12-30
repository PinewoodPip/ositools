#include <stdafx.h>
#include "FunctionLibrary.h"
#include <OsirisProxy.h>

namespace osidbg
{
	namespace func
	{
		bool StatExists(OsiArgumentDesc & args)
		{
			auto statName = args[0].String;
			
			auto stats = gOsirisProxy->GetLibraryManager().GetStats();
			if (stats == nullptr) {
				return false;
			}

			auto object = stats->objects.Find(statName);
			return object != nullptr;
		}

		bool StatAttributeExists(OsiArgumentDesc & args)
		{
			auto statName = args[0].String;
			auto attributeName = args[1].String;

			auto stats = gOsirisProxy->GetLibraryManager().GetStats();
			if (stats == nullptr) {
				return false;
			}

			auto object = stats->objects.Find(statName);
			if (object == nullptr) {
				return false;
			}

			int attributeIndex;
			auto attrInfo = stats->GetAttributeInfo(object, attributeName, attributeIndex);
			return attrInfo != nullptr;
		}

		bool StatGetInt(OsiArgumentDesc & args)
		{
			auto statName = args[0].String;
			auto attributeName = args[1].String;

			auto stats = gOsirisProxy->GetLibraryManager().GetStats();
			if (stats == nullptr) {
				return false;
			}

			auto object = stats->objects.Find(statName);
			if (object == nullptr) {
				OsiError("Stat object '" << statName << "' does not exist");
				return false;
			}

			auto value = stats->GetAttributeInt(object, attributeName);
			if (!value) {
				OsiError("Attribute '" << attributeName << "' not found on object '" << statName << "'");
				return false;
			}

			args[2].Int32 = *value;
			return true;
		}

		bool StatGetString(OsiArgumentDesc & args)
		{
			auto statName = args[0].String;
			auto attributeName = args[1].String;

			auto stats = gOsirisProxy->GetLibraryManager().GetStats();
			if (stats == nullptr) {
				return false;
			}

			auto object = stats->objects.Find(statName);
			if (object == nullptr) {
				OsiError("Stat object '" << statName << "' does not exist");
				return false;
			}

			auto value = stats->GetAttributeFixedString(object, attributeName);
			if (!value) {
				OsiError("Attribute '" << attributeName << "' not found on object '" << statName << "'");
				return false;
			}

			args[2].String = value->Str;
			return true;
		}

		bool StatGetType(OsiArgumentDesc & args)
		{
			auto statsId = args[0].String;

			auto stats = gOsirisProxy->GetLibraryManager().GetStats();
			if (stats == nullptr) {
				return false;
			}

			auto object = stats->objects.Find(statsId);
			if (object == nullptr) {
				OsiError("Stat object '" << statsId << "' does not exist");
				return false;
			}

			auto typeInfo = stats->GetTypeInfo(object);
			if (typeInfo == nullptr) {
				return false;
			}

			args[1].String = typeInfo->Name.Str;
			return true;
		}

		bool StatGetExtraData(OsiArgumentDesc & args)
		{
			auto key = args[0].String;
			auto & value = args[1].Float;

			auto stats = gOsirisProxy->GetLibraryManager().GetStats();
			if (stats == nullptr || stats->ExtraData == nullptr) {
				OsiError("RPGStats not available");
				return false;
			}

			auto extraData = stats->ExtraData->Properties.Find(key);
			if (extraData != nullptr) {
				value = *extraData;
				return true;
			} else {
				return false;
			}
		}
	}

	void CustomFunctionLibrary::RegisterStatFunctions()
	{
		auto & functionMgr = osiris_.GetCustomFunctionManager();

		auto statExists = std::make_unique<CustomQuery>(
			"NRD_StatExists",
			std::vector<CustomFunctionParam>{
				{ "StatsId", ValueType::String, FunctionArgumentDirection::In }
			},
			&func::StatExists
		);
		functionMgr.Register(std::move(statExists));

		auto statAttributeExists = std::make_unique<CustomQuery>(
			"NRD_StatAttributeExists",
			std::vector<CustomFunctionParam>{
				{ "StatsId", ValueType::String, FunctionArgumentDirection::In },
				{ "Attribute", ValueType::String, FunctionArgumentDirection::In },
			},
			&func::StatAttributeExists
		);
		functionMgr.Register(std::move(statAttributeExists));

		auto getStatInt = std::make_unique<CustomQuery>(
			"NRD_StatGetInt",
			std::vector<CustomFunctionParam>{
				{ "StatsId", ValueType::String, FunctionArgumentDirection::In },
				{ "Attribute", ValueType::String, FunctionArgumentDirection::In },
				{ "Value", ValueType::Integer, FunctionArgumentDirection::Out },
			},
			&func::StatGetInt
		);
		functionMgr.Register(std::move(getStatInt));

		auto getStatString = std::make_unique<CustomQuery>(
			"NRD_StatGetString",
			std::vector<CustomFunctionParam>{
				{ "StatsId", ValueType::String, FunctionArgumentDirection::In },
				{ "Attribute", ValueType::String, FunctionArgumentDirection::In },
				{ "Value", ValueType::String, FunctionArgumentDirection::Out },
			},
			&func::StatGetString
		);
		functionMgr.Register(std::move(getStatString));

		auto getStatType = std::make_unique<CustomQuery>(
			"NRD_StatGetType",
			std::vector<CustomFunctionParam>{
				{ "StatsId", ValueType::String, FunctionArgumentDirection::In },
				{ "Type", ValueType::String, FunctionArgumentDirection::Out },
			},
			&func::StatGetType
		);
		functionMgr.Register(std::move(getStatType));

		auto getExtraData = std::make_unique<CustomQuery>(
			"NRD_StatGetExtraData",
			std::vector<CustomFunctionParam>{
				{ "Key", ValueType::String, FunctionArgumentDirection::In },
				{ "Value", ValueType::Real, FunctionArgumentDirection::Out },
			},
			&func::StatGetExtraData
		);
		functionMgr.Register(std::move(getExtraData));
	}

}
