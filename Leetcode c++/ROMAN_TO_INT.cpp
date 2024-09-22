class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int> roman_values;
        roman_values['I']=1;
        roman_values['V']=5;
        roman_values['X']=10;
        roman_values['L']=50;
        roman_values['C']=100;
        roman_values['D']=500;
        roman_values['M']=1000;
        int result=0;
        
        for(int i=0; i<s.length();i++)
        {
            
                if(roman_values[s[i]]<roman_values[s[i+1]])
                {
                    result-=roman_values[s[i]];
                }
                else
                {
                    result+=roman_values[s[i]];

                }
                

            
        }
        return result;
        
    }
};

/*
Just mapping characters(roman) to their corresponding values and iterate through the given string , 
then compute based on the constraints given.
Finally return the result.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)
