Question: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#


Solution: 

bool pairCompare(const pair<pair<int, int>, int> &a,         //function to set the sorting condition
                 const pair<pair<int, int>, int> &b) {
    if (a.first.second != b.first.second) {
        return a.first.second < b.first.second;
    }
    return a.second < b.second;
}

void maxMeetings(int start[], int end[], int n) {

    vector<pair<pair<int, int>, int>> x;

    for (int i = 0; i < n; i++) x.push_back({{start[i], end[i]}, i + 1});

    sort(x.begin(), x.end(), pairCompare);
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (x[i].first.first > last) {
            cout << x[i].second << " ";
            last = x[i].first.second;
        }
    }
}