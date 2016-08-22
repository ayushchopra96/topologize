#include <bits/stdc++.h>
using namespace std;
struct pdb
{
   char atom2[100];
   char t2[100],d2[100],chainid[10];
   int r2,atomno2;
   float x2,y2,z2,h2,e2,ep2;
   //sscanf(buffer,"%s%d%s%s%d%f%f%f%f%f%f\n",atom2,&atomno2,t2,d2,&r2,&x2,&y2,&z2,&h2,&e2,&ep2);
};
struct arr
{
	float slope,len;
};
struct point
{
    float x;
    float y;
    float z;
};
struct vectr
{
	float x,y,z;
};
extern void read_rr(int argc,char *argv[],int n,struct pdb pdbfile[],int &file_length);
extern float dp(struct arr *X,int m,struct arr *Y, int n,float t);
extern float magnituide(struct vectr v);
extern struct vectr unitVector(struct vectr v);
extern float dotProduct(struct vectr a,struct vectr b);
extern struct vectr crossProduct(struct vectr a,struct vectr b);
extern struct vectr multiplication(struct vectr v,float a);
extern struct vectr addition(struct vectr v,struct vectr v1);//scalar
extern struct vectr subtraction(struct vectr v,struct vectr v1);//scalar
extern struct vectr rotate(struct vectr v,struct vectr r,float theta);
extern float getslope(point &a,point &b);
extern float getdist(struct point p1,struct point p2);
extern struct cor translate(struct cor p,struct vectr r,float dist);
extern void traslate_all_point(struct pdb pdbfile1[],int filelength,struct point cor);
extern void rotate_all_point(struct pdb pdbfile1[],int filelength1,struct vectr r);
