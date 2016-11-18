#include <TVout.h>
TVout TV;

int Xmin = 10;
int Xmax = 118;
int Ymin = 10;
int Ymax = 86;
int i = 0;

int XscreenPoint[]= {18, 28, 38, 48, 58, 68, 78, 88, 98, 108, 118};
int DataPoints[] = {0,0,0,30,40,50,60,23,64,12,34};
int ScreenPoints[10];
void setup() {
  // put your setup code here, to run once:
  TV.begin(PAL);
}

void loop() {
  // put your main code here, to run repeatedly:
  graphRefresh();
  delay(200);
}


void graphRefresh(){
  TV.clear_screen();
  graphSetup();
  dataPointsToGraphPoints();
  PlotScreenPoints();
  ConnectTheDots();
}

void graphSetup(){
  TV.draw_line(Xmin, Ymax, Xmin, Ymin,1);
  TV.draw_line(Xmin, Ymax, Xmax, Ymax,1);
}

void dataPointsToGraphPoints(){
  i=0;
  for (i = 0; i < 11; i = i + 1){
    int ScreenPoint = map(DataPoints[i], 0, 70, Ymax, Ymin);
    ScreenPoints[i]= ScreenPoint;
  }
}

void PlotScreenPoints(){
  i = 0;
  for (i = 0 ; i < 10 ; i = i+1){
    TV.set_pixel(XscreenPoint[i], ScreenPoints[i],1);
  }
}

void ConnectTheDots(){
  i =0;
  for (i =0; i<10;i=i+1){
    TV.draw_line(XscreenPoint[i], ScreenPoints[i], XscreenPoint[i+1], ScreenPoints[i+1],1);
  }
}


