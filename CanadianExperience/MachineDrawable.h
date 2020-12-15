/**
 * \file MachineDrawable.h
 *
 * \author Elizabeth Stevens
 *
 * Adapter class for a Machine drawable
 */

#pragma once

#include "Drawable.h"
#include "Machine.h"

class CTimeline;

/** Adapter class for a Machine drawable */
class CMachineDrawable : public CDrawable
{
public:
    virtual ~CMachineDrawable();
    CMachineDrawable(const std::wstring &name);

    /** \brief Default constructor disabled */
    CMachineDrawable() = delete;
    /** \brief Copy constructor disabled */
    CMachineDrawable(const CMachineDrawable&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CMachineDrawable&) = delete;

    virtual void Draw(Gdiplus::Graphics* graphics) override;
    virtual bool HitTest(Gdiplus::Point pos) override;
    void SetLocation(int x, int y);

    /** Set the Machine initial frame
    * \param frame The starting frame */
    void SetInitialFrame(int frame) { mInitialFrame = frame; }

    /** Here because I don't want to set keyframes for the machine */
    virtual void SetKeyframe() override {}
    /** Here because I don't want to get keyframes for the machine */
    virtual void GetKeyframe() override {}

    /** Set the Machine
     * \param machine The Machine */
    void SetMachine(std::shared_ptr<CMachine> machine) { mMachine = machine; }

    /** Get the Machine
     * \return The machine */
    std::shared_ptr<CMachine> GetMachine() { return mMachine; }

    /** Set the Timeline
    * \param timeline The timeline */
    void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }

private:
    /// The initial frame we will start the machine on
    int mInitialFrame = 0;

    /// The machine
    std::shared_ptr<CMachine> mMachine;

    /// The timeline
    CTimeline* mTimeline = nullptr;
};

