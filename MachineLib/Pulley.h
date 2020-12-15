/**
 * \file Pulley.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents a pulley component
 */

#pragma once

#include "Component.h"
#include "Source.h"
#include "Sink.h"

/** Class that represents a pulley component */
class CPulley : public CComponent
{
public:
    CPulley();
    ~CPulley();
    CPulley(double radius);

    /** Copy constructor disabled */
    CPulley(const CPulley&) = delete;
    /** Assignment operator disabled */
    void operator=(const CPulley&) = delete;

    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y) override;
    virtual void SetRotation(double rotation) override;

    void Drive(std::shared_ptr<CPulley> pulley);

    /** Set the radius of the pulley
     * \param radius The pulley radius */
    void SetRadius(double radius) { mRadius = radius; }

    /** Get the radius of the pulley
     * \return The pulley radius */
    double GetRadius() { return mRadius; }

    /** Get the pulley we are driving
     * \return The pulley we are driving */
    std::shared_ptr<CPulley> GetPulley() { return mPulley; }

    /** Set the pulley we are being driven by
     * \param pulley The pulley we are being driven by */
    void SetOtherPulley(CPulley* pulley) { mOtherPulley = pulley; }

    /** Get the sink characteristic
     * \return The sink */
    CSink* GetSink() { return &mSink; }

    /** Get the source characteristic
     * \return The source */
    CSource* GetSource() { return &mSource; }

private:
    /// The radius of our pulley
    double mRadius = 0.0;

    /// The pulley we are driving
    std::shared_ptr<CPulley> mPulley = nullptr;

    /// The pulley we are driven by
    CPulley* mOtherPulley = nullptr;

    /// The sink characteristic
    CSink mSink;

    /// The source characteristic
    CSource mSource;
};

