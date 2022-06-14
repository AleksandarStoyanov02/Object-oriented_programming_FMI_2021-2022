#include <iostream>
#include "Storage.h"
#include "Fruit.h"
#include "Product.h"
int main() {
	Storage list;
	MyString buffer;
	
	std::cout << "1.Print" << std::endl;
	std::cout << "2.Add" << std::endl;
	std::cout << "3.Remove by index" << std::endl;
	std::cout << "4.Remove with parameters" << std::endl;
	std::cout << "6.Log" << std::endl;
	std::cout << "7.Income" << std::endl;
	std::cout << "8.Clean" << std::endl;

	std::cin >> buffer;

	do {
		buffer.getLine(std::cin);
		Vector<MyString> currentCommands = buffer.split(' ');
		if (strcmp(currentCommands[0].c_str(), "Print") == 0) {
			list.print();
		}
		else if (strcmp(currentCommands[0].c_str(), "Add") == 0) {
			if (strcmp(currentCommands[1].c_str(), "Fruit") == 0) {
				std::time_t t = std::time(0);
				list.addFruit(currentCommands[2], currentCommands[3], t,
					currentCommands[5].parseInt(), currentCommands[6].parseDouble());
			}
			else if (strcmp(currentCommands[1].c_str(), "Vegetable") == 0) {
				std::time_t t = std::time(0);
				list.addVegetable(currentCommands[2], currentCommands[3], t,
					currentCommands[5].parseInt(), currentCommands[6].parseDouble());
			}
			else if (strcmp(currentCommands[1].c_str(), "Drink") == 0) {
				std::time_t t = std::time(0);
				list.addDrink(currentCommands[2], currentCommands[3],
					t, currentCommands[5].parseInt(), currentCommands[6].parseDouble());
			}
			else if (strcmp(currentCommands[1].c_str(), "Alcohol Drink") == 0) {
				std::time_t t = std::time(0);
				list.addAlcoholDrink(currentCommands[2], currentCommands[3],
					t, currentCommands[5].parseInt(), currentCommands[6].parseInt(), currentCommands[7].parseDouble());
			}
		}
		else if (strcmp(currentCommands[0].c_str(), "Remove") == 0) {
			if (strcmp(currentCommands[1].c_str(), "by index") == 0) {
				list.remove(currentCommands[2].parseInt());
			}
			else if (strcmp(currentCommands[1].c_str(), "with parameters") == 0) {
				std::time_t t = std::time(0);
				list.remove(currentCommands[2], currentCommands[3]);
			}
		}
		else if (strcmp(currentCommands[0].c_str(), "Log") == 0) {
			list.log();
		}
		else if (strcmp(currentCommands[0].c_str(), "Income") == 0) {
			list.getCurrentIncome();
		}
		else if (strcmp(currentCommands[0].c_str(), "Clean") == 0) {
			list.clean();
		}
	} while (strcmp(buffer.c_str(), "quit") != 0);
}