#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, 
	YPOS, 
	ZPOS, 
	LEFT_TOOTH_ROTATE_Y,
	RIGHT_TOOTH_ROTATE_Y,
	LEFT_ANTENNA_ROTATE_Y,
	LEFT_ANTENNA_ROTATE_X,
	LEFT_ANTENNA_UPPER_ROTATE_Y,
	LEFT_ANTENNA_UPPER_ROTATE_X,
	RIGHT_ANTENNA_ROTATE_Y,
	RIGHT_ANTENNA_ROTATE_X,
	RIGHT_ANTENNA_UPPER_ROTATE_Y,
	RIGHT_ANTENNA_UPPER_ROTATE_X,
	LEFT_LEG_1_1_ROTATE_Y,
	LEFT_LEG_1_1_ROTATE_X,
	LEFT_LEG_1_2_ROTATE_Y,
	LEFT_LEG_1_2_ROTATE_X,
	LEFT_LEG_1_3_ROTATE_Y,
	LEFT_LEG_1_3_ROTATE_X,
	LEFT_LEG_2_1_ROTATE_Y,
	LEFT_LEG_2_1_ROTATE_X,
	LEFT_LEG_2_2_ROTATE_Y,
	LEFT_LEG_2_2_ROTATE_X,
	LEFT_LEG_2_3_ROTATE_Y,
	LEFT_LEG_2_3_ROTATE_X,
	LEFT_LEG_3_1_ROTATE_Y,
	LEFT_LEG_3_1_ROTATE_X,
	LEFT_LEG_3_2_ROTATE_Y,
	LEFT_LEG_3_2_ROTATE_X,
	LEFT_LEG_3_3_ROTATE_Y,
	LEFT_LEG_3_3_ROTATE_X,
	LEFT_LEG_4_1_ROTATE_Y,
	LEFT_LEG_4_1_ROTATE_X,
	LEFT_LEG_4_2_ROTATE_Y,
	LEFT_LEG_4_2_ROTATE_X,
	LEFT_LEG_4_3_ROTATE_Y,
	LEFT_LEG_4_3_ROTATE_X,
	RIGHT_LEG_1_1_ROTATE_Y,
	RIGHT_LEG_1_1_ROTATE_X,
	RIGHT_LEG_1_2_ROTATE_Y,
	RIGHT_LEG_1_2_ROTATE_X,
	RIGHT_LEG_1_3_ROTATE_Y,
	RIGHT_LEG_1_3_ROTATE_X,
	RIGHT_LEG_2_1_ROTATE_Y,
	RIGHT_LEG_2_1_ROTATE_X,
	RIGHT_LEG_2_2_ROTATE_Y,
	RIGHT_LEG_2_2_ROTATE_X,
	RIGHT_LEG_2_3_ROTATE_Y,
	RIGHT_LEG_2_3_ROTATE_X,
	RIGHT_LEG_3_1_ROTATE_Y,
	RIGHT_LEG_3_1_ROTATE_X,
	RIGHT_LEG_3_2_ROTATE_Y,
	RIGHT_LEG_3_2_ROTATE_X,
	RIGHT_LEG_3_3_ROTATE_Y,
	RIGHT_LEG_3_3_ROTATE_X,
	RIGHT_LEG_4_1_ROTATE_Y,
	RIGHT_LEG_4_1_ROTATE_X,
	RIGHT_LEG_4_2_ROTATE_Y,
	RIGHT_LEG_4_2_ROTATE_X,
	RIGHT_LEG_4_3_ROTATE_Y,
	RIGHT_LEG_4_3_ROTATE_X,
	SPINNERET_ROTATE_Y,
	SPINNERET_ROTATE_X,
	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif