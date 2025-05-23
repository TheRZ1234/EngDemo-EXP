/*----------------------------------------------------------------------------------------*/
/*                                                                                        */
/*    Project:          Engineering Demo EXP                                              */
/*    Module:           main.cpp                                                          */
/*    Author:           Ryan Zhang                                                        */
/*    Description:      Code for Engineering Demo EXP bots                                */
/*                                                                                        */
/*                                                                                        */
/*----------------------------------------------------------------------------------------*/

// Include the VEX Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

// Brain should be defined by default
brain Brain;

// Robot configuration code.
inertial BrainInertial = inertial();

/*
MOTORS + CONTROLLER
*/
motor Left1 = motor(PORT6, true);
motor Right1 = motor(PORT9, false);
motor Left2 = motor(PORT7, true);
motor Right2 = motor(PORT10, false);

motor_group Left = motor_group(Left1, Left2);
motor_group Right = motor_group(Right1, Right2);

controller Controller = controller();

/*
CONSTANTS
*/
const float deadZone = 20.0; // upd deadZone: 10.0 -> 20.0
const float forwardPercent = 0.75; // decrease forward speed
const float turnPercent = 0.5; // one stick controls forward and the other controls turn

int main() 
{
    // Main controller loop
    while (true) 
    {
        /*
        UPDATED DRIVE
        */
        if (abs(Controller.Axis2.position()) > deadZone) 
        {
            Left.setVelocity(Controller.Axis2.position()*forwardPercent, percent);
            Right.setVelocity(Controller.Axis2.position()*forwardPercent, percent);
        } 
        else
        {
            Left.setVelocity(0, percent);
            Right.setVelocity(0, percent);
        }

        if (abs(Controller.Axis4.position()) > deadZone)
        {
            Left.setVelocity(Left.velocity()*(1.0+Controller.Axis4.position()/100.0)*turnPercent, percent);
            Right.setVelocity(Right.velocity()*(1.0-Controller.Axis4.position()/100.0)*turnPercent, percent);
        }

        /* TANK DRIVE
        if (abs(Controller.Axis2.position()) > deadZone) 
        {
            Right.setVelocity(Controller.Axis2.position(), percent);
        } 
        else
        {
            Right.setVelocity(0, percent);
        }

        if (abs(Controller.Axis3.position()) > deadZone)
        {
            Left.setVelocity(Controller.Axis3.position(), percent);
        }
        else 
        {
            Left.setVelocity(0, percent);
        }*/

        Left.spin(forward);
        Right.spin(forward);

        wait(20, msec);
    }
}
