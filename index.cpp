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

	void pixel(int x=0, int y=0, char character = '#') {
		dotsArray[y][x] = character;
	}

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

	void sqer(int x=0, int y=12,int wight=5, int height=5, char character='#') {
		for (int i = y; i < y + height; i++) {
			for (int j = x; j < x + wight; j++) {
				pixel(j, i, character);
			}
		}
	}

	void sqerEmpty(int x=10,int y =10, int wight=5,int height = 5, char character='$'){
			line(x, y, x + wight, y, character);
			line(x + wight, y, x + wight, y+height, character);
			line(x + wight, y+height, x, y + height, character);
			line(x, y+height, x, y, character);
	}

	void rightTriangle(int x=0, int y=10, int size=5,int upperCut=0, char character='#',int dir=1) {
		int k = 0;

		switch (dir) {
		case 0:
			for (int i = y; i < y + size - upperCut; i++) {
				for (int j = x; j < x + size - k; j++) {
					pixel(j, i, character);
				}
				k++;
			}
			break;
		case 1:
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

	void rightTriangleEmpty(int x=0, int y=4, int wight=4, int height=4, char character='#',int dir=0) {
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
	//screen.rightTriangle();
	screen.rightTriangle();
	screen.rightTriangleEmpty();
	screen.sqer();
	screen.sqerEmpty();
	//screen.sqer(20, 2, 10, 10, '#');
	
	screen.print();

	return 0;
}