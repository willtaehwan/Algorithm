# [Silver I] Zeroes and Ones - 13036 

[문제 링크](https://www.acmicpc.net/problem/13036) 

### 성능 요약

메모리: 2392 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 8월 4일 09:22:54

### 문제 설명

<p>Peter hasn't submitted his homework for today's Computer Science lesson, so he is punished and given an additional task. The teacher has written two strings of the same length at the blackboard and asks Peter to make them equal using operations of only one type: take two adjacent characters of one of the strings and invert them both. Inversion transforms 0 to 1 and 1 to 0.</p>

<p>To make the problem even harder, Peter must use the minimal number of inversion operations.</p>

<p>Help Peter to complete his difficult task.</p>

<p>For example, if the two strings were "0101" and "1111" one way to make them equal is to invert two characters in the middle of the first string to get "0011" and "1111" and then invert two first characters of the second string to get "0011" and "0011". Note that there are other ways to complete the task with two operations in this example.</p>

### 입력 

 <p>Input data contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 100).</p>

<p>Each test case is described in the following way. The first line contains n (1 ≤ n ≤ 10<sup>5</sup>) — the length of the strings written by the teacher. The second and the third lines contain the strings themselves — two strings of length n containing only 0-s and 1-s.</p>

<p>The sum of values of n for all test cases in one input data doesn't exceed 10<sup>5</sup>.</p>

### 출력 

 <p>For each test case print one line: the minimal required number of inversion operations to make the strings equal, or - 1 if it is impossible to make the strings equal.</p>

<p> </p>

