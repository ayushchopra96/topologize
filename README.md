# Protein Structural Topology Comparison.

Runs independently of the protein primary sequence.
Subsecond result produced.
Takes as input PDB files for the 2 proteins.

Result Analysis:-
	1. output result > 0.72 :- High level of structural similarity
	2. output result < 0.45 :- No structural similarity
	3. 0.72 > output > 0.45 :- Partial Structural Similarity

Tech Pre-Requirements:-
1. Dynamic Programming
2. Computer Graphics.

Executing the program
1. git clone https://github.com/ayushchopra96/topologize.git
2. cd topologize
3. g++ *.cpp 
4. ./a.out <path-to-pdb1> <path-to-pdb2>