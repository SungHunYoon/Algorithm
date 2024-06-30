#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[2][101];
int R[2][101];
int robotNum = 1;

bool checkBelt() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[0][i] == 0)
            cnt++;
        if (A[1][i] == 0)
            cnt++;
        if (cnt >= K)
            return true;
    }
    return false;
}

void printArray() {
    cout << "--------------\n";
    for (int i = 0; i < N; i++)
        cout << A[0][i] << ' ';
    cout << '\n';
    for (int i = 0; i < N; i++)
        cout << A[1][i] << ' ';
    cout << '\n';
}

void printRobot() {
    cout << "===============\n";
    for (int i = 0; i < N; i++)
        cout << R[0][i] << ' ';
    cout << '\n';
    for (int i = 0; i < N; i++)
        cout << R[1][i] << ' ';
    cout << '\n';
}

void rotateBelt() {
    rotate(A[0], (A[0] + N) - 1, A[0] + N);
    rotate(A[1], A[1] + 1, A[1] + N);
    swap(A[0][0], A[1][N - 1]);
    rotate(R[0], R[0] + N - 1, R[0] + N);
    rotate(R[1], R[1] + 1, R[1] + N);
    swap(R[0][0], R[1][N - 1]);
    if (R[0][N - 1] != 0)
        R[0][N - 1] = 0;
}

int findMinRobot() {
    int robot = 1e9;
    for (int i = 0; i < N; i++) {
        if (R[0][i] > 0)
            robot = min(robot, R[0][i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        if (R[1][i] > 0)
            robot = min(robot, R[1][i]);
    }
    return robot;
}

void findRobotProcess(int idx, int num) {
    for (int i = 0; i < N; i++) {
        if (R[idx][i] == num) {
            int pos = -1;
            if (idx == 0 && i + 1 < N)
                pos = i + 1;
            if (idx == 1 && i - 1 > 0)
                pos = i - 1;
            if (pos != -1 && A[idx][pos] > 0 && R[idx][pos] == 0) {
                R[idx][pos] = R[idx][i];
                R[idx][i] = 0;
                A[idx][pos]--; 
            }
            return;
        }
    }
}

void moveRobot() {
    int num = findMinRobot();
    while (num < robotNum) {
        findRobotProcess(0, num);
        findRobotProcess(1, num);
        if (R[0][N - 1] != 0)
            R[0][N - 1] = 0;
        num++;
    }
}

void loadRobot() {
    if (A[0][0] > 0) {
        R[0][0] = robotNum++;
        A[0][0]--;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[0][i];
    for (int i = N - 1; i >= 0; i--)
        cin >> A[1][i];
    int answer = 1;
    while (1) {
        rotateBelt();
        moveRobot();
        loadRobot();
        printArray();
        printRobot();
        if (checkBelt())
            break;
        answer++;
    }
    cout << answer << '\n';
    return 0;
}