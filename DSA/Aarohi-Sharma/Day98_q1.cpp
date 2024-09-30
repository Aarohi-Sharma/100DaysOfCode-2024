class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int , int> m;
        for(int i = 0;i<answers.size();i++)
        {
            m[answers[i]]++;
        }
        int count = 0;
        for(auto p :m)
        {
            if(p.first == 0) count = count + p.second;
            else if(p.second > (p.first + 1))
            {
                int pairs = p.second/(p.first + 1);
                int solo = p.second %(p.first +1);
                if(solo <= p.first +1 && solo != 0) solo = 1;
                count = count + ( p.first +1 )*(pairs + solo);
            }
            else count = count + (p.first +1);
        }
        return count;
    }
};
