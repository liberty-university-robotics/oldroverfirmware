byte incomingByte = 0;	// for incoming serial data

DualVNH5019MotorShield md;


#ifndef FORWARD
#define FORWARD true
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
	Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps
}

bool name = FORWARD;


void loop() {
	/*if (Serial.available()) {
		incomingByte = Serial.read();
         	if(incomingByte == 'w'){
			setSpeeds(200,200);
         	}else if(incomingByte == 'a'){
			setSpeeds(0,200);
		}else if(incomingByte == 'd'){
			setSpeeds(200,0);
		}else if(incomingByte == 's'){
			setSpeeds(-200,-200);
		}else if(incomingByte == 'b'){
			setBrakes(400,400);
		}else if(incomingByte == 'c'){
			setBrakes(0,0);
		}
	}*/
	if (Serial.available()) {
                incomingByte = Serial.read();
                if(incomingByte == 'w'){
                        setSpeeds(200,200);
                }else if(incomingByte == 's'){
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

}
