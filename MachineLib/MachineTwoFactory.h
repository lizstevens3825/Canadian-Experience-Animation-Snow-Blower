/**
 * \file MachineTwoFactory.h
 *
 * \author Elizabeth Stevens
 *
 * Factory that creates our second machine
 */

#pragma once

#include <memory>

class CMachineImage;

/** Factory that creates our second machine */
class CMachineTwoFactory
{
public:
    CMachineTwoFactory();
    ~CMachineTwoFactory();

    std::shared_ptr<CMachineImage> CreateMachine();
};

