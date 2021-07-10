# SPA_compare

---

최단 경로 탐색 알고리즘(Shortest Path Algorithm, SPA)들을 비교하는 프로젝트입니다.
그래프는 미로를 기반으로 구현하였습니다.

특정 셀에서 상하좌우 네 개의 다른 셀로 가는 길이 존재합니다. 평범한 미로에서는 이 길을 벽으로 막음으로써 미로를 구현합니다. 
하지만 가중치가 없는 단순한 막힌 벽과 열린 길만을 구현한다면 다익스트라 알고리즘의 성능이 낮아지게 됩니다. 
따라서 열린 길마다 다양한 무작위적인 가중치를 부여하여 간선으로서의 역할을 할 수 있도록 하였습니다. 

다음을 바탕으로 합니다. 

[The Buckblog, Maze Generation: Eller's Algorithm](http://weblog.jamisbuck.org/2010/12/29/maze-generation-eller-s-algorithm)

[Finding shortest paths on real road networks: the case for A*
/ by Zeng, W.; Church, R. L.](https://zenodo.org/record/979689#.YOS3kRMza3I)

[SHORTEST PATHS ALGORITHMS: THEORY AND EXPERIMENTAL EVALUATION](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.54.8746&rep=rep1&type=pdf)


## 구현한 알고리즘 목록

- Eller's 알고리즘 (미로 생성 알고리즘)

## 구현할 알고리즘 목록

- 다익스트라 알고리즘
- A* 알고리즘


