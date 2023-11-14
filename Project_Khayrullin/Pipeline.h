#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class Pipeline {
	int id;
	static int NextId;
public:
	inline int getid() const { return id; };
	string name;
	double length;
	double diameter;
	bool repairing;
	Pipeline();
	void AddPipeLine();
	static void ViewingPipes(const unordered_map<int, Pipeline>& pipelines);
	//void EditPipeLine(unordered_map<int, Pipeline>& pipelines, const string& pipeName);
	static void ChangePipe(unordered_map<int, Pipeline>& pipelines);
	static void SavePipes(const unordered_map<int, Pipeline>& pipelines, string fileName);
	void LoadPipes(unordered_map<int, Pipeline>& pipelines, string fileName);
};

