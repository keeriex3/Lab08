/*aesar.cpp
Caesar�s Cipher-encrypt a plain text message by adding a shift
to each alphabetic character to produce cipher text.
The plain text will be in an existing file and the cipher
text will be saved in a new file.
*/

#include <iostream>
#include <fstream>
using namespace std;

void process(ifstream & in, ofstream & out);
void highandlow(ifstream & in, ofstream & out);

int main(){
	/*Asks user for filenames for numbers and then only positive numbers
	Opens streams to the files
	Asks user for the shift
	Calls process()
	Closes files
	*/
	char inFileName[200];
	char outFileName[200];
	cout << "Enter file name of all numbers file including path from drive letter: \n";
	cin >> inFileName;
	cin.getline(inFileName, 200);
	cout << "Enter name and path for positive numbers file: \n";
	cin >>outFileName;
	cin.getline(outFileName, 200);
	cout << "So, I will read all numbers from " << inFileName << endl;
	cout << "and write the positive numbers to " << outFileName << endl;
	ifstream in;
	ofstream out;
	in.open(inFileName);
	if (!in.is_open()){
		cout << "ERROR: Failed to open " << inFileName << "for input \n";
		exit(-1);

	}
	out.open(outFileName);
	if (!out.is_open()){
		cout << "EROR: Failed to open " << outFileName << "for output \n";
		exit(-2);
	}
	process(in, out);
	//If you want to use highandlow funciton, comment out the proccess function and use highandlow.
	//highandlow(in, out);
	in.close();
	out.close();
	cout << "Look in " << outFileName << "for positive numbers\n";
	return 0;
}

/*void process(ifstream & in, ofstream & out, int shift){
	char c;
	while (in >> noskipws >> c){
		if (c >= '1' && c <= 'Z'){
			c += shift;
		}
		else if (c >= 'a' && c <= 'z'){
			c += shift;
		}
}

out << c;
}
*/
void process(ifstream & in, ofstream & out)
{
	double current_number;
	while (in >> current_number){
		if (current_number > 0)
			out << current_number;

	}

}

void highandlow(ifstream & in, ofstream & out)
{
	double max, low, num;
	bool firstRun = 0;
	while (in >> num)
	{
		if (firstRun == 0){
			max = num;
			low = num;
			firstRun = 1;
		}
		else{
			if(num > max)
				max = num;
			if(num < low)
				low = num;
		}
	}
	out << max << endl;
	out << low << endl;
}
