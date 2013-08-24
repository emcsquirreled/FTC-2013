

int position(float distance, float degrees, float movement)

{

	float Y;

	float X;

	float sin_cos;

	while(1==1)

	{

		nMotorEncoder[motorB] = 0;

		if(movement == 2)

		{

			while(movement == 2)

			{

				distance = nMotorEncoder[motorB];


			}

		}


		else if(movement == 1)

		{

			sin_cos = sin(degrees);

			X = sin_cos * distance;

			sin_cos = 0;

			sin_cos = cos(degrees);

			Y = sin_cos * distance;



		}






	}

}
