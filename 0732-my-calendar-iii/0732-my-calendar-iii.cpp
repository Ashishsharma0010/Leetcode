
class MyCalendarThree {
private:
    map<int, int> timeline;
    int maxOverlap = 0;

public:
    MyCalendarThree() {
    }

    int book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;

        int active = 0;
        maxOverlap = 0;

        for (auto& [time, change] : timeline) {
            active += change;
            maxOverlap = max(maxOverlap, active);
        }

        return maxOverlap;
    }
};
