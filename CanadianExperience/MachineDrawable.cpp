/**
 * \file MachineDrawable.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "MachineDrawable.h"
#include "Timeline.h"

using namespace Gdiplus;

/** Destructor */
CMachineDrawable::~CMachineDrawable()
{
}

/** \brief Constructor
 * \param name The drawable name */
CMachineDrawable::CMachineDrawable(const std::wstring& name) : CDrawable(name)
{
}

/** \brief Draw the drawable
  * \param graphics Graphics object to draw on */
void CMachineDrawable::Draw(Gdiplus::Graphics* graphics)
{
    float scale = 0.8f;

    auto save = graphics->Save();
    graphics->TranslateTransform((float)mPlacedPosition.X,
        (float)mPlacedPosition.Y);
    graphics->ScaleTransform(scale, scale);

    if (mTimeline->GetCurrentFrame() >= mInitialFrame)
        mMachine->SetMachineFrame(mTimeline->GetCurrentFrame() - mInitialFrame);

    mMachine->DrawMachine(graphics);
    graphics->Restore(save);
}

/**
 * \brief Test to see if we clicked on the image.
 * \param pos Position to test
 * \returns True if clicked on
 */
bool CMachineDrawable::HitTest(Gdiplus::Point pos)
{
    return false;
}

/** Set the Machine location
 * \param x The x location
 * \param y The y location */
void CMachineDrawable::SetLocation(int x, int y)
{
    CDrawable::SetPosition(Point(x, y));
    mMachine->SetLocation(x, y);
}
