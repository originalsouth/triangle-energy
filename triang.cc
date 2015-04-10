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

int main(int argc,char *argv[])
{
    double ans;
    if(argc==4)
    {
        ans=V3(atof(argv[1]),atof(argv[2]),atof(argv[3]));
        printf("%F\n",ans);
    }
    else if(argc==6)
    {
        del=atof(argv[4]);
        a=atof(argv[5]);
        ans=V3(atof(argv[1]),atof(argv[2]),atof(argv[3]));
        printf("%F\n",ans);
    }
    else if(argc==8)
    {
        del=atof(argv[4]);
        a=atof(argv[5]);
        b=atof(argv[6]);
        k=atof(argv[7]);
        ans=V3(atof(argv[1]),atof(argv[2]),atof(argv[3]));
        printf("%F\n",ans);
    }
    else
    {
        ans=0.0;
        printf("%F\n",ans);
    }
    return EXIT_SUCCESS;
}
