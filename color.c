/* Color */
typedef struct {
	float red, green, blue;
} color;

float getColorRed(color c) {
	return c.red;
}

float getColorBlue(color c) {
	return c.blue;
}

float getColorGreen(color c) {
	return c.green;
}

void setColorRed(float x, color c) {
	c.red = x;
}

void setColorBlue(float x, color c) {
	c.blue = x;
}

void setColorGreen(float x, color c) {
	c.green = x;
}

color initColor() {
	color c;
	c.red = 0.5;
	c.blue = 0.5;
	c.green = 0.5;
	return c;
}

color makeColor(float r, float b, float g) {
	color c;
	c.red = r;
	c.blue = b;
	c.green = g;
	return c;  
}




