#pragma once
#include <memory>
#include <filesystem>

#include "Config.h"

namespace SBin {
	template<class T>
	using Ref = std::shared_ptr<T>;

	template<class T, class ...Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	using Path = std::filesystem::path;

	enum class Origin {
		Start,
		Current,
		End
	};

	enum class OpenMode : uint32_t {
		Read = 1 << 0,
		Write = 1 << 1,
		Append = 1 << 2,
		Binary = 1 << 3,
		Text = 1 << 4,
	};
	inline OpenMode operator|(OpenMode a, OpenMode b)
	{
		return static_cast<OpenMode>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
	}
	inline OpenMode operator&(OpenMode a, OpenMode b)
	{
		return static_cast<OpenMode>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
	}
	inline bool CheckFlag(OpenMode value, OpenMode flag) { return (value & flag) == flag; }
}