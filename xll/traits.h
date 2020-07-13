// traits.h - parameterized by XLOPER type
// Copyright (c) KALX, LLC. All rights reserved. No warranty made.

#pragma once
#include <Windows.h>
#include "XLCALL.H"
#include "ensure.h"

#pragma warning(push)
#pragma warning(disable: 4996)

namespace xll {

	// XLOPER/XLOPER12 traits
	template<class X>
	struct traits {
	};
	template<>
	struct traits<XLOPER> {
		typedef CHAR xchar;
		typedef const CHAR* xcstr;
		typedef WORD xrw;
		typedef BYTE xcol;
		typedef short int xint;
		static int Excelv(int xlfn, LPXLOPER operRes, int count, LPXLOPER opers[])
		{
			return ::Excel4v(xlfn, operRes, count, opers);
		}
		static size_t len(const xchar* s)
		{
			return strlen(s);
		}
		static xchar* cpy(xchar* dest, const xchar* src, size_t n)
		{
			return strncpy(dest, src, n);
		}
		static int cmp(const xchar* dest, const xchar* src, size_t n)
		{
			return strncmp(dest, src, n);
		}
	};
	template<>
	struct traits<XLOPER12> {
		typedef XCHAR xchar;
		typedef const XCHAR* xcstr;
		typedef int xint;
		typedef RW xrw;
		typedef COL xcol;
		static int Excelv(int xlfn, LPXLOPER12 operRes, int count, LPXLOPER12 opers[])
		{
			return ::Excel12v(xlfn, operRes, count, opers);
		}
		static size_t len(const xchar* s)
		{
			return wcslen(s);
		}
		static xchar* cpy(xchar* dest, const xchar* src, size_t n)
		{
			return wcsncpy(dest, src, n);
		}
		static int cmp(const xchar* dest, const xchar* src, size_t n)
		{
			return wcsncmp(dest, src, n);
		}
	};

}

#pragma warning(pop)