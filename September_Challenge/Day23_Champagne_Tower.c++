class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        std::vector<double> currentLevel(1, poured);
        
       
        for (int row = 0; row < query_row; row++) {
            
            std::vector<double> nextLevel(row + 2, 0.0);
            
            
            for (int glass = 0; glass < currentLevel.size(); glass++) {
              
                double overflow = (currentLevel[glass] - 1.0) / 2.0;
                if (overflow > 0.0) {
                    nextLevel[glass] += overflow;
                    nextLevel[glass + 1] += overflow;
                }
            }
            
           
            currentLevel = nextLevel;
        }
        
        
        return std::min(1.0, currentLevel[query_glass]);
    }
};
