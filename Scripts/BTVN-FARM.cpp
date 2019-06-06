#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Goat.h"
#include <vector>

int main()
{
	std::string animalType{};
	int animalCount{};
	char apply{};

	std::vector<Animal*> animal{};

	for (int i{ 0 }; i < 10; ++i)
	{
		animal.push_back(new Animal());
	}

	do
	{
		do
		{
			std::cout << "Ban muon them dong vat nao (Cho, Meo, De) : ";
			std::cin >> animalType;

			std::cout << "So luong con (so luong phai lon hon 0) : ";
			std::cin >> animalCount;

			std::string temp = animalCount <= 0 || (animalType != "Cho" && animalType != "Meo" && animalType != "De") ? "Loi ! Moi nhap lai." : "Them thanh cong!";
			std::cout << temp << std::endl;
		}
		while (animalCount <= 0 || (animalType != "Cho" && animalType != "Meo" && animalType != "De"));

		if (animalType == "Cho")
		{
			for (int i{ 0 }; i < animalCount; ++i)
			{
				animal.push_back(new Dog());
			}
		}
		else if (animalType == "Meo")
		{
			for (int i{ 0 }; i < animalCount; ++i)
			{
				animal.push_back(new Cat());
			}
		}
		else
		{
			for (int i{ 0 }; i < animalCount; ++i)
			{
				animal.push_back(new Goat());
			}
		}

		std::cout << "Ban co muon them nua khong (Y/N) ? : ";
		std::cin >> apply;
	}
	while (apply == 'Y');

	printf("\n");
	printf("\t\t\t\t\tTieng keu cua nong trai\n");
	printf("\t\t\t\t\t***********************\n");

	for (int i{ 0 }; i < animal.size(); ++i)
	{
		animal[i]->Sound();
	}

	for (std::vector <Animal*> ::iterator i = animal.begin(); i != animal.end(); ++i)
	{
		delete* i;
	}
}