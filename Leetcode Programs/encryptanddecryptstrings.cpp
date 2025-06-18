class Encrypter {
	unordered_map<char,string> charToEncryptedString;
	unordered_map<string,int> dictionaryWordsToEncryptedWordsCount;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++) {
            charToEncryptedString[keys[i]] = values[i];
        }
	    for(string str : dictionary) {
            string encryptedWord = encrypt(str);
            dictionaryWordsToEncryptedWordsCount[encryptedWord]++;
        }
    }    
    string encrypt(string word1) {
        string encryptedWord = "";
        for(char c : word1) {
            if(charToEncryptedString.find(c) == charToEncryptedString.end()) {
                encryptedWord = "";
                break;
            }
            encryptedWord += charToEncryptedString[c];
	    }
	    return encryptedWord;
    }    
    int decrypt(string word2) {
        return dictionaryWordsToEncryptedWordsCount[word2];
    }
};
