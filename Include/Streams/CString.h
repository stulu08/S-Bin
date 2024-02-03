#pragma once

#include "Types.h"
#include "Stream.h"

#include "Streams/Primitiv.h"
#include "Streams/String.h"

namespace SBin {
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, const char* value) {
		stream << std::string(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, const wchar_t* value) {
		stream << std::wstring(value);
		return stream;
	}

	inline Ref<Stream>& operator>>(Ref<Stream>& stream, char* value) {
		std::string str;
		stream >> str;
		str.push_back('\0');
		memcpy(value, &str[0], str.length() * sizeof(char));
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, wchar_t* value) {
		std::wstring str;
		stream >> str;
		str.push_back(L'\0');
		memcpy(value, &str[0], str.length() * sizeof(wchar_t));
		return stream;
	}
	
}