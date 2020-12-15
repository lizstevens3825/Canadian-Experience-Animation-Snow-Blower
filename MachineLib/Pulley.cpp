/**
 * \file Pulley.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Pulley.h"
#include "Source.h"
#include "Sink.h"

#include <cmath>

using namespace std;
using namespace Gdiplus;

/** Default Constructor */
CPulley::CPulley() : CComponent()
{
    mSink.SetComponent(this);
}

/** Destructor */
CPulley::~CPulley()
{
}

/** Constructor
 * \param radius The radius of the pulley */
CPulley::CPulley(double radius)
{
    mRadius = radius;

    Circle(mRadius);

    mSink.SetComponent(this);
}

/** Set the rotation of the component
 * \param rotation Rotation in turns, where 0-1 is one revolution. */
void CPulley::SetRotation(double rotation)
{    
    if (mOtherPulley)
    {
        rotation = mOtherPulley->GetRotation() * mOtherPulley->GetRadius() / mRadius;
    }
    CPolygon::SetRotation(rotation);
    mSource.SetRotation(rotation);
}

/** Make a connection between pulleys
 * \param pulley The othe pulley  */
void CPulley::Drive(shared_ptr<CPulley> pulley)
{
    mPulley = pulley;
    mPulley->SetOtherPulley(this);
    mSource.AddSink(mPulley->GetSink());
}

/** Draw the component
 * \param graphics Graphics object to draw on 
 * \param x The x position
 * \param y The y position */
void CPulley::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    Pen pen(Color::Black, 1);

    auto saveSM = graphics->GetSmoothingMode();
    graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);

    if (mPulley)
    {
        int r2 = mPulley->GetRadius();
        Gdiplus::Point p1 = GetPosition();
        Gdiplus::Point p2 = mPulley->GetPosition();

        double theta = atan2((p2.Y - p1.Y), (p2.X - p1.X));
        double phi = asin((r2 - mRadius) / sqrt(pow(p2.X - p1.X, 2) + pow(p2.Y - p1.Y, 2)));

        double beta1 = theta + phi + M_PI / 2;
        double beta2 = theta - phi - M_PI / 2;

        int x1 = p1.X + mRadius * cos(beta1);
        int y1 = p1.Y + mRadius * sin(beta1);
        int x2 = p2.X + r2 * cos(beta1);
        int y2 = p2.Y + r2 * sin(beta1);

        graphics->DrawLine(&pen, x + x1, y + y1, x + x2, y + y2);

        x1 = p1.X + mRadius * cos(beta2);
        y1 = p1.Y + mRadius * sin(beta2);
        x2 = p2.X + r2 * cos(beta2);
        y2 = p2.Y + r2 * sin(beta2);
        
        graphics->DrawLine(&pen, x + x1, y + y1, x + x2, y + y2);
    }

    graphics->SetSmoothingMode(saveSM);

    CComponent::Draw(graphics, x, y);
}
