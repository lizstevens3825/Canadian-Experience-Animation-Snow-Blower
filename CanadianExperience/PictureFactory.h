/**
 * \file PictureFactory.h
 *
 * \author Charles B. Owen
 *
 * \brief A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"

class CMachineDrawable;

/**
 * \brief A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();

    std::shared_ptr<CPicture> Create();

    /** Get the first Machine
     * \return The Machine */
    std::shared_ptr<CMachineDrawable> GetMachine1() { return mMachine1; }
    
    /** Get the second Machine
     * \return The Machine */
    std::shared_ptr<CMachineDrawable> GetMachine2() { return mMachine2; }

private:
    /// The first Machine
    std::shared_ptr<CMachineDrawable> mMachine1;
    /// The second machine
    std::shared_ptr<CMachineDrawable> mMachine2;
};

