#pragma config(Sensor, S1,     light,          sensorEV3_Color)
#pragma config(Sensor, S2,     sonar,          sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int turns = 0;
int speedPositive = 50;
int speedNegative = -50;
int _90DegreeMilliseconds = 770;
int backMilliseconds = 400;

task main()
{
	//There are four 90 degree turns in one lap, so there would be eight turns in two laps:
	while (turns < 8) {

		//Goes forward until the light sensor detecs a dark color:
		while (SensorValue(light) > 4) {
			setMotorSpeed(left, speedPositive);
			setMotorSpeed(right, speedPositive);
		}

		//Go Backward:
		setMotorSpeed(left, speedNegative);
		setMotorSpeed(right, speedNegative);
		sleep(backMilliseconds);

		//90 Degree Turn Left:
		setMotorSpeed(left, 0);
		setMotorSpeed(right, speedPositive);
		sleep(_90DegreeMilliseconds);

		turns++;
	}
}
