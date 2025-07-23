# [Gold IV] Security Guards - 16346 

[문제 링크](https://www.acmicpc.net/problem/16346) 

### 성능 요약

메모리: 138552 KB, 시간: 1784 ms

### 분류

너비 우선 탐색, 이분 탐색, 그래프 이론, 그래프 탐색, 누적 합

### 제출 일자

2025년 7월 23일 10:26:56

### 문제 설명

<p>In the course of the last few weeks, Binary Casino has been afflicted by a local crime wave which is primarily focused on casinos in the neighborhood. Although there are surveillance cameras installed in Binary Casino, thieves usually manage to sneak out with relative ease as there is almost nobody patrolling in the casino.</p>

<p>After the theft of all Friday’s earnings, the manager of Binary Casino has lost his patience and decided to reinforce security of the casino by hiring a vast number of security guards. However, nobody in the casino was capable of coming up with a plan on how to distribute guards across the whole casino to maximize security. Security guards are thus scaterred across the casino in no systematic way. Fortunately, their locations can be described by integer coordinates in a 2D plane.</p>

<p>Because of the uneven distribution of security guards, in case of a reported robbery it is very hard for security supervisors to determine which guard is closest to the location of the incident. The task is even harder due to the constrained space in the casino which consists of endless aisles of slot machines. This limitation forces each guard to travel from one location to another in a sequence of steps. In each step, he/she can change each of his/her coordinates by 1, 0 or −1. The distance between two locations is equal to the minimum number of steps the guard has to do to get from one location to the other one.</p>

<p>The task is, for a given locations of guards and a set of locations of security incidents, to compute for each incident its smallest distance to any of the guards. This will allow security supervisors to alert appropriate guards and will greatly increase the casino security.</p>

### 입력 

 <p>The first line of input contains two integers N and Q (1 ≤ N,Q ≤ 3 · 10<sup>5</sup>), the number of guards and the number of security incidents, respectively. After that, N lines follow. Each of these lines contains two integers X and Y (0 ≤ X, Y ≤ 5000) which describe coordinates of a guard in a 2D plane. Next, Q lines follow. Each of these lines contains two integers A and B (0 ≤ A, B ≤ 5000) which describe coordinates of a security incident.</p>

### 출력 

 <p>For each of Q security incidents output a line containing shortest distance to any of the security guards, measured in steps.</p>

