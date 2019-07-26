#include "3_6.h"

// Animal Shelter
void test3_6()
{
	int method;
	AnimalShelter animalShelter;

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
			testFunction(animalShelter, method);
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
				delete toBeRaised;
				break;
		case 4: toBeRaised = animalShelter.dequeueCat();
				toBeRaised->whoAmI();
				delete toBeRaised;
				break;
		case 5: toBeRaised = animalShelter.dequeueAny();
				toBeRaised->whoAmI();
				delete toBeRaised;
				break;
		case 6: animalShelter.print();
				cout << endl;
				break;
	}

	toBeRaised = NULL;
	toBeEnqueued = NULL;
}