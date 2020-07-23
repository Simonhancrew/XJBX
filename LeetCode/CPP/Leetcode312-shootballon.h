bool cmp(vector<int> &a,vector<int>&b){
    return a[0]<b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0){
            return 0;
        }
        std::sort(points.begin(),points.end(),cmp);
        int shoot =1;
        int shoot_begin=points[0][0];
        int shoot_end = points[0][1];
        for (int i =1;i<points.size();i++){
            if(points[i][0]<=shoot_end){
                shoot_begin = points[i][0];
                if(shoot_end>points[i][1]){
                    shoot_end = points[i][1];
                }
            }
            else{
                shoot++;
                shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
        }
        return shoot;    
    }

};