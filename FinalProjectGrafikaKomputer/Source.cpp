#include <iostream>
#include <math.h>
#include <string.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <GL/freeglut_ext.h>
#include <soil.h>
#include "chair.h"
#include "table.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

// XZ position of the camera
float x = -5.0f, z = 18.0f;
float roll = 0.0f;

// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;

//for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;

//Penyimpanan tekstur
const GLsizei n = 10;
GLuint *texture = new GLuint[10];
/*
* Load tekstur dari file BMP dan membuat tekstur
*/
/*int loadBMPFile(const char *filename)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	//glEnable(GL_DEPTH_TEST);

	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	FILE * file;
	fopen_s(&file, filename, "rb");
	if (!file) { printf("Image could not be opened\n"); return 0; }

	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}

	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}

	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );

	glGenTextures(1, &texture[0]); // Create The Texture
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texture[0]);
	return 0;
}*/

void loadImage(const char *filename, int sign) {
	int width = 0;
	int height = 0, nrChannels;
	glBindTexture(GL_TEXTURE_2D, texture[sign]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	unsigned char* image = SOIL_load_image(filename, &width, &height, &nrChannels, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
}

void renderScene(void) {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 2.5f, z,
		x + lx, 2.5f + ly, z + lz,
		roll + 0.0f, 2.5f, 0.0f);

	// Draw floor
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glTexCoord2f(0.0f, 8.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glTexCoord2f(8.0f, 8.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glTexCoord2f(8.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();
	
	// Draw ladder
	glColor3f(0.38f, 0.38f, 0.38f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.75f, -10.0f);
	glVertex3f(-10.0f, 0.75f, -6.0f);
	glVertex3f(10.0f, 0.75f, -6.0f);
	glVertex3f(10.0f, 0.75f, -10.0f);
	glEnd();

	glColor3f(0.38f, 0.38f, 0.38f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.75f, -6.0f);
	glVertex3f(-10.0f, 0.0f, -6.0f);
	glVertex3f(10.0f, 0.0f, -6.0f);
	glVertex3f(10.0f, 0.75f, -6.0f);
	glEnd();

	//wall
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//wall
	glBindTexture(GL_TEXTURE_2D, 0);
	glColor3f(0.52f, 0.52f, 0.52f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();

	//wall with door
	glColor3f(0.52f, 0.52f, 0.52f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.52f, 0.52f, 0.52f);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 0.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.52f, 0.52f, 0.52f);
	glBegin(GL_QUADS);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-6.0f, 5.0f, 10.01f);
	glVertex3f(-3.0f, 5.0f, 10.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-6.0f, 5.0f, 10.01f);
	glVertex3f(-6.0f, 0.0f, 10.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-3.0f, 0.0f, 10.01f);
	glVertex3f(-3.0f, 5.0f, 10.01f);
	glEnd();


	//wall
	glColor3f(0.52f, 0.52f, 0.52f);
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	//ceiling
	glColor3f(0.95f, 0.95f, 0.95f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glEnd();

	// Draw whiteboard
	glColor3f(0.851f, 0.851f, 0.851f);
	glBegin(GL_QUADS);
	glVertex3f(-9.8f, 2.75f, -9.98f);
	glVertex3f(-9.8f, 5.85f, -9.98f);
	glVertex3f(-1.8f, 5.85f, -9.98f);
	glVertex3f(-1.8f, 2.75f, -9.98f);
	glEnd();

	// Draw prof's chair
	Chair profChair;
	glPushMatrix();
	glTranslatef(6.0f, 1.75f, -9.0f);
	glScalef(0.32f, 0.32f, 0.32f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profChair.drawChair();
	glPopMatrix();

	// Draw prof's table
	Table profTable;
	glPushMatrix();
	glTranslatef(6.0f, 2.15f, -7.6f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profTable.drawTable();
	glPopMatrix();


	// Draw student chairs MID
	Chair studentChair[4][4];
	for (int i = -3; i <= 3; i += 2) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i*0.8 - 0.4, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChair[i][j].drawChair();
			glPopMatrix();
		}
	}

	// Draw student chairs SIDE left
	Chair studentChairSIDEleft[2][4];
	for (int i = -3; i <= 3; i += 6) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i*0.2 - 7.9, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChairSIDEleft[i][j].drawChair();
			glPopMatrix();
		}
	}

	// Draw student chairs SIDE right
	Chair studentChairSIDEright[4][4];
	for (int i = -3; i <= 3; i += 6) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i*0.2 + 7.1, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChairSIDEright[i][j].drawChair();
			glPopMatrix();
		}
	}

	// Draw student tables MID
	Table studentTableMID[2][4];
	for (int i = -3; i <= 3; i += 6) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i*0.55, 1.2f, j * 2.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.4f);
			// glRotatef(180.0, 0.0, 1.0, 0.0);
			studentTableMID[i][j].drawTable();
			glPopMatrix();
		}
	}
	// Draw student tables SIDE
	Table studentTableSIDE[2][4];
	for (int i = -3; i <= 3; i += 6) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i*2.50, 1.2f, j * 2.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.4f);
			// glRotatef(180.0, 0.0, 1.0, 0.0);
			studentTableSIDE[i][j].drawTable();
			glPopMatrix();
		}
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (abs(mouseX) > 0.3) {
		angle -= (0.004f * mouseX);
		lx = sin(angle);
		lz = -cos(angle);
	}
	if (abs(mouseY) > 0.3) {
		if (abs(yAngle) < (M_PI / 2)) {
			yAngle += (0.002f * mouseY);
		}
		ly = sin(yAngle);
	}

	glFlush();
	glutSwapBuffers();
}


// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

// Handles the events triggered when any key on the keyboard is pressed.
//Specifically, handles w,a,s,d and Esc.
// moves the camera frward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy) {
	float fraction = 0.1f;
	if (key == 'w') {
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == 'a') {
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
	}
	else if (key == 's') {
		x -= lx * fraction;
		z -= lz * fraction;
	}
	else if (key == 'd') {
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
	}
	else if (key == 'x') {
		roll += 0.5f;
	}
	else if (key == 'z') {
		roll -= 0.5f;
	}
	else if (key == 't') {

	}

	if (key == 27)
		exit(0);

	//  Request display update
	glutPostRedisplay();
}


// Handles the events triggered when the mouse is moved in the window area. 
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy) {

	mouseX = (float)(halfWidth - xx) / halfWidth;
	mouseY = (float)(halfHeight - yy) / halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2)) {
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);

}

// Adjusts the viewport sie when the window size is changed and sets the projection.
 // @param w : new width of window
 // @param h : new height of window
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w / 2.0);
	halfHeight = (float)(h / 2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");
	glewInit();
	//loadBMPFile("./LAND2.BMP");
	glGenTextures(n, texture);
	loadImage("floor.jpg", 0);
	loadImage("sidewall.jpg", 1);

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(processMouseMovement);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}