#include "pch.h"
#include "Stream.h"

namespace SBin {
    std::string Stream::OpenModeToCFlags(OpenMode mode) {
        std::string flagStr;
        flagStr.reserve(3);

        if (CheckFlag(mode, OpenMode::Append)) {
            flagStr.push_back('a');
        }
        else if (CheckFlag(mode, OpenMode::Write)) {
            flagStr.push_back('w');
        }
        else if (CheckFlag(mode, OpenMode::Read)) {
            flagStr.push_back('r');
        }else {
            std::cerr << "SBin: Error invalid OpenMode: " << std::hex << (uint32_t)mode << std::endl;
            return "";
        }

        if (CheckFlag(mode, OpenMode::Binary)) {
            flagStr.push_back('b');
        }
        else if (CheckFlag(mode, OpenMode::Text)) {
            flagStr.push_back('t');
        }

        if (CheckFlag(mode, OpenMode::Append) && flagStr[0] != 'a') {
            flagStr.push_back('+');
        }
        if (CheckFlag(mode, OpenMode::Write) && flagStr[0] != 'w') {
            flagStr.push_back('+');
        }
        if (CheckFlag(mode, OpenMode::Read) && flagStr[0] != 'r') {
            flagStr.push_back('+');
        }

        flagStr.shrink_to_fit();

        
        return flagStr;
    }

    void Stream::Open(const Path& file, OpenMode mode) {
        if (IsOpen()) {
            std::cerr << "SBin: Error stream already open for file: " << file << std::endl;
            return;
        }

        std::string flags = OpenModeToCFlags(mode);
        m_file = fopen(file.string().c_str(), flags.c_str());
        if (!IsOpen()) {
            std::cerr << "SBin: Error could not open stream for file: " << file << std::endl;
            return;
        }
    }
    void Stream::Close() {
        if (!IsOpen()) {
            std::cerr << "SBin: Error cant close a stream which does not exist" << std::endl;
            return;
        }
        if (fclose(m_file) == 0) {
            m_file = nullptr;
            return;
        }

        std::cerr << "SBin: Stream could not be closed" << std::endl;

    }
    void Stream::SetPosition(int32_t pos, Origin originEnum) {
        if (!IsOpen()) {
            std::cerr << "SBin: Error cant offset a stream which does not exist" << std::endl;
            return;
        }

        int origin = 0;
        switch (originEnum)
        {
        case SBin::Origin::Start:
            origin = SEEK_SET;
            break;
        case SBin::Origin::Current:
            origin = SEEK_CUR;
            break;
        case SBin::Origin::End:
            origin = SEEK_END;
            break;
        }

        if (fseek(m_file, (long)pos, origin) == 0) {
            return;
        }
        std::cerr << "SBin: Stream position could not be set" << std::endl;
    }

    size_t Stream::GetPosition() const {
        if (!IsOpen()) {
            std::cerr << "SBin: Error cant get the position of a stream which does not exist" << std::endl;
            return 0;
        }
        return ftell(m_file);
    }
    size_t Stream::GetSize() {
        if (!IsOpen()) {
            std::cerr << "SBin: Error cant get the size of a stream which does not exist" << std::endl;
            return 0;
        }

        size_t pos = GetPosition();
        
        fseek(m_file, 0, SEEK_END);
        int size = ftell(m_file);

        SetPosition((int32_t)pos, Origin::Start);

        return size;
    }

    size_t Stream::WriteBytes(const void* data, size_t size) {
        if (!IsOpen()) {
            std::cerr << "SBin: Error cant write to a stream which does not exist" << std::endl;
            return 0;
        }
        return fwrite(data, size, 1, m_file);
    }
    size_t Stream::ReadBytes(void* destination, size_t size) const {
        if (!IsOpen()) {
            std::cerr << "SBin: Error cant read from a stream which does not exist" << std::endl;
            return 0;
        }
        return fread(destination, size, 1, m_file);
    }
}