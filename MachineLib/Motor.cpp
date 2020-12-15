/**
 * \file Motor.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Motor.h"
#include "Source.h"

/** Constructor */
CMotor::CMotor() : CComponent()
{
}

/** Destructor */
CMotor::~CMotor()
{
}

/** Set the time
 * \param time The time */
void CMotor::SetTime(double time)
{
    CComponent::SetTime(time);
    mRotationCount = time;

    //Set the time and set the time for the source and all sinks
    mSource.SetRotation(time);
}

/** Draw the motor component
 * \param graphics Graphics object to draw on 
 * \param x X Location of the on screen machine
 * \param y Y Location of the on screen machine
 */
void CMotor::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    CComponent::Draw(graphics, x, y);
}

/** Set the motor speed
 * \param speed The speed */
void CMotor::SetSpeed(double speed)
{
}

