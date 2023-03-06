#include "ObjectGate.h"

ObjectGate::ObjectGate(int pins, int outs) : pins(pins), outs(outs) {}
ObjectGate::~ObjectGate() { pins.clear(); outs.clear(); }

void ObjectGate::setPin(bool val, int i) { this->pins[i] = val; }
bool ObjectGate::getPin(int i) { return this->pins[i]; }

void ObjectGate::setOut(bool val, int i) { this->outs[i] = val; }
bool ObjectGate::getOut(int i) { return this->outs[i]; }