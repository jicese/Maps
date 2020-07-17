/*
 * Copyright 2016-2017 Raefaldhi Amartya Junior <raefaldhiamartya@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include <stdio.h>
#include "Maps.h"

Maps::Maps() : BApplication("application/x-vnd.Haiku-Maps") {		
	mapsWindow = new MapsWindow();
	mapsWindow->Show();
}

Maps::~Maps() {
	delete mapsWindow;
}

int main(int argc, char *argv[]) {
	Maps maps;
	maps.Run();
	
	return 0;
}

void Maps::MessageReceived(BMessage* message)
{
	float lon, lat;
	switch(message->what) 
	{
		case B_SET_PROPERTY:
			if(message->FindFloat("longitude", &lon) == B_OK && message->FindFloat("latitude", &lat) == B_OK)
			{
				printf("Got location %f / %f\n", lon, lat);
				mapsWindow->SetLocation(lon, lat);
			}
			break;
				
		default:
			break;
	}
}
