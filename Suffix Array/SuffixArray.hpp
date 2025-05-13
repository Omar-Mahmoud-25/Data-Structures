class SuffixArray{
private:
    class Suffix{
    public:
        int index,currentRank,nextRank;
        Suffix(int index,int currentRank,int nextRank):
            index(index),
            currentRank(currentRank),
            nextRank(nextRank){}
        Suffix(){}
        bool operator< (Suffix other) const{
            if (this->currentRank != other.currentRank)
                return this->currentRank < other.currentRank;
            return this-> nextRank < other.nextRank;
        }
    };
    const char *string;
    int stringLength;
    int *suffixArray;
public:
    SuffixArray(const char *string);
    ~SuffixArray();
    void print();
    void constructUsingPrefixDoubling();
};