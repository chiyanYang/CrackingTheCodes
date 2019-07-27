#include "3_6.h"

// Animal Shelter
void test3_6()
{
	int method;
	// AnimalShelter shelter; // unmark this to test AnimalShelter
	AnimalShelterOrdered shelter;

	while (true)
	{
		cout << "1: Enqueue an Dog" << endl;
		cout << "2: Enqueue an Cat" << endl;
		cout << "3: Dequeue an Dog" << endl;
		cout << "4: Dequeue an Cat" << endl;
		cout << "5: Dequeue Any" << endl;
		cout << "6: Print list" << endl;
		cout << "7: Exit" << endl << endl;
		cout << "Please enter the method: ";
		cin >> method;
		cout << endl;

		if (method != 7)
		{
			testFunction(shelter, method);
		}
		else
		{
			break;
		}
	}
}

void testFunction(AnimalShelter& animalShelter, int method)
{
	Animal* toBeRaised = NULL;
	Animal* toBeEnqueued = NULL;

	switch(method)
	{
		case 1: toBeEnqueued = new Dog();
				animalShelter.enqueue(toBeEnqueued);
				break;
		case 2: toBeEnqueued = new Cat();
				animalShelter.enqueue(toBeEnqueued);
				break;
		case 3: toBeRaised = animalShelter.dequeueDog();
				toBeRaised->whoAmI();
				cout << endl;
				delete toBeRaised;
				break;
		case 4: toBeRaised = animalShelter.dequeueCat();
				toBeRaised->whoAmI();
				cout << endl;
				delete toBeRaised;
				break;
		case 5: toBeRaised = animalShelter.dequeueAny();
				toBeRaised->whoAmI();
				cout << endl;
				delete toBeRaised;
				break;
		case 6: animalShelter.print();
				cout << endl;
				break;
	}

	toBeRaised = NULL;
	toBeEnqueued = NULL;
}

void testFunction(AnimalShelterOrdered& animalShelterOrdered, int method)
{
	Animal* toBeRaised = NULL;
	Animal* toBeEnqueued = NULL;

	switch (method)
	{
	case 1: toBeEnqueued = new Dog();
		animalShelterOrdered.enqueue(toBeEnqueued);
		break;
	case 2: toBeEnqueued = new Cat();
		animalShelterOrdered.enqueue(toBeEnqueued);
		break;
	case 3: toBeRaised = animalShelterOrdered.dequeueDog();
		toBeRaised->whoAmI();
		delete toBeRaised;
		break;
	case 4: toBeRaised = animalShelterOrdered.dequeueCat();
		toBeRaised->whoAmI();
		cout << endl;
		delete toBeRaised;
		break;
	case 5: toBeRaised = animalShelterOrdered.dequeueAny();
		toBeRaised->whoAmI();
		cout << endl;
		delete toBeRaised;
		break;
	case 6: animalShelterOrdered.print();
		cout << endl;
		break;
	}

	toBeRaised = NULL;
	toBeEnqueued = NULL;
}