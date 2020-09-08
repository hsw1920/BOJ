#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cstdio>   
using namespace std;
//변수가 2개인 함수 사용
//sticker(c,status)
//c는 스티커 점수의 최대치
//status는 0이면 왼쪽열에 떼어낸 스티커 없음
//         1이면 왼쪽열 위의 스티커를 뗌
//         2이면 왼쪽열 아래 스티커를 뗌
// 최초함수는 sticker(0,0)
// 1. 위쪽 스티커를 떼는걸 선택하여 그 가치+ sticker(1, 1)
// 2. 아래쪽 스티커를 떼는 걸 선택하여 그 가치 + sticker(1,2)
// 3. 아무 스티커도 떼지 않고 sticker(1,0)
// 1,2,3 중 최댓값이 정답.
int main() {

    return 0;
}