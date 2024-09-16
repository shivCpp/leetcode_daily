class Solution {
public:

int timeToMinute(string& time)
{

int hour = stoi(time.substr(0,2));
int mint = stoi(time.substr(3,2));

return hour * 60 + mint;

}

    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for( string time : timePoints)
        {
            minutes.push_back(timeToMinute(time));
        }

        sort(minutes.begin() , minutes.end());

        int minDiff = INT_MAX;

        for(int i =1; i< minutes.size() ; i++)
        {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }

        int circularDiff = (1440 - minutes.back()) + minutes[0];
        minDiff = min(minDiff , circularDiff);

        return minDiff;

    }
};
