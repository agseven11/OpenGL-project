
#include<GL/glut.h>
#define dx 32
#define dy 32
#define maxrow 25
#define maxcol 25
#include<math.h>
#include<string.h>

double x11, y11;
int i11=0;
GLfloat z11=-650;

double x22, y22;
int i22=0;
GLfloat z22=-650;

double x33, y33;
int i33=0;
GLfloat z33=-650;

double six, siy;
int si=0;

double si1x, si1y;
int si1=0;

double si2x, si2y;
int si2=0;

GLint i, j;
GLint x[maxcol], y[maxrow];
double trw=1.4;
double tmw=1.4;
double tlw=1.45;

void init()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);

}
void rwall()   //right
{

       glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
       glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
       float ambient[] = { 0.9,0.3,0.5,1 };  //set rgb color
       float light_pos[] = { 27,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
       glRotatef(50, 0, 1, 0);
       glRotatef(10, -1, 0, 0);
       glRotatef(11.7, 0, 0, -1);
       glTranslatef(0.4, trw, 0.4);
       glScalef(0.5, 1.2, 0.07);
       glutSolidCube(1);
}
void mwall() //middle
{
       glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       float ambient[] = { 0.7,0.8,0.7,1 };
       float light_pos[] = { 27,8,2,3 };
       glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glRotatef(50, 0, 1, 0);
	glRotatef(10, -1, 0, 0);
	glRotatef(11.7, 0, 0, -1);
	glTranslatef(0.1, tmw, 0.1);
       glScalef(0.5, 1.2, 0.04);
	glutSolidCube(1);
}
void lwall()  //left
{
       glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
       glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
     	float ambient[] = { 0.7,0.7,0.1,1 };
       float light_pos[] = { 27,8,2,3 };
       glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glRotatef(50, 0, 1, 0);
	glRotatef(10, -1, 0, 0);
	glRotatef(11.7, 0, 0, -1);
	glTranslatef(-0.2, tlw, -0.2);
       glScalef(0.4, 1.2, 0.01);
	glutSolidCube(1);
}
void floor()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
       gluLookAt(0.09, -18.0, 3.0, 0.0, 0.0, 2.5, 0.0, 1.0, 0.0);
	glTranslatef(-8, -10, -2);
       glDisable(GL_LIGHTING);
	glColor3f(0.2,0.4,0.4);
	glScalef(0.02, 0.02, 0.02);
	glLineWidth(2.0);
	for (i = 0; i <= maxcol - 1; i++)
		x[i] = x[0] + i*dx;
	for (j = 0; j <= maxrow - 1; j++)
		y[j] = y[0] + j*dy;
	for (i = 0; i < maxcol - 1; i++)
	{
		for (j = 0; j < maxrow - 1; j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(x[i], y[j]);
			glVertex2f(x[i], y[j + 1]);
			glVertex2f(x[i + 1], y[j + 1]);
			glVertex2f(x[i + 1], y[j]);
			glEnd();
		}

	}
}
void gamma() //bottom;
{

       glDisable(GL_LIGHTING);
    	glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = w / h;
	glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
	glDisable(GL_LIGHTING);
	glTranslatef(z11,-45,0);
	glPointSize(5);
	glColor3f(1.0, 1.0, 0.0);
	GLfloat qa=0;
	for (GLfloat i11 = -1400; i11<=qa+10000; i11 = i11+4)
{
       glBegin(GL_POINTS);
       glVertex2f(x11,y11);
       x11 = -(float)i11;
       if(i11>=9995 && i11 <= 9998) qa = 10000;
       else if(i11>=19995 && i11 <= 19998) qa = 20000;
       else if(i11>=29995 && i11 <= 29998) qa = 30000;
       else if(i11>=39995 && i11<= 39998) qa = 40000;
       else if(i11>=49995 && i11<=49998) qa = 60000;
	y11 = 10.0 * sin(i11 *(35.284 / 360.0));
	glEnd();
}
z11+=2;
}
void beta()  //middle
{


 	glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = w / h;
	glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       glColor3f(1,0,0.7);
	glTranslatef(z22,5,0);
	glPointSize(5);
	glColor3f(0.6, 0.3, 0.8);
	GLfloat wa=0;
	for (GLfloat i22 = -1400; i22<=wa+10000; i22 = i22+4)
{
       glBegin(GL_POINTS);
       glVertex2f(x22,y22);
       x22 = -(float)i22;
       if(i22>=9995 && i22 <= 9998) wa = 10000;
       else if(i22>=19995 && i22 <= 19998) wa = 20000;
       else if(i22>=29995 && i22 <= 29998) wa = 30000;
       else if(i22>=39995 && i22<= 39998) wa = 40000;
       else if(i22>=49995 && i22<=49998) wa = 60000;
	y22 = 5.0 * sin(i22 *(35.284 / 360.0)); //increase 1st increase height,increase 2nd decrease width
	glEnd();
}
z22+=1.4;
}
void alpha()  //top
{

 	glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = w / h;
	glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
	glTranslatef(z33,40,0);
	glPointSize(5);
	glColor3f(0.9, 0., 0.4);
	for (GLfloat i33 = -1400; i33<=80200; i33 = i33+4)
{
       glBegin(GL_POINTS);
       glVertex2f(x33,y33);
       x33 = -(float)i33;
	y33 = 5.0 * sin(i33 *(15.284 / 360.0));  //increase 1st increase height,increase 2nd decrease width
	glEnd();
}
z33+=1.6;
}

void molecules()
{
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       float ambient[] = { 0.7,0.1,0.1,1 };
       float light_pos[] = { 2,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
       glTranslatef(-0.7,0.3,0.075);
       glutSolidSphere(0.08,100,100);
       float ambient1[] = { 0.1,0.3,1.0,1 };
       float light_pos1[] = { 27,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);
       glTranslatef(0,-0.3,0);
       glutSolidSphere(0.06,100,100);
       float ambient2[] = { 0.1,1.0,0.1,1 };
       float light_pos2[] = { 27,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos2);
       glTranslatef(0,-0.4,0);
       glutSolidSphere(0.09,100,100);
}
void specialkeyboard(int key,int x,int y)
{
       switch(key)
       {
       case GLUT_KEY_DOWN:
              {
                            tmw=-0.1;
                            break;
              }
       case GLUT_KEY_LEFT:
              {
                  tlw=-0.1;
                  break;

              }
       case GLUT_KEY_RIGHT:
              {
                       trw=-0.1;
                       break;
              }
       case GLUT_KEY_END:
              {
                     trw=1.45;
                     break;
              }
       case GLUT_KEY_PAGE_DOWN:
              {
                     tmw=1.4;
                     break;

              }
       case GLUT_KEY_PAGE_UP:
              {
                     tlw=1.4;
                     break;
              }
	 case GLUT_KEY_HOME:
              {
                     exit(0);
                     break;
              }
       }
}

void display()
{

       glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
       glViewport(200,0,w,h);

	if(tlw!=-0.1)
      {
             glViewport(200,0,w,h);
             alpha();
      }
      else
       {
              glViewport(200,0,w-1100,h);
              alpha();
       }

      if(tmw!=-0.1)
	{
	       glViewport(200,0,w,h);
	       beta();
	}
	else
       {
              glViewport(200,0,w-700,h);
              beta();
       }
	if(trw!=-0.1)
      {
             glViewport(200,0,w,h);
             gamma();
      }
      else
       {
              glViewport(200,0,w-400,h);
              gamma();
       }
	glViewport(0,0,w,h);
	rwall();
	mwall();
	lwall();
	molecules();
	 	char p[]="PAPER";
	 	char a[]="ALLUMINIUM";
	 	char l[]="LEAD";
	 	char al[]="ALPHA RAY";
	 	char be[]="BETA RAY";
	 	char ga[]="GAMMA RAY";
	 	char ml[]="MOLECULES";
	 	char rp[]="RADIATION PENETRATION";
	 	char tp[]="TOPIC : RADIATION";
		char an[] = "Ankur Garg(1JS16CS013)";
		char av[] = "Avinash Kumar(1JS16CS022)";
	 	char tpp[]="PENETRATION";


       glDisable(GL_LIGHTING);
       glColor3f(1,1,1);
	glRasterPos2f(0.35,-0.35);
	for(int iqa=0;iqa<strlen(p);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,p[iqa]);
       }
       glRasterPos2f(0.75,-0.35);
	for(int iqa=0;iqa<strlen(a);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[iqa]);
       }
       glRasterPos2f(1.1,-0.35);
	for(int iqa=0;iqa<strlen(l);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,l[iqa]);
       }
       glRasterPos2f(-0.3,0.7);
	for(int iqa=0;iqa<strlen(al);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,al[iqa]);
       }
       glRasterPos2f(-0.3,0.37);
	for(int iqa=0;iqa<strlen(be);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,be[iqa]);
       }
       glRasterPos2f(-0.3,-0.01);
	for(int iqa=0;iqa<strlen(ga);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ga[iqa]);
       }
       glRasterPos2f(-0.1,0.95);
	for(int iqa=0;iqa<strlen(ml);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ml[iqa]);
       }
       glRasterPos2f(0.5,1);
	for(int iqa=0;iqa<strlen(rp);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,rp[iqa]);
       }
       glRasterPos2f(1.24,-0.5);
	for(int iqa=0;iqa<strlen(tp);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,tp[iqa]);
       }
       glRasterPos2f(1.38,-0.6);
	for(int iqa=0;iqa<strlen(tpp);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,tpp[iqa]);
       }

	glRasterPos2f(-0.2,-0.35);
	for(int iqa=0;iqa<strlen(an);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,an[iqa]);
       }

	glRasterPos2f(-0.2,-0.45);
	for(int iqa=0;iqa<strlen(av);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,av[iqa]);
       }
	floor();

	glFlush();

}

void display1()
{

       glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3,0.1,0.2,0);
	
		char p[]="Guided By";
	 	char a[]="Ms. Rashmi B N";
		char b[]="Assistant Professor";
		char c[]="Mr. Sharana B Gowda";
		char d[]="Assistant Professor";
	 	char al[]="JSS ACADEMY OF TECHNICAL EDUCATION";
	 	char be[]="RADIATION PENETRATION TEST";
	 	char ga[]="Submitted By";
	 	char ml[]="VISVESVARAYA TECHNOLOGICAL UNIVERSITY";
	 	
		char an[] = "ANKUR GARG (1JS16CS013)";
		char av[] = "AVINASH KUMAR (1JS16CS022)";
	 	


       glDisable(GL_LIGHTING);
       glColor3f(1,1,1);

	glRasterPos2f(-0.4,0.8);
	for(int iqa=0;iqa<strlen(ml);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ml[iqa]);
       }

	glColor3f(0,1,1);
	glRasterPos2f(-0.35,0.60);
	for(int iqa=0;iqa<strlen(al);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,al[iqa]);
       }

	glColor3f(1,0.5,0);
	glRasterPos2f(-0.3,0.27);
	for(int iqa=0;iqa<strlen(be);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,be[iqa]);
       }

	glColor3f(0.5,1,0);

	glRasterPos2f(-0.15,0.0);
	for(int iqa=0;iqa<strlen(ga);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ga[iqa]);
       }

	
	 glRasterPos2f(-0.6,-0.25);
	for(int iqa=0;iqa<strlen(an);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,an[iqa]);
       }

	glRasterPos2f(0.1,-0.25);
	for(int iqa=0;iqa<strlen(av);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,av[iqa]);
       } 

	glColor3f(1,0,1);
	glRasterPos2f(-0.15,-0.5);
	for(int iqa=0;iqa<strlen(p);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,p[iqa]);
       }
       glRasterPos2f(-0.47,-0.65);
	for(int iqa=0;iqa<strlen(a);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[iqa]);
       }
       glRasterPos2f(-0.47,-0.75);
	for(int iqa=0;iqa<strlen(b);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b[iqa]);
       }
     
	glRasterPos2f(0.1,-0.65);
	for(int iqa=0;iqa<strlen(c);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[iqa]);
       }
       glRasterPos2f(0.1,-0.75);
	for(int iqa=0;iqa<strlen(d);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,d[iqa]);
       }
     
	
	glFlush();
}

void menu(int choice)
{
    switch(choice)
        {
        case 1:
	
		glutDisplayFunc(display);
            	display();
            	break;
        case 2:
            	tlw=-0.1;
            	break;
	case 3:
	
		tmw=-0.1;
           	break;
        case 4:
		trw=-0.1;
          	break;
	case 5:
            	tlw=1.4;
            	break;
	case 6:
	
		tmw=1.4;
           	break;
        case 7:
		trw=1.45;
          	break;
	
        case 8:
		exit(0);
		break;

	}

	glutPostRedisplay();
}


void update(int value)
{
		glutPostRedisplay();
		glutTimerFunc(1, update, 0);
}


int main(int argc, char **argv)
{
	x[0] = 1;
	y[0] = 1;
	glutInit(&argc, argv);
	init();
	glutInitWindowSize(1400, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project");

	glutCreateMenu(menu);
  	glutAddMenuEntry("Penetration",1);
	glutAddMenuEntry("Paper",2);
    	glutAddMenuEntry("Aluminium",3);
	glutAddMenuEntry("Lead",4);
	glutAddMenuEntry("Paper back",5);
    	glutAddMenuEntry("Aluminium back",6);
	glutAddMenuEntry("Lead back",7);
   	
	glutAddMenuEntry("quit",8);

	glutDisplayFunc(display1);
	glutTimerFunc(0, update, 0);
	glutSpecialFunc(specialkeyboard);
	glEnable(GL_DEPTH_TEST);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
