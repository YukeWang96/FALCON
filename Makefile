cknn: main.cpp citationKNN.cpp ori_citationKNN.cpp
	g++ -std=c++11 main.cpp citationKNN.cpp ori_citationKNN.cpp -o cknn

test:
	./cknn ./cknn-dataset/01_elephant.csv
	./cknn ./cknn-dataset/02_fox.csv
	./cknn ./cknn-dataset/03_tiger.csv
	./cknn ./cknn-dataset/04_musk1.csv
	./cknn ./cknn-dataset/05_musk2.csv
	./cknn ./cknn-dataset/06_Mutagenesis_atoms.csv
	./cknn ./cknn-dataset/07_Mutagensis_bounds.csv
	./cknn ./cknn-dataset/08_Mutagenesis_chains.csv

clean:
	rm -rf cknn


