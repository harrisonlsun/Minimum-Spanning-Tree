/**
 * Author: Harrison Sun (sun.har@northeastern.edu)
 * EECE7205 - Professor Shelley Lin
 * Date: 2019-10-15
 * Homework 4
 *
 * This program runs Djikstra's Algorithm using an adjacency matrix with unsorted array for priority queue.
 */

#pragma once

#include <iostream>
#include <limits>
#include <stdio.h>
#include "header.h"

class Dijkstra {
public:
	Dijkstra(int numVertices, int** matrix);
	~Dijkstra();
	void runDjikstra();
	void printDistance();
private:
	int numVertices;
	int** matrix;
	int* distance;
	bool* sptSet;
};

/**
 * Dijkstra
 * @param - int numVertices - number of vertices in the graph
 * @param - int** matrix - adjacency matrix of the graph
 * @return none
 *
 * This is the constructor for Dijkstra. It initializes the class variables.
 */

Dijkstra::Dijkstra(int numVertices, int** matrix) {
	this->numVertices = numVertices;
	this->matrix = matrix;
	distance = new int[numVertices];
	sptSet = new bool[numVertices];
}

/**
 * ~Dijkstra
 * @param none
 * @return none
 *
 * This is the destructor. It frees up memory by deleting distance and sptSet.
 */

Dijkstra::~Dijkstra() {
	delete[] distance;
	delete[] sptSet;
}

/**
 * runDjikstra
 * @param none
 * @return none
 *
 * This function runs Djikstra's Algorithm.
 */

void Dijkstra::runDjikstra() {
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

void Dijkstra::printDistance() {
	std::cout << "The distance array:" << std::endl;
	for (int i = 0; i < numVertices; i++) {
		std::cout << distance[i] << "\t";
	}
	std::cout << std::endl;
}


