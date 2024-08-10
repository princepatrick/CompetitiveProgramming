/*
	Status in the contest: Upsolved from https://leetcode.com/problems/design-bitset/solutions/1748431/python3-java-c-all-operations-o-1-flipped-string-flip-flag/
	Approach:
	A very intuitive approach with two strings:
		origStr
		flipStr 
		This is the main intuition - which maintains two states at the same time
			Whenever we fix, unfix the states we alternate the origStr and flipStr
		Due to maintaining the states we can use all(), one(), count() and toString()

*/

class Bitset {
public:
    string origStr, flipStr;
    int numOfOnes, numOfZeros, sz;

    Bitset(int size) {
        origStr = string( size, '0' );
        flipStr = string( size, '1' );
        sz = size;
        numOfOnes = 0;
        numOfZeros = sz;
    }
    
    void fix(int idx) {
        if( origStr[idx] != '1' ){
            numOfOnes++;
            numOfZeros--;
        } 
        origStr[idx] = '1';
        flipStr[idx] = '0';        
    }
    
    void unfix(int idx) {
        if( origStr[idx] == '1' ){
            numOfOnes--;
            numOfZeros++;
        } 
        origStr[idx] = '0';
        flipStr[idx] = '1';   
        
    }
    
    void flip() {
        string tempStr = origStr;
        origStr = flipStr;
        flipStr = tempStr;

        int temp = numOfOnes;
        numOfOnes = numOfZeros;
        numOfZeros = temp;        
    }
    
    bool all() {
        return numOfOnes == sz;
    }
    
    bool one() {
        return numOfOnes > 0;
    }
    
    int count() {
        return numOfOnes;
    }
    
    string toString() {
        return origStr;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */