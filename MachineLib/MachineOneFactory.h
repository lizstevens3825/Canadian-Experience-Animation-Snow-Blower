/**
 * \file MachineOneFactory.h
 *
 * \author Elizabeth Stevens
 *
 * Factory to create our first machine
 */

#pragma once

#include <memory>

class CMachineImage;

/** Factory to create our first machine */
class CMachineOneFactory
{
public:
    CMachineOneFactory();
    ~CMachineOneFactory();

    std::shared_ptr<CMachineImage> CreateMachine();
};

