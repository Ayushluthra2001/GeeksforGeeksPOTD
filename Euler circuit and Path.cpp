class Solution {
public:
    int isEulerCircuit(int v, vector<int>adj[]){
        if (v == NULL){
            return {};
        }
        
        int circuit = 0;
        int path = 0;
        
        for (int i=0; i<v; i++){
            if (adj[i].size()%2 == 0){
                circuit++;
            }
            else{
                path++;
            }
        }
        
        if (circuit == v){
            return 2;
        }
        else if(path == 2){
             return 1;
        }
        else{
            return 0;
        }
    }
};
