#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <FL/Fl.H>

#include "modelerglobals.h"
#include "modelerapp.h"

#define SQUARE(x) ((x) * (x))

inline double calculateTargetDiff(double tarX, double tarY, double tarZ, double x, double y, double z);

void moveLeftLeg1(double tarX, double tarY, double tarZ);
void moveLeftLeg2(double tarX, double tarY, double tarZ);
void moveRightLeg1(double tarX, double tarY, double tarZ);

#endif