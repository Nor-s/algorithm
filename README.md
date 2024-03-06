# algorithm

알고리즘 문제풀이
https://nsgg.tistory.com/category/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

## **풀어야 할 문제 리스트**

나무 ~
프로세서
돌 던지기

- 최소편집 문제 : LCS

sparse table리
온라인 쿼리
bakebird : 2d

- 힙

  - 부모와 자식간에 특정한 조건이 있음
  - 완전 이진 트리
  - 루트 삭제, 조회
  - 삽입
  - 버전관리: 다익스트라

- 문제 풀 때 먼저 필요한 연산 정리, 시간복잡도 계산

- 해시

  - 해시 충돌: 비둘기집

    - open addressing, chaining 으로 해결
    - open addressing: x 해쉬값이 있으면, 다음 해쉬값을 찾아 간다.
    - chaining: x 해쉬값이 있으면, 연결리스트로 연결한다.

  - 문자열 -> 27진법으로 변환 (33 , . 등)..
    - 이 때, 진법과 모듈러는 서로소인것이좋고, 소수가 좋음
    - ex) 31, 37, 29 진법 과 10억7 모듈

- 멀티 해쉬.

  - 하나의 문자열에대해 여러개의 해쉬값을 생성
    - 충돌의 경우가 적어짐

- 문자열 찾는 알고리즘: 라빈카프, 아호코라식, 롤링 해쉬 테크닉
  - 오버플로우 자체가 모듈러 연산이라고 생각해도 ㄱㅊ -> 라민카프

## dd

- 세수 합 https://www.acmicpc.net/workbook/view/8400

- n번째
- 컵라면 https://www.acmicpc.net/workbook/view/9502
