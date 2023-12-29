#include <stdio.h>

typedef struct Point {
	double x;
	double y;
} Point;

void output(Point* p) {
	printf("x = %.2f, y = %.2f\n", p->x, p->y);
}

int main() {

	output(&(Point) {
		.x = 1.00,
		.y = 2.00
	});

	return 0;
}
