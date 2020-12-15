/**
 * \file Snow.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents our snow
 */

#pragma once

/** Class that represents our snow */
class CSnow
{
public:
    CSnow();
    ~CSnow();

    void Update(double delta);
    void Draw(Gdiplus::Graphics* graphics, int x, int y);

    /** Set the position
     * \param pos The position */
    void SetPosition(Gdiplus::PointF pos) { mP = pos; }

    /** Get the position
     * \return The position */
    Gdiplus::PointF GetPosition() { return mP; }

    /** Set the velocity
     * \param vel The velocity */
    void SetVelocity(Gdiplus::PointF vel) { mV = vel; }

    /** Get the velocity
     * \return The velocity */
    Gdiplus::PointF GetVelocity() { return mV; }

private:
    /// The position of the snow
    Gdiplus::PointF mP = Gdiplus::PointF(0.0, 0.0);

    /// The velocity of the snow
    Gdiplus::PointF mV = Gdiplus::PointF(0.0, 0.0);

};

