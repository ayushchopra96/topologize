## Sequence Independent Protein Structural Topology Comparison.

# Distinguishing Characteristic
Runs independently of the protein primary sequence.<br>
Subsecond performance

# Input Format
Takes as input PDB files for the 2 proteins.<br>
Store pdb data files in <b>./files</b><br>


# Setup and Execution Instructions
1. git clone https://github.com/ayushchopra96/topologize.git <br>
2. cd topologize <br>
3. sh generate_executable.sh <br>
4. ./a.out ./path/to/pdb1 ./path/to/pdb2 <br>

<br>
Outputs scaled metric value for the structural topology similarity.
<br>

# Metric Inference
Result Analysis:-<br>
	1. output result > 0.72 :- High level of structural similarity<br>
	2. output result < 0.45 :- No structural similarity<br>
	3. 0.72 > output > 0.45 :- Partial Structural Similarity<br>
