/**
 * \file HamsterFactory.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "HamsterFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace Gdiplus;
using namespace std;

/** Constructor */
CHamsterFactory::CHamsterFactory()
{
}

/** Destructor */
CHamsterFactory::~CHamsterFactory()
{
}

/** \brief This is a concrete factory method that creates our Hamster actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CHamsterFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Hamster");

    auto body = make_shared<CImageDrawable>(L"Body", L"images/hamster.png");
    body->SetCenter(Point(55, 50));
    body->SetPosition(Point(0, -114));
    actor->SetRoot(body);

    auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/hamsterleg.png");
    lleg->SetCenter(Point(22, 23));
    lleg->SetPosition(Point(-14, 18));
    body->AddChild(lleg);

    auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/hamsterlegr.png");
    rleg->SetCenter(Point(22, 23));
    rleg->SetPosition(Point(13, 18));
    body->AddChild(rleg);

    actor->AddDrawable(body);
    actor->AddDrawable(lleg);
    actor->AddDrawable(rleg);

    return actor;
}


