#pragma once

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
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
	return matrix;
}

/**
 * minDistance
 * @param - int numVertices - number of vertices in the graph
 * @param - int* distance - array of distances
 * @param - bool* sptSet - array of vertices that are in the shortest path tree
 * @return - int - index of the vertex with the minimum distance
 *
 * This function finds the vertex with the minimum distance.
 */

int minDistance(int numVertices, int* distance, bool* sptSet) {
	// Initialize min value
	int min = std::numeric_limits<int>::max();
	int min_index;

	for (int v = 0; v < numVertices; v++) {
		if (sptSet[v] == false && distance[v] <= min) {
			min = distance[v];
			min_index = v;
		}
	}

	return min_index;
}