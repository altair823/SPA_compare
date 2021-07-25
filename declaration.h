//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_DECLARATION_H
#define SPA_COMPARE_DECLARATION_H

#define MAIN_LOOP_COUNT 20

#define MAX_ROW 200
#define MAX_COLUMN 200
#define DEFAULT_ROW 50
#define DEFAULT_COLUMN 50


#define INF 10000000  // Maximum weight of edges.
#define WEIGHT_STD_DIV 0  // Standard deviation of weight.
#define WEIGHT_MEAN 10  // Mean of weight.

#define MAX_EDGE_COUNT 4

// An estimate of the distance between one vertex and adjacent vertex used in the heuristic of the A* algorithm.
// Usually equal to the mean of the vertex weights.
#define ASTAR_DIST_WEIGHT 10

// The flags that activate each SPA searching.
#define _DIK 1
#define _DIKPQ 1
#define _ASTAR 1

#define RESULT_FILE_NAME "../time_result.txt"

#endif //SPA_COMPARE_DECLARATION_H
