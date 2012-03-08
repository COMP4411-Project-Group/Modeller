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
				drawCylinder(0.5, 0.25, 0.05);
			glPopMatrix();
	
			// right tooth
			glPushMatrix();
				glTranslated(-0.3, 0, -0.2);
				glRotated(VAL(RIGHT_TOOTH_ROTATE_Y), 0, 1, 0);
				drawCylinder(0.5, 0.25, 0.05);
			glPopMatrix();
	
			// left antenna
			glPushMatrix();
				glTranslated(-0.3, 0, 0.4);
				glRotated(-75, 0, 1, 0);
				glRotated(-30, 1, 0, 0);
				drawCylinder(1, 0.1, 0.1);
	
				glPushMatrix();
					glTranslated(0, 0, 1);
					glRotated(-30, 0, 1, 0);
					glRotated(45, 1, 0, 0);
					drawCylinder(0.7, 0.1, 0);
				glPopMatrix();
			glPopMatrix();
			
			// right antenna
			glPushMatrix();
				glTranslated(-0.3, 0, -0.4);
				glRotated(-105, 0, 1, 0);
				glRotated(-30, 1, 0, 0);
				drawCylinder(1, 0.1, 0.1);
	
				glPushMatrix();
					glTranslated(0, 0, 1);
					glRotated(30, 0, 1, 0);
					glRotated(45, 1, 0, 0);
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
					glRotated(-60, 0, 1, 0);
					glRotated(-30, 1, 0, 0);
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(-40, 0, 1, 0);
						glRotated(50, 1, 0, 0);
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(-20, 0, 1, 0);
							glRotated(20, 1, 0, 0);
							drawCylinder(2, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// left 2
				glPushMatrix();
					glRotated(-30, 0, 1, 0);
					glRotated(-25, 1, 0, 0);
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(-30, 0, 1, 0);
						glRotated(40, 1, 0, 0);
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(-20, 0, 1, 0);
							glRotated(30, 1, 0, 0);
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// left 3
				glPushMatrix();
					glRotated(20, 0, 1, 0);
					glRotated(-30, 1, 0, 0);
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(20, 0, 1, 0);
						glRotated(50, 1, 0, 0);
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(20, 0, 1, 0);
							glRotated(40, 1, 0, 0);
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
				
				// left 4
				glPushMatrix();
					glRotated(60, 0, 1, 0);
					glRotated(-20, 1, 0, 0);
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(20, 0, 1, 0);
						glRotated(40, 1, 0, 0);
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(20, 0, 1, 0);
							glRotated(20, 1, 0, 0);
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
					glRotated(-120, 0, 1, 0);
					glRotated(-30, 1, 0, 0);
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(40, 0, 1, 0);
						glRotated(50, 1, 0, 0);
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(20, 0, 1, 0);
							glRotated(20, 1, 0, 0);
							drawCylinder(2, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// right 2
				glPushMatrix();
					glRotated(-150, 0, 1, 0);
					glRotated(-25, 1, 0, 0);
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(30, 0, 1, 0);
						glRotated(40, 1, 0, 0);
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(20, 0, 1, 0);
							glRotated(30, 1, 0, 0);
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
	
				// right 3
				glPushMatrix();
					glRotated(160, 0, 1, 0);
					glRotated(-30, 1, 0, 0);
					drawCylinder(1.5, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(-20, 0, 1, 0);
						glRotated(50, 1, 0, 0);
						drawCylinder(1.5, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(-20, 0, 1, 0);
							glRotated(40, 1, 0, 0);
							drawCylinder(1.5, 0.1, 0);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
				
				// right 4
				glPushMatrix();
					glRotated(120, 0, 1, 0);
					glRotated(-20, 1, 0, 0);
					drawCylinder(2, 0.1, 0.1);
	
					glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(-20, 0, 1, 0);
						glRotated(40, 1, 0, 0);
						drawCylinder(2, 0.1, 0.1);
	
						glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(-20, 0, 1, 0);
							glRotated(20, 1, 0, 0);
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
				glRotated(90, 0, 1, 0);
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

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
