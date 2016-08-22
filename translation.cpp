#include <bits/stdc++.h>
using namespace std;
#include "header.h"
void traslate_all_point(struct pdb pdbfile1[],int filelength,struct point cor)
{
	for(int i=0;i<filelength;i++)
	{
		pdbfile1[i].x2-=cor.x;
		pdbfile1[i].y2-=cor.y;
		pdbfile1[i].z2-=cor.z;
	}
}
struct point translate(struct point p,struct vectr r,float dist)
{
                                        // x is the cordinated to be translated
                                        // r is the direction vector
	                                    // dist distance by which point x is translated
	r=unitVector(r);
	r=multiplication(r,dist);//scaling unit vector
    p.x+=r.x;
    p.y+=r.y;
    p.z+=r.z;
    return p;
}
