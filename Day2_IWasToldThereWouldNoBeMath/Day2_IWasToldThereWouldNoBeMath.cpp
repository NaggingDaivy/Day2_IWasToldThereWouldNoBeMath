// Day2_IWasToldThereWouldNoBeMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream file("WrapPaperList.txt");
	int total = 0;

	if (!file)
		cout << "Erreur ouverture fichier" << endl;
	else
	{
		string str_Line;

		while (getline(file, str_Line))
		{
			string str_l, str_w, str_h;
			int xPosition = 0;

			for (int i = 0; i < str_Line.size(); ++i)
			{
				if (str_Line[i] == 'x')
					++xPosition;
				else if (xPosition == 0)
					str_l += str_Line[i];
				else if (xPosition == 1)
					str_w += str_Line[i];
				else if (xPosition == 2)
					str_h += str_Line[i];
			}

			int il= stoi(str_l);
			int iw = stoi(str_w);
			int ih = stoi(str_h);

			int side1 = il * iw;
			int smallestSide = side1;

			int side2 = iw * ih;
			
			if (side2 < smallestSide)
				smallestSide = side2;

			int side3 = ih * il;

			if (side3 < smallestSide)
				smallestSide = side3;

			total += 2 * side1 + 2 * side2 + 2 * side3 + smallestSide;
		}
	}

	cout << "Total : " << total << endl;


	
	
	
	return 0;

}

