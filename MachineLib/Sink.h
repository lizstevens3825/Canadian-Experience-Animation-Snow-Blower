/**
 * \file Sink.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represent a sink characteristic
 */

#pragma once

#include "Component.h"

#include <memory>

class CSource;

/** Class that represent a sink characteristic */
class CSink
{
public:
    CSink();
    ~CSink();

    /** Copy constructor disabled */
    CSink(const CSink&) = delete;
    /** Assignment operator disabled */
    void operator=(const CSink&) = delete;

    /** Set the source of this sink
     * \param source The source */
    void SetSource(CSource* source) { mSource = source; }

    /** Set the component
     * \param component The component */
    void SetComponent(CComponent* component) { mComponent = component; }

    /** Get the component
     * \return The component */
    CComponent* GetComponent() { return mComponent; }

    /** Set the rotation speed
     * \param rotation The rotation speed */
    void SetRotation(double rotation) { GetComponent()->SetRotation(rotation); }

private:
    /// The source of this sink
    CSource* mSource = nullptr;

    /// The component this sink is associated with
    CComponent* mComponent = nullptr;

    /// The rotation speed
    double mRotationSpeed = 0.0;
};

