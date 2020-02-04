/*
	https://www.urionlinejudge.com.br/judge/en/problems/view/1039	
*/

#include <stdio.h>
#include <math.h>

typedef struct Point{
	int x;
	int y;
} Point;

typedef struct Circle{
	Point origin;
	int radius;
} Circle;

double distance(Point *a, Point *b){
	int dx = (b->x - a->x);
	int dy = (b->y - a->y);
	return sqrt( dx*dx + dy*dy );
}

int main(void){
	Circle a, b;	
	double d;
	while( scanf("%d %d %d %d %d %d", 
			&a.radius, &a.origin.x, &a.origin.y,
			&b.radius, &b.origin.x, &b.origin.y) != EOF){		
		if (a.radius >= b.radius + distance(&a.origin, &b.origin))
			printf("RICO\n");
		else
			printf("MORTO\n");
	}	
	return 0;
}
