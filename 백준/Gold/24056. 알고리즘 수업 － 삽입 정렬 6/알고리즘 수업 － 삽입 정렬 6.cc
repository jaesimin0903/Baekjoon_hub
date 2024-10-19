#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

#define MAX_LEN 500000

int Arr[MAX_LEN];
int Cmp_Arr[MAX_LEN];

// 배열 비교 함수: 두 배열이 같은지 확인
bool array_compare(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;  // 배열 요소가 다르면 false 반환
        }
    }
    return true;  // 배열이 같으면 true 반환
}

int main() {
    int n;
    std::cin >> n;
    int totalN = n;

    // 배열 입력 받기
    for (int i = 0; i < n; i++)
        std::cin >> Arr[i];

    for (int i = 0; i < n; i++)
        std::cin >> Cmp_Arr[i];

    // 뒤쪽에서부터 배열이 동일한 부분은 처리하지 않기 위해 n을 줄임
    while (n > 0 && Arr[n - 1] == Cmp_Arr[n - 1])
        n--;

    int idx = 0;
    // 배열이 이미 정렬된 구간을 찾음
    while (idx + 1 < n && Cmp_Arr[idx] <= Cmp_Arr[idx + 1])
        idx++;

    // 배열이 이미 같다면
    if (array_compare(Arr, Cmp_Arr, totalN)) {
        std::cout << 1;
        return 0;
    }

    // std::sort를 이용한 정렬
    std::sort(Arr, Arr + idx); // C++의 std::sort 사용

    // 정렬 후 배열 비교
    if (array_compare(Arr, Cmp_Arr, totalN)) {
        std::cout << 1;
        return 0;
    }

    // 배열 중복 처리
    int target = -1;
    for (int i = 0; i < n - 1; i++) {
        if (Cmp_Arr[i] == Cmp_Arr[i + 1]) {
            target = i + 1;
            break;
        }
    }

    // 중복된 요소가 없으면 다시 정렬
    if (target == -1) {
        std::sort(Arr, Arr + idx + 1); // std::sort 사용
        std::cout << array_compare(Arr, Cmp_Arr, totalN);
        return 0;
    }
    // for(int i =0;i<totalN;i++) std::cout << Arr[i] << " ";
    // std::cout << "\n";
    // std::cout << "target " << target << " idx " << idx <<"\n";
    // 배열의 삽입 위치 찾아서 요소를 이동
    int tmp = Arr[idx];
    while (0 < idx && target <= idx && tmp < Arr[idx - 1]) {
        Arr[idx] = Arr[idx - 1];
        idx--;
    }
    //Arr[idx] = tmp;
    // for(int i =0;i<totalN;i++) std::cout << Arr[i] << " ";
    // std::cout << "\n";
    // 최종 배열 비교
    std::cout << array_compare(Arr, Cmp_Arr, totalN);

    return 0;
}
