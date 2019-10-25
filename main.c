/* Ray tracer */

#include <stdio.h>
#include <stdbool.h> 
#include<stdlib.h>
#include <math.h>
#include "vector.c"
#include "camera.c"
#include "ray.c"
#include "color.c"
#include "light.c"
#include "sphere.c"
#include "plane.c"


/* Color */
typedef struct {
	float red, green, blue;
} Color;

/* Material Definition */
typedef struct {
	Color color;
	float reflection;
} material;

Color pixels[640 * 480];
;
//-----------------------------------------------------------------------------

int saveppm(const char *filename, int w, int h, Color *data) {

	printf("fefeefefefef");

	FILE *fp = fopen("scene.ppm", "wb"); /* b - binary mode */
	fprintf(fp, "P6\n%d %d\n255\n", w, h);

	/**			for (int x = 0; x < w; x++) {
	 for (int y = 0; y < h; y++) {

	 static unsigned char color[3];
	 color[0] = x % 256;
	 color[1] = y % 256;
	 color[2] = (x * y) % 256;
	 (void) fwrite(color, 1, 3, fp);
	 }
	 }

	 fclose(fp);
	 return EXIT_SUCCESS;*/
	int k = w * h;
	for (int i = 0; i < k; i++) {
		Color rgb = data[i];

		double red = (data[i].red) * 255;
		double green = (data[i].green) * 255;
		double blue = (data[i].blue) * 255;

		unsigned char color[3] = { (int) floor(blue), (int) floor(green),
				(int) floor(red) };
		fwrite(color, 1, 3, fp);
	}
	fclose(fp);
	return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {

	int thisone;
	int width = 640;
	int height = 480;
	int aspectratio = (double)width/(double)height;
	//int dpi = 72;
	//int totalPixels = width * height;

	vector X = makeVector(1,0,0);
	vector Y = makeVector(0,1,0);
	vector Z = makeVector(0,0,1);
	vector O = makeVector(0,0,0);

	vector lookat = makeVector(0,0,0);

	vector campos = makeVector(3,1.5,-4);

	vector diff_btw = (getVecX(campos) - getVecX(lookat), (getVecY(campos) - getVecY(lookat)), (getVecZ(campos) - getVecZ(lookat)));

	vector camdir = normalize(negative(diff_btw));

	vector camright = normalize(crossProduct(Y, camdir));

	vector camdown = crossProduct(camright, camdir);

	camera scene_cam = makeCamera(campos, camdir, camright, camdown);

	color whiteLight = makeColor(1.0,1.0,1.0);
	color pretty_green = makeColor(0.5,1.0,0.5);
	color gray = makeColor(0.5,0.5,0.5);
	color black = makeColor(0.0,0.0,0.0);
	color maroon = makeColor(0.5, 0.25, 0.25);

	vector lightPosition = makeVector(-7,10,-10);
	light sceneLight = makeLight(lightPosition, whiteLight);


	// Scene Objects
	sphere scenceSphere = makeSphere(O, 1, pretty_green);
	plane scenePlane = makePlane(Y, -1, maroon);


	double xamnt, yamnt;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			thisone = y * width + x;

			//No antiAlias
			if(width > height) {
				xamnt = ((x+0.5)/width)*aspectratio - (((width-height)/(double)height)/2);
				yamnt = ((height - y) + 0.5)/height;
			}
			else if (height > width) {  //if image is taller
				xamnt = (x + 0.5)/width;
				yamnt = (((height-y) + 0.5)/height)/aspectratio - (((height - width)/(double)width)/2);
			}
			else { //if its a square
				xamnt = (x + 0.5)/width;
				yamnt = ((height - y) + 0.5)/ height;
			}

			vector camRayOrigin = getCameraPosition(scene_cam);
			vector camRayDirection = normalize(vectAdd(camdir, vectorMult(camright, vectAdd(xamnt - 0.5, vectMult(camdown, yamnt - 0.5)))));

			ray camRay = makeRay(camRayOrigin, camRayDirection);



			if ((x > 200 && x < 400) && (y > 200 && y < 280)) {

				pixels[thisone].red = 23;
				pixels[thisone].green = 222;
				pixels[thisone].blue = 10;

			} else {

				pixels[thisone].red = 0;
				pixels[thisone].green = 0;
				pixels[thisone].blue = 0;

			}
		}
	}

	saveppm("scene.ppm", width, height, pixels);
	printf("Success");

	return 0;
}

