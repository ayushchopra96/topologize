#include <bits/stdc++.h>
using namespace std;
#include "header.h"
void read_rr(int argc,char *argv[],int n,struct pdb pdbfile[],int &file_length)
{
	                //n= read nth pdb
	file_length=0;
	fstream fp;
	fp.open(argv[n],ios::in);
	if(fp==NULL)
	{
		printf("file %s did not open\n",argv[n]);
	}
	else
	{
	   printf("file %s open\n",argv[n]);
	}
	int i=0;
	while(fp)
	{
        //|| strcmp(f.atom2,"HETATM")=0->add to line 33...
		char buffer[1000];
		string line;
		getline(fp,line);
		if(fp==NULL)
			break;
		strcpy(buffer,line.c_str());
		struct pdb f;
		sscanf(buffer,"%s%d%s%s%s%d%f%f%f%f%f%f\n",f.atom2,&f.atomno2,f.t2,f.d2,f.chainid,&f.r2,&f.x2,&f.y2,&f.z2,&f.h2,&f.e2,&f.ep2);
        if(strcmp(f.atom2,"ATOM")==0)
        {
        	if(strcmp(f.t2,"CA")==0)
        	{
        	  pdbfile[i]=f;
              i++;
            }
        }
	}
	file_length=i;
	fp.close();
}
