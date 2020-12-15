/**
 * \file MachineImage.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "MachineImage.h"

using namespace std;

/** Constructor */
CMachineImage::CMachineImage()
{
}

/** Destructor */
CMachineImage::~CMachineImage()
{
}

/** Add a component to this machine image
* \param component The component to add
*/
void CMachineImage::AddComponent(shared_ptr<CComponent> component)
{
    mComponentsInOrder.push_back(component);
    component->SetMachineImage(this);
}

/** Draw this machine image
 * \param graphics The Graphics object we are drawing on 
 * \param x X Location of the on screen machine
 * \param y Y Location of the on screen machine
 */
void CMachineImage::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    for (auto component : mComponentsInOrder)
    {
        component->Draw(graphics, x, y);
    }
}

/** Set the Machine time to elapsed time
 * \param elapsedTime The elapsed time */
void CMachineImage::SetTime(double elapsedTime)
{
    for (auto component : mComponentsInOrder)
    {
        component->SetTime(elapsedTime);
    }
}

/** Advance our snow
 * \param elapsedTime The elapsed time */
void CMachineImage::Advance(double elapsedTime)
{
    for (auto component : mComponentsInOrder)
    {
        component->UpdateSnow(elapsedTime);
    }
}
