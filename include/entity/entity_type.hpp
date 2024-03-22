#pragma once

#include <string>

namespace eon {
	namespace entity {
		enum class EntityType {
			Null,
			Player,
			Computer,
			DynamicAudio,
			Dynamic,
			StaticAudio,
			Static,
			Other
		};

		static std::string getEntityTypeString(EntityType a_type) {
			switch (a_type) {
				case EntityType::Null:
					return "Null";
				case EntityType::Player:
					return "Player";
				case EntityType::Computer:
					return "Computer";
				case EntityType::DynamicAudio:
					return "DynamicAudio";
				case EntityType::Dynamic:
					return "Dynamic";
				case EntityType::StaticAudio:
					return "StaticAudio";
				case EntityType::Static:
					return "Static";
				case EntityType::Other:
					return "Other";
			}
		}
    }
}
