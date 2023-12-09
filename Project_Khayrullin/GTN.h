#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Pipeline.h"

using namespace std;

struct Rib {
	int ID;
	int FromCS;
	int ToCS;
};

class network {
public:
	vector<Rib> graph;
	static void AddPipeToNetwork(const unordered_map<int, Pipeline>& pipelines, network& GTNetwork, int NumStations);
	static void DeletePipeFromNetwork(network& GTNetwork);
	static void PrintGraph(network& GTNetwork);
	static void TopologicSort(network& GTNetwork);
	static void DeletePipeWithStation(network& GTNetwork, int stationID);
};