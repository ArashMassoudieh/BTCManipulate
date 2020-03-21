// BTCManupulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BTCSet.h"

int main()
{

	string path = "C:\\Users\\massoudieh\\Dropbox\\upscaling_results_share_with_myself\\sigma=1_hr\\";
	vector<string> examples;
	examples.push_back("ex1");
	examples.push_back("ex2");
	examples.push_back("ex3");
	examples.push_back("ex4");
	//examples.push_back("ex5");
	//examples.push_back("ex6");
	//examples.push_back("ex7");


	vector<vector<CBTC>> density; 
	
	vector<string> sections; 
	sections.push_back("1"); 
	sections.push_back("2");
	vector<CBTCSet> densities;
	vector<CBTC> Avg(sections.size());
	for (int i = 0; i < sections.size(); i++)
	{
		CBTCSet btcs_in_section; 
		
		for (int j = 0; j < examples.size(); j++)
		{
			
			CBTC _density(path + examples[j] + "\\concentration_BTC_d_" + sections[i] + ".txt");
			btcs_in_section.append(_density,examples[j]);
			if (j == 0) 
				Avg[i] = _density;
			else
				Avg[i] += _density;
		}
		Avg[i] = Avg[i] / double(examples.size()); 
		densities.push_back(btcs_in_section);
		btcs_in_section.writetofile(path + "combined_X=" + sections[i]);
		Avg[i].writefile(path + "Avg_X=" + sections[i] + ".txt");
	}
	
}

