#pragma once

#include "Types.h"
#include "Stream.h"

#include "Streams/Primitiv.h"
#include <vector>

namespace SBin {
#ifndef SBIN_NO_VECTOR
	template<class T>
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, const std::vector<T>& vector) {
#ifdef SBIN_SHORTER_VECTOR_N_STRING_LENGTH
		stream << (uint32_t)vector.size();
#else
		stream << vector.size();
#endif
		for (size_t i = 0; i < vector.size(); i++) {
			stream <<  vector[i];
		}
		return stream;
	}

	template<class T>
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, std::vector<T>& vector) {
#ifdef SBIN_SHORTER_VECTOR_N_STRING_LENGTH
		uint32_t len;
		stream >> len;
#else
		size_t len;
		stream >> len;
#endif
		vector.resize(len);
		for (size_t i = 0; i < len; i++) {
			stream >> vector[i];
		}
		return stream;
	}
#endif
}