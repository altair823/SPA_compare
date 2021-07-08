# Dijkstra

- bucket-heap을 통한 구현


# 미로를 어떻게 만들 것인가?

1. 랜덤 함수를 사용하여 해당 location을 방문하고 open 여부를 수정한다. 
    
    - 얼마나 많은 location을 닫을 것인가? 그리고 그것을 어떻게 논리적으로 설명할 것인가? 
    - 너무나 적은, 또는 너무나 많은 location을 close하지는 않을까?
    - 만약 반드시 하나 이상의 길을 만들으려면 어떻게 해야할까?
    
        - Eller's 알고리즘 사용
            1. 첫 번쨰 줄의 칸들을 각각 모두 다른 집합에 넣는다.
            2. 인접한 칸을 무작위로 연결한다. 이떄 연결한 칸은 같은 집합으로 묶는다. 
            3. 현재 행의 모든 집합은 아래로 내려가는 적어도 한 개의 길을 생성한다. 
            4. 밑으로 내려간 길에 해당하는 밑의 칸은 그 집합에 포함한다. 
            5. 다음 줄로 이동한다. 
            6. 마지막 줄이 아니라면, 2부터 다시 시작한다. 
            7. 다른 집합에 포함된 칸들을 모두 같은 집합으로 묶는다.
   
2. 미로의 칸은 어떻게 구조화할 것인가?
   
   - 각 칸을 열고 닫는다. 
   - 각 Location 객체에 4비트 플래그를 저장하여 4면의 열림과 닫힘을 나타낸다. 
      
      - 4 * 300 * 300 = 360000 bit = 45000 byte = 43.9 kB
      - 매번 생성할텐데, 과연 적절한 용량인가?
      - 한 벽의 열림 여부 플래그가 인접한 칸에 반드시 동기화 되어야 한다. 
   
   - 벽만을 저장한다면?
      
      - 1 * ((300 * 301) + (301 * 300)) = 2 * 90300 = 180600 bit = 22 kB
      - 위의 절반 수준이다. 
      - 계산의 복잡성을 감수할만큼 가치있는 용량 절약인가?
      - 칸 객체 자체가 존재하지 않는다. 
   
   - A* 알고리즘은 출발지와 목적지의 위치(이 경우 좌표)를 요구한다. 
     따라서 칸의 좌표를 특정하기 쉬운 1번 방법을 사용하는 것이 옳다. 
     
   