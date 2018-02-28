#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

byte incomingByte = 0;	// for incoming serial data



#ifndef FORWARD
#define FORWARD true
#endif

//If motor side is true then it is the right side, false is left
#ifndef MOTOR_SIDE
#define MOTOR_SIDE false
#endif

 

#ifndef BACKWARD
#define BACKWARD false
#endif

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
}

void setup() {
	md.init();
	Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps
}

bool name = FORWARD;

void loop() {
	if(MOTOR_SIDE){
		while(1){
			if (Serial.available()) {
				incomingByte = Serial.read();
                		if(incomingByte == 'w'){
                        		name = FORWARD;
                	        	md.setSpeeds(200,200);
                		}else if(incomingByte == 's'){
                        		name = BACKWARD;
                        		md.setSpeeds(-200,-200);
                		}else if(incomingByte == 'b'){
                        		md.setBrakes(400,400);
                		}else if(incomingByte == 'c'){
                        		md.setBrakes(0,0);
                		}   
                		if(name == FORWARD){
                 		       if(incomingByte == 'a'){
                                		md.setSpeeds(200,200);
                        		}else if(incomingByte == 'd'){
                                		md.setSpeeds(0,0);
                        		}
				}else{
					if(incomingByte == 'a'){
                       			         md.setSpeeds(-200,-200);
                        		}else if(incomingByte == 'd'){
                                		md.setSpeeds(0,0);
                        		}
				}  
                        		
			}

		}
	}else{
		while(1){
                        if (Serial.available()) {
                                incomingByte = Serial.read();
                                if(incomingByte == 'w'){
                        		name = FORWARD;
                                        md.setSpeeds(200,200);
                                }else if(incomingByte == 's'){
                                        name = BACKWARD;
                                        md.setSpeeds(-200,-200);
                                }else if(incomingByte == 'b'){
                                        md.setBrakes(400,400);
                                }else if(incomingByte == 'c'){
                                        md.setBrakes(0,0);
                                }
                                if(name == FORWARD){
                                       if(incomingByte == 'a'){
                                                md.setSpeeds(0,0);
                                        }else if(incomingByte == 'd'){
                                                md.setSpeeds(200,200);
                                        }
                                }else{  
                                        if(incomingByte == 'a'){
                                                 md.setSpeeds(0,0);
                                        }else if(incomingByte == 'd'){
                                                md.setSpeeds(-200,-200);
                                        }
                                }       
                                        
                        }

                }
	}
}/*
	if (Serial.available()) {
                incomingByte = Serial.read();
                if(incomingByte == 'w'){
                        setSpeeds(200,200);
                }else if(incomingByte == 's'){
                        name = BACKWORD;
                        setSpeeds(-200,-200);
                }else if(incomingByte == 'b'){
                        setBrakes(400,400);
                }else if(incomingByte == 'c'){
                        setBrakes(0,0);
                }
                if(name == FORWARD){
                        if(incomingByte == 'a'){
                                setSpeeds(0,200);
                        }else if(incomingByte == 'd'){
                                setSpeeds(200,0);
                        }   
                }else{
                        if(incomingByte == 'a'){
                                setSpeeds(0,-200);
                        }else if(incomingByte == 'd'){
                                setSpeeds(-200,0);
                        }
                }
        }
	/*if (Serial.available()) {
                incomingByte = Serial.read();
                if(incomingByte == 'w'){
                        setSpeeds(200,200);
                }else if(incomingByte == 's'){
			name = BACKWORD;
                        setSpeeds(-200,-200);
                }else if(incomingByte == 'b'){
                        setBrakes(400,400);
                }else if(incomingByte == 'c'){
                        setBrakes(0,0);
                }
		if(name == FORWARD){
                        if(incomingByte == 'a'){
                                setSpeeds(0,200);
                        }else if(incomingByte == 'd'){
                                setSpeeds(200,0);
                        }   
                }else{
                        if(incomingByte == 'a'){
                                setSpeeds(0,-200);
                        }else if(incomingByte == 'd'){
                                setSpeeds(-200,0);
                        }
                }
        }*/


