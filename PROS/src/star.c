#include "sensFunc.h"
#include "main.h"

int toDo;
int loopClock;


void rStar(){

  //claw out
  loopClock = 0; encoderReset(driveEnc);
  while(1){
    toDo = 2;
    toDo -= tipOut(loopClock);
    toDo -= clawForward(cClose, 0);
    if(toDo == 0){break;}delay(10);loopClock += 10;
  }


  //reverse
  loopClock = 0; encoderReset(driveEnc);
  while(1){
    toDo = 1;
    toDo -= tankDriveEnc(60, 10, -100);
    if(toDo == 0){break;}delay(10);loopClock += 10;
  }


  //forward
  loopClock = 0; encoderReset(driveEnc);
  while(1){
    toDo = 1;
    toDo -= tankDriveEnc(115, 127, 1200);
    if(toDo == 0){break;}delay(10);loopClock += 10;
  }

  //grab and reverse
  loopClock = 0; encoderReset(driveEnc);
  while(1){
    toDo = 3;
    if(loopClock > 700){toDo -= tankDriveEnc(127, 60, -1200); toDo -= liftLoop(loopClock, 1200, -127, -35);}
    toDo -= clawForward(cSqz, 40);
    if(toDo == 0){break;}delay(10);loopClock += 10;
  }

  //throw
  loopClock = 0; encoderReset(driveEnc);
  while(1){
    toDo = 2;
    toDo -= liftLoop(loopClock, 1500, -127, 0);
    if(loopClock > 900){toDo -= clawBack(cClose);}
    if(toDo == 0){break;}delay(10);loopClock += 10;
  }

  //reset and correct
  loopClock = 0; encoderReset(driveEnc);
  while(1){
    toDo = 2;
    toDo -= liftLoop(loopClock, 1400, 60, 0);
    if(loopClock > 700){toDo -= tankDriveEnc(127, 95, 700);}
    if(toDo == 0){break;}delay(10);loopClock += 10;
  }
}


void lStar(){

    //claw out
    loopClock = 0; encoderReset(driveEncL);
    while(1){
      toDo = 2;
      toDo -= tipOut(loopClock);
      toDo -= clawForward(cClose, 0);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }


    //reverse
    loopClock = 0; encoderReset(driveEncL);
    while(1){
      toDo = 1;
      toDo -= tankDriveEnc(10, 60, -100);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }


    //forward
    loopClock = 0; encoderReset(driveEncL);
    while(1){
      toDo = 1;
      toDo -= tankDriveEnc(125, 127, 1200);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse
    loopClock = 0; encoderReset(driveEncL);
    while(1){
      toDo = 3;
      if(loopClock > 700){toDo -= tankDriveEnc(68, 127, -1250); toDo -= liftLoop(loopClock, 1200, -127, -35);}
      toDo -= clawForward(cSqz, 40);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    loopClock = 0; encoderReset(driveEncL);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cMid);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

}