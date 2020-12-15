/**
 * \file Snowblower.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Snowblower.h"
#include "Sink.h"

#include <vector>

/// Average amount of snow created per rotation
const double SnowPerRotation = 1000;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.169;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 100;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 90;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 110;

using namespace std;

/** Constructor */
CSnowblower::CSnowblower() : CComponent()
{
    mSink.SetComponent(this);

    std::random_device rd;	// Generates a random seed
    mRandom.seed(rd());		// Seed the random number generator
}

/** Destructor */
CSnowblower::~CSnowblower()
{
}

/** Draw the component
 * \param graphics Graphics object to draw on
 * \param x X Location of the on screen machine
 * \param y Y Location of the on screen machine
 */
void CSnowblower::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    for (auto snow : mSnow)
    {
        snow.Draw(graphics, x, y);
    }
    CComponent::Draw(graphics, x, y);
}

/** Set the rotation of the component
 * \param rotation Rotation in turns, where 0-1 is one revolution. */
void CSnowblower::SetRotation(double rotation)
{
    if (mRotated)
    {
        CComponent::SetRotation(rotation);
        mRotated = false;
    }
    mDeltaRotation = rotation - mPrevRotation;
    mPrevRotation = rotation;
}

/** Update the snow
 * \param time The time */
void CSnowblower::UpdateSnow(double time)
{
    // Delete snow in the list that is out of bounds
    DeleteSnow();

    // Update the snow already in our list
    for (auto snowIt = mSnow.begin(); snowIt != mSnow.end(); ++snowIt)
    {
        auto snow = snowIt;
        snow->Update(time);
    }

    // Compute how much snow to generate for this amount of rotation.
    auto num = (int)(mDeltaRotation * (SnowPerRotation + Random(-SnowVariancePerSecond, SnowVariancePerSecond)));
    num = (num >= 10) ? 10 : num;
    for (int i = 0; i < num; i++)
    {
        AddSnow();
    }
}

/**
 * Generate a uniform distribution random number from fmValue to toValue
 * \param fmValue Minimum value to generate
 * \param toValue Maximum value to generate
 * \return Random number
 */
double CSnowblower::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}

/** Add snow to the list */
void CSnowblower::AddSnow()
{
    CSnow snow;

    // GetRotation gets the rotation of the snow machine.
    // This code computes a vector to the emitting end of the
    // snow machine. The random value means that position is over
    // the entire end of the machine, not just a single point.
    auto angle = GetRotation() * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
    auto dx = sin(angle);
    auto dy = -cos(angle);


    auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
    auto dx1 = sin(angle1);
    auto dy1 = -cos(angle1);

    double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
    double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);

    Gdiplus::PointF snowPosition((float)(GetX() + dx * offset), (float)(GetY() + dy * offset));
    Gdiplus::PointF snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));

    snow.SetPosition(snowPosition);
    snow.SetVelocity(snowVelocity);

    mSnow.push_back(snow);
}

/** Delete the snow from the list */
void CSnowblower::DeleteSnow()
{
    vector<list<CSnow>::iterator> deleteThisShit;
    for (auto snowIt = mSnow.begin(); snowIt != mSnow.end(); ++snowIt)
    {
        auto snow = snowIt;
        if (snow->GetPosition().Y > -50)
            deleteThisShit.push_back(snowIt);
    }

    for (auto ass : deleteThisShit)
    {
        mSnow.erase(ass);
    }
}
