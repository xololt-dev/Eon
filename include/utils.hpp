#pragma once

#include <type_traits>

namespace eon {
	// https://stackoverflow.com/questions/8357240/how-to-automatically-convert-strongly-typed-enum-into-int
	template <typename E>
	constexpr auto to_underlying(E a_e) noexcept {
		return static_cast<std::underlying_type_t<E>>(a_e);
	}
}