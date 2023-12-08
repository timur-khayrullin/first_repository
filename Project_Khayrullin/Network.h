#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class NetworkNode;
class NetworkEdge;
unordered_map<int, NetworkNode> NetworkGraph;

class NetworkNode {
public:
	int IdOfNode;
	unordered_set<NetworkEdge> edges;
	unordered_map<int, NetworkEdge> NodeParents;

	NetworkNode(int id) : IdOfNode(id) {}

};

class NetworkEdge {
public:
	int IdOfEdge;
	NetworkNode ToNode;
	NetworkEdge(int id, NetworkNode toNode) : IdOfEdge(id), ToNode(toNode) {}
};

NetworkNode AddOrGetNode(unordered_map<int, NetworkNode>& NetworkGraph, int NodeValue) {
	for (auto& pair : NetworkGraph) {
		if (pair.first == NodeValue) {
			cout << "A node found with ID:" << NodeValue << endl;
			return pair.second;
		} 
		else {
			NetworkNode NewNode(NodeValue);
			NetworkGraph[NodeValue] = NewNode;
			return NewNode;
		}
	}

};

void AddEdge(NetworkNode& fromNode, NetworkNode& toNode, int edgeId) {
	NetworkEdge newEdge(edgeId, toNode);
	fromNode.edges.insert(newEdge);

	auto it = NetworkGraph.find(toNode.IdOfNode);
	if (it != NetworkGraph.end()) {
		toNode.NodeParents[fromNode.IdOfNode] = newEdge;
	}
}

void PrintGraph(const unordered_map<int, NetworkNode>& networkGraph) {
	for (const auto& pair : networkGraph) {
		const NetworkNode& node = pair.second;
		cout << "Node " << node.IdOfNode << ": ";

		for (const NetworkEdge& edge : node.edges) {
			cout << "(" << edge.ToNode.IdOfNode << ", " << edge.IdOfEdge << ") ";
		}

		cout << endl;
	}
}