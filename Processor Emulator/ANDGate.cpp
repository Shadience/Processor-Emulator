#include "ANDGate.h"

ANDGate::ANDGate() : ObjectGate(2, 1) {}
ANDGate::~ANDGate() { pins.clear(); outs.clear(); }

bool ANDGate::doLogic(std::vector<bool> pins, std::vector<bool> outs) { return pins[0] & pins[1]; }