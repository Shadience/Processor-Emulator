#pragma once
#include "stdafx.h"

class ObjectGate
{
public:
	ObjectGate(int pins, int outs);
	~ObjectGate();

	void setPin(bool val, int i);
	bool getPin(int i);

	void setOut(bool val, int i);
	bool getOut(int i);

	virtual bool doLogic(std::vector<bool> pins, std::vector<bool> outs);
private:
	std::vector<bool> pins;
	std::vector<bool> outs;
};