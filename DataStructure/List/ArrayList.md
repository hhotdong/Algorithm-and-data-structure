# Array list

| 구분     | 시간복잡도 |
| :---:   | :------: |
| 조회     | O(1)     |
| 추가     | O(n)     | 
| 삭제     | O(n)     |

## 장점

- 데이터 조회 비용이 적다.[^arraylist_advantage_1]

## 단점

- 배열의 크기를 미리 설정해야 하므로 리스트 크기가 고정된다.[^arraylist_disadvantage_1]
- 데이터 추가/삭제 시 데이터 복사가 빈번히 발생하므로 비용이 크다.[^arraylist_disadvantage_2] 

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [isaaccomputerscience][reference_link_1]

[reference_link_1]: <https://isaaccomputerscience.org/concepts/dsa_datastruct_list?examBoard=all&stage=all>

[^arraylist_advantage_1]: 데이터가 메모리 상에 연속해서 위치하기에 인덱스 중앙값을 찾기 쉽고 이에 따라 효율적인 알고리즘(이진탐색, 합병정렬 등)을 수행할 수 있다.
[^arraylist_disadvantage_1]: 즉, 리스트가 가득 찬 경우 더 이상 데이터를 추가할 수 없다. 그리고 리스트가 가득 찬 경우를 제외하고는 항상 메모리 낭비가 발생한다.
[^arraylist_disadvantage_2]: 배열의 앞에서부터 데이터를 채우는 것이 원칙이므로 데이터 삭제 시 삭제된 데이터 보다 뒤에 위치한 데이터들을 앞으로 한 칸씩 이동시켜야 한다. 마찬가지로 데이터 추가 시 추가한 데이터 뒤에 위치한 데이터들을 뒤로 한 칸씩 이동시켜야 한다.
