#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipeline.h"
#include "CompressionStation.h"
using namespace std;
bool Confirm();
void filterPipe(const unordered_map<string, Pipeline>& pipelines);
void filterStation(const unordered_map<string, CompressionStation> stations);
int InputInt(int min, int max);
double InputDouble(int min, double max);
string InputString();