#include "stdafx.h"
#include "concrete_observer.h"

void ConcreteObserver::Update()
{
	observerState = subject.GetState();
}
