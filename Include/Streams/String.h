#pragma once

#include "Types.h"
#include "Stream.h"

#include "Streams/Primitiv.h"

namespace SBin {
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, const std::string& value) {
#ifdef SBIN_SHORTER_VECTOR_N_STRING_LENGTH
		stream << (uint32_t)value.size();
#else
		stream << value.size();
#endif
		stream->WriteBytes(&value[0], value.length() * sizeof(char));
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, const std::wstring& value) {
#ifdef SBIN_SHORTER_VECTOR_N_STRING_LENGTH
		stream << (uint32_t)value.size();
#else
		stream << value.size();
#endif
		stream->WriteBytes(&value[0], value.length() * sizeof(wchar_t));
		return stream;
	}

	inline Ref<Stream>& operator>>(Ref<Stream>& stream, std::string& value) {
#ifdef SBIN_SHORTER_VECTOR_N_STRING_LENGTH
		uint32_t len;
		stream >> len;
#else
		size_t len;
		stream >> len;
#endif
		value.resize(len);
		stream->ReadBytes(&value[0], len * sizeof(char));
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, std::wstring& value) {
#ifdef SBIN_SHORTER_VECTOR_N_STRING_LENGTH
		uint32_t len;
		stream >> len;
#else
		size_t len;
		stream >> len;
#endif
		value.resize(len);
		stream->ReadBytes(&value[0], len * sizeof(wchar_t));
		return stream;
	}
	
}