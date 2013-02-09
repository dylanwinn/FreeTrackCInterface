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

#include "main.h"

int main(int argc, char **argv)
{
	// declare imported function pointers
	importGetData		getData;
	importGetDllVersion	getDllVersion;
	importReportID		reportID;
    importProvider		provider;

    // create variables for exchanging data with the dll
	FreeTrackData	data;
	FreeTrackData	*pData;
	pData =			&data;
	char			*pDllVersion;
	int name =		453;
	char			*pProvider;

	// load DLL file
	HINSTANCE hinstLib = LoadLibrary("FreeTrackClient.dll");
	if (hinstLib == NULL) {
		printf("ERROR: unable to load DLL\n");
		return 1;
	} else {
		printf("dll loaded\n");
	}

	// get function pointers
	getData			= (importGetData)GetProcAddress(hinstLib, "FTGetData");
	getDllVersion	= (importGetDllVersion)GetProcAddress(hinstLib, "FTGetDllVersion");
	reportID		= (importReportID)GetProcAddress(hinstLib, "FTReportName");
	provider		= (importProvider)GetProcAddress(hinstLib, "FTProvider");

	// check they are valid
	if (getData == NULL) {
		printf("ERROR: unable to find 'FTGetData' function\n");
		FreeLibrary(hinstLib);
		return 1;
	}
	if (getDllVersion == NULL) {
		printf("ERROR: unable to find 'FTGetDllVersion' function\n");
		FreeLibrary(hinstLib);
		return 1;
	}
	if (reportID == NULL) {
		printf("ERROR: unable to find 'FTReportID' function\n");
		FreeLibrary(hinstLib);
		return 1;
	}
	if (reportID == NULL) {
		printf("ERROR: unable to find 'FTProvider' function\n");
		FreeLibrary(hinstLib);
		return 1;
	}

	// print the address of each function
	printf("FTGetData is at address: 0x%x\n",getData);
	printf("FTGetDllVersion is at address: 0x%x\n",getDllVersion);
	printf("FTReportID is at address: 0x%x\n",reportID);
	printf("FTProvider is at address: 0x%x\n",provider);

	// call each function and display result
	pDllVersion = getDllVersion();
	printf("Dll Version: %s\n", pDllVersion);

	pProvider = provider();
	printf("Provider: %s\n", pProvider);
        
	system("pause"); // wait till keyboard is pressed before entering main loop
	while (kbhit() != 1) {
		if (getData(pData)) {
			system("cls"); // clear screen
			printf("Record ID: %d\n" , data.dataID);
			printf("Yaw: %5.2f\n" , data.yaw * 100);
			printf("Pitch: %5.2f\n" , data.pitch * 100);
			printf("Roll: %5.2f\n" , data.roll * 100);
			printf("X: %5.2f\n" , data.x );
			printf("Y: %5.2f\n" , data.y );
			printf("Z: %5.2f\n" , data.z );
		}
	}

	// unload DLL file
	FreeLibrary(hinstLib);

	return 0;
}