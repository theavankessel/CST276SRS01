#pragma once
#include "subject.h"

class ConcreteSubject : public Subject
{
public:
	bool GetState() const;
	void SetState(bool state);

private:
	bool subjectState;
};