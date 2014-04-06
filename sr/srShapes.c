// Software Rasteriser
// Copyright (c) David Avedissian 2014
#include "srCommon.h"
#include "srFrameBuffer.h"
#include "srShapes.h"

void srDrawLine(int x1, int y1, int x2, int y2, int colour)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int dxabs = abs(dx);
	int dyabs = abs(dy);
	int sdx = SR_SGN(dx);
	int sdy = SR_SGN(dy);
	int x = dyabs >> 1;
	int y = dxabs >> 1;
	int px = x1;
	int py = y1;

	srDrawPixel(px, py, colour);
	if (dxabs >= dyabs) // the line is more horizontal than vertical
	{
		for (int i = 0; i < dxabs; ++i)
		{
			y += dyabs;
			if (y >= dxabs)
			{
				y -= dxabs;
				py += sdy;
			}
			px += sdx;
			srDrawPixel(px, py, colour);
		}
	}
	else // the line is more vertical than horizontal
	{
		for (int i = 0; i < dyabs; i++)
		{
			x += dxabs;
			if (x >= dyabs)
			{
				x -= dyabs;
				px += sdx;
			}
			py += sdy;
			srDrawPixel(px, py, colour);
		}
	}
}