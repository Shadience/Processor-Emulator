#pragma once
#include "ObjectGate.h"

class ANDGate :public ObjectGate
{
	ANDGate();
	~ANDGate();

	bool doLogic(std::vector<bool> pins, std::vector<bool> outs) override;
private:
	std::vector<bool> pins;
	std::vector<bool> outs;
};