#include "Slide.h"


void Slide::drawSlide(float y1, float y2) {
	
	glBegin(GL_QUADS);
		//top part
		//top
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.5f, 6.0f, -9.98f);
		glVertex3f(4.5f, 6.0f, -9.98f);
		glVertex3f(4.5f, 6.0f, -9.88f);
		glVertex3f(-1.5f, 6.0f, -9.88f);
		//Bottom
		glVertex3f(-1.5f, 5.9f, -9.98f);
		glVertex3f(4.5f, 5.9f, -9.98f);
		glVertex3f(4.5f, 5.9f, -9.88f);
		glVertex3f(-1.5f, 5.9f, -9.88f);
		//Front
		glVertex3f(-1.5f, 6.0f, -9.88f);
		glVertex3f(4.5f, 6.0f, -9.88f);
		glVertex3f(4.5f, 5.9f, -9.88f);
		glVertex3f(-1.5f, 5.9f, -9.88f);

		//slide part
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.5f, y1, -9.93f);
		glVertex3f(4.5f, y1, -9.93f);
		glVertex3f(4.5f, y2, -9.93f);
		glVertex3f(-1.5f, y2, -9.93f);
	glEnd();
}