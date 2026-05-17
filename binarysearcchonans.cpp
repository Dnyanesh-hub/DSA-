#include<bits/stdc++.h>
using namespace std;
// koko eating banana problem minm interger per hour rate that will help koko
// to eat all bananas in given time

    long long calculatehours(vector<int>& piles, int hourly) {
        long long totalh = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalh += (piles[i] + (long long)hourly - 1) / hourly;
        }

        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {

            int mid = low + (high - low) / 2;
            long long totalh = calculatehours(piles, mid);

            if(totalh <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }