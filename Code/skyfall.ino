/*
  Skyfall SRP Arduino Program
  Version 0.1

  This program does two things:

  - Send data via serial to the Pi and the antenna at set interrupt times
  - Detect different stages of the launch to initiate parachute deployment
  
  TODO:
  - fix up all the missing functions and initializations
  - add timed interrupt to send data and do some anomaly detection
*/

enum States {unready, readyForLaunch, toApogee, apogee, travelDown, deployChute, travelChute, touchDown, anomaly};
enum States state;

boolean anomalyDetect = 0;

void setup() {
  state = unready;
  // initialize all sensors
  // what testing goes here and what in the unready state loop???
  // test communication with SRP board
  // send test signal via serial
}

void loop() {
  // based on continuous launch pulse from SRP board

  while (state == unready) {
    // do unready stuff
    // check if everything is ready -> set check to 1
    boolean check = 1;
    if (launch) {
      state = anomaly;
    } else if (check) {
      state = readyForLaunch;
    } else {
      // check failed
    }
  }
  
  while (state == readyForLaunch) {
    // do ready stuff
    
    // check bad sensor
    boolean check = 1;
    if (launch) {
      state = toApogee;
    } else if (check) {
      state = unready
    }
  }

  while (state == toApogee){
    // check height and IMU data
    // conclude if at apogee
    // or conclude missed apogee
    boolean checkApogee = 1;
    boolean checkDown = 1;
    if (checkApogee && checkDown){
      state = anomaly;
    } else if (checkApogee){
      state = apogee;
    } else if (checkDown){
      state = travelDown;
    }
  }

  while (state == travelDown){
    // monitor altitude
    // check for corrupted data
    boolean checkAltitude = 1;
    boolean checkCorrupt = 1;
    if (checkCorrupt){
      state = anomaly;
    } else if (checkAltitude){
      state = deployChute;
    }
  }

  while (state == deployChute){
    // send chute deploy signal to SRP

    // check for reduction in speed or massive decelleration
    boolean checkSpeed = 1;

    if (checkSpeed){
      state = travelChute;
    } else {
      // resend deploy signal
      // do something after five times???
    }
  }

  while (state == travelChute){
    // send nice message
    // check for app. no speed at all
    boolean checkSpeed = 1;
    if (checkSpeed){
      state = touchDown;
    }
    // what if it doesn't detect any speed change???
  }

  while (state == touchDown){
    // send another nice message

    // shutdown other computers and camera feed???
  }

  while (state == anomaly){
    //send signal to start timer to SRP board
    //or start itself
    // time every interrupt??
    // SRP board already times system??
    anomalyDetect = 1;
    //no way out out of anomaly??
  }
}

