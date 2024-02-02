#pragma once

#include "Types.h"
#include "Stream.h"

#include "Streams/Primitiv.h"
#include <array>

namespace SBin {
#ifndef SBIN_NO_ARRAY
	template<class T, size_t L>
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, const std::array<T, L>& array) {
		for (size_t i = 0; i < L; i++) {
			stream << array[i];
		}
		return stream;
	}

	template<class T, size_t L>
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, std::array<T, L>& array) {
		for (size_t i = 0; i < L; i++) {
			stream >> array[i];
		}
		return stream;
	}
#endif
}