#include "../xll/xll.h"
using namespace xll;

#define ARGMAX 30

// ,LPXLOPERX, LPXLOPERX, ...
#define LPXLOPERX1 ,LPXLOPERX
#define LPXLOPERX2 LPXLOPERX1 LPXLOPERX1
#define LPXLOPERX4 LPXLOPERX2 LPXLOPERX2
#define LPXLOPERX8 LPXLOPERX4 LPXLOPERX4
#define LPXLOPERX16 LPXLOPERX8 LPXLOPERX8
#define LPXLOPERX32 LPXLOPERX16 LPXLOPERX16

namespace xll {

	// first missing arg determines length
	template<class X>
	inline unsigned len(X** ppa)
	{
		auto missing = [](X* pa) { return pa->xltype == xltypeMissing; };
		auto i = std::find_if(ppa, ppa + ARGMAX, missing);

		return i - ppa;
	}

	// 1.2, {"foo", "bar"}, true, ...
	// _1 = 1.2, foo = "bar", _2 = true, ...
	template<class X>
	inline unsigned SetNames(X** ppa)
	{
		//int j = 1;
		for (int i = 0, j = 1; i < ARGMAX; ++i) {
			XOPER<X> ki, vi; // key, value
			const XOPER<X>& ai = *ppa[i];

			if (ai.xltype == xltypeMissing) {
				return i;
			}

			if (ai.size() == 1) {
				ki = XExcel<X>(xlfText, XOPER<X>(j), XOPER<X>("\"_\"0"));
				vi = ai;
				++j;
			}
			else if (ai.size() == 2) {
				ki = ai[0];
				vi = ai[1];
				ensure(ki.xltype == xltypeStr);
			}
			else {
				XLL_ERROR("XLL.EVAL: args must be 1 or 2 dimensional");
			}

			ensure(XExcel<X>(xlfSetName, ki, vi));
			//ensure(XExcel<X>(xlfEvaluate, XExcel<X>(xlfGetName, ki)) == vi);
		}

		return -1;
	}
	template<class X>
	inline void UnsetNames(X** ppa, unsigned len)
	{
		for (unsigned i = 0, j = 1; i < len; ++i) {
			XOPER<X> ki, vi; // key, value
			const XOPER<X>& ai = *ppa[i];

			if (ai.size() == 1) {
				ki = XExcel<X>(xlfText, XOPER<X>(j), XOPER<X>("\"_\"0"));
				++j;
			}
			else if (ai.size() == 2) {
				ki = ai[0];
				ensure(ki.xltype == xltypeStr);
			}
			else {
				XLL_ERROR("XLL.EVAL: args must be 1 or 2 dimensional");
			}

			ensure(XExcel<X>(xlfSetName, ki));
		}
	}
} // namespace xll

AddIn xai_udf(
	Function(XLL_LPOPER, "xll_udf", "XLL.UDF")
	.Arguments(std::vector(ARGMAX, XLL_LPOPER))
	.Uncalced()
	.FunctionHelp("Call user defined function.")
	.Category("XLL")
	/*
	.Documentation(R"(
Call a user defined function given its arguments.
Either the string or register id of the udf may be used.
	)")
	*/
);
LPXLOPERX WINAPI xll_udf(LPXLOPERX pa LPXLOPERX32)  
{
#pragma XLLEXPORT
	static XLOPERX r = ErrValue;

	try {
		XLOPERX** ppa = &pa;

		r = Excelv(xlfEvaluate, len(ppa), ppa);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return &r;
}

AddIn xai_eval(
	Function(XLL_LPOPER, "xll_eval", "XLL.EVAL")
	.Arguments(std::vector(ARGMAX, XLL_LPOPER))
	.Uncalced()
	.FunctionHelp("Evaluate a function.")
	.Category("XLL")
	/*
	.Documentation(R"(
The first argument is a string expression to evaluate.
Occurences of _1, _2, ... are replaced by the following arguments.
If the argument is a key-value pair the key is replaced by the value in the string expression.
To use a cell reference or existing name prepend an exclamation point.		
	)")
	*/
);
LPXLOPERX WINAPI xll_eval(LPXLOPERX pa LPXLOPERX32)
{
#pragma XLLEXPORT
	static XLOPERX r = ErrValue;

	try {
		XLOPERX** ppa = &pa;

		unsigned n = SetNames(ppa + 1);
		r = Excelv(xlfEvaluate, 1, ppa);
		UnsetNames(ppa + 1, n);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return &r;
}

