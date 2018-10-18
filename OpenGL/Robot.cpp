
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
//#include <unistd.h> // required for usleep in Linux
#include <string.h> // required for memset in Linux


// robot position
static float robotPos[] = { 0.0,4.0,0};

// robot rotation angle,X,Y,Z
static float rotate[] = { 0.0,1.0,0.0,0.0 };


// joint angle,X,Y,Z
static float leftShoulder[] = { 0.0,0.0,0.0,0.0 };
static float leftElbow[] = { 0.0,0.0,0.0,0.0 };
static float rightShoulder[] = { 0.0,0.0,0.0,0.0 };
static float rightElbow[] = { 0.0,0.0,0.0,0.0 };
static float leftHip[] = { 0.0,0.0,0.0,0.0 };
static float leftKnee[] = { 0.0,0.0,0.0,0.0 };
static float rightHip[] = { 0.0,0.0,0.0,0.0 };
static float rightKnee[] = { 0.0,0.0,0.0,0.0 };
static float neck[] = { 0.0,0.0,0.0,0.0 };

// used to keep track of of leading leg position (if infront of behind)
// default start walking with left 
static bool legPos = false;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Lighting
	GLfloat ambient[] = { 0.24725,0.1995,0.0745,1.0 };
	GLfloat diffuse[] = { 0.0745,0.0745,0.0745,1.0 };
	GLfloat specular[] = { 0.628281,0.628281,0.628281 };
	GLfloat pos[] = { 0.0,10,3.0,0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.4 * 128.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glFrontFace(GL_CW);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
}

/**
* Reset Joints to default positions. Called before/after animations
*/
void reset()
{
	memset(leftShoulder, 0, 4 * sizeof(float));
	memset(leftElbow, 0, 4 * sizeof(float));
	memset(leftHip, 0, 4 * sizeof(float));
	memset(leftKnee, 0, 4 * sizeof(float));
	memset(rightShoulder, 0, 4 * sizeof(float));
	memset(rightElbow, 0, 4 * sizeof(float));
	memset(rightHip, 0, 4 * sizeof(float));
	memset(rightKnee, 0, 4 * sizeof(float));
	memset(neck, 0, 4 * sizeof(float));
	legPos = false;
}

/**
* Convert degree to radians. 
* @param degree : input degree to be converted. 
*/
float getRadians(float degree)
{
	return degree * 3.14 / 180;
}

/**
* Draws joint. Self contained, pushes and pops off stack
*/
void drawJoint()
{
	glPushMatrix();
		glTranslatef(0.0, 1.1, 0.0);
		glColor3f(1.0, 0.0, 0.0); // Set joint to be red
		glutSolidSphere(0.4, 20, 16);
		glColor3ub(212, 175, 55);  // re-update wuth old color. 
	glPopMatrix();
}

/**
* Draws Box used to represent body parts.
* @param aX: x axis scale factor 
* @param aY: y axis scale factor 
* @param aZ : z axis scale factor 
* @param aJoint : is True is associated body is connected to a joint from the top. 
*/
void drawBox(float aX, float aY, float aZ,bool aJoint)
{
	glPushMatrix();
		if(aJoint)
			drawJoint();
		glScalef(aX, aY, aZ);
		glutSolidCube(1.0);
	glPopMatrix();
}

/**
* Draws Head and updates approtiate rotation matrix. 
*/
void drawHead()
{
	glPushMatrix();
		glColor3ub(218, 165, 32);
		glTranslatef(0.0, -3.0,0.0);
		glRotatef((GLfloat)neck[0],neck[1] + rotate[2], neck[2] + rotate[1] , neck[3] + rotate[3] );
		drawBox(1.0, 1.5, 1.3,false);
		glColor3ub(212, 175, 55);
	glPopMatrix();
}

/**
* Draws arm and updates rotation matrix. 
* @param aShoulder: array of Shoulder values required for rotation
* @param aElbow : array of Elbow values required for rotation
*/
void drawArm(float aShoulder[],float aElbow[])
{
		glTranslatef(0.0, 1.0, 0.0);
		glRotatef((GLfloat)aShoulder[0], aShoulder[1] + rotate[1], aShoulder[2] + rotate[2], aShoulder[3] + rotate[3]);
		glTranslatef(0.0, -1.0, 0.0);

		glPushMatrix();
			drawBox(0.5, 1.5, 0.5,true);
		glPopMatrix();
		
		glTranslatef(0.0, -2.3, 0.0);
		glTranslatef(0.0, 1.1, 0.0);
		glRotatef((GLfloat)aElbow[0], aElbow[1] + rotate[1], aElbow[2] + rotate[2], aElbow[3] + rotate[3]);
		glTranslatef(0.0, -1.1, 0.0);
		
		glPushMatrix();
				drawBox(0.5, 1.5, 0.5,true);
		glPopMatrix();	
}

/**
* Draws upperBody -torso along with left and right arms. 
*/
void drawUpperBody()
{

	glTranslatef(0.0, -5.0, 0.0);
	glPushMatrix();
	drawBox(3.0, 2.5, 2.0,false);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0, 0.0, 0.0);
		drawArm(rightShoulder,rightElbow);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, 0.0, 0.0);
		drawArm(leftShoulder,leftElbow);
	glPopMatrix();
	
	glPushMatrix();
}

/**
* Draws leg and updates associated rotation matrix.
* @param aHip: array of Hip values required for rotation
* @param aKnee: array of Knee values required for rotation
*/
void drawLeg(float aHip[],float aKnee[])
{
		glTranslatef(0.5, 1.0, 0.0);
		glRotatef((GLfloat)aHip[0], aHip[2] +  rotate[1],aHip[1] + rotate[2],aHip[3] + rotate[3]);
		glTranslatef(-0.5, -1.0, 0.0);
	glPushMatrix();
		drawBox(1.0, 1.25, 1.0,true);
	glPopMatrix();

		glTranslatef(0.0, -2.0, 0.0);
		glTranslatef(1.0, 1.0, 0.0);
		glRotatef((GLfloat)aKnee[0], aKnee[2] + rotate[1], aKnee[1] + rotate[2], aKnee[3] + rotate[3]);
		glTranslatef(-1.0, -1.0, 0.0);
	glPushMatrix();
		drawBox(0.5, 2.2, 0.75,true);
	glPopMatrix();
}

/**
* Draws LowerBody
*/
void drawLowerBody()
{
	glTranslatef(0.0, -2.0, 0.0);
	glPushMatrix();
		glTranslatef(0.8, -0.8, 0.0);
		drawLeg(rightHip,rightKnee);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.8, -0.8, 0.0);
		drawLeg(leftHip,leftKnee);
	glPopMatrix(); // Lower Body
	glPopMatrix(); // upper body	
}

/**
* Draw Robot- container method for all asociated drawing, 
* maintains robot rotation and translation. 
*/
void drawRobot()
{
	glPushMatrix();
		glColor3ub(238, 232, 170);
		glTranslatef(robotPos[0], robotPos[1],robotPos[2]);
		glRotatef((GLfloat)rotate[0], rotate[2], rotate[1],rotate[3]);
		drawHead();
		drawUpperBody();
		drawLowerBody();
	glPopMatrix();
}

/**
* Display - called glutPosRedisplay or animate()
*/
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	drawRobot();
	glutSwapBuffers();
}

/**
* Animate - Sleep and re-draw scene. 
*/
void animate(void)
{
	//uSleep(10);
	Sleep(10);
	display();
}

/**
* animateWalk - Called when user interacts with arrow keys 
* legPos flag is used to maintain leftLeg position used to create infinite 
* walk animation. 
*/
void animateWalk()
{
	if (!legPos )
	{
		if (leftHip[0] != 45)
		{
			leftHip[0]++;
			rightHip[0]--;
			rightShoulder[0]+=0.5;
			leftShoulder[0] -= 0.5;
			if (rightHip[0] < 0 && rightHip[0] > -20)
			{
				rightKnee[0]++;
				leftElbow[1]-=2;
				leftElbow[0]+=2;
			}
			if (leftKnee[0] != 0 && leftHip[0] > 20)
			{
				leftKnee[0]--;
				rightElbow[0]-=2;
				rightElbow[1]+=2;
			}				
		}
		else
		{
			legPos = true;
			
		}
	}
	else if (legPos)
	{
		if (leftHip[0] != -45)
		{
			if (leftHip[0] < 0 && leftHip[0] > -20)
			{
				leftKnee[0]++;
				rightElbow[0]+=2;
				rightElbow[1]-=2;
			}

			leftHip[0]--;
			leftShoulder[0] += 0.5;
		}
		if (rightHip[0] != 45)
		{
			if (rightKnee[0] != 0 && rightHip[0] > 20)
			{
				rightKnee[0]--;
				leftElbow[0]-=2;
				leftElbow[1]+=2;
			}
			rightHip[0]++;
			rightShoulder[0]-=0.5;
		}
		else
		{
			legPos = false;
		}
	}
}

/**
* animateKick - Reset values to default and animate kick. 
*/
void animateKick()
{
	reset();
	for (int i = 0; i <= 90; i++)
	{
		if (!legPos && leftHip[0] >= 0)
		{
			if (leftHip[0] <= 45)
			{
				leftHip[0] += 2;
				if (leftHip[0] >= -20)
					leftKnee[0] +=  2;
			}
			else
				legPos = true;
		}
		else if (legPos)
		{
			if (leftHip[0] >= -45)
			{
				leftHip[0] -= 2;
				if (leftHip[0] > -20 && leftKnee[0] != -15)
					leftKnee[0] -= 2;
			}
			else
				legPos = false;
		}
		else if (!legPos && leftHip[0] < 0)
		{
				leftHip[0]+=2;
				if (leftKnee[0] <= 0)
					leftKnee[0]+=2;
		}
		// GlutPostRedisplay doesnt work here, as it called when the system is free
		// cannot be called from within a foor loop. 
		animate();
	}
}

/**
* animateWave - reset values to default and perform wave animation 
*/
void animateWave()
{
	reset();
	bool armExtend = false;
	for(int i = 0; i < 80;i++)
	{	
		if (!armExtend)
		{
			if (leftShoulder[0] > -180)
			{
				leftShoulder[0] -= 10;
			}
			else
				armExtend = true;
		}
		if(armExtend)
{
			leftShoulder[3] = 90;
			if (i < 40)
			{
				leftShoulder[0]++;
			}
			else
			{
				leftShoulder[0]--;
			}
		}
		// GlutPostRedisplay doesnt work here, as it called when the system is free
		// cannot be called from within a foor loop. 
		animate();
	}
	reset();
}

/**
* animateDance - reset values to default and cossask dance
*/
void animateDance()
{
	reset();
	bool dance = false;
	for (int i = 0; i < 100; i++)
	{
		if (!dance)
		{
			// Set up inital dance pos. 
			if (leftHip[0] > -90)
			{

				leftHip[0] -= 5;
				rightHip[0] -= 5;
				leftShoulder[1] += 5;
				rightShoulder[1] -= 5;
				leftElbow[3] -= 5;
				leftElbow[0] -= 5;
				rightElbow[3] -= 5;
				rightElbow[0] += 5;

				if (rightShoulder[0] < 70)
				{
					rightShoulder[0] += 5;
					leftShoulder[0] -= 5;
				}
			}
			
			// Dance - Left
			if (leftKnee[0] < 90)
			{
				leftKnee[0] += 5;
				if (leftKnee[0] < 45)
				{
					robotPos[0] += 0.01;
					robotPos[1] += 0.01;
				}
				else
				{
					robotPos[0] -= 0.01;
					robotPos[1] -= 0.01;
				}

				if (rightKnee[0] != 0)
				{
					rightKnee[0] -= 5;
				}
			}
			else
				dance = true;
		}
		if(dance)
		{
			// Dance - right
			if (rightKnee[0] < 90)
			{
				rightKnee[0] +=5 ;
				leftKnee[0] -= 5;
				if (rightKnee[0] < 45)
				{
					robotPos[0] -= 0.01;
					robotPos[1] += 0.01;
				}
				else
				{
					robotPos[0] += 0.01;
					robotPos[1] -= 0.01;
				}
			}
			else
				dance = false; // back to left 
		}
		// GlutPostRedisplay doesnt work here, as it called when the system is free
		// cannot be called from within a foor loop. 
		animate();
	}
	reset();
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		animateKick();
		glutPostRedisplay();
		break;
	case '2':
		animateWave();
		glutPostRedisplay();
		break;
	case '3':
		animateDance();
		glutPostRedisplay();
		break;
	case '4':
		animateWalk();
		glutPostRedisplay();
		break;
	case 'h':
		neck[0]--;
		glutPostRedisplay();
		break;

	case 'H':
		neck[0]++;
		glutPostRedisplay();
		break;

	case 'a':
		leftShoulder[0]--;
		rightShoulder[0]--;
		glutPostRedisplay();
		break;
	case 'A':
		leftShoulder[0]++;
		rightShoulder[0]++;
		glutPostRedisplay();
		break;
	case '-':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutPostRedisplay();
		break;
	case '+':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutPostRedisplay();
		break;

	case '/':
		reset();
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void keyboardSpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		robotPos[2] += cos(getRadians(rotate[0]))*0.07;
		robotPos[0] += sin(getRadians(rotate[0])) * 0.07;
		animateWalk();
		glutPostRedisplay();
		break; 
	case GLUT_KEY_DOWN:
		robotPos[2] -= cos(getRadians(rotate[0]))*0.07;
		robotPos[0] -= sin(getRadians(rotate[0])) * 0.07;
		animateWalk();
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		rotate[0]--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		rotate[0]++;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN:
		robotPos[1]--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP:
		robotPos[1]++;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(animate);
	glutSpecialFunc(keyboardSpecial);
	glutMainLoop();
	return 0;
}
