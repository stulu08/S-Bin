#include <Stream.h>
#include <File.h>

#include <iostream>

using namespace SBin;

struct TestData {
	std::string str;
	std::vector<std::string> list;
	std::array<int, 2> arr;
	float _float;
	uint32_t _int;
	bool _bool;
};
inline Ref<Stream>& operator<<(Ref<Stream>& stream, const TestData& data) {
	stream << data.str << data.list << data.arr << data._float << data._int << data._bool;
	return stream;
}
inline Ref<Stream>& operator>>(Ref<Stream>& stream, TestData& data) {
	stream >> data.str >> data.list >> data.arr >> data._float >> data._int >> data._bool;
	return stream;
}

void Save(const Ref<File>& file) {
	TestData data;
	data.str = "Test";
	data.list = {
		"ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZ"
	};
	data.arr = { 5, 9 };
	data._float = 123;
	data._int = 764;
	data._bool = true;

	Ref<Stream> writeStream = file->OpenWrite();
	writeStream << data;
}

TestData Load(const Ref<File>& file) {
	Ref<Stream> readStream = file->OpenRead();
	TestData data;
	readStream >> data;
	return data;
}

int main() {
	Ref<File> file = CreateRef<BinaryFile>("test.bin");
	
	// with 32 bit sizes 91 bytes with 64 bit 135, while yaml takes up around 190 bytes in comparison
	Save(file);
	TestData data = Load(file);

	return 0;
}