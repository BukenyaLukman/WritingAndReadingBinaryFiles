#include<iostream>
#include<fstream>
using namespace std;

#pragma pack(push, 1)

struct Person{
	char name[50];
	int age;
	double height;
};
#pragma pack(pop)


int main(){


	Person someone = { "Froddo", 220,1.5 };
	string filename = "ticket.bin";
	// Writing binary file
	ofstream outputFile;

	outputFile.open(filename, ios::binary);

	if (outputFile.is_open())
	{	
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	}else{
		cout << "Could not create file " << filename << endl;
	}

	

	Person someoneElse = {};

	ifstream inputFile;

	inputFile.open(filename, ios::binary);

	if (inputFile.is_open())
	{	
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		inputFile.close();
	}else{
		cout << "Could not read file " << filename << endl;
		 
	}

	cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;


	outputFile.close();

	

	return 0;
}