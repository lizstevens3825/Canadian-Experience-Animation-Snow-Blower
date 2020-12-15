/**
 * \file Source.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Source.h"
#include "Sink.h"

using namespace std;

/** Constructor */
CSource::CSource()
{
}

/** Destructor */
CSource::~CSource()
{
}

/** Add a sink to the collection of connected sinks
 * \param sink The sink to add */
void CSource::AddSink(CSink* sink)
{
    mSinks.push_back(sink);
    sink->SetSource(this);
}

/** Set the rotation speed
 * \param rotation The rotation speed */
void CSource::SetRotation(double rotation)
{
    for (auto sink : mSinks)
    {
        sink->SetRotation(rotation);
    }
}
