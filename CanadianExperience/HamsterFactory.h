/**
 * \file HamsterFactory.h
 *
 * \author Elizabeth Stevens
 *
 * Actor factory class for our hamster
 */

#pragma once
#include "ActorFactory.h"

/** Actor factory class for our hamster */
class CHamsterFactory : public CActorFactory
{
public:
    CHamsterFactory();
    virtual ~CHamsterFactory();

    std::shared_ptr<CActor> Create();
};

