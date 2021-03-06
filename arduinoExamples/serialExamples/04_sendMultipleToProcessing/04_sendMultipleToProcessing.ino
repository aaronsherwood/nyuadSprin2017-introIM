void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("0,0");
}

void loop() {
  if(Serial.available()>0){
    char inByte=Serial.read();
    int sensor = analogRead(A0);
    delay(1);
    int sensor2 = analogRead(A1);
    delay(1);
    Serial.print(sensor);
    Serial.print(',');
    Serial.println(sensor2);
  }
}

/* Processing Code

import processing.serial.*;
Serial myPort;
int xPos=0;
int yPos=0;

void setup(){
  size(960,720);
  printArray(Serial.list());
  String portname=Serial.list()[1];
  println(portname);
  myPort = new Serial(this,portname,9600);
  myPort.clear();
  myPort.bufferUntil('\n');
}

void draw(){
  background(255);
  ellipse(xPos,yPos,30,30);
}

void serialEvent(Serial myPort){
  String s=myPort.readStringUntil('\n');
  s=trim(s);
  if (s!=null){
    int values[]=int(split(s,','));
    if (values.length==2){
      xPos=(int)map(values[0],0,1023,0, width);
      yPos=(int)map(values[1],0,1023,0, height);
    }
  }
  println(xPos);
  myPort.write('0');
}

 */
