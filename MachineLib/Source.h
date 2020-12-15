/**
 * \file Source.h
 *
 * \author Elizabeth Stevens
 *
 * Class that represents a source characteristic
 */

#pragma once

#include <vector>
#include <memory>

class CSink;

/** Class that represents a source characteristic */
class CSource
{
public:
    CSource();
    ~CSource();

    /** Copy constructor disabled */
    CSource(const CSource&) = delete;
    /** Assignment operator disabled */
    void operator=(const CSource&) = delete;

    void AddSink(CSink* sink);
    void SetRotation(double rotation);

private:
    /// The sinks we are connected to
    std::vector<CSink*> mSinks;

};

