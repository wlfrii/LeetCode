#if 0
#include <iostream>
int main() {

    // float val = 11.f / 3;
    // std::cout.precision(3);
    // std::cout << val << std::endl;
    // std::cout << std::fixed << val << std::endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int sstoi(char ch)
{
    switch(ch){
        case 'F': return 15;
        case 'E': return 14;
        case 'D': return 13;
        case 'C': return 12;
        case 'B': return 11;
        case 'A': return 10;
        default: return ch - '0';
    }   
}

int main() {
    std::string str;
    cout << "Cin a 0x number:\n";
    //cin >> str;
    str = "OxAA";
    
    size_t sum = 0;
    int p = 0;
    for(int i = str.size() - 1; i >= 2; i--){
        sum += sstoi(str[i]) * pow(16, p++);
    }
    printf("%zu\n", sum);
    
    return 0;
}
#endif
 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    string str = "abcqweracb";
    //cin >> str;
    
    unordered_set<char> set;
    vector<char> res;
    for(auto ch : str) {
        if(set.find(ch) == set.end()){
            set.insert(ch);
            res.push_back(ch);
        }
    }
    
    // for(auto ch : res){
    //     printf("%c", ch);
    // }
    string ret(res.begin(), res.end());
    cout << ret;
    
    return 0;
}