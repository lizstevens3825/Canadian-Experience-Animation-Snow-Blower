/**
 * \file Shape.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Shape.h"

/** Constructor */
CShape::CShape()
{
    mSink.SetComponent(this);
}

/** Destructor */
CShape::~CShape()
{
}


