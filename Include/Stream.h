#pragma once
#include "Types.h"
#include <string>

namespace SBin {
	class SBIN_API Stream {
	public:
		inline Stream() 
			: m_file(nullptr) {
		}
		inline Stream(const Path& file, OpenMode mode)
			: m_file(nullptr) {
			Open(file, mode);
		}
		virtual inline ~Stream() {
			if(IsOpen())
				Close();
		}

		virtual void Open(const Path& file, OpenMode mode);
		virtual void Close();

		virtual void SetPosition(int32_t offset, Origin origin = Origin::Start);
		virtual size_t GetPosition() const;
		virtual size_t GetSize();

		virtual size_t WriteBytes(const void* data, size_t size);
		virtual size_t ReadBytes(void* destination, size_t size) const;

		template<class T>
		inline size_t Write(const T& data, size_t size = sizeof(T)) {
			return WriteBytes((const void*)&data, size);
		}

		template<class T>
		inline size_t Read(T& t, size_t size = sizeof(T)) const {
			return ReadBytes((void*)&t, size);
		}

		inline bool IsOpen() const { return m_file != nullptr; }

	protected:
		FILE* m_file;

		static std::string OpenModeToCFlags(OpenMode mode);
	};
}