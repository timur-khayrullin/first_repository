#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class Pipeline {
public:
	double length;
	double diameter;
	bool repairing;
	Pipeline() :length(10), diameter(1), repairing(false) {};

	void AddPipeLine(unordered_map<string, Pipeline>& pipelines);
	void ViewingPipes(const unordered_map<string, Pipeline>& pipelines);
	void EditPipeLine(unordered_map<string, Pipeline>& pipelines, const string& pipeName);
	void ChoosePipe(unordered_map<string, Pipeline>& pipelines);
	void SavePipes(const unordered_map<string, Pipeline>& pipelines, string fileName);
	void LoadPipes(unordered_map<string, Pipeline>& pipelines, string fileName);
};

