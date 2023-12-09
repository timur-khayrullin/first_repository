#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "GTN.h"
#include "utils.h"
#include "Pipeline.h"
#include <unordered_set>


void network::AddPipeToNetwork(const unordered_map<int, Pipeline>& pipelines, network& GTNetwork,int NumStations) {
	unordered_set<int> Ids = Pipeline::ChooseIdbyName(pipelines);
	if (!Ids.empty()) {
		for (const auto& i : Ids) {
			bool PipeExist = false;
			for (const auto& existingRib : GTNetwork.graph) {
				if (i == existingRib.ID) {
					cout << "This pipe already added in GT Network" << endl;
					PipeExist = true;
					break;
				}
			}
				if(!PipeExist) {
					Rib rib;
					rib.ID = i;
					cout << "Enter the ID of the station from which the pipe starts: " << endl;
					rib.FromCS = InputValue<int>(0, NumStations);
					cout << "Enter the ID of the station where the pipe ends: " << endl;
					rib.ToCS = InputValue<int>(0, NumStations);
					GTNetwork.graph.push_back(rib);
				}
			}
		}
	else {
		cout << "Pipes with such name have not been found" << endl;
	}
}

void network::DeletePipeFromNetwork(network& GTNetwork)
{
	cout << "Input ID of pipe to delete" << endl;
	int id = InputValue<int>(1, GTNetwork.graph.size());
	GTNetwork.graph.erase(remove_if(GTNetwork.graph.begin(), GTNetwork.graph.end(),
		[id](const Rib& rib) { return rib.ID == id; }), GTNetwork.graph.end());
}
void network::DeletePipeWithStation(network& GTNetwork, int stationID) {
	GTNetwork.graph.erase(remove_if(GTNetwork.graph.begin(), GTNetwork.graph.end(),
		[stationID](const Rib& rib) {
			return rib.FromCS == stationID || rib.ToCS == stationID;
		}),
		GTNetwork.graph.end());

}
void network::PrintGraph(network& GTNetwork)
{
	cout << "Id of pipe{start station,end staton}" << endl;
	for (const auto& rib : GTNetwork.graph) {
		cout << rib.ID << "{" << rib.FromCS << "," << rib.ToCS << "}" << endl;
	}
}
void DFS(int CurrentNode,const network& GTNetwork, unordered_set<int>& visited) {
	visited.insert(CurrentNode);
	cout << CurrentNode << endl;
	for (const Rib& rib : GTNetwork.graph) {
		if (rib.FromCS == CurrentNode && visited.find(rib.ToCS) == visited.end()) {
			DFS(rib.ToCS, GTNetwork, visited);
		}
	}
}
void network::TopologicSort(network& GTNetwork)
{
	unordered_set<int> visited;
	for (const Rib& rib :GTNetwork.graph) {
		if (visited.find(rib.FromCS) == visited.end()) {
			DFS(rib.FromCS, GTNetwork, visited);
		}
	}

}
