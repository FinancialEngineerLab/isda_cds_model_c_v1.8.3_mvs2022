// ISDA_ME.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ISDA_ME.h"

#include "XLCALL.h"
#include "FRAMEWRK.h"
#include "xlutils.h"

#pragma region Generic Excel stuff

// Compares two strings for equality (case-insensitive).
int lpwstricmp(LPWSTR s, LPWSTR t)
{
	int i;
	if (wcslen(s) != *t)
	{
		return 1;
	}
	for (i = 1; i <= s[0]; i++)
	{
		if (towlower(s[i - 1]) != towlower(t[i]))
		{
			return 1;
		}
	}
	return 0;
}

// Excel calls xlAutoOpen when it loads the XLL.
__declspec(dllexport) int WINAPI xlAutoOpen(void)
{
	static XLOPER12 xDLL;      // The filename of this XLL.
	int i;
#if DEBUG
	debugPrintf("xlAutoOpen\n");
#else
#endif
	// Fetch the name of this XLL. This is used as the first arg
	// to the REGISTER function to specify the name of the XLL.
	Excel12f(xlGetName, &xDLL, 0);
#if DEBUG
	debugPrintf("XLL Name : %S\n", xDLL.val.str);
#else
#endif
	// Loop through the g_rgUDFs[] table, registering each
	// function in the table using xlfRegister.
	for (i = 0; i < g_rgNumUDFs; i++)
	{
		Excel12f(
			xlfRegister,
			0,
			1 + g_rgUDFdata,
			static_cast<LPXLOPER12>(&xDLL),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][0])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][1])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][2])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][3])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][4])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][5])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][6])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][7])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][8])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][9])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][10])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][11])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][12])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][13])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][14])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][15])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][16])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][17])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][18])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][19])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][20])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][21])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][22])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][23])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][24])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][25])),
			static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][26]))
		);
	}
	// Free the XLL filename.
	Excel12f(xlFree, nullptr, 1, static_cast<LPXLOPER12>(&xDLL));
	return 1;
}

// Excel calls xlAutoClose when it unloads the XLL.
__declspec(dllexport) int WINAPI xlAutoClose(void)
{
	int i;
#if DEBUG
	debugPrintf("xlAutoClose\n");
#else
#endif
	// Delete all names added by xlAutoOpen or xlAutoRegister.
	for (i = 0; i < g_rgNumUDFs; i++)
	{
		Excel12f(xlfSetName, nullptr, 1, TempStr12(g_rgUDFs[i][2]));
	}
	return 1;
}

// Excel calls xlAutoRegister12 if a macro sheet tries to register
// a function without specifying the type_text argument.
__declspec(dllexport) LPXLOPER12 WINAPI xlAutoRegister12(LPXLOPER12 pxName)
{
	static XLOPER12 xDLL, xRegId;
	int i;
#if DEBUG
	debugPrintf("xlAutoRegister12\n");
#else
#endif
	xRegId.xltype = xltypeErr;
	xRegId.val.err = xlerrValue;
	for (i = 0; i < g_rgNumUDFs; i++)
	{
		if (!lpwstricmp(g_rgUDFs[i][0], pxName->val.str))
		{
			Excel12f(xlfRegister, 0, 1 + g_rgUDFdata,
				static_cast<LPXLOPER12>(&xDLL),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][0])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][1])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][2])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][3])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][4])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][5])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][6])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][7])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][8])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][9])),
				static_cast<LPXLOPER12>(TempStr12(g_rgUDFs[i][10]))
			);
			// Free the oper returned by Excel.
			Excel12f(xlFree, nullptr, 1, static_cast<LPXLOPER12>(&xDLL));
			return static_cast<LPXLOPER12>(&xRegId);
		}
	}
	return static_cast<LPXLOPER12>(&xRegId);
}

// When you add an XLL to the list of active add-ins, the Add-in
// Manager calls xlAutoAdd() and then opens the XLL, which in turn
// calls xlAutoOpen.
__declspec(dllexport) int WINAPI xlAutoAdd(void)
{
#if DEBUG
	debugPrintf("xlAutoAdd\n");
#else
#endif
	return 1;
}

// When you remove an XLL from the list of active add-ins, the
// Add-in Manager calls xlAutoRemove() and then
// UNREGISTER("SimpleXll2007.XLL").

__declspec(dllexport) int WINAPI xlAutoRemove(void)
{
#if DEBUG
	debugPrintf("xlAutoRemove\n");
#else
#endif
	return 1;
}

// The Excel Add-in Manager calls xlAddInManagerInfo12 function
// to find the long name of the add-in.
__declspec(dllexport) LPXLOPER12 WINAPI xlAddInManagerInfo12(LPXLOPER12 xAction)
{
	static XLOPER12 xInfo, xIntAction;
#if DEBUG
	debugPrintf("xlAutoAddInManagerInfo12\n");
#else
#endif
	// This code coerces the passed-in value to an integer.
	Excel12f(xlCoerce, &xIntAction, 2, xAction, TempInt12(xltypeInt));
	if (xIntAction.val.w == 1)
	{
		// Note that the string is length-prefixed in octal.
		xInfo.xltype = xltypeStr;
		xInfo.val.str = L"\020LFIS-CN-CPP-xll";
	}
	else
	{
		xInfo.xltype = xltypeErr;
		xInfo.val.err = xlerrValue;
	}
	// Word of caution: returning static XLOPERs/XLOPER12s is
	// not thread-safe. For UDFs declared as thread-safe, use
	// alternate memory allocation mechanisms.
	return static_cast<LPXLOPER12>(&xInfo);
}

#pragma endregion 

#pragma region ISDA stuff

/*
* ISDA CDS Standard Model
*
* Copyright (C) 2009 International Swaps and Derivatives Association, Inc.
* Developed and supported in collaboration with Markit
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the ISDA CDS Standard Model Public License.
*/

#include "objects.h"
#include "version.h"
#include "cerror.h"
#include "tcurve.h"
#include "cdsone.h"
#include "convert.h"
#include "date_sup.h"
#include "zerocurve.h"
#include "cds.h"
#include "cxzerocurve.h"
#include "defaulted.h"

#include "bastypes.h"
#include "cdate.h"
#include "ldate.h"
#include "cgeneral.h"
#include "dtlist.h"
#include "stub.h"
#include "cashflow.h"
#include "macros.h"

/*
***************************************************************************
** Get the xltype of an xloper
***************************************************************************
*/

__declspec(dllexport) char * WINAPI xloper_type_str(XLOPER12 *p_xlop)
{
	if (p_xlop == NULL) // Should never happen
		return NULL;
	switch (p_xlop->xltype)
	{
		case xltypeNum:
			return "0x0001 xltypeNum";
		case xltypeStr:
			return "0x0002 xltypeStr";
		case xltypeBool:
			return "0x0004 xltypeBool";
		case xltypeRef:
			return "0x0008 xltypeRef";
		case xltypeSRef:
			return "0x0400 xltypeSRef";
		case xltypeErr:
			return "0x0010 xltypeErr";
		case xltypeMulti:
			return "0x0040 xltypeMulti";
		case xltypeMissing:
			return "0x0080 xltypeMissing";
		case xltypeNil:
			return "0x0100 xltypeNil";
		default:
			return "Unexpected type";
	}
}

/*
***************************************************************************
** Read array of doubles from Excel.
***************************************************************************
*/
int ReadDoubleArray(TBoolean mandatory, XLOPER *oper, size_t n, double **values, char *routine, char *param)
{
	size_t i;

	if (mandatory && oper->xltype == xltypeMissing)
	{
		JpmcdsErrMsg("%s: %s parameter is required\n", routine, param);
		return FAILURE;
	}

	if (oper->xltype == xltypeMulti)
	{
		if (oper->val.array.rows != n)
		{
			JpmcdsErrMsg("%s: %s - incorrect number of elements, expected %d\n", routine, param, n);
			return FAILURE;
		}

		*values = NEW_ARRAY(double, n);
		if (*values == NULL)
			return FAILURE;

		for (i = 0; i < n; i++)
		{
			if (JpmcdsExcelGetDouble(oper->val.array.lparray + i, *values + i) != SUCCESS)
				return FAILURE;
		}
	}
	else
	{
		if (n != 1)
		{
			JpmcdsErrMsg("%s: %s - incorrect number of elements, expected %d\n", routine, param, n);
			return FAILURE;
		}

		*values = NEW_ARRAY(double, n);
		if (*values == NULL)
			return FAILURE;

		if (JpmcdsExcelGetDouble(oper, *values) != SUCCESS)
			return FAILURE;
	}

	return SUCCESS;
}


/*
***************************************************************************
** Read date from Excel,
** input either as an explicit dates or a date interval.
***************************************************************************
*/
int ReadDateOrInterval(XLOPER *oper, int i, TDate valueDate, TDate* date, char *routine, char *param)
{
	if (JpmcdsExcelGetDate(oper, date) != SUCCESS)
	{
		TDateInterval  ivl;
		char          *s;

		if (JpmcdsExcelGetString(oper, &s) != SUCCESS)
			return FAILURE;

		if (JpmcdsStringToDate(s, date) != SUCCESS)
		{
			if (JpmcdsStringToDateInterval(s, routine, &ivl) != SUCCESS)
			{
				JpmcdsErrMsg("%s: %s - invalid interval for element[%d].\n", routine, param, i);
				FREE(s);
				return FAILURE;
			}

			FREE(s);

			if (JpmcdsDateFwdThenAdjust(valueDate, &ivl, JPMCDS_BAD_DAY_NONE, "None", date) != SUCCESS)
			{
				JpmcdsErrMsg("%s: %s - invalid interval for element[%d].\n", routine, param, i);
				return FAILURE;
			}
		}
	}

	return SUCCESS;
}


/*
***************************************************************************
** Read array of dates from Excel,
** input either as explicit dates or as date intervals.
***************************************************************************
*/
int ReadDateOrIntervalArray(TBoolean mandatory, XLOPER *oper, size_t n, TDate valueDate, TDate **values, char *routine, char *param)
{
	size_t i;

	if (mandatory && oper->xltype == xltypeMissing)
	{
		JpmcdsErrMsg("%s: %s parameter is required\n", routine, param);
		return FAILURE;
	}

	if (oper->xltype == xltypeMulti)
	{
		if (oper->val.array.rows != n)
		{
			JpmcdsErrMsg("%s: %s - incorrect number of elements, expected %d\n", routine, param, n);
			return FAILURE;
		}

		*values = NEW_ARRAY(TDate, n);
		if (*values == NULL)
			return FAILURE;

		for (i = 0; i < n; i++)
		{
			if (ReadDateOrInterval(oper->val.array.lparray + i, i + 1, valueDate, *values + i, routine, param) != SUCCESS)
				return FAILURE;
		}
	}
	else
	{
		if (n != 1)
		{
			JpmcdsErrMsg("%s: %s - incorrect number of elements, expected %d\n", routine, param, n);
			return FAILURE;
		}

		*values = NEW_ARRAY(TDate, n);
		if (*values == NULL)
			return FAILURE;

		if (ReadDateOrInterval(oper, 1, valueDate, *values, routine, param) != SUCCESS)
			return FAILURE;
	}

	return SUCCESS;
}


/* convenience macro for getting Excel array size */
#define ARRAY_SIZE(oper, n) \
    if (oper->xltype == xltypeMissing) \
        n = 0; \
    else if (oper->xltype == xltypeMulti) \
        n = oper->val.array.rows; \
    else \
        n = 1


/* convenience macro for getting parameter values, checking if mandatory parameters are defined */
#define PARAM(mandatory, paramtype, oper, name) \
    if (mandatory && (oper->xltype == xltypeMissing || oper->xltype == xltypeNil)) \
    { \
        JpmcdsErrMsg("%s: %s parameter is required\n", routine, #name); \
        goto done; \
    } \
    if (oper->xltype == xltypeMulti) \
    { \
        JpmcdsErrMsg("%s: %s scalar value is required\n", routine, #name); \
        goto done; \
    } \
    if (JpmcdsExcelGet##paramtype##(oper, &##name##) != SUCCESS) \
        goto done


/* convenience macro for setting default parameter values */
#define SET_DEFAULT(variable, value) \
    if (variable == NULL) variable = _strdup(value) \


/* convenience macro for returning value to Excel, reporting any error */
#define EXCEL_RETURN \
    if (status != SUCCESS) \
    { \
        JpmcdsErrMsg("%s: Failed!\n", routine); \
        JpmcdsFreeExcelOper(a0); \
    } \
    \
    return (status == SUCCESS) ? ExcelOutput(a0) : ErrorOutput()


/*
***************************************************************************
** Wrapper for Excel addin Version function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_Version(void)
{
	static char *routine = "CDS_Version";
	int          status = FAILURE;
	LPXLOPER     a0 = NULL;
	char         version[256];

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	if (JpmcdsVersionString(version) != SUCCESS)
		goto done;

	if (JpmcdsExcelSetString(version, a0) != SUCCESS)
		goto done;

	status = SUCCESS;

done:
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin ErrorLogStatus function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_ErrorLogStatus(void)
{
	static char *routine = "CDS_ErrorLogStatus";
	int          status = FAILURE;
	LPXLOPER     a0 = NULL;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	a0->xltype = xltypeNum;
	a0->val.num = (double)JpmcdsErrMsgStatus();
	status = SUCCESS;

done:
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin ErrorLogContents function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_ErrorLogContents(void)
{
	int       status = FAILURE;
	LPXLOPER  a0 = NULL;
	char    **lines;
	int       rows = 0;
	int       i;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	lines = JpmcdsErrGetMsgRecord();
	if (lines == NULL)
	{
		status = JpmcdsExcelSetString("(no log contents)", a0);
		goto done;
	}

	while (lines[rows] != NULL)
		rows++;

	a0->xltype = xltypeMulti;
	a0->val.array.rows = rows;
	a0->val.array.columns = 1;
	a0->val.array.lparray = NEW_ARRAY(XLOPER, rows);
	if (a0->val.array.lparray == NULL)
		goto done;

	for (i = 0; i < rows; i++)
		(void) JpmcdsExcelSetString(lines[i], a0->val.array.lparray + i);

	status = SUCCESS;

done:
	if (status != SUCCESS)
		JpmcdsFreeExcelOper(a0);
	return (status == SUCCESS) ? ExcelOutput(a0) : ErrorOutput();
}


/*
***************************************************************************
** Wrapper for Excel addin ErrorLogFilename function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_ErrorLogFilename(void)
{
	static char *routine = "CDS_ErrorLogFilename";
	int          status = FAILURE;
	LPXLOPER     a0 = NULL;
	char*        filename;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	filename = JpmcdsErrMsgGetFileName();
	if (filename == NULL)
		goto done;

	if (JpmcdsExcelSetString(filename, a0) != SUCCESS)
		goto done;

	status = SUCCESS;

done:
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin SetErrorLogFilename function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_SetErrorLogFilename(XLOPER *a1, XLOPER *a2)
{
	static char *routine = "CDS_SetErrorLogFilename";
	int          status = FAILURE;
	LPXLOPER     a0 = NULL;
	char        *filename = NULL;
	long         append;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	PARAM(TRUE, String, a1, filename);
	PARAM(TRUE, Long, a2, append);

	status = JpmcdsErrMsgFileName(filename, (TBoolean)(append));
	a0->xltype = xltypeNum;
	a0->val.num = 1.0;
	status = SUCCESS;

done:
	FREE(filename);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin SetErrorLogStatus function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_SetErrorLogStatus(XLOPER *a1)
{
	static char *routine = "CDS_SetErrorLogStatus";
	int          status = FAILURE;
	LPXLOPER     a0 = NULL;
	long         state;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	PARAM(TRUE, Long, a1, state);

	if (state != 0)
	{
		if (JpmcdsErrMsgEnableRecord(20, 128) != SUCCESS) /* ie. 20 lines, each of max length 128 */
			goto done;
		JpmcdsErrMsgOn();
	}
	else
	{
		if (JpmcdsErrMsgDisableRecord() != SUCCESS)
			goto done;
		JpmcdsErrMsgOff();
	}

	a0->xltype = xltypeNum;
	a0->val.num = (state ? 1.0 : 0.0);
	status = SUCCESS;

done:
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin LoadHolidays function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_LoadHolidays(XLOPER *a1, XLOPER *a2)
{
	static char *routine = "CDS_LoadHolidays";
	int          status = FAILURE;
	LPXLOPER     a0 = NULL;
	char        *name = NULL;
	char        *filename = NULL;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	PARAM(TRUE, String, a1, name);
	PARAM(TRUE, String, a2, filename);

	status = JpmcdsHolidayLoadFromDisk(name, filename);

	a0->xltype = xltypeNum;
	a0->val.num = 1.0;
	status = SUCCESS;

done:
	FREE(name);
	FREE(filename);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin IRZeroCurveBuild function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_IRZeroCurveBuild(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5,
	XLOPER *a6, XLOPER *a7, XLOPER *a8, XLOPER *a9, XLOPER *a10, XLOPER *a11, XLOPER *a12)
{
	static char  *routine = "CDS_IRZeroCurveBuild";
	int           status = FAILURE;
	LPXLOPER      a0 = NULL;
	TDate         valueDate;
	char         *types = NULL;
	TDate        *dates = NULL;
	double       *rates = NULL;
	char         *mmDcc = NULL;
	char         *fixedIvl = NULL;
	char         *floatIvl = NULL;
	char         *fixedDcc = NULL;
	char         *floatDcc = NULL;
	char         *badDayConv = NULL;
	char         *holidays = NULL;
	TCurve       *zeroCurve = NULL;
	char         *name = NULL;
	char         *handle = NULL;

	int           i;
	int           nInstr;
	long          mmDCC;
	TDateInterval fixedIVL;
	TDateInterval floatIVL;
	long          fixedDCC;
	long          floatDCC;
	double        fixedFreq;
	double        floatFreq;

	int           dtSuccess;
	TDateInterval tmp;
	TDateAdjIntvl busday;
	TDate         baseDate;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	ARRAY_SIZE(a2, nInstr);
	PARAM(TRUE, Date, a1, valueDate);

	/* instrument types */
	if (a2->xltype == xltypeMissing)
	{
		JpmcdsErrMsg("%s: Types parameter is required\n", routine);
		goto done;
	}

	types = NEW_ARRAY(char, nInstr);
	if (types == NULL)
		goto done;

	for (i = 0; i < nInstr; i++)
	{
		char *type;
		if (JpmcdsExcelGetString(a2->val.array.lparray + i, &type) != SUCCESS)
			goto done;
		types[i] = type[0];
		FREE(type);
	}

	if (ReadDateOrIntervalArray(TRUE, a3, nInstr, valueDate, &dates, routine, "End Dates") != SUCCESS)
		goto done;

	if (ReadDoubleArray(TRUE, a4, nInstr, &rates, routine, "Rates") != SUCCESS)
		goto done;

	PARAM(FALSE, String, a5, mmDcc);
	PARAM(TRUE, String, a6, fixedIvl);
	PARAM(FALSE, String, a7, floatIvl);
	PARAM(TRUE, String, a8, fixedDcc);
	PARAM(FALSE, String, a9, floatDcc);
	PARAM(FALSE, String, a10, badDayConv);
	PARAM(TRUE, String, a11, holidays);
	PARAM(TRUE, String, a12, name);

	if (mmDcc == NULL) mmDcc = "ACT/360";
	if (JpmcdsStringToDayCountConv(mmDcc, &mmDCC) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(fixedIvl, routine, &fixedIVL) != SUCCESS)
		goto done;

	if (floatIvl == NULL)
		floatIvl = fixedIvl;

	if (JpmcdsStringToDateInterval(floatIvl, routine, &floatIVL) != SUCCESS)
		goto done;

	if (JpmcdsStringToDayCountConv(fixedDcc, &fixedDCC) != SUCCESS)
		goto done;

	if (floatDcc == NULL)
		floatDcc = fixedDcc;

	if (JpmcdsStringToDayCountConv(floatDcc, &floatDCC) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsDateIntervalToFreq(&fixedIVL, &fixedFreq) != SUCCESS)
		goto done;

	if (JpmcdsDateIntervalToFreq(&floatIVL, &floatFreq) != SUCCESS)
		goto done;

	/** adjust cash rates dates to business day */
	baseDate = valueDate;
	for (i = 0; i < nInstr; i++)
	{
		if (types[i] == 'M')
		{
			if (dates[i] - baseDate <= 3)
			{
				/* for business days */
				tmp.flag = 0;
				tmp.prd = dates[i] - baseDate;
				tmp.prd_typ = 'D';
				busday.holidayFile = holidays;
				busday.isBusDays = TRUE;
				busday.badDayConv = JPMCDS_BAD_DAY_FOLLOW;
				busday.interval = tmp;
				/* adjust to business day */
				dtSuccess = JpmcdsDtFwdAdj(baseDate, &busday, dates + i);
			}
			else if (dates[i] - baseDate <= 21)
			{
				/* for less than or equal to 3 weeks */
				/* adjust to business day */
				dtSuccess = JpmcdsBusinessDay(dates[i], 'F', holidays, dates + i);
			}
			else
			{
				/* adjust to business day */
				dtSuccess = JpmcdsBusinessDay(dates[i], 'M', holidays, dates + i);
			}
		}
	}

	zeroCurve = JpmcdsBuildIRZeroCurve(
		valueDate,
		types,
		dates,
		rates,
		nInstr,
		mmDCC,
		(long)fixedFreq,
		(long)floatFreq,
		fixedDCC,
		floatDCC,
		badDayConv[0],
		holidays);

	handle = StoreObject(name, zeroCurve);
	if (handle == NULL)
		goto done;

	if (JpmcdsExcelSetString(handle, a0) != SUCCESS)
		return NULL;

	status = SUCCESS;

done:
	FREE(types);
	FREE(dates);
	FREE(rates);
	FREE(mmDcc);
	FREE(fixedDcc);
	FREE(floatDcc);
	FREE(fixedIvl);
	FREE(floatIvl);
	FREE(badDayConv);
	FREE(holidays);
	FREE(name);
	FREE(handle);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin IRZeroCurveMake function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_IRZeroCurveMake(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5, XLOPER *a6, XLOPER *a7)
{
	static char  *routine = "CDS_IRZeroCurveMake";
	int           status = FAILURE;
	LPXLOPER      a0 = NULL;
	TDate         baseDate;
	TDate        *dates = NULL;
	double       *rates = NULL;
	long          basis;
	char         *zcDcc = NULL;
	TCurve       *zeroCurve = NULL;
	char         *name = NULL;
	char         *handle = NULL;

	int           n;
	long          dcc;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	ARRAY_SIZE(a2, n);
	PARAM(TRUE, Date, a1, baseDate);

	if (ReadDateOrIntervalArray(TRUE, a2, n, baseDate, &dates, routine, "Dates") != SUCCESS)
		goto done;

	if (ReadDoubleArray(TRUE, a3, n, &rates, routine, "Rates") != SUCCESS)
		goto done;

	PARAM(TRUE, Long, a4, basis);
	PARAM(FALSE, String, a5, zcDcc);
	PARAM(TRUE, String, a6, name);

	SET_DEFAULT(zcDcc, "ACT/365F");
	if (JpmcdsStringToDayCountConv(zcDcc, &dcc) != SUCCESS)
		goto done;

	zeroCurve = JpmcdsMakeTCurve(baseDate, dates, rates, n, basis, dcc);

	handle = StoreObject(name, zeroCurve);
	if (handle == NULL)
		goto done;

	if (JpmcdsExcelSetString(handle, a0) != SUCCESS)
		return NULL;

	status = SUCCESS;

done:
	FREE(dates);
	FREE(rates);
	FREE(zcDcc);
	FREE(name);
	FREE(handle);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin CleanSpreadCurveBuild function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_CleanSpreadCurveBuild(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4,
	XLOPER *a5, XLOPER *a6, XLOPER *a7, XLOPER *a8, XLOPER *a9, XLOPER *a10, XLOPER *a11, XLOPER *a12,
	XLOPER *a13, XLOPER *a14, XLOPER *a15, XLOPER *a16)
{
	static char   *routine = "CDS_CleanSpreadCurveBuild";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	TDate          today;               /* 1 */
	TDate          startDate;
	TDate          stepinDate;
	TDate          cashSettleDate;
	TDate         *dates = NULL;        /* 5 */
	double        *rates = NULL;
	long          *includes = NULL;
	long           payAccOnDefault;
	char          *couponInterval = NULL;
	char          *stubType = NULL;    /* 10 */
	char          *paymentDcc = NULL;
	char          *badDayConv = NULL;
	char          *holidays = NULL;
	double         recoveryRate;
	char          *name = NULL;
	TCurve        *discCurve = NULL;
	TCurve        *spreadCurve = NULL;
	char          *handle1 = NULL;
	char          *handle2 = NULL;

	int            i;
	int            n;
	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	ARRAY_SIZE(a5, n);
	PARAM(TRUE, Date, a1, today);
	PARAM(TRUE, Date, a2, startDate);
	PARAM(TRUE, Date, a3, stepinDate);
	PARAM(TRUE, Date, a4, cashSettleDate);

	if (ReadDateOrIntervalArray(TRUE, a5, n, startDate, &dates, routine, "End Dates") != SUCCESS)
		goto done;

	if (ReadDoubleArray(TRUE, a6, n, &rates, routine, "Rates") != SUCCESS)
		goto done;

	/* include flags - NB. missing entry = include everything */
	if (a7->xltype != xltypeMissing && a7->val.array.rows != 0)
	{
		includes = NEW_ARRAY(long, n);
		if (includes == NULL)
			goto done;

		if (a7->val.array.rows != n)
		{
			JpmcdsErrMsg("%s: Include Flags - incorrect number of elements, expected %d\n", routine, n);
			goto done;
		}

		for (i = 0; i < n; i++)
		{
			if (JpmcdsExcelGetLong(a7->val.array.lparray + i, includes + i) != SUCCESS)
				goto done;
		}
	}

	PARAM(TRUE, Long, a8, payAccOnDefault);
	PARAM(TRUE, String, a9, couponInterval);
	PARAM(FALSE, String, a10, stubType);
	PARAM(FALSE, String, a11, paymentDcc);
	PARAM(FALSE, String, a12, badDayConv);
	PARAM(TRUE, String, a13, holidays);
	PARAM(TRUE, String, a14, handle1);
	PARAM(TRUE, Double, a15, recoveryRate);
	PARAM(TRUE, String, a16, name);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	discCurve = (TCurve*)RetrieveObject(handle1);
	if (discCurve == NULL)
		goto done;

	spreadCurve = JpmcdsCleanSpreadCurve(today,
		discCurve,
		startDate,
		stepinDate,
		cashSettleDate,
		n,
		dates,
		rates,
		(TBoolean*)includes,
		recoveryRate,
		(TBoolean)(payAccOnDefault),
		&ivl,
		dcc,
		&stub,
		badDayConv[0],
		holidays);

	handle2 = StoreObject(name, spreadCurve);
	if (handle2 == NULL)
		goto done;

	if (JpmcdsExcelSetString(handle2, a0) != SUCCESS)
		return NULL;

	status = SUCCESS;

done:
	FREE(dates);
	FREE(rates);
	FREE(includes);
	FREE(couponInterval);
	FREE(stubType);
	FREE(paymentDcc);
	FREE(badDayConv);
	FREE(holidays);
	FREE(handle1);
	FREE(handle2);
	FREE(name);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin DiscountFactor function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_DiscountFactor(XLOPER *a1, XLOPER *a2)
{
	static char   *routine = "CDS_DiscountFactor";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	char          *handle = NULL;
	TDate          date;
	TCurve        *curve;
	double         result;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	PARAM(TRUE, String, a1, handle);
	PARAM(TRUE, Date, a2, date);

	curve = (TCurve*)RetrieveObject(handle);
	if (curve == NULL)
		goto done;

	result = JpmcdsZeroPrice(curve, date);

	a0->xltype = xltypeNum;
	a0->val.num = result;
	status = SUCCESS;

done:
	FREE(handle);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin DatesAndRates function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_DatesAndRates(XLOPER *a1)
{
	static char   *routine = "CDS_DatesAndRates";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	char          *handle = NULL;
	TCurve        *curve;
	int            i;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	PARAM(TRUE, String, a1, handle);

	curve = (TCurve*)RetrieveObject(handle);
	if (curve == NULL)
		goto done;

	/* dates and rates to a 2 column Excel array */
	a0->xltype = xltypeMulti;
	a0->val.array.rows = curve->fNumItems;
	a0->val.array.columns = 2;
	a0->val.array.lparray = NEW_ARRAY(XLOPER, 2 * curve->fNumItems);
	if (a0->val.array.lparray == NULL)
		goto done;

	for (i = 0; i < curve->fNumItems; i++)
	{
		a0->val.array.lparray[2 * i].xltype = xltypeNum;
		JpmcdsExcelSetDate(curve->fArray[i].fDate, a0->val.array.lparray + 2 * i);
		a0->val.array.lparray[2 * i + 1].xltype = xltypeNum;
		a0->val.array.lparray[2 * i + 1].val.num = curve->fArray[i].fRate;
	}

	status = SUCCESS;

done:
	FREE(handle);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin UpfrontFlat function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_UpfrontFlat(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5, XLOPER *a6, XLOPER *a7,
	XLOPER *a8, XLOPER *a9, XLOPER *a10, XLOPER *a11, XLOPER *a12, XLOPER *a13,
	XLOPER *a14, XLOPER *a15, XLOPER *a16, XLOPER *a17)
{
	static char   *routine = "CDS_UpfrontFlat";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	TDate          today;
	TDate          valueDate;
	TDate          benchmarkStartDate;
	TDate          startDate;
	TDate          stepinDate;
	TDate          endDate;
	double         couponRate;
	long           payAccOnDefault;
	char          *couponInterval = NULL;
	char          *stubType = NULL;
	char          *paymentDcc = NULL;
	char          *badDayConv = NULL;
	char          *holidays = NULL;
	char          *handle = NULL;
	double         parSpread;
	double         recoveryRate;
	long           isPriceClean;
	double         result;

	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;
	TCurve        *curve;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	PARAM(TRUE, Date, a1, today);
	PARAM(TRUE, Date, a2, valueDate);
	PARAM(TRUE, Date, a3, benchmarkStartDate);
	PARAM(TRUE, Date, a4, stepinDate);
	PARAM(TRUE, Date, a5, startDate);
	PARAM(TRUE, Date, a6, endDate);
	PARAM(TRUE, Double, a7, couponRate);
	PARAM(TRUE, Long, a8, payAccOnDefault);
	PARAM(TRUE, String, a9, couponInterval);
	PARAM(FALSE, String, a10, stubType);
	PARAM(FALSE, String, a11, paymentDcc);
	PARAM(FALSE, String, a12, badDayConv);
	PARAM(TRUE, String, a13, holidays);
	PARAM(TRUE, String, a14, handle);
	PARAM(TRUE, Double, a15, parSpread);
	PARAM(TRUE, Double, a16, recoveryRate);
	PARAM(TRUE, Long, a17, isPriceClean);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	curve = (TCurve*)RetrieveObject(handle);
	if (curve == NULL)
		goto done;

	if (JpmcdsCdsoneUpfrontCharge(today,
		valueDate,
		benchmarkStartDate,
		stepinDate,
		startDate,
		endDate,
		couponRate,
		(TBoolean)(payAccOnDefault),
		&ivl,
		&stub,
		dcc,
		badDayConv[0],
		holidays,
		curve,
		parSpread,
		recoveryRate,
		(TBoolean)(isPriceClean),
		&result) != SUCCESS) goto done;

	a0->xltype = xltypeNum;
	a0->val.num = result;
	status = SUCCESS;

done:
	FREE(couponInterval);
	FREE(stubType);
	FREE(paymentDcc);
	FREE(badDayConv);
	FREE(holidays);
	FREE(handle);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin ParSpreadFlat function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_ParSpreadFlat(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5, XLOPER *a6, XLOPER *a7,
	XLOPER *a8, XLOPER *a9, XLOPER *a10, XLOPER *a11, XLOPER *a12, XLOPER *a13, XLOPER *a14, XLOPER *a15, XLOPER *a16,
	XLOPER *a17)
{
	static char   *routine = "CDS_ParSpreadFlat";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	TDate          today;
	TDate          valueDate;
	TDate          benchmarkStartDate;
	TDate          stepinDate;
	TDate          startDate;
	TDate          endDate;
	double         couponRate;
	long           payAccOnDefault;
	char          *couponInterval = NULL;
	char          *stubType = NULL;
	char          *paymentDcc = NULL;
	char          *badDayConv = NULL;
	char          *holidays = NULL;
	char          *handle = NULL;
	double         upfrontCharge;
	double         recoveryRate;
	long           isPriceClean;
	double         result;

	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;
	TCurve        *curve;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	PARAM(TRUE, Date, a1, today);
	PARAM(TRUE, Date, a2, valueDate);
	PARAM(TRUE, Date, a3, benchmarkStartDate);
	PARAM(TRUE, Date, a4, stepinDate);
	PARAM(TRUE, Date, a5, startDate);
	PARAM(TRUE, Date, a6, endDate);
	PARAM(TRUE, Double, a7, couponRate);
	PARAM(TRUE, Long, a8, payAccOnDefault);
	PARAM(TRUE, String, a9, couponInterval);
	PARAM(FALSE, String, a10, stubType);
	PARAM(FALSE, String, a11, paymentDcc);
	PARAM(FALSE, String, a12, badDayConv);
	PARAM(TRUE, String, a13, holidays);
	PARAM(TRUE, String, a14, handle);
	PARAM(TRUE, Double, a15, upfrontCharge);
	PARAM(TRUE, Double, a16, recoveryRate);
	PARAM(TRUE, Long, a17, isPriceClean);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	curve = (TCurve*)RetrieveObject(handle);
	if (curve == NULL)
		goto done;

	if (JpmcdsCdsoneSpread(today,
		valueDate,
		benchmarkStartDate,
		stepinDate,
		startDate,
		endDate,
		couponRate,
		(TBoolean)(payAccOnDefault),
		&ivl,
		&stub,
		dcc,
		badDayConv[0],
		holidays,
		curve,
		upfrontCharge,
		recoveryRate,
		(TBoolean)(isPriceClean),
		&result) != SUCCESS) goto done;

	a0->xltype = xltypeNum;
	a0->val.num = result;
	status = SUCCESS;

done:
	FREE(couponInterval);
	FREE(stubType);
	FREE(paymentDcc);
	FREE(badDayConv);
	FREE(holidays);
	FREE(handle);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin CdsPrice function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_CdsPrice(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5, XLOPER *a6, XLOPER *a7, XLOPER *a8,
	XLOPER *a9, XLOPER *a10, XLOPER *a11, XLOPER *a12, XLOPER *a13, XLOPER *a14, XLOPER *a15,
	XLOPER *a16)
{
	static char  *routine = "CDS_CdsPrice";
	int           status = FAILURE;
	LPXLOPER      a0 = NULL;
	TDate         today;
	TDate         valueDate;
	TDate         stepinDate;
	TDate         startDate;
	TDate         endDate;
	double        couponRate;
	long          payAccOnDefault;
	char         *couponInterval = NULL;
	char         *stubType = NULL;
	char         *paymentDcc = NULL;
	char         *badDayConv = NULL;
	char         *holidays = NULL;
	char         *handle1 = NULL;
	char         *handle2 = NULL;
	double        recoveryRate;
	long          isPriceClean;
	double        result;

	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;
	TCurve        *discCurve;
	TCurve        *spreadCurve;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	PARAM(TRUE, Date, a1, today);
	PARAM(TRUE, Date, a2, valueDate);
	PARAM(TRUE, Date, a3, stepinDate);
	PARAM(TRUE, Date, a4, startDate);
	PARAM(TRUE, Date, a5, endDate);
	PARAM(TRUE, Double, a6, couponRate);
	PARAM(TRUE, Long, a7, payAccOnDefault);
	PARAM(TRUE, String, a8, couponInterval);
	PARAM(FALSE, String, a9, stubType);
	PARAM(FALSE, String, a10, paymentDcc);
	PARAM(FALSE, String, a11, badDayConv);
	PARAM(TRUE, String, a12, holidays);
	PARAM(TRUE, String, a13, handle1);
	PARAM(TRUE, String, a14, handle2);
	PARAM(TRUE, Double, a15, recoveryRate);
	PARAM(TRUE, Long, a16, isPriceClean);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	discCurve = (TCurve*)RetrieveObject(handle1);
	if (discCurve == NULL)
		goto done;

	spreadCurve = (TCurve*)RetrieveObject(handle2);
	if (spreadCurve == NULL)
		goto done;

	if (JpmcdsCdsPrice(today,
		valueDate,
		stepinDate,
		startDate,
		endDate,
		couponRate,
		(TBoolean)(payAccOnDefault),
		&ivl,
		&stub,
		dcc,
		badDayConv[0],
		holidays,
		discCurve,
		spreadCurve,
		recoveryRate,
		(TBoolean)(isPriceClean),
		&result) != SUCCESS) goto done;

	a0->xltype = xltypeNum;
	a0->val.num = result;
	status = SUCCESS;

done:
	FREE(couponInterval);
	FREE(stubType);
	FREE(paymentDcc);
	FREE(badDayConv);
	FREE(holidays);
	FREE(handle1);
	FREE(handle2);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin ParSpreads function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_ParSpreads(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5, XLOPER *a6, XLOPER *a7,
	XLOPER *a8, XLOPER *a9, XLOPER *a10, XLOPER *a11, XLOPER *a12, XLOPER *a13)
{
	static char   *routine = "CDS_ParSpreads";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	TDate          today;
	TDate          stepinDate;
	TDate          startDate;
	TDate         *dates = NULL;
	long           payAccOnDefault;
	char          *couponInterval = NULL;
	char          *stubType = NULL;
	char          *paymentDcc = NULL;
	char          *badDayConv = NULL;
	char          *holidays = NULL;
	double         recoveryRate;
	double        *results = NULL;
	char          *handle1 = NULL;
	char          *handle2 = NULL;

	int            n, i;
	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;
	TCurve        *discCurve;
	TCurve        *spreadCurve;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	ARRAY_SIZE(a4, n);
	PARAM(TRUE, Date, a1, today);
	PARAM(TRUE, Date, a2, stepinDate);
	PARAM(TRUE, Date, a3, startDate);
	if (ReadDateOrIntervalArray(TRUE, a4, n, stepinDate, &dates, routine, "End Dates") != SUCCESS)
		goto done;
	PARAM(TRUE, Long, a5, payAccOnDefault);
	PARAM(TRUE, String, a6, couponInterval);
	PARAM(FALSE, String, a7, stubType);
	PARAM(FALSE, String, a8, paymentDcc);
	PARAM(FALSE, String, a9, badDayConv);
	PARAM(TRUE, String, a10, holidays);
	PARAM(TRUE, String, a11, handle1);
	PARAM(TRUE, String, a12, handle2);
	PARAM(TRUE, Double, a13, recoveryRate);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	discCurve = (TCurve*)RetrieveObject(handle1);
	if (discCurve == NULL)
		goto done;

	spreadCurve = (TCurve*)RetrieveObject(handle2);
	if (spreadCurve == NULL)
		goto done;

	results = NEW_ARRAY(double, n);
	if (results == NULL)
		goto done;

	if (JpmcdsCdsParSpreads(today,
		stepinDate,
		startDate,
		n,
		dates,
		(TBoolean)(payAccOnDefault),
		&ivl,
		&stub,
		dcc,
		badDayConv[0],
		holidays,
		discCurve,
		spreadCurve,
		recoveryRate,
		results) != SUCCESS)
		goto done;

	/* results is an 1 column Excel array */
	a0->xltype = xltypeMulti;
	a0->val.array.rows = n;
	a0->val.array.columns = 1;
	a0->val.array.lparray = NEW_ARRAY(XLOPER, n);
	if (a0->val.array.lparray == NULL)
		goto done;

	for (i = 0; i < n; i++)
	{
		a0->val.array.lparray[i].xltype = xltypeNum;
		a0->val.array.lparray[i].val.num = results[i];
	}

	status = SUCCESS;

done:
	FREE(dates);
	FREE(stubType);
	FREE(couponInterval);
	FREE(paymentDcc);
	FREE(badDayConv);
	FREE(holidays);
	FREE(handle1);
	FREE(handle2);
	FREE(results);
	EXCEL_RETURN;
}


/*
***************************************************************************
** Wrapper for Excel addin FeeLegFlows function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_FeeLegFlows(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4, XLOPER *a5,
	XLOPER *a6, XLOPER *a7, XLOPER *a8, XLOPER *a9)
{
	static char   *routine = "CDS_FeeLegFlows";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;
	TDate          startDate;
	TDate          endDate;
	double         rate;
	double         notional;
	char          *couponInterval = NULL;
	char          *stubType = NULL;
	char          *paymentDcc = NULL;
	char          *badDayConv = NULL;
	char          *holidays = NULL;
	TCashFlowList *cfl = NULL;

	int            i;
	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;

	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();
	PARAM(TRUE, Date, a1, startDate);
	if (ReadDateOrInterval(a2, TRUE, startDate, &endDate, routine, "End Date") != SUCCESS)
		goto done;
	PARAM(TRUE, Double, a3, rate);
	PARAM(TRUE, Double, a4, notional);
	PARAM(TRUE, String, a5, couponInterval);
	PARAM(FALSE, String, a6, stubType);
	PARAM(FALSE, String, a7, paymentDcc);
	PARAM(FALSE, String, a8, badDayConv);
	PARAM(TRUE, String, a9, holidays);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	cfl = JpmcdsCdsFeeLegFlows(startDate,
		endDate,
		&ivl,
		&stub,
		notional,
		rate,
		dcc,
		badDayConv[0],
		holidays);

	if (cfl == NULL)
		goto done;

	/* write cashflow list to a 2 column Excel array */
	a0->xltype = xltypeMulti;
	a0->val.array.rows = cfl->fNumItems;
	a0->val.array.columns = 2;
	a0->val.array.lparray = NEW_ARRAY(XLOPER, 2 * cfl->fNumItems);
	if (a0->val.array.lparray == NULL)
		goto done;

	for (i = 0; i < cfl->fNumItems; i++)
	{
		a0->val.array.lparray[2 * i].xltype = xltypeNum;
		JpmcdsExcelSetDate(cfl->fArray[i].fDate, a0->val.array.lparray + 2 * i);
		a0->val.array.lparray[2 * i + 1].xltype = xltypeNum;
		a0->val.array.lparray[2 * i + 1].val.num = cfl->fArray[i].fAmount;
	}

	status = SUCCESS;

done:
	JpmcdsFreeCFL(cfl);
	FREE(couponInterval);
	FREE(stubType);
	FREE(paymentDcc);
	FREE(badDayConv);
	FREE(holidays);
	EXCEL_RETURN;
}

/*
***************************************************************************
** Wrapper for Excel addin DefaultedCDS function.
***************************************************************************
*/
__declspec(dllexport) LPXLOPER WINAPI CDS_DefaultAccrual(XLOPER *a1, XLOPER *a2, XLOPER *a3, XLOPER *a4,
	XLOPER *a5, XLOPER *a6, XLOPER *a7, XLOPER *a8, XLOPER *a9, XLOPER *a10, XLOPER *a11)
{

	static char   *routine = "CDS_DefaultAccrual";
	int            status = FAILURE;
	LPXLOPER       a0 = NULL;

	TDate          tradeDate;
	TDate          edd;
	TDate          startDate;
	TDate          endDate;
	double         couponRate;
	double         notional;
	char          *couponInterval = NULL;
	char          *stubType = NULL;
	char          *paymentDcc = NULL;
	char          *badDayConv = NULL;
	char          *holidays = NULL;

	double        defaultAccrual;
	double        accrualDays;

	TStubMethod    stub;
	long           dcc;
	TDateInterval  ivl;


	a0 = NEW(XLOPER);
	if (a0 == NULL)
		goto done;

	JpmcdsClearExcelDateSystem();

	PARAM(TRUE, Date, a1, tradeDate);
	PARAM(TRUE, Date, a2, edd);
	PARAM(TRUE, Date, a3, startDate);
	PARAM(TRUE, Date, a4, endDate);
	PARAM(TRUE, Double, a5, notional);
	PARAM(TRUE, Double, a6, couponRate);
	PARAM(TRUE, String, a7, couponInterval);
	PARAM(FALSE, String, a8, stubType);
	PARAM(FALSE, String, a9, paymentDcc);
	PARAM(FALSE, String, a10, badDayConv);
	PARAM(TRUE, String, a11, holidays);

	SET_DEFAULT(stubType, "f/s");
	if (JpmcdsStringToStubMethod(stubType, &stub) != SUCCESS)
		goto done;

	SET_DEFAULT(paymentDcc, "ACT/360");
	if (JpmcdsStringToDayCountConv(paymentDcc, &dcc) != SUCCESS)
		goto done;

	if (JpmcdsStringToDateInterval(couponInterval, routine, &ivl) != SUCCESS)
		goto done;

	SET_DEFAULT(badDayConv, "N");
	if (JpmcdsBadDayConvValid(routine, badDayConv[0]) != SUCCESS)
		goto done;

	if (JpmcdsDefaultAccrual(
		tradeDate,
		edd,
		startDate,
		endDate,
		&ivl,
		&stub,
		notional,
		couponRate,
		dcc,
		badDayConv[0],
		holidays,
		&accrualDays,
		&defaultAccrual
	) != SUCCESS) goto done;

	a0->xltype = xltypeMulti;
	a0->val.array.rows = 2;
	a0->val.array.columns = 1;
	a0->val.array.lparray = NEW_ARRAY(XLOPER, 2);
	if (a0->val.array.lparray == NULL)
		goto done;

	a0->val.array.lparray[0].xltype = xltypeNum;
	a0->val.array.lparray[0].val.num = accrualDays;
	a0->val.array.lparray[1].xltype = xltypeNum;
	a0->val.array.lparray[1].val.num = defaultAccrual;

	status = SUCCESS;
done:
	FREE(couponInterval);
	FREE(stubType);
	FREE(paymentDcc);
	FREE(holidays);

	EXCEL_RETURN;
}





#pragma endregion 