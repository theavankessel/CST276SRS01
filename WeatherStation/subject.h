#pragma once
#include <vector>
#include <functional>
#include "weatherStationExport.h"

class Observer;

//WEATHERSTATIONIMP_TEMPLATE template class WEATHERSTATION_API std::vector<std::reference_wrapper<Observer>>;

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

