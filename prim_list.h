/**
 * Author: Harrison Sun (sun.har@northeastern.edu)
 * EECE7205 - Professor Shelley Lin
 * Date: 2019-10-15
 * Homework 4
 * 
 * This program runs Prim's Algorithm using an adjacency list with binary heap for priority queue.
 */

#pragma once

#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>
#include <utility>
#include "header.h"

 /**
  * PrimList's Algorithm
  */

class PrimList {
public:
	PrimList(int numVertices, std::vector<std::vector<std::pair<int, int>>>* adjList);
	~PrimList();
	void runPrimList();
	void printDistance();
private:
	int numVertices;
	std::vector<std::vector<std::pair<int, int>>>* adjList;
	int* distance;
	bool* sptSet;
};

/**
 * PrimList
 * @param - int numVertices - number of vertices in the graph
 * @param - std::vector<std::vector<std::pair<int, int>>>* adjList - adjacency list of the graph
 * @return none
 */

PrimList::PrimList(int numVertices, std::vector<std::vector<std::pair<int, int>>>* adjList) {
	this->numVertices = numVertices;
	this->adjList = adjList;
	distance = new int[numVertices];
	sptSet = new bool[numVertices];
}

/**
 * ~PrimList
 * @param none
 * @return none
 */

PrimList::~PrimList() {
	delete[] distance;
	delete[] sptSet;
}

/**
 * runPrimList
 * @param none
 * @return none
 *
 * This function runs PrimList's Algorithm.
 */

void PrimList::runPrimList() {
	// Initialize all distances as infinite and sptSet[] as false
	for (int i = 0; i < numVertices; i++) {
		distance[i] = std::numeric_limits<int>::max();
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	distance[0] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < numVertices - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in first iteration.
		int u = minDistance(distance, sptSet);

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

void PrimList::printDistance() {
	std::cout << "The distance array: \n";
	for (int i = 0; i < numVertices; i++) {
		std::cout << distance[i] << "\t";
	}
	std::cout << "\n";
}
