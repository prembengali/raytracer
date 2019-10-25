#include "vector.c"
#include "color.c"

typedef struct {

	vector position;
	color col;

}light;

light makeLight(vector pos, color c) {
	light l;
	l.position = pos;
	l.col = c;
	return l;
}

vector getLightPosition(light l) {
	return l.position;
}

color getLightColor(light l) {
	return l.col;
}

light initLight() {
	light l;
	l.position = makeVector(0,0,0);
	l.col = makeColor(1,1,1);
	return l;
}

