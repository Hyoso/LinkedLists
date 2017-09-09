#include <iostream>	
#include <string>

class Thing
{
public:
	Thing() {}
	Thing(std::string data, Thing* otherThing) : m_data(data), m_otherThing(otherThing) {}

	std::string m_data;
	Thing* m_otherThing;
};

static std::ostream& operator<<(std::ostream& os, const Thing& t)
{
	//os << t.m_a << " " << t.m_b << " " << t.m_c << " " << t.m_d;
	return os;
}

void main()
{
	Thing* start = new Thing("burger", new Thing("chips", new Thing("pizza", nullptr)));
	Thing* startPointer = start;
	Thing* prevPoint = nullptr;
	Thing* insertObj = new Thing("mushroom", nullptr);
	while (true)
	{
		//std::cout << startPointer->m_data << std::endl;
		if (startPointer->m_data == "aha")
		{
			if (!prevPoint)
			{
				// insert at start of linked list
				insertObj->m_otherThing = startPointer;
				start = insertObj;
			}
			else
			{
				// insert new object here
				insertObj->m_otherThing = startPointer;
				prevPoint->m_otherThing = insertObj;
				break;
			}
		}
		else if (!startPointer->m_otherThing)
		{
			startPointer->m_otherThing = insertObj;
			break;
		}

		// break if a null point is found
		if (!startPointer->m_otherThing)
		{
			break;
		}
		prevPoint = startPointer;
		startPointer = startPointer->m_otherThing;
	}

	startPointer = start;
	while (true)
	{
		std::cout << startPointer->m_data << std::endl;

		// break if a null point is found
		if (!startPointer->m_otherThing)
		{
			break;
		}
		startPointer = startPointer->m_otherThing;
	}



	system("PAUSE");
	return;
}