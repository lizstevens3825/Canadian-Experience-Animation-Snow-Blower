/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "MachineFactory.h"
#include "MachineOneFactory.h"
#include "MachineTwoFactory.h"
#include "MachineDrawable.h"
#include "HamsterFactory.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background2.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    CMachineFactory mfactory;

    // Create first machine;
    auto machine1 = mfactory.CreateMachine();
    machine1->SetMachineNumber(1);
    auto machineOneActor = make_shared<CActor>(L"Machine");
    mMachine1 = make_shared<CMachineDrawable>(L"Machine");
    mMachine1->SetTimeline(picture->GetTimeline());
    mMachine1->SetInitialFrame(160);
    mMachine1->SetMachine(machine1);
    mMachine1->SetLocation(1150, 600);

    machineOneActor->AddDrawable(mMachine1);
    picture->AddActor(machineOneActor);

    // Create second machine;
    auto machine2 = mfactory.CreateMachine();
    machine2->SetMachineNumber(2);
    auto machineTwoActor = make_shared<CActor>(L"Machine");
    mMachine2 = make_shared<CMachineDrawable>(L"Machine");
    mMachine2->SetTimeline(picture->GetTimeline());
    mMachine2->SetInitialFrame(270);
    mMachine2->SetMachine(machine2);
    mMachine2->SetLocation(200, 700);

    machineTwoActor->AddDrawable(mMachine2);
    picture->AddActor(machineTwoActor);

    // Create and add hamster
    CHamsterFactory hamFactory;
    auto hamster = hamFactory.Create();

    // This is where hamster will start out
    hamster->SetPosition(Point(83, 616));
    picture->AddActor(hamster);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(450, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(650, 600));
    picture->AddActor(sparty);

    return picture;
}
