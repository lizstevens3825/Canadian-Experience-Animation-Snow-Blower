/**
 * \file MachineImage.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents the machine image
 */

#pragma once

#include "Component.h"

#include <memory>
#include <vector>

/** Class that represents the machine image */
class CMachineImage
{
public:
    CMachineImage();
    ~CMachineImage();

    /** Copy constructor disabled */
    CMachineImage(const CMachineImage&) = delete;
    /** Assignment operator disabled */
    void operator=(const CMachineImage&) = delete;

    void AddComponent(std::shared_ptr<CComponent> component);
    void Draw(Gdiplus::Graphics* graphics, int x, int y);
    void SetTime(double elapsedTime);
    void Advance(double elapsedTime);

private:
    /// The components in drawing order
    std::vector<std::shared_ptr<CComponent>> mComponentsInOrder;

};

