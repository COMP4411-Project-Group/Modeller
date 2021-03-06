// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include "meta_drawing.h"
#include <FL/gl.h>

#include "modelerglobals.h"

int currMood = 0;

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

void animate() {
	SETVAL(XPOS, VAL(XPOS) + 1);
}

void restoreMood() {
	SETVAL(XPOS, 0);
	SETVAL(YPOS, 0);
	SETVAL(ZPOS, 0);

	SETVAL(SPIDER_ROTATE_Z, 0);
	SETVAL(BODY_ROTATE_Z, 0);

	SETVAL(LEFT_TOOTH_ROTATE_Y, -90);
	SETVAL(RIGHT_TOOTH_ROTATE_Y, -90);

	SETVAL(LEFT_ANTENNA_ROTATE_Y, -75);
	SETVAL(LEFT_ANTENNA_ROTATE_X, -30);
	SETVAL(LEFT_ANTENNA_UPPER_ROTATE_Y, -30);
	SETVAL(LEFT_ANTENNA_UPPER_ROTATE_X, 45);
	SETVAL(RIGHT_ANTENNA_ROTATE_Y, -105);
	SETVAL(RIGHT_ANTENNA_ROTATE_X, -30);
	SETVAL(RIGHT_ANTENNA_UPPER_ROTATE_Y, 30);
	SETVAL(RIGHT_ANTENNA_UPPER_ROTATE_X, 45);

	SETVAL(LEFT_LEG_1_1_ROTATE_Y, -60);
	SETVAL(LEFT_LEG_1_1_ROTATE_X, -30);
	SETVAL(LEFT_LEG_1_2_ROTATE_Y, -40);
	SETVAL(LEFT_LEG_1_2_ROTATE_X, 50);
	SETVAL(LEFT_LEG_1_3_ROTATE_Y, -20);
	SETVAL(LEFT_LEG_1_3_ROTATE_X, 20);

	SETVAL(LEFT_LEG_2_1_ROTATE_Y, -30);
	SETVAL(LEFT_LEG_2_1_ROTATE_X, -25);
	SETVAL(LEFT_LEG_2_2_ROTATE_Y, -30);
	SETVAL(LEFT_LEG_2_2_ROTATE_X, 40);
	SETVAL(LEFT_LEG_2_3_ROTATE_Y, -20);
	SETVAL(LEFT_LEG_2_3_ROTATE_X, 30);

	SETVAL(LEFT_LEG_3_1_ROTATE_Y, 20);
	SETVAL(LEFT_LEG_3_1_ROTATE_X, -30);
	SETVAL(LEFT_LEG_3_2_ROTATE_Y, 20);
	SETVAL(LEFT_LEG_3_2_ROTATE_X, 50);
	SETVAL(LEFT_LEG_3_3_ROTATE_Y, 20);
	SETVAL(LEFT_LEG_3_3_ROTATE_X, 40);

	SETVAL(LEFT_LEG_4_1_ROTATE_Y, 60);
	SETVAL(LEFT_LEG_4_1_ROTATE_X, -20);
	SETVAL(LEFT_LEG_4_2_ROTATE_Y, 20);
	SETVAL(LEFT_LEG_4_2_ROTATE_X, 40);
	SETVAL(LEFT_LEG_4_3_ROTATE_Y, 20);
	SETVAL(LEFT_LEG_4_3_ROTATE_X, 20);

	SETVAL(RIGHT_LEG_1_1_ROTATE_Y, -120);
	SETVAL(RIGHT_LEG_1_1_ROTATE_X, -30);
	SETVAL(RIGHT_LEG_1_2_ROTATE_Y, 40);
	SETVAL(RIGHT_LEG_1_2_ROTATE_X, 50);
	SETVAL(RIGHT_LEG_1_3_ROTATE_Y, 20);
	SETVAL(RIGHT_LEG_1_3_ROTATE_X, 20);

	SETVAL(RIGHT_LEG_2_1_ROTATE_Y, -150);
	SETVAL(RIGHT_LEG_2_1_ROTATE_X, -25);
	SETVAL(RIGHT_LEG_2_2_ROTATE_Y, 30);
	SETVAL(RIGHT_LEG_2_2_ROTATE_X, 40);
	SETVAL(RIGHT_LEG_2_3_ROTATE_Y, 20);
	SETVAL(RIGHT_LEG_2_3_ROTATE_X, 30);

	SETVAL(RIGHT_LEG_3_1_ROTATE_Y, 160);
	SETVAL(RIGHT_LEG_3_1_ROTATE_X, -30);
	SETVAL(RIGHT_LEG_3_2_ROTATE_Y, -20);
	SETVAL(RIGHT_LEG_3_2_ROTATE_X, 50);
	SETVAL(RIGHT_LEG_3_3_ROTATE_Y, -20);
	SETVAL(RIGHT_LEG_3_3_ROTATE_X, 40);

	SETVAL(RIGHT_LEG_4_1_ROTATE_Y, 120);
	SETVAL(RIGHT_LEG_4_1_ROTATE_X, -20);
	SETVAL(RIGHT_LEG_4_2_ROTATE_Y, -20);
	SETVAL(RIGHT_LEG_4_2_ROTATE_X, 40);
	SETVAL(RIGHT_LEG_4_3_ROTATE_Y, -20);
	SETVAL(RIGHT_LEG_4_3_ROTATE_X, 20);

	SETVAL(SPINNERET_ROTATE_Y, 90);
	SETVAL(SPINNERET_ROTATE_X, 0);
}

void setMood() {
	if (VAL(MOOD) != 0) {
		restoreMood();
		if (VAL(MOOD) == 2) { // attack
			SETVAL(YPOS, 0.8f);
			SETVAL(BODY_ROTATE_Z, -40);

			SETVAL(LEFT_ANTENNA_ROTATE_Y, -90);
			SETVAL(LEFT_ANTENNA_ROTATE_X, 0);
			SETVAL(LEFT_ANTENNA_UPPER_ROTATE_Y, 0);
			SETVAL(LEFT_ANTENNA_UPPER_ROTATE_X, 60);

			SETVAL(RIGHT_ANTENNA_ROTATE_Y, -90);
			SETVAL(RIGHT_ANTENNA_ROTATE_X, 0);
			SETVAL(RIGHT_ANTENNA_UPPER_ROTATE_Y, 0);
			SETVAL(RIGHT_ANTENNA_UPPER_ROTATE_X, 60);

			SETVAL(LEFT_LEG_1_1_ROTATE_Y, -60);
			SETVAL(LEFT_LEG_1_1_ROTATE_X, -60);
			SETVAL(LEFT_LEG_1_2_ROTATE_Y, -40);
			SETVAL(LEFT_LEG_1_2_ROTATE_X, 50);
			SETVAL(LEFT_LEG_1_3_ROTATE_Y, -50);
			SETVAL(LEFT_LEG_1_3_ROTATE_X, 20);

			SETVAL(LEFT_LEG_2_1_ROTATE_Y, 0);
			SETVAL(LEFT_LEG_2_1_ROTATE_X, 5);
			SETVAL(LEFT_LEG_2_2_ROTATE_Y, 0);
			SETVAL(LEFT_LEG_2_2_ROTATE_X, 70);
			SETVAL(LEFT_LEG_2_3_ROTATE_Y, -20);
			SETVAL(LEFT_LEG_2_3_ROTATE_X, 0);

			SETVAL(LEFT_LEG_3_1_ROTATE_Y, 40);
			SETVAL(LEFT_LEG_3_1_ROTATE_X, -30);
			SETVAL(LEFT_LEG_3_2_ROTATE_Y, -10);
			SETVAL(LEFT_LEG_3_2_ROTATE_X, 50);
			SETVAL(LEFT_LEG_3_3_ROTATE_Y, -10);
			SETVAL(LEFT_LEG_3_3_ROTATE_X, 70);

			SETVAL(LEFT_LEG_4_1_ROTATE_Y, 60);
			SETVAL(LEFT_LEG_4_1_ROTATE_X, -50);
			SETVAL(LEFT_LEG_4_2_ROTATE_Y, 20);
			SETVAL(LEFT_LEG_4_2_ROTATE_X, 40);
			SETVAL(LEFT_LEG_4_3_ROTATE_Y, -10);
			SETVAL(LEFT_LEG_4_3_ROTATE_X, 50);

			SETVAL(RIGHT_LEG_1_1_ROTATE_Y, -120);
			SETVAL(RIGHT_LEG_1_1_ROTATE_X, -60);
			SETVAL(RIGHT_LEG_1_2_ROTATE_Y, 40);
			SETVAL(RIGHT_LEG_1_2_ROTATE_X, 50);
			SETVAL(RIGHT_LEG_1_3_ROTATE_Y, 20);
			SETVAL(RIGHT_LEG_1_3_ROTATE_X, 50);

			SETVAL(RIGHT_LEG_2_1_ROTATE_Y, -180);
			SETVAL(RIGHT_LEG_2_1_ROTATE_X, 5);
			SETVAL(RIGHT_LEG_2_2_ROTATE_Y, 0);
			SETVAL(RIGHT_LEG_2_2_ROTATE_X, 70);
			SETVAL(RIGHT_LEG_2_3_ROTATE_Y, 20);
			SETVAL(RIGHT_LEG_2_3_ROTATE_X, 0);

			SETVAL(RIGHT_LEG_3_1_ROTATE_Y, 140);
			SETVAL(RIGHT_LEG_3_1_ROTATE_X, -30);
			SETVAL(RIGHT_LEG_3_2_ROTATE_Y, 10);
			SETVAL(RIGHT_LEG_3_2_ROTATE_X, 50);
			SETVAL(RIGHT_LEG_3_3_ROTATE_Y, 10);
			SETVAL(RIGHT_LEG_3_3_ROTATE_X, 70);

			SETVAL(RIGHT_LEG_4_1_ROTATE_Y, 120);
			SETVAL(RIGHT_LEG_4_1_ROTATE_X, -50);
			SETVAL(RIGHT_LEG_4_2_ROTATE_Y, -20);
			SETVAL(RIGHT_LEG_4_2_ROTATE_X, 40);
			SETVAL(RIGHT_LEG_4_3_ROTATE_Y, 10);
			SETVAL(RIGHT_LEG_4_3_ROTATE_X, 50);

			SETVAL(SPINNERET_ROTATE_Y, -15);
		} else if (VAL(MOOD) == 3) { // dead
			SETVAL(SPIDER_ROTATE_Z, -180);

			SETVAL(LEFT_ANTENNA_ROTATE_X, 0);
			SETVAL(LEFT_ANTENNA_UPPER_ROTATE_X, 60);
			SETVAL(RIGHT_ANTENNA_ROTATE_X, 0);
			SETVAL(RIGHT_ANTENNA_UPPER_ROTATE_X, 60);

			SETVAL(LEFT_LEG_1_1_ROTATE_X, 0);
			SETVAL(LEFT_LEG_1_2_ROTATE_X, 80);
			SETVAL(LEFT_LEG_1_3_ROTATE_X, 50);

			SETVAL(LEFT_LEG_2_1_ROTATE_X, 5);
			SETVAL(LEFT_LEG_2_2_ROTATE_X, 70);
			SETVAL(LEFT_LEG_2_3_ROTATE_X, 60);

			SETVAL(LEFT_LEG_3_1_ROTATE_X, 0);
			SETVAL(LEFT_LEG_3_2_ROTATE_X, 80);
			SETVAL(LEFT_LEG_3_3_ROTATE_X, 70);

			SETVAL(LEFT_LEG_4_1_ROTATE_X, 10);
			SETVAL(LEFT_LEG_4_2_ROTATE_X, 70);
			SETVAL(LEFT_LEG_4_3_ROTATE_X, 50);

			SETVAL(RIGHT_LEG_1_1_ROTATE_X, 0);
			SETVAL(RIGHT_LEG_1_2_ROTATE_X, 80);
			SETVAL(RIGHT_LEG_1_3_ROTATE_X, 50);

			SETVAL(RIGHT_LEG_2_1_ROTATE_X, 5);
			SETVAL(RIGHT_LEG_2_2_ROTATE_X, 70);
			SETVAL(RIGHT_LEG_2_3_ROTATE_X, 60);

			SETVAL(RIGHT_LEG_3_1_ROTATE_X, 0);
			SETVAL(RIGHT_LEG_3_2_ROTATE_X, 80);
			SETVAL(RIGHT_LEG_3_3_ROTATE_X, 70);

			SETVAL(RIGHT_LEG_4_1_ROTATE_X, 10);
			SETVAL(RIGHT_LEG_4_2_ROTATE_X, 70);
			SETVAL(RIGHT_LEG_4_3_ROTATE_X, 50);
		}
	}
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
	setDiffuseColor(1, 1, 1);
	//drawSphere(6.0);
	// drawTwoBalls();

	drawWeb(9, 15);

	setDiffuseColor(0.5f, 0.4f, 0.4f);

	#define DETAIL (VAL(LEVEL_OF_DETAIL))

	if (currMood != VAL(MOOD)) {
		setMood();
		currMood = VAL(MOOD);
	}

	if (VAL(ANIMATE)) {
		animate();
	}

	// whole
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
	glTranslated(0, 1.5, 0);
	glRotated(VAL(SPIDER_ROTATE_Z), 0, 0, 1);


	if (DETAIL >= 1) {
		// belly
		glPushMatrix();
		glTranslated(1.5, 0, 0);
		glScaled(1.1, 0.7, 0.8);
		drawSphere(1.2);

		// spinneret
		if (DETAIL >= 2) {
			glPushMatrix();
			glTranslated(1.1, 0, 0);
			glRotated(VAL(SPINNERET_ROTATE_Y), 0, 1, 0); // 90
			glRotated(VAL(SPINNERET_ROTATE_X), 1, 0, 0); // 0
			drawCylinder(0.3, 0.2, 0);
			glPopMatrix();
		}
		glPopMatrix();
	}


	if (DETAIL >= 1) {
		// body
		if (DETAIL >= 2) {
			glPushMatrix();
			glRotated(VAL(BODY_ROTATE_Z), 0, 0, 1);
				glPushMatrix();
				glScaled(1.3, 1, 1);
				drawSphere(0.5);
				glPopMatrix();
			// legs
			if (DETAIL >= 3) {

				// left legs
				glPushMatrix();
				glTranslated(0, 0, 0.3);

				if (DETAIL >= 4) {
					// left 1
					glPushMatrix();
					glRotated(VAL(LEFT_LEG_1_1_ROTATE_Y), 0, 1, 0); // -60
					glRotated(VAL(LEFT_LEG_1_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(2, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(LEFT_LEG_1_2_ROTATE_Y), 0, 1, 0); // -40
						glRotated(VAL(LEFT_LEG_1_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(2, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(LEFT_LEG_1_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(LEFT_LEG_1_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
							// drawSphere(0.2);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();

					// left 2
					glPushMatrix();
					glRotated(VAL(LEFT_LEG_2_1_ROTATE_Y), 0, 1, 0); // -30
					glRotated(VAL(LEFT_LEG_2_1_ROTATE_X), 1, 0, 0); // -25
					drawCylinder(1.5, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(LEFT_LEG_2_2_ROTATE_Y), 0, 1, 0); // -30
						glRotated(VAL(LEFT_LEG_2_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(1.5, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(LEFT_LEG_2_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(LEFT_LEG_2_3_ROTATE_X), 1, 0, 0); // 30
							drawCylinder(1.5, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();

					// left 3
					glPushMatrix();
					glRotated(VAL(LEFT_LEG_3_1_ROTATE_Y), 0, 1, 0); // 20
					glRotated(VAL(LEFT_LEG_3_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(1.5, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(LEFT_LEG_3_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(LEFT_LEG_3_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(1.5, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(LEFT_LEG_3_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(LEFT_LEG_3_3_ROTATE_X), 1, 0, 0); // 40
							drawCylinder(1.5, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();

					// left 4
					glPushMatrix();
					glRotated(VAL(LEFT_LEG_4_1_ROTATE_Y), 0, 1, 0); // 60
					glRotated(VAL(LEFT_LEG_4_1_ROTATE_X), 1, 0, 0); // -20
					drawCylinder(2, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(LEFT_LEG_4_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(LEFT_LEG_4_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(2, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(LEFT_LEG_4_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(LEFT_LEG_4_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}

				glPopMatrix();

				// right legs
				glPushMatrix();
				glTranslated(0, 0, -0.3);

				if (DETAIL >= 4) {
					// right 1
					glPushMatrix();
					glRotated(VAL(RIGHT_LEG_1_1_ROTATE_Y), 0, 1, 0); // -60
					glRotated(VAL(RIGHT_LEG_1_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(2, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(RIGHT_LEG_1_2_ROTATE_Y), 0, 1, 0); // -40
						glRotated(VAL(RIGHT_LEG_1_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(2, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(RIGHT_LEG_1_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(RIGHT_LEG_1_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();

					// right 2
					glPushMatrix();
					glRotated(VAL(RIGHT_LEG_2_1_ROTATE_Y), 0, 1, 0); // -30
					glRotated(VAL(RIGHT_LEG_2_1_ROTATE_X), 1, 0, 0); // -25
					drawCylinder(1.5, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(RIGHT_LEG_2_2_ROTATE_Y), 0, 1, 0); // -30
						glRotated(VAL(RIGHT_LEG_2_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(1.5, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(RIGHT_LEG_2_3_ROTATE_Y), 0, 1, 0); // -20
							glRotated(VAL(RIGHT_LEG_2_3_ROTATE_X), 1, 0, 0); // 30
							drawCylinder(1.5, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();

					// right 3
					glPushMatrix();
					glRotated(VAL(RIGHT_LEG_3_1_ROTATE_Y), 0, 1, 0); // 20
					glRotated(VAL(RIGHT_LEG_3_1_ROTATE_X), 1, 0, 0); // -30
					drawCylinder(1.5, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 1.5);
						glRotated(VAL(RIGHT_LEG_3_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(RIGHT_LEG_3_2_ROTATE_X), 1, 0, 0); // 50
						drawCylinder(1.5, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 1.5);
							glRotated(VAL(RIGHT_LEG_3_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(RIGHT_LEG_3_3_ROTATE_X), 1, 0, 0); // 40
							drawCylinder(1.5, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();

					// right 4
					glPushMatrix();
					glRotated(VAL(RIGHT_LEG_4_1_ROTATE_Y), 0, 1, 0); // 60
					glRotated(VAL(RIGHT_LEG_4_1_ROTATE_X), 1, 0, 0); // -20
					drawCylinder(2, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 2);
						glRotated(VAL(RIGHT_LEG_4_2_ROTATE_Y), 0, 1, 0); // 20
						glRotated(VAL(RIGHT_LEG_4_2_ROTATE_X), 1, 0, 0); // 40
						drawCylinder(2, 0.1, 0.1);

						if (DETAIL >= 6) {
							glPushMatrix();
							glTranslated(0, 0, 2);
							glRotated(VAL(RIGHT_LEG_4_3_ROTATE_Y), 0, 1, 0); // 20
							glRotated(VAL(RIGHT_LEG_4_3_ROTATE_X), 1, 0, 0); // 20
							drawCylinder(2, 0.1, 0);
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}

				glPopMatrix();
			}

			if (DETAIL >= 3) {
				// head
				glPushMatrix();
				glTranslated(-0.6, 0, 0);
				drawSphere(0.5);
				if (DETAIL >= 4) {
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

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 1);
						glRotated(VAL(LEFT_ANTENNA_UPPER_ROTATE_Y), 0, 1, 0); // -30
						glRotated(VAL(LEFT_ANTENNA_UPPER_ROTATE_X), 1, 0, 0); // 45
						drawCylinder(0.7, 0.1, 0);
						glPopMatrix();
					}
					glPopMatrix();

					// right antenna
					glPushMatrix();
					glTranslated(-0.3, 0, -0.4);
					glRotated(VAL(RIGHT_ANTENNA_ROTATE_Y), 0, 1, 0);
					glRotated(VAL(RIGHT_ANTENNA_ROTATE_X), 1, 0, 0);
					drawCylinder(1, 0.1, 0.1);

					if (DETAIL >= 5) {
						glPushMatrix();
						glTranslated(0, 0, 1);
						glRotated(VAL(RIGHT_ANTENNA_UPPER_ROTATE_Y), 0, 1, 0);
						glRotated(VAL(RIGHT_ANTENNA_UPPER_ROTATE_X), 1, 0, 0);
						drawCylinder(0.7, 0.1, 0);
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
	}

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
	controls[LEVEL_OF_DETAIL] = ModelerControl("Level of Detail", 1, 6, 1, 6);
	controls[MOOD] = ModelerControl("Mood", 0, 3, 1, 0);
	controls[ANIMATE] = ModelerControl("Animate", 0, 1, 1, 0);
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);

	controls[SPIDER_ROTATE_Z] = ModelerControl("Spider Rotate Z", -180, 180, 1, 0);
	controls[BODY_ROTATE_Z] = ModelerControl("Body Rotate Z", 30, -60, 1, 0);

    controls[LEFT_TOOTH_ROTATE_Y] = ModelerControl("Left Tooth Rotate Y", -60, -120, 1, -90);
    controls[RIGHT_TOOTH_ROTATE_Y] = ModelerControl("Right Tooth Rotate Y", -60, -120, 1, -90);

    controls[LEFT_ANTENNA_ROTATE_Y] = ModelerControl("Left Antenna Rotate Y", -60, -90, 1, -75);
    controls[LEFT_ANTENNA_ROTATE_X] = ModelerControl("Left Antenna Rotate X", -0, -60, 1, -30);
    controls[LEFT_ANTENNA_UPPER_ROTATE_Y] = ModelerControl("Left Antenna Upper Rotate Y", -0, -60, 1, -30);
    controls[LEFT_ANTENNA_UPPER_ROTATE_X] = ModelerControl("Left Antenna Upper Rotate X", 30, 60, 1, 45);

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

    controls[RIGHT_LEG_3_1_ROTATE_Y] = ModelerControl("Right Leg 3 First Part Rotate Y", 130, 190, 1, 160);
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
