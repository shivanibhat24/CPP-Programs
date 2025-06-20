class MyCircularQueue {
public:
int *arr;
int f;
int r;
int size;
    MyCircularQueue(int k) {
        this->size=k;
        arr=new int[size];
        f=-1;
        r=-1;
    }
    
    bool enQueue(int value) {
        if((r + 1) % size == f){
            return false;
        }
        else if(f==-1){
            f=0;
            r=0;
        }
        else if(f!=0&&r==size-1){
            r=0;
          
        }
        else{
            r++;
        }
          arr[r]=value;
          return true;
    }
    
    bool deQueue() {
        if(f==-1){
            return false;
        }
        else if(f==r){
            f=-1;
            r=-1;
        }
        else if(f==size-1){
            f=0;
        }
        else{
            f++;
        }
        return true;

    }
    
    int Front() {
        if(f!=-1){
            return arr[f];
        }
        return -1;
    }
    
    int Rear() {
        if(r!=-1){
            return arr[r];
        }
        return -1;
        
    }
    
    bool isEmpty() {
        if(f==-1){
            return true;;
        }
        return false;
    }
    
    bool isFull() {
        if((r + 1) % size == f){
            return true;
        }return false;

    }
};
