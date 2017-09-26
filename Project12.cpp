/* Learning resource credit https://www.youtube.com/watch?v=POYRev0zk2k&t=110s */
#include <iostream>
#include <map>
#include <string>

int main() {
	/*
	std::map<std::string, int> map;

	std::string weapon = "Weapon2";

	map["Weapon1"] = 100;
	map["Weapon2"] = 120;

	std::cout << "Damage: " << map[weapon] << std::endl;

	*/
	// cannot create duplicate keys inside the map

	std::map<int, std::string> name_map;

	name_map[1] = "Samantha";
	name_map[2] = "Jordan";

	std::cout << name_map.size() << std::endl;

	for (std::map<int, std::string>::iterator i = name_map.begin(); i != name_map.end(); i++)
	{
		std::cout << i->first << " => " << i->second << std::endl;
	}

	// find 
	std::map<int, std::string>::iterator i = name_map.find(2);
	std::cout << "Key found " << i->second << std::endl;

	name_map.clear();

	std::cout << name_map.size() << std::endl;

	// insert values into map ..

	name_map.insert(std::pair<int, std::string>(3, "Jess"));

	// check new addition

	std::cout << name_map[3] << std::endl;

	system("pause");
	return 0;
}