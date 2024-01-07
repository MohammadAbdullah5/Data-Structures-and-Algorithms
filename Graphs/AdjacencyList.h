#pragma once
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class Vertex
{
	bool isVisited;

public:
	char label;
	Vertex(char lb)
	{
		label = lb;
		isVisited = false;
	}
};

class GraphAdjListUndirected
{
public:
	unordered_map<Vertex, list<Vertex>> adjList; // unorder map is used with key as vertex and 
	list<Vertex> vertices;	// list of vertices					 // value as list of vertex
	GraphAdjListUndirected()
	{
	}

	void addVertex(char data) // if vertex is not there then create a list for that vertex as key
	{
		Vertex vrtx(data);
		vertices.push_back(vrtx);
		if (adjList.find(vrtx) == adjList.end())
		{
			adjList[vrtx] = list<Vertex>();
		}
	}

	void addEdge(Vertex start, Vertex end) // since it is undirected, both sides will be pushed with each other as vertex
	{
		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	void display() {
		// Display the adjacency list
		for (const auto& pair : adjList) {
			cout << "Vertex " << pair.first.label << ": ";
			for (const Vertex& neighbor : pair.second) {
				std::cout << neighbor.label << " ";
			}
			std::cout << std::endl;
		}
	}
};


class GraphAdjListDirected
{
public:
	unordered_map<Vertex, list<Vertex>> adjList; // unorder map is used with key as vertex and 
	list<Vertex> vertices;	// list of vertices					 // value as list of vertex
	GraphAdjListDirected()
	{
	}

	void addVertex(char data)
	{
		Vertex vrtx(data);
		vertices.push_back(vrtx);
		if (adjList.find(vrtx) == adjList.end())
		{
			adjList[vrtx] = list<Vertex>();
		}
	}

	void addEdge(Vertex start, Vertex end)
	{
		adjList[start].push_back(end);
	}

	void display() {
		// Display the adjacency list
		for (const auto& pair : adjList) {
			cout << "Vertex " << pair.first.label << ": ";
			for (const Vertex& neighbor : pair.second) {
				std::cout << neighbor.label << " ";
			}
			std::cout << std::endl;
		}
	}
};