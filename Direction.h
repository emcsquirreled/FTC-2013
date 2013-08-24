#include "drivers/hitechnic-gyro.h"

float currentHeading = 0;

bool gatheringData = true;

void setGatheringData(bool gathering);

task getHeading () {
	float deltaTime = 0;
	float prevHeading = 0;
	float currRate = 0;

  HTGYROstartCal(GYRO);

  while (true) {
    time1[T1] = 0;

    currRate = HTGYROreadRot(GYRO);
    if (gatheringData == true){
    	if (abs(currRate) > 5 || abs(currRate) < -5) {

      	prevHeading = currentHeading;
      	currentHeading = prevHeading + currRate * deltaTime;

      	if (currentHeading > 360) currentHeading -= 360;
      	else if (currentHeading < 0) currentHeading += 360;
    	}
  	}
    wait1Msec(5);
    deltaTime = ((float)time1[T1]) / 1000;
    //delTime /= 1000;
  }
}

void setGatheringData(bool gathering){
	gatheringData = gathering;
}
