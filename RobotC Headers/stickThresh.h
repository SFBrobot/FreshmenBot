#ifndef STICK_THRESH

#define STICK_THRESH

void upSticks(int* sticks, int thresh) {
	for(int i = 0; i < 4; i++) {
		sticks[i] = (abs(vexRT[i]) > thresh)
			? vexRT[i]
			: 0;
	}
}

#endif
