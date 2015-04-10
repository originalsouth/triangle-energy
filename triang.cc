#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double del=0.0725;
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
    const double x[6]={-del*cos(th0),del*cos(th0),a-del*cos(th1),a+del*cos(th1),a/2.0-del*cos(th2),a/2.0+del*cos(th2)};
    const double y[6]={-del*sin(th0),del*sin(th0),-del*sin(th1),del*sin(th1),sqrt(3.0)*a/2.0-del*sin(th2),sqrt(3.0)*a/2.0+del*sin(th2)};
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

int main()
{
    const double h=1e3;
    const double pi=2.0*asin(1.0);
    double eth0=0.0,eth1=0.0,eth2=0.0,V,Vmin=1e99;
    for(double th0=0.0;th0<=pi;th0+=pi/h) for(double th1=0.0;th1<=pi;th1+=pi/h) for(double th2=0.0;th2<=pi;th2+=pi/h)
    {
        V=V3(th0,th1,th2);
        if(V<Vmin) Vmin=V,eth0=th0,eth1=th1,eth2=th2;
    }
    printf("(%F,%F,%F) --> %F\n",eth0,eth1,eth2,V);
    return EXIT_SUCCESS;
}
