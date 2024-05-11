class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
       //Approach 1:using brute force  (gives TLE)
        // int n = quality.size();
       
        // double result = DBL_MAX;
       
        // for (int manager = 0; manager < n; manager++) {
           
        //     double managerRatio = (double)wage[manager] / quality[manager];
           
        //     vector<double> group;
           
        //     for (int worker = 0; worker < n;worker++) {
        //         double worker_wage = quality[worker] * managerRatio;
        //         if (worker_wage >=  wage[worker] ) {
        //             group.push_back(worker_wage);
        //         }
        //     }

        //     if (group.size() < k )  {
        //         continue;
        //     }
            
        //     //max heap
        //     priority_queue<double, vector<double>> pq;
        //     double sumWage = 0;
        //     for ( double &wage: group) {
        //         sumWage += wage;
        //         pq.push(wage);

        //         if (pq.size() > k) {
        //             sumWage -= pq.top();
        //             pq.pop();
        //         }
        //     }
        //     result = min(result,sumWage);

        // }
        // return result;

        //Approch 2 : better (TLE)

        // int n = quality.size();
       
        // double result = DBL_MAX;

        // vector<pair<double,int>> worker_ratio(n);
        // for (int worker = 0; worker < n;worker++) {
        //     worker_ratio[worker] = make_pair((double)wage[worker]/quality[worker],quality[worker]);
        // }
       
        // sort (begin(worker_ratio),end(worker_ratio)); 


        // for (int manager = k-1; manager < n; manager++) {
           
        //     double managerRatio = worker_ratio[manager].first;

           
        //     vector<double> group;
           
        //     for (int worker = 0; worker <= manager; worker++) {
                
        //         double worker_wage = worker_ratio[worker].second * managerRatio;
        //         group.push_back(worker_wage);
                
        //     }
    
        //     //max heap
        //     priority_queue<double, vector<double>> pq;
        //     double sumWage = 0;
        //     for ( double &wage: group) {
        //         sumWage += wage;
        //         pq.push(wage);

        //         if (pq.size() > k) {
        //             sumWage -= pq.top();
        //             pq.pop();
        //         }
        //     }
        //     result = min(result,sumWage);

        // }
        // return result;


        //Approach 3 - OPTIMAL
        
       int n = quality.size();

        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)
            wage[worker]/quality[worker], quality[worker]);
        }
        sort(begin(worker_ratio), end(worker_ratio));

        priority_queue<int, vector<int>> pq;
        
        double sum_quality = 0;
        for(int i = 0; i < k; i++) { 
            pq.push(worker_ratio[i].second); //push all qualities in max-heap
            sum_quality += worker_ratio[i].second; //Find sum of qualities
        }

        double managerRatio = worker_ratio[k-1].first; 
        double result       = managerRatio * sum_quality;

        for(int manager = k; manager < n; manager++) {
            
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second); //push all qualities in max-heap
            sum_quality += worker_ratio[manager].second; //Find sum of qualities

            if(pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            result = min(result, managerRatio*sum_quality);

        }

        return result;
  
    }
};