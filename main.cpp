// dlltest.cpp : Defines the entry point for the DLL application.
//

#include "main.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

void IDL_Message(int code, int action, ...);

extern "C" SDI_API int uDLLTester(int argc, void *argv[])
{

    char buffer[50];
    unsigned int data=0;
    //data = reinterpret_cast<unsigned int>(argv[0]);
    data = (unsigned char)((unsigned int)argv[0]);
    sprintf(buffer, "Data given is: %d",data);

    IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, buffer);
    return 7;
}

extern "C" SDI_API int uDLLUnloader(int argc, void *argv[])
{
    /// EMPTY FUNCTION, CALL FROM IDL USING /UNLOAD
    return 0;
}

//ABORT IMAGE ACQUISITION
// takes no arguments
extern "C" SDI_API int uAbortAcquisition(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = AbortAcquisition();
	return errcode;
}


//CANCEL WAIT
// takes no arguments
extern "C" SDI_API int uCancelWait(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = CancelWait();
	return errcode;
}


//COOLER OFF
// takes no arguments
extern "C" SDI_API int uCoolerOFF(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = CoolerOFF();
	return errcode;
}


//COOLER ON
// tales no arguments
extern "C" SDI_API int uCoolerON(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = CoolerON();
	return errcode;
}


//FREE INTERNAL MEMORY
// takes no arguments
extern "C"
SDI_API int uFreeInternalMemory(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = FreeInternalMemory();
	return errcode;
}


//GET AMP DESCRIPTION
// int index, string desc
extern "C" SDI_API int uGetAmpDesc(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];

    IDL_STRING* description;
    description = (IDL_STRING *) argv[1];

	unsigned int errcode;
	errcode = GetAmpDesc(*index, description->s, description->slen);
	return errcode;
	return 0;
}

//GET AMP DESCRIPTION
// int index, float speed
extern "C" SDI_API int uGetAmpMaxSpeed(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];
    float *speed;
    speed = (float *) argv[1];

	unsigned int errcode;
	errcode = GetAmpMaxSpeed(*index, speed);
	return errcode;
	return 0;
}

//GET ACQUIRED DATA
// calling seq: (long*: array, long: size of array in total pixels)
extern "C" SDI_API int uGetAcquiredData(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *size;
	size = (long *) argv[1];

	unsigned int errcode;
	errcode = GetAcquiredData((long *) argv[0], *size);
	return errcode;
}


//GET ACQUIRED DATA 16-Bit version
// calling seq: (int: array, long: size of array in total pixels)
//extern "C" SDI_API int uGetAcquiredData16(int argc, char *argv[])
//{
//	if (argc != 2) {
//		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
//		return 0;
//	}
//
//	unsigned int errcode;
//	long size = atol(argv[1]);
//	errcode = GetAcquiredData16((int *) argv[0], size);
//	return errcode;
//}


//GET ACQUISITION PROGRESS
// calling seq: (long* accumulated scans, long* series)
extern "C" SDI_API int uGetAcquisitionProgress(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	unsigned int errcode;
	errcode = GetAcquisitionProgress((long *) argv[0], (long *) argv[1]);
	return errcode;
}


//GET ACQUISITION TIMINGS
// calling seq: (float* exposure time (secs), float* accumulate cycle time (secs), float* kinetic cycle time (secs)
extern "C" SDI_API int uGetAcquisitionTimings(int argc, void *argv[])
{
	if (argc != 3) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "3 Parameters Required");
		return 0;
	}

	unsigned int errcode;
	errcode = GetAcquisitionTimings((float *) argv[0],
                                    (float *) argv[1],
                                    (float *) argv[2]);
	return errcode;
}


//GET AVAILABLE CAMERAS
// calling seq: (long* total cameras)
extern "C" SDI_API int uGetAvailableCameras(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	unsigned int errcode;
	errcode = GetAvailableCameras((long *) argv[0]);
	return errcode;
}


//GET BIT DEPTH
// calling seq: (int channel, int* depth)
extern "C" SDI_API int uGetBitDepth(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *channel, *depth;
	channel = (int *) argv[0];
	depth = (int *) argv[1];

	unsigned int errcode;
	errcode = GetBitDepth(*channel, depth);
	return errcode;
}


//GET CAMERA HANDLE
// calling seq: (long camera index, long* camera handle)
extern "C" SDI_API int uGetCameraHandle(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *index, *handle;
	index = (long *) argv[0];
	handle = (long *) argv[1];

	unsigned int errcode;
	errcode = GetCameraHandle(*index, handle);
	return errcode;
}


//GET CAMERA INFORMATION
// calling seq: (int index, long* information
extern "C" SDI_API int uGetCameraInformation(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}


	int index = 0;
    long *info;
	info = (long *) argv[1];

	unsigned int errcode;
	errcode = GetCameraInformation(index, info);
	return errcode;
}

//GET CAMERA SERIAL NUMBER
// calling seq: (int number)
extern "C" SDI_API int uGetCameraSerialNumber(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameter Required");
		return 0;
	}

    int *num;
	num = (int *) argv[0];

	unsigned int errcode;
	errcode = GetCameraSerialNumber(num);
	return errcode;
}


//GET CAPABILITIES



//GET CURRENT CAMERA
// calling seq: (long* camera handle)
extern "C" SDI_API int uGetCurrentCamera(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}


	long *handle;
	handle = (long *) argv[0];

	unsigned int errcode;
	errcode = GetCurrentCamera(handle);
	return errcode;
}


//GETDDGIOCPULSES
// calling seq: (int* pulses)
extern "C" SDI_API int uGetDDGIOCPulses(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}


	int *pulses;
	pulses = (int *) argv[0];

	unsigned int errcode;
	errcode = GetDDGIOCPulses(pulses);
	return errcode;
}


//GET DDG PULSE
// calling seq: (double region, double resolution, double* delay, double* width)
extern "C" SDI_API int uGetDDGPulse(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

	double *region, *resolution, *delay, *width;
	region = (double *) argv[0];
	resolution = (double *) argv[1];
	delay = (double *) argv[2];
	width = (double *) argv[3];

	unsigned int errcode;
	errcode = GetDDGPulse(*region, *resolution, delay, width);
	return errcode;
}


//GET DETECTOR
// calling seq: (int* xpixels, int* ypixels)
extern "C" SDI_API int uGetDetector(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *xpix;
    int *ypix;
	xpix = (int *) argv[0];
	ypix = (int *) argv[1];

	unsigned int errcode;
	errcode = GetDetector(xpix, ypix);
	return errcode;
}


//GET FASTEST RECOMMENDED VS SPEED
// calling seq: (int* index, float* speed)
extern "C" SDI_API int uGetFastestRecommendedVSSpeed(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *index;
    float *speed;
	index = (int *) argv[0];
	speed = (float *) argv[1];

	unsigned int errcode;
	errcode = GetFastestRecommendedVSSpeed(index, speed);
	return errcode;
}


//GET EMCCD GAIN
// calling seq: int gain
extern "C" SDI_API int uGetEMCCDGain(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int* gain = (int *) argv[0];

	unsigned int errcode;
	errcode = GetEMCCDGain(gain);
	return errcode;
}


//GET EMCCD GAIN RANGE
// calling seq: int low, int high
extern "C" SDI_API int uGetEMGainRange(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int* lo = (int*) argv[0];
	int* hi = (int*) argv[1];

	unsigned int errcode;
	errcode = GetEMGainRange(lo, hi);
	return errcode;
}


//GET FILTER MODE
// calling seq: (int* mode)
extern "C" SDI_API int uGetFilterMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
    mode = (int *) argv[0];

	unsigned int errcode;
	errcode = GetFilterMode(mode);
	return errcode;
}


//GET FK EXPOSURE TIME
// calling seq: (float* exposure)
extern "C" SDI_API int uGetFKExposureTime(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	float *exposure;
    exposure = (float *) argv[0];

	unsigned int errcode;
	errcode = GetFKExposureTime(exposure);
	return errcode;
}


//GET FKV SHIFT SPEED F
// calling seq: (int index, float* speed)
extern "C" SDI_API int uGetFKVShiftSpeedF(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];

    float *speed;
	speed = (float *) argv[1];

	unsigned int errcode;
	errcode = GetFKVShiftSpeedF(*index, speed);
	return errcode;
}


//GET HEAD MODEL
// calling seq: (char* model)
extern "C" SDI_API int uGetHeadModel(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

    IDL_STRING* model;
    model = (IDL_STRING *) argv[0];

	unsigned int errcode;
	errcode = GetHeadModel(model->s);
	return errcode;
}


//GET HS SPEED
// calling seq: (int channel, int type, int index, float *speed)
extern "C" SDI_API int uGetHSSpeed(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

	int *channel, *type, *index;
	channel = (int *) argv[0];
	type = (int *) argv[1];
	index = (int *) argv[2];

	float *speed;
	speed = (float *) argv[3];

	unsigned int errcode;
	errcode = GetHSSpeed(*channel, *type, *index, speed);
	return errcode;
}


//GET IMAGES
// calling seq: (long first, long last, long* array, ulong size in tot pixels, long* validfirst, long* validlast)
extern "C" SDI_API int uGetImages(int argc, void *argv[])
{
	if (argc != 6) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "6 Parameters Required");
		return 0;
	}


	long *first, *last, *buffer, *validfirst, *validlast;
	first = (long *) argv[0];
	last = (long *) argv[1];
	buffer = (long *) argv[2];
	validfirst = (long *) argv[4];
	validlast = (long *) argv[5];

	unsigned long *size;
	size = (unsigned long *) argv[3];



	unsigned int errcode;
	errcode = GetImages(*first, *last, buffer, *size, validfirst, validlast);
	return errcode;
}


//GET IMAGES DMA
// caling seq: (ulong* images)
extern "C" SDI_API int uGetImagesPerDMA(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	unsigned long *images;
    images = (unsigned long *) argv[0];

	unsigned int errcode;
	errcode = GetImagesPerDMA(images);
	return errcode;
}

//GET MAX EXPOSURE TIME
// caling seq: float exp
extern "C" SDI_API int uGetMaximumExposure(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	float* maxexp = (float*) argv[0];

	unsigned int errcode;
	errcode = GetMaximumExposure(maxexp);
	return errcode;
}

//GET MOST RECENT IMAGE
// calling seq: (long* array, ulong size in total pixels)
extern "C" SDI_API int uGetMostRecentImage(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *buffer;
    buffer = (long *) argv[0];
	unsigned long *size;
	size = (unsigned long *) argv[1];

	unsigned int errcode;
	errcode = GetMostRecentImage(buffer, *size);
	return errcode;
}


//GET NEW DATA
// calling seq: (long* array, ulong size in total pixels)
extern "C" SDI_API int uGetNewData(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *buffer;
	buffer = (long *) argv[0];

	unsigned long *size;
	size = (unsigned long *) argv[1];

	unsigned int errcode;
	errcode = GetNewData(buffer, *size);
	return errcode;
}


//GET NUMBER AD CHANNELS
// calling seq: (int* number)
extern "C" SDI_API int uGetNumberADChannels(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *number;
	number = (int *) argv[0];

	unsigned int errcode;
	errcode = GetNumberADChannels(number);
	return errcode;
}



//GET NUMBER AMP
// calling seq: (int* number)
extern "C" SDI_API int uGetNumberAmp(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *number;
	number = (int *) argv[0];

	unsigned int errcode;
	errcode = GetNumberAmp(number);
	return errcode;
}


//GET NUMBER FKV SHIFT SPEEDS
// calling seq: (int* number)
extern "C" SDI_API int uGetNumberFKVShiftSpeeds(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *number;
	number = (int *) argv[0];

	unsigned int errcode;
	errcode = GetNumberFKVShiftSpeeds(number);
	return errcode;
}


//GET NUMBER HS SPEEDS
// calling seq: (int channel, int type, int* number)
extern "C" SDI_API int uGetNumberHSSpeeds(int argc, void *argv[])
{
	if (argc != 3) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "3 Parameters Required");
		return 0;
	}

	int *channel, *type, *number;
	channel = (int *) argv[0];
	type = (int *) argv[1];
	number = (int *) argv[2];

	unsigned int errcode;
	errcode = GetNumberHSSpeeds(*channel, *type, number);
	return errcode;
}


//GET NUMBER NEW IMAGES
// calling seq: (long* first, long* last)
extern "C" SDI_API int uGetNumberNewImages(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *first, *last;
	first = (long *) argv[0];
	last = (long *) argv[1];

	unsigned int errcode;
	errcode = GetNumberNewImages(first, last);
	return errcode;
}


//GET NUMBER PRE AMP GAINS
// calling seq: (int* number)
extern "C" SDI_API int uGetNumberPreAmpGains(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *number;
	number = (int *) argv[0];

	unsigned int errcode;
	errcode = GetNumberPreAmpGains(number);
	return errcode;
}



//GET NUMBER VS SPEEDS
// calling seq: (int* number)
extern "C" SDI_API int uGetNumberVSSpeeds(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *number;
	number = (int *) argv[0];

	unsigned int errcode;
	errcode = GetNumberVSSpeeds(number);
	return errcode;
}

//GET NUMBER VS AMPLITUDES
// calling seq: (int* number)
extern "C" SDI_API int uGetNumberVSAmplitudes(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *number;
	number = (int *) argv[0];

	unsigned int errcode;
	errcode = GetNumberVSAmplitudes(number);
	return errcode;
}

//GET OLDEST IMAGE
// calling seq: (long* array, ulong size)
extern "C" SDI_API int uGetOldestImage(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *buffer;
	buffer = (long *) argv[0];

	unsigned long *size;
	size = (unsigned long *) argv[1];

	unsigned int errcode;
	errcode = GetOldestImage(buffer, *size);
	return errcode;
}


//GET PIXEL SIZE
// calling seq: (float* xsize, float* ysize)
extern "C" SDI_API int uGetPixelSize(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	float *xsize, *ysize;
	xsize = (float *) argv[0];
	ysize = (float *) argv[1];

	unsigned int errcode;
	errcode = GetPixelSize(xsize, ysize);
	return errcode;
}


//GET PRE AMP GAIN
// calling seq: (int index, float* gain);
extern "C" SDI_API int uGetPreAmpGain(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];
	float *gain;
	gain = (float *) argv[1];

	unsigned int errcode;
	errcode = GetPreAmpGain(*index, gain);
	return errcode;
}


//GET SIZE OF CIRCULAR BUFFER
// calling seq: (long* max images)
extern "C" SDI_API int uGetSizeOfCircularBuffer(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	long *maximages;
	maximages = (long *) argv[0];

	unsigned int errcode;
	errcode = GetSizeOfCircularBuffer(maximages);
	return errcode;
}

//GET SOFTWARE VERSIONS
// calling seq: 6 unsigned ints, eprom, cof file, driver revision no,
// driver version no, dll revision no, dll version no
extern "C" SDI_API int uGetSoftwareVersion(int argc, void *argv[])
{
	if (argc != 6) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "6 Parameters Required");
		return 0;
	}

    unsigned int* v0 = (unsigned int*)argv[0];
    unsigned int* v1 = (unsigned int*)argv[1];
    unsigned int* v2 = (unsigned int*)argv[2];
    unsigned int* v3 = (unsigned int*)argv[3];
    unsigned int* v4 = (unsigned int*)argv[4];
    unsigned int* v5 = (unsigned int*)argv[5];

	unsigned int errcode;
	errcode = GetSoftwareVersion(v0, v1, v2, v3, v4, v5);
	return errcode;
}



//GET SPOOL PROGRESS
// calling seq: (long* index)
extern "C" SDI_API int uGetSpoolProgress(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	long *numdats;
	numdats = (long *) argv[0];

	unsigned int errcode;
	errcode = GetSpoolProgress(numdats);
	return errcode;
}


//GET STATUS
// calling seq: (int* status)
extern "C" SDI_API int uGetStatus(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *status;
	status = (int *) argv[0];

	unsigned int errcode;
	errcode = GetStatus(status);
	return errcode;
}


//GET TEMPERATURE
// calling seq: (int*temp)
extern "C" SDI_API int uGetTemperature(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *temp;
	temp = (int *) argv[0];

	unsigned int errcode;
	errcode = GetTemperature(temp);
	return errcode;
}



//GET TEMPERATURE F
// calling seq: (float* temp)
extern "C" SDI_API int uGetTemperatureF(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	float *temp;
	temp = (float *) argv[0];

	unsigned int errcode;
	errcode = GetTemperatureF(temp);
	return errcode;
}


//GET TEMPERATURE RANGE
// calling seq: (int* min temp, int* max temp)
extern "C" SDI_API int uGetTemperatureRange(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *mintemp, *maxtemp;
	mintemp = (int *) argv[0];
	maxtemp = (int *) argv[1];

	unsigned int errcode;
	errcode = GetTemperatureRange(mintemp, maxtemp);
	return errcode;
}


//GET TOTAL NUMBER IMAGES ACQUIRED
// calling seq: (long* total images)
extern "C" SDI_API int uGetTotalNumberImagesAcquired(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	long *numimages;
	numimages = (long *) argv[0];

	unsigned int errcode;
	errcode = GetTotalNumberImagesAcquired(numimages);
	return errcode;
}


//GET VS SPEED
// calling seq: (int index, float* speed)
extern "C" SDI_API int uGetVSSpeed(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];

	float *speed;
	speed = (float *) argv[1];

	unsigned int errcode;
	errcode = GetVSSpeed(*index, speed);
	return errcode;
}


//INITIALIZE
// calling seq: (string: path)
extern "C" SDI_API int uInitialize(int argc, void *argv[])
{
	if (argc != 1) {
	    IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	unsigned int errcode;
	errcode = Initialize((char *) argv[0]);
    return errcode;
}


//IS PRE AMP GAIN AVAILABLE
// calling seq: (int channel, int amplifier, int index, int gain, int* status)
extern "C" SDI_API int uIsPreAmpGainAvailable(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

    int *channel, *amplifier, *index, *gain, *status;
	channel = (int *) argv[0];
	amplifier = (int *) argv[1];
	index = (int *) argv[2];
	gain = (int *) argv[3];
	status = (int *) argv[4];

	unsigned int errcode;
	errcode = IsPreAmpGainAvailable(*channel, *amplifier, *index, *gain, status);
	return errcode;
}


//PREPARE ACQUISITION
// takes no arguments
extern "C" SDI_API int uPrepareAcquisition(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = PrepareAcquisition();
	return errcode;
}


//SAVE AS BMP
// calling seq: (char* path, char* palette, long ymin, long ymax)
extern "C" SDI_API int uSaveAsBmp(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

	long *ymin, *ymax;
	ymin = (long *) argv[2];
	ymax = (long *) argv[3];

	unsigned int errcode;
	errcode = SaveAsBmp((char *) argv[0], (char *) argv[1], *ymin, *ymax);
	return errcode;
}

//SAVE AS TIFF
// calling seq: (char* path, char* palette, long position, long type)
extern "C" SDI_API int uSaveAsTiff(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

	long *position, *type;
	position = (long *) argv[2];
	type = (long *) argv[3];

	unsigned int errcode;
	errcode = SaveAsTiff((char *) argv[0], (char *) argv[1], *position, *type);
	return errcode;
}


//SET ACCUMULATION CYCLE TIME
// calling seq: (float time)
extern "C" SDI_API int uSetAccumulationCycleTime(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	float *time;
	time = (float *) argv[0];

	unsigned int errcode;
	errcode = SetAccumulationCycleTime(*time);
	return errcode;
}


//SET ACQUISITION MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetAcquisitionMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetAcquisitionMode(*mode);
	return errcode;
}


//SET AD CHANNEL
// calling seq: (int channel)
extern "C" SDI_API int uSetADChannel(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *channel;
	channel = (int *) argv[0];

	unsigned int errcode;
	errcode = SetADChannel(*channel);
	return errcode;
}


//SET BASELINE CLAMP
// calling seq: (int active)
extern "C" SDI_API int uSetBaselineClamp(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *active;
	active = (int *) argv[0];

	unsigned int errcode;
	errcode = SetBaselineClamp(*active);
	return errcode;
}


//SET COOLER MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetCoolerMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetCoolerMode(*mode);
	return errcode;
}


//SET CURRENT CAMERA
// calling seq: (long camera handle)
extern "C" SDI_API int uSetCurrentCamera(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	long *handle;
	handle = (long *) argv[0];

	unsigned int errcode;
	errcode = SetCurrentCamera(*handle);
	return errcode;
}


//SET CUSTOM TRACK HBIN
// calling seq: (int bin)
extern "C" SDI_API int uSetCustomTrackHBin(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *bin;
	bin = (int *) argv[0];

	unsigned int errcode;
	errcode = SetCustomTrackHBin(*bin);
	return errcode;
}


//SET DDG GAIN
// calling seq: (int gain)
extern "C" SDI_API int uSetDDGGain(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *gain;
	gain = (int *) argv[0];

	unsigned int errcode;
	errcode = SetDDGGain(*gain);
	return errcode;
}


//SET DDG GATE SETUP
// calling seq: (double step)
extern "C" SDI_API int uSetDDGGateStep(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	double *step;
	step = (double *) argv[0];

	unsigned int errcode;
	errcode = SetDDGGateStep(*step);
	return errcode;
}


//SET DDG INSERTION DELAY
// calling seq: (int delay)
extern "C" SDI_API int uSetDDGInsertionDelay(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *delay;
	delay = (int *) argv[0];

	unsigned int errcode;
	errcode = SetDDGInsertionDelay(*delay);
	return errcode;
}


//SET DDG INTELLIGATE
// calling seq: (int gating)
extern "C" SDI_API int uSetDDGIntelligate(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *gating;
	gating = (int *) argv[0];

	unsigned int errcode;
	errcode = SetDDGIntelligate(*gating);
	return errcode;
}


//SET DDG IOC
// calling seq: (int integrate)
extern "C" SDI_API int uSetDDGIOC(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *integrate;
	integrate = (int *) argv[0];

	unsigned int errcode;
	errcode = SetDDGIOC(*integrate);
	return errcode;
}


//SET DG IOC FREQUENCY
// calling seq: (double frequency)
extern "C" SDI_API int uSetDDGIOCFrequency(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	double *frequency;
	frequency = (double *) argv[0];

	unsigned int errcode;
	errcode = SetDDGIOCFrequency(*frequency);
	return errcode;
}


//SET DDG TIMES
// calling seq: (double T0, double T1, double T2)
extern "C" SDI_API int uSetDDGTimes(int argc, void *argv[])
{
	if (argc != 3) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "3 Parameters Required");
		return 0;
	}

	double *t1, *t2, *t3;
	t1 = (double *) argv[0];
	t2 = (double *) argv[1];
	t3 = (double *) argv[2];

	unsigned int errcode;
	errcode = SetDDGTimes(*t1, *t2, *t3);
	return errcode;
}


//SET DDG TRIGGER MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetDDGTriggerMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetDDGTriggerMode(*mode);
	return errcode;
}


//SET DDG VARIABLE GATE STEP
// calling seq: (int mode, double a, double b)
extern "C" SDI_API int uSetDDGVariableGateStep(int argc, void *argv[])
{
	if (argc != 3) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "3 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	double *a, *b;
	a = (double *) argv[1];
	b = (double *) argv[2];

	unsigned int errcode;
	errcode = SetDDGVariableGateStep(*mode, *a, *b);
	return errcode;
}


//SET DELAY GENERATOR
// calling seq: (int board, short address, int type)
extern "C" SDI_API int uSetDelayGenerator(int argc, void *argv[])
{
	if (argc != 3) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "3 Parameters Required");
		return 0;
	}

	int *board, *type;
	board = (int *) argv[0];
	type = (int *) argv[2];

	short *address;
	address = (short *) argv[1];

	unsigned int errcode;
	errcode = SetDelayGenerator(*board, *address, *type);
	return errcode;
}


//SET DMA PARAMETERS
// calling seq: (int max images/dma, float seconds/dma)
extern "C" SDI_API int uSetDMAParameters(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *maxims;
	maxims = (int *) argv[0];

	float *secs;
	secs = (float *) argv[1];

	unsigned int errcode;
	errcode = SetDMAParameters(*maxims, *secs);
	return errcode;
}


//SET DRIVER EVENT
// calling seq: (HANDLE event)


//SET EMCCD GAIN
// calling seq: (int gain)
extern "C" SDI_API int uSetEMCCDGain(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *gain;
	gain = (int *) argv[0];

	unsigned int errcode;
	errcode = SetEMCCDGain(*gain);
	return errcode;
}

//SET EMCCD GAIN MODE
extern "C" SDI_API int uSetEMGainMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetEMGainMode(*mode);
	return errcode;
}

//SET EM SDVANCED
extern "C" SDI_API int uSetEMAdvanced(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetEMAdvanced(*mode);
	return errcode;
}

//SET EXPOSURE TIME
// calling seq: (float time)
extern "C" SDI_API int uSetExposureTime(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	float *time;
	time = (float *) argv[0];

	unsigned int errcode;
	errcode = SetExposureTime(*time);
	return errcode;
}


//SET FAN MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetFanMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetFanMode(*mode);
	return errcode;
}


//SET FAST KINETICS
// calling seq: (int height, int series, float exptime, int mode, int dummy1, int dummy2)
extern "C" SDI_API int uSetFastKinetics(int argc, void *argv[])
{
	if (argc != 6) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "6 Parameters Required");
		return 0;
	}

	int *height, *series, *mode, *dummy1, *dummy2;
	height = (int *) argv[0];
	series = (int *) argv[1];
	mode = (int *) argv[3];
	dummy1 = (int *) argv[4];
	dummy2 = (int *) argv[5];

	float *exptime;
	exptime = (float *) argv[2];

	unsigned int errcode;
	errcode = SetFastKinetics(*height, *series, *exptime, *mode, *dummy1, *dummy2);
	return errcode;
}


//SET FAST KINETICS EX
// calling seq: (int height, int series, float exptime, int mode, int hbin, int vbin, int offset)
extern "C" SDI_API int uSetFastKineticsEx(int argc, void *argv[])
{
	if (argc != 7) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "7 Parameters Required");
		return 0;
	}

	int *height, *series, *mode, *hbin, *vbin, *offset;
	height = (int *) argv[0];
	series = (int *) argv[1];
	mode = (int *) argv[3];
	hbin = (int *) argv[4];
	vbin = (int *) argv[5];
	offset = (int *) argv[6];

	float *exptime;
	exptime = (float *) argv[2];

	unsigned int errcode;
	errcode = SetFastKineticsEx(*height, *series, *exptime, *mode, *hbin, *vbin, *offset);
	return errcode;
}


//SET FAST EXT TRIGGER
// calling seq: (int mode)
extern "C" SDI_API int uSetFastExtTrigger(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetFastExtTrigger(*mode);
	return errcode;
}


//SET FILTER MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetFilterMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetFilterMode(*mode);
	return errcode;
}


//SET FKV SHIFT SPEED
// calling seq: (int index)
extern "C" SDI_API int uSetFKVShiftSpeed(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];

	unsigned int errcode;
	errcode = SetFKVShiftSpeed(*index);
	return errcode;
}


//SET FRAME TRANSFER MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetFrameTransferMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetFrameTransferMode(*mode);
	return errcode;
}


//SET FVB HBIN
// calling seq: (int bin)
extern "C" SDI_API int uSetFVBHBin(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *bin;
	bin = (int *) argv[0];

	unsigned int errcode;
	errcode = SetFVBHBin(*bin);
	return errcode;
}


//SET GAIN
// calling seq: (int gain)
extern "C" SDI_API int uSetGain(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *gain;
	gain = (int *) argv[0];

	unsigned int errcode;
	errcode = SetGain(*gain);
	return errcode;
}


//SET GATE
// calling seq: (float delay, float width, float step)
extern "C" SDI_API int uSetGate(int argc, void *argv[])
{
	if (argc != 3) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "3 Parameters Required");
		return 0;
	}

	float *delay, *width, *step;
	delay = (float *) argv[0];
	width = (float *) argv[1];
	step = (float *) argv[2];

	unsigned int errcode;
	errcode = SetGate(*delay, *width, *step);
	return errcode;
}


//SET GATE MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetGateMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetGateMode(*mode);
	return errcode;
}


//SET HIGH CAPACITY
// calling seq: (int state)
extern "C" SDI_API int uSetHighCapacity(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *state;
	state = (int *) argv[0];

	unsigned int errcode;
	errcode = SetHighCapacity(*state);
	return errcode;
}


//SET HS SPEED
// calling seq: (int type, int index)
extern "C" SDI_API int uSetHSSpeed(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *type, *index;
	type = (int *) argv[0];
	index = (int *) argv[1];

	unsigned int errcode;
	errcode = SetHSSpeed(*type, *index);
	return errcode;
}


//SET IMAGE
// calling seq: (int hbin, int vbin, int hstart, int hend, int vstart, int vend)
extern "C" SDI_API int uSetImage(int argc, void *argv[])
{
	if (argc != 6) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "6 Parameters Required");
		return 0;
	}


	int *hstart, *hend, *vstart, *vend;
	int *hbin, *vbin;
	hbin = (int *) argv[0];
	vbin = (int *) argv[1];
	hstart = (int *) argv[2];
	hend = (int *) argv[3];
	vstart = (int *) argv[4];
	vend = (int *) argv[5];

	unsigned int errcode;
	errcode = SetImage(*hbin, *vbin, *hstart, *hend, *vstart, *vend);
	return errcode;
}


//SET KINETIC CYCLE TIME
// calling seq: (float time)
extern "C" SDI_API int uSetKineticCycleTime(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	float *time;
	time = (float *) argv[0];

	unsigned int errcode;
	errcode = SetKineticCycleTime(*time);
	return errcode;
}


//SET MCP GATING
// calling seq: (int gating)
extern "C" SDI_API int uSetMCPGating(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *gating;
	gating = (int *) argv[0];

	unsigned int errcode;
	errcode = SetMCPGating(*gating);
	return errcode;
}


//SET MULTITRACK
// calling seq: (int number, int height, int offset, int* bottom, int* gap)
extern "C" SDI_API int uSetMultiTrack(int argc, void *argv[])
{
	if (argc != 5) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "5 Parameters Required");
		return 0;
	}

	int *number, *height, *offset, *bottom, *gap;
	number = (int *) argv[0];
	height = (int *) argv[1];
	offset = (int *) argv[2];
	bottom = (int *) argv[3];
	gap = (int *) argv[4];

	unsigned int errcode;
	errcode = SetMultiTrack(*number, *height, *offset, bottom, gap);
	return errcode;
}


//SET MULTITRACK HBIN
// calling seq: (int bin)
extern "C" SDI_API int uSetMultiTrackHBin(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *bin;
	bin = (int *) argv[0];

	unsigned int errcode;
	errcode = SetMultiTrackHBin(*bin);
	return errcode;
}


//SET NEXT ADDRESS
// calling seq: (long* data, long low, long high, long size, long type)
extern "C" SDI_API int uSetNextAddress(int argc, void *argv[])
{
	if (argc != 5) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "5 Parameters Required");
		return 0;
	}

	long *data, *low, *high, *size, *type;
	data = (long *) argv[0];
	low = (long *) argv[1];
	high = (long *) argv[2];
	size = (long *) argv[3];
	type = (long *) argv[4];

	unsigned int errcode;
	errcode = SetNextAddress(data, *low, *high, *size, *type);
	return errcode;
}


//SET NUMBER ACCUMULATIONS
// calling seq: (int number)
extern "C" SDI_API int uSetNumberAccumulations(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *num;
	num = (int *) argv[0];

	unsigned int errcode;
	errcode = SetNumberAccumulations(*num);
	return errcode;
}


//SET NUMBER KINETICS
// calling seq: (int number)
extern "C" SDI_API int uSetNumberKinetics(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *num;
	num = (int *) argv[0];

	unsigned int errcode;
	errcode = SetNumberKinetics(*num);
	return errcode;
}


//SET OUTPUT AMPLIFIER
// calling seq: (int type)
extern "C" SDI_API int uSetOutputAmplifier(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *type;
	type = (int *) argv[0];

	unsigned int errcode;
	errcode = SetOutputAmplifier(*type);
	return errcode;
}


//SET PHOTON COUNTING
// calling seq: (int state)
extern "C" SDI_API int uSetPhotonCounting(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *state;
	state = (int *) argv[0];

	unsigned int errcode;
	errcode = SetPhotonCounting(*state);
	return errcode;
}


//SET PHOTON COUNTING THRESHOLD
// calling seq: (long min, long max)
extern "C" SDI_API int uSetPhotonCountingThreshold(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	long *min, *max;
	min = (long *) argv[0];
	max = (long *) argv[1];

	unsigned int errcode;
	errcode = SetPhotonCountingThreshold(*min, *max);
	return errcode;
}


//SET PRE AMP GAIN
// calling seq: (int index)
extern "C" SDI_API int uSetPreAmpGain(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];

	unsigned int errcode;
	errcode = SetPreAmpGain(*index);
	return errcode;
}


//SET RANDOM TRACKS
// calling seq: (int number, int* tracks)
extern "C" SDI_API int uSetRandomTracks(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *num, *tracks;
	num = (int *) argv[0];
	tracks = (int *) argv[1];

	unsigned int errcode;
	errcode = SetRandomTracks(*num, tracks);
	return errcode;
}


//SET READ MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetReadMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetReadMode(*mode);
	return errcode;
}


//SET SHUTTER
// calling seq: (int type, int mode, int closingtime, int openingtime)
extern "C" SDI_API int uSetShutter(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

	int *type, *mode, *ctime, *otime;
	type = (int *) argv[0];
	mode = (int *) argv[1];
	ctime = (int *) argv[2];
	otime = (int *) argv[3];

	unsigned int errcode;
	errcode = SetShutter(*type, *mode, *ctime, *otime);
	return errcode;
}


//SET SINGLE TRACK
// calling seq: (int centre, int height)
extern "C" SDI_API int uSetSingleTrack(int argc, void *argv[])
{
	if (argc != 2) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "2 Parameters Required");
		return 0;
	}

	int *centre, *height;
	centre = (int *) argv[0];
	height = (int *) argv[1];

	unsigned int errcode;
	errcode = SetSingleTrack(*centre, *height);
	return errcode;
}


//SET SINGLE TRACK HBIN
// calling seq: (int bin)
extern "C" SDI_API int uSetSingleTrackHBin(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *bin;
	bin = (int *) argv[0];

	unsigned int errcode;
	errcode = SetSingleTrackHBin(*bin);
	return errcode;
}


//SET SPOOL
// calling seq: (int active, int method, char* name, int frame buffer size)
extern "C" SDI_API int uSetSpool(int argc, void *argv[])
{
	if (argc != 4) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "4 Parameters Required");
		return 0;
	}

	int *active, *method, *fbsize;
	active = (int *) argv[0];
	method = (int *) argv[1];
	fbsize = (int *) argv[3];

	unsigned int errcode;
	errcode = SetSpool(*active, *method, (char *) argv[2], *fbsize);
	return errcode;
}


//SET STORAGE MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetStorageMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetStorageMode(*mode);
	return errcode;
}


//SET TEMPERATURE
// calling seq: (int temp)
extern "C" SDI_API int uSetTemperature(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}


	int *temp;
	temp = (int *) argv[0];

	unsigned int errcode = 0;
	errcode = SetTemperature(*temp);
	return errcode;
}


//SET TRIGGER MODE
// calling seq: (int mode)
extern "C" SDI_API int uSetTriggerMode(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *mode;
	mode = (int *) argv[0];

	unsigned int errcode;
	errcode = SetTriggerMode(*mode);
	return errcode;
}


//SET VS AMPLITUDE
// calling seq: (int amplitude)
extern "C" SDI_API int uSetVSAmplitude(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *amp;
	amp = (int *) argv[0];

	unsigned int errcode;
	errcode = SetVSAmplitude(*amp);
	return errcode;
}


//SET VS SPEED
// calling seq: (int index)
extern "C" SDI_API int uSetVSSpeed(int argc, void *argv[])
{
	if (argc != 1) {
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, "1 Parameters Required");
		return 0;
	}

	int *index;
	index = (int *) argv[0];

	unsigned int errcode;
	errcode = SetVSSpeed(*index);
	return errcode;
}


//SHUTDOWN
// takes no arguments
extern "C" SDI_API int uShutDown(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = ShutDown();
	return errcode;
}


//START ACQUISITION
// takes no arguments
extern "C" SDI_API int uStartAcquisition(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = StartAcquisition();
	return errcode;
}


//UNMAP PHYSICAL ADDRESS
// takes no arguments
extern "C" SDI_API int uUnMapPhysicalAddress(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = UnMapPhysicalAddress();
	return errcode;
}


//WAIT FOR ACQUISITION
// takes no arguments
extern "C" SDI_API int uWaitForAcquisition(int argc, void *argv[])
{
	unsigned int errcode;
	errcode = WaitForAcquisition();
	return errcode;
}


///////// THE SERIAL PORT STUFF WAS TAKEN FROM THE CAMERADLL CODE /////////

// global list of port handles
static HANDLE ports [10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// Sets up a comm port for serial communications
// IDL Calling sequence
//   Port = 0L & IniStr = "COM1: baud=1200 parity=N data=8 stop=1"
//   CALL_EXTERNAL ("CameraDLL.dll", "OpenPort", Port, IniStr, /UL_Value)
extern "C" SDI_API unsigned int uOpenPort (int argc, void *argv [])
{


		char msg_buffer[100];
		int *Port;
        IDL_STRING *IniStr;
        DCB dcb;
        dcb.DCBlength = sizeof (dcb);

        if (argc < 2)
        {
                sprintf(msg_buffer, "Error in ClosePort:  1 argument expected, %d arguments sent", argc);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return (unsigned int )(0x80000001);
        }

		// get the pointer to our port number (1 - 9) and it's init string
        Port = (int *) argv [0];
		IniStr = (IDL_STRING *)argv [1];

        // close the port if it was already opened
        if (ports [*Port - 1] != NULL)
        {

			sprintf(msg_buffer, "Port %d already opened.  Closing it...", *Port);
			IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

			    ::CloseHandle (ports [*Port - 1]);
                ports [*Port - 1] = INVALID_HANDLE_VALUE;
        }

        char pname[4];
        sprintf(pname, "COM%d", *Port);

		// now open the port and save its file handle
        ports [*Port - 1] = CreateFile (pname,
                GENERIC_READ | GENERIC_WRITE,
                0,    // comm devices must be opened w/exclusive-access
                NULL, // no security attributes
                OPEN_EXISTING, // comm devices must use OPEN_EXISTING
                0,    // not overlapped I/O
                NULL  // hTemplate must be NULL for comm devices
                );

        // make sure the port opened properly
        if (ports [*Port - 1] == INVALID_HANDLE_VALUE)
        {
                ports [*Port - 1] = NULL;
        void *buf;
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                      FORMAT_MESSAGE_FROM_SYSTEM |
                      FORMAT_MESSAGE_IGNORE_INSERTS,
                      NULL,GetLastError(),0,
                      (LPTSTR) &buf,0,NULL);

        MessageBox(NULL, (LPTSTR)buf, NULL, MB_OK | MB_ICONINFORMATION);
                DWORD err = ::GetLastError ();

				sprintf(msg_buffer, "Unable to open port %d.  Error: %s", *Port, (LPTSTR)buf);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);



// Free the buffer
        LocalFree(buf);
                return err;
        }

        // get a starting dcb
        if (!::GetCommState (ports [*Port - 1], &dcb))
        {
                DWORD dwerr = ::GetLastError ();
                ::CloseHandle (ports [*Port - 1]);
                ports [*Port - 1] = NULL;

				sprintf(msg_buffer, "Unable to get current state for port %d.  Error: %X", *Port, dwerr);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

				return dwerr;
        }

        // build a dcb based on the transmitted string
        if (!::BuildCommDCB (IniStr->s, &dcb))
		{
                DWORD dwerr = ::GetLastError ();
                ::CloseHandle (ports [*Port - 1]);
                ports [*Port - 1] = NULL;

				sprintf(msg_buffer, "Unable to build DCB for port %d.  Error: %X", *Port, dwerr);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return dwerr;
        }

		sprintf(msg_buffer, "Init string is \"%s\"", IniStr->s);
		IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

        // and set the information for the port
        if (!::SetCommState (ports [*Port - 1], &dcb))
        {
                DWORD dwerr = ::GetLastError ();
                ::CloseHandle (ports [*Port - 1]);
                ports [*Port - 1] = NULL;

				sprintf(msg_buffer, "Unable to set state for port %d.  Error: %X", *Port, dwerr);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

				return dwerr;
        }

        return 0;
}


// Closes a comm port
// IDL Calling sequence
//   Port = 0L
//   CALL_EXTERNAL ("CameraDLL.dll", "ClosePort", Port, /UL_Value)
extern "C" SDI_API unsigned int uClosePort (int argc, void *argv [])
{


		char msg_buffer[100];

		int *Port;

        if (argc < 1)
        {
				sprintf(msg_buffer, "Error in ClosePort:  1 argument expected, %d arguments sent", argc);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return (unsigned int )(0x80000001);             // error return for illegal number of arguments
        }

        // Get our port number (1 - 9)
        Port = (int *)argv [0];

        // Check that the port was open to begin with
        if (ports [*Port - 1] == NULL)
        {

				sprintf(msg_buffer, "Error in ClosePort:  Port %d has not been opened.", *Port);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

		        return 0x80000002;                              // error return for unopened port
        }

        // Now close the port
        if (!::CloseHandle (ports [*Port - 1]))
        {
                DWORD err = ::GetLastError ();

				sprintf(msg_buffer, "Error in ClosePort:  Could not close port %d.  Error is %X.", *Port, err);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

			    return err;
        }

        // Now set it to NULL so we can tell it was closed in the future
        ports [*Port - 1] = NULL;


        return 0;
}


// Writes a string out to a comm port
// IDL Calling sequence
//   Port = 0L & WrStr = "This goes out the port" & MSDelay = 300
//   CALL_EXTERNAL ("CameraDLL.dll", "WritePort", Port, WrStr, [MSDelay,] /UL_Value)
extern "C" SDI_API unsigned int uWritePort (int argc, void *argv [])
{

		char msg_buffer[100];
		int *Port;                              // port number to write to
        IDL_STRING *WrStr;                      // string to write
        short *MSDelay;                         // delay in milliseconds between characters
        DWORD bw;                               // number of bytes written

        if (argc < 2)
        {

			sprintf(msg_buffer, "Error in WritePort:  2 arguments expected, %d arguments sent", argc);
			IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

			return (unsigned int )(0x80000001);             // error return for illegal number of arguments
        }

        // get our port number (1 - 9), the string to be written, and the delay, if necessary
        Port = (int *)argv [0];
        WrStr = (IDL_STRING *)argv [1];
        if (argc > 2) MSDelay = (short *)argv [2];
        else MSDelay = NULL;

        // make sure the port has been opened
        if (ports [*Port - 1] == NULL)
        {
                sprintf(msg_buffer, "Error in WritePort:  Port %d has not been opened.", *Port);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return 0x80000002;                              // error return for unopened port
        }

        if (MSDelay)
        {
                // now write the string character at a time with MSDelay between
                for (int i = 0; i < WrStr->slen; ++i)
                {
                        if (!WriteFile (ports [*Port - 1], WrStr->s + i, 1, &bw, NULL))
                        {
                                DWORD err = ::GetLastError ();

								sprintf(msg_buffer, "Unable to write with delay to port %d.  Error is %X.", *Port, err);
								IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                                return err;
                        }
                        ::Sleep (*MSDelay);                     // sleep for this long
                }
        }
        else
        {
                // now write the string all at once
                if (!WriteFile (ports [*Port - 1], WrStr->s, WrStr->slen, &bw, NULL))
                {
                                DWORD err = ::GetLastError ();

								sprintf(msg_buffer, "Unable to write string to port %d.  Error is %X.", *Port, err);
								IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                                return err;
                        return ::GetLastError ();
                }
        }
        ::Sleep (65);
        return 0;
}


// Checks a comm port for new data
// IDL Calling sequence
//   Port = 0L & BytesWaiting = 0UL
//   CALL_EXTERNAL ("CameraDLL.dll", "CheckPort", Port, BytesWaiting, /UL_Value)
extern "C" SDI_API unsigned int uCheckPort (int argc, void *argv [])
{


		char msg_buffer[100];
		int *Port;
        unsigned int *BytesWaiting;
        DWORD lpErrors;
        COMSTAT lpStat;

        if (argc < 2)
        {

				sprintf(msg_buffer, "Error in CheckPort:  2 arguments expected, %d arguments sent", argc);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return (unsigned int )(0x80000001);             // error return for illegal number of arguments
        }

        // Get our port number (1 - 9) and a place to store the bytes waiting
        Port = (int *)argv [0];
        BytesWaiting = (unsigned int *)argv [1];

        // Check that the port was open to begin with
        if (ports [*Port - 1] == NULL)
        {

				sprintf(msg_buffer, "Error in CheckPort:  Port %d has not been opened.", *Port);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return 0x80000002;                              // error return for unopened port
        }

        // Try to read the status
        if(::ClearCommError(ports [*Port - 1], &lpErrors, &lpStat) == 0)
        {
                return ::GetLastError ();                               // error return for broken windows
        }

        *BytesWaiting = lpStat.cbInQue;
        return 0;
}


// Reads a string from a comm port
// IDL Calling sequence
//   Port = 0L & RdStr = "Something with enough bytes to handle our input" & ReadBytes = 0L
//   CALL_EXTERNAL ("CameraDLL.dll", "ReadPort", Port, ReadBYtes, RdStr, /UL_Value)
extern "C" SDI_API unsigned int uReadPort (int argc, void *argv [])
{

		char msg_buffer[100];
		int *Port;
        IDL_STRING *RdStr;
        int *ReadBytes;
        DWORD bw;

        if (argc < 3)
        {

				sprintf(msg_buffer, "Error in ReadPort:  3 arguments expected, %d arguments sent", argc);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return (unsigned int )(0x80000001);             // error return for illegal number of arguments
        }

        // get our port number (1 - 9), the number of bytes to read, and the string to put it in
        Port = (int *)argv [0];
        ReadBytes = (int *)argv [1];
        RdStr = (IDL_STRING *)argv [2];

        // make sure the port has been opened
        if (ports [*Port - 1] == NULL)
        {
                sprintf(msg_buffer, "Error in ReadPort:  Port %d has not been opened.", *Port);
				IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, msg_buffer);

                return 0x80000002;                              // error return for unopened port
        }

        // now read the string all at once
        if (!ReadFile (ports [*Port - 1], RdStr->s, *ReadBytes, &bw, NULL))
        {
                return ::GetLastError ();
        }

        return 0;
}


///////////// END OF SERIAL COMMUNICATIONS STUFF /////////////////////////////



/////////////////////////// SPECTRUM BUILDER \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//  This routine builds the spectra from video images. For each pixel that falls in a
//  defined zone (i.e. zone value >= 0), we lookup the corresponding zone and spectral channel.
//  Then, we add the value of the image pixel to the spectral bin for that zone and channel.

extern "C" SDI_API int uUpdateSpectra (int argc, void *argv [])
{
	static short scan, nx, ny, nzones, nchan, chan;
	register short x, y;
	static long ioff, soff, isize, ssize;
	static long *pview;
	static short  *pzone;
	static short *pphase, *psizes;
	static unsigned long *pspex;
 	static char buf[128];

	static short zone;

	pview  =  (long *)argv[0]; // pointer to start of current camera image [x][y] array
	pphase =  (short *)argv[1]; // pointer to start of phase map [x][y] array
	pzone  =  (short *)argv[2]; // pointer to start of zone map [x][y] array
	pspex  =  (unsigned long *)argv[3]; // pointer to start of the array of spectra [nzones][nchan]
	scan   = *(short *)argv[4]; // 16-bit integer specifying the current scan channel
	psizes =  (short *)argv[5]; // pointer to a 4-element array containing size information

	nx     = *(psizes);      // x-size of images
	ny     = *(psizes + 1);  // y-size of images
	nzones = *(psizes + 2);  // number of scan channels per spectrum
	nchan  = *(psizes + 3);  // number of scan channels per spectrum
	isize  = nx*(long)ny;
	ssize  = nzones*(long)nchan;

    char buffer[50];


    for (x=0; x<nx; x++)
		{
		for (y=0; y<ny; y++)
			{
             // ioff = ((long)y)*(long)nx + x; // 1-D offset into the image array corresponding to location x,y

			 ioff = ((long)x)*long(ny) + y;


			if ((*(pzone + ioff)  >= 0) && (ioff >=0 ) && (ioff < isize )) // only accumulate pixels within defined zones
				{
	            chan = scan - *(pphase + ioff); // lookup spectral channel from scan and phase map
		        while (chan <  0)      chan += nchan; // ensure scan channel is positive
		        while (chan >=  nchan) chan -= nchan; // ensure scan channel is positive

                //sprintf(buffer, "%i", chan);
                //IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, buffer);

				soff = (*(pzone + ioff)) + chan*(long)nzones; // 1-D offset into spectra for given zone and channel

				// soff = (*(pzone + ioff))*long(nchan) + chan; - old
				//zone = *(pzone + ioff);

				if (soff >= 0 && (soff < ssize ))
					*(pspex + soff) += *(pview + ioff); // accumulate one image into one spectral bin
				}
			}
		}

	return 1;
}


// ######################################### THIS IS THE MOXA PORT EXPANDER STUFF #########################################


//OPEN COM PORT
extern "C" SDI_API int uMoxaOpenPort(int argc, void *argv[])
{
	int *port;
	int ret;

	port = (int *) argv[0];

	ret = sio_open (*port);

	return ret;
}

//SET CONTROL OPTIONS
extern "C" SDI_API int uMoxaSetIOCTL(int argc, void *argv[])
{
	int *port;
	int *baud;
	int *mode;
	int ret;

    // baud = 0-19
    // 12 = 9600
    // 13 = 19200

	port = (int *) argv[0];
	baud = (int *) argv[1];
	//mode = (int *) argv[2];

	ret = sio_ioctl(*port, *baud, P_NONE | BIT_8 | STOP_1);

	return ret;
}


//SET COM PORT BAUD
extern "C" SDI_API int uMoxaSetPort(int argc, void *argv[])
{

	int *port;
	long *baud;
	int ret;

	port = (int *) argv[0];
	baud = (long *) argv[1];

	ret = sio_baud (*port, *baud);

	return ret;
}


//CLOSE COM PORT
extern "C" SDI_API int uMoxaClosePort(int argc, void *argv[])
{

	int *port;
	int ret;

	port = (int *) argv[0];

	ret = sio_close (*port);

	return ret;
}


//READ COM PORT - reads one character, returned as ascii
extern "C" SDI_API int uMoxaReadPort(int argc, void *argv[])
{

	int *port;
	int ret;

	port = (int *) argv[0];

	ret = sio_getch (*port);

	return ret;
}


//READ COM PORT
extern "C" SDI_API char uMoxaReadAllPort(int argc, void *argv[])
{

	int *port;
	int ret;
	int *len;
	IDL_STRING *str;

	port = (int *) argv[0];
	len = (int *) argv[1];
	str = (IDL_STRING *) argv[2];

	ret = sio_read (*port, str->s, *len);

	return ret;
}

//WRITE COM PORT - writes one character
extern "C" SDI_API int uMoxaWritePort(int argc, void *argv[])
{

	int *port;
	//int *len;
	int ret;
	int *str;
	//IDL_STRING *WrStr;

	port = (int *) argv[0];
	str  = (int *) argv[1];
	//WrStr = (IDL_STRING *) argv[2];

	ret = sio_putch (*port, *str);

	return ret;
}


//WRITE COM PORT
extern "C" SDI_API int uMoxaWriteAllPort(int argc, void *argv[])
{

	int *port;
	int *len;
	int ret;
	int *str;
	IDL_STRING *WrStr;

	port = (int *) argv[0];
	WrStr = (IDL_STRING *) argv[1];

	ret = sio_write (*port, WrStr->s, WrStr->slen);

	return ret;
}

//CHECK COM PORT INPUT BUFFER
extern "C" SDI_API int uMoxaCheckPort(int argc, void *argv[])
{

	int *port;
	int ret;

	port = (int *) argv[0];

	ret = sio_iqueue (*port);

	return ret;
}

//CHECK COM PORT OUTPUT BUFFER
extern "C" SDI_API int uMoxaCheckOutPort(int argc, void *argv[])
{

	int *port;
	int ret;

	port = (int *) argv[0];

	ret = sio_oqueue (*port);

	return ret;
}

//FLUSH BUFFERS (args are: int port, int function( 0 flush input, 1 flush output, 2 flush both))
extern "C" SDI_API int uMoxaFlush(int argc, void *argv[])
{
	int *port;
	int *func;
	int ret;

	port = (int *) argv[0];
	func = (int *) argv[1];

	ret = sio_flush (*port, *func);

	return ret;
}



// AIOUSB ROUTINES

extern "C" SDI_API int uDIO_Config(int argc, void *argv[])
{

	int ret;
	static unsigned long outMask;
	static unsigned char data[4];

	outMask = long(0xFFFFFFFF);
	data[0] = (unsigned char)((unsigned int)argv[0]);
	data[1] = (unsigned char)((unsigned int)argv[1]);
	data[2] = (unsigned char)((unsigned int)argv[2]);
	data[3] = (unsigned char)((unsigned int)argv[3]);
	ret = DIO_Configure(diFirst, false, &outMask, data);

	return ret;
}


extern "C" SDI_API int uDIO_Write8(int argc, void *argv[])
{

	static unsigned long *Port;    // port number to write to
	static unsigned char *port_data;
	int ret;
    Port = (unsigned long *) argv [0];
	port_data = (unsigned char *) argv[1];
	ret = DIO_Write8(diFirst, *Port, *port_data);
	return ret;
}

extern "C" SDI_API int uDIO_WriteAll(int argc, void *argv[])
{

	static char buf[128];
	static unsigned char data[4];
	data[0] = (unsigned char)((unsigned int)argv[0]);
	data[1] = (unsigned char)((unsigned int)argv[1]);
	data[2] = (unsigned char)((unsigned int)argv[2]);
	data[3] = (unsigned char)((unsigned int)argv[3]);

	int ret;
	ret = DIO_WriteAll(diFirst, data);
//	sprintf(buf, "%i, %i, %i, %i", data[0], data[1], data[2], data[3]);
//	IDL_Message(IDL_M_GENERIC, IDL_MSG_INFO, buf);
	return ret;
}
