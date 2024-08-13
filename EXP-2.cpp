#include <iostream>
#include <cstdlib>

#define INF 1000000000

struct Box {
    int weight;
    int port;
};

int minTrips(Box* boxes, int boxesSize, int portsCount, int maxBoxes, int maxWeight) {
    int* dp = (int*)malloc((boxesSize + 1) * sizeof(int));
    int* portVisited = (int*)malloc((portsCount + 1) * sizeof(int));
    int totalWeight = 0, totalBoxes = 0, trips = 0;

    for (int i = 0; i <= boxesSize; ++i) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 0; i <= portsCount; ++i) {
        portVisited[i] = 0;
    }

    int start = 0;

    for (int end = 1; end <= boxesSize; ++end) {
        totalWeight += boxes[end - 1].weight;
        totalBoxes++;
        portVisited[boxes[end - 1].port]++;

        while (totalBoxes > maxBoxes || totalWeight > maxWeight || (start < end && portVisited[boxes[start].port] > 1)) {
            totalWeight -= boxes[start].weight;
            totalBoxes--;
            portVisited[boxes[start].port]--;
            start++;
        }

        trips = dp[start] + 2;

        if (end < boxesSize && boxes[end - 1].port == boxes[end].port) {
            trips--;
        }

        dp[end] = (dp[end] < trips) ? dp[end] : trips;
    }

    int result = dp[boxesSize];

    free(dp);
    free(portVisited);

    return result;
}

int main() {
    Box boxes[] = {{1, 1}, {2, 1}, {1, 2}, {2, 2}, {3, 3}};
    int boxesSize = sizeof(boxes) / sizeof(boxes[0]);
    int portsCount = 3;
    int maxBoxes = 5;
    int maxWeight = 6;

    int result = minTrips(boxes, boxesSize, portsCount, maxBoxes, maxWeight);
    std::cout << "Minimum number of trips: " << result << std::endl;

    return 0;
}
