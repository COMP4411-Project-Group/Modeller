// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	// draw the floor
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_GREEN);

	glPushMatrix();
	glTranslated(-5,0,-5);
	drawBox(10,0.01f,10);
	glPopMatrix();

	setDiffuseColor(0.6f, 0.4f, 0.2f);

	// body
	glPushMatrix();
		glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		glTranslated(0, 1, 0);
		glPushMatrix();
			glScaled(1.3, 1, 1);
			drawSphere(0.7);
		glPopMatrix();


		// head part
		glPushMatrix();
			glTranslated(-0.6, 0, 0);
			drawSphere(0.5);
	
			// left tooth
			glPushMatrix();
				glTranslated(-0.3, 0, 0.2);
				glRotated(VAL(LEFT_TOOTH_ROTATE_Y), 0, 1, 0);
				drawCylinder(0.25, 0.25, 0.05);
			glPopMatrix();
	
			// right tooth
			glPushMatrix();
				glTranslated(-0.3, 0, -0.2);
				glRotated(VAL(RIGHT_TOOTH_ROTATE_Y), 0, 1, 0);
				drawCylinder(0.25, 0.25, 0.05);
			glPopMatrix();
	
			// left antenna
			glPushMatrix();
				glTranslated(-0.3, 0, 0.4);
				glRotated(VAL(LEFT_ANTENNA_ROTATE_Y), 0, 1, 0); // -75
				glRotated(VAL(LEFT_ANTENNA_ROTATE_X), 1, 0, 0); // -30
				drawCylinder(1, 0.1, 0.1);
	
				glPushMatrix();
					glTranslated(0, 0, 1);
					glRotated(VAL(LEFT_ANTENNA_UPPER_ROTATE_Y), 0, 1, 0); // -30
					glRotated(VAL(LEFT_ANTENNA_UPPER_ROTATE_X), 1, 0, 0); // 45
					drawCylinder(0.7, 0.1, 0);
				glPopMatrix();
			glPopMatrix();
			
			// right antenna
			glPushMatrix();
				glTranslated(-0.3, 0, -0.4);
				glRotated(VAL(RIGHT_ANTENNA_ROTATE_Y), 0, 1, 0);
				glRotated(VAL(RIGHT_ANTENNA_ROTATE_X), 1, 0, 0);
				drawCylinder(1, 0.1, 0.1);
	
				glPushMatrix();
					glTranslated(0, 0, 1);
					glRotated(VAL(RIGHT_ANTENNA_UPPER_ROTATE_Y), 0, 1, 0);
					glRotated(VAL(RIGHT_ANTENNA_UPPER_ROTATE_X), 1, 0, 0);
					drawCylinder(0.7, 0.1, 0);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// legs
		glPushMatrix();

			// left legs
			glPushMatrix();
			glTranslated(0, 0, 0.3);

				// left 1
				glPushMatrix();
					glRotated(VAL(LEFT_LEG_1_1_ROTATE_Y), 0, 1, 0); // -60
					glRotated(VAL(LEFT_LEG_1_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(LEFT_LEG_1_2_ROTATE_Y), 0, 1, 0); // -40
						glRotated(VAL(LEFT_LEG_1_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(LEFT_LEG_1_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(LEFT_LEG_1_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// left 2
				glPushMatrix();
					glRotated(VAL(LEFT_LEG_2_1_ROTATE_Y), 0, 1, 0); // -30
					glRotated(VAL(LEFT_LEG_2_1_ROTATE_X), 1, 0, 0); // -25
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(LEFT_LEG_2_2_ROTATE_Y), 0, 1, 0); // -30
						glRotated(VAL(LEFT_LEG_2_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(LEFT_LEG_2_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(LEFT_LEG_2_3_ROTATE_X), 1, 0, 0); // 30
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// left 3
				glPushMatrix();
					glRotated(VAL(LEFT_LEG_3_1_ROTATE_Y), 0, 1, 0); // 20
					glRotated(VAL(LEFT_LEG_3_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(LEFT_LEG_3_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(LEFT_LEG_3_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(LEFT_LEG_3_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(LEFT_LEG_3_3_ROTATE_X), 1, 0, 0); // 40
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
				
				// left 4
				glPushMatrix();
					glRotated(VAL(LEFT_LEG_4_1_ROTATE_Y), 0, 1, 0); // 60
					glRotated(VAL(LEFT_LEG_4_1_ROTATE_X), 1, 0, 0); // -20
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(LEFT_LEG_4_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(LEFT_LEG_4_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(LEFT_LEG_4_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(LEFT_LEG_4_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();

			glPopMatrix();

			// right legs
			glPushMatrix();
			glTranslated(0, 0, -0.3);

				// right 1
				glPushMatrix();
					glRotated(VAL(RIGHT_LEG_1_1_ROTATE_Y), 0, 1, 0); // -60
					glRotated(VAL(RIGHT_LEG_1_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(RIGHT_LEG_1_2_ROTATE_Y), 0, 1, 0); // -40
						glRotated(VAL(RIGHT_LEG_1_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(RIGHT_LEG_1_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(RIGHT_LEG_1_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// right 2
				glPushMatrix();
					glRotated(VAL(RIGHT_LEG_2_1_ROTATE_Y), 0, 1, 0); // -30
					glRotated(VAL(RIGHT_LEG_2_1_ROTATE_X), 1, 0, 0); // -25
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(RIGHT_LEG_2_2_ROTATE_Y), 0, 1, 0); // -30
						glRotated(VAL(RIGHT_LEG_2_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(RIGHT_LEG_2_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(RIGHT_LEG_2_3_ROTATE_X), 1, 0, 0); // 30
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// right 3
				glPushMatrix();
					glRotated(VAL(RIGHT_LEG_3_1_ROTATE_Y), 0, 1, 0); // 20
					glRotated(VAL(RIGHT_LEG_3_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(RIGHT_LEG_3_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(RIGHT_LEG_3_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(RIGHT_LEG_3_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(RIGHT_LEG_3_3_ROTATE_X), 1, 0, 0); // 40
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
				
				// right 4
				glPushMatrix();
					glRotated(VAL(RIGHT_LEG_4_1_ROTATE_Y), 0, 1, 0); // 60
					glRotated(VAL(RIGHT_LEG_4_1_ROTATE_X), 1, 0, 0); // -20
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(RIGHT_LEG_4_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(RIGHT_LEG_4_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(RIGHT_LEG_4_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(RIGHT_LEG_4_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();

			glPopMatrix();
		glPopMatrix();
		
		// belly
		glPushMatrix();
			glScaled(1.1, 0.7, 0.8);
			glTranslated(1.5, 0, 0);
			drawSphere(1.2);

			// spinneret
			glPushMatrix();
				glTranslated(1.1, 0, 0);
				glRotated(VAL(SPINNERET_ROTATE_Y), 0, 1, 0); // 90
				glRotated(VAL(SPINNERET_ROTATE_X), 1, 0, 0); // 0
				drawCylinder(0.3, 0.2, 0);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);

    controls[LEFT_TOOTH_ROTATE_Y] = ModelerControl("Left Tooth Rotate Y", -60, -120, 1, -90);
    controls[RIGHT_TOOTH_ROTATE_Y] = ModelerControl("Right Tooth Rotate Y", -60, -120, 1, -90);

    controls[LEFT_ANTENNA_ROTATE_Y] = ModelerControl("Left Antenna Rotate Y", -60, -90, 1, -75);
    controls[LEFT_ANTENNA_ROTATE_X] = ModelerControl("Left Antenna Rotate X", -0, -60, 1, -30);
    controls[LEFT_ANTENNA_UPPER_ROTATE_Y] = ModelerControl("Left Antenna Upper Rotate Y", -0, -60, 1, -30);
    controls[LEFT_ANTENNA_UPPER_ROTATE_X] = ModelerControl("Right Antenna Upper Rotate X", 30, 60, 1, 45);

    controls[RIGHT_ANTENNA_ROTATE_Y] = ModelerControl("Right Antenna Rotate Y", -90, -120, 1, -105);
    controls[RIGHT_ANTENNA_ROTATE_X] = ModelerControl("Right Antenna Rotate X", -0, -60, 1, -30);
    controls[RIGHT_ANTENNA_UPPER_ROTATE_Y] = ModelerControl("Right Antenna Upper Rotate Y", 0, 60, 1, 30);
    controls[RIGHT_ANTENNA_UPPER_ROTATE_X] = ModelerControl("Right Antenna Upper Rotate X", 30, 60, 1, 45);

    controls[LEFT_LEG_1_1_ROTATE_Y] = ModelerControl("Left Leg 1 First Part Rotate Y", -30, -90, 1, -60);
    controls[LEFT_LEG_1_1_ROTATE_X] = ModelerControl("Left Leg 1 First Part Rotate X", -0, -60, 1, -30);
    controls[LEFT_LEG_1_2_ROTATE_Y] = ModelerControl("Left Leg 1 Second Part Rotate Y", -10, -70, 1, -40);
    controls[LEFT_LEG_1_2_ROTATE_X] = ModelerControl("Left Leg 1 Second Part Rotate X", 20, 80, 1, 50);
    controls[LEFT_LEG_1_3_ROTATE_Y] = ModelerControl("Left Leg 1 Third Part Rotate Y", 10, -50, 1, -20);
    controls[LEFT_LEG_1_3_ROTATE_X] = ModelerControl("Left Leg 1 Third Part Rotate X", -10, 50, 1, 20);

    controls[LEFT_LEG_2_1_ROTATE_Y] = ModelerControl("Left Leg 2 First Part Rotate Y", -0, -60, 1, -30);
    controls[LEFT_LEG_2_1_ROTATE_X] = ModelerControl("Left Leg 2 First Part Rotate X", 5, -55, 1, -25);
    controls[LEFT_LEG_2_2_ROTATE_Y] = ModelerControl("Left Leg 2 Second Part Rotate Y", -0, -60, 1, -30);
    controls[LEFT_LEG_2_2_ROTATE_X] = ModelerControl("Left Leg 2 Second Part Rotate X", 10, 70, 1, 40);
    controls[LEFT_LEG_2_3_ROTATE_Y] = ModelerControl("Left Leg 2 Third Part Rotate Y", 10, -50, 1, -20);
    controls[LEFT_LEG_2_3_ROTATE_X] = ModelerControl("Left Leg 2 Third Part Rotate X", 0, 60, 1, 30);

    controls[LEFT_LEG_3_1_ROTATE_Y] = ModelerControl("Left Leg 3 First Part Rotate Y", -10, 50, 1, 20);
    controls[LEFT_LEG_3_1_ROTATE_X] = ModelerControl("Left Leg 3 First Part Rotate X", 0, -60, 1, -30);
    controls[LEFT_LEG_3_2_ROTATE_Y] = ModelerControl("Left Leg 3 Second Part Rotate Y", -10, 50, 1, 20);
    controls[LEFT_LEG_3_2_ROTATE_X] = ModelerControl("Left Leg 3 Second Part Rotate X", 20, 80, 1, 50);
    controls[LEFT_LEG_3_3_ROTATE_Y] = ModelerControl("Left Leg 3 Third Part Rotate Y", -10, 50, 1, 20);
    controls[LEFT_LEG_3_3_ROTATE_X] = ModelerControl("Left Leg 3 Third Part Rotate X", 10, 70, 1, 40);

    controls[LEFT_LEG_4_1_ROTATE_Y] = ModelerControl("Left Leg 4 First Part Rotate Y", 30, 90, 1, 60);
    controls[LEFT_LEG_4_1_ROTATE_X] = ModelerControl("Left Leg 4 First Part Rotate X", 10, -50, 1, -20);
    controls[LEFT_LEG_4_2_ROTATE_Y] = ModelerControl("Left Leg 4 Second Part Rotate Y", -10, 50, 1, 20);
    controls[LEFT_LEG_4_2_ROTATE_X] = ModelerControl("Left Leg 4 Second Part Rotate X", 10, 70, 1, 40);
    controls[LEFT_LEG_4_3_ROTATE_Y] = ModelerControl("Left Leg 4 Third Part Rotate Y", -10, 50, 1, 20);
    controls[LEFT_LEG_4_3_ROTATE_X] = ModelerControl("Left Leg 4 Third Part Rotate X", -10, 50, 1, 20);

    controls[RIGHT_LEG_1_1_ROTATE_Y] = ModelerControl("Right Leg 1 First Part Rotate Y", -90, -150, 1, -120);
    controls[RIGHT_LEG_1_1_ROTATE_X] = ModelerControl("Right Leg 1 First Part Rotate X", 0, -60, 1, -30);
    controls[RIGHT_LEG_1_2_ROTATE_Y] = ModelerControl("Right Leg 1 Second Part Rotate Y", 10, 70, 1, 40);
    controls[RIGHT_LEG_1_2_ROTATE_X] = ModelerControl("Right Leg 1 Second Part Rotate X", 20, 80, 1, 50);
    controls[RIGHT_LEG_1_3_ROTATE_Y] = ModelerControl("Right Leg 1 Third Part Rotate Y", -10, 50, 1, 20);
    controls[RIGHT_LEG_1_3_ROTATE_X] = ModelerControl("Right Leg 1 Third Part Rotate X", -10, 50, 1, 20);

    controls[RIGHT_LEG_2_1_ROTATE_Y] = ModelerControl("Right Leg 2 First Part Rotate Y", -120, -180, 1, -150);
    controls[RIGHT_LEG_2_1_ROTATE_X] = ModelerControl("Right Leg 2 First Part Rotate X", 5, -55, 1, -25);
    controls[RIGHT_LEG_2_2_ROTATE_Y] = ModelerControl("Right Leg 2 Second Part Rotate Y", 0, 60, 1, 30);
    controls[RIGHT_LEG_2_2_ROTATE_X] = ModelerControl("Right Leg 2 Second Part Rotate X", 10, 70, 1, 40);
    controls[RIGHT_LEG_2_3_ROTATE_Y] = ModelerControl("Right Leg 2 Third Part Rotate Y", -10, 50, 1, 20);
    controls[RIGHT_LEG_2_3_ROTATE_X] = ModelerControl("Right Leg 2 Third Part Rotate X", 0, 60, 1, 30);

    controls[RIGHT_LEG_3_1_ROTATE_Y] = ModelerControl("Right Leg 3 First Part Rotate Y", 120, 190, 1, 160);
    controls[RIGHT_LEG_3_1_ROTATE_X] = ModelerControl("Right Leg 3 First Part Rotate X", 0, -60, 1, -30);
    controls[RIGHT_LEG_3_2_ROTATE_Y] = ModelerControl("Right Leg 3 Second Part Rotate Y", 10, -50, 1, -20);
    controls[RIGHT_LEG_3_2_ROTATE_X] = ModelerControl("Right Leg 3 Second Part Rotate X", 20, 80, 1, 50);
    controls[RIGHT_LEG_3_3_ROTATE_Y] = ModelerControl("Right Leg 3 Third Part Rotate Y", 10, -50, 1, -20);
    controls[RIGHT_LEG_3_3_ROTATE_X] = ModelerControl("Right Leg 3 Third Part Rotate X", 10, 70, 1, 40);

    controls[RIGHT_LEG_4_1_ROTATE_Y] = ModelerControl("Right Leg 4 First Part Rotate Y", 90, 150, 1, 120);
    controls[RIGHT_LEG_4_1_ROTATE_X] = ModelerControl("Right Leg 4 First Part Rotate X", 10, -50, 1, -20);
    controls[RIGHT_LEG_4_2_ROTATE_Y] = ModelerControl("Right Leg 4 Second Part Rotate Y", 10, -50, 1, -20);
    controls[RIGHT_LEG_4_2_ROTATE_X] = ModelerControl("Right Leg 4 Second Part Rotate X", 10, 70, 1, 40);
    controls[RIGHT_LEG_4_3_ROTATE_Y] = ModelerControl("Right Leg 4 Third Part Rotate Y", 10, -50, 1, -20);
    controls[RIGHT_LEG_4_3_ROTATE_X] = ModelerControl("Right Leg 4 Third Part Rotate X", -10, 50, 1, 20);

    controls[SPINNERET_ROTATE_Y] = ModelerControl("Spinneret Rotate Y", 75, 105, 1, 90);
    controls[SPINNERET_ROTATE_X] = ModelerControl("Spinneret Rotate Y", -15, 15, 1, 0);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
