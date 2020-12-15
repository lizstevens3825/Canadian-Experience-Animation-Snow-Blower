/**
 * \file Motor.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents a Motor component
 */

#pragma once

#include "Component.h"
#include "Source.h"

/** Class that represents a motor component */
class CMotor : public CComponent
{
public:
    CMotor();
    ~CMotor();

    /** Copy constructor disabled */
    CMotor(const CMotor&) = delete;
    /** Assignment operator disabled */
    void operator=(const CMotor&) = delete;

    virtual void SetTime(double time) override;
    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);
    void SetSpeed(double speed);

    /** Get the source characteristic 
     * \return The source */
    CSource* GetSource() { return &mSource; }

private:
    /// The speed of the motor
    double mSpeed = 0.0;

    /// The rotation count
    double mRotationCount = 0;

    /// The source characteristic
    CSource mSource;
};

