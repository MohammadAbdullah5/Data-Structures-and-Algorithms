#pragma once
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Vertex
{

public:
	bool isVisited;
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
	vector<vector<int>> adjMatrix; // adjacency matrix
	int noVertices;
	vector<Vertex> vertices;
	queue<int> q;
	GraphAdjListUndirected(int num)
	{
		noVertices = num;
		adjMatrix.resize(num); // setting the size of rows matrix
		for (int i = 0; i < num; i++)
		{
			adjMatrix[i].resize(num);  // setting the size of columns of every row of matrix
		}

		for (int i = 0; i < num; i++) // setting value of every edge to 0
		{
			for (int j = 0; j < num; j++)
			{
				adjMatrix[i][j] = 0;
			}
		}
	}

	void addVertex(char data)
	{
		noVertices++;
		Vertex newVertex(data);
		vertices.push_back(newVertex);
		adjMatrix.resize(noVertices);
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

	bool bfs(int vrtx)
	{
		vertices[0].isVisited = true;
		displayVertex(0);
		q.push(0);
		int v2;
		while (!q.empty())
		{
			int v1 = q.front();
			q.pop();
			while ((v2 = getAdjacentVertex(v1)) != -1)
			{ // get one,
				vertices[v2].isVisited = true; // mark it
				displayVertex(v2); // display it
				q.push(v2); // insert it
			}
		}
		for (int j = 0; j < noVertices; j++) // reset flags
		{
			vertices[j].isVisited = false;
		}
	}

	int getAdjacentVertex(int v)
	{
		for (int j = 0; j < noVertices; j++)
		{
			if (adjMatrix[v][j] == 1 && vertices[j].isVisited == false)
			{
				return j;
			}
		}
		return -1;
	}
};
