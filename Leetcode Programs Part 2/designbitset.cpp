typedef unsigned long Type;
const int TypeBits = sizeof(Type)*8;
const Type InvMask = ~(Type)0;
class Bitset {
public:
    Bitset(int size) : _size(size), _oneCount(0), _inverted(0) {
        int n = size/TypeBits;
        if (size%TypeBits != 0) {
            n++;
        }
        _bits.resize(n, 0);
    }    
    void fix(int idx) {
        int index = idx/TypeBits;
        idx %= TypeBits;
        Type m = (Type)1<<idx;
        Type value = (_bits[index]&m)^(_inverted<<idx);
        if (value == 0) {
            _bits[index] ^= m;
            _oneCount++;
        }
    }    
    void unfix(int idx) {
        int index = idx/TypeBits;
        idx %= TypeBits;
        Type m = (Type)1<<idx;
        Type value = (_bits[index]&m)^(_inverted<<idx);
        if (value != 0) {
            _bits[index] ^= m;
            _oneCount--;
        }
    }    
    void flip() {
        _inverted = 1 - _inverted;
        _oneCount = _size - _oneCount;
    }    
    bool all() {
        return _oneCount == _size;
    }    
    bool one() {
        return _oneCount != 0;
    }
    int count() {
        return _oneCount;
    }
    string toString() {
        string ans(_size, ' ');
        for (int i = 0;i < _size;i++) {
            int idx = i/TypeBits;
            int shift = i%TypeBits;
            Type value = (_bits[idx]&((Type)1<<(shift)))^(_inverted<<shift);
            ans[i] = value == 0? '0' : '1';
        }
        return ans;
    }
private:
    vector<Type> _bits;
    int _size;
    int _oneCount;
    Type _inverted;
};
