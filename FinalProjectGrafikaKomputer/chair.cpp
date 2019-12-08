#include "chair.h"

void Chair::drawChair() {
	glColor3f(0.10f, 0.10f, 0.10f);
	glBegin(GL_QUADS);

	//Front
	//
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(-2.0f, 0.0f, 2.0f);

	//Right
	//
	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, 0.0f, -2.0f);
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, 0.0f, -2.0f);
	glVertex3f(2.0f, 0.0f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//Left
	;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, 0.0f, 2.0f);
	glVertex3f(-2.0f, 0.0f, -2.0f);

	//top
	//

	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(-2.0f, 0.0f, 2.0f);
	glVertex3f(-2.0f, 0.0f, -2.0f);
	glVertex3f(2.0f, 0.0f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(1.8f, -0.2f, 2.0f);
	glVertex3f(1.8f, -3.0f, 2.0f);
	glVertex3f(2.0f, -3.0f, 2.0f);

	//back
	//;

	glVertex3f(2.0f, -0.2f, 1.8f);
	glVertex3f(1.8f, -0.2f, 1.8f);
	glVertex3f(1.8f, -3.0f, 1.8f);
	glVertex3f(2.0f, -3.0f, 1.8f);

	//right
	//

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 1.8f);
	glVertex3f(2.0f, -3.0f, 1.8f);
	glVertex3f(2.0f, -3.0f, 2.0f);

	//left
	//;

	glVertex3f(1.8f, -0.2f, 2.0f);
	glVertex3f(1.8f, -0.2f, 1.8f);
	glVertex3f(1.8f, -3.0f, 1.8f);
	glVertex3f(1.8f, -3.0f, 2.0f);

	//back leg back
	//front
	//;

	glVertex3f(2.0f, -0.2f, -1.8f);
	glVertex3f(1.8f, -0.2f, -1.8f);
	glVertex3f(1.8f, -3.0f, -1.8f);
	glVertex3f(2.0f, -3.0f, -1.8f);

	//back
	//;

	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(1.8f, -0.2f, -2.0f);
	glVertex3f(1.8f, -3.0f, -2.0f);
	glVertex3f(2.0f, -3.0f, -2.0f);

	//right
	//

	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -1.8f);
	glVertex3f(2.0f, -3.0f, -1.8f);
	glVertex3f(2.0f, -3.0f, -2.0f);

	//left
	//

	glVertex3f(1.8f, -0.2f, -2.0f);
	glVertex3f(1.8f, -0.2f, -1.8f);
	glVertex3f(1.8f, -3.0f, -1.8f);
	glVertex3f(1.8f, -3.0f, -2.0f);

	//leg left front
	//

	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-1.8f, -0.2f, 2.0f);
	glVertex3f(-1.8f, -3.0f, 2.0f);
	glVertex3f(-2.0f, -3.0f, 2.0f);

	//back
	//;

	glVertex3f(-2.0f, -0.2f, 1.8f);
	glVertex3f(-1.8f, -0.2f, 1.8f);
	glVertex3f(-1.8f, -3.0f, 1.8f);
	glVertex3f(-2.0f, -3.0f, 1.8f);

	//right


	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, 1.8f);
	glVertex3f(-2.0f, -3.0f, 1.8f);
	glVertex3f(-2.0f, -3.0f, 2.0f);

	//left
	;

	glVertex3f(-1.8f, -0.2f, 2.0f);
	glVertex3f(-1.8f, -0.2f, 1.8f);
	glVertex3f(-1.8f, -3.0f, 1.8f);
	glVertex3f(-1.8f, -3.0f, 2.0f);

	//left leg back front

	//front
	;

	glVertex3f(-2.0f, -0.2f, -1.8f);
	glVertex3f(-1.8f, -0.2f, -1.8f);
	glVertex3f(-1.8f, -3.0f, -1.8f);
	glVertex3f(-2.0f, -3.0f, -1.8f);

	//back
	;

	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-1.8f, -0.2f, -2.0f);
	glVertex3f(-1.8f, -3.0f, -2.0f);
	glVertex3f(-2.0f, -3.0f, -2.0f);

	//right


	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, -0.2f, -1.8f);
	glVertex3f(-2.0f, -3.0f, -1.8f);
	glVertex3f(-2.0f, -3.0f, -2.0f);

	//left


	glVertex3f(-1.8f, -0.2f, -2.0f);
	glVertex3f(-1.8f, -0.2f, -1.8f);
	glVertex3f(-1.8f, -3.0f, -1.8f);
	glVertex3f(-1.8f, -3.0f, -2.0f);

	//chair back
	//front





	//;
	//chair upper part 
	glVertex3f(-2.0f, 1.2f, -2.0f);
	glVertex3f(2.0f, 1.2f, -2.0f);
	glVertex3f(2.0f, 3.5f, -2.0f);
	glVertex3f(-2.0f, 3.5f, -2.0f);

	glVertex3f(-2.0f, 1.2f, -1.8f);
	glVertex3f(2.0f, 1.2f, -1.8f);
	glVertex3f(2.0f, 3.5f, -1.8f);
	glVertex3f(-2.0f, 3.5f, -1.8f);

	//chair upper side
	glVertex3f(-2.0f, 1.2f, -2.0f);
	glVertex3f(-2.0f, 1.2f, -1.8f);
	glVertex3f(-2.0f, 3.5f, -1.8f);
	glVertex3f(-2.0f, 3.5f, -2.0f);

	glVertex3f(2.0f, 1.2f, -2.0f);
	glVertex3f(2.0f, 1.2f, -1.8f);
	glVertex3f(2.0f, 3.5f, -1.8f);
	glVertex3f(2.0f, 3.5f, -2.0f);

	//chiar upper top 
	glVertex3f(-2.0f, 3.5f, -2.0f);
	glVertex3f(-2.0f, 3.5f, -1.8f);
	glVertex3f(2.0f, 3.5f, -1.8f);
	glVertex3f(2.0f, 3.5f, -2.0f);

	glVertex3f(-2.0f, 1.2f, -2.0f);
	glVertex3f(-2.0f, 1.2f, -1.8f);
	glVertex3f(2.0f, 1.2f, -1.8f);
	glVertex3f(2.0f, 1.2f, -2.0f);

	// chair top legs 
	//side walls
	glVertex3f(-2.0f, 1.2f, -2.0f);
	glVertex3f(-2.0f, 1.2f, -1.8f);
	glVertex3f(-2.0f, .0f, -1.8f);
	glVertex3f(-2.0f, .0f, -2.0f);

	glVertex3f(-1.8f, 1.2f, -2.0f);
	glVertex3f(-1.8f, 1.2f, -1.8f);
	glVertex3f(-1.8f, .0f, -1.8f);
	glVertex3f(-1.8f, .0f, -2.0f);

	//froont walls adnd back walls
	glVertex3f(-2.0f, 1.2f, -2.0f);
	glVertex3f(-1.8f, 1.2f, -2.0f);
	glVertex3f(-1.8f, .0f, -2.0f);
	glVertex3f(-2.0f, .0f, -2.0f);

	glVertex3f(-2.0f, 1.2f, -1.8f);
	glVertex3f(-1.8f, 1.2f, -1.8f);
	glVertex3f(-1.8f, .0f, -1.8f);
	glVertex3f(-2.0f, .0f, -1.8f);

	//side walls
	glVertex3f(2.0f, 1.2f, -2.0f);
	glVertex3f(2.0f, 1.2f, -1.8f);
	glVertex3f(2.0f, .0f, -1.8f);
	glVertex3f(2.0f, .0f, -2.0f);

	glVertex3f(1.8f, 1.2f, -2.0f);
	glVertex3f(1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, .0f, -1.8f);
	glVertex3f(1.8f, .0f, -2.0f);

	//froont walls adnd back walls
	glVertex3f(2.0f, 1.2f, -2.0f);
	glVertex3f(1.8f, 1.2f, -2.0f);
	glVertex3f(1.8f, .0f, -2.0f);
	glVertex3f(2.0f, .0f, -2.0f);

	glVertex3f(2.0f, 1.2f, -1.8f);
	glVertex3f(1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, .0f, -1.8f);
	glVertex3f(2.0f, .0f, -1.8f);

	//chair grip right 
	//bottom foot
	glVertex3f(-2.0f, 0.0f, 2.0f);
	glVertex3f(-1.8f, 0.0f, 2.0f);
	glVertex3f(-1.8f, 0.0f, 1.8f);
	glVertex3f(-2.0f, 0.0f, 1.8f);
	//top foot
	glVertex3f(-2.0f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 1.0f, 1.8f);
	glVertex3f(-2.0f, 1.0f, 1.8f);
	//left foot
	glVertex3f(-1.8f, 0.0f, 2.0f);
	glVertex3f(-1.8f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 1.0f, 1.8f);
	glVertex3f(-1.8f, 0.0f, 1.8f);
	//right foot
	glVertex3f(-2.0f, 0.0f, 2.0f);
	glVertex3f(-2.0f, 1.0f, 2.0f);
	glVertex3f(-2.0f, 1.0f, 1.8f);
	glVertex3f(-2.0f, 0.0f, 1.8f);
	//front foot
	glVertex3f(-2.0f, 0.0f, 1.8f);
	glVertex3f(-2.0f, 1.0f, 1.8f);
	glVertex3f(-1.8f, 1.0f, 1.8f);
	glVertex3f(-1.8f, 0.0f, 1.8f);
	//front foot
	glVertex3f(-2.0f, 0.0f, 2.0f);
	glVertex3f(-2.0f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 0.0f, 2.0f);
	//front grip
	glVertex3f(-2.0f, 0.8, 2.0f);
	glVertex3f(-2.0f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 0.8, 2.0f);
	//back grip
	glVertex3f(-2.0f, 0.8, -2.0f);
	glVertex3f(-2.0f, 1.0f, -2.0f);
	glVertex3f(-1.8f, 1.0f, -2.0f);
	glVertex3f(-1.8f, 0.8, -2.0f);
	//right grip
	glVertex3f(-2.0f, 0.8, -2.0f);
	glVertex3f(-2.0f, 1.0f, -2.0f);
	glVertex3f(-2.0f, 1.0f, 2.0f);
	glVertex3f(-2.0f, 0.8, 2.0f);
	//left grip
	glVertex3f(-1.8f, 0.8, -2.0f);
	glVertex3f(-1.8f, 1.0f, -2.0f);
	glVertex3f(-1.8f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 0.8, 2.0f);
	//top grip
	glVertex3f(-1.8f, 1.0, -2.0f);
	glVertex3f(-2.0f, 1.0f, -2.0f);
	glVertex3f(-2.0f, 1.0f, 2.0f);
	glVertex3f(-1.8f, 1.0, 2.0f);
	//bottom grip
	glVertex3f(-1.8f, 0.8, -2.0f);
	glVertex3f(-2.0f, 0.8f, -2.0f);
	glVertex3f(-2.0f, 0.8f, 2.0f);
	glVertex3f(-1.8f, 0.8, 2.0f);

	//chair grip left 
	//bottom foot
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(1.8f, 0.0f, 2.0f);
	glVertex3f(1.8f, 0.0f, 1.8f);
	glVertex3f(2.0f, 0.0f, 1.8f);
	//top foot
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(1.8f, 1.0f, 2.0f);
	glVertex3f(1.8f, 1.0f, 1.8f);
	glVertex3f(2.0f, 1.0f, 1.8f);
	//left foot
	glVertex3f(1.8f, 0.0f, 2.0f);
	glVertex3f(1.8f, 1.0f, 2.0f);
	glVertex3f(1.8f, 1.0f, 1.8f);
	glVertex3f(1.8f, 0.0f, 1.8f);
	//right foot
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(2.0f, 1.0f, 1.8f);
	glVertex3f(2.0f, 0.0f, 1.8f);
	//front foot
	glVertex3f(2.0f, 0.0f, 1.8f);
	glVertex3f(2.0f, 1.0f, 1.8f);
	glVertex3f(1.8f, 1.0f, 1.8f);
	glVertex3f(1.8f, 0.0f, 1.8f);
	//front foot
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(1.8f, 1.0f, 2.0f);
	glVertex3f(1.8f, 0.0f, 2.0f);
	//front grip
	glVertex3f(2.0f, 0.8, 2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(1.8f, 1.0f, 2.0f);
	glVertex3f(1.8f, 0.8, 2.0f);
	//back grip
	glVertex3f(2.0f, 0.8, -2.0f);
	glVertex3f(2.0f, 1.0f, -2.0f);
	glVertex3f(1.8f, 1.0f, -2.0f);
	glVertex3f(1.8f, 0.8, -2.0f);
	//right grip
	glVertex3f(2.0f, 0.8, -2.0f);
	glVertex3f(2.0f, 1.0f, -2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(2.0f, 0.8, 2.0f);
	//left grip
	glVertex3f(1.8f, 0.8, -2.0f);
	glVertex3f(1.8f, 1.0f, -2.0f);
	glVertex3f(1.8f, 1.0f, 2.0f);
	glVertex3f(1.8f, 0.8, 2.0f);
	//top grip
	glVertex3f(1.8f, 1.0, -2.0f);
	glVertex3f(2.0f, 1.0f, -2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(1.8f, 1.0, 2.0f);
	//bottom grip
	glVertex3f(1.8f, 0.8, -2.0f);
	glVertex3f(2.0f, 0.8f, -2.0f);
	glVertex3f(2.0f, 0.8f, 2.0f);
	glVertex3f(1.8f, 0.8, 2.0f);

	glEnd();

}
