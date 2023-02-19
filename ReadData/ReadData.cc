#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

void ReadData (std::string filename, std::vector<std::vector<int>>& arr)
{
	std::vector<std::string> output;
	std::string line1;
	std::ifstream myfile (filename.c_str ());
	if (myfile.is_open ())
	{
		while (getline (myfile, line1))
		{
			int size = line1.size ();
			if (line1.size () == 0)
			{
				continue;
			}
			output.push_back (line1);
		}
		myfile.close ();
		int size = output.size ();
		for (int i = 0; i < size; i++)
		{
			std::cout << output[i] << std::endl;
		}
		for (int i = 0; i < size; i++)
		{
			std::string line = output[i];
			std::string temp;
			std::vector<int> row;
			int num = line.size ();
			for (int j = 0; j < num; j++)
			{
				if (line[i] == ' ')
				{
					row.push_back (std::atoi (temp.c_str ()));
					temp.clear ();
				}
				else if (i == num-1)
				{
					temp.push_back (line[i]);
					row.push_back (std::atoi (temp.c_str ()));
				} 
				else
				{
					temp.push_back (line[i]);
				}
			}
			arr.push_back (row);
		}
	}
	else
	{
		std::cout << "cannot open file " << filename << std::endl;
	}
}

int main (void)
{
	std::vector< std::vector<int> > arr;
	std::string filename = "input.txt";
	ReadData (filename, arr);
	for (int i = 0; i < (int)arr.size (); i++)
	{
		std::vector<int> v = arr[i];
		int s = v.size ();
		for (int j = 0; j < s; j++)
		{
			std::cout << v[j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
