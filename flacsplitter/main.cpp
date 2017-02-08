#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

	char * buffer;
	long size;
	_Longlong num;
	char kek, matcher, keywordlength;
	string keyword,extension,file;

	cout << "\n		ULTRA FILE SPLITTER 3000 \n";

	while(true)
	{

		num=1;matcher=0;

		cout << "\nEnter input file name: ";
		cin >> file;

		cout << "Enter specific keyword to split by: ";
		cin >> keyword;

		cout << "Enter file extension (for example .flac): ";
		cin >> extension;

		keywordlength = keyword.length();

		ifstream infile (file,ifstream::binary);
		ofstream outfile (file+" - 1"+extension,ofstream::binary);

		// get size of file
		infile.seekg(0,ifstream::end);
		size=infile.tellg();
		infile.seekg(0);

		// allocate memory for file content
		buffer = new char [size];

		cout<<"size: "<< size << "\n splitting into files...";
	

		for(int a=0;a<size;a++)
		{
			//cout<<(kek=infile.get())<<" ";
			kek=infile.get();
			outfile << kek;

			if(kek==keyword[matcher])
			{
				if(matcher<keywordlength-1)
					matcher++;
				else
				{
					outfile.close();
					if(num>1)
					{
						outfile.open(file+" - "+to_string(num)+extension,ofstream::binary);
					
					
					}
					else
					{
						//if(a>keywordlength)
							outfile.open(file+" - 1"+extension,ofstream::binary);
						//else
					}
					num++;
					outfile << keyword;
					matcher=0;
				
				}				//GOTCHA
			}
			else
			{
				matcher=0;
			}
		}

			// read content of infile

		//infile.read (buffer,size);

			// write to outfile

		//outfile.write (buffer,size);

		// release dynamically-allocated memory
		delete[] buffer;

		outfile.close();
		infile.close();

		cout<<"Done. \n Number of your shit found: "<< num-1 << "\n";
	
		system("pause");

	}
	//return 0;
}