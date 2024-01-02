#include <iostream>
#include <chrono>
using namespace std;

int main() {
    int hh1, mm1, ss1;
    char colon;
    cin >> hh1 >> colon >> mm1 >> colon >> ss1;

    int hh2, mm2, ss2;
    cin >> hh2 >> colon >> mm2 >> colon >> ss2;

    // 시간을 chrono::system_clock::time_point으로 변환합니다.
    auto current = chrono::system_clock::from_time_t(0) +
                      chrono::hours(hh1) +
                      chrono::minutes(mm1) +
                      chrono::seconds(ss1);

    auto misson_start = chrono::system_clock::from_time_t(0) +
                      chrono::hours(hh2) +
                      chrono::minutes(mm2) +
                      chrono::seconds(ss2);

    // current가 misson_start보다 클 경우 24시간(하루)을 더해줍니다.
    if (current > misson_start)
        misson_start += chrono::hours(24);

    // 두 시간 간의 차이를 계산
    auto duration = chrono::duration_cast<chrono::seconds>(misson_start - current);
    // 시간, 분, 초로 변환
    auto hours = chrono::duration_cast<chrono::hours>(duration);
    auto minutes = chrono::duration_cast<chrono::minutes>(duration % chrono::hours(1));
    auto seconds = chrono::duration_cast<chrono::seconds>(duration % chrono::minutes(1));

    printf("%02ld:%02ld:%02lld", hours.count(), minutes.count(), seconds.count());
}