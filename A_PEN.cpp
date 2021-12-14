#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include<cstring>
#include <random>
#include <ctime>
#include <vector>
#include <chrono>

using namespace std;

class res 
{
public:
	int ra;
	int dec;
	double pr;
};

inline void read(string file, vector<res> (&ares))
{
	ares.clear();
	res g;
	int temp;
	ifstream fp(file.c_str());
	if (!fp.is_open())
	{
		cout << "not opened" << endl;
	}

	while (fp>>temp)
	{
		fp >> g.ra;
		fp >> g.dec;
		fp >> g.pr;
		ares.push_back(g);
	}
}

double p_est(vector<res>(&ares),int c)
{
	double Pr_est;
	for (int n=1; n < c; n++)
	{
		double Tn,M=3;
		Tn = (ares[n].pr + ares[n + 1].pr) / 2;
		Pr_est = 1 - exp(-exp(-((ares[0].pr - Tn - 2 * log(n) - (M - 2) * log(ares[0].pr / Tn)) / 2)));

	}
	return Pr_est;
}


int main()
{
	

	double c=0;
	cin >> c;
	auto start_time = std::chrono::steady_clock::now();
	vector<res> ares;
	read("sort_test_dip.txt", ares);
	cout << "enter N" << endl;
	//cout << log(2.8)<<endl;
	cout << endl;
	cout <<setprecision(30)<< p_est(ares, c)<< endl;

	auto end_time = std::chrono::steady_clock::now();
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
	std::cout << elapsed_ns.count() << " ns\n";

	system("pause");
	return 0;
}