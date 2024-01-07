#pragma once
#include <iostream>
#include <vector>

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
	vector<vector<int>> adjMatrix ; // adjacency matrix
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

	void addEdge(int start, int end)
	{
		adjMatrix[start][end] = 1;
		adjMatrix[end][start] = 1;
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
};

class GraphAdjMatrixDirected
{
public:
	vector<vector<int>> adjMatrix; // adjacency matrix
	int noVertices;
	vector<Vertex> vertices;
	GraphAdjMatrixDirected(int num)
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

	void addEdge(int start, int end)
	{
		adjMatrix[start][end] = 1;
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
};