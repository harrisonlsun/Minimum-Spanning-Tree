/**
 * Author: Harrison Sun (sun.har@northeastern.edu)
 * EECE7205 - Professor Shelley Lin
 * Date: 2019-10-15
 * Homework 4
 *
 * This program runs Bellman-Ford Algorithm.
 */

#pragma once

#include <iostream>
#include <limits>
#include <stdio.h>
#include "header.h"

/**
 * Bellman-Ford Algorithm
 */

class BellmanFord {
public:
	BellmanFord(int numVertices, int** matrix);
};

/**
 * Constructor for Bellman-Ford Algorithm.
 */

BellmanFord::BellmanFord(int numVertices, int** matrix) {
	/** Initialize the distance array. */
	int* distance = new int[numVertices];
	for (int i = 0; i < numVertices; i++) {
		distance[i] = std::numeric_limits<int>::max();
	}
	distance[0] = 0;
	/** Run Bellman-Ford Algorithm. */
	for (int i = 0; i < numVertices - 1; i++) {
		for (int j = 0; j < numVertices; j++) {
			for (int k = 0; k < numVertices; k++) {
				if (matrix[j][k] != 0) {
					if (distance[j] + matrix[j][k] < distance[k]) {
						distance[k] = distance[j] + matrix[j][k];
					}
				}
			}
		}
	}
	/** Print the distance array. */
	std::cout << "The distance array: \n";
	for (int i = 0; i < numVertices; i++) {
		std::cout << distance[i] << "\t";
	}
	std::cout << "\n";
}
