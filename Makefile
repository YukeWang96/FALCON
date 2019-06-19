cknn: main.cpp citationKNN.cpp ori_citationKNN.cpp
	g++ -std=c++11 main.cpp citationKNN.cpp ori_citationKNN.cpp -o cknn

test:
	./cknn

clean:
	rm -rf cknn