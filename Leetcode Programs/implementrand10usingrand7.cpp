class Solution {
public:
    int rand10() {
        while(1){
            int num = (rand7()-1)*7 + rand7();
            if(num <=40)
                return num%10+1;
        }
    }
};
