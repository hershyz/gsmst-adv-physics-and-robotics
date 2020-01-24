#pragma config(Sensor, S2,     ultrasonic,     sensorNone)
#pragma config(Sensor, S3,     light,          sensorEV3_Color)
#pragma config(Sensor, S4,     touch,          sensorEV3_Touch)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)

int lightVal;
int darkVal;
int sum;
int t;

void autoThreshold() {
	while (SensorValue(touch) != 1) {
		displayBigTextLine(5, "Read Light Value");
	}

	lightVal = SensorValue(light);
	eraseDisplay();
	sleep(1000);

	while (SensorValue(touch) != 1) {
		displayBigTextLine(5, "Read Dark Value");
	}

	darkVal = SensorValue(light);
	eraseDisplay();

	sum = lightVal + darkVal;
	t = sum / 2;
}

void go(int lines) {
	int countedLines = 0;
	int seenLight = 1;

	while (countedLines < lines) {
		setMotorSpeed(left, 40);
		setMotorSpeed(right, 40);

		if (SensorValue(light) <= t) {
			if (seenLight == 1) {
				countedLines = countedLines + 1;
				seenLight = 0;
			}
		}
		else {
			seenLight = 1;
		}
	}

	displayBigTextLine(4, "%d", countedLines);
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 0);
	sleep(10000000);

	countedLines = 0;
}

task main()
{
	autoThreshold();
	go(6);
}
