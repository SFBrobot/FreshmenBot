#ifndef DRIVE_CTL

#define DRIVE_CTL

int* arcade(int* pwrs, short int move, short int rot) {
	pwrs[0] = move + rot;
	pwrs[1] = move - rot;
	return pwrs;
}


#endif
