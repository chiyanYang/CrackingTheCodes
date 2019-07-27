#pragma once
#include "../Ch3Common.h"

void test3_6();

class Animal;
class Cat;
class Dog;
class AnimalShelter;
class AnimalShelterOrdered;

void testFunction(AnimalShelter& animalShelter, int method);
void testFunction(AnimalShelterOrdered& animalShelter, int method);


enum animalType
{
	ACat,
	ADog
};

class Animal
{
public:
	animalType type;
	int order;
	virtual void whoAmI() = 0;
	virtual void whoAmIOrdered() = 0;

	Animal(animalType t)
	{
		this->type = t;
	}

	Animal(animalType t, int order)
	{
		this->type = t;
		this->order = order;
	}
};

class Cat : public Animal
{
public:
	Cat(): Animal(ACat) {}
	Cat(int order) : Animal(ACat, order) {}

	void whoAmI()
	{
		cout << "I'm a cute CAT, meow" << endl;
	}

	void whoAmIOrdered()
	{
		cout << this->order << ": I'm a cute CAT, meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal(ADog) {}
	Dog(int order) : Animal(ADog, order) {}

	void whoAmI()
	{
		cout << "I'm a big DOG, wan" << endl;
	}

	void whoAmIOrdered()
	{
		cout << this->order << ": I'm a big DOG, wan" << endl;
	}
};

class AnimalShelterOrdered
{
private:
	list<Cat*> cats;
	list<Dog*> dogs;
	int order = 0;

public:
	void enqueue(Animal* animal)
	{
		animal->order = this->order;

		if (animal->type == ADog)
		{
			dogs.push_back((Dog*)animal);
		}
		else if(animal->type == ACat)
		{
			cats.push_back((Cat*)animal);
		}

		order++;
	}

	Animal* dequeueAny()
	{
		if (cats.size() == 0 && dogs.size() != 0)
		{
			return this->dequeueDog();
		}
		else if (cats.size() != 0 && dogs.size() == 0)
		{
			return this->dequeueCat();
		} 
		else if (cats.size() != 0 && dogs.size() != 0)
		{
			Dog* dog = dogs.front();
			Cat* cat = cats.front();

			if (dog->order < cat->order)
			{
				return this->dequeueDog();
			}
			else
			{
				return this->dequeueCat();
			}
		}
		else
		{
			cout << "No animal now" << endl << endl;
			return NULL;
		}
	}

	Animal* dequeueDog()
	{
		if (dogs.size() != 0)
		{
			Animal* animal = dogs.front();
			dogs.pop_front();

			return animal;
		}
		
		cout << "No dogs now" << endl << endl;
		return NULL;
	}

	Animal* dequeueCat()
	{
		if (cats.size() != 0)
		{
			Animal* animal = cats.front();
			cats.pop_front();

			return animal;
		}

		cout << "No cats now" << endl << endl;
		return NULL;
	}

	void print()
	{
		for (auto it : cats)
		{
			it->whoAmIOrdered();
		}

		for (auto it : dogs)
		{
			it->whoAmIOrdered();
		}

		cout << endl;
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
		Animal* animal = animals.front();
		animals.pop_front();

		return animal;
	}

	Animal* dequeueDog()
	{
		if (animals.size() != 0)
		{
			return this->raiseAnimal(ADog);
		}

		cout << "No dogs now" << endl << endl;
		return NULL;
	}

	Animal* dequeueCat()
	{
		if (animals.size() != 0)
		{
			return this->raiseAnimal(ACat);
		}

		cout << "No cats now" << endl << endl;
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
		for (auto it = animals.cbegin(); it != animals.cend(); it++)
		{
			if ((*it)->type == t)
			{
				Animal* raisedAnimal = *it;
				animals.erase(it);
				return raisedAnimal;
			}
		}

		return this->dequeueAny();
	}
};