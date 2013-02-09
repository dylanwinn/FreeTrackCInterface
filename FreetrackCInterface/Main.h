/********************************************************************
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

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