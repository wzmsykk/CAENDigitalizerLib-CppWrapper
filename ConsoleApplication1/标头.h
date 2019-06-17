

#ifndef __CAENDIGITIZER_H
#define __CAENDIGITIZER_H
#endif
#define win32

#include "CAENDigitizerType.h"

#define FUNC_LOADED 3456
#define ERR_CANNOT_LOAD_FUNCTION -100L
#define ERR_CANNOT_LOAD_LIBRARY -101L

#if !defined(CAEN_USE_DIGITIZERS) && !defined(IGNORE_DPP_DEPRECATED)

#ifdef __GNUC__
#define DPP_DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DPP_DEPRECATED(func) __declspec(deprecated) func
#else
#pragma message("WARNING: DEPRECATED marking not supported on this compiler")
#define DPP_DEPRECATED(func) func
#endif

#else

#define DPP_DEPRECATED(func) func

#endif


//#define CAEN_DGTZ_GetMaxNumAggregatesBLT CAEN_DGTZ_GetMaxNumEventsBLT
//#define CAEN_DGTZ_SetMaxNumAggregatesBLT CAEN_DGTZ_SetMaxNumEventsBLT

#define MAX_PROBENAMES_LEN (50)
class CAENDev
{
public:
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_ConnectionType LinkType, int LinkNum, int ConetNode, uint32_t VMEBaseAddress, int* handle) = 0;

}
class CAENDigitizer :CAENDev
{
public:
	HMODULE hLinkdll;
	int	hDevice;
public:
	CAENDigitizer(const LPCTSTR name)
	{
		// Load DLL when Class is instantiated
		hLinkdll = NULL;
		hLinkdll = LoadLibrary(name);
		hDevice = 0;
	}

	~CAENDigitizer()
	{
		if (hDevice) {
			CAEN_DGTZ_CloseDigitizer(hDevice);
		}

		// unload the dll when the class is deleted
		if (hLinkdll != NULL)
			FreeLibrary(hLinkdll);


	}
	typedef CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_OpenDigitizer) (CAEN_DGTZ_ConnectionType, int, int, uint32_t, int*);
	LPCAEN_DGTZ_OpenDigitizer lpCAEN_DGTZ_OpenDigitizer = NULL;
	long isCAEN_DGTZ_OpenDigitizer = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_ConnectionType LinkType, int LinkNum, int ConetNode, uint32_t VMEBaseAddress, int* handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_OpenDigitizer)
			{
				lpCAEN_DGTZ_OpenDigitizer = NULL;
				lpCAEN_DGTZ_OpenDigitizer = (LPCAEN_DGTZ_OpenDigitizer)GetProcAddress(hLinkdll, "CAEN_DGTZ_OpenDigitizer");
				isCAEN_DGTZ_OpenDigitizer = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_OpenDigitizer)
				return lpCAEN_DGTZ_OpenDigitizer(LinkType, LinkNum, ConetNode, VMEBaseAddress, handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
}
};