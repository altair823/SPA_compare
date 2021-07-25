# SPA_compare

---

최단 경로 탐색 알고리즘(Shortest Path Algorithm, SPA)들을 비교하는 프로젝트입니다.
그래프는 미로를 기반으로 구현하였습니다.

특정 셀에서 상하좌우 네 개의 다른 셀로 가는 길이 존재합니다. 평범한 미로에서는 이 길을 벽으로 막음으로써 미로를 구현합니다. 
하지만 가중치가 없는 단순한 막힌 벽과 열린 길만을 구현한다면 다익스트라 알고리즘의 성능이 낮아지게 됩니다. 
따라서 열린 길마다 다양한 무작위적인 가중치를 부여하여 간선으로서의 역할을 할 수 있도록 하였습니다. 

A* 알고리즘의 경우 미로 통로에 가중치가 일정하지 않을 경우 (어느 정도 범위 이내지만) 최단 경로가 아닌 경로로 도달하는 
경우가 있으며 무작위적으로 변화하는 가중치 때문에 휴리스틱 함수가 목적지까지의 거리를 과대평가하기 때문이라고 예상됩니다.   
정규분포를 보이는 무작위적인 가중치를 부여할 수 있게 구현은 하였으나, A* 알고리즘의 올바른 작동을 위해
표준편자의 초기값을 0으로 설정하여 미로의 통로 가중치를 모두 일정하게 만들었습니다. 

만약 필요하다면 표준편차 값을 임의로 변경할 수 있습니다. 


## 구현한 알고리즘 목록

- Eller's 알고리즘 (미로 생성 알고리즘)
- 리스트를 사용하는 느린 다익스트라 알고리즘
- 우선순위 큐를 사용하는 다익스트라 알고리즘
- A* 알고리즘


## 참고

[The Buckblog, Maze Generation: Eller's Algorithm](http://weblog.jamisbuck.org/2010/12/29/maze-generation-eller-s-algorithm)

[Finding shortest paths on real road networks: the case for A*
/ by Zeng, W.; Church, R. L.](https://zenodo.org/record/979689#.YOS3kRMza3I)

[SHORTEST PATHS ALGORITHMS: THEORY AND EXPERIMENTAL EVALUATION](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.54.8746&rep=rep1&type=pdf)

