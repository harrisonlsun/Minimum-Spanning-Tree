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
#include "header.h"

 /**
  * PrimMatrix's Algorithm
  */

class PrimMatrix {
public:
	PrimMatrix(int numVertices, int** matrix);
	~PrimMatrix();
	void runPrimMatrix();
	void printDistance();
private:
	int numVertices;
	int** matrix;
	int* distance;
	bool* sptSet;
};

/**
 * PrimMatrix
 * @param - int numVertices - number of vertices in the graph
 * @param - int** matrix - adjacency matrix of the graph
 * @return none
 */

PrimMatrix::PrimMatrix(int numVertices, int** matrix) {
	this->numVertices = numVertices;
	this->matrix = matrix;
	distance = new int[numVertices];
	sptSet = new bool[numVertices];
}

/**
 * ~PrimMatrix
 * @param none
 * @return none
 */

PrimMatrix::~PrimMatrix() {
	delete[] distance;
	delete[] sptSet;
}

/**
 * runPrimMatrix
 * @param none
 * @return none
 *
 * This function runs PrimMatrix's Algorithm.
 */

void PrimMatrix::runPrimMatrix() {
	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < numVertices; i++) {
		distance[i] = std::numeric_limits<int>::max();
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	distance[0] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < numVertices - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in first iteration.
		int u = minDistance(numVertices, distance, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < numVertices; v++) {
			// Update distance[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of distance[v]
			if (!sptSet[v] && matrix[u][v] && distance[u] != std::numeric_limits<int>::max() && distance[u] + matrix[u][v] < distance[v]) {
				distance[v] = distance[u] + matrix[u][v];
			}
		}
	}
}

/**
 * printDistance
 * @param none
 * @return none
 *
 * This function prints the distance array.
 */

void PrimMatrix::printDistance() {
	std::cout << "The distance array" << std::endl;
	for (int i = 0; i < numVertices; i++) {
		std::cout << distance[i] << "\t";
	}
	std::cout << "\n";
}

