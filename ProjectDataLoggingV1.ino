#include <TVout.h>
TVout TV;

int ScalePin = 0;
int Xmin = 18;
int Xmax = 120;
int Ymin = 10;
int Ymax = 80;
int i = 0;

int DataPoints[] = {20,23,54,54,12,65,12,2,12,54,65,21,43,12,54,12,12,32,43,25};
int ScreenPoints[100];
int ValMin = 0;
int ValMax = 70;
int XscreenArrayLength = 8;
int XscreenPoints[15];

void setup() {

  // put your setup code here, to run once:
  TV.begin(PAL);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  graphRefresh();
  TV.delay(1000);
}


void graphRefresh(){
  TV.clear_screen();
  //Serial.println("screen Cleared");
  calculateXscreenPoints();
  //Serial.println("points Calculated");
  graphSetup();
  //Serial.println("GraphSetup");
  drawGraph();
  //Serial.println("Graph Drawn");
}

void drawGraph(){
  //Serial.println("enteredfunction");
  dataPointsToGraphPoints();
  //Serial.println("Data Point Converted");
  connectTheDots();
  //Serial.println("DrawnLines");
  plotScreenPoints();
  //Serial.println("points Drawn");
}

void graphSetup(){
  TV.draw_line(Xmin, Ymax, Xmin, Ymin,1);
  TV.draw_line(Xmin, Ymax, Xmax, Ymax,1);
}

void dataPointsToGraphPoints(){
  int i=0;
  for (i = 0 ; i < XscreenArrayLength ;i=i + 1){
    int ScreenPoint = map(DataPoints[i], ValMin, ValMax, Ymax, Ymin);
    ScreenPoints[i]= ScreenPoint;
    //Serial.println( ScreenPoint);
  }
}

void plotScreenPoints(){
  i = 0;
  for (i = 0 ; i <XscreenArrayLength ; i = i+1){
    TV.draw_circle(XscreenPoints[i], ScreenPoints[i],2, 1,0);
  }
}

void connectTheDots(){
  i =0;
  for (i =0; i<XscreenArrayLength-1;i=i+1){
    TV.draw_line(XscreenPoints[i], ScreenPoints[i], XscreenPoints[i+1], ScreenPoints[i+1],1);
  }
}

void calculateXscreenPoints(){
  XscreenArrayLength =  (map(analogRead(ScalePin),0,1023,5,15));
  int XscreenDistance = (Xmax-Xmin)/XscreenArrayLength+1;
  for (i = 0; i < XscreenArrayLength; i=i+1){
    XscreenPoints[i] = Xmin + XscreenDistance * i;
   //Serial.println(i);
   //Serial.println(XscreenDistance*i);
   //Serial.println(Xmin + XscreenDistance*i);

}
}
