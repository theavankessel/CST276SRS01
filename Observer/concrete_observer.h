#pragma once
#include "observer.h"
#include "concrete_subject.h"

class ConcreteObserver : public Observer
{
private:
	void Update() override;
	bool observerState;
	ConcreteSubject subject;
};