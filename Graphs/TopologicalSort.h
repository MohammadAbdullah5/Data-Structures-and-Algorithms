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

class GraphAdjMatrixDirected
{
public:
	vector<vector<int>> adjMatrix; // adjacency matrix
	int noVertices;
	vector<Vertex> vertices;
	vector<char> sortedArray;

	GraphAdjMatrixDirected(int num)
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

	void topoSort()
	{
		int orignVerts = noVertices; // remember how many verts
		while (noVertices > 0) // while vertices remain,
		{
			// get a vertex with no successors, or -1
			int currentVertex = noSuccessor();
			if (currentVertex == -1) // must be a cycle
			{
				return;
			}
			// insert vertex label in sorted array (start at end)
			sortedArray[noVertices - 1] = vertices[currentVertex].label;
			deleteVertex(currentVertex); // delete verte
		}
	}

	int noSuccessor()
	{
		bool isEdge;

		for (int i = 0; i < noVertices; i++) // for every vertex
		{
			isEdge = false;
			for (int j = 0; j < noVertices; j++) 
			{
				if (adjMatrix[i][j] > 0) // if edge to another
				{
					isEdge = true;
					break; // break inner loop
				}
			}

			if (isEdge == false) // if no edges
			{
				return i; // means no successor and return row
			}
		}
		return -1; // no such vertex
	}

	void deleteVertex(int delVert)
	{
		if (delVert != noVertices - 1) // if not last vertex,
		{
			for (int j = delVert; j < noVertices - 1; j++) // delete row from vertices
			{
				vertices[j] = vertices[j + 1]; 
			}
			
			for (int row = delVert; row < noVertices - 1; row++) // delete row from adjMat
			{
				moveRowUp(row, noVertices);
			}
			
			for (int col = delVert; col < noVertices - 1; col++) // delete col from adjMat
				moveColLeft(col, noVertices - 1);
		}
		noVertices--; 
	}

	void moveRowUp(int row, int length)
	{
		for (int col = 0; col < length; col++)
		{
			adjMatrix[row][col] = adjMatrix[row + 1][col];
		}
	}

	void moveColLeft(int col, int length)
	{
		for (int row = 0; row < length; row++)
		{
			adjMatrix[row][col] = adjMatrix[row][col + 1];
		}
	}
};