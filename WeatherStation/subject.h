#pragma once
#include <vector>
#include <functional>
#include "weatherStationExport.h"

class Observer; // Don't ned to include observer header file because we just have references(addresses)

class  WEATHERSTATION_API Subject
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

