/**
 * \file MachineActual.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents our actual Machine
 */

#pragma once

#include "Machine.h"

#include <memory>

class CMachineImage;

/** Class that represents our actual Machine */
class CMachineActual : public CMachine
{
public:
    CMachineActual();
    virtual ~CMachineActual();

    /** Copy constructor disabled */
    CMachineActual(const CMachineActual&) = delete;
    /** Assignment operator disabled */
    void operator=(const CMachineActual&) = delete;

    virtual void SetLocation(int x, int y) override;
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;
    virtual void SetMachineFrame(int frame) override;
    virtual void SetMachineNumber(int machine) override;
    virtual int GetMachineNumber() override;

    /** Get the current frame
     * \return The current frame */
    int GetFrame() { return mFrame; }

    /** Set the Machine image
     * \param image The Machine image */
    void SetMachineImage(std::shared_ptr<CMachineImage> image) { mMachineImage = image; }

    /** Get the Machine image
     * \return The machine image */
    std::shared_ptr<CMachineImage> GetMachineImage() { return mMachineImage; }

    /** Set the Machine frame rate
     * \param rate The Machine frame rate */
    void SetFrameRate(double rate) { mFrameRate = rate; }

private:
    /// The current frame of the Machine
    int mFrame = 0;

    /// The position of the Machine
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

    /// The Machine's number
    int mMachineNumber = 0;

    /// The Machine Image
    std::shared_ptr<CMachineImage> mMachineImage;

    /// The Machine Frame Rate in frames/sec
    double mFrameRate = 30.0;

};

