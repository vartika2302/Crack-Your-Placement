class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(),people.end());
        
        int noOfBoats=0;
        
        int i=0;
        int j=n-1;
        
        // Intuition - The heaviest person if can't be paired with the lightest person, then can't be paired
        // with anyone else. He/She have to take seperate boat;
        while(i<=j) {
            if(people[i]+people[j]<=limit) {
                noOfBoats++;
                i++;
                j--;
            }
            else {
                noOfBoats++;
                j--;
            }
        }
        return noOfBoats;
    }
};