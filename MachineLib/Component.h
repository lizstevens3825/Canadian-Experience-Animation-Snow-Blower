/**
 * \file Component.h
 *
 * \author Elizabeth Stevens
 *
 * Class that repersents a machine component
 */

#pragma once

#include "Polygon.h"

class CMachineImage;

/** Class that repersents a machine component */
class CComponent : public CPolygon
{
public:
    virtual ~CComponent();
    CComponent();

    /** Copy constructor disabled */
    CComponent (const CComponent&) = delete;
    /** Assignment operator disabled */
    void operator=(const CComponent&) = delete;

    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);
    virtual void SetTime(double time);
    virtual void UpdateSnow(double time);

    /** Set the position
     * \param x The x position 
     * \param y The y position */
    void SetPosition(int x, int y) { mPosition = Gdiplus::Point(x,y); }

    /** Get the position
     * \return The position */
    Gdiplus::Point GetPosition() { return mPosition; }

    /** Get the current time of the component
     * \return The time */
    double GetTime() { return mTime; }

    /** Set the Machine Image
     * \param image The machine image */
    void SetMachineImage(CMachineImage* image) { mMachineImage = image; }

    /** Get the Machine Image
     * \return The machine image */
    CMachineImage* GetMachineImage() { return mMachineImage; }

    /** Get the X position
     * \return The X position */
    int GetX() { return mPosition.X; }

    /** Get the Y position
     * \return The Y position */
    int GetY() { return mPosition.Y; }

    /** Set the rotation of the component
     * \param rotation Rotation in turns, where 0-1 is one revolution. */
    virtual void SetRotation(double rotation) override { CPolygon::SetRotation(rotation); }

private:
    /// The position of the component
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

    /// The current time of the component
    double mTime = 0.0;

    /// Pointer to the machine image
    CMachineImage* mMachineImage = nullptr;

};

