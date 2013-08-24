#include "Direction.h"

float Y;

float X;

task Get_Position()

{

	float distance;

	float sin_cos;

	int degrees;

	int motor_A;

	int motor_B;

	int holder;

	while(1==1) // repeat forever

	{


		// zero out all the variables

		holder = 0;

		motor_A = 0;

		motor_B = 0;

		Y = 0;

		X = 0;

		sin_cos = 0;


		nMotorEncoder[motorB] = 0;

		nMotorEncoder[motorA] = 0;


		if(movement == 2)  // if robot is moving

		{
			startHeading = currHeading;

			while(movement == 2) // while robot is moving

			{

				// this will take the average of motors A & B and put it in variable distance

				motor_B = nMotorEncoder[motorB];  // puts degrees from motor B into variable motor_B

				motor_A = nMotorEncoder[motorA];  // puts degrees from motor A into variable motor_A

				holder = motor_A + motor_B;      // add values from motor_A and motor_B then put it in variable holder

				distance = holder / 2;          // divide holder value by 2 then put it in variable distance


			}

		}


		else if(movement == 1)   // if robot is stopped

		{
			degrees = currHeading;

			sin_cos = sin(degrees);       //  get the sin from the numbers of degrees turned

			X = sin_cos * distance;      // multiply the sin by the number of distance travled and put it in the X variable

			sin_cos = 0;                // set the sin_cos variable to zero

			sin_cos = cos(degrees);    // get the cos from the numbers of degrees turned

			Y = sin_cos * distance;   //  multiply the cos by the number of distance travled and put it in the Y variable



		}






	}
	// Tasks by default take as much cpu time as they need
	// This wait allows time for other stuff to get done
	wait1MSec(5);

}
