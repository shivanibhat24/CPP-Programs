class Solution {
public:

    int totalCubes(long long x){
        long long total = x * (x + 1) * (x + 2);
        return total/6;
    }

    int totalSquares(long long x){
        long long total = x * (x + 1);
        return total/2;
    }

    pair<int,int> cube(int n){
        int start = 1;
        int end = 2000;
        int num = 1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(totalCubes(mid) <= n){
                num = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        // int cubes = (num * (num + 1))/2;
        int remaining = n - totalCubes(num);

        return {num,remaining};
    }

    int square(int n){
        int start = 1;
        int end = 2000;
        int num = 0;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(totalSquares(mid) <= n){
                num = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        int remaining = n - totalSquares(num);
        if(remaining > 0) num++;
        return num;
    }

    int minimumBoxes(int n) {
        pair<int,int> val = cube(n);
        int floorCubes = (val.first * (val.first + 1))/2;
        int remaining = val.second;

        cout << floorCubes << " " << remaining << endl;

        floorCubes += square(remaining);
        return floorCubes;
    }
};
