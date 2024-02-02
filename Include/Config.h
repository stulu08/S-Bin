#pragma once

// disbale saveing and loading implementation for std::vector<T>
//#define SBIN_NO_VECTOR

// disbale saveing and loading implementation for std::array<T,L>
//#define SBIN_NO_ARRAY

// save size_t as a uint32_t for vector's and string's
//#define SBIN_SHORTER_VECTOR_N_STRING_LENGTH

#ifdef _WIN32
	#ifdef SBIN_DLL
		#ifdef SBIN_EXPORT
			#define SBIN_API __declspec(dllexport)
		#else
			#define SBIN_API __declspec(dllimport)
		#endif
	#else
		#define SBIN_API
	#endif
#else
	#define SBIN_API
#endif