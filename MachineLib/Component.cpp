/**
 * \file Component.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Component.h"
#include "MachineImage.h"

using namespace Gdiplus;

/** Destructor */
CComponent::~CComponent()
{
}

/** Default Constructor */
CComponent::CComponent() : CPolygon()
{
}

/** Draw the component
 * \param graphics Graphics object to draw on 
 * \param x X Location of the on screen machine
 * \param y Y Location of the on screen machine
 */
void CComponent::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    DrawPolygon(graphics, mPosition.X+x, mPosition.Y+y);
}

/** Set the time
 * \param time The time */
void CComponent::SetTime(double time)
{
    mTime = time;
}

/** Update the snow
 * \param time The time */
void CComponent::UpdateSnow(double time)
{
}
