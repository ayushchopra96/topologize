#include <bits/stdc++.h>
#include "header.h"
using namespace std;
float magnituide(struct vectr v)//magnituide of a vector
{
   float mag = sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
   return mag;
}
struct vectr unitVector(struct vectr v)
{
	struct vectr m;
	float mag=magnituide(v);
    m.x=v.x/mag;
    m.y=v.y/mag;
    m.z=v.z/mag;
	return m;
}
float dotProduct(struct vectr a,struct vectr b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
struct vectr crossProduct(struct vectr a,struct vectr b)
{
    struct  vectr m;
    m.x=a.y*b.z-b.y*a.z;
    m.y=b.x*a.z-a.x*b.z;
    m.z=a.x*b.y-b.x*a.y;
    return m;
}
struct vectr multiplication(struct vectr v,float a)//scalar
{                     //calculates a*v //vector multiplication with scalar quantity;
	struct vectr m;
	m.x=v.x*a;
	m.y=v.y*a;
	m.z=v.z*a;
    return m;
}

struct vectr addition(struct vectr v,struct vectr v1)//scalar
{                     //calculates v+v1
	struct vectr m;
	m.x=v.x+v1.x;
	m.y=v.y+v1.y;
	m.z=v.z+v1.z;
    return m;
}
//editing the defition,errenously same as that for addition:- NOTE POINT..
struct vectr subtraction(struct vectr v,struct vectr v1)//scalar
{                     //calculates v-v1
	struct vectr m;

	//m.x=v.x+v1.x;
	//m.y=v.y+v1.y;
	//m.z=v.z+v1.z;

	m.x=v.x-v1.x;
	m.y=v.y-v1.y;
	m.z=v.z-v1.z;
    return m;
}

struct vectr rotate(struct vectr v,struct vectr r,float theta)
{                   //v vector to be rotated   // vector along it is rotated // angle by which vector v is rotated
   //using this link multiplication is adopted
   //https://math.kennesaw.edu/~plaval/math4490/rotgen.pdf
   const float pie=3.14159;
   float angle=pie*theta/180;//converting into radian
   //float angle=theta;
   r=unitVector(r);
   float temp=(1-cos(angle))*(dotProduct(v,r));
   struct vectr a=multiplication(r,temp);
   struct vectr b=multiplication(v,cos(angle));
   struct vectr c=multiplication(crossProduct(r,v),sin(angle));
   struct vectr d=addition(a,b);
   d=addition(c,d);
   return d;
}
/*void rotate_all_point(struct pdb pdbfile1[],int filelength1,struct vectr r)
{
   r=unitVector(r);
   struct vectr v;
   for(int i=0;i<filelength1;i++)
    {
      v.x=pdbfile1[i].x2;
      v.y=pdbfile1[i].y2;
      v.z=pdbfile1[i].z2;
      float angle=acos(dotProduct(v,r)/magnituide(v))*180/3.14159;

      v=rotate(v,crossProduct(v,r),angle);
      pdbfile1[i].x2=v.x;
      pdbfile1[i].y2=v.y;
      pdbfile1[i].z2=v.z;
   }
}*/
void rotate_all_point(struct pdb pdbfile1[],int filelength1,struct vectr r)
{
    struct vectr m;
    struct vectr v;
    for(int i=0;i<filelength1;i++)
    {
        m.x=pdbfile1[i].x2-r.x;
        m.y=pdbfile1[i].y2-r.y;
        m.z=pdbfile1[i].z2-r.z;

        v.x=pdbfile1[i].x2;
        v.y=pdbfile1[i].y2;
        v.z=pdbfile1[i].z2;

        m=unitVector(m);
        float angle=acos(dotProduct(v,m)/magnituide(v))*180.0/3.14159;
        v=rotate(v,crossProduct(v,m),angle);
        pdbfile1[i].x2=v.x;
        pdbfile1[i].y2=v.y;
        pdbfile1[i].z2=v.z;
    }
}
/*int main()
{
  struct vectr v;v.x=1,v.y=0,v.z=0;
  struct vectr r;r.x=0,r.y=1,r.z=0;
  struct ans=rotate(v,r,90);
  printf(" %f %f %f\n",ans.x,ans.y,ans.z);
}*/
