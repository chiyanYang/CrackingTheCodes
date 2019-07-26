#pragma once
#include "../Ch3Common.h"

void test3_6();

class Animal;
class Cat;
class Dog;
class AnimalShelter;

void testFunction(AnimalShelter& animalShelter, int method);



enum animalType
{
	ACat,
	ADog
};

class Animal
{
public:
	animalType type;
	virtual void whoAmI() = 0;

	Animal(animalType t)
	{
		this->type = t;
	}
};

class Cat : public Animal
{
public:
	Cat(): Animal(ACat) {}

	void whoAmI()
	{
		cout << "I'm a cute CAT, meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal(ADog) {}

	void whoAmI()
	{
		cout << "I'm a big DOG, wan" << endl;
	}
};

class AnimalShelter
{
private:
	list<Animal*> animals;

public:
	void enqueue(Animal* animal)
	{
		animals.push_back(animal);
	}

	Animal* dequeueAny()
	{
		Animal* animal = animals.back();
		animals.pop_back();

		return animal;
	}

	Animal* dequeueDog()
	{
		if (animals.size() != 0)
		{
			return this->raiseAnimal(ADog);
		}
		
		cout << "No animal now" << endl << endl;
		return NULL;
	}

	Animal* dequeueCat()
	{
		if (animals.size() != 0)
		{
			return this->raiseAnimal(ACat);
		}

		cout << "No animal now" << endl << endl;
		return NULL;
	}

	void print()
	{
		for (auto it : animals)
		{
			it->whoAmI();
		}

		cout << endl;
	}

private:
	Animal* raiseAnimal(animalType t)
	{
		int pos = animals.size();
		for (auto rit = animals.crbegin(); rit != animals.crend(); ++rit)
		{
			if ((*rit)->type == t)
			{
				Animal* raised = (*rit);
				animals.erase(next(rit).base());
				return raised;
			}
		}

		return this->dequeueAny();
	}
};