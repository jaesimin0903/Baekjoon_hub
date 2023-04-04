#include<iostream>

using namespace std;

struct point {
	int x;
	int y;
}first, second;

struct line {
	struct point p1;
	struct point p2;
}testLine;

int direction(struct point A, struct point B, struct point C) {
	int dxAB, dxAC, dyAB, dyAC, Dir;
	dxAB = B.x - A.x; dxAC = C.x - A.x;
	dyAB = B.y - A.y; dyAC = C.y - A.y;

	if (dxAB * dyAC < dyAB * dxAC) Dir = -1;
	if (dxAB * dyAC > dyAB * dxAC) Dir = 1;
	if (dxAB * dyAC == dyAB * dxAC) {
		/*if (dxAB == 0 && dyAB == 0) Dir = 0;
		if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) Dir = 1;
		else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) Dir = 0;
		else Dir = -1;*/
		Dir = 0;
	}
	return Dir;
}

int main(void) {
	struct point A;
	struct point B;
	struct point C;

	int i,x, y;

	
	cin >> x >> y;
	A.x = x;
	A.y = y;
	cin >> x >> y;
	B.x = x;
	B.y = y;
	cin >> x >> y;
	C.x = x;
	C.y = y;
	

	cout <<direction(A, B, C);
	
	return 0;
}