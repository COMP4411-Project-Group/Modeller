#include "marching_cube.h"
#include <fl/GL.h>
#include <cstdio>
Cube_Grid::Cube_Grid(int GridSize):
			numVertices(0),
			vertices(NULL),
			numCubes(0),
			cubes(NULL),
			numFacesDrawn(0) {
	allocMem();
	Init(GridSize);
}

bool Cube_Grid::allocMem() {
	vertices = new Cube_Grid_Vertex[(maxGridSize+1)*(maxGridSize+1)*(maxGridSize+1)];
	if(!vertices) {
		printf("Error allocating memeory");
		return false;
	}
	cubes = new Cube_Grid_Cube[maxGridSize*maxGridSize*maxGridSize];
	if(!cubes) {
		printf("Error allocating memory");
		return false;
	}
	return true;
}

bool Cube_Grid::Init(int gridSize) {
	//Vertices
	numVertices = (gridSize+1) * (gridSize+1) * (gridSize + 1);
	int currentVertex = 0;
	for(int i = 0; i < gridSize; i++ ) {
		for(int j=0; j < gridSize; j++) {
			for(int k=0; k < gridSize; k++) {
				vertices[currentVertex].position = 
					 new Vec3<float>((i*10.0f)/(gridSize)-5.0f, (j*10.0f)/(gridSize)-5.0f, (k*10.0f)/(gridSize)-5.0f);
				currentVertex++;
			}
		}
	}
	//Cubes
	numCubes = (gridSize)*(gridSize)*(gridSize); 
	int currentCube = 0;
	for(int i=0; i<gridSize; i++) {
		for(int j=0; j < gridSize; j++) {
			for(int k=0; k < gridSize; k++) {
				cubes[currentCube].vertices[0]=&vertices[(i*(gridSize+1)+j)*(gridSize+1)+k];
				cubes[currentCube].vertices[1]=&vertices[(i*(gridSize+1)+j)*(gridSize+1)+k+1];
				cubes[currentCube].vertices[2]=&vertices[(i*(gridSize+1)+(j+1))*(gridSize+1)+k+1];
				cubes[currentCube].vertices[3]=&vertices[(i*(gridSize+1)+(j+1))*(gridSize+1)+k];
				cubes[currentCube].vertices[4]=&vertices[((i+1)*(gridSize+1)+j)*(gridSize+1)+k];
				cubes[currentCube].vertices[5]=&vertices[((i+1)*(gridSize+1)+j)*(gridSize+1)+k+1];
				cubes[currentCube].vertices[6]=&vertices[((i+1)*(gridSize+1)+(j+1))*(gridSize+1)+k+1];
				cubes[currentCube].vertices[7]=&vertices[((i+1)*(gridSize+1)+(j+1))*(gridSize+1)+k];
				currentCube++;
			}
		}
	}
	return true;
}
 
void Cube_Grid::DrawSurface(float threshold) {
	numFacesDrawn = 0;
	static Surface_Vertex edgeVertices[12];
	glBegin(GL_TRIANGLES);
	//loop through cubes
	for(int i=0; i<numCubes; i++) {
		unsigned char cubeIndex = 0;
		if(cubes[i].vertices[0]->value < threshold)
			cubeIndex |= 1;
		if(cubes[i].vertices[1]->value < threshold)
				cubeIndex |= 2;
		if(cubes[i].vertices[2]->value < threshold)
			cubeIndex |= 4;
		if(cubes[i].vertices[3]->value < threshold)
			cubeIndex |= 8;
		if(cubes[i].vertices[4]->value < threshold)
			cubeIndex |= 16;
		if(cubes[i].vertices[5]->value < threshold)
			cubeIndex |= 32;
		if(cubes[i].vertices[6]->value < threshold)
			cubeIndex |= 64;
		if(cubes[i].vertices[7]->value < threshold)
			cubeIndex |= 128;
		//look up this value in edge table
		int usedEdge = edgeTable[cubeIndex];
		//if the cube is entirely within, outside surface, nothing to do
		if(usedEdge == 0 || usedEdge == 255){
			continue;
		}
		//update these edges
		for(int currentEdge = 0; currentEdge < 12; currentEdge++) {
			//get two end points
			Cube_Grid_Vertex* v1 = cubes[i].vertices[verticesAtEndsOfEdges[currentEdge *2]];
			Cube_Grid_Vertex* v2 = cubes[i].vertices[verticesAtEndsOfEdges[currentEdge*2 +1]];
			float delta = (threshold - v1->value)/(v2->value - v1->value);
			//calculate edge vetices, some ugly formulas
			//I suddenly found out that there are predefined operator, live is good
			//I suddenly again found out that I forgot the precedence of dereference 
			//Operation, lots of brackets.... Ugly
			*(edgeVertices[currentEdge].position) = (*(v1->position)) + delta*((*(v2->position)) - *(v1->position));
			/*
			edgeVertices[currentEdge].position = new Vec3<float>(
				(v1->position->getPointer())[0] + delta *
				(v2->position->getPointer())[0] - (v1->position->getPointer())[0],
				(v1->position->getPointer())[1] + delta *
				(v2->position->getPointer())[1] - (v1->position->getPointer())[1],
				(v1->position->getPointer())[2] + delta *
				(v2->position->getPointer())[2] - (v1->position->getPointer())[2]);
			*/
			*(edgeVertices[currentEdge].normal) = (*(v1->normal)) + delta * ((*(v2->normal)) - (*(v1->normal)));
		}
		//draw the vertices
		for(int k = 0; triTable[cubeIndex][k]!=-1; k+=3) {
			const float *ver1 =edgeVertices[triTable[cubeIndex][k+0]].position->getPointer();
			const float *nor1 = edgeVertices[triTable[cubeIndex][k+0]].normal->getPointer();
			glNormal3f(nor1[0],nor1[1],nor1[2]);
			glVertex3f(ver1[0],ver1[1],ver1[2]);
			//glNormal3fv(edgeVertices[triTable[cubeIndex][k+0]].normal->getPointer());
			//glVertex3fv(edgeVertices[triTable[cubeIndex][k+0]].position->getPointer());

			const float *ver2 =edgeVertices[triTable[cubeIndex][k+1]].position->getPointer();
			const float *nor2 = edgeVertices[triTable[cubeIndex][k+1]].position->getPointer();
			//glNormal3fv(edgeVertices[triTable[cubeIndex][k+2]].normal->getPointer());
			//glVertex3fv(edgeVertices[triTable[cubeIndex][k+2]].position->getPointer());

			const float *ver3 =edgeVertices[triTable[cubeIndex][k+2]].position->getPointer();
			const float *nor3 = edgeVertices[triTable[cubeIndex][k+2]].position->getPointer();
			//glNormal3fv(edgeVertices[triTable[cubeIndex][k+1]].normal->getPointer());
			//glVertex3fv(edgeVertices[triTable[cubeIndex][k+1]].position->getPointer());
			
			numFacesDrawn++;
		}
		glEnd();
	}
}

void Cube_Grid::freeMem() {
	if(vertices) 
		delete [] vertices;
	vertices = NULL;
	numVertices = 0;
	if(cubes)
		delete [] cubes;
	cubes = NULL;
	numCubes = 0;
}