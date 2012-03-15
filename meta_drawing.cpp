#include "meta_drawing.h"
//global settting up
const int minGridSize = 10;
int gridSize = 40;
float threshold = 1.0f;
Cube_Grid cubeGrid(40);
//for testing propose
void drawTwoBalls() {
	//initialize balls
	MetaBall balls[2];
	balls[0].Init(Vec3<float>(0.0,0.0,0.0),25.0);
	balls[1].Init(Vec3<float>(-1.5, 1.5, 0.0),36.0);
	for(int i=0; i<cubeGrid.numCubes; i++) {
		cubeGrid.vertices[i].value = 0.0;
		cubeGrid.vertices[i].normal->zeroElements();
		/*
		printf("%f,%f,%f\n",
			cubeGrid.vertices[i].position->getPointer()[0],
			cubeGrid.vertices[i].position->getPointer()[1],
			cubeGrid.vertices[i].position->getPointer()[2]);
			*/
	}
	Vec3<float> ballToPoint;
	float squaredRadius;
	Vec3<float> ballPosition;
	float normalScale;
	for(int i=0; i<2; i++) {
		squaredRadius = balls[i].squaredRadius;
		ballPosition = balls[i].position;
		for(int j=0; j<cubeGrid.numVertices; j++) {
			ballToPoint = *(cubeGrid.vertices[j].position) -ballPosition;
			/*
			printf("%f,%f,%f\n",
				ballToPoint.getPointer()[0],
				ballToPoint.getPointer()[1],
				ballToPoint.getPointer()[2]);
				*/

			//get squared distance from ball to point
			float squaredDistance = ballToPoint.length2();
			if(squaredDistance == 0.0f)
				squaredDistance = 0.0001f;
			//value = r^2/d^2
			cubeGrid.vertices[j].value+=squaredRadius/squaredDistance;
			//printf("%f\n",cubeGrid.vertices[j].value);
			//normal = (r^2 *v) /d^4
			normalScale = squaredRadius/(squaredDistance*squaredDistance);
			(*(cubeGrid.vertices[j].normal))+=ballToPoint*normalScale;
		}
	}
	cubeGrid.DrawSurface(threshold);
}


