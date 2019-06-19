#include <iostream>
#include <string>
#include <vector>
#include "citationKNN.h"
#include <ctime>
#include <fstream>

using namespace std;

extern long long countDistComp;
extern long long countDistComp2;
extern long long countDistComp3;
extern long long countDistComp4;
extern long long countDistComp5;
extern int hDistType;
extern bool isOriginal;
extern double distSum;
extern int distCount;

int main()
{
	citationKNN CKNN;

	// CKNN.readData("./cknn-dataset/01_elephant.csv");
	// CKNN.readData("./cknn-dataset/02_fox.csv");
	// CKNN.readData("./cknn-dataset/03_tiger.csv");
	// CKNN.readData("./cknn-dataset/04_musk1.csv");
	// CKNN.readData("./cknn-dataset/05_musk2.csv");
	// CKNN.readData("./cknn-dataset/06_Mutagenesis_atoms.csv");
	// CKNN.readData("./cknn-dataset/07_Mutagenesis_chains.csv");
	// CKNN.readData("./cknn-dataset/08_Mutagensis_bounds.csv");

	hDistType = 0;
	isOriginal = false;
	int R = 2;  //2
	int C = 4; 	//4
	int max_grp = 0;


	int start_s=clock();
	
	if(!isOriginal)
		CKNN.grouping(1);
	CKNN.init();

	for (int bid = 0; bid < CKNN.dataset.size(); bid++)
	{
		int grp_size = CKNN.dataset[bid].grp.size();
		// int inst_size = CKNN.dataset[bid].ins.size();
		// std::cout << "bid: "<< bid <<" grp_num: "<< grp_size << std::endl;
		// std::cout << "bid: "<< bid <<" inst_num: "<< inst_size << std::endl;
		max_grp = grp_size > max_grp? grp_size: max_grp;
	}
	std::cout << "max_grp_num: " << max_grp << std::endl;

	vector<int> res;

	for(int i = 0; i < CKNN.dataset.size(); i++)	
	{
		cout<<"Pkg: "<<i<<endl;
		CKNN.clean(i); //clean all existing info about i
		if(!isOriginal)
			res.push_back(CKNN.predict(i, R, C));
		else
			res.push_back(CKNN.ori_predict(i, R, C));
	}
	int stop_s=clock();

	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	for(int i = 0; i < res.size(); i++)
		cout<< "[ "<< i << "] " << res[i] << std::endl;

	int accurateItem = 0;
	for(int i = 0; i < res.size(); i++)
	{
		if(res[i] == CKNN.dataset[i].label)
			accurateItem++;
	}

	cout<<(double)accurateItem / (double)res.size()<<endl;
	long long SUM = countDistComp + countDistComp2 + countDistComp3 + countDistComp4 + countDistComp5;
	cout<<"dist:"<<countDistComp<<" "<<countDistComp / (double)SUM <<endl;
	cout<<"dist2:"<<countDistComp2<<" "<<countDistComp2 / (double)SUM <<endl;
	cout<<"dist3:"<<countDistComp3<<" "<<countDistComp3 / (double)SUM <<endl;
	cout<<"dist4:"<<countDistComp4<<" "<<countDistComp4 / (double)SUM <<endl;
	cout<<"dist5:"<<countDistComp5<<" "<<countDistComp5 / (double)SUM <<endl;
	cout<<"total:"<<SUM<<endl;
	cout<<"grp amount:"<<CKNN.numGroups<<endl;
	cout<<"avg dist:"<<distSum / distCount<<endl;
	
	return 0;
}
