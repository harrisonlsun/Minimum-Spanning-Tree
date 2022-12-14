/**
 * Author: Harrison Sun (sun.har@northeastern.edu)
 * EECE7205 - Professor Shelley Lin
 * Date: 2019-10-15
 * Homework 4
 *
 * This program runs Prim's Algorithm using an adjacency matrix with unsorted array for priority queue.
 */

#pragma once

#include <iostream>
#include <limits>
#include <stdio.h>

/**
 * generateMatrix
 * @param - int numVertices - the number of vertices in the graph
 * @param - int numEdges - the number of edges in the graph
 * @param - int maxWeight - the maximum weight of an edge in the graph
 * 
 * This function generates a random adjacency matrix for a graph with numVertices vertices and numEdges edges. The maximum weight of an edge is maxWeight.
 */

int** generateMatrix(int numVertices, int numEdges, int maxWeight) {
	int** matrix = new int* [numVertices];
	for (int i = 0; i < numVertices; i++) {
		matrix[i] = new int[numVertices];
	}
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			matrix[i][j] = 0;
		}
	}
	int numEdgesAdded = 0;
	while (numEdgesAdded < numEdges) {
		int i = rand() % numVertices;
		int j = rand() % numVertices;
		if (i != j && matrix[i][j] == 0) {
			matrix[i][j] = rand() % maxWeight + 1;
			matrix[j][i] = matrix[i][j];
			numEdgesAdded++;
		}
	}
	/** Print the generated matrix. */
	std::cout << "The generated matrix: \n";
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	return matrix;
}

class PrimMatrix {
public:
	PrimMatrix(int numVertices, int** matrix);
	~PrimMatrix();
	void runPrim();
	void printMST();
private:
	int numVertices;
	int** matrix;
	int* parent;
	int* key;
	bool* mstSet;
};

/**
 * PrimMatrix
 * @param - int numVertices - number of vertices in the graph
 * @param - int** matrix - adjacency matrix of the graph
 * @return none
 * 
 * This is the constructor for PrimMatrix. It initializes the class variables.
 */

PrimMatrix::PrimMatrix(int numVertices, int** matrix) {
	this->numVertices = numVertices;
	this->matrix = matrix;
	parent = new int[numVertices];
	key = new int[numVertices];
	mstSet = new bool[numVertices];
}

/**
 * ~PrimMatrix
 * @param none
 * @return none
 * 
 * This is the destructor. It frees up memory by deleting parent, key, and mstSet.
 */

PrimMatrix::~PrimMatrix() {
	delete[] parent;
	delete[] key;
	delete[] mstSet;
}

/**
 * runPrim()
 * @param none
 * @return void
 *
 * This function runs Prim's Algorithm using an adjacency matrix with unsorted array for priority queue.
 */

void PrimMatrix::runPrim() {
	for (int i = 0; i < numVertices; i++) {
		key[i] = std::numeric_limits<int>::max();
		mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < numVertices - 1; count++) {
		int min = std::numeric_limits<int>::max();
		int minIndex;
		for (int v = 0; v < numVertices; v++) {
			if (mstSet[v] == false && key[v] < min) {
				min = key[v];
				minIndex = v;
			}
		}
		mstSet[minIndex] = true;
		for (int v = 0; v < numVertices; v++) {
			if (matrix[minIndex][v] && mstSet[v] == false && matrix[minIndex][v] < key[v]) {
				parent[v] = minIndex;
				key[v] = matrix[minIndex][v];
			}
		}
	}
}

/**
 * printMST()
 * @param none
 * @return void
 * 
 * This function prints the MST.
 */

void PrimMatrix::printMST() {
	// print the minimum spanning tree
	printf("Edge \tWeight");
	for (int i = 1; i < numVertices; i++) {
		printf("%d - %d \t%d \n", parent[i], i, matrix[i][parent[i]]);
	}
}

