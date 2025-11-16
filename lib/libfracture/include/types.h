#ifndef FRACTURE_TYPES_H
#define FRACTURE_TYPES_H

// Basic type definitions for FractureOS
// Use compiler built-in types to avoid conflicts

#ifdef __cplusplus
extern "C" {
#endif

// Use compiler built-in types
typedef __INT8_TYPE__ int8_t;
typedef __UINT8_TYPE__ uint8_t;
typedef __INT16_TYPE__ int16_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __INT32_TYPE__ int32_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __INT64_TYPE__ int64_t;
typedef __UINT64_TYPE__ uint64_t;

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __INTPTR_TYPE__ intptr_t;
typedef __UINTPTR_TYPE__ uintptr_t;

// ssize_t is not a built-in
#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
typedef __INTPTR_TYPE__ ssize_t;
#endif

// NULL definition
#ifndef NULL
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL ((void*)0)
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif // FRACTURE_TYPES_H
