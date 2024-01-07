#pragma once
#include <vector>
#include <iostream>
#include <stack>
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
	stack<int> st;
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

	bool dfs(int vrtx)
	{
		vertices[0].isVisited = true;
		displayVertex(0);
		st.push(0);
		
		while (!st.empty())
		{
			int v = getAdjacentVertex(st.top());
			if (v == -1)
			{
				st.pop();
			}

			else
			{
				vertices[v].isVisited = true;
				displayVertex(v);
				st.push(v);
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
