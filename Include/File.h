#pragma once

#include "Types.h"
#include "Stream.h"

#include "Streams/Primitiv.h"
#include "Streams/String.h"
#include "Streams/Vector.h"
#include "Streams/Array.h"
#include "Streams/Map.h"
#include "Streams/CString.h"


namespace SBin {
	enum class FileOpen {
		Read,
		Write,
		Append
	};

	class SBIN_API File {
	public:
		virtual ~File() = default;

		// if autoClose == true, new stream will close old one
		virtual Ref<Stream> Open(FileOpen mode, bool autoClose = true) = 0;
		inline Ref<Stream> OpenRead(bool autoClose = true) { return Open(FileOpen::Read, autoClose); };
		inline Ref<Stream> OpenWrite(bool autoClose = true) { return Open(FileOpen::Write, autoClose); };
		inline Ref<Stream> OpenAppend(bool autoClose = true) { return Open(FileOpen::Append, autoClose); };

		virtual void Close() = 0;

		virtual Path GetPath() const = 0;
		virtual Ref<Stream> GetStream() const = 0;

		inline static Ref<File> CreateBinary(const Path& file);
	};
	
	class SBIN_API BinaryFile : public File {
	public:
		BinaryFile(const Path& file);

		virtual ~BinaryFile();

		virtual Ref<Stream> Open(FileOpen mode, bool autoClose) override;
		virtual void Close() override;

		virtual Path GetPath() const override { return m_file; }
		virtual Ref<Stream> GetStream() const override { return m_stream; }
	protected:
		Path m_file;
		Ref<Stream> m_stream;
	};

	inline Ref<File> File::CreateBinary(const Path& file) {
		return CreateRef<BinaryFile>(file);
	}
}