#pragma once
#include "../Ch3Common.h"

void test3_6();

class Animal;
class Cat;
class Dog;
class AnimalShelter;

enum animalType
{
	ACat,
	ADog
};

class Animal
{
public:
	animalType type;
	int sequenceNum;
	virtual void whoAmI() = 0;

	Animal(animalType t, int num)
	{
		this->type = t;
		this->sequenceNum = num;
	}
};

class Cat : public Animal
{
	Cat(int num): Animal(ACat, num) {}

	void whoAmI()
	{
		cout << "I'm a cute cate, meow" << endl;
	}
};

class Dog : public Animal
{
	Dog(int num) : Animal(ADog, num) {}

	void whoAmI()
	{
		cout << "I'm a big dog, wan" << endl;
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
		return this->raiseAnimal(ADog);
	}

	Animal* dequeueCat()
	{
		return this->raiseAnimal(ACat);
	}

private:
	Animal* raiseAnimal(animalType t)
	{
		auto itBegin = animals.cbegin();
		itBegin--;

		auto it = animals.cend();
		it--;

		while (it != (itBegin))
		{
			if ((*it)->type == t)
			{
				Animal* raised = (*it);
				animals.erase(it);
				return raised;
			}
		}
	}
};