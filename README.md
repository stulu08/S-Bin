# S-Bin [![License](https://img.shields.io/github/license/Stulu08/S-Bin.svg)](https://github.com/Stulu08/S-Bin/blob/master/LICENSE)

Simple binary saving and loading

***

## Usage

### Writing Data
```c++
#include <Stream.h>
#include <File.h>

int main() {
	using namespace SBin;
	
	Ref<File> file = CreateRef<BinaryFile>("test.bin");

	Ref<Stream> writeStream = file->OpenWrite();
	std::vector<std::string> data = { "Test","Test2" };
	writeStream << data << 123 << 4385.0f << true;

	return 0;
}
```

### Saving Data
```c++
#include <Stream.h>
#include <File.h>

int main() {
	using namespace SBin;
	
	Ref<File> file = CreateRef<BinaryFile>("test.bin");

	std::vector<std::string> vectorData;
	int intData;
	float floatData;
	bool boolData;
	
	Ref<Stream> readStream = file->OpenRead();
	readStream >> vectorData >> intData >> floatData >> boolData;

	return 0;
}
```

### Overloading own Types

```c++
#include <Stream.h>
#include <File.h>

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
```

### Full example

```c++
#include <Stream.h>
#include <File.h>

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
	
	Save(file);
	TestData data = Load(file);

	return 0;
}
```

## Config
```c++
// disbale saveing and loading implementation for std::vector<T>
//#define SBIN_NO_VECTOR

// disbale saveing and loading implementation for std::array<T,L>
//#define SBIN_NO_ARRAY

// save size_t as a uint32_t for vector's and string's
//#define SBIN_SHORTER_VECTOR_N_STRING_LENGTH
´´´ 


#### Copyright © 2022 Julian Bents