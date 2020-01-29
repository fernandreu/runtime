// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

#ifndef _INTEROP_PLATFORM_H_
#define _INTEROP_PLATFORM_H_

#include <cassert>
#include <cstdint>
#include <cstring>

#ifndef _ASSERTE
#define _ASSERTE(x) assert((x))
#endif

#ifdef _WIN32
#include <Windows.h>

// Common macro for working in COM
#define RETURN_IF_FAILED(exp) { hr = exp; if (FAILED(hr)) { _ASSERTE(false && #exp); return hr; } }
#define RETURN_VOID_IF_FAILED(exp) { hr = exp; if (FAILED(hr)) { _ASSERTE(false && #exp); return; } }

#endif // _WIN32

#define ABI_ASSERT(abi_definition) static_assert((abi_definition), "ABI is being invalidated.")

// BEGIN [TODO] Remove
#include <cstdlib>
// END [TODO] Remove

#endif // _INTEROP_PLATFORM_H_