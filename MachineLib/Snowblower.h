/**
 * \file Snowblower.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents a Snowblower component 
 */

#pragma once

#include "Component.h"
#include "Snow.h"
#include "Sink.h"

#include <list>
#include <random>


/** Class that represents a Snowblower component */
class CSnowblower : public CComponent
{
public:
    CSnowblower();
    ~CSnowblower();

    /** Copy constructor disabled */
    CSnowblower(const CSnowblower&) = delete;
    /** Assignment operator disabled */
    void operator=(const CSnowblower&) = delete;

    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y) override;
    virtual void SetRotation(double rotation) override;
    virtual void UpdateSnow(double time) override;
    double Random(double fmValue, double toValue);
    void AddSnow();
    void DeleteSnow();  

    /** Get the sink characteristic
     * \return The sink */
    CSink* GetSink() { return &mSink; }

private:
    /// Random number
    std::mt19937 mRandom;

    /// The previous rotation
    double mPrevRotation = 0;

    /// The change in rotation
    double mDeltaRotation = 0;

    /// Indicates if initial rotation will be set
    bool mRotated = true;

    /// The collection of snow produced
    std::list<CSnow> mSnow;

    /// The sink characteristic
    CSink mSink;

};

