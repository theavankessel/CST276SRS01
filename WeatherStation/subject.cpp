#include "stdafx.h"
#include "subject.h"
#include <algorithm>
#include "observer.h"


Subject::~Subject() {}

void Subject::Attach(Observer & observer)
{
	observers_.emplace_back(observer);
}

void Subject::Detach(Observer & observer)
{
	observers_.erase(
		std::remove_if(
			observers_.begin(),
			observers_.end(),
			[&observer](Observer const& value) // See: https://en.cppreference.com/w/cpp/language/lambda
			{
				auto const result{ &value == &observer }; // same address
				return result;
			}
		),
		observers_.end()
	);
}

void Subject::Notify()
{
	for (Observer& o : observers_)
	{
		o.Update();
	}
}
