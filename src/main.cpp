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
TD: change ports
*/
motor Left1 = motor(PORT6, false);
motor Right1 = motor(PORT10, true);
motor Left2 = motor(PORT6, false);
motor Right2 = motor(PORT10, true);

motor_group Left = motor_group(Left1, Left2);
motor_group Right = motor_group(Right1, Right2);

controller Controller = controller();

/*
CONSTANTS
*/
const float deadZone = 5.0;

int main() 
{
    // Main controller loop
    while (true) 
    {
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
        }

        Left.spin(forward);
        Right.spin(forward);

        wait(20, msec);
    }
}
