#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int chicken) {
    int answer = 0;
    int coupon = chicken;

    while (coupon >= 10)
    {
        int service = coupon / 10;
        answer += service;
        coupon %= 10;
        coupon += service;
    }

    return answer;
}