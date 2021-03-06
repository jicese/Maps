/*
 * Copyright 2016-2017 Raefaldhi Amartya Junior <raefaldhiamartya@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#ifndef MAPSVIEW_H
#define MAPSVIEW_H

#include <vector>

#include <View.h>
#include <Bitmap.h>
#include <UrlRequest.h>
#include <UrlProtocolRoster.h>
#include <UrlProtocolListener.h>

#include "VirtualScroller.h"

const uint32 kSetMapLocation = 'omap';

const uint8 kPersonIcon[] = {
	0x6e, 0x63, 0x69, 0x66, 0x08, 0x05, 0x00, 0x02, 0x00, 0x06, 0x02, 0x3c,
	0xad, 0xf4, 0x3d, 0x10, 0x4e, 0xbf, 0x02, 0xca, 0x3e, 0xa2, 0x22, 0x4a,
	0xf0, 0x20, 0x46, 0x64, 0x8d, 0x00, 0xff, 0xdb, 0x97, 0xff, 0xfc, 0xaf,
	0x29, 0x02, 0x00, 0x06, 0x02, 0x3a, 0x64, 0x96, 0xba, 0x3f, 0x15, 0x3e,
	0xbc, 0xdd, 0x3e, 0xea, 0x91, 0x46, 0x59, 0x6a, 0x43, 0xb1, 0x57, 0x00,
	0xff, 0xf7, 0xea, 0xfe, 0xfd, 0xd1, 0x7b, 0x02, 0x00, 0x06, 0x02, 0x3a,
	0xb3, 0x67, 0x37, 0x51, 0xb2, 0xbc, 0x59, 0x78, 0x3f, 0xd2, 0xd7, 0x4a,
	0xe3, 0xf1, 0x46, 0xf8, 0x59, 0x00, 0xc8, 0x58, 0x05, 0xff, 0xf0, 0x63,
	0x06, 0x02, 0x01, 0x06, 0x03, 0x3b, 0xc7, 0x1c, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3b, 0xb6, 0xdb, 0x48, 0xd4, 0x00, 0x45, 0x30, 0x00, 0x00,
	0xf2, 0xf2, 0xf2, 0xab, 0x7d, 0x7a, 0x7a, 0xff, 0xbc, 0xa1, 0x84, 0x04,
	0x01, 0x6c, 0x03, 0xa3, 0x29, 0x04, 0x02, 0x00, 0x06, 0x02, 0x38, 0x8a,
	0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x4a, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x58, 0x04, 0xff, 0xdc, 0x95, 0x2f,
	0x09, 0x0a, 0x0d, 0x2c, 0x32, 0x2c, 0x43, 0x30, 0x47, 0x30, 0x58, 0x34,
	0x5a, 0x36, 0x5a, 0x37, 0xca, 0xb5, 0x3c, 0x5e, 0x44, 0x56, 0x44, 0x4b,
	0x48, 0x47, 0x48, 0x35, 0x35, 0x2c, 0x0a, 0x0b, 0x2c, 0x32, 0x2c, 0x43,
	0x30, 0x47, 0x30, 0x58, 0x34, 0x5a, 0x36, 0x5a, 0x37, 0xca, 0xb5, 0x3c,
	0x5e, 0x3c, 0x4d, 0x40, 0x4d, 0x40, 0x3b, 0x0a, 0x06, 0x2c, 0x32, 0x40,
	0x3b, 0x48, 0x35, 0x3a, 0x34, 0xbf, 0xbf, 0xb9, 0xc5, 0x35, 0x2c, 0x0a,
	0x08, 0x40, 0x4d, 0x3c, 0x4d, 0x3c, 0x5e, 0x44, 0x56, 0x44, 0x4b, 0x48,
	0x47, 0x48, 0x35, 0x40, 0x3b, 0x02, 0x04, 0x3a, 0x22, 0x3e, 0x22, 0x36,
	0x22, 0x32, 0x2a, 0x32, 0x26, 0x32, 0x2e, 0x3a, 0x32, 0x36, 0x32, 0x3e,
	0x32, 0x42, 0x2a, 0x42, 0x2e, 0x42, 0x26, 0x06, 0x07, 0xfe, 0x1b, 0x3c,
	0x60, 0x46, 0x60, 0x41, 0x60, 0x4b, 0x60, 0xc8, 0x04, 0xcb, 0x59, 0xc6,
	0x35, 0xcb, 0x4a, 0xcc, 0x25, 0xcb, 0x81, 0xcb, 0x40, 0xc8, 0xa9, 0xcd,
	0xca, 0xc9, 0x75, 0xc9, 0xb9, 0xc8, 0x2f, 0xc6, 0x91, 0xc7, 0x6b, 0x54,
	0xc8, 0x37, 0xc5, 0x1c, 0xc6, 0x67, 0x46, 0x50, 0x57, 0x0a, 0x04, 0x3c,
	0x4d, 0x3c, 0x53, 0x44, 0x4b, 0x40, 0x4d, 0x0a, 0x03, 0x3a, 0x34, 0x48,
	0x35, 0x40, 0x31, 0x0a, 0x04, 0x34, 0x5a, 0x36, 0x5a, 0x36, 0x4c, 0x34,
	0x4b, 0x0a, 0x0a, 0x05, 0x01, 0x05, 0x00, 0x0a, 0x00, 0x01, 0x00, 0x10,
	0x01, 0x17, 0x84, 0x00, 0x04, 0x0a, 0x01, 0x01, 0x01, 0x00, 0x0a, 0x02,
	0x01, 0x02, 0x00, 0x0a, 0x03, 0x01, 0x03, 0x00, 0x0a, 0x06, 0x01, 0x06,
	0x00, 0x0a, 0x07, 0x01, 0x07, 0x00, 0x0a, 0x00, 0x01, 0x04, 0x10, 0x01,
	0x17, 0x84, 0x00, 0x04, 0x0a, 0x04, 0x01, 0x04, 0x00, 0x0a, 0x03, 0x01,
	0x08, 0x08, 0x15, 0xff
};

enum {
	M_MAPSVIEW_ON_FOCUS = 'mmct',
	M_MAPSVIEW_ATTACHEDTOWINDOW = 'matw'
};

class MapsView : public BView {
public:	
	MapsView();
	virtual ~MapsView();

	void AddHandler(BHandler*);

	virtual void Draw(BRect);
	virtual void MouseDown(BPoint);
	virtual void MouseUp(BPoint);
	virtual void MouseMoved(BPoint, uint32, const BMessage*);
	virtual void FrameResized(float, float);
	virtual void MessageReceived(BMessage*);
private:
	BBitmap* bitmap;

	VirtualScroller* virtualScroller;

	bool IsMouseDown;
	bool IsTransformNext;
	BPoint translatePoint;
	BPoint pastPoint;
	
	std::vector<BHandler*> handler;
};

#endif // MAPSVIEW_H
