/**
 * \file Shape.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents a shape component
 */

#pragma once

#include "Component.h"
#include "Sink.h"

/** Class that represents a shape component */
class CShape : public CComponent
{
public:
    CShape();
    ~CShape();

    /** Copy constructor disabled */
    CShape(const CShape&) = delete;
    /** Assignment operator disabled */
    void operator=(const CShape&) = delete;

    /** Get the sink characteristic
     * \return The sink */
    CSink* GetSink() { return &mSink; }

private:
    /// The sink characteristic
    CSink mSink;
};

