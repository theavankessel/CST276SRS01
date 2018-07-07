#pragma once
#include <vector>
#include <functional>
#include "observer.h"

class Subject
{
public:
	virtual ~Subject() = 0;
	void Attach(Observer& observer);
	void Detach(Observer& observer);
	void Notify();

private:
	std::vector<std::reference_wrapper<Observer>> observers_;
};

