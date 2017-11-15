#include <iostream>
using namespace std;

int ternary_search(int nlist[], int val, int& c) {

	// to end search
	bool done = true;
	bool fail = false;

	int key = val; // set val to key to search for 
	int result = -1; // will return -1 if not found and the key if found
	int keycount = 0;

	int start = 0;
	// int end = 10; // get lenght of the array
	int end = sizeof(nlist) / sizeof(nlist[0]);

	// set indexes to divide into 3 parts
	int index1 = start + ((end - start) / 3);
	int index2 = (start + 2 * (end - start) / 3);
	int index3 = 19;

	// print out the 3 indexes 
	std::cout << "Index 1 : " << index1 << std::endl;
	std::cout << "Index 2 : " << index2 << std::endl;
	std::cout << "Index 3 : " << index3 << std::endl;

	while (done == true) {

		if (key >= 0 && key < index1) {
			done = false; 
			for (int i = 0; i < index1;) {
				std::cout << "Checking if " << nlist[i] << "is equal to" << key << std::endl;
				if (nlist[i] == key) {
					std::cout << "Search successful" << std::endl;
					std::cout << nlist[i] << "is located at index {" << i << "} " << std::endl;
					keycount++;
				}
				
				std::cout << "Checkng if " << nlist[i] << "is less then " << key << std::endl;
				if (nlist[i] < key) {
					i++;
				}
			}
		}

		if (key >= index1 && key >= index2) {
			done = false;
			for (int i = index1; i <= index2; i++) {
				std::cout << "Checking if " << nlist[i] << " is equal to " << key << endl;
				if (nlist[i] == key) {
					std::cout << "Search successful" << std::endl;
					std::cout << nlist[i] << "is located at index {" << i << "} " << std::endl;
					keycount++;
				}

					std::cout << "Checkng if " << nlist[i] << "is less then " << key << std::endl;

					if (nlist[i] < key) {
						i++;
					}
				
			}
		}

		if (key >= index2 && key <= index3) {
			done = false;
			for (int i = index2; i < index3; i++) {
				std::cout << "Checking if " << nlist[i] << " is equal to " << key << endl;
				if (nlist[i] == key) {
					std::cout << "Search successful" << std::endl;
					std::cout << nlist[i] << "is located at index {" << i << "} " << std::endl;
					keycount++;
				}

				std::cout << "Checkng if " << nlist[i] << "is less then " << key << std::endl;

				if (nlist[i] < key) {
					i++;
				}
			}
		}
	
	}

	c = keycount;

	if (keycount != 0) {
		result = key;
	}
	return result;
}

int main(int argc, char** argv) {

	
	int count = 0;
	int list[19] = { 6,12,18,22,29,37,38,41,51,53,55,67,73,75,77,81
		,86,88,94 };
	int found = ternary_search(list, 27, count);

	// test...
	//int length = sizeof(list) / sizeof(list[0]);
	//std::cout << length << std::endl;

	if (found != -1) {
		std::cout << "Key " << found << " has been found " << count << " times! woohoo" << std::endl;
	}
	else {
		std::cout << "Sorry your key was not found, try again with another key or list! " << std::endl;
	}

	system("pause");
	return 0;
}