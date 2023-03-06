#include "NOTGate.h"

NOTGate::NOTGate() : ObjectGate(1, 1) {}
NOTGate::~NOTGate() { pins.clear(); outs.clear(); }

bool NOTGate::doLogic(std::vector<bool> pins, std::vector<bool> outs) { return ~pins[0]; }