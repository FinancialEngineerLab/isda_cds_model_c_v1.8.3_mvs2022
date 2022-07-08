/*

-----------------------------------------------------------------------------------------------------------------
|Data Type 					|Pass by Value	|Pass by Ref (Pointer) 	|Comments									|
|---------------------------------------------------------------------------------------------------------------|
|unsigned char *			|				|D, G					|Counted ASCII byte string					|
-----------------------------------------------------------------------------------------------------------------
|[v12+] unsigned short *	|				|C%, F%					|Null-terminated Unicode wide-char string	|
-----------------------------------------------------------------------------------------------------------------
|[v12+] unsigned short *	|				|D%, G%					|Counted Unicode wide character string		|
-----------------------------------------------------------------------------------------------------------------
|unsigned short [int]		|H				|						|DWORD, size_t, wchar_t						|
-----------------------------------------------------------------------------------------------------------------
|[signed] short [int]		|I				|M						|16-bit										|
-----------------------------------------------------------------------------------------------------------------
|[signed long] int			|J				|N						|32-bit										|
-----------------------------------------------------------------------------------------------------------------
|FP							|				|K						|Floating-point array structure				|
-----------------------------------------------------------------------------------------------------------------
|[v12+] FP12				|				|K%						|Larger grid floating-point array structure	|
-----------------------------------------------------------------------------------------------------------------
|XLOPER						|				|P						|Variable-type worksheet values and arrays	|
|							|				|R						|Values, arrays and range references		|
-----------------------------------------------------------------------------------------------------------------
|[v12+] XLOPER12			|				|Q						|Variable-type worksheet values and arrays	|
|							|				|U						|Values, arrays and range references		|
-----------------------------------------------------------------------------------------------------------------

*/


#ifndef ISDA_ME_H
#define ISDA_ME_H

#define g_rgNumUDFs 19
#define g_rgUDFdata 26

#include "minwindef.h"
static LPWSTR g_rgUDFs[g_rgNumUDFs][g_rgUDFdata] =
{
	{
		L"xloper_type_str",							// Function name/ordinal
		L"CQ",									// Func signature type
		L"xloper_type_str",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_Version",							// Function name/ordinal
		L"P",									// Func signature type
		L"CDS_Version",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_ErrorLogStatus",							// Function name/ordinal
		L"P",									// Func signature type
		L"CDS_ErrorLogStatus",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_ErrorLogContents",							// Function name/ordinal
		L"P",									// Func signature type
		L"CDS_ErrorLogContents",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_ErrorLogFilename",							// Function name/ordinal
		L"P",									// Func signature type
		L"CDS_ErrorLogFilename",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_SetErrorLogFilename",							// Function name/ordinal
		L"PPP",									// Func signature type
		L"CDS_SetErrorLogFilename",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_SetErrorLogStatus",							// Function name/ordinal
		L"PP",									// Func signature type
		L"CDS_SetErrorLogStatus",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_LoadHolidays",							// Function name/ordinal
		L"PPP",									// Func signature type
		L"CDS_LoadHolidays",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_IRZeroCurveBuild",							// Function name/ordinal
		L"PPPPPPPPPPPPP",									// Func signature type
		L"CDS_IRZeroCurveBuild",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_IRZeroCurveMake",							// Function name/ordinal
		L"PPPPPPPP",									// Func signature type
		L"CDS_IRZeroCurveMake",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_CleanSpreadCurveBuild",							// Function name/ordinal
		L"PPPPPPPPPPPPPPPPP",									// Func signature type
		L"CDS_CleanSpreadCurveBuild",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_DiscountFactor",							// Function name/ordinal
		L"PPP",									// Func signature type
		L"CDS_DiscountFactor",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_DatesAndRates",							// Function name/ordinal
		L"PP",									// Func signature type
		L"CDS_DatesAndRates",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_UpfrontFlat",							// Function name/ordinal
		L"PPPPPPPPPPPPPPPPPP",									// Func signature type
		L"CDS_UpfrontFlat",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_ParSpreadFlat",							// Function name/ordinal
		L"PPPPPPPPPPPPPPPPPP",									// Func signature type
		L"CDS_ParSpreadFlat",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_CdsPrice",							// Function name/ordinal
		L"PPPPPPPPPPPPPPPPP",									// Func signature type
		L"CDS_CdsPrice",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_ParSpreads",							// Function name/ordinal
		L"PPPPPPPPPPPPPP",									// Func signature type
		L"CDS_ParSpreads",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_FeeLegFlows",							// Function name/ordinal
		L"PPPPPPPPPP",									// Func signature type
		L"CDS_FeeLegFlows",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	},
	{
		L"CDS_DefaultAccrual",							// Function name/ordinal
		L"PPPPPPPPPPPPP",									// Func signature type
		L"CDS_DefaultAccrual",							// Func name in Func wizard
		L"Arg1, Arg2",							// Arg name in Func wizard
		L"1",									// Function type
		L"LFIS-CN-CPP-xll Example functions",	// Category in Func wizard
		L"",									// Shortcut (commands only)
		L"",									// Help topic
		L"SumTwo function help",				// Func help in Func wizard
		L"Help for Arg1",						// Arg help in Func wizard
		L"Help for Arg2",						// Arg help in Func wizard
		L"Help for Arg3",						// Arg help in Func wizard
		L"Help for Arg4",						// Arg help in Func wizard
		L"Help for Arg5",						// Arg help in Func wizard
		L"Help for Arg6",						// Arg help in Func wizard
		L"Help for Arg7",						// Arg help in Func wizard
		L"Help for Arg8",						// Arg help in Func wizard
		L"Help for Arg9",						// Arg help in Func wizard
		L"Help for Arg10",						// Arg help in Func wizard
		L"Help for Arg11",						// Arg help in Func wizard
		L"Help for Arg12",						// Arg help in Func wizard
		L"Help for Arg13",						// Arg help in Func wizard
		L"Help for Arg14",						// Arg help in Func wizard
		L"Help for Arg15",						// Arg help in Func wizard
		L"Help for Arg16",						// Arg help in Func wizard
		L"Help for Arg17"						// Arg help in Func wizard
	}
};

#endif