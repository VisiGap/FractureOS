#ifndef FRACTURE_TYPES_H
#define FRACTURE_TYPES_H

// Basic type definitions for FractureOS

// Integer types
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

// Size types
typedef unsigned long long size_t;
typedef long long ssize_t;
typedef long long ptrdiff_t;

// Pointer types
typedef unsigned long long uintptr_t;
typedef long long intptr_t;

// Boolean
typedef bool bool_t;

// NULL definition
#ifndef NULL
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL ((void*)0)
#endif
#endif

#endif // FRACTURE_TYPES_H
