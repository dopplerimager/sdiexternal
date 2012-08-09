
#ifdef DLL_EXPORTS
#define SDI_API __declspec(dllexport)
#else
#define SDI_API __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

//STANDARD LIBS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//SDI SPECIFIC LIBS
#include "idl_export.h" // IDL
#include "Atmcd32d.h"   // Andor Camera Driver
#include "PComm.h"      // MOXA USB/Serial Driver
#include "AIOUSB.h"

