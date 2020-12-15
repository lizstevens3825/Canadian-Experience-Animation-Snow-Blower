/**
 * \file MachineTwoFactory.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "MachineTwoFactory.h"
#include "MachineImage.h"
#include "Shape.h"
#include "Motor.h"
#include "Snowblower.h"
#include "Pulley.h"

using namespace std;
using namespace Gdiplus;

/** Constructor */
CMachineTwoFactory::CMachineTwoFactory()
{
}

/** Destructor */
CMachineTwoFactory::~CMachineTwoFactory()
{
}

/** Function to create the machine
 * \return The Machine Image */
std::shared_ptr<CMachineImage> CMachineTwoFactory::CreateMachine()
{
    // The machine itself
    auto machine = make_shared<CMachineImage>();

    const int MotorX = -95;	// Motor X location
    const int Post1X = 50;	// Post X location
    const int Post2X = 10;	// Second post X location

    int Post1Height = 120;
    int Post2Height = 50;

    ////
    //// The motor
    ////
    auto motor = make_shared<CMotor>();
    motor->SetPosition(MotorX, -25);
    motor->Rectangle(-85 / 2, 0, 85, 100);
    motor->SetImage(L"images/motor4.png");
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    //////
    ////// The snow blower
    //////
    auto blower = make_shared<CSnowblower>();
    blower->SetPosition(Post1X + 20, -120);
    blower->Rectangle(-138 / 2, 0, 138, 200);
    blower->SetImage(L"images/blowerR.png");
    blower->SetRotation(0.15);
    machine->AddComponent(blower);

    ////
    //// Post to hold the first pulley
    //// Must be added before the motor pulley so it draws behind the belt
    ////
    auto post1 = make_shared<CShape>();
    post1->SetPosition(Post1X, -20);
    post1->Rectangle(Post1X, 0, 20, Post1Height);
    post1->SetColor(Color(10, 10, 10));
    machine->AddComponent(post1);

    ////
    //// Post to hold the second pully
    ////
    auto post2 = make_shared<CShape>();
    post2->SetPosition(Post2X, -20);
    post2->Rectangle(Post2X, 0, 20, Post2Height);
    post2->SetColor(Color(10, 10, 10));
    machine->AddComponent(post2);

    ////
    //// The shaft driven by the motor
    //// Radius=15pixels
    ////
    auto shaft = make_shared<CPulley>(15);
    shaft->SetImage(L"images/shaft.png");
    shaft->SetPosition(MotorX, -130);
    shaft->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(shaft);

    //// This is how I make a connection from a source to a sink.
    //// This is the case where they are driven at the same speed.
    motor->GetSource()->AddSink(shaft->GetSink());

    ////
    //// The pulley driven by the motor
    //// Radius=15pixels
    ////
    auto pulley1 = make_shared<CPulley>(100);
    pulley1->SetImage(L"images/hamsterwheel.png");
    pulley1->SetPosition(MotorX, -130);
    pulley1->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley1);

    //// This is how I make a connection from a source to a sink.
    //// This is the case where they are driven at the same speed.
    motor->GetSource()->AddSink(pulley1->GetSink());

    ////
    //// The pulley on the snow blower. Driven by the motor pulley.
    //// Radius=40pixels
    ////
    auto pulley2 = make_shared<CPulley>(35);
    pulley2->SetImage(L"images/pulley.png");
    pulley2->SetPosition(Post2X + 20, post2->GetY() - Post2Height);
    pulley2->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley2);

    shaft->GetSource()->AddSink(pulley2->GetSink());

    ////
    //// Pulley directly driven by that pulley
    //// Radius=15px
    ////
    auto pulley3 = make_shared<CPulley>(15);
    pulley3->SetImage(L"images/pulley2.png");
    pulley3->SetPosition(pulley2->GetX(), pulley2->GetY());
    machine->AddComponent(pulley3);

    pulley2->GetSource()->AddSink(pulley3->GetSink());

    //// This is how I make a connection from a pully
    //// to another pully using a belt.
    shaft->Drive(pulley2);

    ////
    //// Pully on the second post
    ////
    auto pulley4 = make_shared<CPulley>(45);
    pulley4->SetImage(L"images/pulley.png");
    pulley4->SetPosition(Post1X + 60, post1->GetY() - Post1Height);
    pulley4->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley4);

    pulley3->Drive(pulley4);

    //
    // The base
    //
    auto base = make_shared<CShape>();
    int wid = 350;
    base->Rectangle(-wid / 2, 0, wid, 40);
    base->SetImage(L"images/hay.png");
    machine->AddComponent(base);





    return machine;
}
