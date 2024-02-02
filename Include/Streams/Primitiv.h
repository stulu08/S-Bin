#pragma once

#include "Types.h"
#include "Stream.h"

namespace SBin {
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, unsigned char value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, unsigned short value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, unsigned int value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, unsigned long long value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, char value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, short value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, int value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, long long value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, float value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, double value) {
		stream->Write(value);
		return stream;
	}

	inline Ref<Stream>& operator<<(Ref<Stream>& stream, bool value) {
		stream->Write(value);
		return stream;
	}
	inline Ref<Stream>& operator<<(Ref<Stream>& stream, wchar_t value) {
		stream->Write(value);
		return stream;
	}


	inline Ref<Stream>& operator>>(Ref<Stream>& stream, unsigned char& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, unsigned short& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, unsigned int& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, unsigned long long& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, char& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, short& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, int& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, long long& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, float& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, double& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, bool& value) {
		stream->Read(value);
		return stream;
	}
	inline Ref<Stream>& operator>>(Ref<Stream>& stream, wchar_t& value) {
		stream->Read(value);
		return stream;
	}
}