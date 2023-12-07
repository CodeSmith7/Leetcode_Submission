class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // int size = flowerbed.size();
    // for(int i = 0; i < size && n > 0; i++) {
    //     if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)) {
    //         flowerbed[i] = 1;
    //         n--;
    //     }
    // }
    // return n <= 0;

    int max = 0;

    int fi = -1;
    int li = -1;
    for (int i = 0;i<flowerbed.size();i++) {
        if (flowerbed[i] == 0) {
            continue;
        } else if (fi == -1) {
            fi = i;
            li = i;
        } else {
            li = i;
        }
    }

    // all zeros
    if (fi == -1) {
        return n <= (flowerbed.size() + 1) / 2; 
    }
    //left 
    max = (fi /2); 
    //right 
    max += (flowerbed.size() - li -1) / 2;

    //middle 
    int count = 0;
    for (int i = fi + 1;  i<= li;i++) {
        if (flowerbed[i] == 0) {
            count++;
        } else {
            max += (count - 1) / 2;
            count = 0;
        }
    } 
    max += (count - 1) / 2;

    return n <= max;
 }
};