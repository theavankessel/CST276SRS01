#pragma once
#include <vector>
#include <functional>

class Observer;

class Subject
{
protected:
	virtual ~Subject() = 0;

public:
	void Attach(Observer& observer);
	void Detach(Observer& observer);
	void Notify();

private:
	std::vector<std::reference_wrapper<Observer>> observers_;
};

