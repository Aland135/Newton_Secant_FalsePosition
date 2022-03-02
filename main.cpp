/*
	Alan Garcia
	This code allows you to use the numerical analysis methods: Newton, Secant and False Position.
	It is currently being applied to the formula x*x-2x+1, but the program can be edited to work
	with other equations, just by changing the formula located in the function f and its derivative
	which is located in the function f1.
*/

#include <iostream>
#include <conio.h>
#include <math.h>


using namespace std;

float var, p0, p, err, i, p1, q0, q, q1;


double f(double x)
{
       return pow(x,2)-(2*x)+1;
}
       
double f1(double x1)
{
       return (2*x1)-2;
}

void newton(double p0)
{
               cout<<"#\tp0\tp\tRelErr"<<endl;
               p=p0-(f(p0)/f1(p0));
               err=fabs(p-p0)/fabs(p);
               cout<<i<<"\t"<<p0<<"\t"<<p<<"\t"<<err<<endl;
               i++;
               while(err>=0.001)
               {
                      p=p0-(f(p0)/f1(p0));
                      err=fabs(p-p0)/fabs(p);
                      cout<<i<<"\t"<<p0<<"\t"<<p<<"\t"<<err<<endl;
                      p0=p;
                      i++;
               }
}

void secant(double p, double p0)
{
       cout<<"#\tp(-1)\tp0\tp\tRelErr"<<endl;
               p1=p-((f(p)*(p-p0))/(f(p)-f(p0)));
               err=fabs(p-p0)/fabs(p);
               cout<<i<<"\t"<<p0<<"\t"<<p<<"\t"<<p1<<"\t"<<err<<endl;
               i++;
               while(err>=0.001)
               {
                      p1=p-((f(p)*(p-p0))/(f(p)-f(p0)));
                      err=fabs(p1-p)/fabs(p1);
                      cout<<i<<"\t"<<p0<<"\t"<<p<<"\t"<<p1<<"\t"<<err<<endl;
                      p0=p;
                      p=p1;
                      i++;
               }
}

void falseposition(double p, double p0)
{
        cout<<"#\tp(-1)\tp0\tp\tRelErr"<<endl;
               q0=f(p0);
               q=f(p);
               p1=p-((f(p)*(p-p0))/(f(p)-f(p0)));
               q1=f(p1);
               err=fabs(p-p0)/fabs(p);
               cout<<i<<"\t"<<p0<<"\t"<<p<<"\t"<<p1<<"\t"<<err<<endl;
               i++;
               if(q1*q<0)
               {
                      p0=p;
                      q=q1;          
               }
               p=p1;
               q=q1;
               while(err>0.001)
               {
                     q0=f(p0);
               q=f(p);
               p1=p-((f(p)*(p-p0))/(f(p)-f(p0)));
               q1=f(p1);
               err=fabs(p1-p)/fabs(p1);
               cout<<i<<"\t"<<p0<<"\t"<<p<<"\t"<<p1<<"\t"<<err<<endl;
               i++;
               if(q1*q<0)
               {
                      p0=p;
                      q=q1;          
               }
               p=p1;
               q=q1;
               }
}


int main()
{
    cout<<"Choose the method you wish to apply to your formula"<<endl;
    cout<<"1)Newton\n2)Secant\n3)False position"<<endl;
    cin>>var;
    if (var>3)
    {
                       cout<<"Your option is not valid, please try again"<<endl;
                       return 1;
    }
    
    if (var==1)
    {
               cout<<"Please enter a value to get started"<<endl;
               cin>>p0;
              newton(p0);
               
    }
    
    if (var==2)
    {
              cout<<"Please enter two different values to get started"<<endl;
               cin>>p>>p0;
               secant(p,p0);
    }
                 
     if (var==3)
    {
              cout<<"Please enter two different values to get started"<<endl;
               cin>>p>>p0;
              falseposition(p,p0);
    }
                 
    getch();
    return 0;
    
}

