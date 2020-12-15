/**
 * \file MachineActual.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "MachineActual.h"
#include "MachineImage.h"
#include "MachineOneFactory.h"
#include "MachineTwoFactory.h"

using namespace Gdiplus;

/** Constructor */
CMachineActual::CMachineActual()
{
    SetMachineNumber(1);
}

/** Destructor */
CMachineActual::~CMachineActual()
{
}

/**
 * Set the position for the root of the machine
 * \param x X location (pixels)
 * \param y Y location (pixels)
 */
void CMachineActual::SetLocation(int x, int y)
{
    mPosition = Point(x, y);
}

/**
 * Draw the machine at the currently specified location
 * \param graphics GDI+ Graphics object
 */
void CMachineActual::DrawMachine(Gdiplus::Graphics* graphics)
{
    mMachineImage->Draw(graphics, mPosition.X, mPosition.Y);
}

/**
 * Set the current machine animation frame
 * \param frame Frame number
 */
void CMachineActual::SetMachineFrame(int frame)
{
    if (frame < mFrame)
    {
        mFrame = frame;
        mMachineImage->SetTime(mFrame / mFrameRate);
        mMachineImage->Advance(1.0 / mFrameRate);
        return;
    }

    while (frame > mFrame)
    {
        mFrame++;
        mMachineImage->SetTime(mFrame / mFrameRate);
        mMachineImage->Advance(1.0 / mFrameRate);
    }
}

/**
 * Set the machine number
 * \param machine An integer number. Each number makes a different machine
 */
void CMachineActual::SetMachineNumber(int machine)
{
    mMachineNumber = machine;

    CMachineOneFactory factory1;
    CMachineTwoFactory factory2;
    auto machineOneImage = factory1.CreateMachine();
    auto machineTwoImage = factory2.CreateMachine();

    if (machine == 1)
    {
        SetMachineImage(machineOneImage);
    }
    else if (machine == 2)
    {
        SetMachineImage(machineTwoImage);
    }

}

/**
 * Get the current machine number
 * \return Machine number integer
 */
int CMachineActual::GetMachineNumber()
{
    return mMachineNumber;
}
