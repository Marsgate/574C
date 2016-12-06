#include "API.h"
#include "mutual.h"

void nDrive(){
  //driving
  int right = -joystickGetAnalog(1, 2);
  int left = joystickGetAnalog(1, 3);
  //set motors
  motorSet(2, left);
  motorSet(10, left);
  motorSet(3, right);
  motorSet(9, right);
}

//nick's Lift mech
void nLift(){
  //lift
  if(joystickGetDigital(1, 6, JOY_UP)){
    lift(-127);
  }else if(joystickGetDigital(1, 6, JOY_DOWN)){
    lift(127);
  }else{
    lift(0);
  }
}

void nClaw(){
  //claw
  if(joystickGetDigital(1, 5, JOY_UP)) {
    motorSet(8, 127);
  }else if(joystickGetDigital(1, 5, JOY_DOWN)) {
    motorSet(8 ,-127);
  }else{
    motorSet(8, 0);
  }
}