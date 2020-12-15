/**
 * \file Snow.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Snow.h"

using namespace Gdiplus;

/// Gravity in pixels per second per second
const float Gravity = 15;

/** Constructor */
CSnow::CSnow()
{
}

/** Destructor */
CSnow::~CSnow()
{
}

/** Update the snow
 * \param delta The change in time */
void CSnow::Update(double delta)
{
    mV = PointF(mV.X, mV.Y + Gravity * (float)delta);
    mP = PointF(mP.X + mV.X * (float)delta, mP.Y + mV.Y * (float)delta);
}

/** Draw the snow
 * \param graphics Graphics object to draw on
 * \param x X Location of the on screen machine
 * \param y Y Location of the on screen machine
 */
void CSnow::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    // TODO figure out what x and y are
    SolidBrush brush(Color::White);
    graphics->FillRectangle(&brush, (int)mP.X + x, (int)mP.Y + y, 2, 2);
}
