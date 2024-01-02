#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

/** parametric search(파라매트릭 서치) **/
// 최적화 문제를 결정 문제로 바꾸어 이분 탐색으로 해결하는 것 //
// mid 값, 즉 최장 시간을 가지는 한 blueray 후보 값들이 정렬되어 있는데
// 그 값들 중에서 맞는 것을 이분 탐색으로 찾는 것이다!!

int n, m;
vector<ll> lecture;

// https://eine.tistory.com/entry/이진-탐색-이분-탐색binary-search-구현시-고려할-것들
// * 그러니까 중간부터 하나하나 개수 늘려가며 한 칸 씩 이동하며 찾는 방법 *
// left(low): 블루레이 하나의 크기가 가장 작은 것(각 강의가 한 장마다 배치, 즉 가장 큰 element가 초기값)
// right(high): 블루레이 하나의 크기가 가장 큰 것(모든 강의가 한 장에)
int binary_search(int left, int right) {
    // [left, right] 폐구간, (left < right)로 구현
    // [left, right) 반개구간, (left + 1 < right)로 구현 -> 일반적인 STL 구현 방식
    while (left < right) {
        ll mid = (left + right) / 2;   // 현재 블루레이 길이 (임시 가정)
        ll cnt_blueray = 0, sum = 0;   // mid일 때 블루레이 수 구하기

        for (int i = 0; i < lecture.size(); ++i) {
            if (sum + lecture[i] > mid) {
                cnt_blueray++;  // 현재까지 셌던거 넘은거 찾았으니 블루레이에 담고
                sum = 0;        // 다시 더하기 위해 초기화
            }
            sum += lecture[i];  // 현재 단계 더하기
        }   // 현재 블루레이 기준으로 한 바퀴는 다 돌았다.

        // mid보다 작아서 1 증가시키지 못했을 경우
        if (sum != 0)
            cnt_blueray++;

        // mid 기준으로 한 바퀴(N) 돌았더니 해당 턴에 센 총 블루레이 개수가
        // 가진 총 블루레이 수(M)와 비교.
        // 개폐구간에 따라 mid의 위치를 세심하게 살펴보고 적용해야 한다.
        if (cnt_blueray > m)
            left = mid + 1;
        else
            right = mid;
    }

    return right;   // right = mid 로 끝나기 때문
}

int main() {
    cin >> n >> m;
    lecture.resize(n);

    ll tmp, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        lecture[i] = tmp;
        sum += tmp;
    }

    cout << binary_search(*max_element(lecture.begin(), lecture.end()), sum);
}