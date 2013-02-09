#include <windows.h>
#include <stdio.h>
#include <conio.h>

typedef struct
{
    unsigned long int dataID;
    long int camWidth;
    long int camHeight;

    float yaw;
    float pitch;
    float roll;
    float x;
    float y;
    float z;

    float rawyaw;
    float rawpitch;
    float rawroll;
    float rawx;
    float rawy;
    float rawz;

    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float x4;
    float y4;
}FreeTrackData;

// DLL function signatures
// These match those given in FTTypes.pas
// WINAPI is macro for __stdcall defined somewhere in the depths of windows.h
typedef bool (WINAPI *importGetData)(FreeTrackData * data);
typedef char *(WINAPI *importGetDllVersion)(void);
typedef void (WINAPI *importReportID)(int name);
typedef char *(WINAPI *importProvider)(void);