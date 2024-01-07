#pragma once
#include <iostream>
#include <vector>
#include <list>
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

class GraphAdjMatrixUndirected
{
public:
	vector<vector<int>> adjMatrix; // adjacency matrix
	int noVertices;
	vector<Vertex> vertices;
	GraphAdjMatrixUndirected()
	{
		noVertices = 0;
	}

	void addVertex(char data)
	{
		noVertices++;
		Vertex newVertex(data);
		vertices.push_back(newVertex);
		adjMatrix.push_back(vector<int>());
		for (int i = 0; i < noVertices; i++)
		{
			adjMatrix[i].push_back(0);
		}
	}

	void addEdge(char start, char end, int weight)
	{
		int startVertex = getVertex(start);
		int endVertex = getVertex(end);
		if (startVertex != -1 && endVertex != -1)
		{
			adjMatrix[startVertex][endVertex] = weight;
			adjMatrix[endVertex][startVertex] = weight;
		}
	}

	void displayVertex(int v)
	{
		cout << vertices[v].label << endl;
	}

	void display() const {
		for (const auto& row : adjMatrix) {
			for (int value : row) {
				std::cout << value << ' ';
			}
			std::cout << std::endl;
		}
	}

private:
	int getVertex(char lbl)
	{
		int size = vertices.size();
		for (int i = 0; i < size; ++i) 
		{
			if (vertices[i].label == lbl)
			{
				return i;
			}
		}
		return -1;
	}
};

class GraphAdjMatrixDirected
{
public:
	vector<vector<int>> adjMatrix; // adjacency matrix
	int noVertices;
	vector<Vertex> vertices;
	GraphAdjMatrixDirected()
	{
		noVertices = 0;
	}

	void addVertex(char data)
	{
		noVertices++;
		Vertex newVertex(data);
		vertices.push_back(newVertex);
		adjMatrix.push_back(vector<int>());
		for (int i = 0; i < noVertices; i++)
		{
			adjMatrix[i].push_back(0);
		}
	}

	void addEdge(char start, char end, int weight)
	{
		int startVertex = getVertex(start);
		int endVertex = getVertex(end);
		if (startVertex != -1 && endVertex != -1)
		{
			adjMatrix[startVertex][endVertex] = weight;
		}
	}

	void displayVertex(int v)
	{
		cout << vertices[v].label << endl;
	}

	void display() const {
		for (const auto& row : adjMatrix) {
			for (int value : row) {
				std::cout << value << ' ';
			}
			std::cout << std::endl;
		}
	}

private:
	int getVertex(char lbl)
	{
		int size = vertices.size();
		for (int i = 0; i < size; ++i)
		{
			if (vertices[i].label == lbl)
			{
				return i;
			}
		}
		return -1;
	}
};

class GraphAdjListUnirected
{
	vector<list<pair<int, int>>> adjList; // vector of list of pairs. pairs will be neighbour vertex & weight
	vector<Vertex> vertices;
	int numVertices;
public:
	GraphAdjListUndirected()
	{
		numVertices = 0;
	}

	void addVertex(char data)
	{
		numVertices++;
		Vertex newVertex(data);
		vertices.push_back(newVertex);
		adjList.push_back(list<pair<int, int>>());
	}

	void addEdge(char start, char end, int weight)
	{
		int startIdx = getVertex(start);
		int endIdx = getVertex(end);

		if (startIdx != -1 && endIdx != -1)
		{
			adjList[start].push_back(make_pair(end, weight)); // pushes a pair of end and weight to at start index of vector
			adjList[end].push_back(make_pair(start, weight)); // pushes a pair of start and weight to at end index of vector
		}
	}

private:
	int getVertex(char lbl)
	{
		int size = vertices.size();
		for (int i = 0; i < size; ++i)
		{
			if (vertices[i].label == lbl)
			{
				return i;
			}
		}
		return -1;
	}
};

class GraphAdjListDirected
{
	vector<list<pair<int, int>>> adjList; // vector of list of pairs. pairs will be neighbour vertex & weight
	vector<Vertex> vertices;
	int numVertices;
public:
	GraphAdjListDirected()
	{
		numVertices = 0;
	}

	void addVertex(char data)
	{
		numVertices++;
		Vertex newVertex(data);
		vertices.push_back(newVertex);
		adjList.push_back(list<pair<int, int>>());
	}

	void addEdge(char start, char end, int weight)
	{
		int startIdx = getVertex(start);
		int endIdx = getVertex(end);

		if (startIdx != -1 && endIdx != -1)
		{
			adjList[start].push_back(make_pair(end, weight)); // pushes a pair of end and weight to at start index of vector}
		}
	}

private:
	int getVertex(char lbl)
	{
		int size = vertices.size();
		for (int i = 0; i < size; ++i)
		{
			if (vertices[i].label == lbl)
			{
				return i;
			}
		}
		return -1;
	}
};