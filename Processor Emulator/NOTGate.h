#pragma once
#include "ObjectGate.h"

class NOTGate :public ObjectGate
{
	NOTGate();
	~NOTGate();

	bool doLogic(std::vector<bool> pins, std::vector<bool> outs) override;
private:
	std::vector<bool> pins;
	std::vector<bool> outs;
};