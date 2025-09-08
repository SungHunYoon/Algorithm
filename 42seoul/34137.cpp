#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
struct Block { int r, s, e, c; };

int N, M, T, K;
int C[200001];

// 세그트리: 노드가 단일색이면 그 색 번호, 아니면 -1
int seg[800000];
int lazy_[800000];

// 색별 현재 열 개수, 답, 마지막 반영된 행(r-1)
ll cntColor[200001];
ll answer_[200001];
int lastRow[200001];

int build(int n, int s, int e) {
    if (s == e) return seg[n] = C[s];
    int m = (s + e) >> 1;
    int L = build(n<<1, s, m);
    int R = build(n<<1|1, m+1, e);
    seg[n] = (L == R ? L : -1);
    return seg[n];
}

inline void apply_tag(int n, int s, int e, int c){
    seg[n] = c;
    if (s != e) {
        lazy_[n<<1] = c;
        lazy_[n<<1|1] = c;
    }
}

inline void push(int n, int s, int e){
    if (!lazy_[n]) return;
    apply_tag(n, s, e, lazy_[n]);
    lazy_[n] = 0;
}

// [qs,qe] 구간의 (색, 길이) 목록 수집
void collect(int n, int s, int e, int qs, int qe, vector<pair<int,int>>& out){
    push(n, s, e);
    if (qe < s || e < qs) return;
    if (qs <= s && e <= qe && seg[n] != -1){
        out.emplace_back(seg[n], e - s + 1);
        return;
    }
    if (s == e){
        out.emplace_back(seg[n], 1);
        return;
    }
    int m = (s + e) >> 1;
    collect(n<<1, s, m, qs, qe, out);
    collect(n<<1|1, m+1, e, qs, qe, out);
}

// [qs,qe] 구간을 색 c로 할당
void assign_range(int n, int s, int e, int qs, int qe, int c){
    push(n, s, e);
    if (qe < s || e < qs) return;
    if (qs <= s && e <= qe){
        apply_tag(n, s, e, c);
        return;
    }
    int m = (s + e) >> 1;
    assign_range(n<<1, s, m, qs, qe, c);
    assign_range(n<<1|1, m+1, e, qs, qe, c);
    seg[n] = (seg[n<<1] == seg[n<<1|1] ? seg[n<<1] : -1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> T >> K;
    for (int i = 1; i <= M; ++i){
        cin >> C[i];
        cntColor[C[i]]++; // 초기 각 색의 열 개수
    }

    vector<Block> ev;
    ev.reserve(K);
    for (int i = 0; i < K; ++i){
        int r,s,e,c; cin >> r >> s >> e >> c;
        ev.push_back({r,s,e,c});
    }
    sort(ev.begin(), ev.end(), [](const Block& a, const Block& b){
        if (a.r != b.r) return a.r < b.r;
        if (a.s != b.s) return a.s < b.s;
        return a.e < b.e;
    });

    // 세그트리 초기화
    build(1, 1, M);

    // lastRow 초기값: 0행까지 반영된 걸로 간주 (첫 누적은 r-1 - 0)
    // 이미 cntColor는 설정되어 있으니, 이벤트마다 "변하는 색"만 즉시누적
    int idx = 0;
    while (idx < (int)ev.size()){
        int r = ev[idx].r;

        // 같은 r에서 여러 구간이 있을 수 있으므로 묶어서 처리
        // 각 (s,e,c)에 대해, 먼저 현재 구간의 색 분포를 수집하고
        // 색별 answer 즉시누적 + cntColor 감소 → 새 색 c에 대해 즉시누적 + cntColor 증가 → 세그트리 할당
        while (idx < (int)ev.size() && ev[idx].r == r){
            int s = ev[idx].s, e = ev[idx].e, c = ev[idx].c;

            // 1) [s,e]에 현재 칠해져 있는 색들의 분포 수집
            vector<pair<int,int>> parts;
            parts.reserve(32);
            collect(1, 1, M, s, e, parts);

            // 2) 기존 색들에 대해 r-1 시점까지 면적 즉시 누적 + 카운트 감소
            for (auto &p : parts){
                int col = p.first;
                int len = p.second;
                if (col <= 0) continue; // 안전
                // col의 기존 기여를 r-1까지 마감
                if (cntColor[col] > 0) {
                    answer_[col] += 1LL * (r - 1 - lastRow[col]) * cntColor[col];
                    lastRow[col] = r - 1;
                }
                cntColor[col] -= len;
            }

            // 3) 새 색 c에 대해 r-1까지 즉시 누적 + 카운트 증가
            answer_[c] += 1LL * (r - 1 - lastRow[c]) * cntColor[c];
            lastRow[c] = r - 1;
            cntColor[c] += (e - s + 1);

            // 4) 실제 색을 [s,e]에 반영
            assign_range(1, 1, M, s, e, c);

            ++idx;
        }
    }

    // 모든 이벤트 처리 후, 남은 구간을 N행까지 마감
    for (int col = 1; col <= T; ++col){
        if (cntColor[col] > 0){
            answer_[col] += 1LL * (N - lastRow[col]) * cntColor[col];
            lastRow[col] = N;
        }
    }

    for (int col = 1; col <= T; ++col){
        cout << answer_[col] << (col == T ? '\n' : ' ');
    }
    return 0;
}