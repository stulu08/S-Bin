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
	char _cstr[10];
};
inline Ref<Stream>& operator<<(Ref<Stream>& stream, const TestData& data) {
	stream << data.str << data.list << data.arr << data._float << data._int << data._bool << data._cstr;
	return stream;
}
inline Ref<Stream>& operator>>(Ref<Stream>& stream, TestData& data) {
	stream >> data.str >> data.list >> data.arr >> data._float >> data._int >> data._bool >> data._cstr;
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
	strcpy(data._cstr, "abcdefghi");
	data._cstr[9] = '\0';

	auto writeStream = file->OpenWrite();
	writeStream << data;
}

TestData Load(const Ref<File>& file) {
	auto readStream = file->OpenRead();
	TestData data;
	readStream >> data;
	return data;
}

int main() {
	auto file = File::CreateBinary("test.bin");
	
	Save(file);
	TestData data = Load(file);

	return 0;
}