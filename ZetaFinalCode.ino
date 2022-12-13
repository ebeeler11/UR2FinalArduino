
#include <LiquidCrystal.h>
#include <VarSpeedServo.h>

VarSpeedServo base_servo;
VarSpeedServo arm_servo;
VarSpeedServo end_servo;
const int ledPin = 13; // the pin that the LED is attached to
const byte buffSize = 40;
unsigned int inputBuffer[buffSize];
const char startMarker = '<';
const char endMarker = '>';
byte bytesRecvd = 0;
boolean readInProgress = false;
boolean newDataFromPC = false;
byte coordinates[2];
int X = 0;
int Y = 0;


void setup() {
// put your setup code here, to run once:
Serial.begin(9600);

pinMode(ledPin, OUTPUT);
//magnet setup
pinMode(2, OUTPUT); 
    //servo setup position
    base_servo.write(150);
    arm_servo.write(55);
    end_servo.write(90);
//servo attach
base_servo.attach(3);
arm_servo.attach(10);
end_servo.attach(11);


void loop() {
getDataFromPC();
if(newDataFromPC){
sendSuspendCmd();
digitalWrite(ledPin, HIGH);
delay(5000);
digitalWrite(ledPin, LOW);
sendEnableCmd();
sendCoordinatesToPC();
newDataFromPC = false;
ArmMove();
/*if(shapeTypeFromPC == "Triangle"){
  sortTri();
  }//triangle            code for shape type is inopperable*/
  sortRectangle();

}
}

 void ArmMove(){
  digitalWrite(2,HIGH);
  if(49<X<75){
    if(20<Y<47){
    base_servo.write(178, 6);
    end_servo.write(53, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(77, 6);
         arm_servo.wait();
      delay(2000);
      }
      else if(48<Y<76){
      base_servo.write(175, 6);
      end_servo.write(70, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(81, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(77<Y<107){
      base_servo.write(173, 6);
      end_servo.write(76, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(86, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(108<Y<132){
      base_servo.write(170, 6);
      end_servo.write(81, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(89, 6);
         arm_servo.wait();
      delay(2000);
        }
     
    }
  else if(76<X<100){
    if(20<Y<47){
      base_servo.write(162, 6);
      end_servo.write(53, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(77, 6);
         arm_servo.wait();
      delay(2000);
      }
      else if(48<Y<76){
      base_servo.write(160, 6);
      end_servo.write(70, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(81, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(77<Y<107){
      base_servo.write(158, 6);
      end_servo.write(76, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(86, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(108<Y<132){
      base_servo.write(158, 6);
      end_servo.write(81, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(89, 6);
         arm_servo.wait();
      delay(2000);
        }
     
    }
    else if(101<X<137){
      if(20<Y<47){
      base_servo.write(152, 6);
      end_servo.write(53, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(77, 6);
         arm_servo.wait();
      delay(2000);
      }
      else if(48<Y<76){
      base_servo.write(151, 6);
      end_servo.write(70, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(81, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(77<Y<107){
      base_servo.write(150, 6);
      end_servo.write(76, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(86, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(108<Y<132){
      base_servo.write(149, 6);
      end_servo.write(81, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(89, 6);
         arm_servo.wait();
      delay(2000);
        }
     
    }
    else if(138<X<171){
      if(20<Y<47){
      base_servo.write(136, 6);
      end_servo.write(53, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(77, 6);
         arm_servo.wait();
      delay(2000);
      }
      else if(48<Y<76){
      base_servo.write(138, 6);
      end_servo.write(70, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(81, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(77<Y<107){
      base_servo.write(139, 6);
      end_servo.write(76, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(86, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(108<Y<132){
      base_servo.write(140, 6);
      end_servo.write(81, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(89, 6);
         arm_servo.wait();
      delay(2000);
        }
     
    }
    else if(172<X<200){
      if(20<Y<47){
      base_servo.write(126, 6);
      end_servo.write(53, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(77, 6);
         arm_servo.wait();
      delay(2000);
      }
      else if(48<Y<76){
      base_servo.write(128, 6);
      end_servo.write(70, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(81, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(77<Y<107){
      base_servo.write(129, 6);
      end_servo.write(76, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(86, 6);
         arm_servo.wait();
      delay(2000);
        }
        else if(108<Y<132){
      base_servo.write(130, 6);
      end_servo.write(81, 6);
         base_servo.wait();
         end_servo.wait();
      delay(1000);
    arm_servo.write(89, 6);
         arm_servo.wait();
      delay(2000);
        }
     
    }

    
}
 /*void SortTri() {
  // move base and turn off electromagnet
  //left of robot
  arm_servo.write(50, 6);
    delay(500);
    end_servo.write(72, 6);
  delay(1000);
  base_servo.write(220, 6);//rotate to right
  base_servo.wait();
    end_servo.wait();
    arm_servo.wait();
  delay(4000); //delay so shape isn't thrown
   digitalWrite(2, LOW);//turn off magnet
   delay(4400); 
 }*/

 void SortRectangle() {
  //right of robot
    arm_servo.write(50, 6);
    delay(500);
    end_servo.write(72, 6);
  delay(1000);
  base_servo.write(21, 6);//rotate to right
  base_servo.wait();
    end_servo.wait();
    arm_servo.wait();
  delay(44000); //delay so shape isn't thrown
   digitalWrite(2, LOW);//turn off magnet
   delay(5000); 
 }

 void sendSuspendCmd(){
// send the suspend-true command
Serial.println("<S1>");
}
void sendEnableCmd(){
// send the suspend-false command
Serial.println("<S0>");
}
void sendCoordinatesToPC(){
// send the point data to the PC
Serial.print("<P");
Serial.print(coordinates[0]);
Serial.print(",");
Serial.print(coordinates[1]);
Serial.println(">");
}
// alternative to the readBytes function:
void getDataFromPC() {
// receive data from PC and save it into inputBuffer
if(Serial.available() > 0) {
char x = Serial.read();
// the order of these IF clauses is significant
if (x == endMarker) {
readInProgress = false;
newDataFromPC = true;
inputBuffer[bytesRecvd] = 0;
coordinates[0] = inputBuffer[0];
coordinates[1] = inputBuffer[1];

X = coordinates[0];
Y = coordinates[1];
}
if(readInProgress) {
inputBuffer[bytesRecvd] = x;
bytesRecvd ++;
if (bytesRecvd == buffSize) {
bytesRecvd = buffSize - 1;
}
}
if (x == startMarker) {
bytesRecvd = 0;
readInProgress = true;
}
}
}
