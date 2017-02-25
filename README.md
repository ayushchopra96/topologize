# Protein Structural Topology Comparison.

Runs independently of the protein primary sequence.<br>
Subsecond result produced.<br>
Takes as input PDB files for the 2 proteins.<br>
Test pdb files have been stored in the files folder<br>

Tech Pre-Requirements:-
1. Dynamic Programming<br>
2. Computer Graphics.

<br>

Executing the program <br>
1. git clone https://github.com/ayushchopra96/topologize.git <br>
2. cd topologize <br>
3. sh generate_executable.sh <br>
4. ./a.out ./path/to/pdb1 ./path/to/pdb2 <br>
<br>
Output is the metric value for the protein structural topology similarity.
<br>
Result Analysis:-<br>
	1. output result > 0.72 :- High level of structural similarity<br>
	2. output result < 0.45 :- No structural similarity<br>
	3. 0.72 > output > 0.45 :- Partial Structural Similarity<br>