#include "stdafx.h"
#include "concrete_subject.h"

bool ConcreteSubject::GetState() const
{
	return subjectState;
}

void ConcreteSubject::SetState(bool state)
{
	subjectState = state;
}
