/*
 * Copyright 2016-2017 Raefaldhi Amartya Junior <raefaldhiamartya@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#ifndef MAPSWINDOW_H
#define MAPSWINDOW_H

#include <Window.h>

class MapsWindow : public BWindow {
public:
	MapsWindow();
	~MapsWindow();
	void SetLocation(float longitude, float latitude);
};

#endif // MAPSWINDOW_H
