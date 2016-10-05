#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double delta=0.0725;
double a=0.1;
double b=0.01;
double k=10.0;

double d(double x1,double y1,double x2,double y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double VY(double r)
{
    return b/(r*exp(k*r));
}

double V3(double th0,double th1,double th2)
{
    const double x[6]={-delta*cos(th0),delta*cos(th0),a-delta*cos(th1),a+delta*cos(th1),a/2.0-delta*cos(th2),a/2.0+delta*cos(th2)};
    const double y[6]={-delta*sin(th0),delta*sin(th0),-delta*sin(th1),delta*sin(th1),sqrt(3.0)*a/2.0-delta*sin(th2),sqrt(3.0)*a/2.0+delta*sin(th2)};
    double V=0.0;
    V+=VY(d(x[0],y[0],x[2],y[2]));
    V+=VY(d(x[0],y[0],x[3],y[3]));
    V+=VY(d(x[0],y[0],x[4],y[4]));
    V+=VY(d(x[0],y[0],x[5],y[5]));
    V+=VY(d(x[1],y[1],x[2],y[2]));
    V+=VY(d(x[1],y[1],x[3],y[3]));
    V+=VY(d(x[1],y[1],x[4],y[4]));
    V+=VY(d(x[1],y[1],x[5],y[5]));
    V+=VY(d(x[2],y[2],x[4],y[4]));
    V+=VY(d(x[2],y[2],x[5],y[5]));
    V+=VY(d(x[3],y[3],x[4],y[4]));
    V+=VY(d(x[3],y[3],x[5],y[5]));
    return V;
}
