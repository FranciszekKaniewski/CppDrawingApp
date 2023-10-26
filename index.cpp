#include <iostream>

using namespace std;

class Screen {
public: 
	int x = 50;
	int y = 20;

	char dotsArray[20][50];

	void print() {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << dotsArray[i][j];
			}
			cout << '\n';
		}
	}

	void init(char character) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 50; j++) {
				dotsArray[i][j] = character;
			}
		}
	}

	// Changes one character to a new one in {x,y} position
	void pixel(int x=0, int y=0, char character = '#') {
		dotsArray[y][x] = character;
	}

	// Creates a line from one direction {x,y} to second direction {endx,endy}
	void line(int x = 0, int y = 0, int endx = 5, int endy = 5, char character = '#') {
		pixel(x, y, character);
		pixel(endx, endy, character);

		int i = 1;
		while (x != endx && y != endy) {


			if (x >= endx) {
				x -= i;
			}
			else {
				x += i;
			}
			if (y >= endy) {
				y -= i;
			}
			else {
				y += i;
			}

			pixel(x, y, character);
		}

		if (y == endy && x != endx) {
			if (x > endx) {
				for (int i = x; i > endx; i--) {
					pixel(i, y, character);
				}
			}
			else {
				for (int i = x; i < endx; i++) {
					pixel(i, y, character);
				}
			}
		}

		if (x == endx && y != endy) {
			if (y > endy) {
				for (int i = y; i > endy; i--) {
					pixel(x, i, character);
				}
			}
			else {
				for (int i = y; i < endy; i++) {
					pixel(x, i, character);
				}
			}
		}
	}

	// Creates a fulfill square from {x,y} direction to {x+wight,y+height}
	void sqer(int x=0, int y=0,int wight=5, int height=5, char character='#') {
		for (int i = y; i < y + height; i++) {
			for (int j = x; j < x + wight; j++) {
				pixel(j, i, character);
			}
		}
	}

	// Creates a empty square from {x,y} direction to {x+wight,y+height}
	void sqerEmpty(int x=0,int y =0, int wight=5,int height = 5, char character='#'){
			line(x, y, x + wight, y, character);
			line(x + wight, y, x + wight, y+height, character);
			line(x + wight, y+height, x, y + height, character);
			line(x, y+height, x, y, character);
	}

	// Creates a fulfill rightTryangel from {x,y} with size of size who can be cutted from top and rotated in 4 diration
	void rightTriangle(int x=0, int y=10, int size=5,int upperCut=0, char character='X',int dir=0) {
		int k = 0;

		switch (dir) {
		case 1:
			for (int i = y; i < y + size - upperCut; i++) {
				for (int j = x; j < x + size - k; j++) {
					pixel(j, i, character);
				}
				k++;
			}
			break;
		case 0:
			for (int i = y; i > y - size + upperCut; i--) {
				for (int j = x; j < x + size - k; j++) {
					pixel(j, i, character);
				}
				k++;
			}
			break;
		case 2:
			for (int i = y; i > y - size + upperCut; i--) {
				for (int j = x; j > x - size + k; j--) {
					pixel(j, i, character);
				}
				k++;
			}
			break;
		case 3:
			for (int i = y; i < y + size - upperCut; i++) {
				for (int j = x; j > x - size + k; j--) {
					pixel(j, i, character);
				}
				k++;
			}
			break;
		}
	}

	// Creates a empty rightTryangel from {x,y} with size of size who can be rotated in 4 diration
	void rightTriangleEmpty(int x=0, int y=10, int wight=4, int height=4, char character='X',int dir=0) {
		switch (dir) {
		case 0:
			line(x + wight, y, x, y - height, character);
			line(x, y, x + wight, y, character);
			line(x, y, x, y - height, character);
			break;
		case 1:
			line(x + wight, y, x, y + height, character);
			line(x, y, x + wight, y, character);
			line(x, y, x, height + y, character);
			break;
		case 2:
			line(x - wight, y, x, y + height, character);
			line(x, y, x - wight, y, character);
			line(x, y, x, height + y, character);
			break;
		case 3:
			line(x - wight, y, x, y - height, character);
			line(x, y, x - wight, y, character);
			line(x, y, x, y - height, character);
			break;
		}

	}
};


int main() {

	Screen screen;

	screen.init('.');

	
	//  ========== Basick Objects ==========

	// screen.sqer();
	// screen.sqerEmpty(7,0,4,4);

	// screen.rightTriangle();
	// screen.rightTriangleEmpty(7,10);

	//  ========== Small House ==========
	
	//house
	screen.sqer(10,9,30,10,'*');
	//rof
	screen.rightTriangle(25,10,20,13,'\\');
	screen.rightTriangle(25,10,20,13,'/',2);
	//chimney
	screen.sqer(30,3,7,4,'U');

	//Doors
	screen.sqer(15,14,6,5,'X');

	//Window
	screen.sqer(26,14,11,3,'-');
	screen.line(26,15,37,15,'+');
	screen.line(31,14,31,16,'+');
	screen.sqerEmpty(25,13,12,4,'X');

	
	screen.print();

	return 0;
}