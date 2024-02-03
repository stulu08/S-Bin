#include "pch.h"
#include "File.h"

namespace SBin {
    BinaryFile::BinaryFile(const Path& file)
        : m_file(file), m_stream(nullptr) {
        m_stream = CreateRef<Stream>();
    }
    BinaryFile::~BinaryFile() {
        m_stream.reset();
    }

    Ref<Stream> BinaryFile::Open(FileOpen mode, bool autoClose) {
        uint32_t fileMode = (uint32_t)OpenMode::Binary;

        switch (mode)
        {
        case FileOpen::Read:
            fileMode |= (uint32_t)OpenMode::Read;
            break;
        case FileOpen::Write:
            fileMode |= (uint32_t)OpenMode::Write;
            break;
        case FileOpen::Append:
            fileMode |= (uint32_t)OpenMode::Append;
            break;
        }
        if (m_stream->IsOpen() && autoClose)
            m_stream->Close();

        m_stream->Open(m_file, (OpenMode)fileMode);
        return m_stream;
    }
    void BinaryFile::Close() {
        if(m_stream->IsOpen())
            m_stream->Close();
    }
}