/*1
4
3
7 4
2 4 6
8 5 9 3*/

#include <bits/stdc++.h>
#include "header.h"

using namespace std;
//3 single  bond hai to 109.5
//1 double bond 120
// 1 triple bond  180
void read_pdb(char *argv,struct pdb pdbfile[1000],int &file_length)
{
	                //n= read nth pdb
	file_length=0;
	fstream fp;
	fp.open(argv,ios::in);
	if(fp==NULL)
	{
		printf("file %s did not open\n",argv[n]);
	}
	int i=0;
	while(fp)
	{
        // || strcmp(f.atom2,"HETATM")==0
		char buffer[1000];
		string line;
		getline(fp,line);
		if(fp==NULL)
			break;
		strcpy(buffer,line.c_str());
		struct pdb f;
		sscanf(buffer,"%s%d%s%s%d%f%f%f%f%f%f\n",f.atom2,&f.atomno2,f.t2,f.d2,&f.r2,&f.x2,&f.y2,&f.z2,&f.h2,&f.e2,&f.ep2);
        strcpy(f.atomName,f.t2);
        remove_space_num(f.atomName);
        //printf("|%s|\n",f.atom2);
        if(strcmp(f.atom2,"ATOM")==0)
        {
        	pdbfile[i]=f;
            i++;
        }
	}
	file_length=i;
}
